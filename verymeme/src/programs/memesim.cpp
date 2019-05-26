#include <boost/program_options.hpp>
#include <iostream>

#include "verymeme/common.h"
#include "Vkpu.h"
#include "Vkpu_kpu.h"
#include "Vkpu_control_logic.h"
#include "Vkpu_register_file.h"
#include "Vkpu_sram__D5_W20.h"

namespace po = boost::program_options;

void resetKpu(Vkpu& kpu) {
  kpu.N_RST = 0;
  kpu.eval();
  kpu.N_RST = 1;
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
  // TODO: make /* verilator public */
  std::cout <<
      "BUS: " << std::hex << uint32_t(kpu.kpu->bus) << " TMP0: " << uint32_t(kpu.kpu->tmp0_val) <<
      " TMP1: " << uint32_t(kpu.kpu->tmp1_val) << " MLU output: " << uint32_t(kpu.kpu->mlu_val) <<
      " opcode: " << uint32_t(kpu.kpu->opcode) << " microop counter: " <<
      uint32_t(kpu.kpu->control->microop_count) << " in: " <<
      uint32_t(kpu.kpu->control->control_in_plane) << " out: " <<
      uint32_t(kpu.kpu->control->control_out_plane) << " misc: " <<
      uint32_t(kpu.kpu->control->control_misc_plane) << "\n";
  std::cout << convertToHex(kpu.kpu->regs->registers->mem, 8) << "\n";
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
    cmd = trim(cmd, "\\n ");
    if (cmd == "q") break;
    else clockKpu(kpu);
  }
}
