#include "memeroute/renderer.h"

#include "verymeme/geom.h"
#include "verymeme/util.h"

namespace memeroute {

namespace {

const sf::Color PRIMARY_COLOR[5] = {sf::Color(20, 55, 173, 150), sf::Color(89, 113, 193, 150),
    sf::Color(56, 84, 178, 150), sf::Color(14, 42, 133, 150), sf::Color(9, 31, 105, 150)};

const sf::Color SECONDARY_COLOR[5] = {sf::Color(255, 44, 0, 150), sf::Color(255, 126, 99, 150),
    sf::Color(255, 91, 57, 150), sf::Color(197, 34, 0, 150), sf::Color(155, 27, 0, 150)};

const sf::Color LIGHT_GREY = sf::Color(240, 240, 240);
const float SCALE_FACTOR = 1.2f;
const float MOUSE_SIZE = 0.01f;
const float TEXT_SIZE = 5000.f;
const float MIN_SCALE_FACTOR = 0.5f;
const float MAX_SCALE_FACTOR = 20.f;

sf::Color layerToColor(int layer, int idx) {
  if (layer == -1) return sf::Color::Black;
  return layer ? SECONDARY_COLOR[idx] : PRIMARY_COLOR[idx];
}

}  // namespace

Renderer::Renderer(const Pcb& pcb) : pcb_(pcb), router_(pcb) { initialiseDrawingState(); }

void Renderer::run() {
  sf::ContextSettings settings;
  settings.antialiasingLevel = 4;
  win_ = std::make_unique<sf::RenderWindow>(
      sf::VideoMode(1200, 1200), "memeroute", sf::Style::Default, settings);
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
    for (const auto& text : labels_) win_->draw(text);
    sf::Transform mouse_tf;
    mouse_tf.translate(mouse_cursor);
    win_->draw(createCircle(MOUSE_SIZE / scale_, mouse_tf, sf::Color::Black, true /* filled */));
    win_->display();

    sf::Event ev{};

    win_->waitEvent(ev);
    do {
      switch (ev.type) {
      case sf::Event::Closed: win_->close(); break;
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
      case sf::Event::MouseButtonReleased: panning_ = false; break;
      case sf::Event::MouseMoved:
        if (panning_) {
          const auto& mouse_screen_loc = windowToScreen(ev.mouseMove);
          translation_ += 1.f / scale_ * (mouse_screen_loc - pan_screen_loc_);
          pan_screen_loc_ = mouse_screen_loc;
        }
        mouse_cursor = windowToWorld(ev.mouseMove);
        break;
      default: break;
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

// Returns the bounds in world coordinates (no need to transform).
sf::FloatRect Renderer::addShapeToDisplayList(
    const Shape& shape, const sf::Transform& tf, const sf::Color& color, bool filled) {
  const auto& arrays = createVertexArraysFromShape(shape, tf, color, filled);
  for (const auto& array : arrays) dl_.add(array);
  return getVertexArraysBoundingBox(arrays);
}

sf::FloatRect Renderer::addPadstackToDisplayList(
    const std::string& padstack_id, const sf::Transform& tf) {
  sf::FloatRect bounds = {};
  auto padstack_iter = pcb_.padstacks.find(padstack_id);
  for (const auto& shape : padstack_iter->second.shapes)
    bounds = floatRectUnion(
        addShapeToDisplayList(shape, tf, layerToColor(shape.layer_id, 1), true /* filled */),
        bounds);
  return bounds;
}

sf::FloatRect Renderer::addComponentToDisplayList(const Component& component, sf::Transform tf) {
  tf.translate(pointToVector(component.p));
  tf.rotate(float(component.rotation));
  if (component.side == Side::BACK)
    tf.scale(-1.f, -1.f);  // TODO(check): is it correct to flip both axes?

  sf::FloatRect bounds{};
  const auto& image = pcb_.images[component.image_id];

  for (const auto& outline : image.outlines)
    bounds =
        floatRectUnion(addShapeToDisplayList(outline, tf,
                           layerToColor(pcb_.getLayer(component, outline), 0), false /* filled */),
            bounds);

  for (const auto& kv : image.pins) {
    const auto& pin = kv.second;
    sf::Transform pin_tf = tf;
    pin_tf.translate(pointToVector(pin.p));

    const auto* net = pcb_.getNetForPinId(Net::PinId{component.name, pin.pin_id});
    if (net) {
      auto& net_text = labels_.emplace_back(createText(net->name));
      net_text.move(pin_tf * sf::Vector2f(0, 0));
      net_text.scale(0.25f, 0.25f);
    }

    bounds = floatRectUnion(bounds, addPadstackToDisplayList(pin.padstack_id, pin_tf));
  }

  // Add keepouts.
  for (const auto& keepout : image.keepouts)
    bounds = floatRectUnion(
        addShapeToDisplayList(keepout, tf, SECONDARY_COLOR[2], true /* filled */), bounds);

  dl_.add(createRect(bounds, {}, SECONDARY_COLOR[0], false /* filled */));

  // TODO(improvement): text scale depends on bounds.
  auto& text = labels_.emplace_back(createText(component.part_number));
  text.move(tf * sf::Vector2f(0, 0));

  return bounds;
}

void Renderer::initialiseDrawingState() {
  verify_expr(font_.loadFromFile("assets/Roboto-Bold.ttf"), "could not load font");

  sf::Transform tf;
  tf.scale(1.f, -1.f);  // Flip y scale to correct for viewport.
  // Compute bounds from components.
  for (const auto& kv : pcb_.components)
    bounds_ = floatRectUnion(addComponentToDisplayList(kv.second, tf), bounds_);

  // Set-up initial viewport from bounds.
  scale_ = getInitialScale();
  translation_ = {-bounds_.left - 1.f / scale_, -bounds_.top - 1.f / scale_};

  // Decide how big text should be.
  const float text_scale = 1.f / (TEXT_SIZE * getInitialScale());
  for (auto& label : labels_) label.scale(text_scale, text_scale);

  // Add routed paths.
  auto result = router_.route();
  for (const auto& path : result.traces)
    addShapeToDisplayList(path, tf, layerToColor(path.layer_id, 2), false /* filled */);
  // Add routed vias:
  for (const auto& via_position : result.vias) {
    sf::Transform via_tf = tf;
    via_tf.translate(pointToVector(via_position));
    addPadstackToDisplayList(pcb_.via_padstack_id, via_tf);
  }
  addShapeToDisplayList(pcb_.boundary, tf, SECONDARY_COLOR[1], false /* filled */);
}

float Renderer::getInitialScale() const { return 1.5f / std::max(bounds_.width, bounds_.height); }

}  // namespace memeroute
