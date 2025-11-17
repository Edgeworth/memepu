// Copyright 2019 Eliot Courtney.
#include <regex>

#include "gtest/gtest.h"
#include "memecad/parser.h"
#include "memecad/yosys_module.h"
#include "memecad/types.h"
#include "verymeme/file.h"
#include "verymeme/geom.h"

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

using MemecadTypesTest = testing::Test;

TEST_F(MemecadTypesTest, DirectionEnum) {
  using memecad::Direction;
  EXPECT_NE(Direction::LEFT, Direction::RIGHT);
  EXPECT_NE(Direction::UP, Direction::DOWN);
  EXPECT_NE(Direction::LEFT, Direction::UP);
}

TEST_F(MemecadTypesTest, OrientationEnum) {
  using memecad::Orientation;
  EXPECT_NE(Orientation::HORIZONTAL, Orientation::VERTICAL);
}

TEST_F(MemecadTypesTest, PinTypeEnum) {
  using memecad::PinType;
  EXPECT_NE(PinType::INPUT, PinType::OUTPUT);
  EXPECT_NE(PinType::INPUT, PinType::BIDIRECTIONAL);
  EXPECT_NE(PinType::POWER_IN, PinType::POWER_OUT);
  EXPECT_NE(PinType::TRISTATE, PinType::PASSIVE);
  EXPECT_NE(PinType::OPEN_COLLECTOR, PinType::OPEN_EMITTER);
  EXPECT_NE(PinType::NOT_CONNECTED, PinType::INPUT);
}

TEST_F(MemecadTypesTest, SheetWireComparison) {
  memecad::Sheet::Wire w1{{0, 0}, {10, 10}};
  memecad::Sheet::Wire w2{{0, 0}, {10, 10}};
  memecad::Sheet::Wire w3{{0, 0}, {20, 20}};

  EXPECT_TRUE(w1 == w2);
  EXPECT_FALSE(w1 == w3);
  EXPECT_TRUE(w1 != w3);
}

TEST_F(MemecadTypesTest, RefFieldComparison) {
  memecad::Sheet::RefField rf1;
  rf1.num = 0;
  rf1.text = "test";
  rf1.type = memecad::PinType::INPUT;
  rf1.side = memecad::Direction::LEFT;

  memecad::Sheet::RefField rf2;
  rf2.num = 0;
  rf2.text = "test";
  rf2.type = memecad::PinType::INPUT;
  rf2.side = memecad::Direction::LEFT;

  memecad::Sheet::RefField rf3;
  rf3.num = 1;
  rf3.text = "different";
  rf3.type = memecad::PinType::OUTPUT;
  rf3.side = memecad::Direction::RIGHT;

  EXPECT_TRUE(rf1 == rf2);
  EXPECT_FALSE(rf1 == rf3);
}

TEST_F(MemecadTypesTest, DefaultDimension) {
  EXPECT_EQ(50, memecad::DEFAULT_DIMENSION);
}

TEST_F(MemecadTypesTest, RefFieldHierarchicalOffset) {
  EXPECT_EQ(2, memecad::Sheet::RefField::HIERARCHICAL_REF_OFFSET);
}

TEST_F(MemecadTypesTest, LabelTypes) {
  using LabelType = memecad::Sheet::Label::Type;
  EXPECT_NE(LabelType::GLOBAL, LabelType::LOCAL);
  EXPECT_NE(LabelType::HIERARCHICAL, LabelType::NOTES);
  EXPECT_NE(LabelType::NOCONNECT, LabelType::GLOBAL);
}

TEST_F(MemecadTypesTest, LabelNetTypes) {
  using NetType = memecad::Sheet::Label::NetType;
  EXPECT_NE(NetType::INPUT, NetType::OUTPUT);
  EXPECT_NE(NetType::BIDIRECTIONAL, NetType::TRISTATE);
  EXPECT_NE(NetType::INPUT, NetType::PASSIVE);
  EXPECT_NE(NetType::OUTPUT, NetType::PASSIVE);
}

TEST_F(MemecadTypesTest, ComponentComparison) {
  memecad::Sheet::Component c1;
  c1.name = "comp1";
  c1.ref = "U1";
  c1.subcomponent = 1;

  memecad::Sheet::Component c2;
  c2.name = "comp1";
  c2.ref = "U1";
  c2.subcomponent = 1;

  memecad::Sheet::Component c3;
  c3.name = "comp2";
  c3.ref = "U2";
  c3.subcomponent = 2;

  EXPECT_TRUE(c1 == c2);
  EXPECT_FALSE(c1 == c3);
}

TEST_F(MemecadTypesTest, RefComparison) {
  memecad::Sheet::Ref ref1;
  ref1.name = "sheet1";
  ref1.filename = "file1.sch";

  memecad::Sheet::Ref ref2;
  ref2.name = "sheet1";
  ref2.filename = "file1.sch";

  memecad::Sheet::Ref ref3;
  ref3.name = "sheet2";
  ref3.filename = "file2.sch";

  EXPECT_TRUE(ref1 == ref2);
  EXPECT_FALSE(ref1 == ref3);
}

TEST_F(MemecadTypesTest, FieldComparison) {
  memecad::Sheet::Field f1;
  f1.num = 0;
  f1.text = "field1";

  memecad::Sheet::Field f2;
  f2.num = 0;
  f2.text = "field1";

  memecad::Sheet::Field f3;
  f3.num = 1;
  f3.text = "field2";

  EXPECT_TRUE(f1 == f2);
  EXPECT_FALSE(f1 == f3);
}

TEST_F(MemecadTypesTest, UnitSwappableEnum) {
  using UnitSwappable = memecad::Lib::Component::UnitSwappable;
  EXPECT_NE(UnitSwappable::SWAPPABLE, UnitSwappable::UNSWAPPABLE);
}

TEST_F(MemecadTypesTest, RefFieldDefaults) {
  memecad::Sheet::RefField rf;
  EXPECT_EQ(0, rf.num);
  EXPECT_EQ("", rf.text);
  EXPECT_EQ(memecad::DEFAULT_DIMENSION, rf.dimension);
}

TEST_F(MemecadTypesTest, LabelDefaults) {
  memecad::Sheet::Label label;
  EXPECT_EQ("", label.text);
  EXPECT_FALSE(label.italic);
  EXPECT_FALSE(label.bold);
  EXPECT_EQ(memecad::DEFAULT_DIMENSION, label.dimension);
}

TEST_F(MemecadTypesTest, ComponentDefaults) {
  memecad::Sheet::Component comp;
  EXPECT_EQ("", comp.name);
  EXPECT_EQ("", comp.ref);
  EXPECT_EQ(-1, comp.subcomponent);
  EXPECT_EQ("DEADBEEF", comp.timestamp);
}

TEST_F(MemecadTypesTest, RefDefaults) {
  memecad::Sheet::Ref ref;
  EXPECT_EQ("DEADBEEF", ref.timestamp);
  EXPECT_EQ("", ref.name);
  EXPECT_EQ("", ref.filename);
  EXPECT_EQ(1000, ref.width);
  EXPECT_EQ(1000, ref.height);
}

TEST_F(MemecadTypesTest, LibPinDefaults) {
  memecad::Lib::Pin pin;
  EXPECT_EQ("", pin.name);
  EXPECT_EQ("", pin.id);
  EXPECT_EQ(-1, pin.subcomponent);
}

TEST_F(MemecadTypesTest, LibComponentDefaults) {
  memecad::Lib::Component comp;
  EXPECT_EQ("", comp.ref);
  EXPECT_EQ(-1, comp.unit_count);
}

TEST_F(MemecadTypesTest, RefOffset) {
  memecad::Sheet::Ref ref;
  ref.p = {100, 200};
  ref.offset({10, 20});
  EXPECT_EQ(110, ref.p.x);
  EXPECT_EQ(220, ref.p.y);
}

TEST_F(MemecadTypesTest, ComponentOffset) {
  memecad::Sheet::Component comp;
  comp.p = {50, 75};
  comp.offset({25, 15});
  EXPECT_EQ(75, comp.p.x);
  EXPECT_EQ(90, comp.p.y);
}

}  // namespace
