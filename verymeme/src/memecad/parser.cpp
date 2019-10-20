#include "memecad/parser.h"

#include <boost/lexical_cast.hpp>
#include <regex>

#include "verymeme/string_util.h"
#include "verymeme/tokeniser.h"

namespace memecad {

namespace {

// Token is either: Empty quotes, quoted string, non space/tab/newline string, newline, tab.
const std::regex TOKEN(R"((\".*?[^\\]\")|(\"\")|([^ \t\n]+)|(\n)|(\t))");

int directionToLabelOrientation(Direction d, Sheet::Label::Type label_type) {
  const bool is_hierarchical_or_global =
      label_type == Sheet::Label::Type::HIERARCHICAL || label_type == Sheet::Label::Type::GLOBAL;
  switch (d) {
  case Direction::LEFT: return is_hierarchical_or_global ? 0 : 2;
  case Direction::DOWN: return 3;
  case Direction::RIGHT: return is_hierarchical_or_global ? 2 : 0;
  case Direction::UP: return 1;
  default: verify_expr(false, "unknown direction '%d'", int(d));
  }
}

Direction labelOrientationToDirection(int orientation, Sheet::Label::Type label_type) {
  for (int d = 0; d < int(Direction::COUNT); ++d) {
    if (directionToLabelOrientation(Direction(d), label_type) == orientation) return Direction(d);
  }
  verify_expr(false, "unknown label orientation %d", orientation);
}

class KicadParser {
public:
  explicit KicadParser(const std::string& data) : t_(data, TOKEN) {}

  Sheet parseSheet() {
    Sheet sheet = {};
    sheet.header1 = t_.lines(6);
    t_.expect({"Sheet", "1"});
    sheet.id = t_.next<int>();
    t_.expect({"\n", "Title"});
    sheet.title = trim(t_.next(), "\"");
    t_.expect({"\n"});
    sheet.header2 = t_.lines(8);
    while (true) {
      std::string tok = t_.next();
      if (tok == "$EndSCHEMATC") break;
      else if (tok == "$Comp")
        sheet.components.emplace_back(parseComponent());
      else if (tok == "Text") {
        auto& label = sheet.labels.emplace_back();
        label.type = t_.next<Sheet::Label::Type>();
        label.p = {t_.next<int>(), t_.next<int>()};
        label.direction = labelOrientationToDirection(t_.next<int>(), label.type);
        label.dimension = t_.next<int>();
        if (label.type == Sheet::Label::Type::HIERARCHICAL ||
            label.type == Sheet::Label::Type::GLOBAL)
          label.net_type = t_.next<Sheet::Label::NetType>();
        label.italic = t_.next() == "Italic";
        label.bold = t_.next() != "0";
        t_.expect({"\n"});
        label.text = trim(t_.lines(1), "\\n");
      } else if (tok == "NoConn") {
        auto& label = sheet.labels.emplace_back();
        label.type = Sheet::Label::Type::NOCONNECT;
        t_.expect({"~"});
        label.p = {t_.next<int>(), t_.next<int>()};
        t_.expect({"\n"});
      } else if (tok == "Wire") {
        t_.expect({"Wire", "Line", "\n", "\t"});
        auto& wire = sheet.wires.emplace_back();
        wire.start = {t_.next<int>(), t_.next<int>()};
        wire.end = {t_.next<int>(), t_.next<int>()};
        t_.expect({"\n"});
      } else if (tok == "$Sheet") {
        sheet.refs.emplace_back(parseSheetRef());
      } else {
        verify_expr(false, "unexpected token '%s'", tok.c_str());
      }
    }
    return sheet;
  }

  Lib parseLibrary(const std::string& name) {
    Lib lib = {};
    lib.name = name;
    while (t_.hasTokens()) {
      std::string tok = t_.peek();
      if (tok == "DEF") {
        lib.components.push_back(parseLibraryComponent());
      } else {
        t_.lines(1);  // Skip
      }
    }
    return lib;
  }

private:
  Tokeniser t_;

  Sheet::Component parseComponent() {
    Sheet::Component comp;
    t_.expect({"\n", "L"});
    comp.name = t_.next();
    comp.ref = t_.next();
    t_.expect({"\n", "U"});
    comp.subcomponent = t_.next<int>() - 1;
    t_.expect({"1"});
    comp.timestamp = t_.next();
    t_.expect({"\n", "P"});
    comp.p = {t_.next<int>(), t_.next<int>()};
    t_.expect({"\n"});
    while (true) {
      std::string tok = t_.peek();
      if (tok == "F") {
        auto& field = comp.fields.emplace_back();
        t_.expect({"F"});
        field.num = t_.next<int>();
        field.text = trim(t_.next(), "\"");
        field.orientation = t_.next<Orientation>();
        field.p = {t_.next<int>(), t_.next<int>()};
        field.size = t_.next<int>();
        field.flags = t_.next();
        field.justification = t_.next();
        field.style = t_.next();
        t_.expect({"\n"});
      } else if (tok == "\t") {
        comp.footer = t_.lines(2);
        t_.expect({"$EndComp", "\n"});
        break;
      } else {
        verify_expr(false, "unexpected token '%s'", tok.c_str());
      }
    }
    return comp;
  }

  Sheet::Ref parseSheetRef() {
    Sheet::Ref ref;
    t_.expect({"\n", "S"});
    ref.p = {t_.next<int>(), t_.next<int>()};
    ref.width = t_.next<int>();
    ref.height = t_.next<int>();
    t_.expect({"\n", "U"});
    ref.timestamp = t_.next();
    t_.expect({"\n", "F0"});
    ref.name = trim(t_.next(), "\"");
    t_.next();  // Name dimension.
    t_.expect({"\n", "F1"});
    ref.filename = trim(t_.next(), "\"");
    t_.next();  // Filename dimension.
    t_.expect({"\n"});
    while (true) {
      std::string tok = t_.next();
      if (tok == "$EndSheet") break;

      Sheet::RefField& field = ref.fields.emplace_back();
      field.num = boost::lexical_cast<int>(tok.c_str() + 1);
      field.text = trim(t_.next(), "\"");
      field.type = t_.next<PinType>();
      field.side = t_.next<Direction>();
      field.p = {t_.next<int>(), t_.next<int>()};
      t_.next();  // Label dimension.
      t_.expect({"\n"});
    }
    t_.expect({"\n"});
    return ref;
  }

  Lib::Component parseLibraryComponent() {
    Lib::Component component = {};
    t_.expect({"DEF"});
    component.names.push_back(t_.next());
    component.ref = t_.next();
    t_.expect({"0"});  // Unused.
    t_.next();
    t_.next();
    t_.next();  // Text offset, draw pin number, draw pin name.
    component.unit_count = t_.next<int>();
    component.unit_swappable = t_.next<Lib::Component::UnitSwappable>();
    t_.lines(1);  // Ignore rest.
    while (true) {
      std::string tok = t_.next();
      if (tok == "ENDDEF") break;
      else if (tok == "F0" || tok == "F1") {
        // Record reference and value fields.
        auto& field = component.fields.emplace_back();
        field.num = boost::lexical_cast<int>(tok.substr(1));
        field.text = trim(t_.next(), "\"");
        field.p = {
            t_.next<int>(), -t_.next<int>()};  // Seems like y-axis is inverted for libraries.
        field.text_size = t_.next<int>();
        field.text_orientation = t_.next<Orientation>();
        t_.next();  // Skip visibility.
        field.horizontal_justification = t_.next();
        field.vertical_justification = t_.next();
        t_.expect({"\n"});
      } else if (tok == "ALIAS") {
        for (std::string name = t_.next(); name != "\n"; name = t_.next())
          component.names.push_back(name);
      } else if (tok == "X") {
        auto& pin = component.pins.emplace_back();
        pin.name = t_.next();
        pin.id = t_.next();
        pin.p = {t_.next<int>(), -t_.next<int>()};  // Seems like y-axis is inverted for libraries.
        t_.next();  // Length
        pin.direction = t_.next<Direction>();
        t_.next();
        t_.next();  // Name text size, num text size.
        pin.subcomponent = t_.next<int>() - 1;
        // TODO(improvement): Pins common to all subcomponents (==0) are just put in the first one
        // for now.
        if (pin.subcomponent == -1) pin.subcomponent = 0;
        t_.next();  // convert
        pin.type = t_.next<PinType>();
        t_.lines(1);  // Ignore rest.
      }
    }
    t_.expect({"\n"});
    return component;
  }
};

class KicadWriter {
public:
  static std::string writeSheet(Sheet sheet) {
    std::string data;
    data += sheet.header1;
    data += "Sheet 1 " + tos(sheet.id) + "\n";
    data += "Title \"" + sheet.title + "\"\n";
    data += sheet.header2;

    // Sort children to maintain a consistent order for tests.
    std::sort(sheet.components.begin(), sheet.components.end());
    for (const auto& comp : sheet.components) {
      data += "$Comp\n";
      data += "L " + comp.name + " " + comp.ref + "\n";
      data += "U " + tos(comp.subcomponent + 1) + " 1 " + comp.timestamp + "\n";
      data += "P " + tos(comp.p) + "\n";
      for (const auto& f : comp.fields) {
        data += "F " + tos(f.num) + " \"" + f.text + "\" " + tos(f.orientation) + " " + tos(f.p) +
            " " + tos(f.size) + " " + f.flags + " " + f.justification + " " + f.style + "\n";
      }
      data += comp.footer;
      data += "$EndComp\n";
    }

    std::sort(sheet.labels.begin(), sheet.labels.end());
    for (const auto& l : sheet.labels) {
      if (l.type == Sheet::Label::Type::NOCONNECT) {
        data += "NoConn ~ " + tos(l.p) + "\n";
        continue;
      }
      data += "Text " + tos(l.type) + " " + tos(l.p) + " " +
          tos(directionToLabelOrientation(l.direction, l.type)) + " " + tos(l.dimension) + " ";
      if (l.type == Sheet::Label::Type::HIERARCHICAL || l.type == Sheet::Label::Type::GLOBAL)
        data += tos(l.net_type) + " ";
      data += std::string(l.italic ? "Italic" : "~") + " " + (l.bold ? "10" : "0") + "\n";
      data += l.text + "\n";
    }

    std::sort(sheet.wires.begin(), sheet.wires.end());
    for (const auto& w : sheet.wires)
      data += "Wire Wire Line\n\t" + tos(w.start) + " " + tos(w.end) + "\n";

    std::sort(sheet.refs.begin(), sheet.refs.end());
    for (const auto& r : sheet.refs) {
      data += "$Sheet\n";
      data += "S " + tos(r.p) + " " + tos(r.width) + " " + tos(r.height) + "\n";
      data += "U " + r.timestamp + "\n";
      data += "F0 \"" + r.name + "\" 50\n";
      data += "F1 \"" + r.filename + "\" 50\n";
      for (const auto& f : r.fields) {
        data += "F" + tos(f.num) + " \"" + f.text + "\" " + tos(f.type) + " " + tos(f.side) + " " +
            tos(f.p) + " 50\n";
      }
      data += "$EndSheet\n";
    }

    data += "$EndSCHEMATC\n";
    return data;
  }
};

}  // namespace

Sheet parseSheet(const std::string& data) {
  try {
    return KicadParser(data).parseSheet();
  } catch (const std::exception& e) { verify_expr(false, "failed exception: %s", e.what()); }
}

Lib parseLibrary(const std::string& data, const std::string& name) {
  try {
    return KicadParser(data).parseLibrary(name);
  } catch (const std::exception& e) { verify_expr(false, "failed exception: %s", e.what()); }
}

std::string writeSheet(const Sheet& sheet) {
  try {
    return KicadWriter::writeSheet(sheet);
  } catch (const std::exception& e) { verify_expr(false, "failed exception: %s", e.what()); }
}

}  // namespace memecad
