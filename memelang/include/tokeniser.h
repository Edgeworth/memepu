#ifndef MEMELANG_TOKENISER_H
#define MEMELANG_TOKENISER_H

#include "common.h"
#include <vector>

struct Token {
  enum Type {
    INTERFACE,
    STRUCT,
    PLUS,
    MINUS,
    ASTERISK,
    FSLASH,
    QUOTE,
    FOR,
    LPAREN,
    RPAREN,
    LBRACE,
    RBRACE,
    LANGLE,
    RANGLE,
    LSQUARE,
    RSQUARE,
    SEMICOLON,
    IDENT,
    QUESTION,
    COMMA,
    COLON
  } type;
  std::string data;
  int linenum;
  int colnum;
};

class Tokeniser {
public:
  explicit Tokeniser(const std::string& data) : data_(data) {}

  std::vector<Token> tokenise();

private:
  std::string data_;
  std::string curtok_;
  std::vector<Token> tokens_;
  int linenum_ = 1;
  int colnum_ = 1;

  void pushCurrentToken();
  bool startsNewToken(char c);

  bool atCompleteToken();
};

#endif //MEMELANG_TOKENISER_H
