#include "tokeniser.h"
#include <algorithm>
#include <unordered_map>

namespace {

constexpr char SEPARATORS[] = "/*+-<>(){}[]; \t?,:";

const std::unordered_map<std::string, Token::Type> TOKEN_MAP = {
  {"interface", Token::INTERFACE},
  {"struct", Token::STRUCT},
  {"+", Token::PLUS},
  {"-", Token::MINUS},
  {"*", Token::ASTERISK},
  {"/", Token::FSLASH},
  {"'", Token::QUOTE},
  {"for", Token::FOR},
  {"(", Token::LPAREN},
  {")", Token::RPAREN},
  {"{", Token::LBRACE},
  {"}", Token::RBRACE},
  {"<", Token::LANGLE},
  {">", Token::RANGLE},
  {"[", Token::LSQUARE},
  {"]", Token::RSQUARE},
  {";", Token::SEMICOLON},
  {"?", Token::QUESTION},
  {",", Token::COMMA},
  {":", Token::COLON}
};

}  // anonymous

std::vector<Token> Tokeniser::tokenise() {
  tokens_.clear();
  linenum_ = 1;
  colnum_ = 1;
  for (char c : data_) {
    verify_expr(isprint(c) || c == '\n', "unprintable character '%c' at %d:%d", c, linenum_, colnum_);

    if (atCompleteToken() || startsNewToken(c)) {
      pushCurrentToken();
    }
    if (!isspace(c))
      curtok_ += c;

    if (c == '\n') {
      linenum_++;
      colnum_ = 1;
    } else {
      colnum_++;
    }
  }
  pushCurrentToken();

  return tokens_;
}

void Tokeniser::pushCurrentToken() {
  if (curtok_.empty())
    return;

  Token::Type type;

  auto iter = TOKEN_MAP.find(curtok_);
  if (iter != TOKEN_MAP.end()) {
    type = iter->second;
  } else {
    type = Token::IDENT;
  }
  tokens_.push_back({type, curtok_, linenum_, colnum_});
  curtok_ = "";
}

bool Tokeniser::startsNewToken(char c) {
  return std::string(SEPARATORS).find(c) != std::string::npos;
}

bool Tokeniser::atCompleteToken() {
  if (curtok_.size() == 1)
    return std::string(SEPARATORS).find(curtok_[0]) != std::string::npos;
  return false;
}
