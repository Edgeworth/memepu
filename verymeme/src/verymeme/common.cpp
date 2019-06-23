#include "verymeme/common.h"

#include <regex>

std::string trim(const std::string& data, const std::string& c) {
  const std::regex trim("^[" + c + "]*((\n|.)*?)[" + c + "]*$");
  std::smatch sm;
  verify_expr(std::regex_match(data, sm, trim), "BUG");
  return sm[1].str();
}

int convertFromHex(const std::string& s) {
  std::istringstream stream(s);
  int val;
  bool valid_int = bool(stream >> std::hex >> val);
  if (!valid_int || !stream.eof())
    return INT_MIN;
  return val;
}

int convertFromDec(const std::string& s) {
  std::istringstream stream(s);
  int val;
  bool valid_int = bool(stream >> val);
  if (!valid_int || !stream.eof())
    return INT_MIN;
  return val;
}
