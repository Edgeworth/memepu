#include <utility>
#include <verilated.h>
#include <boost/program_options.hpp>

#include "gtest/gtest.h"
#include "verymeme/test_printer.h"

namespace po = boost::program_options;

int main(int argc, char* argv[]) {
  Verilated::commandArgs(argc, argv);
  Verilated::randReset(2);  // Randomize all bits.
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