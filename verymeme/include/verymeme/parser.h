#ifndef VERYMEME_PARSER_H
#define VERYMEME_PARSER_H

#include <regex>

#include "verymeme/common.h"

class Parser {
public:
  Parser(const std::string& data, const std::regex& token);

  template<typename T = std::string>
  T peek(int ahead = 0) {
    verify_expr(idx_ + ahead < int(toks_.size()), "expecting token");
    return boost::lexical_cast<T>(toks_[idx_ + ahead]);
  }

  template<typename T = std::string>
  T next() {
    T value = peek<T>();
    idx_++;
    return value;
  }

  bool hasTokens() { return idx_ < int(toks_.size()); }

  std::string getLines(int num_lines = 1);
  std::string getSubstr(int st, int en);
  void expect(const std::vector<std::string>& toks);

private:
  std::vector<std::string> toks_;
  int idx_ = 0;
};

#endif  // VERYMEME_PARSER_H
