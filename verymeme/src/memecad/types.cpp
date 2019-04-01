#include "memecad/types.h"

#include <boost/lexical_cast.hpp>
#include <memecad/types.h>


namespace memecad {

namespace {

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

Rect Lib::Component::getBoundingBox(int subcomponent) const {
  Rect bounds;
  for (const auto& pin : pins) {
    if (pin.subcomponent != subcomponent) continue;
    bounds.left = std::min(bounds.left, pin.p.x);
    bounds.right = std::max(bounds.right, pin.p.x);
    bounds.top = std::min(bounds.top, pin.p.y);
    bounds.bottom = std::max(bounds.bottom, pin.p.y);
  }
  bounds.inset(-200, -200);
  return bounds;
}

const Lib::Pin* Lib::Component::findPinByName(const std::string& pin_name) const {
  for (const auto& pin : pins) {
    if (pin.name == pin_name)
      return &pin;
  }
  return nullptr;
}

const Lib::Pin* Lib::Component::findPinById(const std::string& pin_id) const {
  for (const auto& pin : pins) {
    if (pin.id == pin_id)
      return &pin;
  }
  return nullptr;
}

Lib::Component* Lib::findComponent(const std::string& name_to_find) {
  for (auto& comp : components) {
    for (const auto& comp_name : comp.names) {
      if (comp_name == name_to_find)
        return &comp;
    }
  }
  return nullptr;
}

bool Sheet::Wire::operator<(const Sheet::Wire& o) const {
  return std::tie(start, end) < std::tie(o.start, o.end);
}

bool Sheet::RefField::operator<(const Sheet::RefField& o) const {
  return std::tie(text, num, type, side, p, dimension) <
         std::tie(o.text, o.num, o.type, o.side, o.p, o.dimension);
}

void Sheet::Ref::offsetTo(const Point& loc) {
  for (auto& field : fields) {
    field.p += loc - p;
  }
  p = loc;
}

bool Sheet::Ref::operator<(const Sheet::Ref& o) const {
  return std::tie(name, timestamp, filename, p, width, height, fields) <
         std::tie(o.name, o.timestamp, o.filename, o.p, o.width, o.height, o.fields);
}

void Sheet::Label::connectToPin(const Lib::Pin& pin) {
  p = pin.p;
  orientation = pinDirectionToLabelOrientation(pin.direction, type);
}

void Sheet::Label::connectToRefField(const Sheet::RefField& ref_field) {
  p = ref_field.p;
  orientation = pinDirectionToLabelOrientation(ref_field.side, type);
}

bool Sheet::Label::operator<(const Sheet::Label& o) const {
  // Deliberately consider labels the same if they don't differ by net type or text.
  // This is used to collect the set of heirarchical labels that need to be plumbed upward.
  if (net_type != o.net_type) return net_type < o.net_type;
  return toStringIntPair(text) < toStringIntPair(o.text);
}

bool Sheet::Field::operator<(const Sheet::Field& o) const {
  return std::tie(text, num, orientation, p, size, flags, justification, style) <
         std::tie(o.text, o.num, o.orientation, o.p, o.size, o.flags, o.justification, o.style);
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
  for (auto& field : fields)
    field.p += offset;
}

bool Sheet::Component::operator<(const Sheet::Component& o) const {
  return std::tie(name, ref, subcomponent, timestamp, p, fields, footer) <
         std::tie(o.name, o.ref, o.subcomponent, o.timestamp, o.p, o.fields, o.footer);
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
const std::string LABEL_MAPPING[] = {"GLabel", "HLabel", "Label", "Notes", "NoConn"};
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
