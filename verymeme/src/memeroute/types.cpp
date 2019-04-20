#include <set>

#include "memeroute/types.h"

namespace memeroute {

namespace {

const std::string SIDE_MAPPING[] = {"front", "back"};

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

Point Component::localToWorld(const Point& local) const {
  Point world = local;
  if (side == Side::BACK)
    world = -world;
  switch (rotation) {
    case 0: break;
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
  return world + p;
}

void Pcb::verifyAndSetup() {
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
  for (const auto& net : nets) {
    for (const auto& pin_id : net.pin_ids) {
      getPinForPinId(pin_id);  // Make sure the component and pin exists.

      verify_expr(pin_ids.count(pin_id) == 0, "pin '%s' in multiple nets",
          pin_id.toString().c_str());
      pin_ids.insert(pin_id);
    }
  }

  // Generate pin id to net map.
  for (const auto& net : nets)
    for (const auto& pin_id : net.pin_ids)
      pin_id_to_net_[pin_id] = net;
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

}  // memeroute
