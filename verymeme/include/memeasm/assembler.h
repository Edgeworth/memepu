#ifndef MEMEASM_ASSEMBLER_H
#define MEMEASM_ASSEMBLER_H

#include "verymeme/common.h"

#include <regex>

namespace memeasm {

class Assembler {
public:
  explicit Assembler(const std::string& model_json);

  std::vector<uint32_t> assemble(const std::string& data);

private:
  enum class Parameter {
    REGISTER, IMMEDIATE
  };

  struct Mnemonic {
    std::regex rx;
    int opcode;
    bool imm_signed;
    bool imm_relative;
    std::vector<Parameter> params;
  };

  std::vector<Mnemonic> mnemonics_;
  std::vector<std::string> lines_;
  std::vector<uint32_t> bin_;
  std::map<std::string, uint32_t> labels_;

  void assembleInternal(bool first_pass);
};

}  // memeasm

#endif  // MEMEASM_ASSEMBLER_H
