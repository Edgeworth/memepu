#ifndef VERYMEME_KICAD_PARSER_H
#define VERYMEME_KICAD_PARSER_H

#include <string>

#include "common.h"

namespace kicad {

enum class Orientation {
  HORIZONTAL, VERTICAL
};

std::ostream& operator<<(std::ostream& str, const Orientation& o);
std::istream& operator>>(std::istream& str, Orientation& o);

enum class Label {
  GLOBAL, HIERARCHICAL, LOCAL, NOTES
};

std::ostream& operator<<(std::ostream& str, const Label& o);
std::istream& operator>>(std::istream& str, Label& o);

enum class Direction {
  LEFT, RIGHT, UP, DOWN
};

std::ostream& operator<<(std::ostream& str, const Direction& o);
std::istream& operator>>(std::istream& str, Direction& o);

enum class UnitSwappable {
  SWAPPABLE, UNSWAPPABLE
};

std::ostream& operator<<(std::ostream& str, const UnitSwappable& o);
std::istream& operator>>(std::istream& str, UnitSwappable& o);


struct label_t {
  Label type;
  int x;
  int y;
  int orientation;
  int dimension;
  std::string shape;
  std::string text;
};

struct field_t {
  int num;
  std::string text;
  Orientation orientation;
  int x;
  int y;
  int size;
  int flags;
  std::string justification;
  std::string style;
};

struct component_t {
  std::string name;
  std::string ref;
  int subcomponent;
  std::string timestamp;
  int x;
  int y;
  std::vector<field_t> fields;
};

struct sheet_t {
  int id;
  std::string title;
  std::vector<component_t> components;
  std::vector<label_t> labels;
};

struct pin_t {
  std::string name;
  int x;
  int y;
  Direction direction;
  int unit_number;
};

struct lib_component_t {
  std::string name;
  std::string ref;
  int unit_count;
  UnitSwappable unit_swappable;
  std::vector<pin_t> pins;
};

struct library_t {
  std::vector<lib_component_t> components;
};

sheet_t parseSheet(const std::string& filename);

library_t parseLibrary(const std::string& filename);

}  // kicad

#endif  // VERYMEME_KICAD_PARSER_H
