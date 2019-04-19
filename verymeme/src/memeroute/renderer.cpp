#include "memeroute/renderer.h"

namespace memeroute {

namespace {

const sf::Color PRIMARY_COLOR[5] = {
    sf::Color(20, 55, 173),
    sf::Color(89, 113, 193),
    sf::Color(56, 84, 178),
    sf::Color(14, 42, 133),
    sf::Color(9, 31, 105),
};

const sf::Color SECONDARY_COLOR[5] = {
    sf::Color(255, 44, 0),
    sf::Color(255, 126, 99),
    sf::Color(255, 91, 57),
    sf::Color(197, 34, 0),
    sf::Color(155, 27, 0),
};

const sf::Color LIGHT_GREY = sf::Color(240, 240, 240);
const float SCALE_FACTOR = 1.2f;
const float MOUSE_SIZE = 0.01f;
const float TEXT_SIZE = 5000.f;
const float MIN_SCALE_FACTOR = 0.5f;
const float MAX_SCALE_FACTOR = 20.f;

}  // namespace

Renderer::Renderer(const Pcb& pcb) : pcb_(pcb) {
  initialiseDrawingState();
}

void Renderer::run() {
  sf::ContextSettings settings;
  settings.antialiasingLevel = 4;
  win_ = std::make_unique<sf::RenderWindow>(sf::VideoMode(1200, 1200), "memeroute",
      sf::Style::Default, settings);
  win_->setVerticalSyncEnabled(true);

  sf::Vector2f mouse_cursor;
  while (win_->isOpen()) {
    win_->clear(LIGHT_GREY);
    sf::View view(
        sf::FloatRect(-1.f, -1.f, 2.f * win_->getSize().x / float(win_->getSize().y), 2.f));
    view.move(-translation_);
    view.zoom(1.f / scale_);
    win_->setView(view);
    dl_.draw(*win_);
    for (const auto& text : labels_)
      win_->draw(text);
    sf::Transform mouse_tf;
    mouse_tf.translate(mouse_cursor);
    win_->draw(createCircle(MOUSE_SIZE / scale_, true, mouse_tf, sf::Color::Black));
    win_->display();

    sf::Event ev{};

    win_->waitEvent(ev);
    do {
      switch (ev.type) {
        case sf::Event::Closed:
          win_->close();
          break;
        case sf::Event::MouseWheelScrolled: {
          const auto& mouse = windowToWorld(ev.mouseWheelScroll);
          const float f = clamp(getInitialScale() * MIN_SCALE_FACTOR / scale_,
              getInitialScale() * MAX_SCALE_FACTOR / scale_,
              ev.mouseWheelScroll.delta > 0 ? SCALE_FACTOR : 1.f / SCALE_FACTOR);
          translation_ += (1.f / f - 1) * (mouse + translation_);
          scale_ *= f;
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
            const auto& mouse_screen_loc = windowToScreen(ev.mouseMove);
            translation_ += 1.f / scale_ * (mouse_screen_loc - pan_screen_loc_);
            pan_screen_loc_ = mouse_screen_loc;
          }
          mouse_cursor = windowToWorld(ev.mouseMove);
          break;
        default:
          break;
      }
    } while (win_->pollEvent(ev));
  }
}

sf::Text Renderer::createText(const std::string& str) {
  sf::Text text;
  text.setFont(font_);
  text.setString(str);
  text.setCharacterSize(96);
  text.setOutlineThickness(4.f);
  text.setOutlineColor(sf::Color::White);
  text.setFillColor(sf::Color::Black);
  return text;
}

sf::FloatRect Renderer::addShapeToDisplayList(const Shape& shape, const sf::Transform& tf) {
  const auto& arrays = createVertexArraysFromShape(shape, tf, PRIMARY_COLOR[0]);
  for (const auto& array : arrays)
    dl_.add(array);
  return getVertexArraysBoundingBox(arrays);
}

sf::FloatRect Renderer::addImageToDisplayList(const Image& image, const sf::Transform& tf) {
  sf::FloatRect bounds{};
  for (const auto& outline : image.outlines)
    bounds = floatRectUnion(addShapeToDisplayList(outline, tf), bounds);
  for (const auto& pin : image.pins) {
    auto iter = pcb_.padstacks.find(pin.padstack_id);
    for (const auto& shape : iter->second.shapes) {
      sf::Transform new_tf = tf;
      new_tf.translate(pointToVector(pin.p));
      bounds = floatRectUnion(addShapeToDisplayList(shape, new_tf), bounds);
    }
  }
  return bounds;
}

void Renderer::initialiseDrawingState() {
  verify_expr(font_.loadFromFile("assets/Roboto.ttf"), "could not load font");

  for (const auto& component : pcb_.components) {
    const auto& image = pcb_.images[component.image_id];
    // TODO: rotation
    sf::Transform tf;
    // Flip y scale to correct for viewport.
    tf.scale(1.f, -1.f);
    tf.translate(pointToVector(component.p));
    tf.rotate(component.rotation);
    if (component.side == Side::BACK)
      tf.scale(-1.f, -1.f);  // TODO is it correct to flip both axes?
    const auto& image_bounds = addImageToDisplayList(image, tf);
    dl_.add(createRect(image_bounds, {}, SECONDARY_COLOR[0]));
    bounds_ = floatRectUnion(image_bounds, bounds_);

    // Todo text scale depends on bounds.
    auto& text = labels_.emplace_back(createText(component.part_number));
    text.move(tf * sf::Vector2f(0, 0));
  }

  scale_ = getInitialScale();
  translation_ = {-bounds_.left - 1.f / scale_, -bounds_.top - 1.f / scale_};

  const float text_scale = 1.f / (TEXT_SIZE * getInitialScale());
  printf("Initial scale: %f %f %f\n", getInitialScale(), 1.f / getInitialScale(), text_scale);
  for (auto& label : labels_)
    label.setScale(text_scale, text_scale);
}

float Renderer::getInitialScale() {
  return 1.5f / std::max(bounds_.width, bounds_.height);
}

}  // memeroute
