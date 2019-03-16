#include "memecad/parser.h"

#include <regex>
#include <boost/lexical_cast.hpp>

namespace memecad {

namespace {

std::vector<std::string> tokenize(const std::string& data) {
  const std::regex split(R"((\".*?[^\\]\")|(\"\")|([^ \n]+)|(\n))");
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

  sheet_t parseSheet() {
    sheet_t sheet = {};
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
        label_t& label = sheet.labels.emplace_back();
        label.type = next<Label>();
        label.x = next<int>();
        label.y = next<int>();
        label.orientation = next<int>();
        label.dimension = next<int>();
        label.shape = next();
        expect({"0", "\n"});
        label.text = trim(getLines(1), "\\n");
      } else {
        verify_expr(false, "unexpected token '%s'", tok.c_str());
      }
    }
    return sheet;
  }

  lib_t parseLibrary(const std::string& name) {
    lib_t lib = {};
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

  sheet_component_t parseComponent() {
    sheet_component_t comp;
    expect({"\n", "L"});
    comp.name = next();
    comp.ref = next();
    expect({"\n", "U"});
    comp.subcomponent = next<int>();
    expect({"1"});
    comp.timestamp = next();
    expect({"\n", "P"});
    comp.x = next<int>();
    comp.y = next<int>();
    expect({"\n"});
    while (true) {
      std::string tok = peek();
      if (tok == "F") {
        field_t& field = comp.fields.emplace_back();
        expect({"F"});
        field.num = next<int>();
        field.text = trim(next(), "\"");
        field.orientation = next<Orientation>();
        field.x = next<int>();
        field.y = next<int>();
        field.size = next<int>();
        field.flags = next();
        field.justification = next();
        field.style = next();
        expect({"\n"});
      } else if (tok[0] == '\t') {
        comp.footer = getLines(2);
        expect({"$EndComp", "\n"});
        break;
      } else {
        verify_expr(false, "unexpected token '%s'", tok.c_str());
      }
    }
    return comp;
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
      if (!substr.empty() && substr.back() != '\n' && toks_[i] != "\n") substr += ' ';
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

  lib_component_t parseLibraryComponent() {
    lib_component_t component = {};
    expect({"DEF"});
    component.names.push_back(next());
    component.ref = next();
    expect({"0"});  // Unused.
    next();
    next();
    next();  // Text offset, draw pin number, draw pin name.
    component.unit_count = next<int>();
    component.unit_swappable = next<UnitSwappable>();
    getLines(1);  // Ignore rest.
    while (true) {
      std::string tok = next();
      if (tok == "ENDDEF") break;
      else if (tok == "F0" || tok == "F1") {
        // Record reference field.
        lib_field_t& field = component.fields.emplace_back();
        field.text = trim(next(), "\"");
        field.x = next<int>();
        field.y = next<int>();
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
        lib_pin_t& pin = component.pins.emplace_back();
        pin.name = next();
        next(); // Pin number.
        pin.x = next<int>();
        pin.y = next<int>();
        next(); // Length
        pin.direction = next<Direction>();
        next();
        next();  // Name text size, num text size.
        pin.unit_number = next<int>();
        next();  // convert
        pin.type = next<ElectricalType>();
        getLines(1); // Ignore rest.
      }
    }
    expect({"\n"});
    return component;
  }
};

class KicadWriter {
public:
  std::string writeSheet(const sheet_t& sheet) {
    std::string data;
    data += sheet.header1;
    data += "Sheet 1 " + tos(sheet.id) + "\n";
    data += "Title \"" + sheet.title + "\"\n";
    data += sheet.header2;
    for (const auto& comp : sheet.components) {
      data += "$Comp\n";
      data += "L " + comp.name + " " + comp.ref + "\n";
      data += "U " + tos(comp.subcomponent) + " 1 " + comp.timestamp + "\n";
      data += "P " + tos(comp.x) + " " + tos(comp.y) + "\n";
      for (const auto& f : comp.fields) {
        data +=
            "F " + tos(f.num) + " \"" + f.text + "\" " + tos(f.orientation) + " " + tos(f.x) + " " +
            tos(f.y) + " " + tos(f.size) + " " + f.flags + " " + f.justification + " " +
            f.style + "\n";
      }
      data += comp.footer;
      data += "$EndComp\n";
    }

    for (const auto& l : sheet.labels) {
      data +=
          "Text " + tos(l.type) + " " + tos(l.x) + " " + tos(l.y) + " " + tos(l.orientation) + " " +
          tos(l.dimension) + " " + tos(l.shape) + " 0\n";
      data += l.text + "\n";
    }

    data += "$EndSCHEMATC\n";
    return data;
  }

private:
  template<typename T>
  std::string tos(const T& val) { return boost::lexical_cast<std::string>(val); }
};

}  // namespace

sheet_t parseSheet(const std::string& data) {
  return KicadParser(data).parseSheet();
}

std::string writeSheet(const sheet_t& sheet) {
  return KicadWriter().writeSheet(sheet);
}

lib_t parseLibrary(const std::string& filename) {
  return parseLibrary(readFile(filename, false /* binary */), stem(filename));
}

lib_t parseLibrary(const std::string& data, const std::string& name) {
  return KicadParser(data).parseLibrary(name);
}

}  // memecad
