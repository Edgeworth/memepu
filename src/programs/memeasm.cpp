#include <boost/program_options.hpp>
#include <iostream>

#include "memeasm/assembler.h"
#include "verymeme/file.h"
#include "verymeme/string_util.h"

namespace po = boost::program_options;

int main(int argc, char* argv[]) {
  std::string model_filename;
  std::string input_filename;
  std::string output_filename;
  try {
    po::options_description desc{"Options"};
    desc.add_options()("help,h", "Help screen")("model,a", po::value<std::string>()->required())(
        "input,i", po::value<std::string>()->required())(
        "output,o", po::value<std::string>()->required());

    po::variables_map vm;
    po::store(po::command_line_parser(argc, argv).options(desc).run(), vm);

    if (vm.count("help")) {
      std::cout << desc << '\n';
      return 0;
    }

    po::notify(vm);

    model_filename = vm["model"].as<std::string>();
    input_filename = vm["input"].as<std::string>();
    output_filename = vm["output"].as<std::string>();
  } catch (const po::error& ex) {
    std::cerr << ex.what() << '\n';
    return 1;
  }

  memeasm::Assembler assembler(readFile(model_filename));
  std::vector<uint32_t> data = assembler.assemble(readFile(input_filename));
  writeFile(output_filename, hexdump(data));
}
