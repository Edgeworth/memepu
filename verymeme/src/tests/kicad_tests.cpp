#include "memecad/parser.h"

namespace {

using SchematicTest = testing::Test;

TEST_F(SchematicTest, DoesNotLoseInformation) {
  std::string full_adder_original = readFile("test_data/full_adder.sch", false /* binary */);
  memecad::sheet_t sheet = memecad::parseSheet(full_adder_original);
  std::string full_adder_read_back_1 = memecad::writeSheet(sheet);
  memecad::sheet_t sheet_read_back = memecad::parseSheet(full_adder_read_back_1);
  std::string full_adder_read_back_2 = memecad::writeSheet(sheet_read_back);
  EXPECT_EQ(full_adder_read_back_1, full_adder_read_back_2);
}


}  // anonymous
