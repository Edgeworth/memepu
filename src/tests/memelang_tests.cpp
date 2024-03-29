// Copyright 2019 E.
#include <filesystem>
#include <set>

#include "gtest/gtest.h"
#include "memelang/parser.h"
#include "memelang/tokeniser.h"
#include "verymeme/file.h"
#include "verymeme/string_util.h"

namespace {

namespace fs = std::filesystem;

const std::string TEST_DIR = "test_data/memelang";

std::vector<std::pair<fs::path, fs::path>> getFileGoldenPairs(const std::string& golden_dir) {
  std::set<fs::path> paths;
  for (const auto& p : fs::directory_iterator(golden_dir))
    paths.insert(fs::path(p.path()).replace_extension());
  std::vector<std::pair<fs::path, fs::path>> pairs;
  for (const auto& p : paths) {
    const auto orig = fs::path(TEST_DIR) / fs::path(p).replace_extension(".meme").filename();
    const auto golden = fs::path(p).replace_extension(".golden");
    verify(
        fs::exists(orig) && fs::exists(golden), "missing golden pair for %s", p.string().c_str());
    pairs.emplace_back(orig, golden);
  }
  return pairs;
}

using MemelangTokeniserTest = testing::Test;

TEST_F(MemelangTokeniserTest, GoldenTest) {
  for (const auto& [orig_path, golden_path] : getFileGoldenPairs("test_data/memelang/lexing")) {
    const std::string& orig = readFile(orig_path.string());
    const std::string& golden = readFile(golden_path.string());
    const auto cts = memelang::FileContents(orig_path.filename().string(), orig);
    memelang::ast::Tokeniser tokeniser(&cts);
    std::vector<std::string> tokstrs;
    for (const auto& tok : tokeniser.tokenise()) tokstrs.push_back(tok.desc());
    EXPECT_EQ(golden, join(tokstrs, "\n", true)) << " on file " << orig_path.string();
  }
}

using MemelangParserTest = testing::Test;

TEST_F(MemelangParserTest, GoldenTest) {
  for (const auto& [orig_path, golden_path] : getFileGoldenPairs("test_data/memelang/parsing")) {
    const std::string& orig = readFile(orig_path.string());
    const std::string& golden = readFile(golden_path.string());
    std::vector<std::unique_ptr<memelang::FileContents>> cts;
    cts.emplace_back(std::make_unique<memelang::FileContents>(orig_path.filename().string(), orig));
    memelang::ast::Parser parser(cts);
    EXPECT_TRUE(parser.parse());
    EXPECT_EQ(golden, parser.astToString()) << " on file " << orig_path.string();
  }
}

}  // namespace
