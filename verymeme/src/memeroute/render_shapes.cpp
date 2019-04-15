#include "memeroute/render_shapes.h"

namespace memeroute {

namespace {

const sf::Color COLOR = sf::Color::Blue;
const float EP = 1e-6;

float length(const sf::Vector2f& v) {
  return sqrt(v.x * v.x + v.y * v.y);
}

sf::Vector2f normalize(const sf::Vector2f& v) {
  const auto len = length(v);
  verify_expr(len > EP, "BUG: attempt to normalize zero length vector");
  return v / length(v);
}

sf::Vector2f getPerpendicular(const sf::Vector2f& v) {
  return normalize(sf::Vector2f(-v.y, v.x));
}

std::vector<sf::VertexArray>
createPathWithThickness(const std::vector<sf::Vector2f> points, float thickness) {
  sf::VertexArray quads(sf::PrimitiveType::Quads);
  std::vector<sf::VertexArray> circles;
  for (int i = 0; i < int(points.size()) - 1; ++i) {
    const auto& p0 = points[i];
    const auto& p1 = points[i + 1];
    if (length(p0 - p1) > EP) {
      const auto& perp = getPerpendicular(p1 - p0);
      quads.append({p0 + thickness * perp / 2.0f, COLOR});
      quads.append({p0 - thickness * perp / 2.0f, COLOR});
      quads.append({p1 - thickness * perp / 2.0f, COLOR});
      quads.append({p1 + thickness * perp / 2.0f, COLOR});
      circles.push_back(createCircle(p1, thickness / 2.0f, true /* filled */));
    }
    circles.push_back(createCircle(p0, thickness / 2.0f, true /* filled */));
  }
  circles.push_back(std::move(quads));
  return circles;
}

}  // namespace

sf::FloatRect floatRectUnion(const sf::FloatRect& a, const sf::FloatRect& b) {
  sf::FloatRect merged{};
  merged.left = std::min(a.left, b.left);
  merged.top = std::min(a.top, b.top);
  const float right = std::max(a.left + a.width, b.left + b.width);
  const float bottom = std::max(a.top + a.height, b.top + b.height);
  merged.width = right - merged.left;
  merged.height = bottom - merged.top;
  return merged;
}

sf::FloatRect getVertexArraysBoundingBox(const std::vector<sf::VertexArray>& arrays) {
  sf::FloatRect bounds{};
  for (const auto& array : arrays)
    bounds = floatRectUnion(array.getBounds(), bounds);
  return bounds;
}

sf::Vector2f pointToVector(const Point& p) {
  return sf::Vector2f(p.x, p.y);
}

sf::FloatRect rectToFloatRect(const Rect& r) {
  return sf::FloatRect(r.left, r.top, r.width(), r.height());
}

sf::VertexArray createCircle(const sf::Vector2f& loc, float radius, bool filled) {
  sf::CircleShape circle(radius);
  sf::VertexArray array(filled ? sf::PrimitiveType::TriangleFan : sf::PrimitiveType::LineStrip);
  const sf::Vector2f offset = loc - sf::Vector2f(radius, radius);
  for (int i = 0; i < int(circle.getPointCount()); ++i)
    array.append({circle.getPoint(i) + offset, COLOR});
  if (!filled)
    array.append({circle.getPoint(0) + offset, COLOR});
  return array;
}

sf::VertexArray createRect(const sf::FloatRect& r, const sf::Vector2f& offset) {
  sf::VertexArray array(sf::PrimitiveType::LineStrip);
  array.append({sf::Vector2f(r.left, r.top) + offset, COLOR});
  array.append({sf::Vector2f(r.left, r.top + r.height) + offset, COLOR});
  array.append({sf::Vector2f(r.left + r.width, r.top + r.height) + offset, COLOR});
  array.append({sf::Vector2f(r.left + r.width, r.top) + offset, COLOR});
  array.append({sf::Vector2f(r.left, r.top) + offset, COLOR});
  return array;
}

std::vector<sf::VertexArray>
createVertexArraysFromShape(const Shape& shape, const sf::Vector2f& offset) {
  switch (shape.type) {
    case Shape::Type::PATH: {
      std::vector<sf::Vector2f> points;
      for (const auto& p : shape.path.points)
        points.emplace_back(pointToVector(p) + offset);
      return createPathWithThickness(points, shape.path.width);
    }
    case Shape::Type::CIRCLE:
      return {createCircle(offset, shape.circle_diameter / 2.0f, false /* filled */)};
    case Shape::Type::RECT:
      return {createRect(rectToFloatRect(shape.rect), offset)};
  }
}

}  // memeroute
