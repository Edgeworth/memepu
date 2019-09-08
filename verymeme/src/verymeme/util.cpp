#include "verymeme/util.h"

#include <boost/stacktrace.hpp>
#include <sstream>

std::string getStacktrace() {
  std::stringstream s;
  s << boost::stacktrace::stacktrace();
  return s.str();
}
