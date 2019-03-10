#ifndef VERYMEME_COMMON_H
#define VERYMEME_COMMON_H

#include <cstdio>
#include <cstdint>
#include <string>
#include <vector>
#include <sstream>
#include <boost/any.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/stacktrace/stacktrace.hpp>
#include <bitset>

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

std::vector<std::string> split(const std::string& data, char delim);

template<typename T>
std::string toBinary(T value) {
  std::stringstream s;
  std::bitset<sizeof(value) * 8> bset(value);
  s << bset;
  return s.str();
}

template<template<typename...> typename C, int N, typename T, typename... Ts>
struct sized_pack_t {
  using type = typename sized_pack_t<C, N - 1, T, T, Ts...>::type;
};

template<template<typename...> typename C, typename T, typename... Ts>
struct sized_pack_t<C, 0, T, Ts...> {
  using type = C<Ts...>;
};

template<typename T, int N, typename... Ts>
using sized_tuple = typename sized_pack_t<std::tuple, N, T, Ts...>::type;

template<typename A, template<typename...> typename B>
struct pack_functor_t {
};

template<template<typename...> typename A,
    template<typename...> typename B, typename... Ts>
struct pack_functor_t<A<Ts...>, B> {
  using type = B<Ts...>;
};

template<typename A, template<typename...> typename B>
using pack_functor = typename pack_functor_t<A, B>::type;

template<typename U, typename... Ts>
struct cast_seq_t;

template<typename... Ts, std::size_t... Is>
struct cast_seq_t<std::index_sequence<Is...>, Ts...> {
  template<typename F>
  static std::tuple<Ts...> apply(F f) {
    return {(boost::lexical_cast<Ts>(f(Is)))...};
  }
};

template<typename... Ts>
struct cast_t {
  template<typename F>
  constexpr static std::tuple<Ts...> apply(F f) {
    return cast_seq_t<std::index_sequence_for<Ts...>, Ts...>::apply(f);
  }
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
