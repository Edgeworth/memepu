// Copyright 2019 E.
#ifndef VERYMEME_UTIL_H
#define VERYMEME_UTIL_H

#include <cstdio>
#include <string>
#include <vector>

constexpr float EP = 1e-6;

template <class... Ts>
struct overloaded : Ts... {
  using Ts::operator()...;
};
template <class... Ts>
overloaded(Ts...) -> overloaded<Ts...>;

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

template <typename T>
struct AutoReset {
  explicit AutoReset(T callable) : callable_(callable) {}
  ~AutoReset() { callable_(); }
  AutoReset(const AutoReset<T>&) = delete;
  AutoReset(AutoReset<T>&&) = delete;
  AutoReset<T>& operator=(AutoReset<T>&&) = delete;
  AutoReset<T>& operator=(const AutoReset<T>&) = delete;

private:
  T callable_;
};

#endif  // VERYMEME_UTIL_H
