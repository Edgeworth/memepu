#include <boost/program_options.hpp>
#include <iostream>

#include "verymeme/common.h"
#include "Vkpu.h"
#include "Vkpu_kpu.h"
#include "Vkpu_control_logic.h"
#include "Vkpu_register_file.h"
#include "Vkpu_sram__D5_W20.h"
#include "Vkpu_microcode.h"
#include "verymeme/file.h"
#include "verymeme/term.h"

namespace po = boost::program_options;

void clockKpu(Vkpu& kpu) {
  kpu.CLK = 0;
  kpu.N_CLK = 1;
  kpu.eval();

  kpu.CLK = 1;
  kpu.N_CLK = 0;
  kpu.eval();
}

void resetKpu(Vkpu& kpu) {
  kpu.CLK = 0;
  kpu.N_CLK = 1;
  kpu.N_RST_ASYNC = 0;
  kpu.eval();
  kpu.N_RST_ASYNC = 1;
  kpu.eval();
}

const std::map<char, std::tuple<TermColor, TermColor, TermStyle>> COLOR_MAP = {
    {'0', {TermColor::FG_GREEN, TermColor::BG_DEFAULT, TermStyle::BOLD}},
    {'1', {TermColor::FG_RED,   TermColor::BG_DEFAULT, TermStyle::BOLD}},
    {'2', {TermColor::FG_GREEN, TermColor::BG_DEFAULT, TermStyle::BOLD}},
    {'3', {TermColor::FG_RED,   TermColor::BG_DEFAULT, TermStyle::BOLD}},
    {'4', {TermColor::FG_GREEN, TermColor::BG_DEFAULT, TermStyle::BOLD}},
    {'5', {TermColor::FG_RED,   TermColor::BG_DEFAULT, TermStyle::BOLD}},
    {'6', {TermColor::FG_GREEN, TermColor::BG_DEFAULT, TermStyle::BOLD}},
    {'7', {TermColor::FG_RED,   TermColor::BG_DEFAULT, TermStyle::BOLD}},
    {'8', {TermColor::FG_GREEN, TermColor::BG_DEFAULT, TermStyle::BOLD}},
    {'9', {TermColor::FG_RED,   TermColor::BG_DEFAULT, TermStyle::BOLD}},
    {'a', {TermColor::FG_GREEN, TermColor::BG_DEFAULT, TermStyle::BOLD}},
    {'b', {TermColor::FG_RED,   TermColor::BG_DEFAULT, TermStyle::BOLD}},
    {'c', {TermColor::FG_GREEN, TermColor::BG_DEFAULT, TermStyle::BOLD}},
    {'d', {TermColor::FG_RED,   TermColor::BG_DEFAULT, TermStyle::BOLD}},
    {'e', {TermColor::FG_GREEN, TermColor::BG_DEFAULT, TermStyle::BOLD}},
    {'f', {TermColor::FG_RED,   TermColor::BG_DEFAULT, TermStyle::BOLD}},
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
  for (const auto&[name, val] : table) {
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

template<std::size_t N>
std::string convertToString(const WData (& data)[N]) {
  std::string str;
  str.reserve(N * sizeof(WData));
  static_assert(sizeof(WData) == 4, "bug");
  for (WData c : data) {
    str += char(c & 0xFF);
    str += char((c >> 8) & 0xFF);
    str += char((c >> 16) & 0xFF);
    str += char((c >> 24) & 0xFF);
  }
  std::string trimmed(str.c_str());  // Cut off at first 0 byte.
  return std::string(trimmed.rbegin(), trimmed.rend()); // Reverse
}

void printKpu(Vkpu& kpu) {
  const std::vector<std::pair<std::string, std::string>> table = {
      {"bus",        convertToHex(uint32_t(kpu.kpu->bus))},
      {"tmp0",       convertToHex(uint32_t(kpu.kpu->tmp0_val))},
      {"tmp1",       convertToHex(uint32_t(kpu.kpu->tmp1_val))},
      {"ow op",      convertToHex(uint32_t(kpu.kpu->opword_opcode))},
      {"ow bits",    convertToHex(uint32_t(kpu.kpu->opword_bits))},
      {"mlu",        convertToHex(uint32_t(kpu.kpu->mlu_val))},
      {"opcode",     convertToHex(uint32_t(kpu.kpu->control->opcode))},
      {"microop",    convertToHex(uint32_t(kpu.kpu->control->microop_count))},
      {"ctrl data",  convertToHex(uint32_t(kpu.kpu->control->CTRL_DATA))},
      {"reg sel",    convertToHex(uint32_t(kpu.kpu->control->REG_SEL))},
      {"out",        convertToHex(uint32_t(kpu.kpu->control->control_out_plane))},
      {"in",         convertToHex(uint32_t(kpu.kpu->control->control_in_plane))},
      {"misc",       convertToHex(uint32_t(kpu.kpu->control->control_misc_plane))},
      {"mlu plane",  convertToBinary<4>(kpu.kpu->control->MLU_PLANE)},
      {"shifter",    convertToBinary<2>(kpu.kpu->control->SHIFTER_PLANE)},
      {"opcode sel", convertToHex(uint32_t(kpu.kpu->control->control_opcode_sel))},
      {"n_rst",        convertToBinary<1>(kpu.kpu->n_rst)},
      {"asm",        convertToString(kpu.kpu->control->microcode->mnemonic)},
  };
  printTable(table);
  printf("%s\n", prettyPrintNumbers(hexdump(kpu.kpu->regs->registers->mem, 8)).c_str());
}

int main(int argc, char* argv[]) {
  try {
    po::options_description desc{"Options"};
    desc.add_options()
        ("help,h", "Help screen");

    po::variables_map vm;
    po::store(po::command_line_parser(argc, argv).options(desc).run(), vm);

    if (vm.count("help")) {
      std::cout << desc << '\n';
      return 0;
    }

    po::notify(vm);
  } catch (const po::error& ex) {
    std::cerr << ex.what() << '\n';
    return 1;
  }

  checkedChdir("verilog");

  Verilated::commandArgs(argc, argv);
  Verilated::randReset(2);
  Verilated::debug(2);

  Vkpu kpu;
  kpu.N_RST_ASYNC = 1;
  kpu.eval();  // Eval once to set up all signals (X => defined value).
  clockKpu(kpu);  // Clock to end any reset that happened from X => defined value.
  resetKpu(kpu);  // Actually reset.
  while (true) {
    std::string cmd;
    printKpu(kpu);
    std::cout << "> ";
    std::getline(std::cin, cmd);
    cmd = trim(cmd, "\\n ");
    if (cmd == "q") break;
    else clockKpu(kpu);
  }
}
