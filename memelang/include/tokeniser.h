#include <utility>


#ifndef MEMELANG_TOKENISER_H
#define MEMELANG_TOKENISER_H

#include "common.h"
#include "file_contents.h"
#include <vector>
#include <utility>
#include <memory>

namespace meme {

struct Token {
  enum Type {
    INTERFACE, STRUCT, FUNCTION, PLUS, MINUS, ASTERISK, FSLASH, QUOTE, FOR, WHILE, LPAREN, RPAREN, LBRACE, RBRACE,
    LANGLE, RANGLE, LSQUARE, RSQUARE, SEMICOLON, LITERAL, QUESTION, COMMA, COLON, RETURN, EQUAL, IF, DEQUAL, NEQUAL,
    DOT, STATIC, DPLUS, DMINUS, LTEQUAL, GTEQUAL
  } type;
  int loc;
  int size;

  std::string toString(const FileContents* contents) const {
    std::string str;
    format_str(str, "Token('%s', %d:%d)", contents->getSpan(loc, size).c_str(), contents->getLineNumber(loc), contents->getColNumber(loc));
    return str;
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

}  // namespace meme

#endif //MEMELANG_TOKENISER_H
