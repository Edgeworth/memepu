// Copyright 2019 E.
#include "mlu.h"
#include "control_constants.h"

namespace {

uint8_t popcount(uint8_t v) {
  uint8_t count = 0;
  for (int i = 0; i < 8; ++i)
    count += bool(v & (1 << i));
  return count;
}

}

std::string MLU::getBinaryData() {
  // 19 bits available. First 8 are the A register. Second 8 are the B register. Last 3 are MLU operation select.

  // Two byte operations:
  // TODO: Currently all unsigned.
  for (uint32_t a = 0; a < 256; ++a) {
    for (uint32_t b = 0; b < 256; ++b) {
      uint32_t addr = a | (b << 8);
      put(addr | (MLU_AND << 16), uint8_t(a & b));
      put(addr | (MLU_OR << 16), uint8_t(a | b));
      put(addr | (MLU_XOR << 16), uint8_t(a ^ b));
      put(addr | (MLU_MUL << 16), uint8_t(a * b));
      put(addr | (MLU_DIV << 16), uint8_t(b ? a / b : 0));
      put(addr | (MLU_MOD << 16), uint8_t(b ? a % b : 0));
    }
  }

  // Single byte operations:
  for (uint32_t a = 0; a < 256; ++a) {
    uint32_t addr = a | (MLU_SINGLE << 16);
    put(addr | (MLU_SINGLE_NOT << 8), uint8_t(~a));
    put(addr | (MLU_SINGLE_POPCOUNT << 8), popcount(uint8_t(a)));
  }

  return data_;
}
