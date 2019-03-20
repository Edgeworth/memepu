#include <regex>
#include "memecad/parser.h"

namespace {

using SchematicTest = testing::Test;

TEST_F(SchematicTest, DoesNotLoseInformation) {
  std::string full_adder_original = readFile("test_data/full_adder.sch", false /* binary */);
  memecad::Sheet sheet = memecad::parseSheet(full_adder_original);
  std::string full_adder_output = memecad::writeSheet(sheet);

  std::regex whitespace(R"( +(\s))");
  std::string full_adder_whitespace = std::regex_replace(full_adder_original, whitespace, "$1");
  EXPECT_EQ(full_adder_whitespace, full_adder_output);
}

}  // anonymous
