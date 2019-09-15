#include "memelang/ast.h"

#include <boost/format.hpp>

#include "memelang/expression.h"
#include "memelang/parser.h"
#include "memelang/tokeniser.h"
#include "verymeme/string_util.h"

namespace memelang {

using fmt = boost::format;

namespace {

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

std::ostream& operator<<(std::ostream& str, const Expr& o) {
  const static std::string EXPR_TYPES[] = {"ARRAY_ACCESS", "MEMBER_ACCESS", "FN_CALL",
      "POSTFIX_INC", "POSTFIX_DEC", "PREFIX_INC", "PREFIX_DEC", "UNARY_NEGATE", "UNARY_LINVERT",
      "UNARY_BINVERT", "UNARY_DEREF", "UNARY_ADDR", "MUL", "DIV", "MOD", "ADD", "SUB", "LSHIFT",
      "ARITH_RSHIFT", "RSHIFT", "LEQ", "GEQ", "LT", "GT", "EQ", "NEQ", "BAND", "BXOR", "BOR",
      "LAND", "LOR", "TERNARY", "ASSIGNMENT"};
  return outputEnum(str, o, EXPR_TYPES);
}

BoolLit::BoolLit(Parser::Ctx& c) { val = bool(c.consumeTok(Tok::BOOL_LIT)->int_val); }
std::string BoolLit::toString() const {
  return (fmt("BoolLit(%s)") % (val ? "true" : "false")).str();
}
std::vector<Node*> BoolLit::children() { return {}; }

IntLit::IntLit(Parser::Ctx& c) { val = c.consumeTok(Tok::INT_LIT)->int_val; }
std::string IntLit::toString() const { return (fmt("IntLit(%d)") % val).str(); }
std::vector<Node*> IntLit::children() { return {}; }

CharLit::CharLit(Parser::Ctx& c) { val = int32_t(c.consumeTok(Tok::CHAR_LIT)->int_val); }
std::string CharLit::toString() const { return (fmt("CharLit(%c)") % val).str(); }
std::vector<Node*> CharLit::children() { return {}; }

StrLit::StrLit(Parser::Ctx& c) { val = c.consumeTok(Tok::STR_LIT)->str_val; }
std::string StrLit::toString() const { return (fmt("StrLit(%s)") % val).str(); }
std::vector<Node*> StrLit::children() { return {}; }

CompoundLit::CompoundLit(Parser::Ctx& c) {
  c.consumeTok(Tok::LBRACE);
  while (!c.hasTok(Tok::RBRACE)) {
    lits.emplace_back(ExprParser(c).parse());
    if (!c.maybeConsumeTok(Tok::COMMA)) break;
  }
  c.consumeTok(Tok::RBRACE);
}
std::string CompoundLit::toString() const { return "CompoundLit"; }
std::vector<Node*> CompoundLit::children() { return {}; }

Op::Op(Parser::Ctx&) {}
std::string Op::toString() const { return (fmt("Op(%s)") % type).str(); }
std::vector<Node*> Op::children() { return flattenChildren(left, right); }

VarRef::VarRef(Parser::Ctx& c) { name = c.consumeTok(Tok::IDENT)->str_val; }
std::string VarRef::toString() const { return (fmt("VarRef(%s)") % name).str(); }
std::vector<Node*> VarRef::children() { return {}; }

Typelist::Typelist(Parser::Ctx& c) {
  c.consumeTok(Tok::LANGLE);
  while (true) {
    names.push_back(c.consumeTok(Tok::IDENT)->str_val);
    if (c.hasTok(Tok::COMMA)) c.consumeTok();
    else
      break;
  }
  c.consumeTok(Tok::RANGLE);
}

std::string Typelist::toString() const { return "Typelist(" + join(names, ", ") + ")"; }
std::vector<Node*> Typelist::children() { return {}; }

Typename::Typename(Parser::Ctx& c) {
  name = c.consumeTok(Tok::IDENT)->str_val;
  if (c.hasTok(Tok::LANGLE)) tlist = std::make_unique<Typelist>(c);
}
std::string Typename::toString() const { return (fmt("Typename(%s)") % name).str(); }
std::vector<Node*> Typename::children() { return flattenChildren(tlist); }

Qualifier::Qualifier(Parser::Ctx& c) {
  if (c.hasTok(Tok::LSQUARE)) {
    c.consumeTok(Tok::LSQUARE);
    array = c.consumeTok(Tok::INT_LIT)->int_val;
    c.consumeTok(Tok::RSQUARE);
  } else {
    if (c.maybeConsumeTok(Tok::CONST)) cnst = true;
    ptr = true;
    c.consumeTok(Tok::ASTERISK);
  }
}
std::string Qualifier::toString() const {
  return (fmt("Qualifier(const: %1% ptr: %2%, array: %3%)") % cnst % ptr % array).str();
}
std::vector<Node*> Qualifier::children() { return {}; }

Type::Type(Parser::Ctx& c) {
  while (c.hasTok({Tok::ASTERISK, Tok::LSQUARE}) ||
      (c.hasTok(Tok::CONST) && c.hasTok(Tok::ASTERISK, 1)))
    quals.emplace_back(std::make_unique<Qualifier>(c));
  cnst = c.maybeConsumeTok(Tok::CONST);
  if (c.hasTok(Tok::IDENT)) {
    name = c.consumeTok(Tok::IDENT)->str_val;
    if (c.hasTok(Tok::LANGLE)) {
      c.consumeTok(Tok::LANGLE);
      while (c.curTok()->type != Tok::RANGLE) {
        params.emplace_back(std::make_unique<Type>(c));
        if (!c.maybeConsumeTok(Tok::COMMA)) break;
      }
      c.consumeTok(Tok::RANGLE);
    }
  } else {
    name = c.consumeTok(BUILTIN_TYPES)->str_val;
  }
}
std::string Type::toString() const {
  return (fmt("Type(%s%s)") % (cnst ? "const " : "") % name).str();
}
std::vector<Node*> Type::children() { return flattenChildren(quals, params); }

VarDecl::VarDecl(Parser::Ctx& c) {
  name = std::make_unique<VarRef>(c);
  c.consumeTok(Tok::COLON);
  type = std::make_unique<Type>(c);
}
std::string VarDecl::toString() const { return "VarDecl"; }
std::vector<Node*> VarDecl::children() { return flattenChildren(name, type); }

FnCallArgs::FnCallArgs(Parser::Ctx& c) {
  while (c.curTok()->type != Tok::RPAREN) {
    args.emplace_back(ExprParser(c).parse());
    if (!c.maybeConsumeTok(Tok::COMMA)) break;
  }
}
std::string FnCallArgs::toString() const { return "FnCallArgs"; }
std::vector<Node*> FnCallArgs::children() { return flattenChildren(args); }

FnSig::FnSig(Parser::Ctx& c) {
  is_static = c.maybeConsumeTok(Tok::STATIC);
  c.consumeTok(Tok::FN);
  tname = std::make_unique<Typename>(c);
  c.consumeTok(Tok::LPAREN);
  while (c.curTok()->type != Tok::RPAREN) {
    params.emplace_back(std::make_unique<VarDecl>(c));
    if (!c.maybeConsumeTok(Tok::COMMA)) break;
  }
  c.consumeTok(Tok::RPAREN);
  ret_type = std::make_unique<Type>(c);
}
std::string FnSig::toString() const { return "FnSig"; }
std::vector<Node*> FnSig::children() { return flattenChildren(tname, params, ret_type); }

StmtBlk::StmtBlk(Parser::Ctx& c) {
  c.consumeTok(Tok::LBRACE);
  while (!c.hasTok(Tok::RBRACE)) {
    // TODO(Progress): match
    switch (c.curTok()->type) {
    case Tok::RETURN:
      stmts.emplace_back(std::make_unique<Return>(c));
      c.consumeTok(Tok::SEMICOLON);
      break;
    case Tok::VAR:
      stmts.emplace_back(std::make_unique<Var>(c));
      c.consumeTok(Tok::SEMICOLON);
      break;
    case Tok::FOR: stmts.emplace_back(std::make_unique<For>(c)); break;
    case Tok::IF: stmts.emplace_back(std::make_unique<If>(c)); break;
    case Tok::ASM: stmts.emplace_back(std::make_unique<Asm>(c)); break;
    default:
      stmts.emplace_back(ExprParser(c).parse());
      c.consumeTok(Tok::SEMICOLON);
      break;
    }
  }
  c.consumeTok(Tok::RBRACE);
}
std::string StmtBlk::toString() const { return "StmtBlk"; }
std::vector<Node*> StmtBlk::children() { return flattenChildren(stmts); }

Asm::Asm(Parser::Ctx& c) { src = c.consumeTok(Tok::ASM)->str_val; }
std::string Asm::toString() const { return "Asm(" + src + ")"; }
std::vector<Node*> Asm::children() { return {}; }

Return::Return(Parser::Ctx& c) {
  c.consumeTok(Tok::RETURN);
  ret = ExprParser(c).parse();
}
std::string Return::toString() const { return "Return"; }
std::vector<Node*> Return::children() { return flattenChildren(ret); }

Var::Var(Parser::Ctx& c) {
  c.consumeTok(Tok::VAR);
  decl = std::make_unique<VarDecl>(c);
  if (c.hasTok(Tok::EQUAL)) {
    c.consumeTok();
    defn = ExprParser(c).parse();
  }
}
std::string Var::toString() const { return "Var"; }
std::vector<Node*> Var::children() { return flattenChildren(decl, defn); }

For::For(Parser::Ctx& c) {
  c.consumeTok(Tok::FOR);
  c.consumeTok(Tok::LPAREN);
  var_defn = std::make_unique<Var>(c);
  c.consumeTok(Tok::SEMICOLON);
  cond = ExprParser(c).parse();
  c.consumeTok(Tok::SEMICOLON);
  update = ExprParser(c).parse();
  c.consumeTok(Tok::RPAREN);
  blk = std::make_unique<StmtBlk>(c);
}
std::string For::toString() const { return "For"; }
std::vector<Node*> For::children() { return flattenChildren(var_defn, cond, update, blk); }

If::If(Parser::Ctx& c) {
  c.consumeTok(Tok::IF);
  c.consumeTok(Tok::LPAREN);
  cond = ExprParser(c).parse();
  c.consumeTok(Tok::RPAREN);
  then = std::make_unique<StmtBlk>(c);
  if (c.maybeConsumeTok(Tok::ELSE)) {
    if (c.hasTok(Tok::LBRACE)) els = std::make_unique<StmtBlk>(c);
    else els = std::make_unique<If>(c);  // Special case for "else if"
  }
}
std::string If::toString() const { return "If"; }
std::vector<Node*> If::children() { return flattenChildren(cond, then, els); }

Fn::Fn(Parser::Ctx& c) {
  sig = std::make_unique<FnSig>(c);
  blk = std::make_unique<StmtBlk>(c);
}
std::string Fn::toString() const { return "Fn"; }
std::vector<Node*> Fn::children() { return flattenChildren(sig, blk); }

Intf::Intf(Parser::Ctx& c) {
  c.consumeTok(Tok::INTF);
  tname = std::make_unique<Typename>(c);
  c.consumeTok(Tok::LBRACE);
  while (c.hasTok(Tok::FN)) {
    sigs.emplace_back(std::make_unique<FnSig>(c));
    c.consumeTok(Tok::SEMICOLON);
  }
  c.consumeTok(Tok::RBRACE);
}
std::string Intf::toString() const { return "Intf"; }
std::vector<Node*> Intf::children() { return flattenChildren(sigs); }

Enum::Enum(Parser::Ctx& c) {
  c.consumeTok(Tok::ENUM);
  tname = std::make_unique<Typename>(c);
  c.consumeTok(Tok::LBRACE);
  while (!c.hasTok(Tok::RBRACE)) {
    if (c.hasTok(Tok::COMMA, 1)) untyped_enums.emplace_back(c.consumeTok(Tok::IDENT)->str_val);
    else
      typed_enums.emplace_back(std::make_unique<VarDecl>(c));
    c.consumeTok(Tok::COMMA);
  }
  c.consumeTok(Tok::RBRACE);
}
std::string Enum::toString() const {
  return (fmt("Enum(%1% untyped)") % untyped_enums.size()).str();
}
std::vector<Node*> Enum::children() { return flattenChildren(tname, typed_enums); }

Struct::Struct(Parser::Ctx& c) {
  c.consumeTok(Tok::STRUCT);
  tname = std::make_unique<Typename>(c);
  c.consumeTok(Tok::LBRACE);
  while (!c.hasTok(Tok::RBRACE)) {
    if (c.hasTok({Tok::FN, Tok::STATIC})) fns.emplace_back(std::make_unique<Fn>(c));
    else {
      var_decls.emplace_back(std::make_unique<VarDecl>(c));
      c.consumeTok(Tok::SEMICOLON);
    }
  }
  c.consumeTok(Tok::RBRACE);
}
std::string Struct::toString() const { return "Struct"; }
std::vector<Node*> Struct::children() { return flattenChildren(tname, var_decls, fns); }

Impl::Impl(Parser::Ctx& c) {
  c.consumeTok(Tok::IMPL);
  if (c.hasTok(Tok::LANGLE)) tlist = std::make_unique<Typelist>(c);
  tintf = std::make_unique<Typename>(c);
  c.consumeTok(Tok::FOR);
  tstruct = std::make_unique<Typename>(c);
  c.consumeTok(Tok::LBRACE);
  while (!c.hasTok(Tok::RBRACE)) fns.emplace_back(std::make_unique<Fn>(c));
  c.consumeTok(Tok::RBRACE);
}
std::string Impl::toString() const { return "Impl"; }
std::vector<Node*> Impl::children() { return flattenChildren(tlist, tintf, tstruct, fns); }

File::File(Parser::Ctx& c) {
  while (c.hasTok()) {
    switch (c.curTok()->type) {
    case Tok::FN: fns.emplace_back(std::make_unique<Fn>(c)); break;
    case Tok::ENUM: enums.emplace_back(std::make_unique<Enum>(c)); break;
    case Tok::INTF: intfs.emplace_back(std::make_unique<Intf>(c)); break;
    case Tok::STRUCT: structs.emplace_back(std::make_unique<Struct>(c)); break;
    case Tok::IMPL: impls.emplace_back(std::make_unique<Impl>(c)); break;
    default: c.compileError("unexpected token"); break;
    }
  }
}
std::string File::toString() const { return "File"; }
std::vector<Node*> File::children() { return flattenChildren(fns, enums, intfs, structs); }

}  // namespace memelang
