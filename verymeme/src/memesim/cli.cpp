#include "memesim/cli.h"

#include <iostream>
#include <map>

#include "verymeme/concurrent_queue.h"
#include "verymeme/string_util.h"
#include "verymeme/term.h"

namespace memesim {

namespace {

const std::map<char, std::tuple<TermColor, TermColor, TermStyle>> COLOR_MAP = {
    {'0', {TermColor::FG_GREEN, TermColor::BG_DEFAULT, TermStyle::BOLD}},
    {'1', {TermColor::FG_RED, TermColor::BG_DEFAULT, TermStyle::BOLD}},
    {'2', {TermColor::FG_GREEN, TermColor::BG_DEFAULT, TermStyle::BOLD}},
    {'3', {TermColor::FG_RED, TermColor::BG_DEFAULT, TermStyle::BOLD}},
    {'4', {TermColor::FG_GREEN, TermColor::BG_DEFAULT, TermStyle::BOLD}},
    {'5', {TermColor::FG_RED, TermColor::BG_DEFAULT, TermStyle::BOLD}},
    {'6', {TermColor::FG_GREEN, TermColor::BG_DEFAULT, TermStyle::BOLD}},
    {'7', {TermColor::FG_RED, TermColor::BG_DEFAULT, TermStyle::BOLD}},
    {'8', {TermColor::FG_GREEN, TermColor::BG_DEFAULT, TermStyle::BOLD}},
    {'9', {TermColor::FG_RED, TermColor::BG_DEFAULT, TermStyle::BOLD}},
    {'a', {TermColor::FG_GREEN, TermColor::BG_DEFAULT, TermStyle::BOLD}},
    {'b', {TermColor::FG_RED, TermColor::BG_DEFAULT, TermStyle::BOLD}},
    {'c', {TermColor::FG_GREEN, TermColor::BG_DEFAULT, TermStyle::BOLD}},
    {'d', {TermColor::FG_RED, TermColor::BG_DEFAULT, TermStyle::BOLD}},
    {'e', {TermColor::FG_GREEN, TermColor::BG_DEFAULT, TermStyle::BOLD}},
    {'f', {TermColor::FG_RED, TermColor::BG_DEFAULT, TermStyle::BOLD}},
};

std::string prettyPrintNumbers(const std::string& s) {
  std::string pretty;
  for (char c : s) {
    auto iter = COLOR_MAP.find(c);
    if (iter != COLOR_MAP.end()) {
      pretty += convertToColor(std::string(1, c), std::get<0>(iter->second),
          std::get<1>(iter->second), std::get<2>(iter->second));
    } else {
      pretty += c;
    }
  }
  return pretty;
}

void printTable(const std::vector<std::pair<std::string, std::string>>& table) {
  constexpr int MAX_FIELD = 14;
  constexpr int MAX_COL = 70;
  int col = 0;
  bool first = true;
  for (const auto& [name, val] : table) {
    col += MAX_FIELD;
    if (!first) {
      if (col > MAX_COL) {
        col = MAX_FIELD;
        putchar('\n');
      } else {
        putchar(' ');
      }
    }
    first = false;

    const int SPACING = MAX_FIELD - int(name.length()) - int(val.length());
    fputs(name.c_str(), stdout);
    putchar(':');
    for (int i = 0; i < SPACING; ++i) putchar(' ');
    fputs(prettyPrintNumbers(val).c_str(), stdout);
  }
  putchar('\n');
}

}  // namespace

CommandLine::CommandLine(Simulator* simulator)
    : simulator_(simulator), receiver_(new ConcurrentQueue<Simulator::Response>()) {}

void CommandLine::run() {
  while (true) {
    std::string cmd;
    std::cout << "> ";
    std::getline(std::cin, cmd);
    cmd = trim(cmd, "\\n ");
    if (cmd == "q") {
      simulator_->scheduleCommand({Simulator::Command::Type::QUIT, {}, nullptr});
      break;
    } else if (cmd == "c") {
      simulator_->scheduleCommand({Simulator::Command::Type::RUN,  {},nullptr});
    } else {
      simulator_->scheduleCommand({Simulator::Command::Type::STEP,  {},nullptr});
      simulator_->scheduleCommand({Simulator::Command::Type::GET_CPU_STATE,  {},receiver_});
      const auto& state = std::get<Simulator::CpuStateMessage>(receiver_->yield());
      printCpuState(state);
    }
  }
}

void CommandLine::printCpuState(const Simulator::CpuStateMessage& state) {
  const std::vector<std::pair<std::string, std::string>> table = {
      {"bus", convertToHex(state.bus)},
      {"tmp0", convertToHex(state.tmp0)},
      {"tmp1", convertToHex(state.tmp1)},
      {"ow op", convertToHex(state.opword_opcode)},
      {"ow bits", convertToHex(state.opword_bits)},
      {"mlu", convertToHex(state.mlu)},
      {"cond_var", convertToHex(state.cond_var)},
      {"opcode", convertToHex(state.opcode)},
      {"microop", convertToHex(state.microop_count)},
      {"ctrl data", convertToHex(state.ctrl_data)},
      {"reg sel", convertToHex(state.reg_sel)},
      {"out", convertToHex(state.out_plane)},
      {"in", convertToHex(state.in_plane)},
      {"misc", convertToHex(state.misc_plane)},
      {"mlu plane", convertToBinary<4>(state.mlu_plane)},
      {"shifter", convertToBinary<2>(state.shifter_plane)},
      {"opcode sel", convertToHex(state.opcode_sel)},
      {"cond var sel", convertToHex(state.cond_var_sel)},
      {"n_rst", convertToBinary<1>(state.n_rst)},
      {"asm", state.mnemonic},
  };
  printTable(table);
  printf("%s\n", prettyPrintNumbers(hexdump(state.regs, 8)).c_str());
}

}  // namespace memesim
