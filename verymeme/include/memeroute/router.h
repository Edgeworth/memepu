#ifndef MEMEROUTE_ROUTER_H
#define MEMEROUTE_ROUTER_H

#include "memeroute/router_worker.h"
#include "memeroute/types.h"

namespace memeroute {

class Router {
public:
  explicit Router(Pcb pcb);

  RouterWorker::RoutingResult route();

private:
  Pcb pcb_;
};

}  // namespace memeroute

#endif  // MEMEROUTE_ROUTER_H
