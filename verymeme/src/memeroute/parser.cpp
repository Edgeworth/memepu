#include "verymeme/parser.h"
#include "memeroute/parser.h"

namespace memeroute {

namespace {

// Token is either: Paren, empty quotes, quoted string, non space/tab/newline/paren string.
const std::regex TOKEN(R"(([()])|(\".*?[^\\]\")|(\"\")|([^ \t\n()]+))");

class PcbParser {
public:
  explicit PcbParser(const std::string& data) : p_(data, TOKEN) {}

  const Pcb parsePcb() {
    parse();
    pcb_.verifyAndSetup();
    return pcb_;
  }

private:
  Parser p_;
  Pcb pcb_;
  int resolution_ = 2540000;  // Default value.

  int64_t parseDimension() {
    const float dim = p_.next<float>() * resolution_;
    verify_expr(std::abs(dim - int64_t(dim)) < EP, "coordinate conversion loses information");
    return int64_t(dim);
  }

  Point parsePoint() {
    return {parseDimension(), parseDimension()};
  }

  Shape parseShape() {
    Shape shape{};
    p_.expect({"("});
    std::string type = p_.next();
    const std::string layer_name = p_.next();
    shape.layer_id = getDefault(pcb_.layers, layer_name, -1);

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
          Pin pin = parsePin();
          verify_expr(image.pins.count(pin.pin_id) == 0, "duplicate pin '%s'", pin.pin_id.c_str());
          image.pins[pin.pin_id] = pin;
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

  std::vector<Component> parseComponents() {
    p_.expect({"(", "component"});
    const std::string image_id = trim(p_.next(), "\"");
    std::vector<Component> components;
    while (true) {
      const std::string& tok = p_.peek();
      if (tok == "(") {
        p_.expect({"(", "place"});
        Component& component = components.emplace_back();
        component.name = p_.next();
        component.image_id = image_id;
        component.p = parsePoint();
        component.side = p_.next<Side>();
        component.rotation = p_.next<int>();
        p_.expect({"(", "PN"});
        component.part_number = p_.next();
        p_.expect({")", ")"});
      } else {
        break;
      }
    }
    p_.expect({")"});
    return components;
  }

  void checkParseConfiguration() {
    p_.expect({"(", "parser"});
    while (true) {
      const std::string& tok = p_.peek();
      if (tok == ")") {
        break;
      } else {
        p_.expect({"("});
        const std::string& child = p_.peek();
        if (child == "string_quote")
          p_.expect({"string_quote", "\"", ")"});
        else if (child == "space_in_quoted_tokens" || child == "host_cad" ||
                 child == "host_version")
          ignoreRestOfExpression();
        else
          verify_expr(false, "unrecognised expression '%s'", tok.c_str());
      }
    }
    p_.expect({")"});
  }

  void parseStructure() {
    p_.expect({"(", "structure"});
    while (true) {
      const std::string& tok = p_.peek();
      if (tok == ")") {
        break;
      } else {
        p_.expect({"("});
        const std::string& child = p_.peek();
        if (child == "boundary") {
          p_.expect({"boundary"});
          pcb_.boundary = parseShape();
          p_.expect({")"});
        } else if (child == "layer") {
          p_.expect({"layer"});
          const std::string name = p_.next();
          p_.expect({"(", "type", "signal", ")", "(", "property", "(", "index"});
          verify_expr(pcb_.layers.count(name) == 0, "duplicate layer '%s'", name.c_str());
          pcb_.layers[name] = p_.next<int>();
          p_.expect({")", ")", ")"});
        } else if (child == "via") {
          p_.expect({"via"});
          pcb_.via_padstack_id = p_.next();
          p_.expect({")"});
        } else if (child == "rule") {
          // TODO: Collect via and rules and propagate to router.
          ignoreRestOfExpression();  // TODO: Don't ignore these.
        } else
          verify_expr(false, "unrecognised expression '%s'", tok.c_str());
      }
    }
    p_.expect({")"});
  }

  void parse() {
    std::string name = p_.peek(1);
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
    } else if (name == "component") {
      const auto& components = parseComponents();
      for (const auto& component : components) {
        verify_expr(pcb_.components.count(component.name) == 0, "duplicate component '%s'",
            component.name.c_str());
        pcb_.components[component.name] = component;
      }
    } else if (name == "structure") {
      parseStructure();
    } else if (name == "parser") {
      checkParseConfiguration();
    } else if (name == "net") {
      p_.expect({"(", "net"});
      Net net = {};
      net.name = p_.next();
      p_.expect({"(", "pins"});
      while (p_.peek() != ")") {
        const std::string component_pin = p_.next();
        const auto div = component_pin.find('-');
        verify_expr(div != std::string::npos, "invalid component-pin specifier '%s'",
            component_pin.c_str());
        net.pin_ids.push_back({component_pin.substr(0, div), component_pin.substr(div + 1)});
      }
      verify_expr(pcb_.nets.count(net.name) == 0, "duplicate net description with name '%s'",
          net.name.c_str());
      pcb_.nets[net.name] = std::move(net);
      p_.expect({")", ")"});
    } else if (name == "class") {
      ignoreRestOfExpression();  // TODO: Don't ignore.
    } else if (name == "wiring") {
      ignoreRestOfExpression();  // TODO: Don't ignore.
    } else if (name == "resolution") {
      p_.expect({"(", "resolution"});
      p_.next();  // Ignore unit for now.
      resolution_ = p_.next<int>();
      p_.expect({")"});
    } else if (name == "unit") {
      ignoreRestOfExpression();  // Ignore for now.
    } else if (name == "library" || name == "placement" || name == "network") {
      // Just process children.
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
