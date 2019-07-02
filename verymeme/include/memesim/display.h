#ifndef VERYMEME_DISPLAY_H
#define VERYMEME_DISPLAY_H

#include "verymeme/common.h"

#include <SFML/Graphics.hpp>

#include "memesim/simulator.h"

namespace memesim {

class Display {
public:
  explicit Display(Simulator* simulator);

  void run();

private:
  Simulator* simulator_;
  std::shared_ptr<ConcurrentQueue<Simulator::VgaStateMessage>> vga_state_receiver_;

  std::unique_ptr<sf::RenderWindow> win_;
};

}  // memesim

#endif  // VERYMEME_DISPLAY_H