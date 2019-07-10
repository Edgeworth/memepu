#include "memelang/tokeniser.h"
#include <unordered_map>

namespace memelang {

namespace {

constexpr char SEPARATORS[] = "/*+-<>(){}[]; \t?,:.=";

// Stores the tokens which are just a simple string match.
const std::unordered_map<std::string, Token::Type> SIMPLE_TOKENS = {
    // Basic tokens:
    {"+", Token::PLUS}, {"-", Token::MINUS}, {"*", Token::ASTERISK}, {"%", Token::PERCENT},
    {"/", Token::FSLASH}, {"'", Token::QUOTE}, {"\"", Token::DQUOTE}, {"(", Token::LPAREN},
    {")", Token::RPAREN}, {"{", Token::LBRACE}, {"}", Token::RBRACE}, {"<", Token::LANGLE},
    {">", Token::RANGLE}, {"[", Token::LSQUARE}, {"]", Token::RSQUARE}, {";", Token::SEMICOLON},
    {":", Token::COLON}, {"?", Token::QUESTION}, {",", Token::COMMA}, {".", Token::DOT},
    {"~", Token::TILDE}, {"!", Token::EXCLAMATION}, {"&", Token::AMPERSAND},
    {"&&", Token::DAMPERSAND}, {"|", Token::BAR}, {"||", Token::DBAR}, {"=", Token::EQUAL},
    {"==", Token::DEQUAL}, {"!=", Token::NEQUAL}, {"<=", Token::LTEQUAL}, {">=", Token::GTEQUAL},
    // Keywords:
    {"intf", Token::INTF}, {"struct", Token::STRUCT}, {"enum", Token::ENUM}, {"impl", Token::IMPL},
    {"fn", Token::FN}, {"if", Token::IF}, {"else", Token::ELSE}, {"match", Token::MATCH},
    {"for", Token::FOR}, {"return", Token::RETURN}, {"static", Token::STATIC},
    {"const", Token::CONST}, {"auto", Token::AUTO}, {"i8", Token::I8}, {"i16", Token::I16},
    {"i32", Token::I32}, {"u8", Token::U8}, {"u16", Token::U16}, {"u32", Token::U32},
    {"bool", Token::BOOL}, {"bit", Token::BIT},
};

// TODO:
//{"asm", Token::ASM}, // TODO
//{"TODO", Token::STR_LIT},
//{"TODO", Token::INT_LIT},
//{"TODO", Token::CHAR_LIT},
//{"TODO", Token::BOOL_LIT},
//{"TODO", Token::IDENT},
//{"TODO", Token::COMMENT},

}  // namespace

std::vector<Token> Tokeniser::tokenise() {
  tokens_.clear();
  const auto& data = contents_->data();
  for (idx_ = 0; idx_ < int(data.size()); ++idx_) {
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
  auto iter = SIMPLE_TOKENS.find(curtok_);
  if (iter != SIMPLE_TOKENS.end()) {
    type = iter->second;
  } else {
    type = Token::LITERAL;
  }

  // Try to merge tokens together (==, >=, <=).
  if (!tokens_.empty()) {
    auto prevtok = tokens_.back();
    std::string mergetok = contents_->getSpan(prevtok.loc, prevtok.size) + curtok_;
    auto iter = SIMPLE_TOKENS.find(mergetok);
    if (iter != SIMPLE_TOKENS.end()) {
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

}  // namespace memelang
