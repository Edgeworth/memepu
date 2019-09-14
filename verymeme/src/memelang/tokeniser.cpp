#include "memelang/tokeniser.h"

#include <unordered_map>

#include "verymeme/string_util.h"

namespace memelang {

namespace {

constexpr char SEPARATORS[] = "/*+-<>(){}[]; \t\r\n?,:.=\"'&";

// Stores the tokens which are just a simple string match.
const std::unordered_map<std::string, Tok::Type> SIMPLE_TOKENS = {
    // Basic tokens:
    {"+", Tok::PLUS}, {"++", Tok::DPLUS}, {"-", Tok::MINUS}, {"--", Tok::DMINUS},
    {"*", Tok::ASTERISK}, {"%", Tok::PERCENT}, {"/", Tok::FSLASH}, {"'", Tok::QUOTE},
    {"\"", Tok::DQUOTE}, {"(", Tok::LPAREN}, {")", Tok::RPAREN}, {"{", Tok::LBRACE},
    {"}", Tok::RBRACE}, {"<", Tok::LANGLE}, {">", Tok::RANGLE}, {"[", Tok::LSQUARE},
    {"]", Tok::RSQUARE}, {";", Tok::SEMICOLON}, {":", Tok::COLON}, {"?", Tok::QUESTION},
    {",", Tok::COMMA}, {".", Tok::DOT}, {"~", Tok::TILDE}, {"!", Tok::EXCLAMATION},
    {"&", Tok::AMPERSAND}, {"&&", Tok::DAMPERSAND}, {"^", Tok::CARET}, {"|", Tok::BAR},
    {"||", Tok::DBAR}, {"=", Tok::EQUAL}, {"==", Tok::DEQUAL}, {"!=", Tok::NEQUAL},
    {"<=", Tok::LTEQUAL}, {">=", Tok::GTEQUAL},
    // Keywords:
    {"intf", Tok::INTF}, {"struct", Tok::STRUCT}, {"enum", Tok::ENUM}, {"impl", Tok::IMPL},
    {"fn", Tok::FN}, {"if", Tok::IF}, {"else", Tok::ELSE}, {"match", Tok::MATCH}, {"for", Tok::FOR},
    {"return", Tok::RETURN}, {"var", Tok::VAR}, {"static", Tok::STATIC}, {"const", Tok::CONST},
    {"auto", Tok::AUTO}, {"i8", Tok::I8}, {"i16", Tok::I16}, {"i32", Tok::I32}, {"u8", Tok::U8},
    {"u16", Tok::U16}, {"u32", Tok::U32}, {"bool", Tok::BOOL}, {"bit", Tok::BIT},
    // Specially handled tokens:
    {"asm", Tok::ASM}, {"//", Tok::COMMENT}, {"\"", Tok::DQUOTE}, {"'", Tok::QUOTE}};

}  // namespace

std::ostream& operator<<(std::ostream& str, const Tok::Type& o) {
  const static std::string TOKEN_TYPES[] = {"PLUS", "DPLUS", "MINUS", "DMINUS", "ASTERISK",
      "PERCENT", "FSLASH", "QUOTE", "DQUOTE", "LPAREN", "RPAREN", "LBRACE", "RBRACE", "LANGLE",
      "RANGLE", "LSQUARE", "RSQUARE", "SEMICOLON", "COLON", "QUESTION", "COMMA", "DOT", "TILDE",
      "EXCLAMATION", "AMPERSAND", "DAMPERSAND", "CARET", "BAR", "DBAR", "EQUAL", "DEQUAL", "NEQUAL",
      "LTEQUAL", "GTEQUAL", "INTF", "STRUCT", "ENUM", "IMPL", "FN", "IF", "ELSE", "MATCH", "FOR",
      "RETURN", "VAR", "STATIC", "CONST", "AUTO", "I8", "I16", "I32", "U8", "U16", "U32", "BOOL",
      "BIT", "ASM", "STR_LIT", "INT_LIT", "CHAR_LIT", "BOOL_LIT", "IDENT", "COMMENT"};
  return outputEnum(str, o, TOKEN_TYPES);
}

std::vector<Tok> Tokeniser::tokenise() {
  toks_.clear();
  const auto& data = contents_->data();
  for (int i = 0; i < int(data.size()); ++i)
    verify_expr(isprint(data[i]) || data[i] == '\n', "unprintable character '%c' at %d:%d", data[i],
        contents_->getLineNumber(i), contents_->getColNumber(i));

  while (idx_ < int(data.size())) {
    if (startsNewToken(data[idx_]) || atCompleteToken()) pushCurrentToken();

    if (!isspace(data[idx_])) curtok_ += data[idx_];
    else
      can_merge_ = false;  // Can't merge across spaces.
    idx_++;
  }
  pushCurrentToken();

  return toks_;
}

void Tokeniser::pushCurrentToken() {
  if (curtok_.empty()) return;

  Tok::Type type;
  std::string str_val = curtok_;
  auto cur_iter = SIMPLE_TOKENS.find(curtok_);
  if (cur_iter != SIMPLE_TOKENS.end()) {
    type = cur_iter->second;
  } else {
    type = Tok::IDENT;
  }

  // Try to merge tokens together.
  if (!toks_.empty() && can_merge_) {
    auto prevtok = toks_.back();
    std::string mergetok = contents_->getSpan(prevtok.loc, prevtok.size) + curtok_;
    auto merge_iter = SIMPLE_TOKENS.find(mergetok);
    if (merge_iter != SIMPLE_TOKENS.end()) {
      type = merge_iter->second;
      curtok_ = str_val = std::move(mergetok);
      prev_idx_ = prevtok.loc;
      toks_.pop_back();
    }
  }

  const auto& data = contents_->data();
  int64_t int_val = INT64_MIN;
  switch (type) {
  case Tok::QUOTE:
    type = Tok::CHAR_LIT;
    str_val = grabEscapedChar();
    verify_expr(isChar('\'', "unexpected EOF"), "unterminated char literal");
    idx_++;  // Skip '.
    break;
  case Tok::DQUOTE:
    type = Tok::STR_LIT;
    str_val.clear();
    while (!isChar('"', "missing closing quote for string literal")) str_val += grabEscapedChar();
    idx_++;  // Skip ".
    break;
  case Tok::ASM:
    while (!isChar('{', "asm block has no opening brace")) idx_++;
    idx_++;  // Skip {.
    str_val.clear();
    while (!isChar('}', "asm block has no closing brace")) str_val += data[idx_++];
    idx_++;  // Skip }.
    break;
  case Tok::IDENT:
    int_val = convertFromInteger(curtok_);
    if (int_val != INT64_MIN) type = Tok::INT_LIT;
    if (curtok_ == "false" || curtok_ == "true") {
      int_val = curtok_ == "true";
      type = Tok::BOOL_LIT;
    }
    break;
  case Tok::COMMENT:
    while (!isChar('\n', "file not newline terminated")) idx_++;
    break;
  default: break;
  }

  while (isspace(data[prev_idx_])) prev_idx_++;  // Skip initial whitespace.
  toks_.push_back({type, prev_idx_, idx_ - prev_idx_, int_val, str_val});
  curtok_ = "";
  // Added a new token, we can potentially merge it next.
  can_merge_ = true;
  prev_idx_ = idx_;
}

bool Tokeniser::startsNewToken(char c) {
  // A separator character marks the start of a new token.
  return std::string(SEPARATORS).find(c) != std::string::npos;
}

bool Tokeniser::atCompleteToken() {
  // A separator is a token of itself. We may merge it to a larger token later.
  if (curtok_.size() == 1) return std::string(SEPARATORS).find(curtok_[0]) != std::string::npos;
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
  case 'n': return '\n';
  case 'r': return '\r';
  case 't': return '\t';
  case '\'': return '\'';
  case '\\': return '\\';
  case '"': return '"';
  default: verify_expr(false, "unknown escape sequence \\%c", data[idx_ - 1]);
  }
  return -1;
}

}  // namespace memelang
