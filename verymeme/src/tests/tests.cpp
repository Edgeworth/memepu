#include <array>

#include "common.h"
#include "Vchip7400.h"
#include "Vchip7404.h"
#include "Vchip7408.h"
#include "Vchip7432.h"
#include "Vchip7486.h"
#include "Vchip74299.h"
#include "Vfull_adder.h"

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
  ASSERT_EQ(~(A & B) & 0x0F, chip.Y);
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
  ASSERT_EQ(~A & 0x3F, chip.Y);
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
  ASSERT_EQ(A & B, chip.Y);
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
  ASSERT_EQ(A | B, chip.Y);
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
  ASSERT_EQ(A ^ B, chip.Y);
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
  ASSERT_EQ(IO, chip.IO);
  ASSERT_EQ(IO & 1, chip.Q0);
  ASSERT_EQ((IO >> 7) & 1, chip.Q7);

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
  ASSERT_EQ(N_MR && N_OE == 0b00 ? result : 0, chip.IO);
  ASSERT_EQ(N_MR ? result & 1 : 0, chip.Q0);
  ASSERT_EQ(N_MR ? (result >> 7) & 1 : 0, chip.Q7);
  ASSERT_EQ(!N_OE && S == 0b11, chip.ERR);  // Err if outputting and trying to read.
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
  ASSERT_EQ(uint8_t(result), chip.Y);
  ASSERT_EQ((result & 0x100) >> 8, chip.C_OUT);
}

INSTANTIATE_TEST_SUITE_P(Exhaustive, FullAdderTest, bitRanges(8, 8, 1));

}  // anonymous
