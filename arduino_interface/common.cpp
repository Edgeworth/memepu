#include "common.h"

char printf_buf[128];
int selection;

namespace {

const char* suffixes[] = {
  "s", "ms", "us", "ns"
};

}

void printTime(unsigned long us) {
  float time = us / 1000000.f;
  int suffix = 0;
  while (time < 1.0f && suffix < sizeof(suffixes) / sizeof(suffixes[0]) - 1) {
    time *= 1000;
    suffix++;
  }
  Serial.print(time);
  Serial.print(suffixes[suffix]);
}