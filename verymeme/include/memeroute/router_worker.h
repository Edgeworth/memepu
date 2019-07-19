#ifndef MEMEROUTE_ROUTER_WORKER_H
#define MEMEROUTE_ROUTER_WORKER_H

#include "memeroute/types.h"
#include "verymeme/geom.h"

namespace memeroute {

// TODO(improvement): move to invocationparams.
constexpr int GRID_ROWS = 500;
constexpr int GRID_COLS = 500;
constexpr int NUM_LAYERS = 2;

class RouterWorker {
public:
  explicit RouterWorker(Pcb pcb);

  struct InvocationParams {
    std::vector<std::string> net_names = {};
  };

  struct RoutingResult {
    std::vector<Shape> traces = {};
    std::vector<Point> vias = {};
    int failed = 0;

    void merge(const RoutingResult& result);
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

  // TODO(improvement): Needs to support more than 2 layers.
  static constexpr State DP9[9] =
      {{{-1, -1}, 0},
          {{-1, 0}, 0},
          {{-1, 1}, 0},
          {{0, -1}, 0},
          {{0, 1}, 0},
          {{1, -1}, 0},
          {{1, 0}, 0},
          {{1, 1}, 0},
          {{0, 0}, 1}};

  // Routing state:
  std::vector<State> tmp_states_;
  std::vector<Shape> tmp_shapes_;
  std::vector<Point> tmp_vias_;

  int blocked_[GRID_ROWS][GRID_COLS][NUM_LAYERS]{};
  uint8_t traces_[GRID_ROWS][GRID_COLS][NUM_LAYERS]{};
  uint8_t seen_[GRID_ROWS][GRID_COLS][NUM_LAYERS]{};
  State back_[GRID_ROWS][GRID_COLS][NUM_LAYERS];

  // Regular state:
  Pcb pcb_;
  Rect boundary_;

  // Routing:
  void initializeGrid();
  RoutingResult bfsAndAddToGrid(const std::vector<State>& states);
  bool bfsOnce(const State& start);

  RoutingResult collectRoutes(State s);
  void collectRoutesInternal(State s);

  // Helpers:

  bool oob(const State& s) const;
  Point convertWorldToGrid(const Point& p) const;
  Point convertGridToWorld(const Point& p) const;
  void markPinInGrid(const Component& component, const Pin& pin, int val);
  void markPadstackInGrid(const Point& p, const std::string& padstack_id);
  void markFilledShapeInGrid(const Shape& shape, int layer, int val);
  bool isBlocked(const State& prev_s, const State& s);
};

}  // memeroute


#endif  // MEMEROUTE_ROUTER_WORKER_H
