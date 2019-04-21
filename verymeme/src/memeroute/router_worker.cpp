#include <queue>

#include "memeroute/router_worker.h"

namespace memeroute {

namespace {

int64_t ceil_div(int64_t a, int64_t b) {
  return a / b + bool(a % b);
}

}  // namespace

RouterWorker::State RouterWorker::State::transitionTo(const RouterWorker::State& s) const {
  return {p + s.p, s.layer ? !layer : layer};  // TODO: Currently just flips layer.
}

bool RouterWorker::State::operator!=(const RouterWorker::State& s) const {
  return p != s.p || layer != s.layer;
}

std::string RouterWorker::State::toString() const {
  return "{" + p.toString() + ", " + std::to_string(layer) + "}";
}

RouterWorker::RouterWorker(const Pcb& pcb) : pcb_(pcb) {}

bool RouterWorker::oob(const RouterWorker::State& s) const {
  return s.p.x < 0 || s.p.y < 0 || s.p.x >= GRID_COLS || s.p.y >= GRID_ROWS || s.layer < 0 ||
         s.layer >= NUM_LAYERS;
}

Point RouterWorker::convertWorldToGrid(const Point& p) const {
  // Rounded up boundary so divisions guaranteed to be okay.
  const Point grid_point = {(p.x - boundary_.left) * GRID_COLS / boundary_.width(),
                            (p.y - boundary_.top) * GRID_ROWS / boundary_.height()};
  verify_expr(grid_point.x < GRID_COLS && grid_point.y < GRID_ROWS,
      "grid point %s from %s out of range", grid_point.toString().c_str(), p.toString().c_str());
  return grid_point;
}

Point RouterWorker::convertGridToWorld(const Point& p) const {
  return {(p.x * boundary_.width() + boundary_.width() / 2) / GRID_COLS + boundary_.left,
          (p.y * boundary_.height() + boundary_.height() / 2) / GRID_ROWS + boundary_.top};
}

void RouterWorker::markPinInGrid(const Component& component, const Pin& pin, int val) {
  const auto& padstack = pcb_.padstacks[pin.padstack_id];
  // Add padstacks. Convert from pin coord -> component coord -> pcb coord
  for (const auto& s : padstack.shapes)
    markFilledShapeInGrid(component.toParentCoord(pin.toParentCoord(s)),
        pcb_.getLayer(component, s), val);
}

void RouterWorker::markFilledShapeInGrid(const Shape& shape, int layer, int val) {
  const Rect bbox = shape.getBoundingBox();  // TODO: For now just do bounding box.
  const Rect grid_bbox = Rect::enclosing(convertWorldToGrid(bbox.origin()),
      convertWorldToGrid(bbox.bottom_right()));

  for (int r = grid_bbox.top; r < grid_bbox.bottom; ++r)
    for (int c = grid_bbox.left; c < grid_bbox.right; ++c)
      blocked[r][c][layer] += val;
}

void RouterWorker::initializeGrid() {
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
      markFilledShapeInGrid(component.toParentCoord(keepout),
          pcb_.getLayer(component, keepout), 1);
  }
}

RouterWorker::RoutingResult RouterWorker::route(const RouterWorker::InvocationParams& params) {
  initializeGrid();

  std::vector<Shape> paths;
  int idx = 0;
  int num_failed = 0;
  for (const auto& net_name : params.net_names) {
    const auto& net = pcb_.getNet(net_name);
//    printf("ROUTING: %s...", net.name.c_str());
    std::vector<State> states;
    for (const auto& pin_id : net.pin_ids) {
      const auto& component = pcb_.getComponentForPinId(pin_id);
      const auto& pin = pcb_.getPinForPinId(pin_id);
      // TODO: Through hole components can start from any layer. Needs to check padstack.
      states.push_back(
          {convertWorldToGrid(component.toParentCoord(pin.p)), pcb_.getLayer(component.side)});
      markPinInGrid(component, pin, -1);  // Temporarily unmark pins in this net.
    }
    const auto& routes = bfsAndAddToGrid(states);
    paths.insert(paths.end(), routes.begin(), routes.end());

    if (routes.empty()) {
//      printf(" FAILED AT %d\n", idx);
      num_failed++;
    }
//    else printf("\n");

    // Put them back.
    for (const auto& pin_id : net.pin_ids)
      markPinInGrid(pcb_.getComponentForPinId(pin_id), pcb_.getPinForPinId(pin_id), 1);
    idx++;
  }

  return {std::move(paths), num_failed};
}


std::vector<Shape> RouterWorker::bfsAndAddToGrid(const std::vector<State>& states) {
  memset(traces, 0, sizeof(traces)); // Reset traces to zero
  traces[states[0].p.y][states[0].p.x][states[0].layer] = true;  // Set-up initial connection point.

  // Start from the 2nd pad and try to connect to previous stuff so everything is connected.
  bool succeeded = true;
  for (int i = 1; i < int(states.size()); ++i) {
    memset(seen, 0, sizeof(seen));  // Reset seen to zero
    if (!bfsOnce(states[i])) {
      succeeded = false;
      break;
    }
  }

  if (!succeeded) return {};

  // Don't cross traces for the next bfs.
  for (int r = 0; r < GRID_ROWS; ++r)
    for (int c = 0; c < GRID_COLS; ++c)
      for (int l = 0; l < NUM_LAYERS; ++l) {
        // Do a cross block around traces[r][c][l] to prevent diagonal lines crossing.
        blocked[r][c][l] += int(traces[r][c][l]);
        if (r > 0) blocked[r - 1][c][l] += int(traces[r][c][l]);
        if (r + 1 < GRID_ROWS) blocked[r + 1][c][l] += int(traces[r][c][l]);
        if (c > 0) blocked[r][c - 1][l] += int(traces[r][c][l]);
        if (c + 1 < GRID_COLS) blocked[r][c + 1][l] += int(traces[r][c][l]);
      }

  return convertTraceArrayToShapes(states[0]);
}

// TODO: Do dijkstra instead?
bool RouterWorker::bfsOnce(const State& start) {
  std::queue<State> q;
  q.push(start);

  seen[start.p.y][start.p.x][start.layer] = true;
  while (!q.empty()) {
    const State s = q.front();
    q.pop();
    const int cur_seen = seen[s.p.y][s.p.x][s.layer];
    verify_expr(cur_seen, "BUG, cur_seen is false");

    for (const auto& dp : DP9) {
      const State new_s = s.transitionTo(dp);
      if (oob(new_s) || blocked[s.p.y][s.p.x][s.layer]) continue;

      // Found ourselves, ignore.
      if (seen[new_s.p.y][new_s.p.x][new_s.layer]) continue;

      // Found a friend trace. Add this path to here
      if (traces[new_s.p.y][new_s.p.x][new_s.layer]) {
        State cur = s;
        // Collect points back to starting point.
        while (cur != start) {
          traces[cur.p.y][cur.p.x][cur.layer] = true;
          cur = back[cur.p.y][cur.p.x][cur.layer];
        }
        traces[start.p.y][start.p.x][start.layer] = true;
        return true; // We are done.
      }

      back[new_s.p.y][new_s.p.x][new_s.layer] = s;  // Mark for backtracking.
      seen[new_s.p.y][new_s.p.x][new_s.layer] = true;  // Mark seen.
      q.push(new_s);  // Keep searching.
    }
  }
  return false;  // Unable to do.
}

void RouterWorker::convertTraceArrayToShapesInternal(const State s) {
  tmp_states_.push_back(s);
  seen[s.p.y][s.p.x][s.layer] = true;
  bool found = false;
  for (const auto& dp : DP9) {
    const State new_s = s.transitionTo(dp);
    if (oob(new_s) || seen[new_s.p.y][new_s.p.x][new_s.layer]) continue;
    if (traces[new_s.p.y][new_s.p.x][new_s.layer]) {
      convertTraceArrayToShapesInternal(new_s);
      // Only let the first search down place a path for previous states. Everything after should
      // just be branchs coming off the existing path.
      tmp_states_.clear();
      tmp_states_.push_back(s);
      found = true;
    }
  }

  if (!found) {
    // At leaf, add the shape.
    Shape cur_path;
    cur_path.type = Shape::Type::PATH;
    cur_path.path.width = std::min(boundary_.width() / GRID_COLS, boundary_.height() / GRID_ROWS);
    for (int idx = 0; idx < int(tmp_states_.size()); ++idx) {
      // Needs a new path if we're just starting or jumped layers.
      const bool needs_new_path = idx == 0 || tmp_states_[idx].layer != tmp_states_[idx - 1].layer;
      if (needs_new_path) {
        if (idx != 0) {
          tmp_shapes_.push_back(cur_path);
          cur_path.path.points.clear();
          // TODO: Add via here because we switched layers.
        }
        cur_path.layer_id = tmp_states_[idx] .layer;
      }

      const auto& grid_point = convertGridToWorld(tmp_states_[idx].p);
      // Trim collinear lines.
      if (cur_path.path.points.size() >= 2u) {
        const auto& a = cur_path.path.points[cur_path.path.points.size() - 2];
        const auto& b = cur_path.path.points.back();
        if ((b - a).cross(grid_point - b) == 0)
          cur_path.path.points.pop_back();
      }
      cur_path.path.points.push_back(grid_point);
    }
    tmp_shapes_.push_back(cur_path);  // Push final path.
  }
  tmp_states_.pop_back();
}

std::vector<Shape> RouterWorker::convertTraceArrayToShapes(const State s) {
  memset(seen, 0, sizeof(seen));  // Reset seen to zero
  tmp_shapes_.clear();
  convertTraceArrayToShapesInternal(s);
  return std::move(tmp_shapes_);
}

}  // memeroute
