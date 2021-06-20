// Copyright 2019 E.
#include "verymeme/macros.h"

#include <sstream>

#include "boost/stacktrace.hpp"

std::string getStacktrace() {
  std::stringstream s;
  s << boost::stacktrace::stacktrace();
  return s.str();
}
