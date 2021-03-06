#ifndef MEMEROUTE_RENDERER_H
#define MEMEROUTE_RENDERER_H

#include <SFML/Graphics.hpp>

#include "memeroute/render_shapes.h"
#include "memeroute/router.h"
#include "memeroute/types.h"

namespace memeroute {

class Renderer {
public:
  explicit Renderer(const Pcb& pcb);

  void run();

private:
  // Rendering:
  std::unique_ptr<sf::RenderWindow> win_;
  DisplayList dl_;
  sf::Font font_;
  std::vector<sf::Text> labels_;

  // Screen coordinates are (-1, -1) to (1, 1).
  float scale_ = 1.0f;  // Converts from world to screen coords.
  sf::Vector2f translation_ = {};  // Translation in world coordinates.
  bool panning_ = false;
  sf::Vector2f pan_screen_loc_ = {};
  sf::FloatRect bounds_ = {};

  // Pcb:
  Pcb pcb_;
  Router router_;

  sf::Text createText(const std::string& str);
  sf::FloatRect addShapeToDisplayList(
      const Shape& shape, const sf::Transform& tf, const sf::Color& color, bool filled);
  sf::FloatRect addPadstackToDisplayList(const std::string& padstack_id, const sf::Transform& tf);
  sf::FloatRect addComponentToDisplayList(const Component& component, sf::Transform tf);
  void initialiseDrawingState();

  float getInitialScale() const;

  template <typename T>
  sf::Vector2f windowToScreen(const T& mouse) {
    return 2.f *
        sf::Vector2f(mouse.x / float(win_->getSize().x), mouse.y / float(win_->getSize().y)) -
        sf::Vector2f(1.0f, 1.0f);
  }

  template <typename T>
  sf::Vector2f windowToWorld(const T& mouse) {
    return 1.f / scale_ * windowToScreen(mouse) - translation_;
  }
};

}  // namespace memeroute

#endif  // MEMEROUTE_RENDERER_H
