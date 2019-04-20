#include <bitset>
#include <queue>

#include "memeroute/router.h"

namespace memeroute {

namespace {

constexpr int GRID_ROWS = 500;
constexpr int GRID_COLS = 500;
const Point DP8[8] = {{-1, -1},
                      {-1, 0},
                      {-1, 1},
                      {0,  -1},
                      {0,  1},
                      {1,  -1},
                      {1,  0},
                      {1,  1}};
//const Point DP[4] = {
//    {0,  -1},
//    {-1, 0},
//    {0,  1},
//    {1,  0}};
// TODO: not thread safe.
int blocked[GRID_ROWS][GRID_COLS];
std::bitset<GRID_COLS> traces[GRID_ROWS];
std::bitset<GRID_COLS> seen[GRID_ROWS];
Point back[GRID_ROWS][GRID_COLS];

int64_t ceil_div(int64_t a, int64_t b) {
  return a / b + bool(a % b);
}

bool oob(const Point& p) {
  return p.x < 0 || p.y < 0 || p.x >= GRID_COLS || p.y >= GRID_ROWS;
}

}  // namespace

Router::Router(const Pcb& pcb) : pcb_(pcb) {}

std::vector<Shape> Router::route() {
  initializeGrid();

  std::vector<Shape> paths;
  int idx = 0;
  for (const auto& net : pcb_.nets) {
    std::vector<Point> grid_points;
    for (const auto& pin_id : net.pin_ids) {
      const auto& component = pcb_.getComponentForPinId(pin_id);
      const auto& pin = pcb_.getPinForPinId(pin_id);
      grid_points.push_back(convertWorldToGrid(component.toParentCoord(pin.p)));
      markPinInGrid(component, pin, -1);  // Temporarily unmark pins in this net.
    }
    const auto& routes = bfsAndAddToGrid(grid_points);
    paths.insert(paths.end(), routes.begin(), routes.end());

    if (routes.empty()) printf("FAILED AT %d\n", idx);

    // Put them back.
    for (const auto& pin_id : net.pin_ids)
      markPinInGrid(pcb_.getComponentForPinId(pin_id), pcb_.getPinForPinId(pin_id), 1);
    if (idx++ > 5) break;
  }
//  for (int r = 0; r < GRID_ROWS; ++r)
//    for (int c = 0; c < GRID_COLS; ++c) {
//      if (!blocked[r][c]) continue;
//      Shape path = {};
//      path.type = Shape::Type::PATH;
//      path.layer_id = "";
//      path.path.width = 1000;
//      path.path.points.push_back(convertGridToWorld({c, r}));
//      paths.push_back(std::move(path));
//    }
  return paths;
}

void Router::initializeGrid() {
  memset(blocked, 0, sizeof(blocked));

  // Set-up boundary. Round up so it evenly divides the grid.
  boundary_ = pcb_.boundary.getBoundingBox();
  verify_expr(!boundary_.empty(), "boundary empty");
  boundary_.set_width(ceil_div(boundary_.width() + 1, GRID_COLS) * GRID_COLS);
  boundary_.set_height(ceil_div(boundary_.height() + 1, GRID_ROWS) * GRID_ROWS);

  for (const auto& kv : pcb_.components) {
    const auto& component = kv.second;
    const auto& image = pcb_.images[component.image_id];
    for (const auto& kv2 : image.pins)
      markPinInGrid(component, kv2.second, 1);
    for (const auto& keepout : image.keepouts)
      markFilledShapeInGrid(component.toParentCoord(keepout), 1);
  }
}

void Router::markPinInGrid(const Component& component, const Pin& pin, int val) {
  const auto& padstack = pcb_.padstacks[pin.padstack_id];
  // Add padstacks. Convert from pin coord -> component coord -> pcb coord
  for (const auto& s : padstack.shapes)
    markFilledShapeInGrid(component.toParentCoord(pin.toParentCoord(s)), val);
}

void Router::markFilledShapeInGrid(const Shape& shape, int val) {
  const Rect bbox = shape.getBoundingBox();  // TODO: For now just do bounding box.
  const Rect grid_bbox = Rect::enclosing(convertWorldToGrid(bbox.origin()),
      convertWorldToGrid(bbox.bottom_right()));

  for (int r = grid_bbox.top; r < grid_bbox.bottom; ++r)
    for (int c = grid_bbox.left; c < grid_bbox.right; ++c)
      blocked[r][c] += val;
}

Point Router::convertWorldToGrid(const Point& p) const {
  // Rounded up boundary so divisions guaranteed to be okay.
  const Point grid_point = {(p.x - boundary_.left) * GRID_COLS / boundary_.width(),
                            (p.y - boundary_.top) * GRID_ROWS / boundary_.height()};
  verify_expr(grid_point.x < GRID_COLS && grid_point.y < GRID_ROWS,
      "grid point %s from %s out of range", grid_point.toString().c_str(), p.toString().c_str());
  return grid_point;
}

Point Router::convertGridToWorld(const Point& p) const {
  return {(p.x * boundary_.width() + boundary_.width() / 2) / GRID_COLS + boundary_.left,
          (p.y * boundary_.height() + boundary_.height() / 2) / GRID_ROWS + boundary_.top};
}

std::vector<Shape> Router::bfsAndAddToGrid(const std::vector<Point>& grid_points) {
  for (auto& row : traces) row.reset();  // Reset traces to zero.

  traces[grid_points[0].y][grid_points[0].x] = true;  // Set-up initial connection point.

  // Start from the 2nd pad and try to connect to previous stuff so everything is connected.
  bool succeeded = true;
  for (int i = 1; i < int(grid_points.size()); ++i) {
    for (auto& row : seen) row.reset();  // Reset seen to zero.
    if (!bfsOnce(grid_points[i])) {
      succeeded = false;
      break;
    }
  }

  if (!succeeded) return {};

  // Don't cross traces for the next bfs.
  for (int r = 0; r < GRID_ROWS; ++r)
    for (int c = 0; c < GRID_COLS; ++c)
      blocked[r][c] += int(traces[r][c]);

  return convertTraceArrayToShapes(grid_points[0]);
}

// Consider placing something directly next to something that is blocked an error.
// This solves the case of diagonal lines intersecting.
bool Router::canRouteOn(const Point& p) const {
  if (blocked[p.y][p.x]) return false;
  for (const auto& dp : DP8) {
    const Point new_p = p + dp;
    if (oob(new_p)) continue;
    if (blocked[new_p.y][new_p.x]) return false;
  }
  return true;
}

bool Router::bfsOnce(const Point& start) {
  std::queue<Point> q;
  q.push(start);

  seen[start.y][start.x] = true;
  while (!q.empty()) {
    const Point p = q.front();
    q.pop();
    const int cur_seen = seen[p.y][p.x];
    verify_expr(cur_seen, "BUG, cur_seen is false");

    for (const auto& dp : DP8) {
      const Point new_p = p + dp;
      if (oob(new_p) || !canRouteOn(new_p)) continue;

      // Found ourselves, ignore.
      if (seen[new_p.y][new_p.x]) continue;

      // Found a friend trace. Add this path to here
      if (traces[new_p.y][new_p.x]) {
        Point cur = p;
        // Collect points back to starting point.
        while (cur != start) {
          traces[cur.y][cur.x] = true;
          cur = back[cur.y][cur.x];
        }
        traces[start.y][start.x] = true;
        return true; // We are done.
      }

      back[new_p.y][new_p.x] = p;  // Mark for backtracking.
      seen[new_p.y][new_p.x] = true;  // Mark seen.
      q.push(new_p);  // Keep searching.
    }
  }
  return false;  // Unable to do.
}

void Router::convertTraceArrayToShapesInternal(Point p) {
  tmp_points_.push_back(p);
  seen[p.y][p.x] = true;
  bool found = false;
  for (const auto& dp : DP8) {
    const Point next_p = p + dp;
    if (oob(next_p) || seen[next_p.y][next_p.x]) continue;
    if (traces[next_p.y][next_p.x]) {
      convertTraceArrayToShapesInternal(next_p);
      found = true;
    }
  }
  // At leaf, add the shape.
  if (!found) {
    Shape path = {};
    path.type = Shape::Type::PATH;
    path.layer_id = "";  // TODO: Specify layer.
    path.path.width = std::min(boundary_.width() / GRID_COLS, boundary_.height() / GRID_ROWS);
    for (const auto& path_point : tmp_points_) {
      const auto& grid_point = convertGridToWorld(path_point);
      // Trim collinear lines.
      if (path.path.points.size() >= 2u) {
        const auto& a = path.path.points[path.path.points.size() - 2];
        const auto& b = path.path.points.back();
        if ((b - a).cross(grid_point - b) == 0)
          path.path.points.pop_back();
      }
      path.path.points.push_back(grid_point);
    }
    tmp_shapes_.push_back(std::move(path));
  }
  tmp_points_.pop_back();
}

std::vector<Shape> Router::convertTraceArrayToShapes(Point p) {
  for (auto& row : seen) row.reset();
  tmp_shapes_.clear();
  convertTraceArrayToShapesInternal(p);
  return std::move(tmp_shapes_);
}

}  // memeroute
