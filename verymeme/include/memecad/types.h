#ifndef VERYMEME_MEMECAD_TYPES_H
#define VERYMEME_MEMECAD_TYPES_H

#include <vector>
#include <string>

#include "verymeme/common.h"

namespace memecad {

enum class Orientation {
  HORIZONTAL, VERTICAL, COUNT
};

enum class Label {
  GLOBAL, HIERARCHICAL, LOCAL, NOTES, COUNT
};

enum class Direction {
  LEFT, RIGHT, UP, DOWN, COUNT
};

enum class UnitSwappable {
  SWAPPABLE, UNSWAPPABLE, COUNT
};

enum class ElectricalType {
  INPUT, OUTPUT, BIDIRECTIONAL, TRISTATE, PASSIVE, UNSPECIFIED, POWER_IN, POWER_OUT, OPEN_COLLECTOR,
  OPEN_EMITTER, NOT_CONNECTED, COUNT
};

struct lib_field_t {
  std::string text;
  int x = -1;
  int y = -1;
  int text_size = -1;
  Orientation text_orientation;
  std::string horizontal_justification = "C";
  std::string vertical_justification = "CNN";
};

struct lib_pin_t {
  std::string name;
  int x = -1;
  int y = -1;
  Direction direction;
  int unit_number = -1;
  ElectricalType type;

  std::string toString(int indent = 0);
};

struct lib_component_t {
  std::vector<std::string> names;
  std::string ref;
  int unit_count = -1;
  UnitSwappable unit_swappable;
  std::vector<lib_pin_t> pins;
  std::vector<lib_field_t> fields;

  std::string toString(int indent = 0);
};

struct lib_t {
  std::string name;
  std::vector<lib_component_t> components;

  lib_component_t& findComponent(const std::string& name);
  std::string toString(int indent = 0);
};


struct label_t {
  Label type;
  int x = -1;
  int y = -1;
  int orientation = -1;
  int dimension = -1;
  std::string shape;
  std::string text;

  std::string toString(int indent = 0);
};

struct field_t {
  int num = -1;
  std::string text;
  Orientation orientation = Orientation::HORIZONTAL;
  int x = -1;
  int y = -1;
  int size = 50;
  std::string flags = "0000";
  std::string justification = "C";
  std::string style = "CNN";

  static field_t
  fromLibraryField(const lib_field_t& lib_field, int num, const std::string& text, int offset_x,
      int offset_y);
  std::string toString(int indent = 0);
};

constexpr const char* DEFAULT_FOOTER = "\t1    2600 1750\n\t1    0    0    -1\n";

struct sheet_component_t {
  std::string name;
  std::string ref;
  int subcomponent = -1;
  std::string timestamp;
  int x = -1;
  int y = -1;
  std::vector<field_t> fields;
  std::string footer = DEFAULT_FOOTER;

  std::string toString(int indent = 0);
};

constexpr const char* DEFAULT_HEADER1 =
    "EESchema Schematic File Version 4\nLIBS:full_adder-cache\n"
    "EELAYER 29 0\nEELAYER END\n$Descr A3 16535 11693\nencoding utf-8\n";

constexpr const char* DEFAULT_HEADER2 =
    "Date \"\"\nRev \"\"\nComp \"\"\nComment1 \"\"\nComment2 \"\"\n"
    "Comment3 \"\"\nComment4 \"\"\n$EndDescr\n";

struct sheet_t {
  std::string header1 = DEFAULT_HEADER1;
  int id;
  std::string title;
  std::string header2 = DEFAULT_HEADER2;
  std::vector<sheet_component_t> components;
  std::vector<label_t> labels;

  std::string toString(int indent = 0);
};

std::ostream& operator<<(std::ostream& str, const Orientation& o);
std::istream& operator>>(std::istream& str, Orientation& o);

std::ostream& operator<<(std::ostream& str, const Label& o);
std::istream& operator>>(std::istream& str, Label& o);

std::ostream& operator<<(std::ostream& str, const Direction& o);
std::istream& operator>>(std::istream& str, Direction& o);

std::ostream& operator<<(std::ostream& str, const UnitSwappable& o);
std::istream& operator>>(std::istream& str, UnitSwappable& o);

std::ostream& operator<<(std::ostream& str, const ElectricalType& o);
std::istream& operator>>(std::istream& str, ElectricalType& o);

}  // memecad

#endif  // VERYMEME_MEMECAD_TYPES_H
