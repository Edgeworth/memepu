#ifndef VERYMEME_MEMEROUTE_ROUTER_H
#define VERYMEME_MEMEROUTE_ROUTER_H

#include "verymeme/common.h"
#include "memeroute/types.h"

namespace memeroute {

class Router {
public:
  explicit Router(const Pcb& pcb);

  std::vector<Shape> route();

  struct State {
    Point p;
    int layer;

    bool operator!=(const State& s) const;
    State transitionTo(const State& s) const;
    std::string toString() const;
  };

private:
  Pcb pcb_;
  Rect boundary_;

  // Routing:
  std::vector<State> tmp_states_;
  std::vector<Shape> tmp_shapes_;

  void initializeGrid();
  void markPinInGrid(const Component& component, const Pin& pin, int val);
  void markFilledShapeInGrid(const Shape& shape, int layer, int val);
  Point convertWorldToGrid(const Point& p) const;
  Point convertGridToWorld(const Point& p) const;

  // Routing:
  bool canRouteOn(const State& s) const;
  std::vector<Shape> bfsAndAddToGrid(const std::vector<State>& states);
  bool bfsOnce(const State& start);
  std::vector<Shape> convertTraceArrayToShapes(const State s);
  void convertTraceArrayToShapesInternal(const State s);

  //debug:
  int idx_ = 0;
};

}  // memeroute

#endif  // VERYMEME_MEMEROUTE_ROUTER_H
