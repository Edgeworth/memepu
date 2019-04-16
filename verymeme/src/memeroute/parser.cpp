#include "verymeme/parser.h"
#include "memeroute/parser.h"

namespace memeroute {

namespace {

void verifyPcb(const Pcb& pcb) {
  for (const auto& kv : pcb.images) {
    const auto&[name, image] = kv;
    for (const auto& pin : image.pins) {
      verify_expr(pcb.padstacks.count(pin.padstack_id) > 0, "missing padstack '%s'",
          pin.padstack_id.c_str());
    }
  }
}

// Token is either: Paren, empty quotes, quoted string, non space/tab/newline/paren string.
const std::regex TOKEN(R"(([()])|(\".*?[^\\]\")|(\"\")|([^ \t\n()]+))");

class PcbParser {
public:
  explicit PcbParser(const std::string& data) : p_(data, TOKEN) {}


  Pcb parsePcb() {
    parse();
    verifyPcb(pcb_);
    return pcb_;
  }

private:
  Parser p_;
  Pcb pcb_;
  int resolution_ = 2540000;  // Default value.

  int parseDimension() {
    const float dim = p_.next<float>() * resolution_;
    verify_expr(std::abs(dim - int(dim)) < EP, "coordinate conversion loses information");
    return int(dim);
  }

  Point parsePoint() {
    return {parseDimension(), parseDimension()};
  }

  Shape parseShape() {
    Shape shape{};
    printf("Parsing shape\n");
    p_.expect({"("});
    std::string type = p_.next();
    shape.layer_id = p_.next();

    if (type == "path") {
      shape.type = Shape::Type::PATH;
      shape.path.width = parseDimension();
      while (p_.peek() != ")") {
        shape.path.points.push_back(parsePoint());
      }
    } else if (type == "circle") {
      shape.type = Shape::Type::CIRCLE;
      shape.circle.diameter = parseDimension();
      if (p_.peek() != ")")
        shape.circle.p = parsePoint();
    } else if (type == "rect") {
      shape.type = Shape::Type::RECT;
      const Point& a = parsePoint();
      const Point& b = parsePoint();
      shape.rect = Rect::enclosing(a, b);  // Opposite points but can be in either order.
    } else {
      verify_expr(false, "unsupported shape type '%s'", type.c_str());
    }
    p_.expect({")"});
    printf("Finished parsing shape\n");
    return shape;
  }

  Pin parsePin() {
    Pin pin{};
    p_.expect({"(", "pin"});
    pin.padstack_id = p_.next();
    pin.pin_id = p_.next();
    pin.p = parsePoint();
    p_.expect({")"});
    return pin;
  }

  Image parseImage() {
    Image image{};
    p_.expect({"(", "image"});
    image.name = trim(p_.next(), "\"");
    printf("Parsing image: %s\n", image.name.c_str());
    while (true) {
      const std::string& tok = p_.peek();
      if (tok == ")") {
        break;
      } else {
        verify_expr(tok == "(", "expected child expression in image");
        const std::string& child = p_.peek(1);
        if (child == "outline") {
          p_.expect({"(", "outline"});
          image.outlines.push_back(parseShape());
          p_.expect({")"});
        } else if (child == "pin") {
          image.pins.push_back(parsePin());
        } else if (child == "keepout") {
          p_.expect({"(", "keepout"});
          p_.next();  // Skip keepout name.
          image.keepouts.push_back(parseShape());
          p_.expect({")"});
        } else {
          verify_expr(false, "unknown token '%s'", child.c_str());
        }
      }
    }
    p_.expect({")"});
    return image;
  }

  Padstack parsePadstack() {
    Padstack padstack{};
    p_.expect({"(", "padstack"});
    padstack.name = p_.next();
    while (true) {
      const std::string& tok = p_.peek();
      if (tok == ")") {
        break;
      } else {
        verify_expr(tok == "(", "expected child expression in image");
        const std::string& child = p_.peek(1);
        if (child == "shape") {
          p_.expect({"(", "shape"});
          padstack.shapes.push_back(parseShape());
          p_.expect({")"});
        } else {
          verify_expr(child == "attach", "unknown token '%s", child.c_str());
          ignoreRestOfExpression();  // TODO: Ignore for now.
        }
      }
    }
    p_.expect({")"});
    return padstack;
  }

  void ignoreRestOfExpression() {
    const bool inside_expr = p_.peek() != "(";
    while (true) {
      const std::string& tok = p_.next();
      if (tok == "(") {
        ignoreRestOfExpression();
        if (!inside_expr) break;  // Handle the case of being called at the start of an expression.
      } else if (tok == ")") {
        break;
      }
    }
  }

  void checkParseConfiguration() {
    p_.expect({"(", "parser"});
    while (true) {
      const std::string& tok = p_.peek();
      if (tok == ")") {
        break;
      } else {
        p_.expect({"("});
        const std::string& child = p_.next();
        if (child == "string_quote")
          p_.expect({"\"", ")"});
        else if (child == "space_in_quoted_tokens" || child == "host_cad" ||
                 child == "host_version")
          ignoreRestOfExpression();
        else
          verify_expr(false, "unrecognised expression '%s'", tok.c_str());
      }
    }
    p_.expect({")"});
  }

  void parse() {
    std::string name = p_.peek(1);
    printf("Parsing at %s\n", name.c_str());
    if (name == "pcb") {
      // TODO: support more expressions. Error if see unrecognised.
      p_.expect({"("});
      p_.next();  // ignore name for this expr.
      while (true) {
        const std::string& tok = p_.peek();
        if (tok == "(") {
          parse();
        } else if (tok == ")") {
          break;
        } else {
          p_.next();
        }
      }
      p_.expect({")"});
    } else if (name == "image") {
      const auto& image = parseImage();
      verify_expr(pcb_.images.count(image.name) == 0, "duplicate image");
      pcb_.images[image.name] = image;
    } else if (name == "padstack") {
      const auto& padstack = parsePadstack();
      verify_expr(pcb_.padstacks.count(padstack.name) == 0, "duplicate padstack");
      pcb_.padstacks[padstack.name] = padstack;
    } else if (name == "placement") {
      ignoreRestOfExpression(); // TODO: Don't ignore.
//      pcb_.components.push_back(parseComponent());
    } else if (name == "structure") {
      ignoreRestOfExpression();  // TODO: Don't ignore.
    } else if (name == "parser") {
      checkParseConfiguration();
    } else if (name == "network") {
      ignoreRestOfExpression();  // TODO: Don't ignore.
    } else if (name == "wiring") {
      ignoreRestOfExpression();  // TODO: Don't ignore.
    }else if (name == "resolution") {
      p_.expect({"(", "resolution"});
      p_.next();  // Ignore unit for now.
      resolution_ = p_.next<int>();
      p_.expect({")"});
    } else if (name == "unit") {
      ignoreRestOfExpression();  // Ignore for now.
    } else if (name == "library") {
      // Ignore some expressions.
      // TODO: Actually make parseLibrary function?
      p_.expect({"(", name});
      while (p_.peek() != ")") parse();
      p_.expect({")"});
    } else {
      verify_expr(false, "unrecognised expression '%s'", name.c_str());
    }
  }
};

}  // namespace

Pcb parsePcb(const std::string& data) {
  try {
    return PcbParser(data).parsePcb();
  } catch (const std::exception& e) {
    verify_expr(false, "failed exception: %s", e.what());
  }
}

}  // memeroute
