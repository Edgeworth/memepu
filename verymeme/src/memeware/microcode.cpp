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

class Microcode {
public:
  Microcode() : data_(SIZE, 0) {}

#define WRITE(opcode, ...) { \
  uint32_t microops[] = {__VA_ARGS__}; \
  writeMicroops(opcode, microops, sizeof(microops) / sizeof(microops[0])); \
}
  std::vector<uint8_t> get() {
    WRITE(OP_RESET, 0);
    return data_;
  }
#undef WRITE

private:
  std::vector<uint8_t> data_;
  static constexpr size_t NUM_BITS = 11u;
  static constexpr size_t SIZE = 1u << NUM_BITS;
  static constexpr size_t MICROOP_BITS = 5u;
  static constexpr size_t MAX_MICROOPS = 1u << MICROOP_BITS;

  uint32_t addr_opcode(Opcode opcode) { return static_cast<uint32_t>(opcode) << MICROOP_BITS; }
  uint32_t addr_microop(int idx) {
    verify_expr(idx < int(MAX_MICROOPS), "too many microops");
    return idx;
  }

  void put(uint32_t addr, uint32_t output) {
    verify_expr((addr & (SIZE - 1)) == addr, "only %lu bits for address", NUM_BITS);
    data_[addr] = output;
  }

  void writeMicroops(Opcode opcode, uint32_t* microops, int num) {
    verify_expr(num <= int(MAX_MICROOPS),
        "no more than %lu microops for opcode %d, has %d microops",
        MAX_MICROOPS, static_cast<int>(opcode), num);
    for (int microop_idx = 0; microop_idx < int(MAX_MICROOPS); ++microop_idx) {
      // Verify last micro-op resets micro-op counter, unless it's the final micro-op.
//    if (microop_idx == num - 1 && microop_idx != MAX_MICROOPS - 1)
//      verify_expr(multi_from_microop(microops[microop_idx]) == MULTI_N_RESET_UOP_COUNT,
//          "last micro-op must reset micro-op count, opcode: %d", static_cast<int>(opcode));

      // For unused portions, reset uop count for debug purposes.
      if (microop_idx < num)
        write(opcode, microop_idx, microops[microop_idx]);
//    else write(opcode, microop_idx, multi(MULTI_N_RESET_UOP_COUNT));
    }
  }

  void write(Opcode opcode, int microop_idx, uint32_t microop_data) {
    uint32_t addr = 0;
    addr |= addr_opcode(opcode);
    addr |= addr_microop(microop_idx);
    put(addr, microop_data);
  }
};


std::vector<uint8_t> generateMicrocodeFirmware() {
  return Microcode().get();
}

}  // memeware
