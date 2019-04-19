#ifndef VERYMEME_MEMEROUTE_TYPES_H
#define VERYMEME_MEMEROUTE_TYPES_H

#include "verymeme/common.h"

namespace memeroute {

enum class Side {
  FRONT, BACK, COUNT
};

struct Shape {
  struct Path {
    int width;
    std::vector<Point> points;
  };
  struct Circle {
    int diameter;
    Point p = {};
  };
  enum class Type {
    PATH, CIRCLE, RECT
  };
  Type type;
  std::string layer_id = "";
  Path path = {};
  Circle circle = {};
  Rect rect = {};
};

struct Padstack {
  std::string name;
  std::vector<Shape> shapes;
};

struct Pin {
  std::string padstack_id;
  std::string pin_id;  // e.g. 1@1 format pin id can be string.
  Point p;
};

struct Image {
  std::string name;
  std::vector<Shape> outlines;
  std::vector<Pin> pins;
  std::vector<Shape> keepouts;
};

struct Component {
  std::string name;
  std::string image_id;
  Point p;
  Side side;
  int rotation;
  std::string part_number;
};

struct Pcb {
  std::string name;
  std::unordered_map<std::string, Image> images;
  std::unordered_map<std::string, Padstack> padstacks;
  std::vector<Component> components;
};


std::ostream& operator<<(std::ostream& str, const Side& o);
std::istream& operator>>(std::istream& str, Side& o);

}  // memeroute

#endif  // VERYMEME_MEMEROUTE_TYPES_H
