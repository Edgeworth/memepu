#include "memecad/parser.h"
#include "verymeme/parser.h"

#include <regex>
#include <boost/lexical_cast.hpp>

namespace memecad {

namespace {

// Token is either: Empty quotes, quoted string, non space/tab/newline string, newline, tab.
const std::regex TOKEN(R"((\".*?[^\\]\")|(\"\")|([^ \t\n]+)|(\n)|(\t))");

int directionToLabelOrientation(Direction d, Sheet::Label::Type label_type) {
  const bool is_hierarchical_or_global =
      label_type == Sheet::Label::Type::HIERARCHICAL || label_type == Sheet::Label::Type::GLOBAL;
  switch (d) {
    case Direction::LEFT:
      return is_hierarchical_or_global ? 0 : 2;
    case Direction::DOWN:
      return 3;
    case Direction::RIGHT:
      return is_hierarchical_or_global ? 2 : 0;
    case Direction::UP:
      return 1;
    default:
      verify_expr(false, "unknown direction '%d'", int(d));
  }
}

Direction labelOrientationToDirection(int orientation, Sheet::Label::Type label_type) {
  for (int d = 0; d < int(Direction::COUNT); ++d) {
    if (directionToLabelOrientation(Direction(d), label_type) == orientation)
      return Direction(d);
  }
  verify_expr(false, "unknown label orientation %d", orientation);
}

class KicadParser {
public:
  explicit KicadParser(const std::string& data) : p_(data, TOKEN) {}

  Sheet parseSheet() {
    Sheet sheet = {};
    sheet.header1 = p_.getLines(6);
    p_.expect({"Sheet", "1"});
    sheet.id = p_.next<int>();
    p_.expect({"\n", "Title"});
    sheet.title = trim(p_.next(), "\"");
    p_.expect({"\n"});
    sheet.header2 = p_.getLines(8);
    while (true) {
      std::string tok = p_.next();
      if (tok == "$EndSCHEMATC") break;
      else if (tok == "$Comp") sheet.components.emplace_back(parseComponent());
      else if (tok == "Text") {
        auto& label = sheet.labels.emplace_back();
        label.type = p_.next<Sheet::Label::Type>();
        label.p = {p_.next<int>(), p_.next<int>()};
        label.direction = labelOrientationToDirection(p_.next<int>(), label.type);
        label.dimension = p_.next<int>();
        if (label.type == Sheet::Label::Type::HIERARCHICAL ||
            label.type == Sheet::Label::Type::GLOBAL)
          label.net_type = p_.next<Sheet::Label::NetType>();
        label.italic = p_.next() == "Italic";
        label.bold = p_.next() != "0";
        p_.expect({"\n"});
        label.text = trim(p_.getLines(1), "\\n");
      } else if (tok == "NoConn") {
        auto& label = sheet.labels.emplace_back();
        label.type = Sheet::Label::Type::NOCONNECT;
        p_.expect({"~"});
        label.p = {p_.next<int>(), p_.next<int>()};
        p_.expect({"\n"});
      } else if (tok == "Wire") {
        p_.expect({"Wire", "Line", "\n", "\t"});
        auto& wire = sheet.wires.emplace_back();
        wire.start = {p_.next<int>(), p_.next<int>()};
        wire.end = {p_.next<int>(), p_.next<int>()};
        p_.expect({"\n"});
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
    while (p_.hasTokens()) {
      std::string tok = p_.peek();
      if (tok == "DEF") {
        lib.components.push_back(parseLibraryComponent());
      } else {
        p_.getLines(1);  // Skip
      }
    }
    return lib;
  }

private:
  Parser p_;

  Sheet::Component parseComponent() {
    Sheet::Component comp;
    p_.expect({"\n", "L"});
    comp.name = p_.next();
    comp.ref = p_.next();
    p_.expect({"\n", "U"});
    comp.subcomponent = p_.next<int>() - 1;
    p_.expect({"1"});
    comp.timestamp = p_.next();
    p_.expect({"\n", "P"});
    comp.p = {p_.next<int>(), p_.next<int>()};
    p_.expect({"\n"});
    while (true) {
      std::string tok = p_.peek();
      if (tok == "F") {
        auto& field = comp.fields.emplace_back();
        p_.expect({"F"});
        field.num = p_.next<int>();
        field.text = trim(p_.next(), "\"");
        field.orientation = p_.next<Orientation>();
        field.p = {p_.next<int>(), p_.next<int>()};
        field.size = p_.next<int>();
        field.flags = p_.next();
        field.justification = p_.next();
        field.style = p_.next();
        p_.expect({"\n"});
      } else if (tok == "\t") {
        comp.footer = p_.getLines(2);
        p_.expect({"$EndComp", "\n"});
        break;
      } else {
        verify_expr(false, "unexpected token '%s'", tok.c_str());
      }
    }
    return comp;
  }

  Sheet::Ref parseSheetRef() {
    Sheet::Ref ref;
    p_.expect({"\n", "S"});
    ref.p = {p_.next<int>(), p_.next<int>()};
    ref.width = p_.next<int>();
    ref.height = p_.next<int>();
    p_.expect({"\n", "U"});
    ref.timestamp = p_.next();
    p_.expect({"\n", "F0"});
    ref.name = trim(p_.next(), "\"");
    p_.next();  // Name dimension.
    p_.expect({"\n", "F1"});
    ref.filename = trim(p_.next(), "\"");
    p_.next();  // Filename dimension.
    p_.expect({"\n"});
    while (true) {
      std::string tok = p_.next();
      if (tok == "$EndSheet") break;

      Sheet::RefField& field = ref.fields.emplace_back();
      field.num = boost::lexical_cast<int>(tok.c_str() + 1);
      field.text = trim(p_.next(), "\"");
      field.type = p_.next<PinType>();
      field.side = p_.next<Direction>();
      field.p = {p_.next<int>(), p_.next<int>()};
      p_.next();  // Label dimension.
      p_.expect({"\n"});
    }
    p_.expect({"\n"});
    return ref;
  }

  Lib::Component parseLibraryComponent() {
    Lib::Component component = {};
    p_.expect({"DEF"});
    component.names.push_back(p_.next());
    component.ref = p_.next();
    p_.expect({"0"});  // Unused.
    p_.next();
    p_.next();
    p_.next();  // Text offset, draw pin number, draw pin name.
    component.unit_count = p_.next<int>();
    component.unit_swappable = p_.next<Lib::Component::UnitSwappable>();
    p_.getLines(1);  // Ignore rest.
    while (true) {
      std::string tok = p_.next();
      if (tok == "ENDDEF") break;
      else if (tok == "F0" || tok == "F1") {
        // Record reference and value fields.
        auto& field = component.fields.emplace_back();
        field.num = boost::lexical_cast<int>(tok.substr(1));
        field.text = trim(p_.next(), "\"");
        field.p = {p_.next<int>(), -p_.next<int>()}; // Seems like y-axis is inverted for libraries.
        field.text_size = p_.next<int>();
        field.text_orientation = p_.next<Orientation>();
        p_.next();  // Skip visibility.
        field.horizontal_justification = p_.next();
        field.vertical_justification = p_.next();
        p_.expect({"\n"});
      } else if (tok == "ALIAS") {
        for (std::string name = p_.next(); name != "\n"; name = p_.next())
          component.names.push_back(name);
      } else if (tok == "X") {
        auto& pin = component.pins.emplace_back();
        pin.name = p_.next();
        pin.id = p_.next();
        pin.p = {p_.next<int>(), -p_.next<int>()}; // Seems like y-axis is inverted for libraries.
        p_.next(); // Length
        pin.direction = p_.next<Direction>();
        p_.next();
        p_.next();  // Name text size, num text size.
        pin.subcomponent = p_.next<int>() - 1;
        // TODO: Pins common to all subcomponents (==0) are just put in the first one for now.
        if (pin.subcomponent == -1) pin.subcomponent = 0;
        p_.next();  // convert
        pin.type = p_.next<PinType>();
        p_.getLines(1); // Ignore rest.
      }
    }
    p_.expect({"\n"});
    return component;
  }
};

class KicadWriter {
public:
  std::string writeSheet(Sheet sheet) {
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

private:
};

}  // namespace

Sheet parseSheet(const std::string& data) {
  try {
    return KicadParser(data).parseSheet();
  } catch (const std::exception& e) {
    verify_expr(false, "failed exception: %s", e.what());
  }
}

Lib parseLibrary(const std::string& data, const std::string& name) {
  try {
    return KicadParser(data).parseLibrary(name);
  } catch (const std::exception& e) {
    verify_expr(false, "failed exception: %s", e.what());
  }
}

std::string writeSheet(const Sheet& sheet) {
  try {
    return KicadWriter().writeSheet(sheet);
  } catch (const std::exception& e) {
    verify_expr(false, "failed exception: %s", e.what());
  }
}

}  // memecad
