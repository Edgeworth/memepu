#ifndef MEMEPU_COMMON_H_
#define MEMEPU_COMMON_H_

#include <cstdio>
#include <cstdint>
#include <string>
#include <vector>

#include "gtest/gtest.h"

std::string readFile(const std::string& filename);

void writeFile(const std::string& filename, const std::string& data);

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

#define verify_expr(expr, ...)                        \
  do {                                                \
    if (!(expr)) {                                    \
      fprintf(stderr, "%s:%d: ", __func__, __LINE__); \
      fprintf(stderr, __VA_ARGS__);                   \
      fprintf(stderr, "\n");                          \
      exit(1);                                        \
    }                                                 \
  } while (0)


#endif  // MEMEPU_COMMON_H_
