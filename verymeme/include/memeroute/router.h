#ifndef MEMEROUTE_ROUTER_H
#define MEMEROUTE_ROUTER_H

#include "memeroute/types.h"
#include "memeroute/router_worker.h"

namespace memeroute {

class Router {
public:
  explicit Router(Pcb pcb);

  RouterWorker::RoutingResult route();

private:
  Pcb pcb_;
};

}  // memeroute

#endif  // MEMEROUTE_ROUTER_H
