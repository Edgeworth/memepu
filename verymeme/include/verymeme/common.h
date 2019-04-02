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
    reversed.emplace_back(std::move(vec[i]));
  return reversed;
}

struct Point {
  int x = 0;
  int y = 0;

  Point& operator+=(const Point& p);
  Point operator-(const Point& p) const;
  bool operator<(const Point& p) const;
};

std::ostream& operator<<(std::ostream& str, const Point& p);

struct Rect {
  int left = 0;
  int top = 0;
  int right = 0;
  int bottom = 0;

  void inset(int w, int h) {
    left += w;
    top += h;
    right -= w;
    bottom -= h;
  }

  void merge(const Rect& r) {
    left = std::min(left, r.left);
    right = std::max(right, r.right);
    top = std::min(top, r.top);
    bottom = std::max(bottom, r.bottom);
  }

  void offset(const Point& p) {
    left += p.x;
    right += p.x;
    top += p.y;
    bottom += p.y;
  }

  constexpr Point origin() const { return {left, top}; }
  constexpr int width() const { return right - left; }
  constexpr int height() const { return bottom - top; }

  std::string toString() const {
    return "{" + std::to_string(left) + ", " + std::to_string(top) + ", " + std::to_string(right) +
        ", " + std::to_string(bottom) + "}";
  }
};

#endif  // VERYMEME_COMMON_H
