#include <boost/program_options.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <iostream>

namespace po = boost::program_options;
namespace pt = boost::property_tree;

int main(int argc, char* argv[]) {
  std::string filename;
  try {
    po::options_description desc{"Options"};
    desc.add_options()
        ("help,h", "Help screen")
        ("file,f", po::value<std::string>());

    po::variables_map vm;
    po::store(po::command_line_parser(argc, argv).options(desc).run(), vm);
    po::notify(vm);

    if (vm.count("help")) {
      std::cout << desc << '\n';
      return 0;
    }

    filename = vm["file"].as<std::string>();
  } catch (const po::error& ex) {
    std::cerr << ex.what() << '\n';
  }

  pt::ptree ptree;
  pt::read_xml(filename, ptree);
  std::cout << ptree.get<std::string>("verilator_xml.files.file.<xmlattr>.filename") << "\n";
}