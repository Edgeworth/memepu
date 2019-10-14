#ifndef VERYMEME_GEOM_H
#define VERYMEME_GEOM_H

#include <algorithm>
#include <cstdint>
#include <string>

#include "verymeme/macros.h"

template <typename T>
T clamp(T low, T high, T val) {
  return std::max(low, std::min(val, high));
}

struct Point {
  int64_t x = 0;
  int64_t y = 0;

  Point& operator+=(const Point& p);
  Point operator+(const Point& p) const;
  Point operator-(const Point& p) const;
  Point operator-() const;

  int64_t cross(const Point& p) const;
  std::string toString() const { return "(" + std::to_string(x) + ", " + std::to_string(y) + ")"; }
  COMPARISON(Point, x, y);
};

struct Rect {
  int64_t left = 0;
  int64_t top = 0;
  int64_t right = 0;
  int64_t bottom = 0;

  void inset(int64_t w, int64_t h) {
    left += w;
    top += h;
    right -= w;
    bottom -= h;
  }

  void unionRect(const Rect& r) {
    if (r.empty()) return;
    if (empty()) {
      *this = r;
      return;
    }
    left = std::min(left, r.left);
    right = std::max(right, r.right);
    top = std::min(top, r.top);
    bottom = std::max(bottom, r.bottom);
  }

  Rect& offset(const Point& p) {
    left += p.x;
    right += p.x;
    top += p.y;
    bottom += p.y;
    return *this;
  }

  constexpr bool contains(const Rect& r) const {
    return left <= r.left && top <= r.top && right >= r.right && bottom >= r.bottom;
  }
  constexpr Point origin() const { return {left, top}; }
  constexpr Point bottom_right() const { return {right, bottom}; }
  constexpr int64_t width() const { return right - left; }
  constexpr int64_t height() const { return bottom - top; }

  void set_width(int64_t width) { right = left + width; }
  void set_height(int64_t height) { bottom = top + height; }

  bool empty() const { return width() == 0 && height() == 0; }

  std::string toString() const {
    return "{" + std::to_string(left) + ", " + std::to_string(top) + ", " + std::to_string(right) +
        ", " + std::to_string(bottom) + "}";
  }

  static Rect enclosing(const Point& a, const Point& b);
};

std::ostream& operator<<(std::ostream& str, const Point& p);

#endif  // VERYMEME_GEOM_H
