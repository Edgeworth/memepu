#include <verilated.h>

#include <boost/program_options.hpp>
#include <iostream>
#include <numeric>
#include <thread>

#include "memesim/cli.h"
#include "memesim/display.h"
#include "memesim/simulator.h"
#include "verymeme/file.h"

namespace po = boost::program_options;

int main(int argc, char* argv[]) {
  std::string initial_cmd;
  try {
    po::options_description desc{"Options"};
    desc.add_options()("help,h", "Help screen")(
        "initial-cmd,c", po::value<std::vector<std::string>>()->multitoken(), "Initial command");

    po::positional_options_description p;
    p.add("initial-cmd", -1);

    po::variables_map vm;
    po::store(po::command_line_parser(argc, argv).options(desc).positional(p).run(), vm);

    if (vm.count("help")) {
      std::cout << desc << '\n';
      return 0;
    }

    po::notify(vm);
    if (vm.count("initial-cmd")) {
      for (const auto& s : vm["initial-cmd"].as<std::vector<std::string>>()) initial_cmd += s + " ";
    }
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

  cmd.run(initial_cmd);

  display_thread.join();
  simulator_thread.join();
}
