#ifndef COMMON_H_
#define COMMON_H_
#include "Arduino.h"

extern char printf_buf[128];
extern int selection;

#define printf(...) do { \
  snprintf(printf_buf, sizeof(printf_buf), __VA_ARGS__); \
  Serial.print(printf_buf); \
} while (0)

#define PROFILE(x) do { \
  unsigned long st = micros(); \
  x; \
  unsigned long en = micros(); \
  printf("Time for " #x ": %ld\n", en - st); \
} while(0)

#define CHECK(x) do { \
  if (!(x)) { \
  	printf("Assertion " #x " failed."); \
  } \
} while (0)

#endif
