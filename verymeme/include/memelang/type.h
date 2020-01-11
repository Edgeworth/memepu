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
using Hnd = int32_t;
constexpr inline TypeId INVL_TID = -1;
constexpr inline Hnd INVL_HND = -1;

struct Val {
  Hnd hnd;  // Handle into VM memory. If invalid, this value represents a type.
  TypeId type;

  constexpr Val(Hnd hnd, TypeId type) : hnd(hnd), type(type) {}
  constexpr Val() : hnd(INVL_HND), type(INVL_TID) {}

  COMPARISON(Val, hnd, type);
};

constexpr inline Val INVL_VAL = Val(INVL_HND, INVL_TID);

class WildcardInfo {
public:
  std::string name;

  explicit WildcardInfo(std::string name) : name(std::move(name)) {}
  int size() const { return 0; }
  std::string str() const { return "Wildcard(" + name + ")"; }
  COMPARISON(WildcardInfo, name);
};

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

class IntfInfo {
public:
  ast::Intf* intf;
  Mapping m;

  explicit IntfInfo(ast::Intf* intf, Mapping m) : intf(intf), m(std::move(m)) {}
  int size() const { unimplemented(); }
  std::string str() const { return "Intf(" + intf->tname->name + ")"; }
  COMPARISON(IntfInfo, intf);
};

class StructInfo {
public:
  ast::Struct* st;
  Mapping m;

  explicit StructInfo(ast::Struct* st, Mapping m) : st(st), m(std::move(m)) {}
  int size() const { unimplemented(); }
  std::string str() const { return "Struct(" + st->tname->name + ")"; }
  COMPARISON(StructInfo, st);
};

class EnumInfo {
public:
  ast::Enum* en;
  Mapping m;

  explicit EnumInfo(ast::Enum* en, Mapping m) : en(en), m(std::move(m)) {}
  int size() const { unimplemented(); }
  std::string str() const { return "Enum(" + en->tname->name + ")"; }
  COMPARISON(EnumInfo, en);
};

class BuiltinStorageInfo {
public:
  std::string name;

  explicit BuiltinStorageInfo(std::string name) : name(std::move(name)) {}
  int size() const {
    bug_unless(BUILTIN_SIZE.contains(name));
    return BUILTIN_SIZE.find(name)->second;
  }
  std::string str() const { return "Builtin(" + name + ")"; }
  COMPARISON(BuiltinStorageInfo, name);
};

class BuiltinFnInfo {
public:
  std::string name;

  explicit BuiltinFnInfo(std::string name) : name(std::move(name)) {}
  int size() const { unimplemented(); }
  std::string str() const { return "Builtin(" + name + ")"; }
  COMPARISON(BuiltinFnInfo, name);
};

class FnInfo {
public:
  ast::Fn* fn;
  Mapping m;
  FnInfo(ast::Fn* fn, Mapping m) : fn(fn), m(std::move(m)) {}
  int size() const { unimplemented(); }
  std::string str() const { return "FnInfo(fn: " + fn->str() + ", m: " + m.str() + ")"; }
  COMPARISON(FnInfo, fn, m);
};

class FnSetInfo {
public:
  std::vector<FnInfo> fns;  // N.B. These are ordered by preference.

  explicit FnSetInfo(std::vector<FnInfo> fns) : fns(std::move(fns)) {}
  int size() const { unimplemented(); }
  std::string str() const {
    const std::string s = join(
        fns.begin(), fns.end(), [](const auto& fn) { return fn.str(); }, ", ");
    return "FnSetInfo(" + s + ")";
  }
  COMPARISON(FnSetInfo, fns);
};

using TypeInfo = std::variant<IntfInfo, StructInfo, EnumInfo, FnInfo, FnSetInfo, WildcardInfo,
    BuiltinStorageInfo, BuiltinFnInfo>;

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

  Type(const TypeInfo& info, Exec* e) : Type(info, false, {}, e) {}
  Type(TypeInfo info, bool cnst, std::vector<Qualifier> quals, Exec* e)
      : info(std::move(info)), cnst(cnst), quals(std::move(quals)), e_(e) {}
  int size() const;
  bool isPtr() const { return !quals.empty() && quals.back().ptr; }
  bool isArray() const { return !quals.empty() && quals.back().array != 0; }

  std::string str() const;

  COMPARISON(Type, info, cnst, quals);

private:
  Exec* e_;
};

std::pair<int, Mapping> dist(const Type& a, const Type& b, Exec* e);
// E.g. *T => **u8. if parameter is *u8.
void resolveWildcardWith(Type& wildcard, const Type& concrete);
// Converts the path in |type| to a string - this doesn't include template parameters.
std::string typepathToString(ast::Type* type);

}  // namespace memelang::exec

#endif  // MEMELANG_TYPE_H
