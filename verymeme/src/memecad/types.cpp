#include "memecad/types.h"

#include <boost/lexical_cast.hpp>


namespace memecad {

#define PRINT_FIELD(f) \
  s << std::string(indent, ' ') <<  #f << ": " << boost::lexical_cast<std::string>(f) << "\n";

std::string label_t::toString(int indent) {
  std::stringstream s;
  PRINT_FIELD(type);
  PRINT_FIELD(x);
  PRINT_FIELD(y);
  PRINT_FIELD(orientation);
  PRINT_FIELD(dimension);
  PRINT_FIELD(shape);
  PRINT_FIELD(text);
  return s.str();
}

std::string field_t::toString(int indent) {
  std::stringstream s;
  PRINT_FIELD(num);
  PRINT_FIELD(text);
  PRINT_FIELD(orientation);
  PRINT_FIELD(x);
  PRINT_FIELD(y);
  PRINT_FIELD(size);
  PRINT_FIELD(flags);
  PRINT_FIELD(justification);
  PRINT_FIELD(style);
  return s.str();
}

std::string sheet_component_t::toString(int indent) {
  std::stringstream s;
  PRINT_FIELD(name);
  PRINT_FIELD(ref);
  PRINT_FIELD(subcomponent);
  PRINT_FIELD(timestamp);
  PRINT_FIELD(x);
  PRINT_FIELD(y);
  for (int i = 0; i < int(fields.size()); ++i) {
    s << std::string(indent, ' ') << "Field #" << (i + 1) << "\n";
    s << fields[i].toString(indent + 2);
  }
  return s.str();
}

std::string sheet_t::toString(int indent) {
  std::stringstream s;
  PRINT_FIELD(id);
  PRINT_FIELD(title);
  for (int i = 0; i < int(components.size()); ++i) {
    s << std::string(indent, ' ') << "Component #" << (i + 1) << "\n";
    s << components[i].toString(indent + 2);
  }
  for (int i = 0; i < int(labels.size()); ++i) {
    s << std::string(indent, ' ') << "Label #" << (i + 1) << "\n";
    s << labels[i].toString(indent + 2);
  }
  return s.str();
}

std::string lib_pin_t::toString(int indent) {
  std::stringstream s;
  PRINT_FIELD(name);
  PRINT_FIELD(x);
  PRINT_FIELD(y);
  PRINT_FIELD(direction);
  return s.str();
}

std::string lib_component_t::toString(int indent) {
  std::stringstream s;
  PRINT_FIELD(names[0]);
  PRINT_FIELD(ref);
  PRINT_FIELD(unit_count);
  PRINT_FIELD(unit_swappable);
  for (int i = 0; i < int(pins.size()); ++i) {
    s << std::string(indent, ' ') << "Pin #" << (i + 1) << "\n";
    s << pins[i].toString(indent + 2);
  }
  return s.str();
}

std::string lib_t::toString(int indent) {
  std::stringstream s;
  for (int i = 0; i < int(components.size()); ++i) {
    s << std::string(indent, ' ') << "Library component #" << (i + 1) << "\n";
    s << components[i].toString(indent + 2);
  }
  return s.str();
}

#undef PRINT_FIELD

lib_component_t& lib_t::findComponent(const std::string& name) {
  for (auto& comp : components) {
    for (const auto& comp_name : comp.names) {
      if (comp_name == name)
        return comp;
    }
  }
  verify_expr(false, "can't find component '%s'", name.c_str());
}

// TODO: Replace with general enum mapping stuff.

std::ostream& operator<<(std::ostream& str, const Orientation& o) {
  return str << (o == Orientation::HORIZONTAL ? "H" : "V");
}

std::istream& operator>>(std::istream& str, Orientation& o) {
  std::string v;
  str >> v;
  if (v == "H") o = Orientation::HORIZONTAL;
  else if (v == "V") o = Orientation::VERTICAL;
  else
    verify_expr(false, "invalid orientation %s", v.c_str());
  return str;
}

std::ostream& operator<<(std::ostream& str, const Label& o) {
  switch (o) {
    case Label::GLOBAL:
      return str << "GLabel";
    case Label::HIERARCHICAL:
      return str << "HLabel";
    case Label::LOCAL:
      return str << "Label";
    case Label::NOTES:
      return str << "Notes";
  }
  verify_expr(false, "unknown label");
}

std::istream& operator>>(std::istream& str, Label& o) {
  std::string v;
  str >> v;
  if (v == "HLabel") o = Label::HIERARCHICAL;
  else if (v == "GLabel") o = Label::GLOBAL;
  else if (v == "Label") o = Label::LOCAL;
  else if (v == "Notes") o = Label::NOTES;
  else
    verify_expr(false, "invalid text label type %s", v.c_str());
  return str;
}

std::ostream& operator<<(std::ostream& str, const Direction& o) {
  switch (o) {
    case Direction::LEFT:
      return str << "L";
    case Direction::RIGHT:
      return str << "R";
    case Direction::UP:
      return str << "U";
    case Direction::DOWN:
      return str << "D";
  }
  verify_expr(false, "unknown direction");
}

std::istream& operator>>(std::istream& str, Direction& o) {
  std::string v;
  str >> v;
  if (v == "L") o = Direction::LEFT;
  else if (v == "R") o = Direction::RIGHT;
  else if (v == "U") o = Direction::UP;
  else if (v == "D") o = Direction::DOWN;
  else
    verify_expr(false, "invalid direction type %s", v.c_str());
  return str;
}

std::ostream& operator<<(std::ostream& str, const UnitSwappable& o) {
  return str << (o == UnitSwappable::SWAPPABLE ? "F" : "L");
}

std::istream& operator>>(std::istream& str, UnitSwappable& o) {
  std::string v;
  str >> v;
  if (v == "F") o = UnitSwappable::SWAPPABLE;
  else if (v == "L") o = UnitSwappable::UNSWAPPABLE;
  else
    verify_expr(false, "invalid orientation %s", v.c_str());
  return str;
}

std::ostream& operator<<(std::ostream& str, const ElectricalType& o) {
  switch (o) {
    case ElectricalType::INPUT:
      return str << "I";
    case ElectricalType::OUTPUT:
      return str << "O";
    case ElectricalType::BIDIRECTIONAL:
      return str << "B";
    case ElectricalType::TRISTATE:
      return str << "T";
    case ElectricalType::PASSIVE:
      return str << "P";
    case ElectricalType::UNSPECIFIED:
      return str << "U";
    case ElectricalType::POWER_IN:
      return str << "W";
    case ElectricalType::POWER_OUT:
      return str << "w";
    case ElectricalType::OPEN_COLLECTOR:
      return str << "C";
    case ElectricalType::OPEN_EMITTER:
      return str << "E";
    case ElectricalType::NOT_CONNECTED:
      return str << "N";
  }
  verify_expr(false, "unknown electrical type");
}

std::istream& operator>>(std::istream& str, ElectricalType& o) {
  std::string v;
  str >> v;

  if (v == "I")
    o = ElectricalType::INPUT;
  else if (v == "O")
    o = ElectricalType::OUTPUT;
  else if (v == "B")
    o = ElectricalType::BIDIRECTIONAL;
  else if (v == "T")
    o = ElectricalType::TRISTATE;
  else if (v == "P")
    o = ElectricalType::PASSIVE;
  else if (v == "U")
    o = ElectricalType::UNSPECIFIED;
  else if (v == "W")
    o = ElectricalType::POWER_IN;
  else if (v == "w")
    o = ElectricalType::POWER_OUT;
  else if (v == "C")
    o = ElectricalType::OPEN_COLLECTOR;
  else if (v == "E")
    o = ElectricalType::OPEN_EMITTER;
  else if (v == "N")
    o = ElectricalType::NOT_CONNECTED;
  else
    verify_expr(false, "invalid direction type %s", v.c_str());
  return str;
}


}  // memecad
