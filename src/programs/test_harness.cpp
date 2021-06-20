#include <verilated.h>

#include <boost/program_options.hpp>

#include "gtest/gtest.h"

namespace po = boost::program_options;

int main(int argc, char* argv[]) {
  Verilated::commandArgs(argc, argv);
  Verilated::randReset(2);
  Verilated::debug(2);

  ::testing::InitGoogleTest(&argc, argv);

  try {
    po::options_description desc{"Options"};
    desc.add_options()("help,h", "Help screen");

    po::variables_map vm;
    po::store(po::command_line_parser(argc, argv).options(desc).allow_unregistered().run(), vm);

    if (vm.count("help")) {
      std::cout << desc << '\n';
      return 0;
    }

    po::notify(vm);
  } catch (const po::error& ex) { std::cerr << ex.what() << '\n'; }

  return RUN_ALL_TESTS();
}
