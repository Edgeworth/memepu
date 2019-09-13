#include "memelang/parser.h"

#include <numeric>
#include <unordered_map>
#include <utility>

#include "memelang/ast.h"
#include "verymeme/string_util.h"
#include "verymeme/util.h"

namespace memelang {

using fmt = boost::format;

Parser::Parser(const FileContents* contents, const std::vector<Tok>& tokens)
    : ctx_(new Context(contents, tokens)), root_() {}

Parser::~Parser() = default;

bool Parser::parse() {
  try {
    collectTypeIdents();
    root_ = std::make_unique<File>(*ctx_);
  } catch (const std::exception& e) { verify_expr(false, "%s", e.what()); }
  return true;
}

std::string Parser::astToString() {
  verify_expr(root_ != nullptr, "null root");
  std::string s;
  root_->visit(
      [&s](Node& n, int depth) { s += std::string(uint64_t(depth), ' ') + n.toString() + "\n"; });
  return s;
}

void Parser::collectTypeIdents() {}

Parser::Context::Context(const FileContents* cts, std::vector<Tok> tokens)
    : cts(cts), toks_(std::move(tokens)) {}

const Tok* Parser::Context::curToken(const std::vector<Tok::Type>& ts) const {
  if (!hasToken()) compileError("unexpected end of file");
  const auto* token = &toks_[idx_];
  if (!hasToken(ts))
    compileError("unexpected token, must be one of " +
        std::accumulate(ts.begin(), ts.end(), std::string(),
            [](const auto& a, const auto& b) { return tos(a) + tos(b) + ", "; }));
  return token;
}

const Tok* Parser::Context::consumeToken(const std::vector<Tok::Type>& ts) {
  const auto* token = curToken(ts);
  idx_++;
  return token;
}

void Parser::Context::compileError(const std::string& msg) const {
  std::string loc = "eof";
  if (hasToken()) {
    const auto* token = curToken();
    loc = (fmt("%d:%d - \"%s\"") % cts->getLineNumber(token->loc) % cts->getColNumber(token->loc) %
        token->toString(cts))
              .str();
  }
  throw std::runtime_error(
      (fmt("compile error at %s: %s\n%s") % loc % msg % getStacktrace()).str());
}

bool Parser::Context::hasToken(const std::vector<Tok::Type>& ts, int peek) const {
  if (idx_ + peek >= int(toks_.size())) return false;
  if (ts.empty()) return true;
  const auto& token = toks_[idx_ + peek];
  return std::any_of(ts.begin(), ts.end(), [token](auto type) { return token.type == type; });
}

bool Parser::Context::maybeConsumeToken(Tok::Type type) {
  const Tok* token = curToken();
  if (token->type == type) {
    idx_++;
    return true;
  }
  return false;
}

}  // namespace memelang
