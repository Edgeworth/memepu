#ifndef MEMELANG_TYPE_H
#define MEMELANG_TYPE_H

#include <climits>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <variant>
#include <vector>

#include "memelang/ast.h"
#include "memelang/constants.h"
#include "verymeme/macros.h"
#include "verymeme/string_util.h"

namespace memelang::exec {

class Type;
class Exec;
using TypeId = int32_t;
constexpr inline TypeId INVALID_TYPEID = -1;
using Hnd = int32_t;
constexpr inline Hnd INVALID_HND = -1;

struct Val {
  Hnd hnd;  // Handle into VM memory. If invalid, this value represents a type.
  TypeId type;

  constexpr Val(Hnd hnd, TypeId type) : hnd(hnd), type(type) {}
  constexpr Val() : hnd(INVALID_HND), type(INVALID_TYPEID) {}
};

constexpr inline Val INVALID_VAL = Val(INVALID_HND, INVALID_TYPEID);

class IntfInfo {
public:
  ast::Intf* intf;

  explicit IntfInfo(ast::Intf* intf) : intf(intf) {}
  int size() const { unimplemented(); }
  ast::Typename* tname() { return intf->tname.get(); }
  std::string str() const { return "Intf(" + intf->tname->name + ")"; }
  COMPARISON(IntfInfo, intf);
};

class StructInfo {
public:
  ast::Struct* st;

  explicit StructInfo(ast::Struct* st) : st(st) {}
  int size() const { unimplemented(); }
  ast::Typename* tname() { return st->tname.get(); }
  std::string str() const { return "Struct(" + st->tname->name + ")"; }
  COMPARISON(StructInfo, st);
};

class EnumInfo {
public:
  ast::Enum* en;

  explicit EnumInfo(ast::Enum* en) : en(en) {}
  int size() const { unimplemented(); }
  ast::Typename* tname() { return en->tname.get(); }
  std::string str() const { return "Enum(" + en->tname->name + ")"; }
  COMPARISON(EnumInfo, en);
};

class BuiltinStorageInfo {
public:
  std::string name;

  explicit BuiltinStorageInfo(const std::string& name) : name(name) {}
  int size() const {
    bug_unless(BUILTIN_SIZE.contains(name));
    return BUILTIN_SIZE.find(name)->second;
  }
  ast::Typename* tname() { return nullptr; }
  std::string str() const { return "Builtin(" + name + ")"; }
  COMPARISON(BuiltinStorageInfo, name);
};

class BuiltinFnInfo {
public:
  std::string name;

  explicit BuiltinFnInfo(std::string name) : name(std::move(name)) {}
  int size() const { unimplemented(); }
  ast::Typename* tname() { return nullptr; }
  std::string str() const { return "Builtin(" + name + ")"; }
  COMPARISON(BuiltinFnInfo, name);
};

class WildcardInfo {
public:
  std::string name;

  explicit WildcardInfo(std::string name) : name(std::move(name)) {}
  int size() const { return 0; }
  ast::Typename* tname() { return nullptr; }
  std::string str() const { return "Wildcard(" + name + ")"; }
  COMPARISON(WildcardInfo, name);
};

class FnInfo {
public:
  ast::Fn* fn;

  explicit FnInfo(ast::Fn* fn) : fn(fn) {}
  int size() const { return sizeof(Hnd); }
  ast::Typename* tname() { return fn->sig->tname.get(); }
  std::string str() const { return "FnInfo(" + fn->sig->tname->name + ")"; }
  COMPARISON(FnInfo, fn);
};

using TypeInfo = std::variant<IntfInfo, StructInfo, EnumInfo, BuiltinStorageInfo, WildcardInfo,
    FnInfo, BuiltinFnInfo>;

class Mapping {
public:
  constexpr static int NOT_SUBTYPE = INT_MAX / 2;
  std::map<WildcardInfo, TypeId> map;

  explicit Mapping(Exec* e) : e_(e) {}

  std::string str() const;
  void merge(const Mapping& mapping);
  void unmerge(const Mapping& mapping);

  COMPARISON(Mapping, map);

private:
  Exec* e_;
};

struct Qualifier {
  int array = 0;
  bool ptr = false;
  bool cnst = false;

  std::string str() const;

  COMPARISON(Qualifier, array, ptr, cnst);
};

class Type {
public:
  TypeInfo info;
  bool cnst;
  // Holds qualifiers from right to left (innermost first).
  std::vector<Qualifier> quals;
  Mapping m;

  Type(const TypeInfo& info, Exec* e) : Type(info, false, {}, Mapping(e), e) {}
  Type(TypeInfo info, bool cnst, std::vector<Qualifier> quals, Mapping m, Exec* e)
      : info(std::move(info)), cnst(cnst), quals(std::move(quals)), m(std::move(m)), e_(e) {}
  int size() const;
  bool isPtr() const { return !quals.empty() && quals.back().ptr; }
  bool isArray() const { return !quals.empty() && quals.back().array != 0; }

  std::string str() const;
  // E.g. *T => **u8. if parameter is *u8.
  // TODO: move to outside function?
  void resolveWildcardWith(TypeId concrete);

  COMPARISON(Type, info, quals, m);

private:
  Exec* e_;
};

std::pair<int, Mapping> dist(TypeId aid, TypeId bid, Exec* e);
Mapping typelistToMapping(ast::Typelist* tlist, Exec* e);
// Converts the path in |type| to a string - this doesn't include template parameters.
std::string typepathToString(ast::Type* type);

}  // namespace memelang::exec

#endif  // MEMELANG_TYPE_H
