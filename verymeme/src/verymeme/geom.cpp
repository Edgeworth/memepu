#include "verymeme/geom.h"

#include <sstream>
#include <tuple>

std::ostream& operator<<(std::ostream& str, const Point& p) { return str << p.x << " " << p.y; }

Point& Point::operator+=(const Point& p) {
  x += p.x;
  y += p.y;
  return *this;
}

Point Point::operator+(const Point& p) const { return {x + p.x, y + p.y}; }

Point Point::operator-(const Point& p) const { return {x - p.x, y - p.y}; }

Point Point::operator-() const { return {-x, -y}; }

int64_t Point::cross(const Point& p) const { return x * p.y - y * p.x; }

Rect Rect::enclosing(const Point& a, const Point& b) {
  Rect r{};
  // Make one larger for right and bottom so |b| is inside.
  r.left = std::min(a.x, b.x);
  r.right = std::max(a.x, b.x) + 1;
  r.top = std::min(a.y, b.y);
  r.bottom = std::max(a.y, b.y) + 1;
  return r;
}
