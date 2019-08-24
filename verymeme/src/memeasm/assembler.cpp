#include "memeasm/assembler.h"

#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <cinttypes>

#include "memeware/constants.h"
#include "verymeme/string_util.h"

namespace memeasm {

namespace {

const char* PREAMBLE_RX = "\\s*";
const char* POSTAMBLE_RX = "\\s*(;.*)?";
const char* LABEL_RX = "([0-9a-zA-Z]+):";

std::vector<std::string> getLines(const std::string& data) {
  std::stringstream ss(data);
  std::string line;
  std::vector<std::string> lines;
  while (std::getline(ss, line)) {
    int last_idx = 0;
    while (last_idx < int(line.size()) && line[last_idx] != ';') last_idx++;  // Remove comments.
    const auto& s = trim(line.substr(0, last_idx), " \t\n");
    if (!s.empty()) lines.push_back(s);
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
    for (int i = 0; i < int(mnemonic_str.size()); ++i) {
      if (mnemonic_str[i] == '%') {
        verify_expr(i < int(mnemonic_str.size()) - 2, "ill-formed ksm model (BUG)");
        i += 2;  // Skip % and number.
        char type = mnemonic_str[i];
        Parameter param;
        if (type == '%') {  // No format specifier, assume register.
          param = Parameter::REGISTER;
        } else if (type == '$') {  // Format specifier, assume immediate and skip specifier.
          param = Parameter::IMMEDIATE;
          i++;
        } else
          verify_expr(false, "unknown parameter type '%c'", type);
        mnemonic_rx += "([0-9a-zA-Z]+)";
        mnemonic.params.push_back(param);
      } else {
        std::string escape = "";
        if (mnemonic_str[i] == '[' || mnemonic_str[i] == ']') escape = "\\";
        mnemonic_rx += escape + mnemonic_str[i];
      }
    }
    mnemonic_rx += POSTAMBLE_RX;
    mnemonic.rx = std::regex(mnemonic_rx);
    mnemonics_.push_back(mnemonic);
  }
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

  for (int lnum = 0; lnum < int(lines_.size()); ++lnum) {
    const std::string& line = lines_[lnum];

    std::smatch sm;
    if (std::regex_match(line, sm, label_rx)) {
      const auto& label = sm[1].str();
      if (first_pass) {
        verify_expr(labels_.count(label) == 0, "%d: duplicate label definition of %s", lnum + 1,
            label.c_str());
        labels_[label] = int(bin_.size()) * memeware::OPWORD_SIZE;
      }
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
    for (int i = 0; i < int(mnemonic.params.size()); ++i) {
      verify_expr(i + 1 < int(sm.size()), "%d: missing parameter %s", lnum, line.c_str());
      const auto& pstr = sm[i + 1].str();
      switch (mnemonic.params[i]) {
      case Parameter::REGISTER: {
        const auto reg = convertFromDec(pstr);
        verify_expr(reg >= 0 && reg <= 31, "%d: register %" PRId64 " does not exist", lnum, reg);
        opword |= (uint32_t(reg) << (reg_count * 5u + 6u));
        reg_count++;
        break;
      }
      case Parameter::IMMEDIATE: {
        auto imm = convertFromHex(pstr);
        if (imm == INT64_MIN) {
          if (first_pass) {
            imm = 0;  // Placeholder value.
          } else {
            const auto& label = pstr;
            verify_expr(
                labels_.count(label), "%d: missing label definition of %s", lnum, label.c_str());
            if (mnemonic.imm_relative)
              imm = labels_[label] - bin_.size() * memeware::OPWORD_SIZE - memeware::OPWORD_SIZE;
            else
              imm = labels_[label];
          }
        }
        verify_expr(imm < 0 ? int16_t(imm) == imm : uint16_t(imm) == imm,
            "%d: immediate value %" PRId64 " out of range", lnum, imm);
        opword |= uint32_t(imm) << 16u;
        break;
      }
      }
    }
    return opword;
  }
  verify_expr(false, "%d: unable to parse %s", lnum, line.c_str());
}

}  // namespace memeasm
