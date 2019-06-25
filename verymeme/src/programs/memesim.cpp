#include <boost/program_options.hpp>
#include <iostream>
#include <verilated.h>
#include <thread>

#include "verymeme/common.h"
#include "verymeme/file.h"
#include "memesim/simulator.h"
#include "memesim/cli.h"
#include "memesim/display.h"

namespace po = boost::program_options;


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

  memesim::Simulator simulator;
  memesim::CommandLine cmd(&simulator);
  memesim::Display display(&simulator);

  std::thread simulator_thread(&memesim::Simulator::run, &simulator);
  std::thread display_thread(&memesim::Display::run, &display);

  cmd.run();

  display_thread.join();
  simulator_thread.join();
}
