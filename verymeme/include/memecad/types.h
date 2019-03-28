#ifndef VERYMEME_MEMECAD_TYPES_H
#define VERYMEME_MEMECAD_TYPES_H

#include <vector>
#include <string>

#include "verymeme/common.h"

namespace memecad {

enum class Orientation {
  HORIZONTAL, VERTICAL, COUNT
};

enum class PinType {
  INPUT, OUTPUT, BIDIRECTIONAL, TRISTATE, PASSIVE, UNSPECIFIED, POWER_IN, POWER_OUT,
  OPEN_COLLECTOR, OPEN_EMITTER, NOT_CONNECTED, COUNT
};

enum class Direction {
  LEFT, RIGHT, UP, DOWN, COUNT
};

struct Lib {
  struct Pin {
    std::string name;
    int pin_number = -1;
    Point p = {};
    Direction direction;
    int subcomponent = -1;
    PinType type;
  };

  struct Field {
    int num = -1;
    std::string text;
    Point p = {};
    int text_size = -1;
    Orientation text_orientation;
    std::string horizontal_justification = "C";
    std::string vertical_justification = "CNN";
  };

  struct Component {
    enum class UnitSwappable {
      SWAPPABLE, UNSWAPPABLE, COUNT
    };

    std::vector<std::string> names;
    std::string ref;
    int unit_count = -1;
    UnitSwappable unit_swappable;
    std::vector<Pin> pins;
    std::vector<Field> fields;

    Rect getBoundingBox(int subcomponent) const;
    const Lib::Pin* findPin(const std::string& pin_name) const;
    const Lib::Pin* findPin(int pin_number) const;
  };

  std::string name;
  std::vector<Component> components;

  Component& findComponent(const std::string& name);
};

struct Sheet {
  struct Wire {
    Point start = {};
    Point end = {};
  };

  struct RefField {
    // First two fields are for name and filename.
    constexpr static int HIERARCHICAL_REF_OFFSET = 2;
    int num = 0;
    std::string text;
    PinType type;
    Direction side;
    Point p = {};
    int dimension = 50;
  };

  struct Ref {
    std::string timestamp = "DEADBEEF";
    std::string name;
    std::string filename;
    Point p = {};
    int width = 1000;
    int height = 1000;
    std::vector<RefField> fields;

    void offsetTo(const Point& loc);
  };

  struct Label {
    enum class Type {
      GLOBAL, HIERARCHICAL, LOCAL, NOTES, NOCONNECT, COUNT
    };
    enum class NetType {
      INPUT, OUTPUT, BIDIRECTIONAL, TRISTATE, PASSIVE, COUNT
    };

    Type type;
    Point p = {};
    int orientation = 0;
    int dimension = 50;
    NetType net_type;  // Only used for Global and Hierarchical labels.
    bool italic = false;
    bool bold = false;
    std::string text;

    void connectToPin(const Lib::Pin& pin);
    void connectToRefField(const RefField& ref_field);
    bool operator<(const Label& o) const;
  };

  struct Field {
    int num = -1;
    std::string text;
    Orientation orientation = Orientation::HORIZONTAL;
    Point p = {};
    int size = 50;
    std::string flags = "0000";
    std::string justification = "C";
    std::string style = "CNN";
  };

  struct Component {
    std::string name;
    std::string ref;
    int subcomponent = -1;
    std::string timestamp = "DEADBEEF";
    Point p = {};
    std::vector<Field> fields;
    std::string footer = DEFAULT_FOOTER;

    void offset(Point offset);
    void addLibField(const Lib::Field& lib_field, const std::string& text);
  };

  std::string header1 = DEFAULT_HEADER1;
  int id;
  std::string title;
  std::string header2 = DEFAULT_HEADER2;
  std::vector<Component> components;
  std::vector<Label> labels;
  std::vector<Ref> refs;
  std::vector<Wire> wires;

private:
  constexpr static const char* DEFAULT_HEADER1 =
      "EESchema Schematic File Version 4\nLIBS:\n"
      "EELAYER 29 0\nEELAYER END\n$Descr A3 16535 11693\nencoding utf-8\n";
  constexpr static const char* DEFAULT_HEADER2 =
      "Date \"\"\nRev \"\"\nComp \"\"\nComment1 \"\"\nComment2 \"\"\n"
      "Comment3 \"\"\nComment4 \"\"\n$EndDescr\n";
  constexpr static const char* DEFAULT_FOOTER = "\t1    2600 1750\n\t1    0    0    -1\n";

};

PinType netTypeToPinType(Sheet::Label::NetType net_type);
int pinDirectionToLabelOrientation(Direction d, Sheet::Label::Type label_type);

std::ostream& operator<<(std::ostream& str, const Orientation& o);
std::istream& operator>>(std::istream& str, Orientation& o);

std::ostream& operator<<(std::ostream& str, const Sheet::Label::Type& o);
std::istream& operator>>(std::istream& str, Sheet::Label::Type& o);

std::ostream& operator<<(std::ostream& str, const Direction& o);
std::istream& operator>>(std::istream& str, Direction& o);

std::ostream& operator<<(std::ostream& str, const Lib::Component::UnitSwappable& o);
std::istream& operator>>(std::istream& str, Lib::Component::UnitSwappable& o);

std::ostream& operator<<(std::ostream& str, const PinType& o);
std::istream& operator>>(std::istream& str, PinType& o);

std::ostream& operator<<(std::ostream& str, const Sheet::Label::NetType& o);
std::istream& operator>>(std::istream& str, Sheet::Label::NetType& o);

}  // memecad

#endif  // VERYMEME_MEMECAD_TYPES_H
