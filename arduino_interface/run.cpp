#include "run.h"

enum {
  BUS0 = 11,
  BUS1 = 10,
  BUS2 = 9,
  BUS3 = 8,
  BUS4 = 7,
  BUS5 = 6,
  BUS6 = 5,
  BUS7 = 4,
  INT_IN_CLK = 3,  // Peripheral (us) should read
  CLK = 2,
  INT_FLAG = A0,  // Flags interrupt to host
  INT_OUT_NCLK = A1  // Peripheral (us) should write to host.
};

const int BUS_PINS[8] = {BUS0, BUS1, BUS2, BUS3, BUS4, BUS5, BUS6, BUS7};

volatile uint32_t num_clocks = 0;

void clockIsr() {
  num_clocks += 1;
}

void run() {
  for (int bus_pin : BUS_PINS)
    pinMode(bus_pin, INPUT);
  pinMode(INT_FLAG, OUTPUT);
  pinMode(INT_OUT_NCLK, INPUT);

  digitalWrite(INT_FLAG, LOW);

  Serial.begin(57600);

  attachInterrupt(digitalPinToInterrupt(CLK), clockIsr, RISING);

  while (1) {
    // Needs locking but w/e.
    printf("%lu clocks occurred\n", num_clocks);
    num_clocks = 0;
    delay(2000);
  }
}
