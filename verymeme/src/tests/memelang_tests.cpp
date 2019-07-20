#include "gtest/gtest.h"
#include "memelang/tokeniser.h"
#include "verymeme/file.h"

namespace {

using MemelangTokeniserTest = testing::Test;

TEST_F(MemelangTokeniserTest, BasicTest) {
  const std::string expression = readFile("test_data/memelang/expression.meme");
  const auto contents = memelang::FileContents("expression.meme", expression);
  memelang::Tokeniser tokeniser(&contents);
  auto tokens = tokeniser.tokenise();
  for (const auto& token : tokens) {
    printf("%s\n", token.toString(&contents).c_str());
  }
  // TODO
//  EXPECT_EQ({}, tokens);
}

TEST_F(MemelangTokeniserTest, ParsingTest) {
  const std::string expression = readFile("test_data/memelang/parsing.meme");
  const auto contents = memelang::FileContents("parsing.meme", expression);
  memelang::Tokeniser tokeniser(&contents);
  auto tokens = tokeniser.tokenise();
  for (const auto& token : tokens) {
    printf("%s\n", token.toString(&contents).c_str());
  }
//  EXPECT_EQ({}, tokens);
}

}  // anonymous
