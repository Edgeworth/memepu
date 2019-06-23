#include "memeasm/assembler.h"

#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>

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
    if (line.back() == '\n') line.pop_back();
    lines.push_back(std::move(line));
  }
  return lines;
}

}

namespace pt = boost::property_tree;

Assembler::Assembler(const std::string& model_json) {
  pt::ptree root;
  std::stringstream s(model_json);
  pt::read_json(s, root);
  for (const auto& kv : root) {
    const auto& mnemonic_str = kv.second.get<std::string>("mnemonic");
    Mnemonic mnemonic = {};
    mnemonic.opcode = kv.second.get<int>("opcode");
    std::string mnemonic_rx = PREAMBLE_RX;
    for (int i = 0; i < int(mnemonic_str.size()); ++i) {
      if (mnemonic_str[i] == '%') {
        verify_expr(i != int(mnemonic_str.size()) - 1, "ill-formed ksm model (BUG)");
        char type = mnemonic_str[++i];
        Parameter param;
        if (type == 'd') {
          param = Parameter::REGISTER;
        } else if (type == 'x') {
          param = Parameter::IMMEDIATE;
        } else
          verify_expr(false, "unknown parameter type '%c'", type);
        mnemonic_rx += "([0-9a-zA-Z]+)";
        mnemonic.params.push_back(param);
      } else {
        mnemonic_rx += mnemonic_str[i];
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
        labels_[label] = bin_.size() * sizeof(bin_[0]);
      }
      continue;
    }

    bool found = false;
    for (const auto& mnemonic : mnemonics_) {
      if (!std::regex_match(line, sm, mnemonic.rx)) continue;
      found = true;

      uint32_t opword = mnemonic.opcode;
      int reg_count = 0;
      for (int i = 0; i < int(mnemonic.params.size()); ++i) {
        verify_expr(i + 1 < int(sm.size()), "%d: missing parameter %s", lnum + 1, line.c_str());
        const auto& pstr = sm[i + 1].str();
        switch (mnemonic.params[i]) {
          case Parameter::REGISTER: {
            const int reg = convertFromDec(pstr);
            verify_expr(reg >= 0 && reg <= 31, "%d: register %d does not exist", lnum + 1, reg);
            opword |= (uint32_t(reg) << (reg_count * 5u + 6u));
            reg_count++;
            break;
          }
          case Parameter::IMMEDIATE: {
            int imm = convertFromHex(pstr);
            if (imm == INT_MIN) {
              const auto& label = pstr;
              verify_expr(labels_.count(label), "%d: missing label definition of %s", lnum + 1,
                  label.c_str());
              imm = labels_[label];
            }
            // TODO: Check signedness.
            verify_expr(
                imm <= std::numeric_limits<uint16_t>::max() &&
                imm >= std::numeric_limits<uint16_t>::min(),
                "%d: immediate value %d out of range", lnum + 1, imm);
            opword |= uint32_t(imm) << 16u;
            break;
          }
        }
      }
      bin_.push_back(opword);
      break;
    }
    verify_expr(found, "%d: unable to parse %s", lnum + 1, line.c_str());
  }
}

}  // memeasm
