#include <utility>
#include <Vchip7404.h>

#include "gtest/gtest.h"
#include "verilated.h"
#include "Vchip7400.h"
#include "Vchip7404.h"
#include "Vchip74299.h"
#include "common.h"

namespace {

class Chip7400Test : public ::testing::TestWithParam<std::array<int, 2>> {
protected:
  Vchip7400 chip;
};

TEST_P(Chip7400Test, Chip7400Test) {
  const auto[A, B] = GetParam();
  chip.A = A;
  chip.B = B;
  chip.eval();
  ASSERT_EQ(~(A & B) & 0x0F, chip.Y & 0x0F);
}

INSTANTIATE_TEST_SUITE_P(Chip7400Test, Chip7400Test, ::testing::ValuesIn(CartesianProduct<2>({1 << 4, 1 << 4}).get()));

class Chip7404Test : public ::testing::TestWithParam<std::array<int, 1>> {
protected:
  Vchip7404 chip;
};

TEST_P(Chip7404Test, Chip7404Test) {
  const uint8_t A = GetParam()[0];
  chip.A = A;
  chip.eval();
  ASSERT_EQ(~A & 0x7F, chip.Y);
}

INSTANTIATE_TEST_SUITE_P(Chip7404Test, Chip7404Test, ::testing::ValuesIn(CartesianProduct<1>({1 << 6}).get()));

class Chip74299Test : public ::testing::TestWithParam<std::array<int, 1>> {
protected:
  Vchip74299 chip;
};

TEST_P(Chip74299Test, Chip74299Test) {
  const int N_MR = GetParam()[0];
  chip.CP = 0;
  chip.N_MR = 0;
  chip.eval();
  ASSERT_EQ(0, chip.IO);

  chip.CP = 1;
  chip.N_MR = N_MR;
  chip.eval();
  ASSERT_EQ(N_MR ? 55 : 0, chip.IO);
}

INSTANTIATE_TEST_SUITE_P(Chip74299Test, Chip74299Test, ::testing::ValuesIn(CartesianProduct<1>({2}).get()));


}  // anonymous

int main(int argc, char** argv) {
  Verilated::commandArgs(argc, argv);
  Verilated::randReset(2);  // Randomize all bits.

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}