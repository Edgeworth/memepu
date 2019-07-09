#ifndef MEMELANG_TOKENISER_H
#define MEMELANG_TOKENISER_H

#include "verymeme/common.h"
#include "memelang/file_contents.h"
#include <vector>
#include <utility>
#include <memory>
#include <boost/format.hpp>

namespace memelang {

struct Token {
  enum Type {
    // Basic tokens:
    PLUS, MINUS, ASTERISK, PERCENT, FSLASH, QUOTE, DQUOTE, LPAREN, RPAREN, LBRACE, RBRACE,
    LANGLE, RANGLE, LSQUARE, RSQUARE, SEMICOLON, COLON, QUESTION, COMMA, DOT, TILDE, EXCLAMATION,
    AMPERSAND, DAMPERSAND, BAR, DBAR, EQUAL, DEQUAL, NEQUAL, LTEQUAL, GTEQUAL,
    // Keywords:
    INTF, STRUCT, ENUM, IMPL, FN, IF, ELSE, MATCH, FOR, RETURN, STATIC, CONST, AUTO, I8, I16, I32,
    U8, U16, U32, BOOL, BIT,
    // Complex tokens
    ASM, STR_LIT, INT_LIT, CHAR_LIT, BOOL_LIT, IDENT, COMMENT,
  } type;
  int loc;
  int size;

  std::string toString(const FileContents* contents) const {
    return (boost::format("Token('%s', %d:%d)") % contents->getSpan(loc, size) %
            contents->getLineNumber(loc) % contents->getColNumber(loc)).str();
  }
};

class Tokeniser {
public:
  explicit Tokeniser(const FileContents* contents) : contents_(contents) {}

  std::vector<Token> tokenise();

private:
  const FileContents* contents_;
  std::string curtok_;
  std::vector<Token> tokens_;
  int idx_ = 0;

  void pushCurrentToken();
  bool startsNewToken(char c);

  bool atCompleteToken();
};

}  // namespace memelang

#endif  // MEMELANG_TOKENISER_H
