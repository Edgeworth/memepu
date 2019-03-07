#include <regex>

#include "kicad_parser.h"

namespace kicad {

void printPin(pin_t& pin, int i);
namespace {

// Sheet regexes
const std::regex SHEET(R"(^Sheet\s+(\S+))");
const std::regex TITLE(R"_(^Title\s+"([^"]*)")_");
const std::regex COMP(R"(^\$Comp)");
const std::regex COMP_L(R"_(^L\s+(\S+)\s+(\S+))_");
const std::regex COMP_U(R"_(^U\s+(\S+)\s+\S+\s+(\S+))_");
const std::regex COMP_P(R"_(^P\s+(\S+)\s+(\S+))_");
const std::regex COMP_F(
    R"_(^F\s+(\S+)\s+"(\S*)"\s+(\S+)\s+(\S+)\s+(\S+)\s+(\S+)\s+(\S+)\s+(\S+)\s+(\S+))_");
const std::regex COMP_END(R"(^\$EndComp)");
const std::regex SHEET_IGNORE(
    R"(^(EESchema)|(LIBS)|(EELAYER)|(\$Descr)|(encoding)|(Date)|(Rev)|(Comp)|(Comment)|(\$EndDescr)|(\t)|(\$EndSCHEMATC))");
const std::regex TEXT(R"(^Text\s+(\S+)\s+(\S+)\s+(\S+)\s+(\S+)\s+(\S+)\s+(\S+))");

// Library regexes
const std::regex LIB_IGNORE(
    R"(^(EESchema)|(#)|(F0)|(F1)|(F2)|(F3)|(DRAW)|(ENDDRAW)|(A )|(P )|(C )|(S )|(T ))");
const std::regex LIB_FPLIST(R"(^\$FPLIST)");
const std::regex LIB_ENDFPLIST(R"(^\$ENDFPLIST)");
const std::regex DEF(R"(^DEF\s+(\S+)\s+(\S+)\s+\S+\s+\S+\s+\S+\s+\S+\s+(\S+)\s+(\S+))");
const std::regex DEF_END(R"(^ENDDEF)");
const std::regex DEF_PIN(R"(^X\s+(\S+)\s+\S+\s+(\S+)\s+(\S+)\s+\S+\s+(\S+)\s+\S+\s+\S+\s+(\S+))");

#define PRINT_FIELD(f) \
  printIndent(indent); \
  printf("%s: %s\n", #f, boost::lexical_cast<std::string>(v.f).c_str());

void printIndent(int indent) {
  std::string spaces(indent, ' ');
  printf("%s", spaces.c_str());
}

void printField(const field_t& v, int indent) {
  PRINT_FIELD(num);
  PRINT_FIELD(text);
  PRINT_FIELD(orientation);
  PRINT_FIELD(x);
  PRINT_FIELD(y);
  PRINT_FIELD(size);
  PRINT_FIELD(flags);
  PRINT_FIELD(justification);
  PRINT_FIELD(style);
}

void printComponent(const component_t& v, int indent) {
  PRINT_FIELD(name);
  PRINT_FIELD(ref);
  PRINT_FIELD(subcomponent);
  PRINT_FIELD(timestamp);
  PRINT_FIELD(x);
  PRINT_FIELD(y);
  for (int i = 0; i < int(v.fields.size()); ++i) {
    printIndent(indent);
    printf("Field #%d:\n", i + 1);
    printField(v.fields[i], indent + 2);
  }
}

void printLabel(const label_t& v, int indent) {
  PRINT_FIELD(type);
  PRINT_FIELD(x);
  PRINT_FIELD(y);
  PRINT_FIELD(orientation);
  PRINT_FIELD(dimension);
  PRINT_FIELD(shape);
  PRINT_FIELD(text);
}

void printSheet(const sheet_t& v, int indent = 0) {
  PRINT_FIELD(id);
  PRINT_FIELD(title);
  for (int i = 0; i < int(v.components.size()); ++i) {
    printf("Component #%d\n", i + 1);
    printComponent(v.components[i], 2);
  }
  for (int i = 0; i < int(v.labels.size()); ++i) {
    printf("Label #%d\n", i + 1);
    printLabel(v.labels[i], 2);
  }
}

void printPin(const pin_t& v, int indent) {
  PRINT_FIELD(name);
  PRINT_FIELD(x);
  PRINT_FIELD(y);
  PRINT_FIELD(direction);
  PRINT_FIELD(unit_number);
}

void printLibraryComponent(const lib_component_t& v, int indent) {
  PRINT_FIELD(name);
  PRINT_FIELD(ref);
  PRINT_FIELD(unit_count);
  PRINT_FIELD(unit_swappable);
  for (int i = 0; i < int(v.pins.size()); ++i) {
    printIndent(indent);
    printf("Pin #%d:\n", i + 1);
    printPin(v.pins[i], indent + 2);
  }
}

void printLibrary(const library_t& v) {
  for (int i = 0; i < int(v.components.size()); ++i) {
    printf("Library component #%d:\n", i + 1);
    printLibraryComponent(v.components[i], 2);
  }
}

#undef PRINT_FIELD

class KicadParser {
public:
  explicit KicadParser(std::vector<std::string>&& lines) : lines_(std::move(lines)) {}

  sheet_t parseSheet() {
    sheet_t sheet = {};
    for (; idx_ < int(lines_.size()); ++idx_) {
      if (peek(COMP)) sheet.components.push_back(parseComponent());
      else if (peek(SHEET)) sheet.id = grabOne<int>(SHEET, "missing sheet");
      else if (peek(TITLE)) sheet.title = grabString(TITLE, "missing title");
      else if (peek(SHEET_IGNORE)) continue;
      else if (peek(TEXT)) {
        label_t l;
        std::tie(l.type, l.x, l.y, l.orientation, l.dimension,
            l.shape) = grab<Label, int, int, int, int, std::string>(TEXT, "invalid label");
        verify_expr(++idx_ < int(lines_.size()), "no label text");
        l.text = lines_[idx_];
        sheet.labels.push_back(l);
      } else
        verify_expr(false, "unrecognised line: %s", lines_[idx_].c_str());
    }
    printSheet(sheet);
    return sheet;
  }

  library_t parseLibrary() {
    library_t lib = {};
    for (; idx_ < int(lines_.size()); ++idx_) {
      if (peek(DEF)) lib.components.push_back(parseLibraryComponent());
      else if (peek(LIB_IGNORE)) continue;
      else
        verify_expr(false, "unrecognised line: %s", lines_[idx_].c_str());
    }
    printLibrary(lib);
    return lib;
  }

private:
  std::vector<std::string> lines_;
  int idx_ = 0;

  lib_component_t parseLibraryComponent() {
    lib_component_t component = {};
    for (; idx_ < int(lines_.size()) && !peek(DEF_END); ++idx_) {
      if (peek(DEF_PIN)) {
        pin_t pin;
        std::tie(pin.name, pin.x, pin.y, pin.direction,
            pin.unit_number) = grab<std::string, int, int, Direction, int>(DEF_PIN, "invalid pin");
        component.pins.push_back(pin);
      } else if (peek(DEF)) {
        std::tie(component.name, component.ref, component.unit_count, component.unit_swappable) =
            grab<std::string, std::string, int, UnitSwappable>(DEF, "invalid library component");
      } else if (peek(LIB_IGNORE)) continue;
      else if (peek(LIB_FPLIST)) {
        while (idx_ < int(lines_.size()) && !peek(LIB_ENDFPLIST)) idx_++;
      } else {
        verify_expr(false, "unrecognised line in library component: %s", lines_[idx_].c_str());
      }
    }
    return component;
  }

  component_t parseComponent() {
    component_t component;
    idx_++;  // Skip $Comp
    for (; idx_ < int(lines_.size()) && !peek(COMP_END); ++idx_) {
      if (peek(COMP_F)) {
        field_t f;
        std::tie(f.num, f.text, f.orientation, f.x, f.y, f.size, f.flags, f.justification,
            f.style) = grab<int, std::string, Orientation, int, int, int, int, std::string, std::string>(
            COMP_F, "no field");
        component.fields.push_back(f);
      } else if (peek(COMP_L)) {
        std::tie(component.name, component.ref) = grabStrings<2>(COMP_L, "no name+ref");
      } else if (peek(COMP_U)) {
        std::tie(component.subcomponent, component.timestamp) = grab<int, std::string>(COMP_U,
            "no subcomponent and timestamp");
      } else if (peek(COMP_P)) {
        std::tie(component.x, component.y) = grab<int, 2>(COMP_P, "no x/y pos");
      } else if (peek(SHEET_IGNORE)) continue;
      else {
        verify_expr(false, "unrecognised line in component: %s", lines_[idx_].c_str());
      }
    }
    return component;
  }

  bool peek(const std::regex& rx) {
    return std::regex_search(lines_[idx_], rx);
  }

  std::smatch grabMatch(const std::regex& rx, const char* message, int num_matches = 0) {
    std::smatch sm;
    verify_expr(std::regex_search(lines_[idx_], sm, rx), "%s", message);
    verify_expr(num_matches == int(sm.size()) - 1, "wrong number of matches (bug), %s", message);
    return sm;
  }

  template<typename... Ts>
  std::tuple<Ts...> grab(const std::regex& rx, const char* message) {
    std::smatch sm = grabMatch(rx, message, sizeof...(Ts));
    return cast_t<Ts...>::apply([&sm](int i) { return sm[i + 1].str(); });
  }


  template<typename T, int N>
  sized_tuple<T, N> grab(const std::regex& rx, const char* message) {
    std::smatch sm = grabMatch(rx, message, N);
    return pack_functor<sized_tuple<T, N>, cast_t>::apply([&sm](int i) { return sm[i + 1].str(); });
  }

  template<int N>
  sized_tuple<std::string, N> grabStrings(const std::regex& rx, const char* message) {
    return grab<std::string, N>(rx, message);
  }

  template<typename T>
  T grabOne(const std::regex& rx, const char* message) {
    return std::get<0>(grab<T>(rx, message));
  }

  std::string grabString(const std::regex& rx, const char* message) {
    return grabOne<std::string>(rx, message);
  }
};

class KicadWriter {
public:
  std::string writeSheet(const sheet_t& sheet) {
    std::string data;
    data += "EESchema Schematic File Version 4\n";
    data += "$Descr A3 0 0\nencoding utf-8\nSheet 1 1\nTitle \"";
    data += sheet.title;
    data += "\"\nDate \"\"\nRev \"\"\n";
    data += "Comp \"\"\nComment1 \"\"\nComment2 \"\"\nComment3 \"\"\nComment4 \"\"$EndDescr\n";
    for (const auto& component : sheet.components) {
      // TODO
    }
    // TODO return
  }
};

}  // namespace

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

sheet_t parseSheet(const std::string& filename) {
  return KicadParser(::split(readFile(filename, false /* binary */), '\n')).parseSheet();
}

void writeSheet(const sheet_t& sheet, const std::string& filename) {
  writeFile(filename, KicadWriter().writeSheet(sheet), false /* binary */);
}


library_t parseLibrary(const std::string& filename) {
  return KicadParser(::split(readFile(filename, false /* binary */), '\n')).parseLibrary();
}

}  // kicad