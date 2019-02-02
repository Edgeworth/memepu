#include "gtest/gtest.h"
#include "verilated.h"

namespace {

class VerilatorTest : public ::testing::Test {
};

TEST_F(VerilatorTest, ATest) {
  ASSERT_FALSE(true);
}

}  // anonymous

int main(int argc, char **argv) {
  Verilated::commandArgs(argc, argv);
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}