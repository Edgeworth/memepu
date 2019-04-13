#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <boost/program_options.hpp>

#include "memeroute/parser.h"
#include "verymeme/common.h"

const sf::Color LIGHT_GREY(240, 240, 240);

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

  memeroute::parsePcb(readFile(dsn_filename));

  return 0;

  sf::RenderWindow window(sf::VideoMode(800, 600), "memeroute");
  window.setVerticalSyncEnabled(true);

  while (window.isOpen()) {
    sf::Event ev{};
    while (window.pollEvent(ev)) {
      if (ev.type == sf::Event::Closed)
        window.close();
    }

    window.clear(LIGHT_GREY);
    window.display();
  }
}
