#include "verymeme/common.h"

#include "gtest/gtest.h"
#include "verymeme/file.h"

namespace {

using CommonTest = testing::Test;

TEST_F(CommonTest, BasenameAndStem) {
  const struct {
    std::string filename;
    std::string expected_basename;
    std::string expected_stem;
  } test_data[] = {
      {"1/2/3",      "3",      "3"},
      {"1/2/3.txt",  "3.txt",  "3"},
      {"1/2/3.a.b",  "3.a.b",  "3"},
      {"1/2/.3.a.b", ".3.a.b", ".3.a.b"},
      {"3",          "3",      "3"},
      {"3/",         "",       ""},
      {"",           "",       ""},
  };
  for (const auto& test : test_data) {
    EXPECT_EQ(test.expected_basename, basename(test.filename));
    EXPECT_EQ(test.expected_stem, stem(test.filename));
  }
}

}  // anonymous
