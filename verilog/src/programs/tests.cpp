#include <utility>
#include <Vchip7404.h>

#include "gtest/gtest.h"
#include "verilated.h"
#include "Vchip7400.h"
#include "Vchip7404.h"
#include "Vchip74299.h"
#include "common.h"

namespace {

template<typename ...Ts>
constexpr auto bitRanges(Ts... ts) {
  std::array<int, sizeof...(ts)> arr = {ts...};
  for (int i = 0; i < arr.size(); ++i)
    arr[i] = 1 << arr[i];
  return ::testing::ValuesIn(CartesianProduct<arr.size()>(arr).get());
}

class Chip7400Test : public ::testing::TestWithParam<std::array<int, 2>> {
protected:
  Vchip7400 chip;
};

TEST_P(Chip7400Test, Chip7400Test) {
  const auto[A, B] = GetParam();
  chip.A = A;
  chip.B = B;
  chip.eval();
  ASSERT_EQ(~(A & B) & 0x0F, chip.Y);
}

INSTANTIATE_TEST_SUITE_P(Chip7400Test, Chip7400Test, bitRanges(1, 1));

class Chip7404Test : public ::testing::TestWithParam<std::array<int, 1>> {
protected:
  Vchip7404 chip;
};

TEST_P(Chip7404Test, Chip7404Test) {
  const uint8_t A = GetParam()[0];
  chip.A = A;
  chip.eval();
  ASSERT_EQ(~A & 0x3F, chip.Y);
}

INSTANTIATE_TEST_SUITE_P(Chip7404Test, Chip7404Test, bitRanges(1));

class Chip74299Test : public ::testing::TestWithParam<std::array<int, 6>> {
protected:
  Vchip74299 chip;
};

// TODO: general-ish test.

TEST_P(Chip74299Test, Chip74299Test) {
  const auto [S, N_OE, N_MR, DSR, DSL, IO] = GetParam();
  chip.CP = 0;
  chip.S = 0b11;  // LOAD.
  chip.N_OE = N_OE;
  chip.N_MR = N_MR;
  chip.DSR = DSR;
  chip.DSL = DSL;
  chip.IO = IO;
  chip.eval();

  chip.CP = 1;
  chip.eval();
  ASSERT_EQ(N_MR && N_OE == 0b11 ? IO : 0, chip.IO);
  ASSERT_EQ(N_MR ? IO & 1 : 0, chip.Q0);
  ASSERT_EQ(N_MR ? (IO >> 7) & 1 : 0, chip.Q7);

  // TODO try op S.
}

INSTANTIATE_TEST_SUITE_P(Chip74299Test, Chip74299Test, bitRanges(2, 2, 1, 1, 1, 8));


}  // anonymous

int main(int argc, char** argv) {
  Verilated::commandArgs(argc, argv);
  Verilated::randReset(2);  // Randomize all bits.

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}