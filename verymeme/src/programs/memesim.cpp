#include <boost/program_options.hpp>
#include <iostream>

#include "verymeme/common.h"
#include "Vkpu.h"
#include "Vkpu_kpu.h"
#include "Vkpu_control_logic.h"
#include "Vkpu_register_file.h"
#include "Vkpu_sram__D5_W20.h"
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

const std::map<char, TermColor> COLOR_MAP = {
    {'0', TermColor::FG_WHITE}
};

std::string prettyPrintNumbers(const std::string& s) {

}

void printTable(const std::vector<std::pair<std::string, std::string>>& table) {

}

void printKpu(Vkpu& kpu) {
  const std::vector<std::pair<std::string, std::string>> table = {
      {"bus",        convertToHex(kpu.kpu->bus)},
      {"tmp0",       convertToHex(kpu.kpu->tmp0_val)},
      {"tmp1",       convertToHex(kpu.kpu->tmp1_val)},
      {"opword",     convertToHex(kpu.kpu->opword_val)},
      {"mlu",        convertToHex(kpu.kpu->mlu_val)},
      {"opcode",     convertToHex(kpu.kpu->control->opcode)},
      {"microop",    convertToHex(kpu.kpu->control->microop_count)},
      {"ctrl data",  convertToHex(kpu.kpu->control->CTRL_DATA__out)},
      {"reg sel",    convertToHex(kpu.kpu->control->REG_SEL__out)},
      {"out",        convertToBinary<4>(kpu.kpu->control->control_out_plane)},
      {"in",         convertToBinary<3>(kpu.kpu->control->control_in_plane)},
      {"misc",       convertToBinary<1>(kpu.kpu->control->control_misc_plane)},
      {"mlu",        convertToBinary<4>(kpu.kpu->control->MLU_PLANE__out)},
      {"shifter",    convertToBinary<2>(kpu.kpu->control->SHIFTER_PLANE__out)},
      {"opcode sel", convertToHex(kpu.kpu->control->control_opcode_sel)},
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
    po::notify(vm);

    if (vm.count("help")) {
      std::cout << desc << '\n';
      return 0;
    }
  } catch (const po::error& ex) {
    std::cerr << ex.what() << '\n';
    return 1;
  }

  checkedChdir("verilog");

  Verilated::commandArgs(argc, argv);
  Verilated::randReset(2);
  Verilated::debug(2);

  Vkpu kpu;
  kpu.eval();  // Eval once to set up all signals (X => defined value).
  resetKpu(kpu);
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
