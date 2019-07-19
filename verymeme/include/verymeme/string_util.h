#ifndef VERYMEME_STRING_UTIL_H
#define VERYMEME_STRING_UTIL_H

#include <boost/lexical_cast.hpp>
#include <bitset>
#include <iomanip>

#include "verymeme/util.h"

std::string trim(const std::string& data, const std::string& c);

int64_t convertFromHex(const std::string& s);

int64_t convertFromDec(const std::string& s);

// Converts from formatted number: 123, 0xff, 0701.
int64_t convertFromInteger(const std::string& s);

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

template<typename T>
std::string hexdump(const std::vector<T>& input, int width = 40) {
  static_assert(sizeof(T) <= sizeof(uint64_t), "input type too large");
  std::stringstream stream;
  int count = 0;
  for (auto c : input) {
    stream << std::hex << std::setw(2 * sizeof(T)) << std::setfill('0') << uint64_t(c);
    if (++count == width) {
      stream << "\n";
      count = 0;
    } else {
      stream << " ";
    }
  }
  if (count) stream << "\n";
  return stream.str();
}

template<typename T, std::size_t N>
std::string hexdump(const T (& input)[N], int width = 40) {
  return hexdump(std::vector<T>(input, input + N), width);
}

template<std::size_t N>
std::string convertToString(const uint32_t (& data)[N]) {
  std::string str;
  str.reserve(N * sizeof(uint32_t));
  for (uint32_t c : data) {
    str += char(c & 0xFF);
    str += char((c >> 8) & 0xFF);
    str += char((c >> 16) & 0xFF);
    str += char((c >> 24) & 0xFF);
  }
  std::string trimmed(str.c_str());  // Cut off at first 0 byte.
  return std::string(trimmed.rbegin(), trimmed.rend()); // Reverse
}

template<typename T>
std::string convertToHex(T val) {
  std::stringstream stream;
  stream << std::hex << val;
  return stream.str();
}

template<std::size_t N>
std::string convertToBinary(int val) {
  static_assert(N <= 32, "number of bits too large");
  std::bitset<N> bs(val);
  return bs.to_string();
}

#endif  //VERYMEME_STRING_UTIL_H
