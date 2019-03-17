#include "memecad/types.h"

#include <boost/lexical_cast.hpp>


namespace memecad {

#define PRINT_FIELD(f) \
  s << std::string(indent, ' ') <<  #f << ": " << boost::lexical_cast<std::string>(f) << "\n";

std::string Sheet::Label::toString(int indent) {
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

int Sheet::Label::labelOrientationFromPinDirection(Lib::Pin::Direction d) {
  switch (d) {
    case Lib::Pin::Direction::LEFT:
      return 0;
    case Lib::Pin::Direction::UP:
      return 1;
    case Lib::Pin::Direction::RIGHT:
      return 2;
    case Lib::Pin::Direction::DOWN:
      return 3;
    default:
      verify_expr(false, "unknown direction '%d'", int(d));
  }
}

std::string Sheet::Field::toString(int indent) {
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

Sheet::Field
Sheet::Field::fromLibraryField(const Lib::Field& lib_field, int num, const std::string& text,
    int offset_x, int offset_y) {
  Field f = {};
  f.num = num;
  f.text = text;
  f.x = lib_field.x + offset_x;
  f.y = lib_field.y + offset_y;
  f.size = lib_field.text_size;
  f.justification = lib_field.horizontal_justification;
  f.style = lib_field.vertical_justification;
  return f;
}

std::string Sheet::Component::toString(int indent) {
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

void Sheet::Component::offset(int x_offset, int y_offset) {
  x += x_offset;
  y += y_offset;
  for (auto& field : fields) {
    field.x += x_offset;
    field.y += y_offset;
  }
}

std::string Sheet::toString(int indent) {
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

std::string Lib::Pin::toString(int indent) {
  std::stringstream s;
  PRINT_FIELD(name);
  PRINT_FIELD(x);
  PRINT_FIELD(y);
  PRINT_FIELD(direction);
  return s.str();
}

std::string Lib::Component::toString(int indent) {
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

std::string Lib::toString(int indent) {
  std::stringstream s;
  for (int i = 0; i < int(components.size()); ++i) {
    s << std::string(indent, ' ') << "Library component #" << (i + 1) << "\n";
    s << components[i].toString(indent + 2);
  }
  return s.str();
}

#undef PRINT_FIELD

Lib::Component& Lib::findComponent(const std::string& name) {
  for (auto& comp : components) {
    for (const auto& comp_name : comp.names) {
      if (comp_name == name)
        return comp;
    }
  }
  verify_expr(false, "can't find component '%s'", name.c_str());
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
const std::string ELECTRICAL_TYPE_MAPPING[] =
    {"I", "O", "B", "T", "P", "U", "W", "w", "C", "E", "N"};

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

std::ostream& operator<<(std::ostream& str, const Lib::Pin::Direction& o) {
  return outputEnum(str, o, DIRECTION_MAPPING);
}

std::istream& operator>>(std::istream& str, Lib::Pin::Direction& o) {
  return inputEnum(str, o, DIRECTION_MAPPING);
}

std::ostream& operator<<(std::ostream& str, const Lib::Component::UnitSwappable& o) {
  return outputEnum(str, o, UNIT_SWAPPABLE_MAPPING);
}

std::istream& operator>>(std::istream& str, Lib::Component::UnitSwappable& o) {
  return inputEnum(str, o, UNIT_SWAPPABLE_MAPPING);
}

std::ostream& operator<<(std::ostream& str, const Lib::Pin::ElectricalType& o) {
  return outputEnum(str, o, ELECTRICAL_TYPE_MAPPING);
}

std::istream& operator>>(std::istream& str, Lib::Pin::ElectricalType& o) {
  return inputEnum(str, o, ELECTRICAL_TYPE_MAPPING);
}


}  // memecad
