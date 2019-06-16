#include "verymeme/common.h"

#include <regex>

std::string trim(const std::string& data, const std::string& c) {
  const std::regex trim("^[" + c + "]*((\n|.)*?)[" + c + "]*$");
  std::smatch sm;
  verify_expr(std::regex_match(data, sm, trim), "BUG");
  return sm[1].str();
}

