#include "run.h"
#include "device.h"

namespace {

const int SERIAL_BUF_SIZE = 64;

volatile uint32_t num_clocks = 0;
DeviceConnection device;
int serial_idx = 0;
char serial_buf[SERIAL_BUF_SIZE];

void clockIsr() {
  bool high = digitalRead(CLK) == HIGH;
  if (high) {
    num_clocks += 1;
    device.onRisingClock();
  } else {
    device.onFallingClock();
  }
}

void checkCommandFromHost() {
  while (Serial.available()) {
    serial_buf[serial_idx] = Serial.read();
    if (serial_buf[serial_idx] == '\n') {
      if (serial_buf[0] == 'd') { // Dump
        printf("Dumping state\n");
        device.sendDumpDataCommand();
      } else if (serial_buf[0] == 'r') { // Read byte
        printf("Reading data\n");
        device.sendReadByteCommand();
      }

      serial_idx = -1;
    }

    serial_idx++;
    if (serial_idx >= SERIAL_BUF_SIZE) {
      printf("Too much data.\n");
      serial_idx = 0;
    }
  }
}

}  // namespace

void run() {
  setBusMode(INPUT);
  pinMode(INT_FLAG, OUTPUT);
  pinMode(INT_OUT_NCLK, INPUT);

  digitalWrite(INT_FLAG, LOW);

  Serial.begin(57600);

  attachInterrupt(digitalPinToInterrupt(CLK), clockIsr, CHANGE);
  attachInterrupt(digitalPinToInterrupt(INT_IN_CLK), peripheralIsr, RISING);

  unsigned long before = millis();
  while (1) {
    device.checkData();
    checkCommandFromHost();

    unsigned long now = millis();
    if (now - before > 2000) {
      printf("%lu clocks occurred\n", num_clocks);
      // Needs locking but w/e.
      num_clocks = 0;
      before = now;
    }
  }
}
