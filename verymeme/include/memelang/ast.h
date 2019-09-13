#ifndef MEMELANG_AST_H
#define MEMELANG_AST_H

#include <vector>

#include "memelang/parser.h"
#include "memelang/tokeniser.h"

namespace memelang {

#define DEFNLT(type, ...) \
  auto getTie() const { return std::tie(__VA_ARGS__); } \
  bool operator<(const type& o) const { return getTie() < o.getTie(); } \
  explicit type(Parser::Context& ctx); \
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
struct Expr : public Node {
  enum Type {
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
};

std::ostream& operator<<(std::ostream& str, const Expr::Type& o);

struct BoolLit : public Expr {
  bool val;

  DEFNLT(BoolLit, val);
};

struct IntLit : public Expr {
  int64_t val;

  DEFNLT(IntLit, val);
};

struct CharLit : public Expr {
  int32_t val;

  DEFNLT(CharLit, val);
};

struct StrLit : public Expr {
  std::string val;

  DEFNLT(StrLit, val);
};

struct CompoundLit : public Expr {
  std::vector<std::unique_ptr<Expr>> lits;

  DEFNLT(CompoundLit, lits);
};

struct VarRef : public Expr {
  std::string name;

  DEFNLT(VarRef, name);
};

struct Op : public Expr {
  Expr::Type type;
  bool is_binop = false;
  std::unique_ptr<Expr> left;
  std::unique_ptr<Expr> right;

  DEFNLT(Op, left, right);
};

// Function related:

struct VarDecl : public Node {
  std::unique_ptr<VarRef> name;
  std::unique_ptr<Type> type;

  DEFNLT(VarDecl, name, type);
};

struct FnCallArgs : public Expr {
  std::vector<std::unique_ptr<Expr>> args;

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
struct Return : public Node {
  std::unique_ptr<Expr> ret;

  DEFNLT(Return, ret);
};

struct Var : public Node {
  std::unique_ptr<VarDecl> decl;
  std::unique_ptr<Expr> defn;

  DEFNLT(Var, decl, defn);
};

struct For : public Node {
  std::unique_ptr<Var> var_defn;
  std::unique_ptr<Expr> cond;
  std::unique_ptr<Expr> update;
  std::unique_ptr<StmtBlk> blk;

  DEFNLT(For, var_defn, cond, update, blk);
};

struct If : public Node {
  std::unique_ptr<Expr> cond;
  std::unique_ptr<StmtBlk> blk;

  DEFNLT(If, cond, blk);
};

// Top level constructs:
struct FnDefn : public Node {
  std::unique_ptr<FnSig> sig;
  std::unique_ptr<StmtBlk> blk;

  DEFNLT(FnDefn, sig, blk);
};

struct IntfDefn : public Node {
  std::unique_ptr<Typename> tname;
  std::vector<std::unique_ptr<FnSig>> decls;

  DEFNLT(IntfDefn, tname, decls);
};

struct EnumDefn : public Node {
  std::unique_ptr<Typename> tname;
  std::vector<std::unique_ptr<VarDecl>> typed_enums;
  std::vector<std::string> untyped_enums;

  DEFNLT(EnumDefn, tname, typed_enums, untyped_enums);
};

struct File : public Node {
  std::vector<std::unique_ptr<IntfDefn>> intf_defns;
  std::vector<std::unique_ptr<FnDefn>> fn_defns;
  std::vector<std::unique_ptr<EnumDefn>> enum_defns;

  DEFNLT(File, intf_defns);
};

#undef DEFNLT

}  // namespace memelang

#endif  // MEMELANG_AST_H
