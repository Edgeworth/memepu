#ifndef VERYMEME_MEMEROUTE_RENDER_SHAPES_H
#define VERYMEME_MEMEROUTE_RENDER_SHAPES_H

#include <SFML/Graphics.hpp>

#include "verymeme/common.h"
#include "memeroute/types.h"

namespace memeroute {

// Helper routines:
sf::FloatRect floatRectUnion(const sf::FloatRect& a, const sf::FloatRect& b);
sf::FloatRect getVertexArraysBoundingBox(const std::vector<sf::VertexArray>& arrays);

// Drawing routines:
sf::VertexArray
createCircle(float radius, bool filled, sf::Transform tf, const sf::Color& color);
sf::VertexArray
createRect(const sf::FloatRect& r, const sf::Transform& tf, const sf::Color& color);


std::vector<sf::VertexArray>
createVertexArraysFromShape(const Shape& shape, sf::Transform tf, const sf::Color& color);

// Conversion routines:
sf::Vector2f pointToVector(const Point& p);
sf::FloatRect rectToFloatRect(const Rect& r);

template<typename T>
sf::Vector2f centerOf(const T& p) {
  return sf::Vector2f(p.left + float(p.width) / 2.f, p.top + float(p.height) / 2.f);
}

class DisplayList {
public:
  void draw(sf::RenderWindow& window);
  void add(const sf::VertexArray& array);

private:
  std::vector<sf::VertexArray> arrays_;
};

}  // memeroute

#endif  // VERYMEME_MEMEROUTE_RENDER_SHAPES_H
