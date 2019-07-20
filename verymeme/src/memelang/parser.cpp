#include "memelang/parser.h"
#include "verymeme/util.h"
#include "verymeme/string_util.h"
#include <climits>
#include <sstream>
#include <unordered_map>
#include <numeric>

namespace memelang {

namespace {

//std::unordered_map<Token::Type, Node::Type> OPMAP = {
//    {Token::Type::PLUS, Node::ADD},
//    {Token::Type::MINUS, Node::SUB},
//    {Token::Type::ASTERISK, Node::MUL},
//    {Token::Type::FSLASH, Node::DIV},
//    {Token::Type::EQUAL, Node::ASSIGN},
//    {Token::Type::DEQUAL, Node::EQUALS},
//    {Token::Type::NEQUAL, Node::NOT_EQUALS},
//    {Token::Type::DOT, Node::ACCESS},
//    {Token::Type::LANGLE, Node::LESS_THAN},
//    {Token::Type::RANGLE, Node::GREATER_THAN},
//    {Token::Type::LTEQUAL, Node::LESS_THAN_EQUAL},
//    {Token::Type::GTEQUAL, Node::GREATER_THAN_EQUAL},
//};

//std::unordered_map<Node::Type, int> PRECEDENCE = {
//    {Node::ACCESS, 4},
//    {Node::MUL, 3},
//    {Node::DIV, 3},
//    {Node::ADD, 2},
//    {Node::SUB, 2},
//    {Node::LESS_THAN, 1},
//    {Node::GREATER_THAN, 1},
//    {Node::LESS_THAN_EQUAL, 1},
//    {Node::GREATER_THAN_EQUAL, 1},
//    {Node::EQUALS, 1},
//    {Node::NOT_EQUALS, 1},
//    {Node::ASSIGN, 0},
//};

const std::vector<Token::Type> BUILTIN_TYPES = {Token::AUTO, Token::I8, Token::I16, Token::I32,
    Token::U8,
    Token::U16, Token::U32, Token::BOOL, Token::BIT};

void fcInternal(std::vector<Node*>&) {}

template<typename T, typename... Args>
void fcInternal(std::vector<Node*>& cs, const T& head, const Args& ...tail) {
  if constexpr (std::is_assignable_v<T, nullptr_t>) cs.push_back(head.get());
  else for (const auto& p : head) cs.push_back(p.get());
  fcInternal(cs, tail...);
}

template<typename... Args>
std::vector<Node*> flattenChildren(const Args& ...args) {
  std::vector<Node*> cs;
  fcInternal(cs, args...);
  return cs;
}

}  // namespace

//// Expression possibilities:
//std::unique_ptr<Node> Parser::tryExpression(int last_precedence) {
//  std::unique_ptr<Node> node;
//  while (true) {
//    peek_token(token);
//    // Stop parsing at the end of a statement, sub-expression, start of a block (e.g. if statement),
//    // end of an indexing, or part of a list (comma).
//    if (token->type == Token::SEMICOLON || token->type == Token::RPAREN ||
//        token->type == Token::LBRACE || token->type == Token::RSQUARE ||
//        token->type == Token::COMMA)
//      break;

//    auto iter = OPMAP.find(token->type);
//    if (iter != OPMAP.end()) {
//      auto type = iter->second;
//      auto precedence = PRECEDENCE[type];

//      // If current precedence isn't high enough to keep going, stop parsing here.
//      if (precedence <= last_precedence)
//        break;

//      discard_token();
//      auto child = nodeFromToken(type, token);
//      std::swap(child, node);
//      node->children.push_back(std::move(child));

//      expect_parse(subexpr, [this, precedence] { return tryExpression(precedence); });
//      node->children.push_back(std::move(subexpr));
//      continue;
//    }

//    // Don't want hanging exprs.
//    token_error(!node, token, "unexpected token in expression");

//    switch (token->type) {
//      // TODO
////      case Token::LITERAL: {
////        // Parse literal last - it might be an index,  function call, or struct initialiser.
////        expect_parse(literal, [this] { return tryFunctionCall(); }, [this] { return tryIndex(); },
////            [this] { return tryStructInitialiser(); }, [this] { return tryLiteral(); });
////        node = std::move(literal);
////        continue;
////      }
//      case Token::LPAREN: {
//        discard_token();
//        expect_parse(subexpr, [this] { return tryExpression(); });
//        node = std::move(subexpr);
//        expect_token(Token::RPAREN, "closing paren");
//        continue;
//      }
//      default:
//        break;
//    }

//    token_error(false, token, "unexpected token");
//  }

//  return node;
//}

struct Parser::Context {
  const FileContents* contents;
  std::vector<Token> toks;
  int idx;

  const Token* curToken() const { return curToken(std::vector<Token::Type>{}); }
  const Token* curToken(Token::Type type) const { return curToken(std::vector<Token::Type>{type}); }
  const Token* curToken(const std::vector<Token::Type>& ts) const {
    if (!hasToken())
      throw std::runtime_error("unexpected end of file\n" + getStacktrace());
    const auto* token = &toks[int(idx)];
    if (!hasToken(ts))
      throw std::runtime_error("unexpected token " + token->toString(contents) +
          ": must be one of " + std::accumulate(ts.begin(), ts.end(), std::string(),
          [](const auto& a, const auto& b) { return tos(a) + tos(b) + ", "; }) + "\n" +
          getStacktrace());
    return token;
  }

  const Token* consumeToken() { return consumeToken(std::vector<Token::Type>{}); }
  const Token* consumeToken(Token::Type type) {
    return consumeToken(std::vector<Token::Type>{type});
  }
  const Token* consumeToken(const std::vector<Token::Type>& ts) {
    const auto* token = curToken(ts);
    idx++;
    return token;
  }
  bool maybeConsumeToken(Token::Type type) {
    const Token* token = curToken();
    if (token->type == type) {
      idx++;
      return true;
    }
    return false;
  }

  bool hasToken() const { return hasToken(std::vector<Token::Type>{}); }
  bool hasToken(Token::Type type) const { return hasToken(std::vector<Token::Type>{type}); }
  bool hasToken(const std::vector<Token::Type>& ts) const {
    if (idx >= int(toks.size())) return false;
    if (ts.empty()) return true;
    const auto& token = toks[int(idx)];
    return std::any_of(ts.begin(), ts.end(), [token](auto type) { return token.type == type; });
  }
};

Parser::Parser(const FileContents* contents, std::vector<Token> tokens)
    : ctx_(new Context{contents, std::move(tokens), 0}), root_() {}

Parser::~Parser() = default;

bool Parser::parse() {
  try {
    root_ = std::make_unique<File>(*ctx_);
  } catch (const std::exception& e) {
    verify_expr(false, "%s\n", e.what());
  }
  return true;
}

std::string Parser::astToString() {
  verify_expr(root_ != nullptr, "null root");
  std::string s;
  root_->visit([&s](Node& n) { s += n.toString() + "\n"; });
  return s;
}

using fmt = boost::format;

Typelist::Typelist(Parser::Context& ctx) {
  ctx.consumeToken(Token::LANGLE);
  while (true) {
    names.push_back(ctx.consumeToken(Token::IDENT)->toString(ctx.contents));
    if (ctx.hasToken(Token::COMMA)) ctx.consumeToken();
    else break;
  }
  ctx.consumeToken(Token::RANGLE);
}

std::string Typelist::toString() const { return "Typelist"; }
std::vector<Node*> Typelist::children() { return {}; }
void Typelist::generateIr() const {}

Typename::Typename(Parser::Context& ctx) {
  name = ctx.consumeToken(Token::IDENT)->toString(ctx.contents);
  if (ctx.hasToken(Token::LANGLE))
    tlist = std::make_unique<Typelist>(ctx);
}

std::string Typename::toString() const { return (fmt("Typename %s") % name).str(); }
std::vector<Node*> Typename::children() { if (tlist) return {tlist.get()}; return {}; }
void Typename::generateIr() const {}

Qualifier::Qualifier(Parser::Context& ctx) {
  if (ctx.hasToken(Token::LSQUARE)) {
    ctx.consumeToken(Token::LSQUARE);
    array = ctx.consumeToken(Token::INT_LIT)->int_val;
    ctx.consumeToken(Token::RSQUARE);
  } else {
    if (ctx.maybeConsumeToken(Token::CONST)) cnst = true;
    ptr = true;
    ctx.consumeToken(Token::ASTERISK);
  }
}

std::string Qualifier::toString() const { return "Qualifier"; }
std::vector<Node*> Qualifier::children() { return {}; }
void Qualifier::generateIr() const {}

Type::Type(Parser::Context& ctx) {
  while (ctx.hasToken({Token::ASTERISK, Token::LSQUARE}))
    quals.emplace_back(std::make_unique<Qualifier>(ctx));
  cnst = ctx.maybeConsumeToken(Token::CONST);
  if (ctx.hasToken(Token::IDENT)) {
    name = ctx.consumeToken(Token::IDENT)->toString(ctx.contents);
    if (ctx.hasToken(Token::LANGLE)) {
      ctx.consumeToken(Token::LANGLE);
      while (ctx.curToken()->type != Token::RANGLE) {
        params.emplace_back(std::make_unique<Type>(ctx));
        if (!ctx.maybeConsumeToken(Token::COMMA)) break;
      }
      ctx.consumeToken(Token::RANGLE);
    }
  } else {
    name = ctx.consumeToken(BUILTIN_TYPES)->toString(ctx.contents);
  }
}

std::string Type::toString() const { return (fmt("Type %s") % name).str(); }
std::vector<Node*> Type::children() { return flattenChildren(quals, params); }
void Type::generateIr() const {}

FnVarDecl::FnVarDecl(Parser::Context& ctx) {
  type = std::make_unique<Type>(ctx);
  name = ctx.consumeToken(Token::IDENT)->toString(ctx.contents);
}

std::string FnVarDecl::toString() const { return (fmt("FnVarDecl %s") % name).str(); }
std::vector<Node*> FnVarDecl::children() { return {type.get()}; }
void FnVarDecl::generateIr() const {}

FnSig::FnSig(Parser::Context& ctx) {
  ctx.consumeToken(Token::FN);
  tname = std::make_unique<Typename>(ctx);
  ctx.consumeToken(Token::LPAREN);
  while (ctx.curToken()->type != Token::RPAREN) {
    params.emplace_back(std::make_unique<FnVarDecl>(ctx));
    if (!ctx.maybeConsumeToken(Token::COMMA)) break;
  }
  ctx.consumeToken(Token::RPAREN);
  ret_type = std::make_unique<Type>(ctx);
}

std::string FnSig::toString() const { return "FnSig"; }
std::vector<Node*> FnSig::children() { return flattenChildren(tname, params, ret_type); }
void FnSig::generateIr() const {}

IntfDefn::IntfDefn(Parser::Context& ctx) {
  ctx.consumeToken(Token::INTF);
  tname = std::make_unique<Typename>(ctx);
  ctx.consumeToken(Token::LBRACE);
  while (ctx.hasToken(Token::FN)) {
    decls.emplace_back(std::make_unique<FnSig>(ctx));
    ctx.consumeToken(Token::SEMICOLON);
  }
  ctx.consumeToken(Token::RBRACE);
}

std::string IntfDefn::toString() const { return "Intf"; }
std::vector<Node*> IntfDefn::children() { return flattenChildren(decls); }
void IntfDefn::generateIr() const {}

File::File(Parser::Context& ctx) {
  printf("ASDF\n");
  while (ctx.hasToken()) {
    const auto* token = ctx.curToken(Token::INTF);
    if (token->type == Token::INTF) {
      printf("NEW INTF\n");
      intf_defns.emplace_back(std::make_unique<IntfDefn>(ctx));
    }
  }
}

std::string File::toString() const { return "File"; }
std::vector<Node*> File::children() { return flattenChildren(intf_defns); }
void File::generateIr() const {}

}  // namespace memelang
