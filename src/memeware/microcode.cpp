// Copyright 2019 E.
#include "memeware/microcode.h"

#include <sstream>

#include "Vmicrocode.h"
#include "Vmicrocode_microcode.h"
#include "Vmlu_lookahead.h"
#include "Vmlu_slice.h"
#include "boost/property_tree/json_parser.hpp"
#include "boost/property_tree/ptree.hpp"
#include "memeware/constants.h"
#include "verymeme/string_util.h"

namespace memeware {

namespace pt = boost::property_tree;

std::vector<uint8_t> generateMluSliceFirmware() {
  Vmlu_slice slice;
  std::vector<uint8_t> firmware;
  const int MAX_ADDR = (1u << MLU_SLICE_DEPTH);
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
  const int MAX_ADDR = (1u << MLU_LOOKAHEAD_DEPTH);
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
  const int MAX_ADDR = (1u << MICROCODE_DEPTH);
  for (int addr = 0; addr < MAX_ADDR; ++addr) {
    microcode.ADDR = addr;
    microcode.eval();
    firmware.push_back(microcode.OUT);
  }
  return firmware;
}

std::string generateMemeasmModel() {
  Vmicrocode microcode;
  // This must be updated if the opcode format or location is changed.
  const int MAX_OPCODE = (1u << 6u);
  std::stringstream s;
  bool first = true;
  s << "[\n";
  for (uint16_t opcode = 0; opcode < MAX_OPCODE; ++opcode) {
    microcode.ADDR = opcode << 5u;
    microcode.eval();

    const std::string mnemonic = convertToString(microcode.microcode->mnemonic);
    if (mnemonic.empty()) continue;

    pt::ptree instruction;
    if (!first) s << ",";
    instruction.add("opcode", opcode);
    instruction.add("mnemonic", mnemonic);
    instruction.add("imm_relative", microcode.microcode->imm_relative);
    pt::write_json(s, instruction);
    first = false;
  }
  s << "]\n";
  return s.str();
}

}  // namespace memeware
