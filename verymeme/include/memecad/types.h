#ifndef VERYMEME_MEMECAD_TYPES_H
#define VERYMEME_MEMECAD_TYPES_H

#include <vector>
#include <string>

#include "verymeme/common.h"

namespace memecad {

enum class Orientation {
  HORIZONTAL, VERTICAL, COUNT
};

class Lib {
public:
  class Pin {
  public:
    enum class ElectricalType {
      INPUT, OUTPUT, BIDIRECTIONAL, TRISTATE, PASSIVE, UNSPECIFIED, POWER_IN, POWER_OUT,
      OPEN_COLLECTOR, OPEN_EMITTER, NOT_CONNECTED, COUNT
    };
    enum class Direction {
      LEFT, RIGHT, UP, DOWN, COUNT
    };

    std::string name;
    int pin_number = -1;
    int x = -1;
    int y = -1;
    Direction direction;
    int subcomponent = -1;
    ElectricalType type;

    std::string toString(int indent = 0);
  };

  class Field {
  public:
    std::string text;
    int x = -1;
    int y = -1;
    int text_size = -1;
    Orientation text_orientation;
    std::string horizontal_justification = "C";
    std::string vertical_justification = "CNN";
  };

  class Component {
  public:
    enum class UnitSwappable {
      SWAPPABLE, UNSWAPPABLE, COUNT
    };

    std::vector<std::string> names;
    std::string ref;
    int unit_count = -1;
    UnitSwappable unit_swappable;
    std::vector<Pin> pins;
    std::vector<Field> fields;

    std::string toString(int indent = 0);
  };

  std::string name;
  std::vector<Component> components;

  Component& findComponent(const std::string& name);
  std::string toString(int indent = 0);
};

class Sheet {
public:
  class Label {
  public:
    enum class Type {
      GLOBAL, HIERARCHICAL, LOCAL, NOTES, COUNT
    };

    Type type;
    int x = -1;
    int y = -1;
    int orientation = 0;
    int dimension = 50;
    std::string shape = "~";
    std::string text;

    static int labelOrientationFromPinDirection(Lib::Pin::Direction d);
    std::string toString(int indent = 0);
  };

  class Field {
  public:
    int num = -1;
    std::string text;
    Orientation orientation = Orientation::HORIZONTAL;
    int x = -1;
    int y = -1;
    int size = 50;
    std::string flags = "0000";
    std::string justification = "C";
    std::string style = "CNN";

    static Field
    fromLibraryField(const Lib::Field& lib_field, int num, const std::string& text, int offset_x,
        int offset_y);
    std::string toString(int indent = 0);
  };

  class Component {
  public:
    std::string name;
    std::string ref;
    int subcomponent = -1;
    std::string timestamp;
    int x = -1;
    int y = -1;
    std::vector<Field> fields;
    std::string footer = DEFAULT_FOOTER;

    void offset(int x_offset, int y_offset);
    std::string toString(int indent = 0);
  };

  std::string header1 = DEFAULT_HEADER1;
  int id;
  std::string title;
  std::string header2 = DEFAULT_HEADER2;
  std::vector<Component> components;
  std::vector<Label> labels;

  std::string toString(int indent = 0);

private:
  constexpr static const char* DEFAULT_HEADER1 =
      "EESchema Schematic File Version 4\nLIBS:\n"
      "EELAYER 29 0\nEELAYER END\n$Descr A3 16535 11693\nencoding utf-8\n";
  constexpr static const char* DEFAULT_HEADER2 =
      "Date \"\"\nRev \"\"\nComp \"\"\nComment1 \"\"\nComment2 \"\"\n"
      "Comment3 \"\"\nComment4 \"\"\n$EndDescr\n";
  constexpr static const char* DEFAULT_FOOTER = "\t1    2600 1750\n\t1    0    0    -1\n";

};

std::ostream& operator<<(std::ostream& str, const Orientation& o);
std::istream& operator>>(std::istream& str, Orientation& o);

std::ostream& operator<<(std::ostream& str, const Sheet::Label::Type& o);
std::istream& operator>>(std::istream& str, Sheet::Label::Type& o);

std::ostream& operator<<(std::ostream& str, const Lib::Pin::Direction& o);
std::istream& operator>>(std::istream& str, Lib::Pin::Direction& o);

std::ostream& operator<<(std::ostream& str, const Lib::Component::UnitSwappable& o);
std::istream& operator>>(std::istream& str, Lib::Component::UnitSwappable& o);

std::ostream& operator<<(std::ostream& str, const Lib::Pin::ElectricalType& o);
std::istream& operator>>(std::istream& str, Lib::Pin::ElectricalType& o);

}  // memecad

#endif  // VERYMEME_MEMECAD_TYPES_H
