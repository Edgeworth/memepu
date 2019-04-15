#include "verymeme/parser.h"
#include "memeroute/parser.h"

namespace memeroute {

namespace {

void verifyPcb(const Pcb& pcb) {
  for (const auto& image : pcb.images) {
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

  Point parsePoint() {
    // TODO: discards decimal. Need to multiply up.
    return {int(p_.next<float>()), int(p_.next<float>())};
  }

  Shape parseShape() {
    Shape shape{};
    printf("Parsing shape\n");
    p_.expect({"("});
    std::string type = p_.next();
    shape.layer_id = p_.next();

    if (type == "path") {
      shape.type = Shape::Type::PATH;
      shape.path.width = p_.next<int>();
      while (p_.peek() != ")") {
        shape.path.points.push_back(parsePoint());
      }
    } else if (type == "circle") {
      shape.type = Shape::Type::CIRCLE;
      shape.circle_diameter = p_.next<int>();
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
        } else {
//          verify_expr(false, "unknown token '%s'", child.c_str());
          parse();  // TODO: for now ignore
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
          parse();  // Ignore for now.
        }
      }
    }
    p_.expect({")"});
    return padstack;
  }

  void parse() {
    std::string name = p_.peek(1);
    printf("Parsing at %s\n", name.c_str());
    if (name == "image") {
      pcb_.images.push_back(parseImage());
    } else if (name == "padstack") {
      const auto& padstack = parsePadstack();
      verify_expr(pcb_.padstacks.count(padstack.name) == 0, "duplicate padstack");
      pcb_.padstacks[padstack.name] = padstack;
    } else {
      // TODO: support more expressions.
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
