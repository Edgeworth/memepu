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
    {"JMP", {Opcode::JUMP, 0, 1}},
    {"DSP", {Opcode::DISPLAY, 0, 0}},
    {"SWP", {Opcode::SWAP, 0, 0}},
    {"LDINT", {Opcode::LDA_INT, 0, 0}},
    {"DMP", {Opcode::DUMP, 0, 0}},
    {"RFI", {Opcode::RETURN_FROM_ISR, 0, 0}},
    {"EINT", {Opcode::ENABLE_INTERRUPTS, 0, 0}},
    {"DINT", {Opcode::DISABLE_INTERRUPTS, 0, 0}},
    {"IN0", {Opcode::IN_DEV_0, 0, 0}},
    {"OUT0", {Opcode::OUT_IMM_DEV_0, 1, 0}},
    {"CMP", {Opcode::COMPARE, 0, 0}},
    {"JZ", {Opcode::JUMP_IF_ZERO, 0, 1}}
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
  // Do first pass to get label addresses.
  doPass(true);
  extents_.clear();
  cur_extent_ = 0;

  doPass(false);
  return mergeExtents();
}

void Asm::parseLabelOrOffset(std::string token, bool first_pass) {
  std::string label = token.substr(0, token.size() - 1);

  int offset = parseHexInt(label);
  if (offset >= 0) {
    cur_extent_ = offset;
  } else {
    verify_expr(!first_pass || labels_.find(label) == labels_.end(), "redefinition of label %s", label.c_str());
    labels_[label] = uint32_t(extents_[cur_extent_].size()) + cur_extent_ + START_OFFSET;
  }

}

void Asm::parseInstruction(std::string token, std::istringstream& stream, bool first_pass) {
  auto iter = OPCODE_DATA.find(token);
  verify_expr(iter != OPCODE_DATA.end(), "unknown instruction %s", token.c_str());

  auto opcode = iter->second;
  extents_[cur_extent_] += uint8_t(opcode.opcode);

  int param;
  for (int i = 0; i < opcode.int_params; ++i) {
    verify_expr(stream >> param, "expected %d ints after %s", opcode.int_params, token.c_str());
    verify_expr(uint8_t(param) == param, "param must be 8 bit");
    extents_[cur_extent_] += uint8_t(param);
  }

  std::string label;
  for (int i = 0; i < opcode.label_params; ++i) {
    verify_expr(stream >> label, "expected %d labels after %s", opcode.label_params, token.c_str());
    auto label_iter = labels_.find(label);
    verify_expr(first_pass || label_iter != labels_.end(), "unknown label %s", label.c_str());
    if (first_pass) {
      extents_[cur_extent_] += uint8_t(0);
      extents_[cur_extent_] += uint8_t(0);
      extents_[cur_extent_] += uint8_t(0);
    } else {
      extents_[cur_extent_] += uint8_t(label_iter->second);
      extents_[cur_extent_] += uint8_t(label_iter->second >> 8);
      extents_[cur_extent_] += uint8_t(label_iter->second >> 16);
    }

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

void Asm::doPass(bool first_pass) {
  std::string token;
  std::string line;
  std::istringstream lines(data_);
  while (std::getline(lines, line)) {
    std::istringstream stream(line);
    if (!(stream >> token))
      continue;

    if (token.front() == ';') {
      continue;  // Skip comments.
    } else if (token.back() == ':') {
      parseLabelOrOffset(token, first_pass);
    } else {
      parseInstruction(token, stream, first_pass);
    }
  }
}
