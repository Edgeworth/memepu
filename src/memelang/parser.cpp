// Copyright 2019 E.
#include "memelang/parser.h"

#include <numeric>
#include <unordered_map>

#include "memelang/ast.h"
#include "memelang/constants.h"
#include "verymeme/macros.h"
#include "verymeme/string_util.h"

namespace memelang::ast {

using fmt = boost::format;

Parser::Parser(const std::vector<std::unique_ptr<FileContents>>& cts) {
  for (const auto& c : cts) c_.emplace_back(std::make_unique<Ctx>(c.get()));
}

Parser::~Parser() = default;

bool Parser::parse() {
  try {
    collectTypeIdents();
    root_ = std::make_unique<Module>(c_);
  } catch (const std::exception& e) { verify(false, "%s", e.what()); }
  return true;
}

std::string Parser::astToString() {
  verify(root_ != nullptr, "null root");
  std::string s;
  root_->visit(
      [&s](Node& n, int depth) { s += std::string(uint64_t(depth), ' ') + n.str() + "\n"; });
  return s;
}

void Parser::collectTypeIdents() {
  std::unordered_set<std::string> types;
  types.insert(std::begin(BUILTIN_TYPES), std::end(BUILTIN_TYPES));

  // Collect type idents for everything in the module.
  // TODO: handle public/private stuff + imports?
  for (const auto& ctx : c_) {
    while (ctx->hasTok()) {
      const bool was_enum = ctx->hasTok(Tok::ENUM);
      // Functions are not treated as types by the parser - e.g. *somefn(x) means dereference
      // the return value of the function, not a pointer type.
      if (ctx->hasTok({Tok::STRUCT, Tok::INTF, Tok::ENUM})) {
        ctx->consumeTok();
        // Next token should be the ident.
        // TODO: Handle namespaces?
        const std::string type_ident = ctx->consumeTok()->str_val;
        types.insert(type_ident);

        // Collect enum idents.
        if (was_enum) {
          // Can't parse using regular Enum code because it may reference another enum type.
          while (!ctx->hasTok(Tok::LBRACE)) ctx->consumeTok();
          ctx->consumeTok(Tok::LBRACE);
          std::string prev_ident;
          while (!ctx->hasTok(Tok::RBRACE)) {
            // Collect all enum variants. Data variants are types, numbered variants are typevalues,
            // so don't include them.
            prev_ident = ctx->curTok()->str_val;
            ctx->consumeTok();
            if (ctx->hasTok(Tok::COLON)) types.insert(type_ident + "." + prev_ident);
          }
        }
      } else {
        ctx->consumeTok();
      }
    }
    ctx->reset();  // Go back to the beginning for actual parsing.
  }

  for (const auto& ctx : c_) ctx->types = types;
}

Parser::Ctx::Ctx(const FileContents* contents) : cts(contents) {
  Tokeniser tokeniser(cts);
  for (const auto& tok : tokeniser.tokenise())
    if (tok.type != Tok::COMMENT) toks_.push_back(tok);
}

const Tok* Parser::Ctx::peekTok(int peek) const {
  if (!hasTok(std::vector<Tok::Type>{}, peek)) error("unexpected end of file");
  return &toks_[idx_ + peek];
}

const Tok* Parser::Ctx::curTok(const std::vector<Tok::Type>& ts) const {
  if (!hasTok()) error("unexpected end of file");
  const auto* token = &toks_[idx_];
  if (!hasTok(ts))
    error("unexpected token, must be one of " +
        std::accumulate(ts.begin(), ts.end(), std::string(),
            [](const auto& a, const auto& b) { return tos(a) + tos(b) + ", "; }));
  return token;
}

const Tok* Parser::Ctx::consumeTok(const std::vector<Tok::Type>& ts) {
  const auto* token = curTok(ts);
  idx_++;
  return token;
}

void Parser::Ctx::error(const std::string& msg) const {
  std::string loc = "eof";
  if (hasTok()) {
    const auto* token = curTok();
    loc = (fmt("%s - \"%s\"") % cts->fpos(token->loc) % token->desc()).str();
  }
  throw std::runtime_error(
      (fmt("compile error at %s:%s: %s\n%s") % cts->filename() % loc % msg % getStacktrace())
          .str());
}

bool Parser::Ctx::hasTok(const std::vector<Tok::Type>& ts, int peek) const {
  if (idx_ + peek >= toks_.size()) return false;
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

}  // namespace memelang::ast
