#ifndef MEMELANG_PARSER_H
#define MEMELANG_PARSER_H

#include "memelang/tokeniser.h"
#include "memelang/file_contents.h"
#include <vector>
#include <memory>
#include <unordered_set>

namespace memelang {

struct File;

class Parser {
public:
  struct Context;

  Parser(const FileContents* contents, std::vector<Token> tokens);
  ~Parser();

  bool parse();
  const File* root() { return root_.get(); }
  std::string astToString();

private:
  std::unique_ptr<Context> ctx_;
  std::unique_ptr<File> root_;
};


#define DEFNLT(type, ...) \
  auto getTie() const { return std::tie(__VA_ARGS__); } \
  bool operator<(const type& o) const { return getTie() < o.getTie(); } \
  explicit type(Parser::Context& ctx); \
  type(type&&) = default; \
  type& operator=(type&&) = default; \
  type(const type&) = delete; \
  type& operator=(const type&) = delete; \
  std::string toString() const override; \
  std::vector<Node*> children() override; \
  void generateIr() const override

struct Node {
//  enum Type {
//    // Top level constructs:
//    INTF_DEFN, STRUCT_DEFN, FN_DEFN, ENUM_DEFN, IMPL_DEFN,
//    // Blocks:
//    STMT_BLK, STRUCT_BLK, IMPL_BLK, INTF_BLK, ENUM_BLK, MATCH_BLK,
//    // Statements:
//    VAR_DEFN, VAR_DECL, STMT_RET, STMT_FOR, STMT_IF, STMT_MATCH, STMT_ASM,
//    // Qualifiers:
//    TYPENAME, TYPELIST, STATIC,
//    // Expressions:
//    TYPE, INDEX, INTEGER_LITERAL, IDENT, ADD, SUB, MUL,
//    DIV, MOD, FUNCTION_CALL, POINTER, EQUALS, NOT_EQUALS, ACCESS, ASSIGN,
//    STRUCT_INITIALISER, LESS_THAN, GREATER_THAN, LESS_THAN_EQUAL, GREATER_THAN_EQUAL
//  } type;
  Token tok = {};

  virtual std::string toString() const = 0;
  virtual void generateIr() const = 0;
  virtual std::vector<Node*> children() = 0;
  virtual void visit(const std::function<void(Node&)>& f) {
    f(*this);
    for (const auto& child : children())
      child->visit(f);
  }
};

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

struct FnVarDecl : public Node {
  std::string name;
  std::unique_ptr<Type> type;

  DEFNLT(FnVarDecl, name, type);
};

struct FnSig : public Node {
  std::unique_ptr<Typename> tname;
  std::vector<std::unique_ptr<FnVarDecl>> params;
  std::unique_ptr<Type> ret_type;
  bool is_static = false;  // Only allowed in structs.

  DEFNLT(FnSig, tname, params, ret_type, is_static);
};

// Expression related:
// TODO: change variable declaration style to let a: type = asdf ?
struct Expr : public Node {

};

struct BinOp : public Expr {
  std::unique_ptr<Expr> left;
  std::unique_ptr<Expr> right;

  DEFNLT(BinOp, left, right);
};

// Statement related:

// Block related:
struct StmtBlk : public Node {
  std::vector<std::unique_ptr<Node>> stmts;

  DEFNLT(StmtBlk, stmts);
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

struct File : public Node {
  std::vector<std::unique_ptr<IntfDefn>> intf_defns;

  DEFNLT(File, intf_defns);
};

#undef DEFNLT

}  // namespace memelang

#endif  // MEMELANG_PARSER_H
