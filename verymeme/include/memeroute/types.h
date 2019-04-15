#ifndef VERYMEME_MEMEROUTE_TYPES_H
#define VERYMEME_MEMEROUTE_TYPES_H

#include "verymeme/common.h"

namespace memeroute {

struct Shape {
  struct Path {
    int width;
    std::vector<Point> points;
  };
  enum class Type {
    PATH, CIRCLE, RECT
  };
  Type type;
  std::string layer_id;
  Path path;
  int circle_diameter;
  Rect rect;
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
};

struct Pcb {
  std::string name;
  std::vector<Image> images;
  std::unordered_map<std::string, Padstack> padstacks;
};

}  // memeroute

#endif  // VERYMEME_MEMEROUTE_TYPES_H
