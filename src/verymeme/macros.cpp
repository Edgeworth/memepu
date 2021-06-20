// Copyright 2019 E.
#include "verymeme/macros.h"

#include <boost/stacktrace.hpp>
#include <sstream>

std::string getStacktrace() {
  std::stringstream s;
  s << boost::stacktrace::stacktrace();
  return s.str();
}
