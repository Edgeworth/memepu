#ifndef VERYMEME_COMMON_H
#define VERYMEME_COMMON_H

#include <cstdio>
#include <cstdint>
#include <string>
#include <vector>
#include <sstream>
#include <boost/stacktrace/stacktrace.hpp>
#include <boost/lexical_cast.hpp>

#define verify_expr(expr, ...)                        \
  do {                                                \
    if (!(expr)) {                                    \
      fprintf(stderr, "%s:%d: ", __func__, __LINE__); \
      fprintf(stderr, __VA_ARGS__);                   \
      fprintf(stderr, "\n");                          \
      std::stringstream _s; \
      _s << boost::stacktrace::stacktrace(); \
      fprintf(stderr, "Stack:\n%s\n", _s.str().c_str()); \
      exit(1);                                        \
    }                                                 \
  } while (0)

constexpr float EP = 1e-6;

template<typename T>
T clamp(T low, T high, T val) {
  return std::max(low, std::min(val, high));
}

std::string readFile(const std::string& filename, bool binary = false);
void writeFile(const std::string& filename, const std::string& data, bool binary = false);
std::string basename(const std::string& filename);
std::string stem(const std::string& filename);
void checked_chdir(const std::string& path);

template<typename M, typename K, typename V>
V getDefault(const M& map, const K& key, const V& def) {
  auto iter = map.find(key);
  if (iter == map.end()) return def;
  return iter->second;
}

template<typename T>
std::vector<T> reverse(std::vector<T>&& vec) {
  std::vector<T> reversed;
  reversed.reserve(vec.size());
  for (int i = int(vec.size()) - 1; i >= 0; --i)
    reversed.emplace_back(std::move(vec[i]));
  return reversed;
}

template<typename T>
std::string tos(const T& val) { return boost::lexical_cast<std::string>(val); }

template<typename T>
std::ostream&
outputEnum(std::ostream& str, const T& enumeration, const std::string (& mapping)[int(T::COUNT)]) {
  return str << mapping[int(enumeration)];
}

template<typename T>
std::istream&
inputEnum(std::istream& str, T& enumeration, const std::string (& mapping)[int(T::COUNT)]) {
  std::string v;
  str >> v;
  for (int i = 0; i < int(T::COUNT); ++i) {
    if (mapping[i] == v) {
      enumeration = T(i);
      return str;
    }
  }
  verify_expr(false, "unknown enum with string value '%s'", v.c_str());
}

struct Point {
  int64_t x = 0;
  int64_t y = 0;

  Point& operator+=(const Point& p);
  Point operator+(const Point& p) const;
  Point operator-(const Point& p) const;
  Point operator-() const;
  bool operator<(const Point& p) const;
  bool operator!=(const Point& p) const;

  int64_t cross(const Point& p) const;

  std::string toString() const { return "(" + std::to_string(x) + ", " + std::to_string(y) + ")"; }
};

std::ostream& operator<<(std::ostream& str, const Point& p);

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

  void offset(const Point& p) {
    left += p.x;
    right += p.x;
    top += p.y;
    bottom += p.y;
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

#endif  // VERYMEME_COMMON_H
