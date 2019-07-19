#ifndef MEMELANG_TYPES_H
#define MEMELANG_TYPES_H

#include "memelang/tokeniser.h"

#include <vector>
#include <string>

namespace memelang {

#define DEFNLT(type, ...) \
  auto getTie() const { return std::tie(__VA_ARGS__); } \
  bool operator<(const type& o) const { return getTie() < o.getTie(); } \
  type() = delete; \
  type(type&&) = default; \
  type& operator=(type&&) = default; \
  type(const type&) = delete; \
  type& operator=(const type&) = delete; \
  std::string toString() const override; \
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
  int loc;
  int size;

  explicit Node(const Token& tok);

  virtual std::string toString() const = 0;
  virtual void generateIr() const = 0;
};

struct Typename : public Node {
  std::string name;
  std::vector<std::string> typelist;

  explicit Typename(const Token& tok);

  DEFNLT(Typename, name, typelist);
};

struct Qualifier : public Node {
  bool cnst = false;
  bool ptr = false;
  int array = 0;

  explicit Qualifier(const Token& tok);

  DEFNLT(Qualifier, cnst, ptr, array);
};

struct Type : public Node {
  std::string name;
  std::vector<std::unique_ptr<Qualifier>> quals;
  std::vector<std::unique_ptr<Type>> params;

  explicit Type(const Token& tok);

  DEFNLT(Type, name, quals, params);
};

struct FnVarDecl : public Node {
  std::string name;
  std::unique_ptr<Type> type;

  explicit FnVarDecl(const Token& tok);

  DEFNLT(FnVarDecl, name, type);
};

struct FnSig : public Node {
  std::unique_ptr<Typename> name;
  std::vector<std::unique_ptr<FnVarDecl>> params;
  std::unique_ptr<Type> ret_type;
  bool is_static = false;  // Only allowed in structs.

  explicit FnSig(const Token& tok);

  DEFNLT(FnSig, name, params, ret_type, is_static);
};

struct IntfDefn : public Node {
  std::string name;
  std::unique_ptr<Typename> tname;
  std::vector<std::unique_ptr<FnSig>> decls;

  explicit IntfDefn(const Token& tok);

  DEFNLT(IntfDefn, name, tname, decls);
};

struct File : public Node {
  std::vector<std::unique_ptr<IntfDefn>> intf_defns;

  explicit File(const Token& tok);

  DEFNLT(File, intf_defns);
};

#undef DEFNLT

}  // namespace meme

#endif  // MEMELANG_TYPES_H
