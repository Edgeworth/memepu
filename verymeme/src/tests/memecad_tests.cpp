#include <regex>

#include "gtest/gtest.h"
#include "memecad/yosys_module.h"
#include "memecad/parser.h"

namespace {

std::string removeWhitespace(const std::string& input) {
  std::regex whitespace(R"( +(\s))");
  return std::regex_replace(input, whitespace, "$1");
}

using SchematicTest = testing::Test;

TEST_F(SchematicTest, Parsing0) {
  std::string full_adder_original = readFile("test_data/parsing0/full_adder.sch",
      false /* binary */);
  memecad::Sheet sheet = memecad::parseSheet(full_adder_original);
  std::string full_adder_output = memecad::writeSheet(sheet);
  EXPECT_EQ(removeWhitespace(full_adder_original), full_adder_output);
}

TEST_F(SchematicTest, Hierarchical0) {
  auto files = memecad::convertVerilogToKicadSchematics(
      "test_data/common/memecad_map.json",
      {"test_data/hierarchical0/tapb_top_level.v", "test_data/hierarchical0/two_a_plus_b.v",
       "test_data/hierarchical0/full_adder.v", "test_data/common/chip7408.v",
       "test_data/common/chip7432.v", "test_data/common/chip7486.v"},
      {"test_data/common/74xx.lib"});
  EXPECT_EQ(3u, files.size());
  for (const auto& file : files) {
    std::string golden = readFile("test_data/hierarchical0/output/" + file.filename,
        false /* binary */);
    EXPECT_EQ(golden, file.contents);
  }
}

TEST_F(SchematicTest, Alu0) {
  auto files = memecad::convertVerilogToKicadSchematics(
      "test_data/common/memecad_map.json",
      {"test_data/alu0/alu.v", "test_data/alu0/alu_lookahead.v", "test_data/alu0/sram17x8.v",
       "test_data/alu0/alu_slice.v", "test_data/alu0/sram.v", "test_data/common/chip7408.v"},
      {"test_data/common/74xx.lib", "test_data/common/Memory_RAM.lib"});
  EXPECT_EQ(3u, files.size());
  for (const auto& file : files) {
    std::string golden = readFile("test_data/alu0/output/" + file.filename,
        false /* binary */);
    EXPECT_EQ(golden, file.contents);
  }
}

}  // anonymous
