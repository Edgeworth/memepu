// Copyright 2019 E.
#ifndef VERYMEME_TOKENISER_H_
#define VERYMEME_TOKENISER_H_

#include <regex>

#include "boost/lexical_cast.hpp"
#include "verymeme/macros.h"

class Tokeniser {
 public:
  Tokeniser(const std::string& data, const std::regex& token);

  template <typename T = std::string>
  T peek(int ahead = 0) {
    verify(idx_ + ahead < static_cast<int>(toks_.size()), "expecting token");
    return boost::lexical_cast<T>(toks_[idx_ + ahead]);
  }

  template <typename T = std::string>
  T next() {
    T value = peek<T>();
    idx_++;
    return value;
  }

  bool hasTokens() { return idx_ < static_cast<int>(toks_.size()); }

  std::string lines(int num_lines = 1);
  std::string substr(int st, int en);
  void expect(const std::vector<std::string>& toks);

 private:
  std::vector<std::string> toks_;
  int idx_ = 0;
};

#endif  // VERYMEME_TOKENISER_H_
