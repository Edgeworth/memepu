#include "verymeme/parser.h"
#include "memeroute/parser.h"

namespace memeroute {

namespace {

// Token is either: Paren, empty quotes, quoted string, non space/tab/newline string, newline, tab.
const std::regex TOKEN(R"(([()])|(\".*?[^\\]\")|(\"\")|([^ \t\n]+)|(\n)|(\t))");

class PcbParser {
public:
  explicit PcbParser(const std::string& data) : p_(data, TOKEN) {}

  Pcb parsePcb() {
    while (p_.hasTokens()) {
      printf("TOKEN: %s\n", p_.next().c_str());
    }
  }

private:
  Parser p_;
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
