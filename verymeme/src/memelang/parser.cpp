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
    : c_(new Ctx(contents, tokens)), root_() {}

Parser::~Parser() = default;

bool Parser::parse() {
  try {
    collectTypeIdents();
    root_ = std::make_unique<File>(*c_);
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

void Parser::collectTypeIdents() {
  while (c_->hasTok()) {
    if (c_->hasTok({Tok::STRUCT, Tok::INTF, Tok::ENUM})) {
      c_->consumeTok();
      // Next token should be the ident.
      c_->type_idents.push_back(c_->consumeTok()->toString(c_->cts));
      printf("TYPE IDENT: %s\n", c_->type_idents.back().c_str());
    } else {
      c_->consumeTok();
    }
  }
  c_->reset();
}

Parser::Ctx::Ctx(const FileContents* cts, std::vector<Tok> tokens)
    : cts(cts), toks_(std::move(tokens)) {}

const Tok* Parser::Ctx::curTok(const std::vector<Tok::Type>& ts) const {
  if (!hasTok()) compileError("unexpected end of file");
  const auto* token = &toks_[idx_];
  if (!hasTok(ts))
    compileError("unexpected token, must be one of " +
        std::accumulate(ts.begin(), ts.end(), std::string(),
            [](const auto& a, const auto& b) { return tos(a) + tos(b) + ", "; }));
  return token;
}

const Tok* Parser::Ctx::consumeTok(const std::vector<Tok::Type>& ts) {
  const auto* token = curTok(ts);
  idx_++;
  return token;
}

void Parser::Ctx::compileError(const std::string& msg) const {
  std::string loc = "eof";
  if (hasTok()) {
    const auto* token = curTok();
    loc = (fmt("%d:%d - \"%s\"") % cts->getLineNumber(token->loc) % cts->getColNumber(token->loc) %
        token->toString(cts))
              .str();
  }
  throw std::runtime_error(
      (fmt("compile error at %s: %s\n%s") % loc % msg % getStacktrace()).str());
}

bool Parser::Ctx::hasTok(const std::vector<Tok::Type>& ts, int peek) const {
  if (idx_ + peek >= int(toks_.size())) return false;
  if (ts.empty()) return true;
  const auto& token = toks_[idx_ + peek];
  return std::any_of(ts.begin(), ts.end(), [token](auto type) { return token.type == type; });
}

bool Parser::Ctx::maybeConsumeTok(Tok::Type type) {
  const Tok* token = curTok();
  if (token->type == type) {
    idx_++;
    return true;
  }
  return false;
}

}  // namespace memelang
