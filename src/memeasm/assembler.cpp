// Copyright 2019 E.
#include "memeasm/assembler.h"

#include <cinttypes>
#include <utility>

#include "boost/property_tree/json_parser.hpp"
#include "boost/property_tree/ptree.hpp"
#include "memeware/constants.h"
#include "verymeme/string_util.h"

namespace memeasm {

namespace {

#define IDENT_RX "([a-zA-Z_][0-9a-zA-Z_]*)"

const char* PREAMBLE_RX = "\\s*";
const char* POSTAMBLE_RX = "\\s*(;.*)?";
const char* LABEL_RX = IDENT_RX ":";
const char* LABEL_REF_RX = IDENT_RX "\\s*([+]\\s*(\\d+))?";

std::vector<std::string> getLines(const std::string& data) {
  std::stringstream ss(data);
  std::string line;
  std::vector<std::string> lines;
  while (std::getline(ss, line)) {
    int last_idx = 0;
    while (last_idx < static_cast<int>(line.size()) && line[last_idx] != ';')
      last_idx++;  // Remove comments.
    const auto& s = trim(line.substr(0, last_idx), " \t\n");
    lines.push_back(s);  // Include blank lines so line numbers are accurate.
  }
  return lines;
}

}  // namespace

namespace pt = boost::property_tree;

Assembler::Assembler(const std::string& model_json) {
  pt::ptree root;
  std::stringstream s(model_json);
  pt::read_json(s, root);
  for (const auto& kv : root) {
    const auto& mnemonic_str = kv.second.get<std::string>("mnemonic");
    Mnemonic mnemonic = {};
    mnemonic.opcode = kv.second.get<int>("opcode");
    mnemonic.imm_relative = kv.second.get<bool>("imm_relative");
    std::string mnemonic_rx = PREAMBLE_RX;
    for (int i = 0; i < static_cast<int>(mnemonic_str.size()); ++i) {
      if (mnemonic_str[i] == '%') {
        verify(i < static_cast<int>(mnemonic_str.size()) - 2, "ill-formed ksm model (BUG)");
        i += 2;  // Skip % and number.
        char type = mnemonic_str[i];
        Parameter param;
        if (type == '%') {  // No format specifier, assume register.
          param = Parameter::REGISTER;
          mnemonic_rx += "([0-9]+)";
        } else if (type == '$') {  // Format specifier, assume immediate and skip specifier.
          param = Parameter::IMMEDIATE;
          mnemonic_rx += "([^r][^,]*)";
          i++;
        } else
          verify(false, "unknown parameter type '%c'", type);
        mnemonic.params.push_back(param);
      } else {
        std::string escape;
        if (mnemonic_str[i] == '[' || mnemonic_str[i] == ']') escape = "\\";
        mnemonic_rx += escape + mnemonic_str[i];
      }
    }
    mnemonic_rx += POSTAMBLE_RX;
    mnemonic.rx = std::regex(mnemonic_rx);
    mnemonics_.push_back(mnemonic);
  }

  // Add data word mnemonic:
  Mnemonic dw = {};
  dw.opcode = 0;  // Set to zero so it doesn't affect data when OR'd together.
  dw.rx = std::regex(PREAMBLE_RX + std::string("dw\\s+(\\S+)") + POSTAMBLE_RX);
  dw.params.push_back(Parameter::DATA);
  mnemonics_.push_back(dw);
}

std::vector<uint32_t> Assembler::assemble(const std::string& data) {
  lines_ = getLines(data);
  bin_.clear();
  labels_.clear();

  assembleInternal(true /* first_pass */);
  bin_.clear();
  assembleInternal(false /* first_pass */);
  return std::move(bin_);
}

void Assembler::assembleInternal(bool first_pass) {
  std::regex label_rx(std::string(PREAMBLE_RX) + LABEL_RX + POSTAMBLE_RX);

  for (int lnum = 0; lnum < static_cast<int>(lines_.size()); ++lnum) {
    const std::string& line = lines_[lnum];
    if (line.empty()) continue;

    std::smatch sm;
    if (std::regex_match(line, sm, label_rx)) {
      resolveLabel(sm[1].str(), lnum + 1, first_pass, false);
      continue;
    }

    bin_.push_back(convertMnemonicStringToOpword(line, lnum + 1, first_pass));
  }
}

std::string Assembler::generateMnemonicString(
    const std::string& mnemonic_str, uint32_t opword_bits) {
  const uint32_t regs[3] = {
      opword_bits & 0x1Fu, (opword_bits >> 5u) & 0x1Fu, (opword_bits >> 10u) & 0x1Fu};
  const auto imm = uint16_t(opword_bits >> 10u);
  boost::format fmt(mnemonic_str);
  fmt.exceptions(boost::io::all_error_bits ^ boost::io::too_many_args_bit);
  return (fmt % regs[0] % regs[1] % regs[2] % imm).str();
}

uint32_t Assembler::convertMnemonicStringToOpword(
    const std::string& line, int lnum, bool first_pass) {
  std::smatch sm;
  for (const auto& mnemonic : mnemonics_) {
    if (!std::regex_match(line, sm, mnemonic.rx)) continue;

    auto opword = uint32_t(mnemonic.opcode);
    int reg_count = 0;
    for (int i = 0; i < static_cast<int>(mnemonic.params.size()); ++i) {
      verify(i + 1 < static_cast<int>(sm.size()), "%d: missing parameter %s", lnum, line.c_str());
      const auto& pstr = sm[i + 1].str();
      switch (mnemonic.params[i]) {
      case Parameter::REGISTER: {
        const auto reg = convertFromDec(pstr);
        verify(reg >= 0 && reg <= 31, "%d: register %" PRId64 " does not exist", lnum, reg);
        opword |= (uint32_t(reg) << (reg_count * 5u + 6u));
        reg_count++;
        break;
      }
      case Parameter::IMMEDIATE: {
        int64_t imm = convertFromHex(pstr);
        if (imm == INT64_MIN) {
          if (first_pass) {
            imm = 0;  // Placeholder value.
          } else {
            imm = resolveLabel(pstr, lnum, first_pass, mnemonic.imm_relative);
          }
        }
        verify(imm < 0 ? int16_t(imm) == imm : uint16_t(imm) == imm,
            "%d: immediate value %" PRId64 " out of range", lnum, imm);
        opword |= uint32_t(imm) << 16u;
        break;
      }
      case Parameter::DATA:
        if (!first_pass) {
          int64_t data = convertFromHex(pstr);
          if (data == INT64_MIN) data = resolveLabel(pstr, lnum, first_pass, false /* relative */);
          verify(data != INT64_MIN && data == uint32_t(data), "%d: invalid data parameter '%s'",
              lnum, pstr.c_str());
          opword |= uint32_t(data);
        }
        break;
      }
    }
    return opword;
  }
  verify(false, "%d: unable to parse %s", lnum, line.c_str());
}

int64_t Assembler::resolveLabel(const std::string& lstr, int lnum, bool first_pass, bool relative) {
  std::regex rx(LABEL_REF_RX);
  std::smatch sm;
  verify(std::regex_match(lstr, sm, rx), "%d: invalid label %s", lnum, lstr.c_str());

  const auto& label = sm[1].str();
  if (first_pass) {  // Defining labels in first pass.
    verify(
        labels_.count(label) == 0, "%d: duplicate label definition of %s", lnum + 1, label.c_str());
    labels_[label] = bin_.size() * memeware::OPWORD_SIZE;
    return 0;
  }

  // Referencing labels in second pass.
  verify(labels_.count(label), "%d: missing label definition of %s", lnum, label.c_str());
  int64_t addr = labels_[label];
  if (sm[2].matched) {
    // If we have computation for offset, do it.
    addr += convertFromInteger(sm[3].str());
  }
  if (relative) return addr - bin_.size() * memeware::OPWORD_SIZE - memeware::OPWORD_SIZE;
  return addr;
}

}  // namespace memeasm
