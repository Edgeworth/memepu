#include "memecad/types.h"

#include <boost/lexical_cast.hpp>


namespace memecad {

namespace {

int pinDirectionToLabelOrientation(Direction d, Sheet::Label::Type label_type) {
  bool is_hierarchical_or_global =
      label_type == Sheet::Label::Type::HIERARCHICAL || label_type == Sheet::Label::Type::GLOBAL;
  switch (d) {
    case Direction::LEFT: return is_hierarchical_or_global ? 2 : 0;
    case Direction::DOWN: return 1;
    case Direction::RIGHT: return is_hierarchical_or_global ? 0 : 2;
    case Direction::UP: return 3;
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

Rect Lib::Component::getBoundingBox(int subcomponent) const {
  Rect bounds;
  for (const auto& pin : pins) {
    if (pin.subcomponent != subcomponent) continue;
    bounds.left = std::min(bounds.left, pin.x);
    bounds.right = std::max(bounds.right, pin.x);
    bounds.top = std::min(bounds.top, pin.y);
    bounds.bottom = std::max(bounds.bottom, pin.y);
  }
  bounds.inset(-200, -200);
  return bounds;
}
const Lib::Pin* Lib::Component::findPin(const std::string& pin_name) const {
  for (const auto& pin : pins) {
    if (pin.name == pin_name)
      return &pin;
  }
  return nullptr;
}

const Lib::Pin* Lib::Component::findPin(int pin_number) const {
  for (const auto& pin : pins) {
    if (pin.pin_number == pin_number)
      return &pin;
  }
  return nullptr;
}

Lib::Component& Lib::findComponent(const std::string& name) {
  for (auto& comp : components) {
    for (const auto& comp_name : comp.names) {
      if (comp_name == name)
        return comp;
    }
  }
  verify_expr(false, "can't find component '%s'", name.c_str());
}


void Sheet::Ref::offsetTo(const Point& loc) {
  for (auto& field : fields) {
    field.x += loc.x - x;
    field.y += loc.y - y;
  }
  x = loc.x;
  y = loc.y;
}

void Sheet::Label::connectToPin(const Lib::Pin& pin) {
  x = pin.x;
  y = pin.y;
  orientation = pinDirectionToLabelOrientation(pin.direction, type);
}

void Sheet::Label::connectToRefField(const Sheet::RefField& ref_field) {
  x = ref_field.x;
  y = ref_field.y;
  orientation = pinDirectionToLabelOrientation(ref_field.side, type);
}

bool Sheet::Label::operator<(const Sheet::Label& o) const {
  // Consider labels uniquely defined by their text and net type. Put inputs before outputs.
  return std::tie(net_type, text) < std::tie(o.net_type, o.text);
}

void Sheet::Component::addLibField(const Lib::Field& lib_field, const std::string& text) {
  auto& f = fields.emplace_back();
  f.num = lib_field.num;
  f.text = text;
  f.x = lib_field.x;
  f.y = lib_field.y;
  f.size = lib_field.text_size;
  f.justification = lib_field.horizontal_justification;
  f.style = lib_field.vertical_justification;
}

void Sheet::Component::offset(Point p) {
  x += p.x;
  y += p.y;
  for (auto& field : fields) {
    field.x += p.x;
    field.y += p.y;
  }
}

template<typename T>
std::ostream&
outputEnum(std::ostream& str, const T& enumeration, const std::string (& mapping)[int(T::COUNT)]) {
  return str << mapping[int(enumeration)];
}

template<typename T>
std::istream&
inputEnum(std::istream& str, T& enumeration, const std::string (& mapping)[int(T::COUNT)]) {
  std::string v;
  str >> v;
  for (int i = 0; i < int(T::COUNT); ++i) {
    if (mapping[i] == v) {
      enumeration = T(i);
      return str;
    }
  }
  verify_expr(false, "unknown enum with string value '%s'", v.c_str());
}

const std::string ORIENTATION_MAPPING[] = {"H", "V"};
const std::string LABEL_MAPPING[] = {"GLabel", "HLabel", "Label", "Notes"};
const std::string DIRECTION_MAPPING[] = {"L", "R", "U", "D"};
const std::string UNIT_SWAPPABLE_MAPPING[] = {"F", "L"};
const std::string PIN_TYPE_MAPPING[] =
    {"I", "O", "B", "T", "P", "U", "W", "w", "C", "E", "N"};
const std::string NET_TYPE_MAPPING[] = {
    "Input", "Output", "BiDi", "3State", "UnSpc"
};

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

}  // memecad
