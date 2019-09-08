#include <array>
#include <numeric>

#include "Vchip7400.h"
#include "Vchip7404.h"
#include "Vchip7408.h"
#include "Vchip74299.h"
#include "Vchip7432.h"
#include "Vchip7486.h"
#include "Vkpu.h"
#include "Vkpu_control_logic.h"
#include "Vkpu_kpu.h"
#include "Vmlu.h"
#include "Vregister_file.h"
#include "Vshifter.h"
#include "Vtimer.h"
#include "gtest/gtest.h"
#include "memesim/simulator.h"
#include "memeware/constants.h"
#include "verymeme/file.h"

namespace {

class VerilatorTest : public ::testing::Test {
public:
  VerilatorTest() { checkedChdir("verilog"); }

  ~VerilatorTest() override { checkedChdir(".."); }
};

template <int... Ns>
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
    const auto [A, B] = param;
    chip.A = uint8_t(A);
    chip.B = uint8_t(B);
    chip.eval();
    EXPECT_EQ(~(A & B) & 0x0F, chip.Y);
  }
};

TEST_F(Chip7400Test, Exhaustive) { run(); }

class Chip7404Test : public ExhaustiveVerilatorTest<6> {
  void doTest() override {
    Vchip7404 chip;
    const auto [A] = param;
    chip.A = uint8_t(A);
    chip.eval();
    EXPECT_EQ(~A & 0x3F, chip.Y);
  }
};

TEST_F(Chip7404Test, Exhaustive) { run(); }

class Chip7408Test : public ExhaustiveVerilatorTest<4, 4> {
  void doTest() override {
    Vchip7408 chip;
    const auto [A, B] = param;
    chip.A = uint8_t(A);
    chip.B = uint8_t(B);
    chip.eval();
    EXPECT_EQ(A & B, chip.Y);
  }
};

TEST_F(Chip7408Test, Exhaustive) { run(); }

class Chip7432Test : public ExhaustiveVerilatorTest<4, 4> {
  void doTest() override {
    Vchip7432 chip;
    const auto [A, B] = param;
    chip.A = uint8_t(A);
    chip.B = uint8_t(B);
    chip.eval();
    EXPECT_EQ(A | B, chip.Y);
  }
};

TEST_F(Chip7432Test, Exhaustive) { run(); }

class Chip7486Test : public ExhaustiveVerilatorTest<4, 4> {
  void doTest() override {
    Vchip7486 chip;
    const auto [A, B] = param;
    chip.A = uint8_t(A);
    chip.B = uint8_t(B);
    chip.eval();
    EXPECT_EQ(A ^ B, chip.Y);
  }
};

TEST_F(Chip7486Test, Exhaustive) { run(); }

class Chip74299Test : public ExhaustiveVerilatorTest<2, 2, 1, 1, 1, 8> {
  void doTest() override {
    Vchip74299 chip;
    const auto [S, N_OE, N_MR, DSR, DSL, IO] = param;
    chip.CP = 0;
    chip.eval();

    chip.S = 0b11;  // LOAD.
    chip.N_OE = 0b11;  // Don't output.
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
    else if (S == 0b10)
      result = uint8_t((result >> 1u) | (DSR << 7u));
    EXPECT_EQ(N_MR && N_OE == 0b00 ? result : 0, chip.IO);
    EXPECT_EQ(N_MR ? result & 1 : 0, chip.Q0);
    EXPECT_EQ(N_MR ? (result >> 7) & 1 : 0, chip.Q7);
  }
};

TEST_F(Chip74299Test, Exhaustive) { run(); }

#define TEST_MLU_OP(result) \
  EXPECT_EQ(uint32_t(result), mlu.OUT); \
  EXPECT_EQ(((result)&0x100000000ull) >> 32u, mlu.C); \
  EXPECT_EQ(uint32_t(result) ? 0 : 1, mlu.Z); \
  EXPECT_EQ((result)&0x80000000u ? 1 : 0, mlu.N)

void testMluOps(Vmlu& mlu, uint64_t a, uint64_t b, uint64_t c_in) {
  mlu.A = uint32_t(a);
  mlu.B = uint32_t(b);
  mlu.C_IN = uint8_t(c_in);

  mlu.OP = memeware::MLU_ADD;
  mlu.eval();
  TEST_MLU_OP(a + b + c_in);

  mlu.OP = memeware::MLU_AND;
  mlu.eval();
  TEST_MLU_OP(a & b);

  mlu.OP = memeware::MLU_OR;
  mlu.eval();
  TEST_MLU_OP(a | b);

  mlu.OP = memeware::MLU_XOR;
  mlu.eval();
  TEST_MLU_OP(a ^ b);

  mlu.OP = memeware::MLU_NOT;
  mlu.eval();
  TEST_MLU_OP((~a) & 0xFFFFFFFF);

  mlu.OP = memeware::MLU_ANOT;
  mlu.eval();
  TEST_MLU_OP(a & (~b));

  mlu.C_IN = 1;  // SUB only valid for C_IN == 1.
  mlu.OP = memeware::MLU_SUB;
  mlu.eval();
  TEST_MLU_OP(a + ((~b) & 0xFFFFFFFF) + 1);
}

#undef TEST_MLU_OP

class SemiExhaustiveMluTest : public ExhaustiveVerilatorTest<10, 10, 1> {
public:
  SemiExhaustiveMluTest() {
    mlu_.N_BOOTED = 0;
    mlu_.N_RST = 1;
    mlu_.BOOTSTRAP_MLU_LOOKAHEAD_N_WE = 1;
    mlu_.BOOTSTRAP_MLU_SLICE_N_WE = 1;
  }

  void doTest() override {
    const auto [A, B, C_IN] = param;
    testMluOps(mlu_, A, B, C_IN);
  }

private:
  Vmlu mlu_;
};

TEST_F(SemiExhaustiveMluTest, SemiExhaustiveMluTest) { run(); }

class MluTest : public VerilatorTest,
                public ::testing::WithParamInterface<std::tuple<uint32_t, uint32_t, uint32_t>> {
public:
  MluTest() {
    mlu_.N_BOOTED = 0;
    mlu_.N_RST = 1;
    mlu_.BOOTSTRAP_MLU_LOOKAHEAD_N_WE = 1;
    mlu_.BOOTSTRAP_MLU_SLICE_N_WE = 1;
  }

protected:
  Vmlu mlu_;
};

TEST_P(MluTest, SpecialTestCases) {
  const auto [A, B, C_IN] = GetParam();
  testMluOps(mlu_, A, B, C_IN);
}

INSTANTIATE_TEST_SUITE_P(Basic, MluTest,
    testing::Values(std::make_tuple(1, 2, 0), std::make_tuple(1, 1, 1),
        std::make_tuple(3364619464, 3637411669, 0)));

class SemiExhaustiveShifterTest : public ExhaustiveVerilatorTest<15, 5, 2, 1> {
public:
  void doTest() override {
    const auto [IN, SHFT, SEL, ARITH] = param;
    if (SEL != memeware::Shifter::SHIFTER_RIGHT_SHIFT && ARITH) return;
    shifter_.IN = IN;
    shifter_.SHFT = SHFT;
    shifter_.SEL = SEL;
    shifter_.ARITH = ARITH;
    shifter_.eval();
    switch (memeware::Shifter(SEL)) {
    case memeware::SHIFTER_LEFT_SHIFT: EXPECT_EQ(IN << SHFT, shifter_.OUT); break;
    case memeware::SHIFTER_RIGHT_SHIFT:
      if (ARITH) EXPECT_EQ(int32_t(IN) >> SHFT, shifter_.OUT);
      else
        EXPECT_EQ(IN >> SHFT, shifter_.OUT);
      break;
    case memeware::SHIFTER_SIGNEXT8:
      EXPECT_EQ(uint32_t(int32_t(int8_t(IN))) << SHFT, shifter_.OUT);
      break;
    case memeware::SHIFTER_SIGNEXT16:
      EXPECT_EQ(uint32_t(int32_t(int16_t(IN))) << SHFT, shifter_.OUT);
      break;
    }
  }

private:
  Vshifter shifter_;
};

TEST_F(SemiExhaustiveShifterTest, SemiExhaustiveShifterTest) { run(); }

class SemiExhaustiveRegisterFileTest : public ExhaustiveVerilatorTest<5> {
public:
  void doTest() override {
    const auto [REG_SRC] = param;
    const int TEST_VAL = int(REG_SRC) + 55;  // Use non-static value.
    file_.REG_SEL = 0;
    file_.REG_SRC0 = REG_SRC;
    file_.REG_SRC1 = 4;
    file_.REG_SRC2 = 2;
    file_.N_WE = 1;
    file_.N_OE = 1;
    file_.IN_DATA = TEST_VAL;
    file_.eval();

    file_.N_WE = 0;  // Write value in.
    file_.eval();

    file_.REG_SEL = 0;
    file_.REG_SRC0 = REG_SRC;
    file_.REG_SRC1 = 8;
    file_.REG_SRC2 = 2;
    file_.N_WE = 1;  // Read value out.
    file_.N_OE = 0;
    file_.eval();
    EXPECT_EQ(TEST_VAL, file_.OUT_DATA);

    file_.REG_SEL = 1;
    file_.REG_SRC0 = 5;
    file_.REG_SRC1 = REG_SRC;
    file_.REG_SRC2 = 2;
    file_.N_WE = 1;  // Read value out.
    file_.N_OE = 0;
    file_.eval();
    EXPECT_EQ(TEST_VAL, file_.OUT_DATA);

    file_.REG_SEL = 2;
    file_.REG_SRC0 = 5;
    file_.REG_SRC1 = 4;
    file_.REG_SRC2 = REG_SRC;
    file_.N_WE = 1;  // Read value out.
    file_.N_OE = 0;
    file_.eval();
    EXPECT_EQ(TEST_VAL, file_.OUT_DATA);
  }

private:
  Vregister_file file_;
};

TEST_F(SemiExhaustiveRegisterFileTest, SemiExhaustiveRegisterFileTest) { run(); }

class KpuTest : public VerilatorTest {
protected:
  Vkpu kpu_;
};

TEST_F(KpuTest, AsyncResetFromLowClk) {
  kpu_.eval();

  // Asynchronous reset from low CLK.
  kpu_.N_RST_ASYNC = 0;
  kpu_.CLK = 0;
  kpu_.N_CLK = 1;
  kpu_.eval();
  EXPECT_FALSE(kpu_.kpu->n_rst);

  kpu_.N_RST_ASYNC = 1;
  kpu_.CLK = 1;
  kpu_.N_CLK = 0;
  kpu_.eval();
  EXPECT_FALSE(kpu_.kpu->n_rst);

  kpu_.CLK = 0;
  kpu_.N_CLK = 1;
  kpu_.eval();
  // Only one falling edge, should still be reset.
  EXPECT_FALSE(kpu_.kpu->n_rst);

  kpu_.CLK = 1;
  kpu_.N_CLK = 0;
  kpu_.eval();
  EXPECT_FALSE(kpu_.kpu->n_rst);

  kpu_.CLK = 0;
  kpu_.N_CLK = 1;
  kpu_.eval();
  EXPECT_TRUE(kpu_.kpu->n_rst);
}

TEST_F(KpuTest, AsyncResetFromHighClk) {
  kpu_.eval();

  // Asynchronous reset from high CLK.
  kpu_.N_RST_ASYNC = 0;
  kpu_.CLK = 1;
  kpu_.N_CLK = 0;
  kpu_.eval();
  EXPECT_FALSE(kpu_.kpu->n_rst);

  kpu_.N_RST_ASYNC = 1;
  kpu_.CLK = 0;
  kpu_.N_CLK = 1;
  kpu_.eval();
  // Only one falling edge, should still be reset.
  EXPECT_FALSE(kpu_.kpu->n_rst);

  kpu_.CLK = 1;
  kpu_.N_CLK = 0;
  kpu_.eval();
  EXPECT_FALSE(kpu_.kpu->n_rst);

  kpu_.CLK = 0;
  kpu_.N_CLK = 1;
  kpu_.eval();
  EXPECT_TRUE(kpu_.kpu->n_rst);
}

TEST_F(KpuTest, TimerIsReset) {
  memesim::initializeKpu(kpu_);
  EXPECT_TRUE(kpu_.kpu->n_rst);
  EXPECT_EQ(0u, kpu_.kpu->timer_val);
}

TEST_F(KpuTest, MicroopCounterIsReset) {
  memesim::initializeKpu(kpu_);
  EXPECT_TRUE(kpu_.kpu->n_rst);
  EXPECT_EQ(0u, kpu_.kpu->control->microop_count);
}

TEST_F(KpuTest, OpcodeIsReset) {
  memesim::initializeKpu(kpu_);
  EXPECT_TRUE(kpu_.kpu->n_rst);
  EXPECT_EQ(0u, kpu_.kpu->control->opcode);
}

TEST_F(KpuTest, InterruptsDisabledAtReset) {
  memesim::initializeKpu(kpu_);
  EXPECT_TRUE(kpu_.kpu->n_rst);
  EXPECT_EQ(0u, kpu_.kpu->control->has_interrupt);

  kpu_.kpu->INTERRUPT_ASYNC = 1;
  memesim::clockKpu(kpu_);
  EXPECT_EQ(0u, kpu_.kpu->control->has_interrupt);
}

class TimerTest : public VerilatorTest {
protected:
  Vtimer timer_;
};

TEST_F(TimerTest, Increments) {
  timer_.CLK = 0;
  timer_.N_RST = 1;
  timer_.eval();
  uint32_t prev_time = timer_.TIME;

  for (int i = 0; i < 100; ++i) {
    timer_.CLK = 0;
    timer_.eval();

    timer_.CLK = 1;
    timer_.eval();
    EXPECT_EQ(prev_time + 1, timer_.TIME);
    prev_time = timer_.TIME;
  }
}

TEST_F(TimerTest, AsynchronousReset) {
  timer_.CLK = 0;
  timer_.N_RST = 1;
  timer_.eval();

  timer_.CLK = 1;
  timer_.eval();
  EXPECT_NE(0, timer_.TIME);

  timer_.N_RST = 0;
  timer_.eval();
  EXPECT_EQ(0, timer_.TIME);
}

}  // namespace
