#include <boost/program_options.hpp>
#include <iostream>

#include "verymeme/common.h"
#include "memeware/microcode.h"

namespace po = boost::program_options;

int main(int argc, char* argv[]) {
  std::string output;
  try {
    po::options_description desc{"Options"};
    desc.add_options()
        ("help,h", "Help screen")
        ("output_path,o", po::value<std::string>()->required());

    po::variables_map vm;
    po::store(po::command_line_parser(argc, argv).options(desc).run(), vm);
    po::notify(vm);

    if (vm.count("help")) {
      std::cout << desc << '\n';
      return 0;
    }

    output = vm["output_path"].as<std::string>();
  } catch (const po::error& ex) {
    std::cerr << ex.what() << '\n';
    return 1;
  }

  writeFile(output + "/mlu_slice.hex", convertToHex(memeware::generateMluSliceFirmware()));
  writeFile(output + "/mlu_lookahead.hex", convertToHex(memeware::generateMluLookaheadFirmware()));
  writeFile(output + "/microcode.hex", convertToHex(memeware::generateMicrocodeFirmware()));
}
