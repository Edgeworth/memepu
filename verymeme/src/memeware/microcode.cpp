#include "memeware/microcode.h"
#include "memeware/constants.h"

namespace memeware {

uint8_t generateSumOutput(uint32_t sum, uint32_t carry_in) {
  // Out, Propagate, Generate, Zero
  const uint8_t sum_propagate = sum == 0x0F ? 0b0001'0000 : 0;
  const uint8_t sum_generate = sum > 0x0F ? 0b0010'0000 : 0;
  const uint8_t sum_out = (sum + carry_in) & 0x0F;
  const uint8_t sum_zero = sum_out == 0 ? 0b0100'0000 : 0;
  return sum_out | sum_propagate | sum_generate | sum_zero;
}

uint8_t generateGeneralOutput(uint32_t result) {
  return (result & 0x0F) | ((result & 0x0F) == 0 ? 0b0100'0000 : 0);
}

std::vector<uint8_t> generateMluSliceFirmware() {
  std::vector<uint8_t> data(1 << 12);
  for (uint32_t a = 0; a < (1 << 4); ++a) {
    for (uint32_t b = 0; b < (1 << 4); ++b) {
      for (uint32_t c_in = 0; c_in < 2; ++c_in) {
        uint32_t addr = a | (b << 4) | (c_in << 8);
        data[(MLU_ADD << 9) | addr] = generateSumOutput(a + b, c_in);
        data[(MLU_SUB << 9) | addr] = generateSumOutput(a + ((~b) & 0x0F), c_in);
        data[(MLU_AND << 9) | addr] = generateGeneralOutput(a & b);
        data[(MLU_OR << 9) | addr] = generateGeneralOutput(a | b);
        data[(MLU_XOR << 9) | addr] = generateGeneralOutput(a ^ b);
        data[(MLU_NOT << 9) | addr] = generateGeneralOutput(~a);
        data[(MLU_NOP0 << 9) | addr] = generateGeneralOutput(0);
        data[(MLU_NOP1 << 9) | addr] = generateGeneralOutput(0);
      }
    }
  }
  return data;
}

std::vector<uint8_t> generateMluLookaheadFirmware() {
  std::vector<uint8_t> data(1 << 17);
  for (uint32_t p = 0; p < (1 << 8); ++p) {
    for (uint32_t g = 0; g < (1 << 8); ++g) {
      for (uint32_t c_in = 0; c_in < 2; ++c_in) {
        uint32_t addr = p | (g << 8) | (c_in << 16);

        uint8_t carrys = 0;
        int prev_carry = c_in;
        for (int i = 0; i < 8; ++i) {
          const int carry = (prev_carry && (p & (1 << i))) || (g & (1 << i)) ? 1 : 0;
          carrys |= (carry << i);
          prev_carry = carry;
        }
        data[addr] = carrys;
      }
    }
  }
  return data;
}

std::vector<uint8_t> generateMicrocodeFirmware() {
  std::vector<uint8_t> data(1 << 6);
  for (uint32_t i = 0; i < data.size(); ++i)
    data[i] = 0;
  return data;
}

}  // memeware
