#include "memeware/microcode.h"
#include "memeware/constants.h"

#include "Vmicrocode.h"
#include "Vmlu_lookahead.h"
#include "Vmlu_slice.h"

namespace memeware {

std::vector<uint8_t> generateMluSliceFirmware() {
  Vmlu_slice slice;
  std::vector<uint8_t> firmware;
  const int MAX_ADDR = (1u << 12u);
  for (int addr = 0; addr < MAX_ADDR; ++addr) {
    slice.ADDR = addr;
    slice.eval();
    firmware.push_back(slice.OUT);
  }
  return firmware;
}

std::vector<uint8_t> generateMluLookaheadFirmware() {
  Vmlu_lookahead lookahead;
  std::vector<uint8_t> firmware;
  const int MAX_ADDR = (1u << 17u);
  for (int addr = 0; addr < MAX_ADDR; ++addr) {
    lookahead.ADDR = addr;
    lookahead.eval();
    firmware.push_back(lookahead.CARRYS);
  }
  return firmware;
}

std::vector<uint32_t> generateMicrocodeFirmware() {
  Vmicrocode microcode;
  std::vector<uint32_t> firmware;
  const int MAX_ADDR = (1u << 10u);
  for (int addr = 0; addr < MAX_ADDR; ++addr) {
    microcode.ADDR = addr;
    microcode.eval();
    firmware.push_back(microcode.OUT);
  }
  return firmware;
}

}  // memeware
