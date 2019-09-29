#ifndef VERYMEME_UTIL_H
#define VERYMEME_UTIL_H

#include <cstdio>
#include <string>
#include <vector>

// Crash so AFL can find bugs.
#ifdef __AFL_COMPILER
#define AFL 1
#else
#define AFL 0
#endif

#define bug_unless(expr) \
  do { \
    if (!(expr)) { \
      if (!AFL) { \
        fprintf(stderr, "BUG at %s:%d: ", __func__, __LINE__); \
        fprintf(stderr, "Stack:\n%s\n", getStacktrace().c_str()); \
      } \
      abort(); \
    } \
  } while (0)

#define verify_expr(expr, ...) \
  do { \
    if (!(expr)) { \
      fprintf(stderr, "%s:%d: ", __func__, __LINE__); \
      fprintf(stderr, __VA_ARGS__); \
      fprintf(stderr, "\n"); \
      fprintf(stderr, "Stack:\n%s\n", getStacktrace().c_str()); \
      exit(1); \
    } \
  } while (0)

#define unimplemented() verify_expr(false, "UNIMPLEMENTED")
constexpr float EP = 1e-6;

std::string getStacktrace();

template <typename M, typename K, typename V>
V getDefault(const M& map, const K& key, const V& def) {
  auto iter = map.find(key);
  if (iter == map.end()) return def;
  return iter->second;
}

template <typename T>
std::vector<T> reverse(std::vector<T>&& vec) {
  std::vector<T> reversed;
  reversed.reserve(vec.size());
  for (int i = int(vec.size()) - 1; i >= 0; --i) reversed.emplace_back(std::move(vec[i]));
  return reversed;
}

template <class... Ts>
struct overloaded : Ts... {
  using Ts::operator()...;
};
template <class... Ts>
overloaded(Ts...)->overloaded<Ts...>;

#endif  // VERYMEME_UTIL_H
