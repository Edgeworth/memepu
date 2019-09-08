
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "memelang/tokeniser.h"
#include "verymeme/file.h"

namespace {

using MemelangTokeniserTest = testing::Test;
using memelang::Tok;
using ::testing::ElementsAreArray;

TEST_F(MemelangTokeniserTest, BasicTest) {
  const std::string expression = readFile("test_data/memelang/lexing/expression.meme");
  const auto contents = memelang::FileContents("expression.meme", expression);
  memelang::Tokeniser tokeniser(&contents);
  auto tokens = tokeniser.tokenise();
  std::vector<Tok::Type> types;
  for (const auto& tok : tokens) types.push_back(tok.type);
  const Tok::Type expected[] = {Tok::FN, Tok::IDENT, Tok::LPAREN, Tok::RPAREN, Tok::I32,
      Tok::LBRACE, Tok::MINUS, Tok::LPAREN, Tok::INT_LIT, Tok::PLUS, Tok::INT_LIT, Tok::RPAREN,
      Tok::ASTERISK, Tok::LPAREN, Tok::INT_LIT, Tok::FSLASH, Tok::INT_LIT, Tok::RPAREN, Tok::MINUS,
      Tok::MINUS, Tok::INT_LIT, Tok::SEMICOLON, Tok::IDENT, Tok::DMINUS, Tok::INT_LIT,
      Tok::SEMICOLON, Tok::IDENT, Tok::DMINUS, Tok::MINUS, Tok::IDENT, Tok::SEMICOLON, Tok::DMINUS,
      Tok::MINUS, Tok::IDENT, Tok::DPLUS, Tok::PLUS, Tok::IDENT, Tok::DMINUS, Tok::MINUS,
      Tok::IDENT, Tok::SEMICOLON, Tok::RETURN, Tok::INT_LIT, Tok::SEMICOLON, Tok::RBRACE};
  EXPECT_THAT(types, ElementsAreArray(expected));
}

TEST_F(MemelangTokeniserTest, ParsingTest) {
  const std::string expression = readFile("test_data/memelang/lexing/complex.meme");
  const auto contents = memelang::FileContents("parsing.meme", expression);
  memelang::Tokeniser tokeniser(&contents);
  auto tokens = tokeniser.tokenise();
  std::vector<Tok::Type> types;
  for (const auto& tok : tokens) types.push_back(tok.type);
  const Tok::Type expected[] = {Tok::ENUM, Tok::IDENT, Tok::LBRACE, Tok::RBRACE, Tok::ENUM,
      Tok::IDENT, Tok::LBRACE, Tok::IDENT, Tok::COMMA, Tok::IDENT, Tok::COMMA, Tok::IDENT,
      Tok::LPAREN, Tok::IDENT, Tok::RPAREN, Tok::COMMA, Tok::RBRACE, Tok::ENUM, Tok::IDENT,
      Tok::LANGLE, Tok::IDENT, Tok::COMMA, Tok::IDENT, Tok::RANGLE, Tok::LBRACE, Tok::IDENT,
      Tok::LPAREN, Tok::IDENT, Tok::RPAREN, Tok::COMMA, Tok::IDENT, Tok::LPAREN, Tok::IDENT,
      Tok::RPAREN, Tok::COMMA, Tok::RBRACE, Tok::FN, Tok::IDENT, Tok::LANGLE, Tok::IDENT,
      Tok::RANGLE, Tok::LPAREN, Tok::CONST, Tok::ASTERISK, Tok::IDENT, Tok::IDENT, Tok::RPAREN,
      Tok::IDENT, Tok::LBRACE, Tok::RBRACE, Tok::STRUCT, Tok::IDENT, Tok::LBRACE, Tok::I8,
      Tok::IDENT, Tok::SEMICOLON, Tok::BIT, Tok::IDENT, Tok::COLON, Tok::INT_LIT, Tok::SEMICOLON,
      Tok::BOOL, Tok::IDENT, Tok::SEMICOLON, Tok::STATIC, Tok::FN, Tok::IDENT, Tok::LPAREN,
      Tok::RPAREN, Tok::IDENT, Tok::LBRACE, Tok::RBRACE, Tok::RBRACE, Tok::INTF, Tok::IDENT,
      Tok::LBRACE, Tok::RBRACE, Tok::INTF, Tok::IDENT, Tok::LANGLE, Tok::IDENT, Tok::RANGLE,
      Tok::LBRACE, Tok::RBRACE, Tok::IMPL, Tok::IDENT, Tok::FOR, Tok::IDENT, Tok::LBRACE,
      Tok::RBRACE, Tok::IMPL, Tok::LANGLE, Tok::IDENT, Tok::RANGLE, Tok::IDENT, Tok::LANGLE,
      Tok::IDENT, Tok::RANGLE, Tok::FOR, Tok::IDENT, Tok::LBRACE, Tok::RBRACE, Tok::FN, Tok::IDENT,
      Tok::LPAREN, Tok::RPAREN, Tok::I8, Tok::LBRACE, Tok::ASM, Tok::ASM, Tok::IDENT, Tok::IDENT,
      Tok::SEMICOLON, Tok::IDENT, Tok::IDENT, Tok::EQUAL, Tok::IDENT, Tok::LBRACE, Tok::RBRACE,
      Tok::SEMICOLON, Tok::IDENT, Tok::IDENT, Tok::EQUAL, Tok::IDENT, Tok::LPAREN, Tok::IDENT,
      Tok::RPAREN, Tok::SEMICOLON, Tok::IDENT, Tok::DOT, Tok::IDENT, Tok::EQUAL, Tok::INT_LIT,
      Tok::SEMICOLON, Tok::I8, Tok::IDENT, Tok::EQUAL, Tok::INT_LIT, Tok::SEMICOLON, Tok::I8,
      Tok::IDENT, Tok::EQUAL, Tok::INT_LIT, Tok::SEMICOLON, Tok::LSQUARE, Tok::INT_LIT,
      Tok::RSQUARE, Tok::IDENT, Tok::EQUAL, Tok::LSQUARE, Tok::RSQUARE, Tok::SEMICOLON, Tok::IDENT,
      Tok::LSQUARE, Tok::INT_LIT, Tok::MINUS, Tok::INT_LIT, Tok::RSQUARE, Tok::EQUAL, Tok::BOOL_LIT,
      Tok::DAMPERSAND, Tok::LPAREN, Tok::BOOL_LIT, Tok::DBAR, Tok::IDENT, Tok::RPAREN,
      Tok::QUESTION, Tok::IDENT, Tok::AMPERSAND, Tok::INT_LIT, Tok::COLON, Tok::INT_LIT, Tok::IDENT,
      Tok::INT_LIT, Tok::BAR, Tok::INT_LIT, Tok::SEMICOLON, Tok::IF, Tok::IDENT, Tok::DEQUAL,
      Tok::IDENT, Tok::DOT, Tok::IDENT, Tok::DBAR, Tok::IDENT, Tok::LSQUARE, Tok::INT_LIT,
      Tok::MINUS, Tok::INT_LIT, Tok::RSQUARE, Tok::NEQUAL, Tok::IDENT, Tok::DBAR, Tok::IDENT,
      Tok::LTEQUAL, Tok::IDENT, Tok::DBAR, Tok::IDENT, Tok::RANGLE, Tok::IDENT, Tok::DBAR,
      Tok::IDENT, Tok::GTEQUAL, Tok::IDENT, Tok::DOT, Tok::IDENT, Tok::DBAR, Tok::IDENT,
      Tok::LANGLE, Tok::IDENT, Tok::LSQUARE, Tok::INT_LIT, Tok::RSQUARE, Tok::LBRACE, Tok::IDENT,
      Tok::LANGLE, Tok::I8, Tok::RANGLE, Tok::LPAREN, Tok::IDENT, Tok::RPAREN, Tok::SEMICOLON,
      Tok::RBRACE, Tok::ELSE, Tok::IF, Tok::BOOL_LIT, Tok::LBRACE, Tok::RBRACE, Tok::ELSE,
      Tok::LBRACE, Tok::MATCH, Tok::IDENT, Tok::LBRACE, Tok::INT_LIT, Tok::LBRACE, Tok::RBRACE,
      Tok::INT_LIT, Tok::LBRACE, Tok::RBRACE, Tok::INT_LIT, Tok::LBRACE, Tok::IDENT, Tok::LPAREN,
      Tok::INT_LIT, Tok::RPAREN, Tok::SEMICOLON, Tok::RBRACE, Tok::RBRACE, Tok::MATCH, Tok::IDENT,
      Tok::LBRACE, Tok::IDENT, Tok::LBRACE, Tok::RBRACE, Tok::IDENT, Tok::LBRACE, Tok::RBRACE,
      Tok::IDENT, Tok::LPAREN, Tok::IDENT, Tok::RPAREN, Tok::LBRACE, Tok::IDENT, Tok::LPAREN,
      Tok::IDENT, Tok::RPAREN, Tok::SEMICOLON, Tok::RBRACE, Tok::RBRACE, Tok::RBRACE, Tok::CONST,
      Tok::AUTO, Tok::IDENT, Tok::EQUAL, Tok::MINUS, Tok::LPAREN, Tok::INT_LIT, Tok::PLUS,
      Tok::INT_LIT, Tok::RPAREN, Tok::ASTERISK, Tok::LPAREN, Tok::INT_LIT, Tok::FSLASH,
      Tok::INT_LIT, Tok::RPAREN, Tok::MINUS, Tok::MINUS, Tok::INT_LIT, Tok::SEMICOLON, Tok::IDENT,
      Tok::MINUS, Tok::MINUS, Tok::INT_LIT, Tok::PERCENT, Tok::INT_LIT, Tok::SEMICOLON, Tok::IDENT,
      Tok::MINUS, Tok::MINUS, Tok::MINUS, Tok::IDENT, Tok::SEMICOLON, Tok::IDENT, Tok::SEMICOLON,
      Tok::IDENT, Tok::SEMICOLON, Tok::IDENT, Tok::SEMICOLON, Tok::IDENT, Tok::SEMICOLON,
      Tok::IDENT, Tok::SEMICOLON, Tok::INT_LIT, Tok::DOT, Tok::INT_LIT, Tok::SEMICOLON, Tok::FOR,
      Tok::I8, Tok::IDENT, Tok::EQUAL, Tok::INT_LIT, Tok::SEMICOLON, Tok::IDENT, Tok::LANGLE,
      Tok::INT_LIT, Tok::SEMICOLON, Tok::IDENT, Tok::PLUS, Tok::PLUS, Tok::LBRACE, Tok::RETURN,
      Tok::INT_LIT, Tok::SEMICOLON, Tok::RBRACE, Tok::COMMENT, Tok::RETURN, Tok::INT_LIT,
      Tok::SEMICOLON, Tok::RBRACE};
  //  EXPECT_THAT(types, ElementsAreArray(expected));
}

}  // namespace
