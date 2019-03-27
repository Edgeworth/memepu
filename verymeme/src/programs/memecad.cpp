#include <boost/program_options.hpp>
#include <kernel/yosys.h>

#include "memecad/mapper.h"
#include "memecad/parser.h"
#include "memecad/yosys_module.h"

namespace po = boost::program_options;

int main(int argc, char* argv[]) {
  std::vector<std::string> verilog_filenames;
  std::string kicad_library_filename;
  std::string memecad_map_filename;
  try {
    po::options_description desc{"Options"};
    desc.add_options()
        ("help,h", "Help screen")
        ("files,f", po::value<std::vector<std::string>>()->required()->multitoken())
        ("memecad-map,k", po::value<std::string>()->required())
        ("chip-library,c", po::value<std::string>()->required());

    po::variables_map vm;
    po::store(po::command_line_parser(argc, argv).options(desc).run(), vm);
    po::notify(vm);

    if (vm.count("help")) {
      std::cout << desc << '\n';
      return 0;
    }

    verilog_filenames = vm["files"].as<std::vector<std::string>>();
    kicad_library_filename = vm["chip-library"].as<std::string>();
    memecad_map_filename = vm["memecad-map"].as<std::string>();
  } catch (const po::error& ex) {
    std::cerr << ex.what() << '\n';
    return 1;
  }

  Yosys::log_streams.push_back(&std::cout);
  Yosys::log_error_stderr = true;
  Yosys::yosys_banner();

  memecad::convertVerilogToKicadSchematics(memecad_map_filename, verilog_filenames,
      {kicad_library_filename});
}
