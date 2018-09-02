#include "tokeniser.h"
#include <unordered_map>

namespace {

constexpr char SEPARATORS[] = "/*+-<>(){}[]; \t?,:.=";

const std::unordered_map<std::string, Token::Type> TOKEN_MAP = {
  {"interface", Token::INTERFACE}, {"struct", Token::STRUCT}, {"func", Token::FUNCTION}, {"for", Token::FOR},
  {"while", Token::WHILE}, {"return", Token::RETURN}, {"if", Token::IF},
  {"+", Token::PLUS}, {"-", Token::MINUS}, {"*", Token::ASTERISK}, {"/", Token::FSLASH},
  {"'", Token::QUOTE}, {"(", Token::LPAREN}, {")", Token::RPAREN}, {"{", Token::LBRACE}, {"}", Token::RBRACE},
  {"<", Token::LANGLE}, {">", Token::RANGLE}, {"[", Token::LSQUARE}, {"]", Token::RSQUARE}, {";", Token::SEMICOLON},
  {"?", Token::QUESTION}, {",", Token::COMMA}, {":", Token::COLON}, {"=", Token::EQUAL}, {"==", Token::DEQUAL},
  {"!=", Token::NEQUAL}, {".", Token::DOT}, {"static", Token::STATIC}, {"<=", Token::LTEQUAL}, {">=", Token::GTEQUAL}
};

}  // anonymous

std::vector<Token> Tokeniser::tokenise() {
  tokens_.clear();
  const auto& data = contents_->data();
  for (idx_ = 0; idx_ < data.size(); ++idx_) {
    char c = data[idx_];
    verify_expr(isprint(c) || c == '\n', "unprintable character '%c' at %d:%d",
        c, contents_->getLineNumber(idx_), contents_->getColNumber(idx_));

    if (atCompleteToken() || startsNewToken(c)) {
      pushCurrentToken();
    }
    if (!isspace(c))
      curtok_ += c;
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
    type = Token::LITERAL;
  }

  // Maybe merge tokens together (==, >=, <=).
  if (!tokens_.empty()) {
    auto prevtok = tokens_.back();
    std::string mergetok = contents_->getSpan(prevtok.loc, prevtok.size) + curtok_;
    auto iter = TOKEN_MAP.find(mergetok);
    if (iter != TOKEN_MAP.end()) {
      tokens_.pop_back();
      type = iter->second;
      curtok_ = std::move(mergetok);
    }
  }

  tokens_.push_back({type, idx_ - int(curtok_.size()), int(curtok_.size())});
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
