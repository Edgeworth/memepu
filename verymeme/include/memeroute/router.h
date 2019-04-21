#ifndef VERYMEME_MEMEROUTE_ROUTER_H
#define VERYMEME_MEMEROUTE_ROUTER_H

#include "verymeme/common.h"
#include "memeroute/types.h"

namespace memeroute {

class Router {
public:
  explicit Router(const Pcb& pcb);

  std::vector<Shape> route();

private:
  Pcb pcb_;

};

}  // memeroute

#endif  // VERYMEME_MEMEROUTE_ROUTER_H
