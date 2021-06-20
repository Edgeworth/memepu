// Copyright 2019 E.
#ifndef VERYMEME_STRING_UTIL_H_
#define VERYMEME_STRING_UTIL_H_

#include <verilated_heavy.h>

#include <bitset>
#include <cstddef>
#include <iomanip>
#include <vector>

#include "verymeme/macros.h"

std::string trim(const std::string& data, const std::string& c);
int64_t convertFromHex(const std::string& s);
int64_t convertFromDec(const std::string& s);

// Converts from formatted number: 123, 0xff, 0701.
int64_t convertFromInteger(const std::string& s);

template <typename T>
std::string tos(const T& val) {
  std::stringstream s;
  s << val;
  return s.str();
}

template <typename T>
std::ostream& outputEnum(std::ostream& str, const T& enumeration,
    const std::string (&mapping)[static_cast<int>(T::COUNT)]) {
  return str << mapping[static_cast<int>(enumeration)];
}

template <typename T>
std::istream& inputEnum(
    std::istream& str, T& enumeration, const std::string (&mapping)[static_cast<int>(T::COUNT)]) {
  std::string v;
  str >> v;
  for (int i = 0; i < static_cast<int>(T::COUNT); ++i) {
    if (mapping[i] == v) {
      enumeration = T(i);
      return str;
    }
  }
  verify(false, "unknown enum with string value '%s'", v.c_str());
}

template <typename T>
std::string hexdump(const std::vector<T>& input, int width = 80) {
  static_assert(sizeof(T) <= sizeof(uint64_t), "input type too large");
  std::stringstream stream;
  int count = 0;
  for (auto c : input) {
    stream << std::hex << std::setw(2 * sizeof(T)) << std::setfill('0') << uint64_t(c);
    count += 2 * sizeof(T);
    if (count >= width) {
      stream << "\n";
      count = 0;
    } else {
      stream << " ";
      ++count;
    }
  }
  if (count) stream << "\n";
  return stream.str();
}

template <typename T, std::size_t N>
std::string hexdump(const T (&input)[N], int width = 80) {
  return hexdump(std::vector<T>(input, input + N), width);
}

template <std::size_t N>
std::string convertToString(const VlWide<N>& data) {
  std::string str;
  str.reserve(N * sizeof(uint32_t));
  for (size_t i = 0; i < N; i++) {
    auto c = data[i];
    str += static_cast<char>(c & 0xFFu);
    str += static_cast<char>((c >> 8u) & 0xFFu);
    str += static_cast<char>((c >> 16u) & 0xFFu);
    str += static_cast<char>((c >> 24u) & 0xFFu);
  }
  std::string trimmed(str.c_str());  // Cut off at first 0 byte.
  return std::string(trimmed.rbegin(), trimmed.rend());  // Reverse
}

template <typename T>
std::string convertToHex(T val) {
  std::stringstream stream;
  stream << std::hex << val;
  return stream.str();
}

template <std::size_t N>
std::string convertToBinary(int val) {
  static_assert(N <= 32, "number of bits too large");
  std::bitset<N> bs(static_cast<uint64_t>(val));
  return bs.to_string();
}

std::string join(const std::vector<std::string>& l, const std::string& j, bool terminate = false);

template <typename Iter, typename F>
std::string join(Iter st, Iter en, F conv, const std::string& j, bool terminate = false) {
  std::vector<std::string> converted;
  std::transform(st, en, std::back_inserter(converted), conv);
  return join(converted, j, terminate);
}

#endif  // VERYMEME_STRING_UTIL_H_
