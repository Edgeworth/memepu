// Copyright 2019 E.
#include "memelang/tokeniser.h"

#include <string>
#include <unordered_map>

#include "verymeme/string_util.h"

namespace memelang::ast {

namespace {

constexpr char SEPARATORS[] = "!/*+-<>(){}[]; \t\r\n?,:.=\"'&";

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
    {"while", Tok::WHILE}, {"ret", Tok::RET}, {"import", Tok::IMPORT}, {"static", Tok::STATIC},
    {"const", Tok::CONST},
    // Specially handled tokens:
    {"asm", Tok::ASM}, {"//", Tok::COMMENT}, {"\"", Tok::DQUOTE}, {"'", Tok::QUOTE}};
}  // namespace

std::string Tok::desc() const {
  std::string d = (boost::format("Token(%s, %s, '%s'") % type % fpos() % span()).str();
  if (int_val != INT64_MIN) d += (boost::format(", %d") % int_val).str();
  if (!str_val.empty()) d += (boost::format(", '%s'") % str_val).str();
  d += ")";
  return d;
}

std::ostream& operator<<(std::ostream& str, const Tok::Type& o) {
  static const std::string TOKEN_TYPES[] = {"PLUS", "DPLUS", "MINUS", "DMINUS", "ASTERISK",
      "PERCENT", "FSLASH", "QUOTE", "DQUOTE", "LPAREN", "RPAREN", "LBRACE", "RBRACE", "LANGLE",
      "RANGLE", "LSQUARE", "RSQUARE", "SEMICOLON", "COLON", "QUESTION", "COMMA", "DOT", "TILDE",
      "EXCLAMATION", "AMPERSAND", "DAMPERSAND", "CARET", "BAR", "DBAR", "EQUAL", "DEQUAL", "NEQUAL",
      "LTEQUAL", "GTEQUAL", "INTF", "STRUCT", "ENUM", "IMPL", "FN", "IF", "ELSE", "MATCH", "FOR",
      "WHILE", "RET", "IMPORT", "STATIC", "CONST", "ASM", "STR_LIT", "INT_LIT", "UINT_LIT",
      "CHAR_LIT", "BOOL_LIT", "IDENT", "COMMENT"};
  return outputEnum(str, o, TOKEN_TYPES);
}

Tokeniser::Tokeniser(const FileContents* cts) : cts_(cts) { bug_unless(cts_); }

std::vector<Tok> Tokeniser::tokenise() {
  toks_.clear();
  const auto& data = cts_->data();
  for (int i = 0; i < static_cast<int>(data.size()); ++i)
    verify(isprint(data[i]) || data[i] == '\n', "unprintable character '%c' at %s", data[i],
        cts_->fpos(i).c_str());

  while (idx_ < static_cast<int>(data.size())) {
    if (startsNewToken(data[idx_]) || atCompleteToken()) pushCurrentToken();

    if (!isspace(data[idx_]))
      curtok_ += data[idx_];
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
    std::string mergetok = prevtok.span() + curtok_;
    auto merge_iter = SIMPLE_TOKENS.find(mergetok);
    if (merge_iter != SIMPLE_TOKENS.end()) {
      type = merge_iter->second;
      curtok_ = str_val = std::move(mergetok);
      prev_idx_ = prevtok.loc;
      toks_.pop_back();
    }
  }

  const auto& data = cts_->data();
  int64_t int_val = INT64_MIN;
  switch (type) {
  case Tok::QUOTE:
    type = Tok::CHAR_LIT;
    str_val = int_val = grabEscapedChar();
    verify(isChar('\'', "unexpected EOF"), "unterminated char literal");
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
  case Tok::IDENT: {
    const bool unsign = curtok_.back() == 'u';
    if (unsign) curtok_.pop_back();
    int_val = convertFromInteger(curtok_);
    if (int_val != INT64_MIN) type = unsign ? Tok::UINT_LIT : Tok::INT_LIT;
    if (curtok_ == "false" || curtok_ == "true") {
      int_val = curtok_ == "true";
      type = Tok::BOOL_LIT;
    }
    break;
  }
  case Tok::COMMENT:
    while (!isChar('\n', "file not newline terminated")) idx_++;
    break;
  default: break;
  }

  while (isspace(data[prev_idx_])) prev_idx_++;  // Skip initial whitespace.
  toks_.push_back({type, prev_idx_, idx_ - prev_idx_, int_val, str_val, cts_});
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
  const auto& data = cts_->data();
  verify(idx_ < static_cast<int>(data.size()), "%s", msg);
  return data[idx_] == c;
}

char Tokeniser::grabEscapedChar() {
  const auto& data = cts_->data();
  if (data[idx_] != '\\') return data[idx_++];
  verify(++idx_ < static_cast<int>(data.size()), "unexpected EOF in escape sequence");
  idx_++;
  switch (data[idx_ - 1]) {
  case 'n': return '\n';
  case 'r': return '\r';
  case 't': return '\t';
  case 'v': return '\v';
  case 'f': return '\f';
  case '\'': return '\'';
  case '\\': return '\\';
  case '"': return '"';
  default: verify(false, "unknown escape sequence \\%c", data[idx_ - 1]);
  }
  return -1;
}

}  // namespace memelang::ast
