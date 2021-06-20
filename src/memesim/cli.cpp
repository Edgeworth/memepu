// Copyright 2019 E.
#include "memesim/cli.h"

#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

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
    {'f', {TermColor::FG_RED, TermColor::BG_DEFAULT, TermStyle::BOLD}}};

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

    const int SPACING = MAX_FIELD - name.length() - val.length();
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

void CommandLine::run(const std::string& initial_cmd) {
  if (!initial_cmd.empty()) processCmdLine(initial_cmd);

  while (true) {
    std::string line;
    std::cout << "> ";
    std::getline(std::cin, line);
    if (processCmdLine(line)) break;
  }
}

bool CommandLine::processCmdLine(const std::string& line) {
  std::stringstream ss(line);
  std::string cmd;
  do {
    ss >> cmd;
    if (cmd == "q") {
      simulator_->scheduleCommand({Simulator::Cmd::Type::QUIT, {}, nullptr});
      return true;
    } else if (cmd == "c") {
      simulator_->scheduleCommand({Simulator::Cmd::Type::RUN, {}, nullptr});
    } else if (cmd == "s") {
      simulator_->scheduleCommand({Simulator::Cmd::Type::STOP, {}, nullptr});
    } else if (cmd == "b") {
      uint32_t addr = 0;
      if (!(ss >> addr)) {
        printf("Set breakpoint missing address.\n");
        return false;
      } else {
        printf("Set breakpoint at %u\n", addr);
      }
      simulator_->scheduleCommand({Simulator::Cmd::Type::SET_BREAKPOINT, {addr}, receiver_});
    } else if (cmd != ";") {
      simulator_->scheduleCommand({Simulator::Cmd::Type::STEP, {}, receiver_});
      simulator_->scheduleCommand({Simulator::Cmd::Type::GET_CPU_STATE, {}, receiver_});
      const auto& state = std::get<Simulator::CpuStateMessage>(receiver_->yield());
      printCpuState(state);
    }
  } while (ss >> cmd);
  return false;
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
      {"int enabled", convertToHex(state.interrupts_enabled)},
      {"has int", convertToHex(state.has_interrupt)},
  };
  printTable(table);
  printf("%s\n", prettyPrintNumbers(hexdump(state.regs)).c_str());
}

}  // namespace memesim
