#ifndef MEMELANG_AST_H
#define MEMELANG_AST_H

#include <vector>

#include "memelang/parser.h"
#include "memelang/tokeniser.h"

namespace memelang {

#define DEFNLT(type, ...) \
    auto getTie() const { return std::tie(__VA_ARGS__); } \
    bool operator<(const type& o) const { return getTie() < o.getTie(); } \
    explicit type(Parser::Ctx& c); \
    type(type&&) = default; \
    type& operator=(type&&) = default; \
    type(const type&) = delete; \
    type& operator=(const type&) = delete; \
    ~type() = default; \
    std::string toString() const override; \
    std::vector<Node*> children() override

struct Node {
  Tok tok = {};
  virtual ~Node() = default;

  virtual std::string toString() const = 0;
  virtual std::vector<Node*> children() = 0;
  void visit(const std::function<void(Node&, int)>& f, int depth = 0) {
    f(*this, depth);
    for (const auto& child : children()) child->visit(f, depth + 1);
  }
};

// Type related:
struct Typelist : public Node {
  std::vector<std::string> names;

  DEFNLT(Typelist, names);
};

struct Typename : public Node {
  std::string name;
  std::unique_ptr<Typelist> tlist;

  DEFNLT(Typename, name, tlist);
};

struct Qualifier : public Node {
  bool cnst = false;
  bool ptr = false;
  int64_t array = 0;

  DEFNLT(Qualifier, cnst, ptr, array);
};

struct Type : public Node {
  std::string name;
  std::vector<std::unique_ptr<Qualifier>> quals;
  std::vector<std::unique_ptr<Type>> params;
  bool cnst = false;

  DEFNLT(Type, name, quals, params, cnst);
};

// Expression related:

enum class Expr {
  ARRAY_ACCESS,
  MEMBER_ACCESS,
  FN_CALL,
  POSTFIX_INC,
  POSTFIX_DEC,
  PREFIX_INC,
  PREFIX_DEC,
  UNARY_NEGATE,
  UNARY_LINVERT,
  UNARY_BINVERT,
  UNARY_DEREF,
  UNARY_ADDR,
  MUL,
  DIV,
  MOD,
  ADD,
  SUB,
  LSHIFT,
  ARITH_RSHIFT,
  RSHIFT,
  LEQ,
  GEQ,
  LT,
  GT,
  EQ,
  NEQ,
  BAND,
  BXOR,
  BOR,
  LAND,
  LOR,
  TERNARY,
  ASSIGNMENT,
  COUNT
};

std::ostream& operator<<(std::ostream& str, const Expr& o);

struct BoolLit : public Node {
  bool val;

  DEFNLT(BoolLit, val);
};

struct IntLit : public Node {
  int64_t val;

  DEFNLT(IntLit, val);
};

struct CharLit : public Node {
  int32_t val;

  DEFNLT(CharLit, val);
};

struct StrLit : public Node {
  std::string val;

  DEFNLT(StrLit, val);
};

struct CompoundLit : public Node {
  std::vector<std::unique_ptr<Node>> lits;

  DEFNLT(CompoundLit, lits);
};

struct VarRef : public Node {
  std::string name;

  DEFNLT(VarRef, name);
};

struct Op : public Node {
  Expr type;
  bool is_binop = false;
  std::unique_ptr<Node> left;
  std::unique_ptr<Node> right;

  DEFNLT(Op, left, right);
};

// Function related:
struct VarDecl : public Node {
  std::unique_ptr<VarRef> ref;
  std::unique_ptr<Type> type;

  DEFNLT(VarDecl, ref, type);
};

struct FnCallArgs : public Node {
  std::vector<std::unique_ptr<Node>> args;

  DEFNLT(FnCallArgs, args);
};

struct FnSig : public Node {
  std::unique_ptr<Typename> tname;
  std::vector<std::unique_ptr<VarDecl>> params;
  std::unique_ptr<Type> ret_type;
  bool is_static = false;  // Only allowed in structs.

  DEFNLT(FnSig, tname, params, ret_type, is_static);
};

// Block related:
struct StmtBlk : public Node {
  std::vector<std::unique_ptr<Node>> stmts;

  DEFNLT(StmtBlk, stmts);
};

// Statement related:
struct Asm : public Node {
  std::string src;

  DEFNLT(Asm, src);
};

struct Return : public Node {
  std::unique_ptr<Node> ret;

  DEFNLT(Return, ret);
};

struct VarDefn : public Node {
  std::unique_ptr<VarDecl> decl;
  std::unique_ptr<Node> defn;

  DEFNLT(VarDefn, decl, defn);
};

struct For : public Node {
  std::unique_ptr<VarDefn> var_defn;
  std::unique_ptr<Node> cond;
  std::unique_ptr<Node> update;
  std::unique_ptr<StmtBlk> blk;

  DEFNLT(For, var_defn, cond, update, blk);
};

struct If : public Node {
  std::unique_ptr<Node> cond;
  std::unique_ptr<Node> then;
  std::unique_ptr<Node> els;

  DEFNLT(If, cond, then, els);
};

// Top level constructs:
struct Fn : public Node {
  std::unique_ptr<FnSig> sig;
  std::unique_ptr<StmtBlk> blk;

  DEFNLT(Fn, sig, blk);
};

struct Intf : public Node {
  std::unique_ptr<Typename> tname;
  std::vector<std::unique_ptr<FnSig>> sigs;

  DEFNLT(Intf, tname, sigs);
};

struct Enum : public Node {
  std::unique_ptr<Typename> tname;
  std::vector<std::unique_ptr<VarDecl>> typed_enums;
  std::vector<std::string> untyped_enums;

  DEFNLT(Enum, tname, typed_enums, untyped_enums);
};

struct Struct : public Node {
  std::unique_ptr<Typename> tname;
  std::vector<std::unique_ptr<VarDecl>> var_decls;
  std::vector<std::unique_ptr<Fn>> fns;

  DEFNLT(Struct, tname, var_decls, fns);
};

struct Impl : public Node {
  std::unique_ptr<Typelist> tlist;
  std::unique_ptr<Typename> tintf;
  std::unique_ptr<Typename> tstruct;
  std::vector<std::unique_ptr<Fn>> fns;

  DEFNLT(Impl, tlist, tintf, tstruct, fns);
};

struct File : public Node {
  std::vector<std::unique_ptr<Fn>> fns;
  std::vector<std::unique_ptr<Enum>> enums;
  std::vector<std::unique_ptr<Intf>> intfs;
  std::vector<std::unique_ptr<Struct>> structs;
  std::vector<std::unique_ptr<Impl>> impls;

  DEFNLT(File, fns, enums, intfs, structs, impls);
};

#undef DEFNLT

}  // namespace memelang

#endif  // MEMELANG_AST_H
