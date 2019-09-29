#ifndef VERYMEME_STRING_UTIL_H
#define VERYMEME_STRING_UTIL_H

#include <bitset>
#include <iomanip>

#include "verymeme/util.h"

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
std::ostream& outputEnum(
    std::ostream& str, const T& enumeration, const std::string (&mapping)[int(T::COUNT)]) {
  return str << mapping[int(enumeration)];
}

template <typename T>
std::istream& inputEnum(
    std::istream& str, T& enumeration, const std::string (&mapping)[int(T::COUNT)]) {
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
std::string convertToString(const uint32_t (&data)[N]) {
  std::string str;
  str.reserve(N * sizeof(uint32_t));
  for (uint32_t c : data) {
    str += char(c & 0xFFu);
    str += char((c >> 8u) & 0xFFu);
    str += char((c >> 16u) & 0xFFu);
    str += char((c >> 24u) & 0xFFu);
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

#endif  // VERYMEME_STRING_UTIL_H
