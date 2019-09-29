#ifndef MEMELANG_TOKENISER_H
#define MEMELANG_TOKENISER_H

#include <boost/format.hpp>
#include <memory>
#include <utility>
#include <vector>

#include "memelang/file_contents.h"

namespace memelang::ast {

struct Tok {
  enum Type {
    // Basic tokens:
    PLUS,
    DPLUS,
    MINUS,
    DMINUS,
    ASTERISK,
    PERCENT,
    FSLASH,
    QUOTE,
    DQUOTE,
    LPAREN,
    RPAREN,
    LBRACE,
    RBRACE,
    LANGLE,
    RANGLE,
    LSQUARE,
    RSQUARE,
    SEMICOLON,
    COLON,
    QUESTION,
    COMMA,
    DOT,
    TILDE,
    EXCLAMATION,
    AMPERSAND,
    DAMPERSAND,
    CARET,
    BAR,
    DBAR,
    EQUAL,
    DEQUAL,
    NEQUAL,
    LTEQUAL,
    GTEQUAL,
    // Keywords:
    INTF,
    STRUCT,
    ENUM,
    IMPL,
    FN,
    IF,
    ELSE,
    MATCH,
    FOR,
    WHILE,
    RETURN,
    VAR,
    STATIC,
    CONST,
    AUTO,
    // Complex tokens
    ASM,
    STR_LIT,
    INT_LIT,
    CHAR_LIT,
    BOOL_LIT,
    IDENT,
    COMMENT,
    COUNT
  } type;
  int loc = -1;
  int size = -1;
  int64_t int_val = INT64_MIN;
  std::string str_val = "";

  std::string desc(const FileContents* contents) const {
    std::string d = (boost::format("Token(%s, %d:%d, '%s'") % type % contents->getLineNumber(loc) %
        contents->getColNumber(loc) % contents->getSpan(loc, size))
                        .str();
    if (int_val != INT64_MIN) d += (boost::format(", %d") % int_val).str();
    if (!str_val.empty()) d += (boost::format(", '%s'") % str_val).str();
    d += ")";
    return d;
  }
};

class Tokeniser {
public:
  explicit Tokeniser(const FileContents* contents) : contents_(contents) {}

  std::vector<Tok> tokenise();

private:
  const FileContents* contents_;
  std::string curtok_;
  std::vector<Tok> toks_;
  int idx_ = 0;
  int prev_idx_ = 0;
  bool can_merge_ = true;

  static bool startsNewToken(char c);

  void pushCurrentToken();
  bool atCompleteToken();
  bool isChar(char c, const char* msg);
  char grabEscapedChar();
};

std::ostream& operator<<(std::ostream& str, const Tok::Type& o);

}  // namespace memelang::ast

#endif  // MEMELANG_TOKENISER_H
