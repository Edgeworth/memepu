#include <iostream>
#include <boost/program_options.hpp>

#include "memeroute/renderer.h"
#include "memeroute/parser.h"

namespace po = boost::program_options;

int main(int argc, char* argv[]) {
  std::string dsn_filename;
  try {
    po::options_description desc{"Options"};
    desc.add_options()
        ("help,h", "Help screen")
        ("dsn-input,i", po::value<std::string>()->required());

    po::variables_map vm;
    po::store(po::command_line_parser(argc, argv).options(desc).run(), vm);
    po::notify(vm);

    if (vm.count("help")) {
      std::cout << desc << '\n';
      return 0;
    }
    dsn_filename = vm["dsn-input"].as<std::string>();
  } catch (const po::error& ex) {
    std::cerr << ex.what() << '\n';
    return 1;
  }

  memeroute::Renderer renderer(memeroute::parsePcb(readFile(dsn_filename)));
  renderer.run();
}
