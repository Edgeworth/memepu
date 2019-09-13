#include "memelang/ast.h"

#include <boost/format.hpp>

#include "memelang/expression.h"
#include "memelang/parser.h"
#include "memelang/tokeniser.h"
#include "verymeme/string_util.h"

namespace memelang {

using fmt = boost::format;

namespace {

const std::vector<Tok::Type> BUILTIN_TYPES = {
    Tok::AUTO, Tok::I8, Tok::I16, Tok::I32, Tok::U8, Tok::U16, Tok::U32, Tok::BOOL, Tok::BIT};

void fcInternal(std::vector<Node*>&) {}

template <typename T, typename... Args>
void fcInternal(std::vector<Node*>& cs, const T& head, const Args&... tail) {
  if constexpr (std::is_assignable_v<T, std::nullptr_t>) {
    if (head) cs.push_back(head.get());
  } else {
    for (const auto& p : head) {
      if (p != nullptr) cs.push_back(p.get());
    }
  }
  fcInternal(cs, tail...);
}

template <typename... Args>
std::vector<Node*> flattenChildren(const Args&... args) {
  std::vector<Node*> cs;
  fcInternal(cs, args...);
  return cs;
}

}  // namespace

std::ostream& operator<<(std::ostream& str, const Expr::Type& o) {
  const static std::string EXPR_TYPES[] = {"ARRAY_ACCESS", "MEMBER_ACCESS", "FN_CALL",
      "POSTFIX_INC", "POSTFIX_DEC", "PREFIX_INC", "PREFIX_DEC", "UNARY_NEGATE", "UNARY_LINVERT",
      "UNARY_BINVERT", "UNARY_DEREF", "UNARY_ADDR", "MUL", "DIV", "MOD", "ADD", "SUB", "LSHIFT",
      "ARITH_RSHIFT", "RSHIFT", "LEQ", "GEQ", "LT", "GT", "EQ", "NEQ", "BAND", "BXOR", "BOR",
      "LAND", "LOR", "TERNARY", "ASSIGNMENT"};

  return outputEnum(str, o, EXPR_TYPES);
}

BoolLit::BoolLit(Parser::Context& ctx) { val = bool(ctx.consumeToken(Tok::BOOL_LIT)->int_val); }
std::string BoolLit::toString() const {
  return (fmt("BoolLit(%s)") % (val ? "true" : "false")).str();
}
std::vector<Node*> BoolLit::children() { return {}; }

IntLit::IntLit(Parser::Context& ctx) { val = ctx.consumeToken(Tok::INT_LIT)->int_val; }
std::string IntLit::toString() const { return (fmt("IntLit(%d)") % val).str(); }
std::vector<Node*> IntLit::children() { return {}; }

CharLit::CharLit(Parser::Context& ctx) { val = int32_t(ctx.consumeToken(Tok::CHAR_LIT)->int_val); }
std::string CharLit::toString() const { return (fmt("CharLit(%c)") % val).str(); }
std::vector<Node*> CharLit::children() { return {}; }

StrLit::StrLit(Parser::Context& ctx) { val = ctx.consumeToken(Tok::STR_LIT)->str_val; }
std::string StrLit::toString() const { return (fmt("StrLit(%s)") % val).str(); }
std::vector<Node*> StrLit::children() { return {}; }

CompoundLit::CompoundLit(Parser::Context& ctx) {
  ctx.consumeToken(Tok::LBRACE);
  while (!ctx.hasToken(Tok::RBRACE)) {
    lits.emplace_back(ExpressionParser(ctx).parse());
    ctx.consumeToken(Tok::COMMA);
  }
  ctx.consumeToken(Tok::RBRACE);
}
std::string CompoundLit::toString() const { return "CompoundLit"; }
std::vector<Node*> CompoundLit::children() { return {}; }

Op::Op(Parser::Context&) {}
std::string Op::toString() const { return (fmt("Op(%s)") % type).str(); }
std::vector<Node*> Op::children() { return flattenChildren(left, right); }

VarRef::VarRef(Parser::Context& ctx) { name = ctx.consumeToken(Tok::IDENT)->toString(ctx.cts); }
std::string VarRef::toString() const { return (fmt("VarRef(%s)") % name).str(); }
std::vector<Node*> VarRef::children() { return {}; }

Typelist::Typelist(Parser::Context& ctx) {
  ctx.consumeToken(Tok::LANGLE);
  while (true) {
    names.push_back(ctx.consumeToken(Tok::IDENT)->toString(ctx.cts));
    if (ctx.hasToken(Tok::COMMA)) ctx.consumeToken();
    else
      break;
  }
  ctx.consumeToken(Tok::RANGLE);
}

std::string Typelist::toString() const { return "Typelist"; }
std::vector<Node*> Typelist::children() { return {}; }

Typename::Typename(Parser::Context& ctx) {
  name = ctx.consumeToken(Tok::IDENT)->toString(ctx.cts);
  if (ctx.hasToken(Tok::LANGLE)) tlist = std::make_unique<Typelist>(ctx);
}
std::string Typename::toString() const { return (fmt("Typename %s") % name).str(); }
std::vector<Node*> Typename::children() { return flattenChildren(tlist); }

Qualifier::Qualifier(Parser::Context& ctx) {
  if (ctx.hasToken(Tok::LSQUARE)) {
    ctx.consumeToken(Tok::LSQUARE);
    array = ctx.consumeToken(Tok::INT_LIT)->int_val;
    ctx.consumeToken(Tok::RSQUARE);
  } else {
    if (ctx.maybeConsumeToken(Tok::CONST)) cnst = true;
    ptr = true;
    ctx.consumeToken(Tok::ASTERISK);
  }
}
std::string Qualifier::toString() const {
  return (fmt("Qualifier const: %1% ptr: %2%, array: %3%") % cnst % ptr % array).str();
}
std::vector<Node*> Qualifier::children() { return {}; }

Type::Type(Parser::Context& ctx) {
  while (ctx.hasToken({Tok::ASTERISK, Tok::LSQUARE}) ||
      (ctx.hasToken(Tok::CONST) && ctx.hasToken(Tok::ASTERISK, 1)))
    quals.emplace_back(std::make_unique<Qualifier>(ctx));
  cnst = ctx.maybeConsumeToken(Tok::CONST);
  if (ctx.hasToken(Tok::IDENT)) {
    name = ctx.consumeToken(Tok::IDENT)->toString(ctx.cts);
    if (ctx.hasToken(Tok::LANGLE)) {
      ctx.consumeToken(Tok::LANGLE);
      while (ctx.curToken()->type != Tok::RANGLE) {
        params.emplace_back(std::make_unique<Type>(ctx));
        if (!ctx.maybeConsumeToken(Tok::COMMA)) break;
      }
      ctx.consumeToken(Tok::RANGLE);
    }
  } else {
    name = ctx.consumeToken(BUILTIN_TYPES)->toString(ctx.cts);
  }
}
std::string Type::toString() const { return (fmt("Type %s") % name).str(); }
std::vector<Node*> Type::children() { return flattenChildren(quals, params); }

VarDecl::VarDecl(Parser::Context& ctx) {
  name = std::make_unique<VarRef>(ctx);
  ctx.consumeToken(Tok::COLON);
  type = std::make_unique<Type>(ctx);
}
std::string VarDecl::toString() const { return "VarDecl"; }
std::vector<Node*> VarDecl::children() { return flattenChildren(name, type); }

FnCallArgs::FnCallArgs(Parser::Context& ctx) {
  while (ctx.curToken()->type != Tok::RPAREN) {
    args.emplace_back(ExpressionParser(ctx).parse());
    if (!ctx.maybeConsumeToken(Tok::COMMA)) break;
  }
}
std::string FnCallArgs::toString() const { return "FnCallArgs"; }
std::vector<Node*> FnCallArgs::children() { return flattenChildren(args); }

FnSig::FnSig(Parser::Context& ctx) {
  ctx.consumeToken(Tok::FN);
  tname = std::make_unique<Typename>(ctx);
  ctx.consumeToken(Tok::LPAREN);
  while (ctx.curToken()->type != Tok::RPAREN) {
    params.emplace_back(std::make_unique<VarDecl>(ctx));
    if (!ctx.maybeConsumeToken(Tok::COMMA)) break;
  }
  ctx.consumeToken(Tok::RPAREN);
  ret_type = std::make_unique<Type>(ctx);
}
std::string FnSig::toString() const { return "FnSig"; }
std::vector<Node*> FnSig::children() { return flattenChildren(tname, params, ret_type); }

StmtBlk::StmtBlk(Parser::Context& ctx) {
  ctx.consumeToken(Tok::LBRACE);
  while (!ctx.hasToken(Tok::RBRACE)) {
    // TODO(Progress): match, asm
    switch (ctx.curToken()->type) {
    case Tok::RETURN:
      stmts.emplace_back(std::make_unique<Return>(ctx));
      ctx.consumeToken(Tok::SEMICOLON);
      break;
    case Tok::VAR:
      stmts.emplace_back(std::make_unique<Var>(ctx));
      ctx.consumeToken(Tok::SEMICOLON);
      break;
    case Tok::FOR: stmts.emplace_back(std::make_unique<For>(ctx)); break;
    case Tok::IF: stmts.emplace_back(std::make_unique<If>(ctx)); break;
    default:
      stmts.emplace_back(ExpressionParser(ctx).parse());
      ctx.consumeToken(Tok::SEMICOLON);
      break;
    }
  }
  ctx.consumeToken(Tok::RBRACE);
}
std::string StmtBlk::toString() const { return "StmtBlk"; }
std::vector<Node*> StmtBlk::children() { return flattenChildren(stmts); }

Return::Return(Parser::Context& ctx) {
  ctx.consumeToken(Tok::RETURN);
  ret = ExpressionParser(ctx).parse();
}
std::string Return::toString() const { return "Return"; }
std::vector<Node*> Return::children() { return flattenChildren(ret); }

Var::Var(Parser::Context& ctx) {
  ctx.consumeToken(Tok::VAR);
  decl = std::make_unique<VarDecl>(ctx);
  if (ctx.hasToken(Tok::EQUAL)) {
    ctx.consumeToken();
    defn = ExpressionParser(ctx).parse();
  }
}
std::string Var::toString() const { return "Var"; }
std::vector<Node*> Var::children() { return flattenChildren(decl, defn); }

For::For(Parser::Context& ctx) {
  ctx.consumeToken(Tok::FOR);
  ctx.consumeToken(Tok::LPAREN);
  var_defn = std::make_unique<Var>(ctx);
  ctx.consumeToken(Tok::SEMICOLON);
  cond = ExpressionParser(ctx).parse();
  ctx.consumeToken(Tok::SEMICOLON);
  update = ExpressionParser(ctx).parse();
  ctx.consumeToken(Tok::RPAREN);
  blk = std::make_unique<StmtBlk>(ctx);
}
std::string For::toString() const { return "For"; }
std::vector<Node*> For::children() { return flattenChildren(var_defn, cond, update, blk); }

If::If(Parser::Context& ctx) {
  ctx.consumeToken(Tok::IF);
  ctx.consumeToken(Tok::LPAREN);
  cond = ExpressionParser(ctx).parse();
  ctx.consumeToken(Tok::RPAREN);
  blk = std::make_unique<StmtBlk>(ctx);
}
std::string If::toString() const { return "If"; }
std::vector<Node*> If::children() { return flattenChildren(cond, blk); }

FnDefn::FnDefn(Parser::Context& ctx) {
  sig = std::make_unique<FnSig>(ctx);
  blk = std::make_unique<StmtBlk>(ctx);
}
std::string FnDefn::toString() const { return "FnDefn"; }
std::vector<Node*> FnDefn::children() { return flattenChildren(sig, blk); }

IntfDefn::IntfDefn(Parser::Context& ctx) {
  ctx.consumeToken(Tok::INTF);
  tname = std::make_unique<Typename>(ctx);
  ctx.consumeToken(Tok::LBRACE);
  while (ctx.hasToken(Tok::FN)) {
    decls.emplace_back(std::make_unique<FnSig>(ctx));
    ctx.consumeToken(Tok::SEMICOLON);
  }
  ctx.consumeToken(Tok::RBRACE);
}
std::string IntfDefn::toString() const { return "Intf"; }
std::vector<Node*> IntfDefn::children() { return flattenChildren(decls); }

EnumDefn::EnumDefn(Parser::Context& ctx) {
  ctx.consumeToken(Tok::ENUM);
  tname = std::make_unique<Typename>(ctx);
  ctx.consumeToken(Tok::LBRACE);
  while (!ctx.hasToken(Tok::RBRACE)) {
    if (ctx.hasToken(Tok::COMMA, 1))
      untyped_enums.emplace_back(ctx.consumeToken(Tok::IDENT)->toString(ctx.cts));
    else
      typed_enums.emplace_back(std::make_unique<VarDecl>(ctx));
    ctx.consumeToken(Tok::COMMA);
  }
  ctx.consumeToken(Tok::RBRACE);
}
std::string EnumDefn::toString() const {
  return (fmt("Enum (%1% untyped)") % untyped_enums.size()).str();
}
std::vector<Node*> EnumDefn::children() { return flattenChildren(tname, typed_enums); }

File::File(Parser::Context& ctx) {
  while (ctx.hasToken()) {
    switch (ctx.curToken()->type) {
    case Tok::INTF: intf_defns.emplace_back(std::make_unique<IntfDefn>(ctx)); break;
    case Tok::FN: fn_defns.emplace_back(std::make_unique<FnDefn>(ctx)); break;
    case Tok::ENUM: enum_defns.emplace_back(std::make_unique<EnumDefn>(ctx)); break;
    default: ctx.compileError("unexpected token"); break;
    }
  }
}
std::string File::toString() const { return "File"; }
std::vector<Node*> File::children() { return flattenChildren(intf_defns, fn_defns); }

}  // namespace memelang
