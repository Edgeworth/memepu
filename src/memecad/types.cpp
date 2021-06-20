// Copyright 2019 E.
#include "memecad/types.h"

#include <boost/lexical_cast.hpp>

#include "verymeme/geom.h"
#include "verymeme/macros.h"
#include "verymeme/string_util.h"

namespace memecad {

namespace {

// Split e.g. LABEL1 => LABEL, 1 so ordering for numbers is done correctly.
std::pair<std::string, int> toStringIntPair(const std::string& s) {
  std::string str;
  std::string num;
  for (auto c : s) {
    num += c;
    if (!isdigit(c)) {
      str += num;
      num = "";
    }
  }
  if (num.empty()) return std::make_pair(str, 0);
  return std::make_pair(str, boost::lexical_cast<int>(num));
}

Direction getOppositeDirection(Direction d) {
  switch (d) {
  case Direction::LEFT: return Direction::RIGHT;
  case Direction::DOWN: return Direction::UP;
  case Direction::RIGHT: return Direction::LEFT;
  case Direction::UP: return Direction::DOWN;
  default: verify_expr(false, "unknown direction '%d'", int(d));
  }
}

}  // namespace

PinType netTypeToPinType(Sheet::Label::NetType net_type) {
  switch (net_type) {
  case Sheet::Label::NetType::INPUT: return PinType::INPUT;
  case Sheet::Label::NetType::OUTPUT: return PinType::OUTPUT;
  case Sheet::Label::NetType::BIDIRECTIONAL: return PinType::BIDIRECTIONAL;
  case Sheet::Label::NetType::TRISTATE: return PinType::TRISTATE;
  case Sheet::Label::NetType::PASSIVE: return PinType::PASSIVE;
  default: verify_expr(false, "Unknown net type '%d'", int(net_type));
  }
}

Rect Lib::Component::bbox(int subcomponent) const {
  Rect bounds;
  for (const auto& pin : pins) {
    if (pin.subcomponent != subcomponent) continue;
    bounds.left = std::min(bounds.left, pin.p.x);
    bounds.right = std::max(bounds.right, pin.p.x);
    bounds.top = std::min(bounds.top, pin.p.y);
    bounds.bottom = std::max(bounds.bottom, pin.p.y);
  }
  bounds.inset(-100, -100);
  return bounds;
}

const Lib::Pin* Lib::Component::findPinByName(const std::string& pin_name) const {
  for (const auto& pin : pins) {
    if (pin.name == pin_name) return &pin;
  }
  return nullptr;
}

const Lib::Pin* Lib::Component::findPinById(const std::string& pin_id) const {
  for (const auto& pin : pins) {
    if (pin.id == pin_id) return &pin;
  }
  return nullptr;
}

Lib::Component* Lib::findComponent(const std::string& name_to_find) {
  for (auto& comp : components) {
    for (const auto& comp_name : comp.names) {
      if (comp_name == name_to_find) return &comp;
    }
  }
  return nullptr;
}

void Sheet::Ref::offset(const Point& offset) {
  p += offset;
  for (auto& field : fields) field.p += offset;
}

void Sheet::Label::connectToPin(const Lib::Pin& pin) {
  p = pin.p;
  direction = getOppositeDirection(pin.direction);
}

void Sheet::Label::connectToRefField(const Sheet::RefField& ref_field) {
  p = ref_field.p;
  direction = getOppositeDirection(ref_field.side);
}

bool Sheet::Label::operator<(const Sheet::Label& o) const {
  // Deliberately consider labels the same if they don't differ by net type or text.
  // This is used to collect the set of hierarchical labels that need to be plumbed upward.
  if (net_type != o.net_type) return net_type < o.net_type;
  return toStringIntPair(text) < toStringIntPair(o.text);
}

Rect Sheet::Label::bbox() const {
  const int text_length = text.size() * dimension;
  switch (direction) {
  case Direction::LEFT: return {p.x - text_length, p.y - dimension, p.x, p.y};
  case Direction::DOWN: return {p.x - dimension, p.y, p.x, p.y + text_length};
  case Direction::RIGHT: return {p.x, p.y - dimension, p.x + text_length, p.y};
  case Direction::UP: return {p.x - dimension, p.y - text_length, p.x, p.y};
  default: verify_expr(false, "unknown direction '%d'", int(direction));
  }
}

void Sheet::Component::addLibField(const Lib::Field& lib_field, const std::string& text) {
  auto& f = fields.emplace_back();
  f.num = lib_field.num;
  f.text = text;
  f.p = lib_field.p;
  f.size = lib_field.text_size;
  f.justification = lib_field.horizontal_justification;
  f.style = lib_field.vertical_justification;
}

void Sheet::Component::offset(Point offset) {
  p += offset;
  for (auto& field : fields) field.p += offset;
}

const std::string ORIENTATION_MAPPING[] = {"H", "V"};
const std::string LABEL_MAPPING[] = {"GLabel", "HLabel", "Label", "Notes", "NoConn"};
const std::string DIRECTION_MAPPING[] = {"L", "R", "U", "D"};
const std::string UNIT_SWAPPABLE_MAPPING[] = {"F", "L"};
const std::string PIN_TYPE_MAPPING[] = {"I", "O", "B", "T", "P", "U", "W", "w", "C", "E", "N"};
const std::string NET_TYPE_MAPPING[] = {"Input", "Output", "BiDi", "3State", "UnSpc"};

std::ostream& operator<<(std::ostream& str, const Orientation& o) {
  return outputEnum(str, o, ORIENTATION_MAPPING);
}

std::istream& operator>>(std::istream& str, Orientation& o) {
  return inputEnum(str, o, ORIENTATION_MAPPING);
}

std::ostream& operator<<(std::ostream& str, const Sheet::Label::Type& o) {
  return outputEnum(str, o, LABEL_MAPPING);
}

std::istream& operator>>(std::istream& str, Sheet::Label::Type& o) {
  return inputEnum(str, o, LABEL_MAPPING);
}

std::ostream& operator<<(std::ostream& str, const Direction& o) {
  return outputEnum(str, o, DIRECTION_MAPPING);
}

std::istream& operator>>(std::istream& str, Direction& o) {
  return inputEnum(str, o, DIRECTION_MAPPING);
}

std::ostream& operator<<(std::ostream& str, const Lib::Component::UnitSwappable& o) {
  return outputEnum(str, o, UNIT_SWAPPABLE_MAPPING);
}

std::istream& operator>>(std::istream& str, Lib::Component::UnitSwappable& o) {
  return inputEnum(str, o, UNIT_SWAPPABLE_MAPPING);
}

std::ostream& operator<<(std::ostream& str, const PinType& o) {
  return outputEnum(str, o, PIN_TYPE_MAPPING);
}

std::istream& operator>>(std::istream& str, PinType& o) {
  return inputEnum(str, o, PIN_TYPE_MAPPING);
}

std::ostream& operator<<(std::ostream& str, const Sheet::Label::NetType& o) {
  return outputEnum(str, o, NET_TYPE_MAPPING);
}

std::istream& operator>>(std::istream& str, Sheet::Label::NetType& o) {
  return inputEnum(str, o, NET_TYPE_MAPPING);
}

}  // namespace memecad
