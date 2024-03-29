// Copyright 2019 E.
#ifndef MEMELANG_AST_H_
#define MEMELANG_AST_H_

#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "memelang/parser.h"
#include "memelang/tokeniser.h"
#include "verymeme/macros.h"

namespace memelang::ast {

#define DEFNLT(type, ...)                \
  COMPARISON(type, __VA_ARGS__)          \
  explicit type(Parser::Ctx& c);         \
  type(type&&) = default;                \
  type& operator=(type&&) = default;     \
  type(const type&) = delete;            \
  type& operator=(const type&) = delete; \
  ~type() = default;                     \
  std::string str() const override;      \
  std::vector<Node*> children() override

struct Node {
  Tok tok{};

  Node() = default;
  explicit Node(Parser::Ctx& c) : tok(*c.curTok()) {}
  virtual ~Node() = default;

  virtual std::string str() const = 0;
  virtual std::vector<Node*> children() = 0;
  void visit(const std::function<void(Node&, int)>& f, int depth = 0) {
    f(*this, depth);
    for (const auto& child : children()) child->visit(f, depth + 1);
  }
};

// Type related:
struct Typelist : public Node {
  std::vector<std::string> names;

  // Adds the wildcard names in this Typelist to the current context, to resolve types vs vars.
  void pushTypes(Parser::Ctx& c);
  void popTypes(Parser::Ctx& c);

  DEFNLT(Typelist, names);
};

struct Typename : public Node {
  std::string name;
  std::unique_ptr<Typelist> tlist;

  DEFNLT(Typename, name, tlist);
};

struct Qualifier : public Node {
  std::unique_ptr<Node> array;
  bool cnst = false;
  bool ptr = false;

  DEFNLT(Qualifier, array, cnst, ptr);
};

struct Type;

struct Ref : public Node {
  std::string name;
  std::vector<std::unique_ptr<Type>> params;

  DEFNLT(Ref, name, params);
};

struct Type : public Node {
  std::vector<std::unique_ptr<Ref>> path;
  std::vector<std::unique_ptr<Qualifier>> quals;
  bool cnst = false;
  bool ref = false;

  static std::unique_ptr<Type> tryParseType(Parser::Ctx& c);

  DEFNLT(Type, ref, path, quals, cnst);
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
  bool unsign;

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

struct CompoundLitFragment : public Node {
  std::string name;  // Optional.
  std::unique_ptr<Node> lit;

  DEFNLT(CompoundLitFragment, name, lit);
};

struct CompoundLit : public Node {
  std::unique_ptr<Type> type;  // Optional.
  std::vector<std::unique_ptr<CompoundLitFragment>> frags;

  CompoundLit(Parser::Ctx& c, std::unique_ptr<Type> t) : CompoundLit(c) { type = std::move(t); }

  DEFNLT(CompoundLit, frags);
};

struct Op : public Node {
  Expr type{};
  bool is_binop = false;
  std::unique_ptr<Node> left;
  std::unique_ptr<Node> right;

  DEFNLT(Op, left, right);
};

// Function related:
struct VarDecl : public Node {
  std::string name;
  std::unique_ptr<Type> type;

  DEFNLT(VarDecl, name, type);
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
struct If;
struct StmtBlk : public Node {
  StmtBlk(std::unique_ptr<If> ifst, Parser::Ctx& c);
  std::vector<std::unique_ptr<Node>> stmts;

  DEFNLT(StmtBlk, stmts);
};

// Statement related:
struct Asm : public Node {
  std::string src;

  DEFNLT(Asm, src);
};

struct Ret : public Node {
  std::unique_ptr<Node> ret;

  DEFNLT(Ret, ret);
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

struct While : public Node {
  std::unique_ptr<Node> cond;
  std::unique_ptr<StmtBlk> blk;

  DEFNLT(While, cond, blk);
};

struct If : public Node {
  std::unique_ptr<Node> cond;
  std::unique_ptr<StmtBlk> then;
  std::unique_ptr<StmtBlk> els;

  DEFNLT(If, cond, then, els);
};

struct Import : public Node {
  std::string name;

  DEFNLT(Import, name);
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
  std::vector<std::unique_ptr<VarDecl>> data_variants;
  std::vector<std::string> numbered_variants;

  DEFNLT(Enum, tname, data_variants, numbered_variants);
};

struct Struct : public Node {
  std::unique_ptr<Typename> tname;
  std::vector<std::unique_ptr<VarDecl>> var_decls;

  DEFNLT(Struct, tname, var_decls);
};

struct Impl : public Node {
  std::unique_ptr<Typelist> tlist;
  std::unique_ptr<Type> tintf;  // Optional.
  std::unique_ptr<Type> type;
  std::vector<std::unique_ptr<Fn>> fns;

  DEFNLT(Impl, tlist, tintf, type, fns);
};

struct File : public Node {
  std::vector<std::unique_ptr<Fn>> fns;
  std::vector<std::unique_ptr<Enum>> enums;
  std::vector<std::unique_ptr<Intf>> intfs;
  std::vector<std::unique_ptr<Struct>> structs;
  std::vector<std::unique_ptr<Impl>> impls;
  std::vector<std::unique_ptr<Import>> imports;
  std::string filename;

  DEFNLT(File, fns, enums, intfs, structs, impls, imports);
};

struct Module : public Node {
  explicit Module(const std::vector<std::unique_ptr<Parser::Ctx>>& ctxs);
  std::vector<std::unique_ptr<File>> files;

  DEFNLT(Module, files);
};

#undef DEFNLT

}  // namespace memelang::ast

#endif  // MEMELANG_AST_H_
