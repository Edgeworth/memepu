#include "kicad_parser.h"
#include "common.h"

namespace {

using SchematicTest = testing::Test;

TEST_P(SchematicTest, Golden) {
  std::string full_adder_original = readFile("test_data/full_addr.sch", false /* binary */);
  kicad::sheet_t sheet = kicad::parseSheet(full_adder_original);
  std::string full_adder_read_back = kicad::writeSheet(sheet);
  EXPECT_EQ(full_adder_original, full_adder_read_back);
}


}  // anonymous
