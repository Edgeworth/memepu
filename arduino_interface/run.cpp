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
const int NUM_DUMP_REGS = 12;
const char* DUMP_STRS[NUM_DUMP_REGS] = {
  "A", "B", "M0", "M1", "M2", "SUM", "STATUS", "INTERRUPT", "PC0",
  "PC1", "PC2", "TASK"
};
const int RING_SIZE = 64;

volatile uint32_t num_clocks = 0;
volatile int ring_start = 0;
volatile int ring_end = 0;  // Exclusive.
volatile uint8_t ring_buf[RING_SIZE];

void clockIsr() {
  num_clocks += 1;
}

uint8_t readBus() {
  uint8_t value = 0;
  for (int pin : BUS_PINS) {
    value <<= 1;
    value |= (digitalRead(pin) == HIGH);
  }
  return value;
}

void peripheralIsr() {
  digitalWrite(INT_FLAG, LOW);
  ring_buf[ring_end++] = readBus();
}

void run() {
  for (int bus_pin : BUS_PINS)
    pinMode(bus_pin, INPUT);
  pinMode(INT_FLAG, OUTPUT);
  pinMode(INT_OUT_NCLK, INPUT);

  digitalWrite(INT_FLAG, LOW);

  Serial.begin(57600);

  attachInterrupt(digitalPinToInterrupt(CLK), clockIsr, RISING);
  attachInterrupt(digitalPinToInterrupt(INT_IN_CLK), peripheralIsr, RISING);

  unsigned long before = millis();
  int seq = 0;
  while (1) {
    while (ring_end - ring_start > 0) {
      if (seq == 0) {
        printf("Dump (ring buffer size: %d)", int(ring_end - ring_start));
      }

      printf("%s: %d", DUMP_STRS[seq], ring_buf[ring_start++]);
      seq = (seq + 1) % NUM_DUMP_REGS;
    }

    unsigned long now = millis();
    if (now - before > 2000) {
      printf("%lu clocks occurred\n", num_clocks);
      // Needs locking but w/e.
      num_clocks = 0;
      before = now;

      // Send interrupt.
      digitalWrite(INT_FLAG, HIGH);
    }
  }
}
