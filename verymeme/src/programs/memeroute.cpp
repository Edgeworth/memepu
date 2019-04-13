#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "verymeme/common.h"

const sf::Color LIGHT_GREY(240, 240, 240);

int main() {
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
