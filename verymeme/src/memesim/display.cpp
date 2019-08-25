#include "memesim/display.h"

#include "verymeme/concurrent_queue.h"

namespace memesim {

using memeware::VGA_HEIGHT;
using memeware::VGA_WIDTH;

Display::Display(Simulator* simulator)
    : simulator_(simulator), receiver_(new ConcurrentQueue<Simulator::Response>()) {}

void Display::run() {
  sf::ContextSettings settings;
  settings.antialiasingLevel = 0;
  win_ = std::make_unique<sf::RenderWindow>(
      sf::VideoMode(VGA_WIDTH * 4, VGA_HEIGHT * 4), "memesim", sf::Style::Default, settings);
  win_->setVerticalSyncEnabled(true);
  win_->setFramerateLimit(30);

  sf::Texture tex;
  tex.create(VGA_WIDTH, VGA_HEIGHT);

  sf::Image img;
  img.create(VGA_WIDTH, VGA_HEIGHT);

  while (win_->isOpen()) {
    win_->clear(sf::Color::Black);

    simulator_->scheduleCommand({Simulator::Cmd::Type::GET_VGA_STATE, {}, receiver_});

    const auto& state = std::get<Simulator::VgaStateMessage>(receiver_->yield());
    for (int r = 0; r < VGA_HEIGHT; ++r) {
      for (int c = 0; c < VGA_WIDTH; ++c) {
        uint8_t val = state.pixels[r * memeware::VGA_WIDTH + c];
        auto col = sf::Color(
            uint8_t(val >> 5u) * 36, uint8_t((val & 0x1cu) >> 2u) * 36, uint8_t(val & 0x3u) * 63);
        img.setPixel(c, r, col);
      }
    }
    tex.loadFromImage(img);

    sf::Sprite sprite(tex);
    sprite.setScale(win_->getSize().x / float(VGA_WIDTH), win_->getSize().y / float(VGA_HEIGHT));
    win_->draw(sprite);
    win_->display();

    sf::Event ev{};
    while (win_->pollEvent(ev)) {
      switch (ev.type) {
      case sf::Event::Closed:
        simulator_->scheduleCommand({Simulator::Cmd::Type::QUIT, {}, receiver_});
        win_->close();
        break;
      case sf::Event::MouseMoved: {
        const int x = ev.mouseMove.x * VGA_WIDTH / win_->getSize().x;
        const int y = ev.mouseMove.y * VGA_HEIGHT / win_->getSize().y;
        simulator_->scheduleCommand({Simulator::Cmd::Type::SET_MOUSE, {x, y}, receiver_});
        break;
      }
      default: break;
      }
    }
  }
}

}  // namespace memesim
