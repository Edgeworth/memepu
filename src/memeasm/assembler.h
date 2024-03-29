// Copyright 2019 E.
#ifndef MEMEASM_ASSEMBLER_H_
#define MEMEASM_ASSEMBLER_H_

#include <cstdint>
#include <map>
#include <regex>
#include <string>
#include <vector>

namespace memeasm {

class Assembler {
 public:
  explicit Assembler(const std::string& model_json);

  std::vector<uint32_t> assemble(const std::string& data);

  static std::string generateMnemonicString(const std::string& mnemonic_str, uint32_t opword_bits);

 private:
  enum class Parameter { REGISTER, IMMEDIATE, DATA };

  struct Mnemonic {
    std::regex rx;
    int opcode;
    bool imm_relative;
    std::vector<Parameter> params;
  };

  std::vector<Mnemonic> mnemonics_;
  std::vector<std::string> lines_;
  std::vector<uint32_t> bin_;
  std::map<std::string, uint32_t> labels_;

  uint32_t convertMnemonicStringToOpword(const std::string& line, int lnum, bool first_pass);
  void assembleInternal(bool first_pass);
  int64_t resolveLabel(const std::string& label, int lnum, bool first_pass, bool relative);
};

}  // namespace memeasm

#endif  // MEMEASM_ASSEMBLER_H_
