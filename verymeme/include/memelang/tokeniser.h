#ifndef MEMELANG_TOKENISER_H
#define MEMELANG_TOKENISER_H

#include <boost/format.hpp>
#include <memory>
#include <utility>
#include <vector>

#include "memelang/file_contents.h"

namespace memelang {

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
    RETURN,
    VAR,
    STATIC,
    CONST,
    AUTO,
    I8,
    I16,
    I32,
    U8,
    U16,
    U32,
    BOOL,
    BIT,
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

  std::string toString(const FileContents* contents) const {
    return (boost::format("Token(%s, '%s',  %d:%d, %s, \"%s\")") % type %
        contents->getSpan(loc, size) % contents->getLineNumber(loc) % contents->getColNumber(loc) %
        (int_val == INT64_MIN ? "no int" : std::to_string(int_val)) % str_val)
        .str();
  }
};

class Tokeniser {
public:
  explicit Tokeniser(const FileContents* contents) : contents_(contents) {}

  std::vector<Tok> tokenise();

private:
  const FileContents* contents_;
  std::string curtok_;
  std::vector<Tok> tokens_;
  int idx_ = 0;
  bool can_merge_ = true;

  static bool startsNewToken(char c);

  void pushCurrentToken();
  bool atCompleteToken();
  bool isChar(char c, const char* msg);
  char grabEscapedChar();
};

std::ostream& operator<<(std::ostream& str, const Tok::Type& o);

}  // namespace memelang

#endif  // MEMELANG_TOKENISER_H
