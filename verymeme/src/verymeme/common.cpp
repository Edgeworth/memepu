#include "verymeme/common.h"

#include <regex>

std::string trim(const std::string& data, const std::string& c) {
  const std::regex trim("^[" + c + "]*((\n|.)*?)[" + c + "]*$");
  std::smatch sm;
  verify_expr(std::regex_match(data, sm, trim), "BUG");
  return sm[1].str();
}

int64_t convertFromHex(const std::string& s) {
  std::istringstream stream(s);
  int val;
  bool valid_int = bool(stream >> std::hex >> val);
  if (!valid_int || !stream.eof()) return INT64_MIN;
  return val;
}

int64_t convertFromDec(const std::string& s) {
  std::istringstream stream(s);
  int val;
  bool valid_int = bool(stream >> val);
  if (!valid_int || !stream.eof()) return INT64_MIN;
  return val;
}

int64_t convertFromInteger(const std::string& s) {
  char* end = nullptr;
  int64_t val = strtoll(s.c_str(), &end, 0);
  if (end != s.c_str() + s.size() || int32_t(val) != val) return INT64_MIN;
  return val;
}
