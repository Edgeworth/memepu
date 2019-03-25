#include <boost/program_options.hpp>
#include <kernel/yosys.h>

#include "memecad/mapper.h"
#include "memecad/parser.h"
#include "memecad/yosys_module.h"

namespace po = boost::program_options;

int main(int argc, char* argv[]) {
  std::string filename;
  std::string kicad_library_filename;
  std::string memecad_map_filename;
  try {
    po::options_description desc{"Options"};
    desc.add_options()
        ("help,h", "Help screen")
        ("file,f", po::value<std::string>()->required())
        ("memecad-map,k", po::value<std::string>()->required())
        ("chip-library,c", po::value<std::string>()->required());

    po::variables_map vm;
    po::store(po::command_line_parser(argc, argv).options(desc).run(), vm);
    po::notify(vm);

    if (vm.count("help")) {
      std::cout << desc << '\n';
      return 0;
    }

    filename = vm["file"].as<std::string>();
    kicad_library_filename = vm["chip-library"].as<std::string>();
    memecad_map_filename = vm["memecad-map"].as<std::string>();
  } catch (const po::error& ex) {
    std::cerr << ex.what() << '\n';
    return 1;
  }

  memecad::TestPass test_pass(memecad_map_filename, kicad_library_filename);

  Yosys::log_streams.push_back(&std::cout);
  Yosys::log_error_stderr = true;

  Yosys::yosys_setup();
  Yosys::yosys_banner();

  Yosys::run_pass(
      "read -sv ./verilog/two_a_plus_b.v ./verilog/full_adder.v ./verilog/chip7486.v ./verilog/chip7408.v ./verilog/chip7432.v");
  Yosys::run_pass("memecad");

  Yosys::yosys_shutdown();
}
