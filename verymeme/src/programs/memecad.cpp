#include <kernel/yosys.h>

#include <boost/program_options.hpp>

#include "memecad/parser.h"
#include "memecad/yosys_module.h"
#include "verymeme/file.h"

namespace po = boost::program_options;

int main(int argc, char* argv[]) {
  std::vector<std::string> verilog_filenames;
  std::vector<std::string> kicad_library_filenames;
  std::string memecad_map_filename;
  try {
    po::options_description desc{"Options"};
    desc.add_options()("help,h", "Help screen")(
        "files,f", po::value<std::vector<std::string>>()->required()->multitoken())(
        "memecad-map,k", po::value<std::string>()->required())(
        "chip-libraries,c", po::value<std::vector<std::string>>()->required()->multitoken());

    po::variables_map vm;
    po::store(po::command_line_parser(argc, argv).options(desc).run(), vm);

    if (vm.count("help")) {
      std::cout << desc << '\n';
      return 0;
    }

    po::notify(vm);

    verilog_filenames = vm["files"].as<std::vector<std::string>>();
    kicad_library_filenames = vm["chip-libraries"].as<std::vector<std::string>>();
    memecad_map_filename = vm["memecad-map"].as<std::string>();
  } catch (const po::error& ex) {
    std::cerr << ex.what() << '\n';
    return 1;
  }

  auto files = memecad::convertVerilogToKicadSchematics(
      memecad_map_filename, verilog_filenames, kicad_library_filenames);
  for (const auto& file : files) writeFile("test/" + file.filename, file.contents);
  printf("Finished writing %d files\n", int(files.size()));
}
