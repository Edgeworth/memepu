#include <utility>
#include <verilated.h>
#include <boost/program_options.hpp>

#include "gtest/gtest.h"
#include "verymeme/test_printer.h"

namespace po = boost::program_options;

int main(int argc, char* argv[]) {
  Verilated::commandArgs(argc, argv);
  // Set all initial bits to zero. Do this instead of random reset because of what looks like a bug
  // in verilator. Creating e.g. wire [8:0] carrys; assign carrys[0] = C_IN; assign C = carrys[8];
  // some_output(.OUT(carrys[8:1])) makes verilator produce assignment to carrys of the form:
  // carrys = old_carrys & 0xFE | C_IN; carrys = (OUT & 0xFE) | carrys; which keeps random bits
  // around from the beginning.
  Verilated::randReset(0);
  Verilated::debug(2);

  ::testing::InitGoogleTest(&argc, argv);

  bool print_individual_tests = false;
  try {
    po::options_description desc{"Options"};
    desc.add_options()
        ("help,h", "Help screen")
        ("print_individual_tests,t", po::bool_switch()->default_value(false),
            "Print individual tests");

    po::variables_map vm;
    po::store(po::command_line_parser(argc, argv).options(desc).allow_unregistered().run(), vm);
    po::notify(vm);

    if (vm.count("help")) {
      std::cout << desc << '\n';
      return 0;
    }

    print_individual_tests = vm["print_individual_tests"].as<bool>();
  } catch (const po::error& ex) {
    std::cerr << ex.what() << '\n';
  }

  ::testing::TestEventListeners& listeners =
      ::testing::UnitTest::GetInstance()->listeners();
  delete listeners.Release(listeners.default_result_printer());
  listeners.Append(new TestPrinter(print_individual_tests));

  return RUN_ALL_TESTS();
}
