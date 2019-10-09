#include "memelang/ast.h"

#include <boost/format.hpp>

#include "memelang/expression.h"
#include "memelang/parser.h"
#include "memelang/tokeniser.h"
#include "verymeme/string_util.h"

namespace memelang::ast {

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

BoolLit::BoolLit(Parser::Ctx& c) : Node(c) { val = bool(c.consumeTok(Tok::BOOL_LIT)->int_val); }
std::string BoolLit::toString() const {
  return (fmt("BoolLit(%s)") % (val ? "true" : "false")).str();
}
std::vector<Node*> BoolLit::children() { return {}; }

IntLit::IntLit(Parser::Ctx& c) : Node(c) {
  unsign = c.hasTok(Tok::UINT_LIT);
  val = c.consumeTok({Tok::INT_LIT, Tok::UINT_LIT})->int_val;
}
std::string IntLit::toString() const {
  return (fmt("IntLit(%d%s)") % val % (unsign ? ", unsigned" : "")).str();
}
std::vector<Node*> IntLit::children() { return {}; }

CharLit::CharLit(Parser::Ctx& c) : Node(c) { val = int32_t(c.consumeTok(Tok::CHAR_LIT)->int_val); }
std::string CharLit::toString() const { return (fmt("CharLit(%c)") % val).str(); }
std::vector<Node*> CharLit::children() { return {}; }

StrLit::StrLit(Parser::Ctx& c) : Node(c) { val = c.consumeTok(Tok::STR_LIT)->str_val; }
std::string StrLit::toString() const { return (fmt("StrLit(%s)") % val).str(); }
std::vector<Node*> StrLit::children() { return {}; }

CompoundLit::CompoundLit(Parser::Ctx& c) : Node(c) {
  c.consumeTok(Tok::LBRACE);
  while (!c.hasTok(Tok::RBRACE)) {
    lits.emplace_back(ExprParser(c).parse());
    if (!c.maybeConsumeTok(Tok::COMMA)) break;
  }
  c.consumeTok(Tok::RBRACE);
}
std::string CompoundLit::toString() const { return "CompoundLit"; }
std::vector<Node*> CompoundLit::children() { return {}; }

Op::Op(Parser::Ctx& c) : Node(c) {}
std::string Op::toString() const { return (fmt("Op(%s)") % type).str(); }
std::vector<Node*> Op::children() { return flattenChildren(left, right); }

VarRef::VarRef(Parser::Ctx& c) : Node(c) { name = c.consumeTok(Tok::IDENT)->str_val; }
std::string VarRef::toString() const { return (fmt("VarRef(%s)") % name).str(); }
std::vector<Node*> VarRef::children() { return {}; }

Typelist::Typelist(Parser::Ctx& c) : Node(c) {
  c.consumeTok(Tok::LANGLE);
  while (true) {
    if (!c.hasTok(Tok::IDENT)) c.compileError("typelist must contain type");
    names.push_back(c.consumeTok()->str_val);
    if (c.hasTok(Tok::COMMA)) c.consumeTok();
    else
      break;
  }
  c.consumeTok(Tok::RANGLE);
}

std::string Typelist::toString() const { return "Typelist(" + join(names, ", ") + ")"; }
std::vector<Node*> Typelist::children() { return {}; }

Typename::Typename(Parser::Ctx& c) : Node(c) {
  name = c.consumeTok(Tok::IDENT)->str_val;
  if (c.hasTok(Tok::LANGLE)) tlist = std::make_unique<Typelist>(c);
}
std::string Typename::toString() const { return (fmt("Typename(%s)") % name).str(); }
std::vector<Node*> Typename::children() { return flattenChildren(tlist); }

Qualifier::Qualifier(Parser::Ctx& c) : Node(c) {
  if (c.hasTok(Tok::LSQUARE)) {
    c.consumeTok(Tok::LSQUARE);
    array = ExprParser(c).parse();
    c.consumeTok(Tok::RSQUARE);
  } else {
    if (c.maybeConsumeTok(Tok::CONST)) cnst = true;
    ptr = true;
    c.consumeTok(Tok::ASTERISK);
  }
}
std::string Qualifier::toString() const {
  return (fmt("Qualifier(const: %1% ptr: %2%, array: %3%)") % cnst % ptr %
      (array ? array->toString() : "0"))
      .str();
}
std::vector<Node*> Qualifier::children() { return flattenChildren(array); }

Type::Type(Parser::Ctx& c) : Node(c) {
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
  } else if (c.hasTok(Tok::AUTO)) {
    c.consumeTok();  // TODO remove?
  }
}
std::string Type::toString() const {
  return (fmt("Type(%s%s)") % (cnst ? "const " : "") % name).str();
}
std::vector<Node*> Type::children() { return flattenChildren(quals, params); }

VarDecl::VarDecl(Parser::Ctx& c) : Node(c) {
  ref = std::make_unique<VarRef>(c);
  c.consumeTok(Tok::COLON);
  type = std::make_unique<Type>(c);
}
std::string VarDecl::toString() const { return "VarDecl"; }
std::vector<Node*> VarDecl::children() { return flattenChildren(ref, type); }

FnCallArgs::FnCallArgs(Parser::Ctx& c) : Node(c) {
  while (c.curTok()->type != Tok::RPAREN) {
    args.emplace_back(ExprParser(c).parse());
    if (!c.maybeConsumeTok(Tok::COMMA)) break;
  }
}
std::string FnCallArgs::toString() const { return "FnCallArgs"; }
std::vector<Node*> FnCallArgs::children() { return flattenChildren(args); }

FnSig::FnSig(Parser::Ctx& c) : Node(c) {
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

StmtBlk::StmtBlk(Parser::Ctx& c) : Node(c) {
  c.consumeTok(Tok::LBRACE);
  while (!c.hasTok(Tok::RBRACE)) {
    if (c.hasTok(Tok::COLON, 1)) {  // Look one token ahead for colon
      stmts.emplace_back(std::make_unique<VarDefn>(c));
      c.consumeTok(Tok::SEMICOLON);
      continue;
    }
    // TODO(Progress): match
    switch (c.curTok()->type) {
    case Tok::RET:
      stmts.emplace_back(std::make_unique<Ret>(c));
      c.consumeTok(Tok::SEMICOLON);
      break;
    case Tok::FOR: stmts.emplace_back(std::make_unique<For>(c)); break;
    case Tok::WHILE: stmts.emplace_back(std::make_unique<While>(c)); break;
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
StmtBlk::StmtBlk(std::unique_ptr<If> ifst, Parser::Ctx& c) : Node(c) {
  stmts.emplace_back(std::move(ifst));
}
std::string StmtBlk::toString() const { return "StmtBlk"; }
std::vector<Node*> StmtBlk::children() { return flattenChildren(stmts); }

Asm::Asm(Parser::Ctx& c) : Node(c) { src = c.consumeTok(Tok::ASM)->str_val; }
std::string Asm::toString() const { return "Asm(" + src + ")"; }
std::vector<Node*> Asm::children() { return {}; }

Ret::Ret(Parser::Ctx& c) : Node(c) {
  c.consumeTok(Tok::RET);
  ret = ExprParser(c).parse();
}
std::string Ret::toString() const { return "Ret"; }
std::vector<Node*> Ret::children() { return flattenChildren(ret); }

VarDefn::VarDefn(Parser::Ctx& c) : Node(c) {
  decl = std::make_unique<VarDecl>(c);
  c.consumeTok(Tok::EQUAL);
  defn = ExprParser(c).parse();
}
std::string VarDefn::toString() const { return "VarDefn"; }
std::vector<Node*> VarDefn::children() { return flattenChildren(decl, defn); }

For::For(Parser::Ctx& c) : Node(c) {
  c.consumeTok(Tok::FOR);
  var_defn = std::make_unique<VarDefn>(c);
  c.consumeTok(Tok::SEMICOLON);
  cond = ExprParser(c).parse();
  c.consumeTok(Tok::SEMICOLON);
  update = ExprParser(c).parse();
  blk = std::make_unique<StmtBlk>(c);
}
std::string For::toString() const { return "For"; }
std::vector<Node*> For::children() { return flattenChildren(var_defn, cond, update, blk); }

While::While(Parser::Ctx& c) : Node(c) {
  c.consumeTok(Tok::WHILE);
  cond = ExprParser(c).parse();
  blk = std::make_unique<StmtBlk>(c);
}
std::string While::toString() const { return "While"; }
std::vector<Node*> While::children() { return flattenChildren(cond, blk); }

If::If(Parser::Ctx& c) : Node(c) {
  c.consumeTok(Tok::IF);
  cond = ExprParser(c).parse();
  then = std::make_unique<StmtBlk>(c);
  if (c.maybeConsumeTok(Tok::ELSE)) {
    if (c.hasTok(Tok::LBRACE)) els = std::make_unique<StmtBlk>(c);
    else
      els = std::make_unique<StmtBlk>(std::make_unique<If>(c), c);  // Special case for "else if"
  }
}
std::string If::toString() const { return "If"; }
std::vector<Node*> If::children() { return flattenChildren(cond, then, els); }

Fn::Fn(Parser::Ctx& c) : Node(c) {
  sig = std::make_unique<FnSig>(c);
  blk = std::make_unique<StmtBlk>(c);
}
std::string Fn::toString() const { return "Fn"; }
std::vector<Node*> Fn::children() { return flattenChildren(sig, blk); }

Intf::Intf(Parser::Ctx& c) : Node(c) {
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

Enum::Enum(Parser::Ctx& c) : Node(c) {
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

Struct::Struct(Parser::Ctx& c) : Node(c) {
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

Impl::Impl(Parser::Ctx& c) : Node(c) {
  c.consumeTok(Tok::IMPL);
  if (c.hasTok(Tok::LANGLE)) tlist = std::make_unique<Typelist>(c);
  tintf = std::make_unique<Type>(c);
  c.consumeTok(Tok::FOR);
  type = std::make_unique<Type>(c);
  c.consumeTok(Tok::LBRACE);
  while (!c.hasTok(Tok::RBRACE)) fns.emplace_back(std::make_unique<Fn>(c));
  c.consumeTok(Tok::RBRACE);
}
std::string Impl::toString() const { return "Impl"; }
std::vector<Node*> Impl::children() { return flattenChildren(tlist, tintf, type, fns); }

File::File(Parser::Ctx& c) : Node(c) {
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
std::vector<Node*> File::children() { return flattenChildren(fns, enums, intfs, structs, impls); }

}  // namespace memelang::ast
