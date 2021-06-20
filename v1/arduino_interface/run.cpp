// Copyright 2019 E.
#include "run.h"
#include "device.h"

namespace {

volatile uint32_t num_clocks = 0;
DeviceConnection device;

void clockIsr() {
  bool high = digitalRead(CLK) == HIGH;
  if (high) {
    num_clocks += 1;
    device.onRisingClock();
  } else {
    device.onFallingClock();
  }
}

class Runner {
public:
  void run() {
    unsigned long before = millis();
    while (1) {
      device.checkData();
      checkCommandFromHost();

      unsigned long now = millis();
      if (now - before > 5000) {
        if (print_clock_) {
          printf("%lu clocks occurred\n", num_clocks);
          print_clock_ = false;
        }
        // Needs locking but w/e.
        num_clocks = 0;
        before = now;
      }
    }
  }

private:
  constexpr static int SERIAL_BUF_SIZE = 64;
  int serial_idx_ = 0;
  char serial_buf_[SERIAL_BUF_SIZE];
  bool print_clock_ = false;

  void checkCommandFromHost() {
    while (Serial.available()) {
      serial_buf_[serial_idx_] = Serial.read();
      if (serial_buf_[serial_idx_] == '\n') {
        if (serial_buf_[0] == 'd') { // Dump
          printf("Dumping state\n");
          device.sendDumpDataCommand();
        } else if (serial_buf_[0] == 'r') { // Read byte
          printf("Reading data\n");
          device.sendReadByteCommand();
        } else if (serial_buf_[0] == 'c') {  // Count number of clocks.
          print_clock_ = true;
        }

        serial_idx_ = -1;
      }

      serial_idx_++;
      if (serial_idx_ >= SERIAL_BUF_SIZE) {
        printf("Too much data.\n");
        serial_idx_ = 0;
      }
    }
  }
};

}  // namespace

void run() {
  setBusMode(INPUT);
  pinMode(INT_FLAG, OUTPUT);
  pinMode(INT_OUT_NCLK, INPUT);

  digitalWrite(INT_FLAG, LOW);

  Serial.begin(1200);

  attachInterrupt(digitalPinToInterrupt(CLK), clockIsr, CHANGE);
  attachInterrupt(digitalPinToInterrupt(INT_IN_CLK), peripheralIsr, RISING);

  Runner runner;
  runner.run();
}
