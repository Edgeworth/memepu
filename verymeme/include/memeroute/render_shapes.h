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
createCircle(float radius, bool filled, const sf::Vector2f& loc, const sf::Color& color);
sf::VertexArray
createRect(const sf::FloatRect& r, const sf::Vector2f& offset, const sf::Color& color);
std::vector<sf::VertexArray>
createVertexArraysFromShape(const Shape& shape, const sf::Vector2f& offset, const sf::Color& color);

// Conversion routines:
sf::Vector2f pointToVector(const Point& p);
sf::FloatRect rectToFloatRect(const Rect& r);

}  // memeroute

#endif  // VERYMEME_MEMEROUTE_RENDER_SHAPES_H
