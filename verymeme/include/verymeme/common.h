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
void checked_chdir(const std::string& path);

template<typename T>
std::vector<T> reverse(std::vector<T>&& vec) {
  std::vector<T> reversed;
  reversed.reserve(vec.size());
  for (int i = int(vec.size()) - 1; i >= 0; --i)
    reversed[i] = std::move(vec[i]);
  return reversed;
}

struct Point {
  int x = 0;
  int y = 0;

  Point& operator+=(const Point& p);
};

std::ostream& operator<<(std::ostream& str, const Point& p);

struct Rect {
  int left = 0;
  int top = 0;
  int right = 0;
  int bottom = 0;

  void inset(int w, int h) {
    left += w / 2;
    top += h / 2;
    right -= w / 2;
    bottom -= h / 2;
  }

  constexpr int width() const { return right - left; }
  constexpr int height() const { return bottom - top; }
};

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
