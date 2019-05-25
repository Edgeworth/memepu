#include <boost/program_options.hpp>
#include <iostream>

#include "verymeme/common.h"
#include "Vkpu.h"

namespace po = boost::program_options;

void resetKpu(Vkpu& kpu) {
  kpu.N_RST = 0;
  kpu.eval();
}

void clockKpu(Vkpu& kpu) {
  kpu.CLK = 0;
  kpu.N_CLK = 1;
  kpu.eval();

  kpu.CLK = 1;
  kpu.N_CLK = 0;
  kpu.eval();
}

void printKpu(Vkpu& kpu) {
  std::cout << "BUS: " << std::hex << kpu.kpu__DOT__bus << " MLU output: " <<
    kpu.kpu__DOT__mlu_val << " opcode: " << kpu.kpu__DOT__opcode_reg__DOT__value <<
    " microcode control word: " << kpu.kpu__DOT__control__DOT__microcode__DOT__OUT_DATA__out__out0 << "\n";
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

  checked_chdir("verilog");

  Vkpu kpu;
  resetKpu(kpu);
  while (true) {
    std::string cmd;
    printKpu(kpu);
    std::cout << "> ";
    std::getline(std::cin, cmd);
    trim()
    if (!(std::cin >> cmd)) break;
    if (cmd == "q") break;
    else clockKpu(kpu);
    std::cout << "... clocked cpu\n";
  }
}
