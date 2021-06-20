// Copyright 2019 E.
#ifndef COMMON_H_
#define COMMON_H_
#include "Arduino.h"

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

extern char printf_buf[128];
extern int selection;

void printTime(unsigned long us);
void setBusMode(int mode);

#define printf(...) do { \
  snprintf(printf_buf, sizeof(printf_buf), __VA_ARGS__); \
  Serial.print(printf_buf); \
} while (0)

#define PROFILE(x) do { \
  unsigned long st = micros(); \
  x; \
  unsigned long en = micros(); \
  printf("Time for " #x ": "); \
  printTime(en - st); \
  printf("\n"); \
} while(0)

#define CHECK(x) do { \
  if (!(x)) { \
    printf("Assertion " #x " failed."); \
  } \
} while (0)

#endif
