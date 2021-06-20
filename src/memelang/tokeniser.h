// Copyright 2019 E.
#ifndef MEMELANG_TOKENISER_H
#define MEMELANG_TOKENISER_H

#include <memory>
#include <utility>
#include <vector>

#include "boost/format.hpp"
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
    RET,
    IMPORT,
    STATIC,
    CONST,
    // Complex tokens
    ASM,
    STR_LIT,
    INT_LIT,
    UINT_LIT,
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
  const FileContents* cts = nullptr;

  std::string desc() const;
  std::string span() const { return cts->span(loc, size); }
  std::string fpos() const { return cts->fpos(loc); }
};

class Tokeniser {
 public:
  explicit Tokeniser(const FileContents* contents);

  std::vector<Tok> tokenise();

 private:
  const FileContents* cts_;
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
