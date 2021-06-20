// Copyright 2019 E.
#ifndef VERYMEME_MACROS_H_
#define VERYMEME_MACROS_H_

#include <cstdio>
#include <cstdlib>
#include <string>

// Crash so AFL can find bugs.
#ifdef __AFL_COMPILER
#define AFL 1
#else
#define AFL 0
#endif

#define bug_unless(expr)                                          \
  do {                                                            \
    if (!(expr)) {                                                \
      if (!AFL) {                                                 \
        fprintf(stderr, "BUG at %s:%d: ", __func__, __LINE__);    \
        fprintf(stderr, "Stack:\n%s\n", getStacktrace().c_str()); \
      }                                                           \
      abort();                                                    \
    }                                                             \
  } while (0)

#define verify(expr, ...)                                       \
  do {                                                          \
    if (!(expr)) {                                              \
      fprintf(stderr, "%s:%d: ", __func__, __LINE__);           \
      fprintf(stderr, __VA_ARGS__);                             \
      fprintf(stderr, "\n");                                    \
      fprintf(stderr, "Stack:\n%s\n", getStacktrace().c_str()); \
      exit(1);                                                  \
    }                                                           \
  } while (0)

#define unimplemented() verify(false, "UNIMPLEMENTED")

#define COMPARISON(type, ...)                                                   \
  auto getTie() const { return std::tie(__VA_ARGS__); }                         \
  bool operator<(const type& o) const { return getTie() < o.getTie(); }         \
  bool operator==(const type& o) const { return !(*this < o) && !(o < *this); } \
  bool operator!=(const type& o) const { return (*this < o) || (o < *this); }

std::string getStacktrace();

#endif  // VERYMEME_MACROS_H_
