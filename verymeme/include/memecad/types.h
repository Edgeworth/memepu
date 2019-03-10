#ifndef VERYMEME_MEMECAD_TYPES_H
#define VERYMEME_MEMECAD_TYPES_H

#include <vector>
#include <string>

#include "common.h"

namespace memecad {

enum class Orientation {
  HORIZONTAL, VERTICAL
};

enum class Label {
  GLOBAL, HIERARCHICAL, LOCAL, NOTES
};

enum class Direction {
  LEFT, RIGHT, UP, DOWN
};

enum class UnitSwappable {
  SWAPPABLE, UNSWAPPABLE
};

struct label_t {
  Label type;
  int x;
  int y;
  int orientation;
  int dimension;
  std::string shape;
  std::string text;

  std::string toString(int indent = 0);
};

struct field_t {
  int num;
  std::string text;
  Orientation orientation;
  int x;
  int y;
  int size;
  std::string flags;
  std::string justification;
  std::string style;

  std::string toString(int indent = 0);
};

struct component_t {
  std::string name;
  std::string ref;
  int subcomponent;
  std::string timestamp;
  int x;
  int y;
  std::vector<field_t> fields;
  std::string footer;

  std::string toString(int indent = 0);
};

struct sheet_t {
  std::string header1;
  int id;
  std::string title;
  std::string header2;
  std::vector<component_t> components;
  std::vector<label_t> labels;

  std::string toString(int indent = 0);
};

struct pin_t {
  std::string name;
  int x;
  int y;
  Direction direction;
  int unit_number;

  std::string toString(int indent = 0);
};

struct lib_component_t {
  std::string name;
  std::string ref;
  int unit_count;
  UnitSwappable unit_swappable;
  std::vector<pin_t> pins;

  std::string toString(int indent = 0);
};

struct library_t {
  std::vector<lib_component_t> components;

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

}  // memecad

#endif  // VERYMEME_MEMECAD_TYPES_H
