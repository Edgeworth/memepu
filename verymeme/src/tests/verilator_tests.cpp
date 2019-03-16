#include <array>

#include "verymeme/common.h"
#include "Vchip7400.h"
#include "Vchip7404.h"
#include "Vchip7408.h"
#include "Vchip7432.h"
#include "Vchip7486.h"
#include "Vchip74299.h"
#include "Vfull_adder.h"
#include "Valu.h"
#include "verymeme/firmware_constants.h"

namespace {

template<typename ...Ts>
constexpr auto bitRanges(Ts... ts) {
  std::array<int, sizeof...(ts)> arr{static_cast<int>(ts)...};
  for (std::size_t i = 0; i < arr.size(); ++i)
    arr[i] = 1 << arr[i];
  return ::testing::ValuesIn(CartesianProduct<uint32_t, arr.size()>(arr).get());
}

class Chip7400Test : public ::testing::TestWithParam<std::array<uint32_t, 2>> {
protected:
  Vchip7400 chip;
};

TEST_P(Chip7400Test, Exhaustive) {
  const auto[A, B] = GetParam();
  chip.A = uint8_t(A);
  chip.B = uint8_t(B);
  chip.eval();
  EXPECT_EQ(~(A & B) & 0x0F, chip.Y);
}

INSTANTIATE_TEST_SUITE_P(Exhaustive, Chip7400Test, bitRanges(4, 4));

class Chip7404Test : public ::testing::TestWithParam<std::array<uint32_t, 1>> {
protected:
  Vchip7404 chip;
};

TEST_P(Chip7404Test, Exhaustive) {
  const auto[A] = GetParam();
  chip.A = uint8_t(A);
  chip.eval();
  EXPECT_EQ(~A & 0x3F, chip.Y);
}

INSTANTIATE_TEST_SUITE_P(Exhaustive, Chip7404Test, bitRanges(6));

class Chip7408Test : public ::testing::TestWithParam<std::array<uint32_t, 2>> {
protected:
  Vchip7408 chip;
};

TEST_P(Chip7408Test, Exhaustive) {
  const auto[A, B] = GetParam();
  chip.A = uint8_t(A);
  chip.B = uint8_t(B);
  chip.eval();
  EXPECT_EQ(A & B, chip.Y);
}

INSTANTIATE_TEST_SUITE_P(Exhaustive, Chip7408Test, bitRanges(4, 4));

class Chip7432Test : public ::testing::TestWithParam<std::array<uint32_t, 2>> {
protected:
  Vchip7432 chip;
};

TEST_P(Chip7432Test, Exhaustive) {
  const auto[A, B] = GetParam();
  chip.A = uint8_t(A);
  chip.B = uint8_t(B);
  chip.eval();
  EXPECT_EQ(A | B, chip.Y);
}

INSTANTIATE_TEST_SUITE_P(Exhaustive, Chip7432Test, bitRanges(4, 4));

class Chip7486Test : public ::testing::TestWithParam<std::array<uint32_t, 2>> {
protected:
  Vchip7486 chip;
};

TEST_P(Chip7486Test, Exhaustive) {
  const auto[A, B] = GetParam();
  chip.A = uint8_t(A);
  chip.B = uint8_t(B);
  chip.eval();
  EXPECT_EQ(A ^ B, chip.Y);
}

INSTANTIATE_TEST_SUITE_P(Exhaustive, Chip7486Test, bitRanges(4, 4));

class Chip74299Test : public ::testing::TestWithParam<std::array<uint32_t, 6>> {
protected:
  Vchip74299 chip;
};

TEST_P(Chip74299Test, Exhaustive) {
  const auto[S, N_OE, N_MR, DSR, DSL, IO] = GetParam();
  chip.CP = 0;
  chip.eval();

  chip.S = 0b11;  // LOAD.
  chip.N_OE = 0b11; // Don't output.
  chip.N_MR = 1;
  chip.DSR = 0;
  chip.DSL = 0;
  chip.IO = uint8_t(IO);
  chip.CP = 1;
  chip.eval();

  chip.N_OE = 0b00;  // Output and check.
  chip.eval();
  EXPECT_EQ(IO, chip.IO);
  EXPECT_EQ(IO & 1, chip.Q0);
  EXPECT_EQ((IO >> 7) & 1, chip.Q7);

  // Now apply operation to loaded data.
  chip.CP = 0;
  chip.eval();

  chip.S = uint8_t(S);
  chip.N_OE = uint8_t(N_OE);
  chip.N_MR = uint8_t(N_MR);
  chip.DSR = uint8_t(DSR);
  chip.DSL = uint8_t(DSL);
  chip.IO = uint8_t(IO);
  chip.CP = 1;
  chip.eval();
  uint32_t result = IO;
  if (S == 0b01) result = uint8_t((result << 1) | DSL);
  else if (S == 0b10) result = uint8_t((result >> 1) | (DSR << 7));
  EXPECT_EQ(N_MR && N_OE == 0b00 ? result : 0, chip.IO);
  EXPECT_EQ(N_MR ? result & 1 : 0, chip.Q0);
  EXPECT_EQ(N_MR ? (result >> 7) & 1 : 0, chip.Q7);
}

INSTANTIATE_TEST_SUITE_P(Exhaustive, Chip74299Test, bitRanges(2, 2, 1, 1, 1, 8));

class FullAdderTest : public ::testing::TestWithParam<std::array<uint32_t, 3>> {
protected:
  Vfull_adder chip;
};

TEST_P(FullAdderTest, Exhaustive) {
  const auto[A, B, C_IN] = GetParam();
  chip.A = uint8_t(A);
  chip.B = uint8_t(B);
  chip.C_IN = uint8_t(C_IN);
  chip.eval();
  const uint32_t result = A + B + C_IN;
  EXPECT_EQ(uint8_t(result), chip.Y);
  EXPECT_EQ((result & 0x100) >> 8, chip.C_OUT);
}

INSTANTIATE_TEST_SUITE_P(Exhaustive, FullAdderTest, bitRanges(8, 8, 1));

#define TEST_ALU_OP(result) \
  EXPECT_EQ(uint32_t(result), alu.OUT); \
  EXPECT_EQ(((result) & 0x100000000LL) >> 32, alu.C); \
  EXPECT_EQ(uint32_t(result) ? 0 : 1, alu.Z); \
  EXPECT_EQ((result) & 0x80000000 ? 1 : 0, alu.N); \

void testAluOps(uint64_t a, uint64_t b, uint64_t c_in) {
  Valu alu;
  alu.A = uint32_t(a);
  alu.B = uint32_t(b);
  alu.C_IN = uint8_t(c_in);

  alu.OP = Alu::ADD;
  alu.eval();
  TEST_ALU_OP(a + b + c_in);

  alu.OP = Alu::AND;
  alu.eval();
  TEST_ALU_OP(a & b);

  alu.OP = Alu::OR;
  alu.eval();
  TEST_ALU_OP(a | b);

  alu.OP = Alu::XOR;
  alu.eval();
  TEST_ALU_OP(a ^ b);

  alu.OP = Alu::NOT;
  alu.eval();
  TEST_ALU_OP((~a) & 0xFFFFFFFF);

  alu.C_IN = 1;  // SUB only valid for C_IN == 1.
  alu.OP = Alu::SUB;
  alu.eval();
  TEST_ALU_OP(a + ((~b) & 0xFFFFFFFF) + 1);
}

class SemiExhaustiveAluTest : public ::testing::TestWithParam<std::array<uint32_t, 3>> {};

TEST_P(SemiExhaustiveAluTest, Basic) {
  const auto[A, B, C_IN] = GetParam();
  testAluOps(A, B, C_IN);
}

INSTANTIATE_TEST_SUITE_P(Exhaustive, SemiExhaustiveAluTest, bitRanges(8, 8, 1));

class AluTest : public ::testing::TestWithParam<std::tuple<uint32_t, uint32_t, uint32_t>> {};

TEST_P(AluTest, Exhaustive) {
  const auto[A, B, C_IN] = GetParam();
  testAluOps(A, B, C_IN);
}

INSTANTIATE_TEST_SUITE_P(Basic, AluTest,
    testing::Values(std::make_tuple(1, 2, 0), std::make_tuple(1, 1, 1),
        std::make_tuple(3364619464, 3637411669, 0)));

}  // anonymous
