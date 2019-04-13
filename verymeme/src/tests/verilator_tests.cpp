#include <array>
#include <numeric>

#include "gtest/gtest.h"
#include "verymeme/common.h"
#include "Vchip7400.h"
#include "Vchip7404.h"
#include "Vchip7408.h"
#include "Vchip7432.h"
#include "Vchip7486.h"
#include "Vchip74299.h"
#include "Vmlu.h"
#include "Vshifter.h"
#include "verymeme/firmware_constants.h"

namespace {

class VerilatorTest : public ::testing::Test {
public:
  void SetUp() override {
    checked_chdir("verilog");
  }

  void TearDown() override {
    checked_chdir("..");
  }
};

template<int... Ns>
class ExhaustiveVerilatorTest : public VerilatorTest {
public:
  void run() {
    // Do this because gtest will construct a list of every test, which is slow for large
    // exhaustive tests.
    const uint32_t bits[sizeof...(Ns)] = {Ns...};
    uint64_t bitsum = 0;
    for (int i : bits) bitsum += i;

    for (uint64_t i = 0; i < (1ull << bitsum); ++i) {
      uint32_t bitcum = 0;
      for (uint32_t bitidx = 0; bitidx < int(sizeof...(Ns)); ++bitidx) {
        param[bitidx] = (i >> bitcum) & ((1ull << bits[bitidx]) - 1);
        bitcum += bits[bitidx];
      }
      doTest();
    }
  }

  virtual void doTest() = 0;

protected:
  std::array<uint32_t, sizeof...(Ns)> param = {};
};

class Chip7400Test : public ExhaustiveVerilatorTest<4, 4> {
  void doTest() override {
    Vchip7400 chip;
    const auto[A, B] = param;
    chip.A = uint8_t(A);
    chip.B = uint8_t(B);
    chip.eval();
    EXPECT_EQ(~(A & B) & 0x0F, chip.Y);
  }
};

TEST_F(Chip7400Test, Exhaustive) {
  run();
}

class Chip7404Test : public ExhaustiveVerilatorTest<6> {
  void doTest() override {
    Vchip7404 chip;
    const auto[A] = param;
    chip.A = uint8_t(A);
    chip.eval();
    EXPECT_EQ(~A & 0x3F, chip.Y);
  }
};

TEST_F(Chip7404Test, Exhaustive) {
  run();
}

class Chip7408Test : public ExhaustiveVerilatorTest<4, 4> {
  void doTest() override {
    Vchip7408 chip;
    const auto[A, B] = param;
    chip.A = uint8_t(A);
    chip.B = uint8_t(B);
    chip.eval();
    EXPECT_EQ(A & B, chip.Y);
  }
};

TEST_F(Chip7408Test, Exhaustive) {
  run();
}

class Chip7432Test : public ExhaustiveVerilatorTest<4, 4> {
  void doTest() override {
    Vchip7432 chip;
    const auto[A, B] = param;
    chip.A = uint8_t(A);
    chip.B = uint8_t(B);
    chip.eval();
    EXPECT_EQ(A | B, chip.Y);
  }
};

TEST_F(Chip7432Test, Exhaustive) {
  run();
}

class Chip7486Test : public ExhaustiveVerilatorTest<4, 4> {
  void doTest() override {
    Vchip7486 chip;
    const auto[A, B] = param;
    chip.A = uint8_t(A);
    chip.B = uint8_t(B);
    chip.eval();
    EXPECT_EQ(A ^ B, chip.Y);
  }
};

TEST_F(Chip7486Test, Exhaustive) {
  run();
}

class Chip74299Test : public ExhaustiveVerilatorTest<2, 2, 1, 1, 1, 8> {
  void doTest() override {
    Vchip74299 chip;
    const auto[S, N_OE, N_MR, DSR, DSL, IO] = param;
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
    if (S == 0b01) result = uint8_t((result << 1u) | DSL);
    else if (S == 0b10) result = uint8_t((result >> 1u) | (DSR << 7u));
    EXPECT_EQ(N_MR && N_OE == 0b00 ? result : 0, chip.IO);
    EXPECT_EQ(N_MR ? result & 1 : 0, chip.Q0);
    EXPECT_EQ(N_MR ? (result >> 7) & 1 : 0, chip.Q7);
  }
};

TEST_F(Chip74299Test, Exhaustive) {
  run();
}

#define TEST_MLU_OP(result) \
  EXPECT_EQ(uint32_t(result), mlu.OUT); \
  EXPECT_EQ(((result) & 0x100000000ull) >> 32u, mlu.C); \
  EXPECT_EQ(uint32_t(result) ? 0 : 1, mlu.Z); \
  EXPECT_EQ((result) & 0x80000000u ? 1 : 0, mlu.N); \

void testMluOps(Vmlu& mlu, uint64_t a, uint64_t b, uint64_t c_in) {
  mlu.A = uint32_t(a);
  mlu.B = uint32_t(b);
  mlu.C_IN = uint8_t(c_in);

  mlu.OP = Mlu::ADD;
  mlu.eval();
  TEST_MLU_OP(a + b + c_in);

  mlu.OP = Mlu::AND;
  mlu.eval();
  TEST_MLU_OP(a & b);

  mlu.OP = Mlu::OR;
  mlu.eval();
  TEST_MLU_OP(a | b);

  mlu.OP = Mlu::XOR;
  mlu.eval();
  TEST_MLU_OP(a ^ b);

  mlu.OP = Mlu::NOT;
  mlu.eval();
  TEST_MLU_OP((~a) & 0xFFFFFFFF);

  mlu.C_IN = 1;  // SUB only valid for C_IN == 1.
  mlu.OP = Mlu::SUB;
  mlu.eval();
  TEST_MLU_OP(a + ((~b) & 0xFFFFFFFF) + 1);
}

#undef TEST_MLU_OP

class SemiExhaustiveMluTest : public ExhaustiveVerilatorTest<10, 10, 1> {
public:
  void doTest() override {
    const auto[A, B, C_IN] = param;
    testMluOps(mlu_, A, B, C_IN);
  }
private:
  Vmlu mlu_;
};

TEST_F(SemiExhaustiveMluTest, SemiExhaustiveMluTest) {
  run();
}

class MluTest
    : public VerilatorTest,
      public ::testing::WithParamInterface<std::tuple<uint32_t, uint32_t, uint32_t>> {
protected:
  Vmlu mlu_;
};

TEST_P(MluTest, SpecialTestCases) {
  const auto[A, B, C_IN] = GetParam();
  testMluOps(mlu_, A, B, C_IN);
}

INSTANTIATE_TEST_SUITE_P(Basic, MluTest,
    testing::Values(std::make_tuple(1, 2, 0), std::make_tuple(1, 1, 1),
        std::make_tuple(3364619464, 3637411669, 0)));

class SemiExhaustiveShifterTest : public ExhaustiveVerilatorTest<15, 5, 1, 1> {
public:
  void doTest() override {
    const auto[IN, SHFT, LEFT, ARITH] = param;
    if (LEFT && ARITH) return;  // Skip arithmetic left shift.
    shifter_.IN = IN;
    shifter_.SHFT = SHFT;
    shifter_.LEFT = LEFT;
    shifter_.ARITH = ARITH;
    shifter_.eval();
    if (LEFT) EXPECT_EQ(IN << SHFT, shifter_.OUT);
    else if (ARITH) EXPECT_EQ(int32_t(IN) >> SHFT, shifter_.OUT);
    else
      EXPECT_EQ(IN >> SHFT, shifter_.OUT);
  }
private:
  Vshifter shifter_;
};

TEST_F(SemiExhaustiveShifterTest, SemiExhaustiveShifterTest) {
  run();
}

}  // anonymous
