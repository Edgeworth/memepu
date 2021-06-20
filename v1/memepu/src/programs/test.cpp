// Copyright 2019 E.
#include "common.h"

bool state[256][256];

int main() {
  uint8_t a = 0, b = 1;
  int cycle = 0;
  printf("0\n");
  while (!state[a][b]) {
    printf("%d\n", static_cast<int>(b));
    state[a][b] = true;
    uint8_t tmp = a + b;
    a = b;
    b = tmp;
    cycle++;
  }
  printf("Found cycle after %d steps, coming back to %d %d\n", cycle, static_cast<int>(a),
      static_cast<int>(b));
}
