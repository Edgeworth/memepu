#include "asm.h"

namespace {

struct OpcodeData {
  Opcode opcode;
  int int_params;
  int label_params;
};

std::map<std::string, OpcodeData> OPCODE_DATA = {
    {"LDA", {Opcode::LDA_IMM, 1, 0}},
    {"LDB", {Opcode::LDB_IMM, 1, 0}},
    {"LDM0", {Opcode::LDM0_IMM, 1, 0}},
    {"ADD", {Opcode::ADD, 0, 0}},
    {"SUB", {Opcode::SUB, 0, 0}},
    {"JMP", {Opcode::JMP, 0, 1}},
    {"DSP", {Opcode::DISPLAY, 0, 0}},
    {"SWP", {Opcode::SWAP, 0, 0}},
    {"LDINT", {Opcode::LDA_INT, 0, 0}}
};

int parseHexInt(const std::string& s) {
  std::istringstream stream(s);
  int val;
  bool valid_int = bool(stream >> std::hex >> val);
  if (!valid_int || !stream.eof())
    return -1;
  return val;
}

constexpr uint32_t START_OFFSET = 0x0; // TODO: EEPROM has line 20 low - BUG.

}  // namespace

std::string Asm::assembleToBinaryData() {
  std::string token;
  std::string label;
  while (stream_ >> token) {
    if (token.back() == ':') {
      parseLabelOrOffset(token);
    } else {
      parseInstruction(token);
    }


  }
  return mergeExtents();
}

void Asm::parseLabelOrOffset(const std::string& token) {
  std::string label = token.substr(0, token.size() - 1);

  int offset = parseHexInt(label);
  if (offset >= 0) {
    cur_extent_ = offset;
  } else {
    verify_expr(labels_.find(label) == labels_.end(), "redefinition of label %s", label.c_str());
    labels_[label] = uint32_t(extents_[cur_extent_].size()) + cur_extent_ + START_OFFSET;
  }

}

void Asm::parseInstruction(const std::string& token) {
  auto iter = OPCODE_DATA.find(token);
  verify_expr(iter != OPCODE_DATA.end(), "unknown instruction %s", token.c_str());

  auto opcode = iter->second;
  extents_[cur_extent_] += uint8_t(opcode.opcode);

  int param;
  for (int i = 0; i < opcode.int_params; ++i) {
    verify_expr(stream_ >> param, "expected %d ints after %s", opcode.int_params, token.c_str());
    verify_expr(uint8_t(param) == param, "param must be 8 bit");
    extents_[cur_extent_] += uint8_t(param);
  }

  std::string label;
  for (int i = 0; i < opcode.label_params; ++i) {
    verify_expr(stream_ >> label, "expected %d labels after %s", opcode.label_params, token.c_str());
    auto label_iter = labels_.find(label);
    verify_expr(label_iter != labels_.end(), "unknown label %s", label.c_str());  // TODO: Currently can't reference labels in the future.
    extents_[cur_extent_] += uint8_t(label_iter->second);
    extents_[cur_extent_] += uint8_t(label_iter->second >> 8);
    extents_[cur_extent_] += uint8_t(label_iter->second >> 16);
  }
}

std::string Asm::mergeExtents() {
  std::string output;
  for (const auto& iter : extents_) {
    int addr = iter.first;
    const std::string& data = iter.second;
    int gap = addr - int(output.size());
    verify_expr(gap >= 0, "overlapping %d bytes into extent starting at %x", -gap, addr);
    for (int i = 0; i < gap; ++i) {
      output += uint8_t(0xFF);
    }
    output += data;
  }
  return output;
}
