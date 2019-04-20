#include "memeroute/router.h"

namespace memeroute {

Router::Router(const Pcb& pcb) : pcb_(pcb) {}

std::vector<Shape> Router::route() {
  std::vector<Shape> paths;
  for (const auto& net : pcb_.nets) {
    auto& path = paths.emplace_back();
    path.type = Shape::Type::PATH;
    path.layer_id = "";  // TODO
    path.path.width = 500; // TODO
    for (const auto& pin_id : net.pin_ids) {
      const auto& component = pcb_.getComponentForPinId(pin_id);
      const auto& pin = pcb_.getPinForPinId(pin_id);
      path.path.points.push_back(component.localToWorld(pin.p));
    }
    break;
  }
  return paths;
}

}  // memeroute
