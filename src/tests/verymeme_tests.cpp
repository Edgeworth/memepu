// Copyright 2019 Eliot Courtney.
#include "gtest/gtest.h"
#include "verymeme/file.h"
#include "verymeme/string_util.h"
#include "verymeme/geom.h"
#include "verymeme/tokeniser.h"
#include "verymeme/term.h"
#include "verymeme/bimap.h"
#include "verymeme/util.h"
#include <regex>
#include <fstream>
#include <filesystem>

namespace {

using VerymemeFileTest = testing::Test;

TEST_F(VerymemeFileTest, BasenameWithPath) {
  EXPECT_EQ("file.txt", basename("path/to/file.txt"));
  EXPECT_EQ("file", basename("path/to/file"));
  EXPECT_EQ("file.a.b", basename("path/file.a.b"));
}

TEST_F(VerymemeFileTest, BasenameWithoutPath) {
  EXPECT_EQ("file.txt", basename("file.txt"));
  EXPECT_EQ("file", basename("file"));
}

TEST_F(VerymemeFileTest, BasenameWithTrailingSlash) {
  EXPECT_EQ("", basename("path/"));
  EXPECT_EQ("", basename("/"));
}

TEST_F(VerymemeFileTest, BasenameEmpty) {
  EXPECT_EQ("", basename(""));
}

TEST_F(VerymemeFileTest, StemWithExtension) {
  EXPECT_EQ("file", stem("path/to/file.txt"));
  EXPECT_EQ("file", stem("file.cpp"));
  EXPECT_EQ("test", stem("test.h"));
}

TEST_F(VerymemeFileTest, StemWithMultipleExtensions) {
  EXPECT_EQ("file", stem("path/file.tar.gz"));
  EXPECT_EQ("file", stem("file.a.b.c"));
}

TEST_F(VerymemeFileTest, StemWithoutExtension) {
  EXPECT_EQ("file", stem("path/to/file"));
  EXPECT_EQ("file", stem("file"));
}

TEST_F(VerymemeFileTest, StemWithDotFile) {
  EXPECT_EQ(".gitignore", stem(".gitignore"));
  EXPECT_EQ(".hidden", stem("path/.hidden"));
  EXPECT_EQ(".file.txt", stem(".file.txt"));
}

TEST_F(VerymemeFileTest, ReadAndWriteFile) {
  const std::string test_file = "/tmp/test_file_verymeme.txt";
  const std::string test_content = "Hello, World!\nThis is a test.";

  writeFile(test_file, test_content);
  std::string read_content = readFile(test_file);

  EXPECT_EQ(test_content, read_content);
  std::filesystem::remove(test_file);
}

TEST_F(VerymemeFileTest, ReadAndWriteBinaryFile) {
  const std::string test_file = "/tmp/test_binary_verymeme.bin";
  const std::string test_content = std::string("\x00\x01\x02\xFF\xFE", 5);

  writeFile(test_file, test_content, true);
  std::string read_content = readFile(test_file, true);

  EXPECT_EQ(test_content, read_content);
  std::filesystem::remove(test_file);
}

using VerymemeStringUtilTest = testing::Test;

TEST_F(VerymemeStringUtilTest, TrimSpaces) {
  EXPECT_EQ("hello", trim("  hello  ", " "));
  EXPECT_EQ("test", trim("test", " "));
  EXPECT_EQ("a b c", trim("  a b c  ", " "));
}

TEST_F(VerymemeStringUtilTest, TrimTabs) {
  EXPECT_EQ("hello", trim("\t\thello\t\t", "\t"));
  EXPECT_EQ("test", trim("test", "\t"));
}

TEST_F(VerymemeStringUtilTest, TrimMultipleChars) {
  EXPECT_EQ("hello", trim(" \t hello \t ", " \t"));
  EXPECT_EQ("test", trim("\n\ntest\n\n", "\n"));
}

TEST_F(VerymemeStringUtilTest, ConvertFromHexValid) {
  EXPECT_EQ(255, convertFromHex("ff"));
  EXPECT_EQ(255, convertFromHex("FF"));
  EXPECT_EQ(0, convertFromHex("0"));
  EXPECT_EQ(4096, convertFromHex("1000"));
  EXPECT_EQ(0xDEADBEEF, convertFromHex("deadbeef"));
}

TEST_F(VerymemeStringUtilTest, ConvertFromHexInvalid) {
  EXPECT_EQ(INT64_MIN, convertFromHex("gg"));
  EXPECT_EQ(INT64_MIN, convertFromHex("xyz"));
  EXPECT_EQ(INT64_MIN, convertFromHex(""));
  EXPECT_EQ(INT64_MIN, convertFromHex("ff extra"));
}

TEST_F(VerymemeStringUtilTest, ConvertFromDecValid) {
  EXPECT_EQ(123, convertFromDec("123"));
  EXPECT_EQ(0, convertFromDec("0"));
  EXPECT_EQ(-456, convertFromDec("-456"));
  EXPECT_EQ(999999, convertFromDec("999999"));
}

TEST_F(VerymemeStringUtilTest, ConvertFromDecInvalid) {
  EXPECT_EQ(INT64_MIN, convertFromDec("abc"));
  EXPECT_EQ(INT64_MIN, convertFromDec(""));
  EXPECT_EQ(INT64_MIN, convertFromDec("123abc"));
  EXPECT_EQ(INT64_MIN, convertFromDec("12 34"));
}

TEST_F(VerymemeStringUtilTest, ConvertFromIntegerDecimal) {
  EXPECT_EQ(123, convertFromInteger("123"));
  EXPECT_EQ(0, convertFromInteger("0"));
  EXPECT_EQ(-456, convertFromInteger("-456"));
}

TEST_F(VerymemeStringUtilTest, ConvertFromIntegerHex) {
  EXPECT_EQ(255, convertFromInteger("0xff"));
  EXPECT_EQ(255, convertFromInteger("0xFF"));
  EXPECT_EQ(0, convertFromInteger("0x0"));
  EXPECT_EQ(4096, convertFromInteger("0x1000"));
}

TEST_F(VerymemeStringUtilTest, ConvertFromIntegerOctal) {
  EXPECT_EQ(8, convertFromInteger("010"));
  EXPECT_EQ(0, convertFromInteger("00"));
  EXPECT_EQ(64, convertFromInteger("0100"));
}

TEST_F(VerymemeStringUtilTest, ConvertFromIntegerOverflow) {
  // Test values that exceed int32_t range
  EXPECT_EQ(INT64_MIN, convertFromInteger("2147483648"));  // INT32_MAX + 1
  EXPECT_EQ(INT64_MIN, convertFromInteger("-2147483649")); // INT32_MIN - 1
}

TEST_F(VerymemeStringUtilTest, ConvertFromIntegerInvalid) {
  EXPECT_EQ(INT64_MIN, convertFromInteger("abc"));
  EXPECT_EQ(INT64_MIN, convertFromInteger(""));
  EXPECT_EQ(INT64_MIN, convertFromInteger("123abc"));
}

TEST_F(VerymemeStringUtilTest, JoinEmpty) {
  std::vector<std::string> empty;
  EXPECT_EQ("", join(empty, ","));
  EXPECT_EQ("", join(empty, ",", true));
}

TEST_F(VerymemeStringUtilTest, JoinSingle) {
  std::vector<std::string> single = {"one"};
  EXPECT_EQ("one", join(single, ","));
  EXPECT_EQ("one,", join(single, ",", true));
}

TEST_F(VerymemeStringUtilTest, JoinMultiple) {
  std::vector<std::string> items = {"one", "two", "three"};
  EXPECT_EQ("one,two,three", join(items, ","));
  EXPECT_EQ("one,two,three,", join(items, ",", true));
  EXPECT_EQ("one two three", join(items, " "));
  EXPECT_EQ("one\ntwo\nthree", join(items, "\n"));
}

TEST_F(VerymemeStringUtilTest, ConvertToHex) {
  EXPECT_EQ("ff", convertToHex(255));
  EXPECT_EQ("0", convertToHex(0));
  EXPECT_EQ("100", convertToHex(256));
}

TEST_F(VerymemeStringUtilTest, HexdumpVector) {
  std::vector<uint8_t> data = {0x00, 0x11, 0x22, 0x33, 0x44};
  std::string result = hexdump(data, 20);
  EXPECT_TRUE(result.find("00") != std::string::npos);
  EXPECT_TRUE(result.find("11") != std::string::npos);
  EXPECT_TRUE(result.find("22") != std::string::npos);
}

using VerymemeGeomTest = testing::Test;

TEST_F(VerymemeGeomTest, PointAddition) {
  Point p1{1, 2};
  Point p2{3, 4};
  Point result = p1 + p2;
  EXPECT_EQ(4, result.x);
  EXPECT_EQ(6, result.y);
}

TEST_F(VerymemeGeomTest, PointSubtraction) {
  Point p1{5, 7};
  Point p2{2, 3};
  Point result = p1 - p2;
  EXPECT_EQ(3, result.x);
  EXPECT_EQ(4, result.y);
}

TEST_F(VerymemeGeomTest, PointNegation) {
  Point p{3, -4};
  Point result = -p;
  EXPECT_EQ(-3, result.x);
  EXPECT_EQ(4, result.y);
}

TEST_F(VerymemeGeomTest, PointAddAssign) {
  Point p1{1, 2};
  Point p2{3, 4};
  p1 += p2;
  EXPECT_EQ(4, p1.x);
  EXPECT_EQ(6, p1.y);
}

TEST_F(VerymemeGeomTest, PointCross) {
  Point p1{2, 3};
  Point p2{4, 5};
  EXPECT_EQ(2 * 5 - 3 * 4, p1.cross(p2));
  EXPECT_EQ(-(2 * 5 - 3 * 4), p2.cross(p1));
}

TEST_F(VerymemeGeomTest, PointComparison) {
  Point p1{1, 2};
  Point p2{1, 2};
  Point p3{2, 1};

  EXPECT_TRUE(p1 == p2);
  EXPECT_FALSE(p1 == p3);
  EXPECT_TRUE(p1 != p3);
  EXPECT_FALSE(p1 != p2);
}

TEST_F(VerymemeGeomTest, RectInset) {
  Rect r{0, 0, 100, 100};
  r.inset(10, 20);
  EXPECT_EQ(10, r.left);
  EXPECT_EQ(20, r.top);
  EXPECT_EQ(90, r.right);
  EXPECT_EQ(80, r.bottom);
}

TEST_F(VerymemeGeomTest, RectOffset) {
  Rect r{10, 20, 30, 40};
  r.offset({5, 10});
  EXPECT_EQ(15, r.left);
  EXPECT_EQ(30, r.top);
  EXPECT_EQ(35, r.right);
  EXPECT_EQ(50, r.bottom);
}

TEST_F(VerymemeGeomTest, RectDimensions) {
  Rect r{10, 20, 50, 70};
  EXPECT_EQ(40, r.width());
  EXPECT_EQ(50, r.height());
}

TEST_F(VerymemeGeomTest, RectOriginAndBottomRight) {
  Rect r{10, 20, 50, 70};
  Point origin = r.origin();
  Point br = r.bottom_right();
  EXPECT_EQ(10, origin.x);
  EXPECT_EQ(20, origin.y);
  EXPECT_EQ(50, br.x);
  EXPECT_EQ(70, br.y);
}

TEST_F(VerymemeGeomTest, RectEmpty) {
  Rect r1{0, 0, 0, 0};
  Rect r2{10, 20, 10, 20};
  Rect r3{10, 20, 30, 40};

  EXPECT_TRUE(r1.empty());
  EXPECT_TRUE(r2.empty());
  EXPECT_FALSE(r3.empty());
}

TEST_F(VerymemeGeomTest, RectContains) {
  Rect outer{0, 0, 100, 100};
  Rect inner{10, 10, 90, 90};
  Rect partial{50, 50, 150, 150};

  EXPECT_TRUE(outer.contains(inner));
  EXPECT_FALSE(inner.contains(outer));
  EXPECT_FALSE(outer.contains(partial));
}

TEST_F(VerymemeGeomTest, RectUnion) {
  Rect r1{0, 0, 50, 50};
  Rect r2{25, 25, 75, 75};
  r1.unionRect(r2);

  EXPECT_EQ(0, r1.left);
  EXPECT_EQ(0, r1.top);
  EXPECT_EQ(75, r1.right);
  EXPECT_EQ(75, r1.bottom);
}

TEST_F(VerymemeGeomTest, RectUnionWithEmpty) {
  Rect r1{10, 10, 50, 50};
  Rect empty{0, 0, 0, 0};
  r1.unionRect(empty);

  EXPECT_EQ(10, r1.left);
  EXPECT_EQ(10, r1.top);
  EXPECT_EQ(50, r1.right);
  EXPECT_EQ(50, r1.bottom);
}

TEST_F(VerymemeGeomTest, RectEnclosing) {
  Point a{10, 20};
  Point b{50, 70};
  Rect r = Rect::enclosing(a, b);

  EXPECT_EQ(10, r.left);
  EXPECT_EQ(20, r.top);
  EXPECT_EQ(51, r.right);  // +1 to include point b
  EXPECT_EQ(71, r.bottom); // +1 to include point b
}

TEST_F(VerymemeGeomTest, RectSetDimensions) {
  Rect r{10, 20, 30, 40};
  r.set_width(100);
  r.set_height(200);

  EXPECT_EQ(100, r.width());
  EXPECT_EQ(200, r.height());
  EXPECT_EQ(10, r.left);
  EXPECT_EQ(20, r.top);
}

TEST_F(VerymemeGeomTest, ClampFunction) {
  EXPECT_EQ(5, clamp(0, 10, 5));
  EXPECT_EQ(0, clamp(0, 10, -5));
  EXPECT_EQ(10, clamp(0, 10, 15));
  EXPECT_EQ(0, clamp(0, 10, 0));
  EXPECT_EQ(10, clamp(0, 10, 10));
}

using VerymemeTokeniserTest = testing::Test;

TEST_F(VerymemeTokeniserTest, BasicTokenization) {
  std::string data = "hello 123 world 456";
  std::regex token(R"([^\s]+)");
  Tokeniser tok(data, token);

  EXPECT_TRUE(tok.hasTokens());
  EXPECT_EQ("hello", tok.next());
  EXPECT_EQ("123", tok.next());
  EXPECT_EQ("world", tok.next());
  EXPECT_EQ("456", tok.next());
  EXPECT_FALSE(tok.hasTokens());
}

TEST_F(VerymemeTokeniserTest, PeekAhead) {
  std::string data = "a b c d";
  std::regex token(R"([^\s]+)");
  Tokeniser tok(data, token);

  EXPECT_EQ("a", tok.peek(0));
  EXPECT_EQ("b", tok.peek(1));
  EXPECT_EQ("c", tok.peek(2));
  EXPECT_EQ("a", tok.next());
  EXPECT_EQ("b", tok.peek(0));
}

TEST_F(VerymemeTokeniserTest, ExpectSuccess) {
  std::string data = "hello world";
  std::regex token(R"([^\s]+)");
  Tokeniser tok(data, token);

  EXPECT_NO_THROW(tok.expect({"hello", "world"}));
  EXPECT_FALSE(tok.hasTokens());
}

TEST_F(VerymemeTokeniserTest, SubstrExtraction) {
  std::string data = "one two three four";
  std::regex token(R"([^\s]+)");
  Tokeniser tok(data, token);

  tok.next(); // skip "one"
  std::string result = tok.substr(1, 3);
  EXPECT_TRUE(result.find("two") != std::string::npos);
  EXPECT_TRUE(result.find("three") != std::string::npos);
}

using VerymemeTermTest = testing::Test;

TEST_F(VerymemeTermTest, ColorConversionBasic) {
  std::string result = convertToColor("test", TermColor::FG_RED);
  EXPECT_TRUE(result.find("test") != std::string::npos);
  EXPECT_TRUE(result.find("\033[") != std::string::npos);
  EXPECT_TRUE(result.find("\033[0m") != std::string::npos);
}

TEST_F(VerymemeTermTest, ColorConversionWithBackground) {
  std::string result = convertToColor("test", TermColor::FG_GREEN, TermColor::BG_BLUE);
  EXPECT_TRUE(result.find("test") != std::string::npos);
  EXPECT_TRUE(result.find("32") != std::string::npos); // FG_GREEN code
  EXPECT_TRUE(result.find("44") != std::string::npos); // BG_BLUE code
}

TEST_F(VerymemeTermTest, ColorConversionWithStyle) {
  std::string result = convertToColor("test", TermColor::FG_YELLOW, TermColor::BG_DEFAULT, TermStyle::BOLD);
  EXPECT_TRUE(result.find("test") != std::string::npos);
  EXPECT_TRUE(result.find("1;") != std::string::npos); // BOLD code
}

TEST_F(VerymemeTermTest, EmptyString) {
  std::string result = convertToColor("", TermColor::FG_RED);
  EXPECT_TRUE(result.find("\033[") != std::string::npos);
}

using VerymemeBimapTest = testing::Test;

TEST_F(VerymemeBimapTest, InsertAndLookup) {
  Bimap<int, std::string> bm;
  EXPECT_TRUE(bm.insert(1, "one"));
  EXPECT_TRUE(bm.insert(2, "two"));

  EXPECT_EQ("one", bm[1]);
  EXPECT_EQ("two", bm[2]);
}

TEST_F(VerymemeBimapTest, DuplicateKeyRejected) {
  Bimap<int, std::string> bm;
  EXPECT_TRUE(bm.insert(1, "one"));
  EXPECT_FALSE(bm.insert(1, "another"));
  EXPECT_EQ("one", bm[1]);
}

TEST_F(VerymemeBimapTest, DuplicateValueRejected) {
  Bimap<int, std::string> bm;
  EXPECT_TRUE(bm.insert(1, "same"));
  EXPECT_FALSE(bm.insert(2, "same"));
}

TEST_F(VerymemeBimapTest, ContainsKey) {
  Bimap<int, std::string> bm;
  bm.insert(1, "one");

  EXPECT_TRUE(bm.containsKey(1));
  EXPECT_FALSE(bm.containsKey(2));
}

TEST_F(VerymemeBimapTest, KeyForValue) {
  Bimap<int, std::string> bm;
  bm.insert(1, "one");
  bm.insert(2, "two");
  bm.insert(3, "three");

  EXPECT_EQ(1, bm.keyForValue("one"));
  EXPECT_EQ(2, bm.keyForValue("two"));
  EXPECT_EQ(3, bm.keyForValue("three"));
}

TEST_F(VerymemeBimapTest, MultipleInserts) {
  Bimap<std::string, int> bm;
  EXPECT_TRUE(bm.insert("a", 1));
  EXPECT_TRUE(bm.insert("b", 2));
  EXPECT_TRUE(bm.insert("c", 3));
  EXPECT_TRUE(bm.insert("d", 4));

  EXPECT_EQ(1, bm["a"]);
  EXPECT_EQ(2, bm["b"]);
  EXPECT_EQ(3, bm["c"]);
  EXPECT_EQ(4, bm["d"]);
}

using VerymemeUtilTest = testing::Test;

TEST_F(VerymemeUtilTest, GetDefaultWithKey) {
  std::map<std::string, int> m = {{"a", 1}, {"b", 2}};
  EXPECT_EQ(1, getDefault(m, std::string("a"), 99));
  EXPECT_EQ(2, getDefault(m, std::string("b"), 99));
}

TEST_F(VerymemeUtilTest, GetDefaultWithoutKey) {
  std::map<std::string, int> m = {{"a", 1}, {"b", 2}};
  EXPECT_EQ(99, getDefault(m, std::string("c"), 99));
  EXPECT_EQ(0, getDefault(m, std::string("d"), 0));
}

TEST_F(VerymemeUtilTest, ReverseVector) {
  std::vector<int> v = {1, 2, 3, 4, 5};
  auto rev = reverse(std::move(v));
  EXPECT_EQ(5, rev.size());
  EXPECT_EQ(5, rev[0]);
  EXPECT_EQ(4, rev[1]);
  EXPECT_EQ(3, rev[2]);
  EXPECT_EQ(2, rev[3]);
  EXPECT_EQ(1, rev[4]);
}

TEST_F(VerymemeUtilTest, ReverseEmptyVector) {
  std::vector<int> v;
  auto rev = reverse(std::move(v));
  EXPECT_TRUE(rev.empty());
}

TEST_F(VerymemeUtilTest, ReverseSingleElement) {
  std::vector<int> v = {42};
  auto rev = reverse(std::move(v));
  EXPECT_EQ(1, rev.size());
  EXPECT_EQ(42, rev[0]);
}

}  // namespace
