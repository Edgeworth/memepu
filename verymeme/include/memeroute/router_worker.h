#ifndef VERYMEME_MEMEROUTE_ROUTER_WORKER_H
#define VERYMEME_MEMEROUTE_ROUTER_WORKER_H

#include "verymeme/common.h"
#include "memeroute/types.h"

namespace memeroute {

// TODO: move to invocationparams.
constexpr int GRID_ROWS = 500;
constexpr int GRID_COLS = 500;
constexpr int NUM_LAYERS = 2;

class RouterWorker {
public:
  explicit RouterWorker(const Pcb& pcb);

  struct InvocationParams {
    std::vector<std::string> net_names;
  };

  struct RoutingResult {
    std::vector<Shape> traces;
    int failed;
  };

  RoutingResult route(const InvocationParams& params);

private:
  struct State {
    Point p;
    int layer;

    bool operator!=(const State& s) const;
    State transitionTo(const State& s) const;
    std::string toString() const;
  };

  // TODO: Needs to support more than 2 layers.
  static constexpr State DP9[9] =
      {{{-1, -1}, 0},
       {{-1, 0},  0},
       {{-1, 1},  0},
       {{0,  -1}, 0},
       {{0,  1},  0},
       {{1,  -1}, 0},
       {{1,  0},  0},
       {{1,  1},  0},
       {{0,  0},  1}};

  // Routing state:
  std::vector<State> tmp_states_;
  std::vector<Shape> tmp_shapes_;

  int blocked[GRID_ROWS][GRID_COLS][NUM_LAYERS];
  uint8_t traces[GRID_ROWS][GRID_COLS][NUM_LAYERS];
  uint8_t seen[GRID_ROWS][GRID_COLS][NUM_LAYERS];
  State back[GRID_ROWS][GRID_COLS][NUM_LAYERS];

  // Regular state:
  Pcb pcb_;
  Rect boundary_;

  // Routing:
  void initializeGrid();
  std::vector<Shape> bfsAndAddToGrid(const std::vector<State>& states);
  bool bfsOnce(const State& start);

  std::vector<Shape> convertTraceArrayToShapes(const State s);
  void convertTraceArrayToShapesInternal(const State s);

  // Helpers:

  bool oob(const State& s) const;
  Point convertWorldToGrid(const Point& p) const;
  Point convertGridToWorld(const Point& p) const;
  void markPinInGrid(const Component& component, const Pin& pin, int val);
  void markFilledShapeInGrid(const Shape& shape, int layer, int val);
};

}  // memeroute


#endif  // VERYMEME_MEMEROUTE_ROUTER_WORKER_H
