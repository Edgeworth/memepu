#include <iomanip>
#include "memeware/util.h"

namespace memeware {

std::string convertToHex(const std::vector<uint8_t>& input) {
  std::stringstream stream;
  int count = 0;
  for (auto c : input) {
    stream << std::hex << std::setw(2) << std::setfill('0') << int(c);
    if (++count == 40) {
      stream << "\n";
      count = 0;
    } else {
      stream << " ";
    }
  }
  if (count) stream << "\n";
  return stream.str();
}

}  // memeware
