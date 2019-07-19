#include <set>

#include "memeroute/types.h"
#include "verymeme/geom.h"
#include "verymeme/util.h"
#include "verymeme/string_util.h"

namespace memeroute {

namespace {

const std::string SIDE_MAPPING[] = {"front", "back"};

Point transformPoint(const Point& p, Side side, const Point& translation, int rotation) {
  Point world = p;
  if (side == Side::BACK)
    world = -world;
  switch (rotation) {
    case 0:
      break;
    case 90:
      world = {-world.y, world.x};
      break;
    case 180:
      world = {-world.x, -world.y};
      break;
    case 270:
      world = {world.y, -world.x};
      break;
    default:
      verify_expr(false, "only support axis aligned rotations, not '%d'", rotation);
  }
  return world + translation;
}

Shape transformShape(Shape s, Side side, const Point& translation, int rotation) {
  switch (s.type) {
    case Shape::Type::PATH:
      for (auto& p : s.path.points)
        p = transformPoint(p, side, translation, rotation);
      break;
    case Shape::Type::CIRCLE:
      s.circle.p = transformPoint(s.circle.p, side, translation, rotation);
      break;
    case Shape::Type::RECT: {
      const Point top_left = transformPoint(s.rect.origin(), side, translation, rotation);
      const Point bottom_right = transformPoint(s.rect.bottom_right(), side, translation, rotation);
      s.rect = Rect::enclosing(top_left, bottom_right);
      break;
    }
  }
  return s;
}

}  // namespace

std::ostream& operator<<(std::ostream& str, const Side& o) {
  return outputEnum(str, o, SIDE_MAPPING);
}

std::istream& operator>>(std::istream& str, Side& o) {
  return inputEnum(str, o, SIDE_MAPPING);
}

bool Net::PinId::operator<(const Net::PinId& o) const {
  return std::tie(component_id, pin_id) < std::tie(o.component_id, o.pin_id);
}

std::string Net::PinId::toString() const {
  return component_id + "-" + pin_id;
}

Rect Shape::getBoundingBox() const {
  switch (type) {
    case Type::PATH: {
      Rect bounds = {};
      for (const auto& point : path.points) {
        // Paths with zero width are treated as having a small non-zero width, so min.
        const int radius_ceil = std::max(1, path.width / 2 + path.width % 2);
        const Rect r = {point.x - radius_ceil, point.y - radius_ceil, point.x + radius_ceil,
            point.y + radius_ceil};
        bounds.unionRect(r);
      }
      return bounds;
    }
    case Type::CIRCLE: {
      const int radius_ceil = circle.diameter / 2 + circle.diameter % 2;
      const Point radius = {radius_ceil, radius_ceil};
      return Rect::enclosing(circle.p - radius, circle.p + radius);
    }
    case Type::RECT:
      return rect;
  }
  verify_expr(false, "BUG");
  return {};
}

Point Pin::toParentCoord(const Point& local) const {
  return local + p;
}

Shape Pin::toParentCoord(const Shape& local) const {
  return transformShape(local, Side::FRONT, p, 0 /* rotation */);
}

Point Component::toParentCoord(const Point& local) const {
  return transformPoint(local, side, p, rotation);
}

Shape Component::toParentCoord(const Shape& local) const {
  return transformShape(local, side, p, rotation);
}

void Pcb::verifyAndSetup() {
  verify_expr(padstacks.count(via_padstack_id), "via type '%s' padstack does not exist",
      via_padstack_id.c_str());

  for (const auto& kv : images) {
    const auto&[name, image] = kv;
    for (const auto& kv2 : image.pins) {
      verify_expr(padstacks.count(kv2.second.padstack_id) > 0, "missing padstack '%s'",
          kv2.second.padstack_id.c_str());
    }
  }
  for (const auto& kv : components) {
    verify_expr(images.count(kv.second.image_id) > 0, "missing image '%s'",
        kv.second.image_id.c_str());
  }
  std::set<Net::PinId> pin_ids;
  for (const auto& kv : nets) {
    for (const auto& pin_id : kv.second.pin_ids) {
      getPinForPinId(pin_id);  // Make sure the component and pin exists.

      verify_expr(pin_ids.count(pin_id) == 0, "pin '%s' in multiple nets",
          pin_id.toString().c_str());
      pin_ids.insert(pin_id);
    }
  }

  for (const auto& kv : padstacks)
    for (const auto& shape : kv.second.shapes)
      verify_expr(shape.layer_id != -1,
          "padstack shapes must have specified layer id since they aren't associated with a component");

  // Generate pin id to net map.
  for (const auto& kv : nets)
    for (const auto& pin_id : kv.second.pin_ids)
      pin_id_to_net_[pin_id] = kv.second;
}

const Net& Pcb::getNet(const std::string& net_name) const {
  auto iter = nets.find(net_name);
  verify_expr(iter != nets.end(), "unknown net '%s'", net_name.c_str());
  return iter->second;
}

const Net* Pcb::getNetForPinId(const Net::PinId& pin_id) const {
  auto iter = pin_id_to_net_.find(pin_id);
  if (iter == pin_id_to_net_.end()) return nullptr;
  return &iter->second;
}

const Component& Pcb::getComponentForPinId(const Net::PinId& pin_id) const {
  auto iter = components.find(pin_id.component_id);
  verify_expr(iter != components.end(), "net to unknown component '%s",
      pin_id.component_id.c_str());
  return iter->second;
}

const Pin& Pcb::getPinForPinId(const Net::PinId& pin_id) const {
  const auto& component = getComponentForPinId(pin_id);
  auto image_iter = images.find(component.image_id);
  verify_expr(image_iter != images.end(), "unknown image '%s'", component.image_id.c_str());
  auto pin_iter = image_iter->second.pins.find(pin_id.pin_id);
  verify_expr(pin_iter != image_iter->second.pins.end(), "unknown pin '%s'",
      pin_id.toString().c_str());
  return pin_iter->second;
}

int Pcb::getLayer(Side side) const {
  const std::string layer_name = side == Side::FRONT ? "F.Cu" : "B.Cu";
  auto iter = layers.find(layer_name);
  verify_expr(iter != layers.end(), "must contain front and back copper layers");
  return iter->second;
}

int Pcb::getLayer(const Component& component, const Shape& shape) const {
  return shape.layer_id != -1 ? shape.layer_id : getLayer(component.side);
}

}  // memeroute
