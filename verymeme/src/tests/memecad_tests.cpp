#include <regex>

#include "gtest/gtest.h"
#include "memecad/parser.h"
#include "memecad/yosys_module.h"
#include "verymeme/file.h"

namespace {

std::string removeWhitespace(const std::string& input) {
  std::regex whitespace(R"( +(\s))");
  return std::regex_replace(input, whitespace, "$1");
}

using SchematicTest = testing::Test;

TEST_F(SchematicTest, Parsing0) {
  std::string full_adder_original = readFile("test_data/memecad/full_adder.sch");
  memecad::Sheet sheet = memecad::parseSheet(full_adder_original);
  std::string full_adder_output = memecad::writeSheet(sheet);
  EXPECT_EQ(removeWhitespace(full_adder_original), full_adder_output);
}

TEST_F(SchematicTest, Hierarchical0) {
  auto files = memecad::convertVerilogToKicadSchematics("test_data/memecad/memecad_map.json",
      {"test_data/memecad/hierarchical/tapb_top_level.v",
          "test_data/memecad/hierarchical/two_a_plus_b.v",
          "test_data/memecad/hierarchical/full_adder.v", "test_data/memecad/chip7408.v",
          "test_data/memecad/chip7432.v", "test_data/memecad/chip7486.v"},
      {"test_data/memecad/74xx.lib"});
  EXPECT_EQ(3u, files.size());
  for (const auto& file : files) {
    std::string golden = readFile("test_data/memecad/hierarchical/output/" + file.filename);
    EXPECT_EQ(golden, file.contents);
  }
}

TEST_F(SchematicTest, Alu0) {
  auto files = memecad::convertVerilogToKicadSchematics("test_data/memecad/memecad_map.json",
      {"test_data/memecad/alu/alu.v", "test_data/memecad/alu/alu_lookahead.v",
          "test_data/memecad/alu/sram17x8.v", "test_data/memecad/alu/alu_slice.v",
          "test_data/memecad/alu/sram16x32.v", "test_data/memecad/chip7408.v"},
      {"test_data/memecad/74xx.lib", "test_data/memecad/Memory_RAM.lib"});
  EXPECT_EQ(3u, files.size());
  for (const auto& file : files) {
    std::string golden = readFile("test_data/memecad/alu/output/" + file.filename);
    EXPECT_EQ(golden, file.contents);
  }
}

}  // namespace
