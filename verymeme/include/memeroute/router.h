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
  Rect boundary_;

  // Routing:
  std::vector<Point> tmp_points_;
  std::vector<Shape> tmp_shapes_;

  void initializeGrid();
  void markPinInGrid(const Component& component, const Pin& pin, int val);
  void markFilledShapeInGrid(const Shape& shape, int val);
  Point convertWorldToGrid(const Point& p) const;
  Point convertGridToWorld(const Point& p) const;

  // Routing:
  bool canRouteOn(const Point& p) const;
  std::vector<Shape> bfsAndAddToGrid(const std::vector<Point>& grid_points);
  bool bfsOnce(const Point& start);
  std::vector<Shape> convertTraceArrayToShapes(Point p);
  void convertTraceArrayToShapesInternal(Point p);
};

}  // memeroute

#endif  // VERYMEME_MEMEROUTE_ROUTER_H
