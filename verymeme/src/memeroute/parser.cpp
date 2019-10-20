#include "memeroute/parser.h"

#include "verymeme/geom.h"
#include "verymeme/macros.h"
#include "verymeme/string_util.h"
#include "verymeme/tokeniser.h"
#include "verymeme/util.h"

namespace memeroute {

namespace {

// Token is either: Paren, empty quotes, quoted string, non space/tab/newline/paren string.
const std::regex TOKEN(R"(([()])|(\".*?[^\\]\")|(\"\")|([^ \t\n()]+))");

class PcbParser {
public:
  explicit PcbParser(const std::string& data) : t_(data, TOKEN) {}

  Pcb parsePcb() {
    parse();
    pcb_.verifyAndSetup();
    return pcb_;
  }

private:
  Tokeniser t_;
  Pcb pcb_;
  int resolution_ = 2540000;  // Default value.

  int64_t parseDimension() {
    const float dim = t_.next<float>() * float(resolution_);
    verify_expr(std::abs(dim - int64_t(dim)) < EP, "coordinate conversion loses information");
    return int64_t(dim);
  }

  Point parsePoint() { return {parseDimension(), parseDimension()}; }

  Shape parseShape() {
    Shape shape{};
    t_.expect({"("});
    std::string type = t_.next();
    const std::string layer_name = t_.next();
    shape.layer_id = getDefault(pcb_.layers, layer_name, -1);

    if (type == "path") {
      shape.type = Shape::Type::PATH;
      shape.path.width = parseDimension();
      while (t_.peek() != ")") { shape.path.points.push_back(parsePoint()); }
    } else if (type == "circle") {
      shape.type = Shape::Type::CIRCLE;
      shape.circle.diameter = parseDimension();
      if (t_.peek() != ")") shape.circle.p = parsePoint();
    } else if (type == "rect") {
      shape.type = Shape::Type::RECT;
      const Point& a = parsePoint();
      const Point& b = parsePoint();
      shape.rect = Rect::enclosing(a, b);  // Opposite points but can be in either order.
    } else {
      verify_expr(false, "unsupported shape type '%s'", type.c_str());
    }
    t_.expect({")"});
    return shape;
  }

  Pin parsePin() {
    Pin pin{};
    t_.expect({"(", "pin"});
    pin.padstack_id = t_.next();
    pin.pin_id = t_.next();
    pin.p = parsePoint();
    t_.expect({")"});
    return pin;
  }

  Image parseImage() {
    Image image{};
    t_.expect({"(", "image"});
    image.name = trim(t_.next(), "\"");
    while (true) {
      const std::string& tok = t_.peek();
      if (tok == ")") {
        break;
      } else {
        verify_expr(tok == "(", "expected child expression in image");
        const std::string& child = t_.peek(1);
        if (child == "outline") {
          t_.expect({"(", "outline"});
          image.outlines.push_back(parseShape());
          t_.expect({")"});
        } else if (child == "pin") {
          Pin pin = parsePin();
          verify_expr(image.pins.count(pin.pin_id) == 0, "duplicate pin '%s'", pin.pin_id.c_str());
          image.pins[pin.pin_id] = pin;
        } else if (child == "keepout") {
          t_.expect({"(", "keepout"});
          t_.next();  // Skip keepout name.
          image.keepouts.push_back(parseShape());
          t_.expect({")"});
        } else {
          verify_expr(false, "unknown token '%s'", child.c_str());
        }
      }
    }
    t_.expect({")"});
    return image;
  }

  Padstack parsePadstack() {
    Padstack padstack{};
    t_.expect({"(", "padstack"});
    padstack.name = t_.next();
    while (true) {
      const std::string& tok = t_.peek();
      if (tok == ")") {
        break;
      } else {
        verify_expr(tok == "(", "expected child expression in image");
        const std::string& child = t_.peek(1);
        if (child == "shape") {
          t_.expect({"(", "shape"});
          padstack.shapes.push_back(parseShape());
          t_.expect({")"});
        } else {
          verify_expr(child == "attach", "unknown token '%s", child.c_str());
          ignoreRestOfExpression();  // TODO(improvement): Ignore for now.
        }
      }
    }
    t_.expect({")"});
    return padstack;
  }

  void ignoreRestOfExpression() {
    const bool inside_expr = t_.peek() != "(";
    while (true) {
      const std::string& tok = t_.next();
      if (tok == "(") {
        ignoreRestOfExpression();
        if (!inside_expr) break;  // Handle the case of being called at the start of an expression.
      } else if (tok == ")") {
        break;
      }
    }
  }

  std::vector<Component> parseComponents() {
    t_.expect({"(", "component"});
    const std::string image_id = trim(t_.next(), "\"");
    std::vector<Component> components;
    while (true) {
      const std::string& tok = t_.peek();
      if (tok == "(") {
        t_.expect({"(", "place"});
        Component& component = components.emplace_back();
        component.name = t_.next();
        component.image_id = image_id;
        component.p = parsePoint();
        component.side = t_.next<Side>();
        component.rotation = t_.next<int>();
        t_.expect({"(", "PN"});
        component.part_number = t_.next();
        t_.expect({")", ")"});
      } else {
        break;
      }
    }
    t_.expect({")"});
    return components;
  }

  void checkParseConfiguration() {
    t_.expect({"(", "parser"});
    while (true) {
      const std::string& tok = t_.peek();
      if (tok == ")") {
        break;
      } else {
        t_.expect({"("});
        const std::string& child = t_.peek();
        if (child == "string_quote") t_.expect({"string_quote", "\"", ")"});
        else if (child == "space_in_quoted_tokens" || child == "host_cad" ||
            child == "host_version")
          ignoreRestOfExpression();
        else
          verify_expr(false, "unrecognised expression '%s'", tok.c_str());
      }
    }
    t_.expect({")"});
  }

  void parseStructure() {
    t_.expect({"(", "structure"});
    while (true) {
      const std::string& tok = t_.peek();
      if (tok == ")") {
        break;
      } else {
        t_.expect({"("});
        const std::string& child = t_.peek();
        if (child == "boundary") {
          t_.expect({"boundary"});
          pcb_.boundary = parseShape();
          t_.expect({")"});
        } else if (child == "layer") {
          t_.expect({"layer"});
          const std::string name = t_.next();
          t_.expect({"(", "type", "signal", ")", "(", "property", "(", "index"});
          verify_expr(pcb_.layers.count(name) == 0, "duplicate layer '%s'", name.c_str());
          pcb_.layers[name] = t_.next<int>();
          t_.expect({")", ")", ")"});
        } else if (child == "via") {
          t_.expect({"via"});
          pcb_.via_padstack_id = t_.next();
          t_.expect({")"});
        } else if (child == "rule") {
          // TODO(improvement): Collect via and rules and propagate to router.
          ignoreRestOfExpression();  // TODO(improvement): Don't ignore these.
        } else
          verify_expr(false, "unrecognised expression '%s'", tok.c_str());
      }
    }
    t_.expect({")"});
  }

  void parse() {
    std::string name = t_.peek(1);
    if (name == "pcb") {
      // TODO(improvement): support more expressions. Error if see unrecognised.
      t_.expect({"("});
      t_.next();  // ignore name for this expr.
      while (true) {
        const std::string& tok = t_.peek();
        if (tok == "(") {
          parse();
        } else if (tok == ")") {
          break;
        } else {
          t_.next();
        }
      }
      t_.expect({")"});
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
      t_.expect({"(", "net"});
      Net net = {};
      net.name = t_.next();
      t_.expect({"(", "pins"});
      while (t_.peek() != ")") {
        const std::string component_pin = t_.next();
        const auto div = component_pin.find('-');
        verify_expr(div != std::string::npos, "invalid component-pin specifier '%s'",
            component_pin.c_str());
        net.pin_ids.push_back({component_pin.substr(0, div), component_pin.substr(div + 1)});
      }
      verify_expr(pcb_.nets.count(net.name) == 0, "duplicate net description with name '%s'",
          net.name.c_str());
      pcb_.nets[net.name] = std::move(net);
      t_.expect({")", ")"});
    } else if (name == "class") {
      ignoreRestOfExpression();  // TODO(improvement): Don't ignore.
    } else if (name == "wiring") {
      ignoreRestOfExpression();  // TODO(improvement): Don't ignore.
    } else if (name == "resolution") {
      t_.expect({"(", "resolution"});
      t_.next();  // Ignore unit for now.
      resolution_ = t_.next<int>();
      t_.expect({")"});
    } else if (name == "unit") {
      ignoreRestOfExpression();  // Ignore for now.
    } else if (name == "library" || name == "placement" || name == "network") {
      // Just process children.
      t_.expect({"(", name});
      while (t_.peek() != ")") parse();
      t_.expect({")"});
    } else {
      verify_expr(false, "unrecognised expression '%s'", name.c_str());
    }
  }
};

}  // namespace

Pcb parsePcb(const std::string& data) {
  try {
    return PcbParser(data).parsePcb();
  } catch (const std::exception& e) { verify_expr(false, "failed exception: %s", e.what()); }
}

}  // namespace memeroute
