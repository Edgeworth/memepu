#include "memesim/display.h"

namespace memesim {

namespace {

}  // namespace

Display::Display(Simulator* simulator) : simulator_(simulator), vga_state_receiver_(
    new ConcurrentQueue<Simulator::VgaStateMessage>()) {}


void Display::run() {
  sf::ContextSettings settings;
  settings.antialiasingLevel = 0;
  win_ = std::make_unique<sf::RenderWindow>(sf::VideoMode(1200, 1200), "memesim",
      sf::Style::Default, settings);
  win_->setVerticalSyncEnabled(true);
  win_->setFramerateLimit(30);

  sf::Texture tex;
  tex.create(Simulator::VGA_WIDTH, Simulator::VGA_HEIGHT);

  sf::Image img;
  img.create(Simulator::VGA_WIDTH, Simulator::VGA_HEIGHT);

  while (win_->isOpen()) {
    win_->clear(sf::Color::Black);

    simulator_->scheduleCommand(
        {Simulator::Command::Type::GET_VGA_STATE, nullptr, vga_state_receiver_});

    const auto& state = vga_state_receiver_->yield();
    for (int r = 0; r < Simulator::VGA_HEIGHT; ++r) {
      for (int c = 0; c < Simulator::VGA_WIDTH; ++c) {
        uint8_t val = state.pixels[r * Simulator::VGA_WIDTH + c];
        auto col = sf::Color((val >> 5u) * 36, ((val & 0x1cu) >> 2u) * 36, (val & 0x3u) * 63);
        img.setPixel(c, r, col);
      }
    }
    tex.loadFromImage(img);

    sf::Sprite sprite(tex);
    sprite.setScale(
        win_->getSize().x / float(Simulator::VGA_WIDTH),
        win_->getSize().y / float(Simulator::VGA_HEIGHT));
    win_->draw(sprite);
    win_->display();

    sf::Event ev{};
    while (win_->pollEvent(ev)) {
      switch (ev.type) {
        case sf::Event::Closed:
          win_->close();
          break;
        default:
          break;
      }
    }
  }
}

}  // memesim
