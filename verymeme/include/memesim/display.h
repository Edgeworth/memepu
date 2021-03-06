#ifndef MEMESIM_DISPLAY_H
#define MEMESIM_DISPLAY_H

#include <SFML/Graphics.hpp>

#include "memesim/simulator.h"
#include "verymeme/concurrent_queue.h"

namespace memesim {

class Display {
public:
  explicit Display(Simulator* simulator);

  void run();

private:
  Simulator* simulator_;
  std::shared_ptr<ConcurrentQueue<Simulator::Response>> receiver_;

  std::unique_ptr<sf::RenderWindow> win_;
};

}  // namespace memesim

#endif  // MEMESIM_DISPLAY_H
