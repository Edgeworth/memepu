#include <filesystem>
#include <set>

#include "gtest/gtest.h"
#include "memelang/parser.h"
#include "memelang/tokeniser.h"
#include "verymeme/file.h"
#include "verymeme/string_util.h"

namespace {

namespace fs = std::filesystem;

std::vector<std::pair<fs::path, fs::path>> getFileGoldenPairs(const std::string& dir) {
  std::set<fs::path> paths;
  for (const auto& p : fs::directory_iterator(dir))
    paths.insert(fs::path(p.path()).replace_extension());
  std::vector<std::pair<fs::path, fs::path>> pairs;
  for (const auto& p : paths) {
    const auto orig = fs::path(p).replace_extension(".meme");
    const auto golden = fs::path(p).replace_extension(".golden");
    verify_expr(
        fs::exists(orig) && fs::exists(golden), "missing golden pair for %s", p.string().c_str());
    pairs.emplace_back(orig, golden);
  }
  return pairs;
}

using MemelangTokeniserTest = testing::Test;
using memelang::Tok;

TEST_F(MemelangTokeniserTest, GoldenTest) {
  for (const auto& [orig_path, golden_path] : getFileGoldenPairs("test_data/memelang/lexing")) {
    const std::string& orig = readFile(orig_path.string());
    const std::string& golden = readFile(golden_path.string());
    const auto cts = memelang::FileContents(orig_path.filename().string(), orig);
    memelang::Tokeniser tokeniser(&cts);
    std::vector<std::string> tokstrs;
    for (const auto& tok : tokeniser.tokenise()) tokstrs.push_back(tok.desc(&cts));
    EXPECT_EQ(golden, join(tokstrs, "\n", true)) << " on file " << orig_path.string();
  }
}

using MemelangParserTest = testing::Test;

TEST_F(MemelangParserTest, GoldenTest) {
  for (const auto& [orig_path, golden_path] : getFileGoldenPairs("test_data/memelang/parsing")) {
    const std::string& orig = readFile(orig_path.string());
    const std::string& golden = readFile(golden_path.string());
    const auto cts = memelang::FileContents(orig_path.filename().string(), orig);
    memelang::Parser parser(&cts, memelang::Tokeniser(&cts).tokenise());
    EXPECT_TRUE(parser.parse());
    EXPECT_EQ(golden, parser.astToString()) << " on file " << orig_path.string();
  }
}

}  // namespace
