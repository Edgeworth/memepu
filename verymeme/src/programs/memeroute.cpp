#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <boost/program_options.hpp>

#include "memeroute/render_shapes.h"
#include "memeroute/parser.h"
#include "verymeme/common.h"

namespace po = boost::program_options;

namespace memeroute {

class DisplayList {
public:
  void draw(sf::RenderWindow& window) {
    for (const auto& array : arrays_)
      window.draw(array);
  }

  void add(const sf::VertexArray& array) {
    arrays_.push_back(array);
  }

private:
  std::vector<sf::VertexArray> arrays_;
};

class Renderer {
public:
  explicit Renderer(const Pcb& pcb) : pcb_(pcb) {}

  void run() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 4;
    win_ = std::make_unique<sf::RenderWindow>(sf::VideoMode(800, 800), "memeroute",
        sf::Style::Default, settings);
    win_->setVerticalSyncEnabled(true);
    win_->setFramerateLimit(60);  // TODO

    addPcbToDisplayList();

    sf::Vector2f mouse_cusor;
    while (win_->isOpen()) {
      sf::Event ev{};
      while (win_->pollEvent(ev)) {
        switch (ev.type) {
          case sf::Event::Closed:
            win_->close();
            break;
          case sf::Event::MouseWheelScrolled: {
            const auto& mouse = windowToWorld(ev.mouseWheelScroll);
            const float f = ev.mouseWheelScroll.delta > 0 ? SCALE_FACTOR : 1.f / SCALE_FACTOR;
            translation += (1.f / f - 1) * (mouse + translation);
            scale *= f;
            break;
          }
          case sf::Event::MouseButtonPressed:
            panning_ = true;
            pan_screen_loc_ = windowToScreen(ev.mouseButton);
            break;
          case sf::Event::MouseButtonReleased:
            panning_ = false;
            break;
          case sf::Event::MouseMoved:
            if (panning_) {
              const auto& mouse_screen_loc_ = windowToScreen(ev.mouseMove);
              translation += 1 / scale * (mouse_screen_loc_ - pan_screen_loc_);
              pan_screen_loc_ = mouse_screen_loc_;
            }
            mouse_cusor = windowToWorld(ev.mouseMove);
            break;
          default:
            break;
        }
      }

      win_->clear(LIGHT_GREY);
      sf::View view(sf::FloatRect(-1.f, -1.f, 2.f, 2.f));
      view.move(-translation);
      view.zoom(1.f / scale);
      win_->setView(view);
      dl_.draw(*win_);
      win_->draw(createCircle(500.f, true, mouse_cusor, sf::Color::Black));
      win_->display();
    }
  }

private:
  const sf::Color LIGHT_GREY = sf::Color(240, 240, 240);
  const float HSIZE = 50000.f;
  const float SCALE_FACTOR = 1.2f;
  const float PADDING = 1000.f;

  std::unique_ptr<sf::RenderWindow> win_;
  DisplayList dl_;
  Pcb pcb_;

  bool panning_ = false;
  sf::Vector2f pan_screen_loc_ = {};
  float scale = 1.f / (HSIZE * 2.0f);  // Converts from world to screen coords.
  sf::Vector2f translation = {};  // Translation in world coordinates.

  template<typename T>
  sf::Vector2f windowToScreen(const T& mouse) {
    return
        2.f * sf::Vector2f(mouse.x / float(win_->getSize().x), mouse.y / float(win_->getSize().y)) -
        sf::Vector2f(1.0f, 1.0f);
  }

  template<typename T>
  sf::Vector2f windowToWorld(const T& mouse) {
    return 1.f / scale * windowToScreen(mouse) - translation;
  }

  sf::FloatRect addShapeToDisplayList(const Shape& shape, const sf::Vector2f& offset) {
    const auto& arrays = createVertexArraysFromShape(shape, offset, sf::Color::Blue);
    for (const auto& array : arrays)
      dl_.add(array);
    return getVertexArraysBoundingBox(arrays);
  }

  sf::FloatRect addImageToDisplayList(const Image& image, const sf::Vector2f& offset) {
    sf::FloatRect bounds{};
    for (const auto& outline : image.outlines)
      bounds = floatRectUnion(addShapeToDisplayList(outline, offset), bounds);
    for (const auto& pin : image.pins) {
      auto iter = pcb_.padstacks.find(pin.padstack_id);
      for (const auto& shape : iter->second.shapes)
        bounds = floatRectUnion(
            addShapeToDisplayList(shape, pointToVector(pin.p) + offset), bounds);
    }
    return bounds;
  }

  void addPcbToDisplayList() {
    sf::Vector2f offset = {-HSIZE / 2.0f, -HSIZE / 2.0f};
    for (const auto& kv : pcb_.images) {
      const auto& image = kv.second;
      const auto& bounds = addImageToDisplayList(image, offset);
      dl_.add(createRect(bounds, {}, sf::Color::Red));
      offset.x += bounds.width + PADDING;
      if (offset.x > HSIZE / 2.0f) {
        offset.x = -HSIZE / 2.0f;
        offset.y += bounds.height + PADDING;
      }
    }
  }
};

}  // memeroute

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
