#include "memelang/tokeniser.h"
#include <unordered_map>
#include "verymeme/string_util.h"

namespace memelang {

namespace {

constexpr char SEPARATORS[] = "/*+-<>(){}[]; \t\r\n?,:.=";

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
    // Specially hanlded tokens:
    {"asm", Token::ASM}, {"//", Token::COMMENT},
};

const std::string TOKEN_TYPES[] = {"PLUS", "MINUS", "ASTERISK", "PERCENT", "FSLASH", "QUOTE",
    "DQUOTE", "LPAREN", "RPAREN", "LBRACE", "RBRACE", "LANGLE", "RANGLE", "LSQUARE", "RSQUARE",
    "SEMICOLON", "COLON", "QUESTION", "COMMA", "DOT", "TILDE", "EXCLAMATION", "AMPERSAND",
    "DAMPERSAND", "BAR", "DBAR", "EQUAL", "DEQUAL", "NEQUAL", "LTEQUAL", "GTEQUAL", "INTF",
    "STRUCT", "ENUM", "IMPL", "FN", "IF", "ELSE", "MATCH", "FOR", "RETURN", "STATIC", "CONST",
    "AUTO", "I8", "I16", "I32", "U8", "U16", "U32", "BOOL", "BIT", "ASM", "STR_LIT", "INT_LIT",
    "CHAR_LIT", "BOOL_LIT", "IDENT", "COMMENT"};

}  // namespace

std::ostream& operator<<(std::ostream& str, const Token::Type& o) {
  return outputEnum(str, o, TOKEN_TYPES);
}

std::vector<Token> Tokeniser::tokenise() {
  tokens_.clear();
  const auto& data = contents_->data();
  for (idx_ = 0; idx_ < int(data.size()); ++idx_) {
    char c = data[idx_];
    verify_expr(isprint(c) || c == '\n', "unprintable character '%c' at %d:%d",
        c, contents_->getLineNumber(idx_), contents_->getColNumber(idx_));

    if (atCompleteToken() || startsNewToken(c))
      pushCurrentToken();
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
  std::string str_val = curtok_;
  auto iter = SIMPLE_TOKENS.find(curtok_);
  if (iter != SIMPLE_TOKENS.end()) {
    type = iter->second;
  } else {
    type = Token::IDENT;
  }

  // Try to merge tokens together.
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

  const auto& data = contents_->data();
  int64_t int_val = INT64_MIN;
  switch (type) {
    case Token::QUOTE:
      type = Token::CHAR_LIT;
      str_val = grabEscapedChar();
      verify_expr(isChar('\'', "unexpected EOF"), "unterminated char literal");
      idx_++;  // Skip '.
      break;
    case Token::DQUOTE:
      type = Token::STR_LIT;
      while (!isChar('"', "missing closing quote for string literal")) str_val += grabEscapedChar();
      idx_++;  // Skip ".
      break;
    case Token::ASM:
      while (!isChar('{', "asm block has no opening brace")) idx_++;
      idx_++;  // Skip {.
      while (!isChar('}', "asm block has no closing brace")) str_val += data[idx_++];
      idx_++;  // Skip }.
      break;
    case Token::IDENT: {
      int_val = convertFromInteger(curtok_);
      if (int_val != INT64_MIN)
        type = Token::INT_LIT;
      if (curtok_ == "false" || curtok_ == "true") {
        int_val = curtok_ == "true";
        type = Token::BOOL_LIT;
      }
      break;
    }
    case Token::COMMENT:
      while (!isChar('\n', "file not newline terminated")) idx_++;
      break;
    default:
      break;
  }

  tokens_.push_back({type, idx_ - int(curtok_.size()), int(curtok_.size()), int_val, str_val});
  curtok_ = "";
}

bool Tokeniser::startsNewToken(char c) {
  // A separator character marks the start of a new token.
  return std::string(SEPARATORS).find(c) != std::string::npos;
}

bool Tokeniser::atCompleteToken() {
  // A separator is a token of itself. We may merge it to a larger token later.
  if (curtok_.size() == 1)
    return std::string(SEPARATORS).find(curtok_[0]) != std::string::npos;
  return false;
}

bool Tokeniser::isChar(char c, const char* msg) {
  const auto& data = contents_->data();
  verify_expr(idx_ < int(data.size()), msg);
  return data[idx_] == c;
}

char Tokeniser::grabEscapedChar() {
  const auto& data = contents_->data();
  if (data[idx_] != '\\') return data[idx_++];
  verify_expr(++idx_ < int(data.size()), "unexpected EOF in escape sequence");
  idx_++;
  switch (data[idx_ - 1]) {
    case 'n':
      return '\n';
    case 'r':
      return '\r';
    case 't':
      return '\t';
    case '\'':
      return '\'';
    case '"':
      return '"';
  }
  verify_expr(false, "unknown escape sequence \\%c", data[idx_ - 1]);
  return -1;
}

}  // namespace memelang
