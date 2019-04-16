#include "gtest/gtest.h"
#include "memeroute/render_shapes.h"
#include <SFML/Graphics.hpp>

namespace {

using MemerouteTest = testing::Test;

TEST_F(MemerouteTest, FloatRectUnion) {
  EXPECT_EQ(sf::FloatRect(0, 0, 2.f, 2.f),
      memeroute::floatRectUnion(sf::FloatRect(0, 0, 2.f, 2.f), sf::FloatRect(0, 0, 0, 0)));
  EXPECT_EQ(sf::FloatRect(0, 0, 2.f, 2.f),
      memeroute::floatRectUnion(sf::FloatRect(0, 0, 0, 0), sf::FloatRect(0, 0, 2.f, 2.f)));
  EXPECT_EQ(sf::FloatRect(0, 0, 0, 0),
      memeroute::floatRectUnion(sf::FloatRect(0, 0, 0, 0), sf::FloatRect(0, 0, 0, 0)));
  EXPECT_EQ(sf::FloatRect(0, 0, 2.f, 2.f),
      memeroute::floatRectUnion(sf::FloatRect(0, 0, 2.f, 2.f), sf::FloatRect(0, 0, 2.f, 2.f)));
  EXPECT_EQ(sf::FloatRect(0, 0, 3.f, 3.f),
      memeroute::floatRectUnion(sf::FloatRect(0, 0, 2.f, 2.f), sf::FloatRect(1.f, 1.f, 2.f, 2.f)));
  EXPECT_EQ(sf::FloatRect(-1.f, -1.f, 6.f, 6.f),
      memeroute::floatRectUnion(sf::FloatRect(-1.f, -1.f, 2.f, 2.f),
          sf::FloatRect(3.f, 3.f, 2.f, 2.f)));
}

}  // anonymous
