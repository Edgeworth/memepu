#include <boost/program_options.hpp>
#include <iostream>

#include "memeware/microcode.h"
#include "verymeme/file.h"
#include "verymeme/string_util.h"

namespace po = boost::program_options;

int main(int argc, char* argv[]) {
  std::string output;
  try {
    po::options_description desc{"Options"};
    desc.add_options()("help,h", "Help screen")(
        "output_path,o", po::value<std::string>()->required());

    po::variables_map vm;
    po::store(po::command_line_parser(argc, argv).options(desc).run(), vm);

    if (vm.count("help")) {
      std::cout << desc << '\n';
      return 0;
    }

    po::notify(vm);

    output = vm["output_path"].as<std::string>();
  } catch (const po::error& ex) {
    std::cerr << ex.what() << '\n';
    return 1;
  }

  writeFile(output + "/mlu_slice.hex", hexdump(memeware::generateMluSliceFirmware()));
  writeFile(output + "/mlu_lookahead.hex", hexdump(memeware::generateMluLookaheadFirmware()));
  writeFile(output + "/microcode.hex", hexdump(memeware::generateMicrocodeFirmware()));
  writeFile(output + "/ksm_model.json", memeware::generateMemeasmModel());
}
