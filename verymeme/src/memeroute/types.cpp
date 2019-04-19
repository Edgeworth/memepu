#include "memeroute/types.h"

namespace memeroute {

const std::string SIDE_MAPPING[] = {"front", "back"};

std::ostream& operator<<(std::ostream& str, const Side& o) {
  return outputEnum(str, o, SIDE_MAPPING);
}

std::istream& operator>>(std::istream& str, Side& o) {
  return inputEnum(str, o, SIDE_MAPPING);
}

}  // memeroute
