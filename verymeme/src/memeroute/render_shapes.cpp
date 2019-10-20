#include "memeroute/render_shapes.h"

#include <cmath>

#include "verymeme/geom.h"
#include "verymeme/macros.h"
#include "verymeme/util.h"

namespace memeroute {

namespace {

float length(const sf::Vector2f& v) { return std::sqrt(v.x * v.x + v.y * v.y); }

sf::Vector2f normalize(const sf::Vector2f& v) {
  const auto len = length(v);
  bug_unless(len > EP);
  return v / length(v);
}

sf::Vector2f getPerpendicular(const sf::Vector2f& v) { return normalize(sf::Vector2f(-v.y, v.x)); }

std::vector<sf::VertexArray> createPathWithThickness(
    const std::vector<sf::Vector2f>& points, float thickness, const sf::Color& color) {
  sf::VertexArray quads(sf::PrimitiveType::Quads);
  std::vector<sf::VertexArray> circles;
  for (int i = 0; i < int(points.size()); ++i) {
    const auto& p0 = points[i];
    sf::Transform p0_tf;
    p0_tf.translate(p0);
    circles.push_back(createCircle(thickness / 2.0f, p0_tf, color, true /* filled */));
    if (i + 1 >= int(points.size())) continue;

    const auto& p1 = points[i + 1];
    if (length(p0 - p1) > EP) {
      const auto& perp = getPerpendicular(p1 - p0);
      quads.append({p0 + thickness * perp / 2.0f, color});
      quads.append({p0 - thickness * perp / 2.0f, color});
      quads.append({p1 - thickness * perp / 2.0f, color});
      quads.append({p1 + thickness * perp / 2.0f, color});
      sf::Transform p1_tf;
      p1_tf.translate(p1);
      circles.push_back(createCircle(thickness / 2.0f, p1_tf, color, true /* filled */));
    }
  }
  circles.push_back(std::move(quads));
  return circles;
}

sf::VertexArray createLineStrip(const std::vector<sf::Vector2f>& points, const sf::Color& color) {
  sf::VertexArray array(sf::PrimitiveType::LineStrip);
  for (const auto& point : points) array.append({point, color});
  return array;
}

}  // namespace

sf::FloatRect floatRectUnion(const sf::FloatRect& a, const sf::FloatRect& b) {
  if (a.width == 0 && a.height == 0) return b;
  if (b.width == 0 && b.height == 0) return a;
  sf::FloatRect merged{};
  merged.left = std::min(a.left, b.left);
  merged.top = std::min(a.top, b.top);
  const float right = std::max(a.left + a.width, b.left + b.width);
  const float bottom = std::max(a.top + a.height, b.top + b.height);
  merged.width = right - merged.left;
  merged.height = bottom - merged.top;
  return merged;
}

sf::FloatRect computeVertexArraysBbox(const std::vector<sf::VertexArray>& arrays) {
  sf::FloatRect bounds{};
  for (const auto& array : arrays) bounds = floatRectUnion(array.getBounds(), bounds);
  return bounds;
}

sf::Vector2f pointToVector(const Point& p) { return sf::Vector2f(p.x, p.y); }

sf::FloatRect rectToFloatRect(const Rect& r) {
  return sf::FloatRect(r.left, r.top, r.width(), r.height());
}

sf::VertexArray createCircle(float radius, sf::Transform tf, const sf::Color& color, bool filled) {
  sf::CircleShape circle(radius);
  sf::VertexArray array(filled ? sf::PrimitiveType::TriangleFan : sf::PrimitiveType::LineStrip);
  tf.translate(-radius, -radius);
  for (int i = 0; i < int(circle.getPointCount()); ++i)
    array.append({tf * circle.getPoint(i), color});
  if (!filled) array.append({tf * circle.getPoint(0), color});
  return array;
}

sf::VertexArray createRect(
    const sf::FloatRect& r, const sf::Transform& tf, const sf::Color& color, bool filled) {
  sf::VertexArray array(filled ? sf::PrimitiveType::Quads : sf::PrimitiveType::LineStrip);
  array.append({tf * sf::Vector2f(r.left, r.top), color});
  array.append({tf * sf::Vector2f(r.left, r.top + r.height), color});
  array.append({tf * sf::Vector2f(r.left + r.width, r.top + r.height), color});
  array.append({tf * sf::Vector2f(r.left + r.width, r.top), color});
  if (!filled) array.append({tf * sf::Vector2f(r.left, r.top), color});
  return array;
}

std::vector<sf::VertexArray> createVertexArraysFromShape(
    const Shape& shape, sf::Transform tf, const sf::Color& color, bool filled) {
  switch (shape.type) {
  case Shape::Type::PATH: {
    std::vector<sf::Vector2f> points;
    for (const auto& p : shape.path.points) points.emplace_back(tf * pointToVector(p));
    // Treat paths with width 0 as line strips so they are visible (width of >= 1 pixel).
    // TODO(improvement): Support |filled| for path.
    if (shape.path.width != 0)
      return createPathWithThickness(points, float(shape.path.width), color);
    else
      return {createLineStrip(points, color)};
  }
  case Shape::Type::CIRCLE: {
    tf.translate(pointToVector(shape.circle.p));
    return {createCircle(float(shape.circle.diameter) / 2.0f, tf, color, filled)};
  }
  case Shape::Type::RECT: return {createRect(rectToFloatRect(shape.rect), tf, color, false)};
  }
  bug_unless(false);
}

void DisplayList::draw(sf::RenderWindow& window) {
  for (const auto& array : arrays_) window.draw(array);
}

void DisplayList::add(const sf::VertexArray& array) { arrays_.push_back(array); }

}  // namespace memeroute
