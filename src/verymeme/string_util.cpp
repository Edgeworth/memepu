// Copyright 2019 E.
#include "verymeme/string_util.h"

#include <regex>
#include <string>

std::string trim(const std::string& data, const std::string& c) {
  const std::regex trim("^[" + c + "]*((\n|.)*?)[" + c + "]*$");
  std::smatch sm;
  bug_unless(std::regex_match(data, sm, trim));
  return sm[1].str();
}

int64_t convertFromHex(const std::string& s) {
  std::istringstream stream(s);
  int64_t val = 0;
  bool valid_int = static_cast<bool>(stream >> std::hex >> val);
  if (!valid_int || !stream.eof()) return INT64_MIN;
  return val;
}

int64_t convertFromDec(const std::string& s) {
  std::istringstream stream(s);
  int64_t val = 0;
  bool valid_int = static_cast<bool>(stream >> val);
  if (!valid_int || !stream.eof()) return INT64_MIN;
  return val;
}

int64_t convertFromInteger(const std::string& s) {
  char* end = nullptr;
  int64_t val = strtoll(s.c_str(), &end, 0);
  if (end != s.c_str() + s.size() || int32_t(val) != val) return INT64_MIN;
  return val;
}

std::string join(const std::vector<std::string>& l, const std::string& j, bool terminate) {
  std::string ret;
  for (int i = 0; i < static_cast<int>(l.size()) - 1; ++i) ret += l[i] + j;
  if (!l.empty()) ret += l.back();
  if (terminate) ret += j;
  return ret;
}
