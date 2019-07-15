#ifndef MEMELANG_TYPES_H
#define MEMELANG_TYPES_H

#include "verymeme/common.h"

#include <vector>
#include <string>

namespace memelang {

#define DEFNLT(type, ...) \
  auto getTie() const { return std::tie(__VA_ARGS__); } \
  bool operator<(const type& o) const { return getTie() < o.getTie(); } \
  type(type&&) = default; \
  type& operator=(type&&) = default; \
  type(const type&) = delete; \
  type& operator=(const type&) = delete

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

  explicit Node(const Token& tok) : loc(tok.loc), size(tok.size) {}

  void generateIr() {}
};

struct Typename : public Node {
  std::string name;
  std::vector<std::string> typelist;

  DEFNLT(Typename, name, typelist);
};

struct Qualifier {
  bool cnst = false;
  bool ptr = false;
  int array = 0;

  DEFNLT(Qualifier, cnst, ptr, array);
};

struct Type : public Node {
  std::string name;
  std::vector<Qualifier> quals;
  std::vector<Type> params;

  DEFNLT(Type, name, quals, params);
};

struct FnVarDecl : public Node {
  std::string name;
  Type type;

  DEFNLT(FnVarDecl, name, type);
};

struct FnSig : public Node {
  Typename name;
  std::vector<FnVarDecl> params;
  Type ret_type;
  bool is_static = false;  // Only allowed in structs.

  DEFNLT(FnSig, name, params, ret_type, is_static);
};

struct IntfDefn : public Node {
  std::string name;
  Typename tname;
  std::vector<FnSig> decls;

  DEFNLT(IntfDefn, name, tname, decls);
};

struct File : public Node {
  std::vector<IntfDefn> intf_defns;
};

#undef DEFNLT

}  // namespace meme

#endif  // MEMELANG_TYPES_H
