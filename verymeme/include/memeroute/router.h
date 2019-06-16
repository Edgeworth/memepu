#ifndef VERYMEME_MEMEROUTE_ROUTER_H
#define VERYMEME_MEMEROUTE_ROUTER_H

#include "verymeme/common.h"
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

#endif  // VERYMEME_MEMEROUTE_ROUTER_H
