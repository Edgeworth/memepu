#include "memecad/parser.h"

#include <regex>
#include <boost/lexical_cast.hpp>

namespace memecad {

namespace {

std::vector<std::string> tokenize(const std::string& data) {
  // Token is either: Empty quotes, quoted string, non space/tab/newline string, newline, tab.
  const std::regex split(R"((\".*?[^\\]\")|(\"\")|([^ \t\n]+)|(\n)|(\t))");
  std::vector<std::string> toks;
  for (auto i = std::sregex_iterator(data.begin(), data.end(), split);
       i != std::sregex_iterator(); ++i) {
    const std::smatch& sm = *i;
    toks.push_back(sm[0].str());
  }
  return toks;
}

std::string trim(const std::string& data, const std::string& c) {
  const std::regex trim("^" + c + "*((\n|.)*?)" + c + "*$");
  std::smatch sm;
  verify_expr(std::regex_match(data, sm, trim), "BUG");
  return sm[1].str();
}

class KicadParser {
public:
  explicit KicadParser(const std::string& data) : toks_(tokenize(data)) {}

  Sheet parseSheet() {
    Sheet sheet = {};
    sheet.header1 = getLines(6);
    expect({"Sheet", "1"});
    sheet.id = next<int>();
    expect({"\n", "Title"});
    sheet.title = trim(next(), "\"");
    expect({"\n"});
    sheet.header2 = getLines(8);
    while (true) {
      std::string tok = next();
      if (tok == "$EndSCHEMATC") break;
      else if (tok == "$Comp") sheet.components.emplace_back(parseComponent());
      else if (tok == "Text") {
        auto& label = sheet.labels.emplace_back();
        label.type = next<Sheet::Label::Type>();
        label.p = {next<int>(), next<int>()};
        label.orientation = next<int>();
        label.dimension = next<int>();
        if (label.type == Sheet::Label::Type::HIERARCHICAL ||
            label.type == Sheet::Label::Type::GLOBAL)
          label.net_type = next<Sheet::Label::NetType>();
        label.italic = next() == "Italic";
        label.bold = next() != "0";
        expect({"\n"});
        label.text = trim(getLines(1), "\\n");
      } else if (tok == "NoConn") {
        auto& label = sheet.labels.emplace_back();
        label.type = Sheet::Label::Type::NOCONNECT;
        expect({"~"});
        label.p = {next<int>(), next<int>()};
        expect({"\n"});
      } else if (tok == "Wire") {
        expect({"Wire", "Line", "\n", "\t"});
        auto& wire = sheet.wires.emplace_back();
        wire.start = {next<int>(), next<int>()};
        wire.end = {next<int>(), next<int>()};
        expect({"\n"});
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
    while (idx_ < int(toks_.size())) {
      std::string tok = peek();
      if (tok == "DEF") {
        lib.components.push_back(parseLibraryComponent());
      } else {
        getLines(1);  // Skip
      }
    }
    return lib;
  }

private:
  std::vector<std::string> toks_;
  int idx_ = 0;

  Sheet::Component parseComponent() {
    Sheet::Component comp;
    expect({"\n", "L"});
    comp.name = next();
    comp.ref = next();
    expect({"\n", "U"});
    comp.subcomponent = next<int>() - 1;
    expect({"1"});
    comp.timestamp = next();
    expect({"\n", "P"});
    comp.p = {next<int>(), next<int>()};
    expect({"\n"});
    while (true) {
      std::string tok = peek();
      if (tok == "F") {
        auto& field = comp.fields.emplace_back();
        expect({"F"});
        field.num = next<int>();
        field.text = trim(next(), "\"");
        field.orientation = next<Orientation>();
        field.p = {next<int>(), next<int>()};
        field.size = next<int>();
        field.flags = next();
        field.justification = next();
        field.style = next();
        expect({"\n"});
      } else if (tok == "\t") {
        comp.footer = getLines(2);
        expect({"$EndComp", "\n"});
        break;
      } else {
        verify_expr(false, "unexpected token '%s'", tok.c_str());
      }
    }
    return comp;
  }

  Sheet::Ref parseSheetRef() {
    Sheet::Ref ref;
    expect({"\n", "S"});
    ref.p = {next<int>(), next<int>()};
    ref.width = next<int>();
    ref.height = next<int>();
    expect({"\n", "U"});
    ref.timestamp = next();
    expect({"\n", "F0"});
    ref.name = trim(next(), "\"");
    next();  // Name dimension.
    expect({"\n", "F1"});
    ref.filename = trim(next(), "\"");
    next();  // Filename dimension.
    expect({"\n"});
    while (true) {
      std::string tok = next();
      if (tok == "$EndSheet") break;

      Sheet::RefField& field = ref.fields.emplace_back();
      field.num = boost::lexical_cast<int>(tok.c_str() + 1);
      field.text = trim(next(), "\"");
      field.type = next<PinType>();
      field.side = next<Direction>();
      field.p = {next<int>(), next<int>()};
      next();  // Label dimension.
      expect({"\n"});
    }
    expect({"\n"});
    return ref;
  }

  template<typename T = std::string>
  T peek() {
    verify_expr(idx_ < int(toks_.size()), "expecting token");
    return boost::lexical_cast<T>(toks_[idx_]);
  }

  template<typename T = std::string>
  T next() {
    T value = peek<T>();
    idx_++;
    return value;
  }

  void expect(const std::vector<std::string>& toks) {
    for (const std::string& tok : toks) {
      const std::string next_tok = next();
      verify_expr(tok == next_tok, "expected '%s', got '%s'", tok.c_str(),
          next_tok.c_str());
    }
  }

  std::string getSubstr(int st, int en) {
    std::string substr;
    for (int i = st; i < en; ++i) {
      // Only separate by a space if there's at least one character accumulated, and it's:
      // 1. not already terminated with a newline (prevent space on next line)
      // 2. not about to be terminated with a newline (prevent space before newline)
      // 3. same two rules as above for tab.
      if (!substr.empty() && substr.back() != '\n' && toks_[i] != "\n" &&
          substr.back() != '\t' && toks_[i] != "\t")
        substr += ' ';
      substr += toks_[i];
    }
    return substr;
  }

  std::string getLines(int num_lines = 1) {
    const int start_idx = idx_;
    while (num_lines > 0)
      if (next() == "\n") num_lines--;
    return getSubstr(start_idx, idx_);
  }

  Lib::Component parseLibraryComponent() {
    Lib::Component component = {};
    expect({"DEF"});
    component.names.push_back(next());
    component.ref = next();
    expect({"0"});  // Unused.
    next();
    next();
    next();  // Text offset, draw pin number, draw pin name.
    component.unit_count = next<int>();
    component.unit_swappable = next<Lib::Component::UnitSwappable>();
    getLines(1);  // Ignore rest.
    while (true) {
      std::string tok = next();
      if (tok == "ENDDEF") break;
      else if (tok == "F0" || tok == "F1") {
        // Record reference and value fields.
        auto& field = component.fields.emplace_back();
        field.num = boost::lexical_cast<int>(tok.substr(1));
        field.text = trim(next(), "\"");
        field.p = {next<int>(), -next<int>()}; // Seems like y-axis is inverted for libraries.
        field.text_size = next<int>();
        field.text_orientation = next<Orientation>();
        next();  // Skip visibility.
        field.horizontal_justification = next();
        field.vertical_justification = next();
        expect({"\n"});
      } else if (tok == "ALIAS") {
        for (std::string name = next(); name != "\n"; name = next())
          component.names.push_back(name);
      } else if (tok == "X") {
        auto& pin = component.pins.emplace_back();
        pin.name = next();
        pin.pin_number = next<int>();
        pin.p = {next<int>(), -next<int>()}; // Seems like y-axis is inverted for libraries.
        next(); // Length
        pin.direction = next<Direction>();
        next();
        next();  // Name text size, num text size.
        pin.subcomponent = next<int>() - 1;
        next();  // convert
        pin.type = next<PinType>();
        getLines(1); // Ignore rest.
      }
    }
    expect({"\n"});
    return component;
  }
};

class KicadWriter {
public:
  std::string writeSheet(const Sheet& sheet) {
    std::string data;
    data += sheet.header1;
    data += "Sheet 1 " + tos(sheet.id) + "\n";
    data += "Title \"" + sheet.title + "\"\n";
    data += sheet.header2;
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

    for (const auto& l : sheet.labels) {
      if (l.type == Sheet::Label::Type::NOCONNECT) {
        data += "NoConn ~ " + tos(l.p) + "\n";
        continue;
      }
      data += "Text " + tos(l.type) + " " + tos(l.p) + " " + tos(l.orientation) + " " +
              tos(l.dimension) + " ";
      if (l.type == Sheet::Label::Type::HIERARCHICAL || l.type == Sheet::Label::Type::GLOBAL)
        data += tos(l.net_type) + " ";
      data += std::string(l.italic ? "Italic" : "~") + " " + (l.bold ? "10" : "0") + "\n";
      data += l.text + "\n";
    }

    for (const auto& w : sheet.wires)
      data += "Wire Wire Line\n\t" + tos(w.start) + " " + tos(w.end) + "\n";

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
  template<typename T>
  std::string tos(const T& val) { return boost::lexical_cast<std::string>(val); }
};

}  // namespace

Sheet

parseSheet(const std::string& data) {
  return KicadParser(data).parseSheet();
}

std::string writeSheet(const Sheet& sheet) {
  return KicadWriter().writeSheet(sheet);
}

Lib parseLibrary(const std::string& filename) {
  return parseLibrary(readFile(filename, false /* binary */), stem(filename));
}

Lib parseLibrary(const std::string& data, const std::string& name) {
  return KicadParser(data).parseLibrary(name);
}

}  // memecad
