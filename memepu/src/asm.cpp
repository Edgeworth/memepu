#include <sstream>
#include <unordered_map>
#include "asm.h"

namespace {

struct OpcodeData {
  Opcode opcode;
  int int_params;
  int label_params;
};

std::unordered_map<std::string, OpcodeData> OPCODE_DATA = {
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

}  // namespace

std::string Asm::assembleToBinaryData(const std::string& filedata) {
  constexpr uint32_t START_OFFSET = 0x0; // TODO: EEPROM has line 20 low - BUG.
  std::istringstream stream(filedata);
  std::string output;
  std::string token;
  std::unordered_map<std::string, uint32_t> labels;
  int param;
  std::string label;
  while (stream >> token) {
    if (token.back() == ':') {
      label = token.substr(0, token.size() - 1);
      verify_expr(labels.find(label) == labels.end(), "redefinition of label %s", label.c_str());
      labels[label] = static_cast<uint32_t>(output.size()) + START_OFFSET;  // TODO: Start offset - make configurable.
      continue;
    }
    auto iter = OPCODE_DATA.find(token);
    verify_expr(iter != OPCODE_DATA.end(), "unknown instruction %s", token.c_str());
    auto data = iter->second;
    output += static_cast<uint8_t>(data.opcode);

    for (int i = 0; i < data.int_params; ++i) {
      verify_expr(stream >> param, "expected %d ints after %s", data.int_params, token.c_str());
      verify_expr(static_cast<uint8_t>(param) == param, "param must be 8 bit");
      output += static_cast<uint8_t>(param);
    }

    for (int i = 0; i < data.label_params; ++i) {
      verify_expr(stream >> label, "expected %d labels after %s", data.label_params, token.c_str());
      auto label_iter = labels.find(label);
      verify_expr(label_iter != labels.end(), "unknown label %s", label.c_str());  // TODO: Currently can't reference labels in the future.
      output += static_cast<uint8_t>(label_iter->second);
      output += static_cast<uint8_t>(label_iter->second >> 8);
      output += static_cast<uint8_t>(label_iter->second >> 16);
    }
  }
  return output;
}
