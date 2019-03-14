#ifndef VERYMEME_COMMON_H
#define VERYMEME_COMMON_H

#include <cstdio>
#include <cstdint>
#include <string>
#include <vector>
#include <sstream>
#include <boost/stacktrace/stacktrace.hpp>

#include "gtest/gtest.h"

#define verify_expr(expr, ...)                        \
  do {                                                \
    if (!(expr)) {                                    \
      fprintf(stderr, "%s:%d: ", __func__, __LINE__); \
      fprintf(stderr, __VA_ARGS__);                   \
      fprintf(stderr, "\n");                          \
      std::stringstream s; \
      s << boost::stacktrace::stacktrace(); \
      fprintf(stderr, "Stack:\n%s\n", s.str().c_str()); \
      exit(1);                                        \
    }                                                 \
  } while (0)

std::string readFile(const std::string& filename, bool binary);

void writeFile(const std::string& filename, const std::string& data, bool binary);

std::string basename(const std::string& filename);

std::string stem(const std::string& filename);

template<typename T, int N>
class CartesianProduct {
public:
  explicit CartesianProduct(const std::array<int, N>& ranges) : ranges_(std::move(ranges)) {}

  std::vector<std::array<T, N>> get() {
    generate(0);
    return std::move(product_);
  }

private:
  void generate(int i) {
    if (i == int(ranges_.size())) {
      product_.push_back(cur_);
      return;
    }

    for (int j = 0; j < ranges_[i]; ++j) {
      cur_[i] = T(j);
      generate(i + 1);
    }
  }

  std::array<int, N> ranges_;
  std::array<T, N> cur_;
  std::vector<std::array<T, N>> product_;
};

#endif  // VERYMEME_COMMON_H
