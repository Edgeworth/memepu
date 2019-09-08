
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "memelang/tokeniser.h"
#include "verymeme/file.h"

namespace {

using MemelangTokeniserTest = testing::Test;
using Token = memelang::Token;
using ::testing::ElementsAreArray;

TEST_F(MemelangTokeniserTest, BasicTest) {
  const std::string expression = readFile("test_data/memelang/expression.meme");
  const auto contents = memelang::FileContents("expression.meme", expression);
  memelang::Tokeniser tokeniser(&contents);
  auto tokens = tokeniser.tokenise();
  std::vector<Token::Type> types;
  for (const auto& tok : tokens) types.push_back(tok.type);
  // TODO: Change DMINUS back to MINUS MINUS? => ---a vs a--- => need to do in parser?
  const Token::Type expected[] = {Token::FN, Token::IDENT, Token::LPAREN, Token::RPAREN, Token::I32,
      Token::LBRACE, Token::MINUS, Token::LPAREN, Token::INT_LIT, Token::PLUS, Token::INT_LIT,
      Token::RPAREN, Token::ASTERISK, Token::LPAREN, Token::INT_LIT, Token::FSLASH, Token::INT_LIT,
      Token::RPAREN, Token::MINUS, Token::MINUS, Token::INT_LIT, Token::SEMICOLON, Token::IDENT,
      Token::MINUS, Token::MINUS, Token::INT_LIT, Token::SEMICOLON, Token::IDENT, Token::MINUS,
      Token::MINUS, Token::MINUS, Token::IDENT, Token::SEMICOLON, Token::RETURN, Token::INT_LIT,
      Token::SEMICOLON, Token::RBRACE};
  //  EXPECT_THAT(types, ElementsAreArray(expected));
}

TEST_F(MemelangTokeniserTest, ParsingTest) {
  const std::string expression = readFile("test_data/memelang/parsing.meme");
  const auto contents = memelang::FileContents("parsing.meme", expression);
  memelang::Tokeniser tokeniser(&contents);
  auto tokens = tokeniser.tokenise();
  std::vector<Token::Type> types;
  for (const auto& tok : tokens) types.push_back(tok.type);
  const Token::Type expected[] = {Token::ENUM, Token::IDENT, Token::LBRACE, Token::RBRACE,
      Token::ENUM, Token::IDENT, Token::LBRACE, Token::IDENT, Token::COMMA, Token::IDENT,
      Token::COMMA, Token::IDENT, Token::LPAREN, Token::IDENT, Token::RPAREN, Token::COMMA,
      Token::RBRACE, Token::ENUM, Token::IDENT, Token::LANGLE, Token::IDENT, Token::COMMA,
      Token::IDENT, Token::RANGLE, Token::LBRACE, Token::IDENT, Token::LPAREN, Token::IDENT,
      Token::RPAREN, Token::COMMA, Token::IDENT, Token::LPAREN, Token::IDENT, Token::RPAREN,
      Token::COMMA, Token::RBRACE, Token::FN, Token::IDENT, Token::LANGLE, Token::IDENT,
      Token::RANGLE, Token::LPAREN, Token::CONST, Token::ASTERISK, Token::IDENT, Token::IDENT,
      Token::RPAREN, Token::IDENT, Token::LBRACE, Token::RBRACE, Token::STRUCT, Token::IDENT,
      Token::LBRACE, Token::I8, Token::IDENT, Token::SEMICOLON, Token::BIT, Token::IDENT,
      Token::COLON, Token::INT_LIT, Token::SEMICOLON, Token::BOOL, Token::IDENT, Token::SEMICOLON,
      Token::STATIC, Token::FN, Token::IDENT, Token::LPAREN, Token::RPAREN, Token::IDENT,
      Token::LBRACE, Token::RBRACE, Token::RBRACE, Token::INTF, Token::IDENT, Token::LBRACE,
      Token::RBRACE, Token::INTF, Token::IDENT, Token::LANGLE, Token::IDENT, Token::RANGLE,
      Token::LBRACE, Token::RBRACE, Token::IMPL, Token::IDENT, Token::FOR, Token::IDENT,
      Token::LBRACE, Token::RBRACE, Token::IMPL, Token::LANGLE, Token::IDENT, Token::RANGLE,
      Token::IDENT, Token::LANGLE, Token::IDENT, Token::RANGLE, Token::FOR, Token::IDENT,
      Token::LBRACE, Token::RBRACE, Token::FN, Token::IDENT, Token::LPAREN, Token::RPAREN,
      Token::I8, Token::LBRACE, Token::ASM, Token::ASM, Token::IDENT, Token::IDENT,
      Token::SEMICOLON, Token::IDENT, Token::IDENT, Token::EQUAL, Token::IDENT, Token::LBRACE,
      Token::RBRACE, Token::SEMICOLON, Token::IDENT, Token::IDENT, Token::EQUAL, Token::IDENT,
      Token::LPAREN, Token::IDENT, Token::RPAREN, Token::SEMICOLON, Token::IDENT, Token::DOT,
      Token::IDENT, Token::EQUAL, Token::INT_LIT, Token::SEMICOLON, Token::I8, Token::IDENT,
      Token::EQUAL, Token::INT_LIT, Token::SEMICOLON, Token::I8, Token::IDENT, Token::EQUAL,
      Token::INT_LIT, Token::SEMICOLON, Token::LSQUARE, Token::INT_LIT, Token::RSQUARE,
      Token::IDENT, Token::EQUAL, Token::LSQUARE, Token::RSQUARE, Token::SEMICOLON, Token::IDENT,
      Token::LSQUARE, Token::INT_LIT, Token::MINUS, Token::INT_LIT, Token::RSQUARE, Token::EQUAL,
      Token::BOOL_LIT, Token::DAMPERSAND, Token::LPAREN, Token::BOOL_LIT, Token::DBAR, Token::IDENT,
      Token::RPAREN, Token::QUESTION, Token::IDENT, Token::AMPERSAND, Token::INT_LIT, Token::COLON,
      Token::INT_LIT, Token::IDENT, Token::INT_LIT, Token::BAR, Token::INT_LIT, Token::SEMICOLON,
      Token::IF, Token::IDENT, Token::DEQUAL, Token::IDENT, Token::DOT, Token::IDENT, Token::DBAR,
      Token::IDENT, Token::LSQUARE, Token::INT_LIT, Token::MINUS, Token::INT_LIT, Token::RSQUARE,
      Token::NEQUAL, Token::IDENT, Token::DBAR, Token::IDENT, Token::LTEQUAL, Token::IDENT,
      Token::DBAR, Token::IDENT, Token::RANGLE, Token::IDENT, Token::DBAR, Token::IDENT,
      Token::GTEQUAL, Token::IDENT, Token::DOT, Token::IDENT, Token::DBAR, Token::IDENT,
      Token::LANGLE, Token::IDENT, Token::LSQUARE, Token::INT_LIT, Token::RSQUARE, Token::LBRACE,
      Token::IDENT, Token::LANGLE, Token::I8, Token::RANGLE, Token::LPAREN, Token::IDENT,
      Token::RPAREN, Token::SEMICOLON, Token::RBRACE, Token::ELSE, Token::IF, Token::BOOL_LIT,
      Token::LBRACE, Token::RBRACE, Token::ELSE, Token::LBRACE, Token::MATCH, Token::IDENT,
      Token::LBRACE, Token::INT_LIT, Token::LBRACE, Token::RBRACE, Token::INT_LIT, Token::LBRACE,
      Token::RBRACE, Token::INT_LIT, Token::LBRACE, Token::IDENT, Token::LPAREN, Token::INT_LIT,
      Token::RPAREN, Token::SEMICOLON, Token::RBRACE, Token::RBRACE, Token::MATCH, Token::IDENT,
      Token::LBRACE, Token::IDENT, Token::LBRACE, Token::RBRACE, Token::IDENT, Token::LBRACE,
      Token::RBRACE, Token::IDENT, Token::LPAREN, Token::IDENT, Token::RPAREN, Token::LBRACE,
      Token::IDENT, Token::LPAREN, Token::IDENT, Token::RPAREN, Token::SEMICOLON, Token::RBRACE,
      Token::RBRACE, Token::RBRACE, Token::CONST, Token::AUTO, Token::IDENT, Token::EQUAL,
      Token::MINUS, Token::LPAREN, Token::INT_LIT, Token::PLUS, Token::INT_LIT, Token::RPAREN,
      Token::ASTERISK, Token::LPAREN, Token::INT_LIT, Token::FSLASH, Token::INT_LIT, Token::RPAREN,
      Token::MINUS, Token::MINUS, Token::INT_LIT, Token::SEMICOLON, Token::IDENT, Token::MINUS,
      Token::MINUS, Token::INT_LIT, Token::PERCENT, Token::INT_LIT, Token::SEMICOLON, Token::IDENT,
      Token::MINUS, Token::MINUS, Token::MINUS, Token::IDENT, Token::SEMICOLON, Token::IDENT,
      Token::SEMICOLON, Token::IDENT, Token::SEMICOLON, Token::IDENT, Token::SEMICOLON,
      Token::IDENT, Token::SEMICOLON, Token::IDENT, Token::SEMICOLON, Token::INT_LIT, Token::DOT,
      Token::INT_LIT, Token::SEMICOLON, Token::FOR, Token::I8, Token::IDENT, Token::EQUAL,
      Token::INT_LIT, Token::SEMICOLON, Token::IDENT, Token::LANGLE, Token::INT_LIT,
      Token::SEMICOLON, Token::IDENT, Token::PLUS, Token::PLUS, Token::LBRACE, Token::RETURN,
      Token::INT_LIT, Token::SEMICOLON, Token::RBRACE, Token::COMMENT, Token::RETURN,
      Token::INT_LIT, Token::SEMICOLON, Token::RBRACE};
  //  EXPECT_THAT(types, ElementsAreArray(expected));
}

}  // namespace
