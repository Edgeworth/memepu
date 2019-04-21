#ifndef VERYMEME_MEMEROUTE_TYPES_H
#define VERYMEME_MEMEROUTE_TYPES_H

#include <unordered_map>
#include <map>

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
  int layer_id = -1;  // Layer id in Pcb::layers or -1.
  Path path = {};
  Circle circle = {};
  Rect rect = {};

  Rect getBoundingBox() const;
};

struct Padstack {
  std::string name;
  std::vector<Shape> shapes;
};

struct Pin {
  std::string padstack_id;
  std::string pin_id;  // e.g. 1@1 format pin id can be string.
  Point p;

  Point toParentCoord(const Point& local) const;
  Shape toParentCoord(const Shape& local) const;
};

struct Image {
  std::string name;
  std::vector<Shape> outlines;
  std::unordered_map<std::string, Pin> pins;
  std::vector<Shape> keepouts;
};

struct Component {
  std::string name;
  std::string image_id;
  Point p;
  Side side;
  int rotation;
  std::string part_number;

  Point toParentCoord(const Point& local) const;
  Shape toParentCoord(const Shape& local) const;
};

struct Net {
  struct PinId {
    std::string component_id;
    std::string pin_id;

    bool operator<(const PinId& o) const;
    std::string toString() const;
  };

  std::string name;
  std::vector<PinId> pin_ids;  // Of the form: ComponentId-PinId
};

struct Pcb {
  std::string name;
  Shape boundary;
  std::unordered_map<std::string, Image> images;
  std::unordered_map<std::string, Padstack> padstacks;
  std::unordered_map<std::string, Component> components;
  std::unordered_map<std::string, int> layers;
  std::vector<Net> nets;

  void verifyAndSetup();
  const Net* getNetForPinId(const Net::PinId& pin_id) const;
  const Component& getComponentForPinId(const Net::PinId& pin_id) const;
  const Pin& getPinForPinId(const Net::PinId& pin_id) const;

  int getLayer(Side side) const;

  // Gets which layer |shape| part of |component| should be placed on.
  int getLayer(const Component& component, const Shape& shape) const;

private:
  std::map<Net::PinId, Net> pin_id_to_net_;
};


std::ostream& operator<<(std::ostream& str, const Side& o);
std::istream& operator>>(std::istream& str, Side& o);

}  // memeroute

#endif  // VERYMEME_MEMEROUTE_TYPES_H
