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

  constexpr Val(Hnd hnd, TypeId type) : hnd(hnd), type(type) {
    bug_unless(!(hnd != INVL_HND && type == INVL_TID));  // Don't allow storage with no type.
  }
  constexpr Val() : hnd(INVL_HND), type(INVL_TID) {}
  constexpr bool hasStorage() const { return hnd != INVL_HND; }

  COMPARISON(Val, hnd, type);
};

constexpr inline Val INVL_VAL = Val(INVL_HND, INVL_TID);

class Mapping {
public:
  std::map<std::string, TypeId> map;
  Exec* e;

  explicit Mapping(Exec* e) : e(e) {}
  std::string str() const;
  void merge(const Mapping& mapping);
  void unmerge(const Mapping& mapping);

  COMPARISON(Mapping, map);
};

// Map from (depth, breath) => dist
struct DistMap {
  std::map<std::pair<int, int>, int> m;

  bool operator<(const DistMap& o) const;
  std::string str() const;
};

struct DistResult {
  bool doable = false;
  DistMap d;
  Mapping m;
};

class WildcardInfo {
public:
  std::string name;

  explicit WildcardInfo(std::string name) : name(std::move(name)) {}
  int size() const { unimplemented(); }
  void resolve(const Mapping& m);
  DistResult distTo(const WildcardInfo& o, Exec* e) const;
  std::string str() const { return "Wildcard(" + name + ")"; }
  COMPARISON(WildcardInfo, name);
};

class IntfInfo {
public:
  ast::Intf* intf;
  Mapping m;

  explicit IntfInfo(ast::Intf* intf, Mapping m) : intf(intf), m(std::move(m)) {}
  int size() const { unimplemented(); }
  void resolve(const Mapping& m);
  DistResult distTo(const IntfInfo& o, Exec* e) const;
  std::string str() const { return "Intf(" + intf->tname->name + ")"; }
  COMPARISON(IntfInfo, intf, m);
};

class StructInfo {
public:
  struct MemberInfo {
    int offset;
    TypeId type;
    COMPARISON(MemberInfo, offset, type);
  };

  ast::Struct* st;
  Mapping m;
  std::map<std::string, MemberInfo> mems;

  explicit StructInfo(ast::Struct* st, Mapping m);
  int size() const {
    printf("SIZE OF STRUCT: %p %s %d %d\n", this, str().c_str(), size_, int(resolved_));
    bug_unless(resolved_);
    return size_;
  }
  void resolve(const Mapping& m);  // This must be called before the StructInfo can be used.
  DistResult distTo(const StructInfo& o, Exec* e) const;
  Val access(Hnd hnd, const std::string& member) const;
  Val access(Hnd hnd, int offset) const;
  std::string str() const { return "Struct(" + st->tname->name + +" m: " + m.str() + ")"; }
  COMPARISON(StructInfo, st, m, mems);  // Also include mems, as resolved status affects this.

private:
  int size_ = 0;
  bool resolved_ = false;
};

class EnumInfo {
public:
  ast::Enum* en;
  Mapping m;

  explicit EnumInfo(ast::Enum* en, Mapping m) : en(en), m(std::move(m)) {}
  int size() const {
    // TODO: Support typed enums
    return 4;
  }
  void resolve(const Mapping& m);
  DistResult distTo(const EnumInfo& o, Exec* e) const;
  Val access(const std::string& member) const;
  std::string str() const { return "Enum(" + en->tname->name + ")"; }
  COMPARISON(EnumInfo, en, m);
};

class BuiltinStorageInfo {
public:
  std::string name;

  explicit BuiltinStorageInfo(std::string name) : name(std::move(name)) {}
  int size() const {
    bug_unless(BUILTIN_SIZE.contains(name));
    return BUILTIN_SIZE.find(name)->second;
  }
  void resolve(const Mapping& m);
  DistResult distTo(const BuiltinStorageInfo& o, Exec* e) const;
  std::string str() const { return "BuiltinStorage(" + name + ")"; }
  COMPARISON(BuiltinStorageInfo, name);
};

class BuiltinFnInfo {
public:
  std::string name;

  explicit BuiltinFnInfo(std::string name) : name(std::move(name)) {}
  int size() const { unimplemented(); }
  void resolve(const Mapping& m);
  DistResult distTo(const BuiltinFnInfo& o, Exec* e) const;
  std::string str() const { return "BuiltinFn(" + name + ")"; }
  COMPARISON(BuiltinFnInfo, name);
};

class FnInfo {
public:
  ast::Fn* fn;
  Mapping m;
  FnInfo(ast::Fn* fn, Mapping m) : fn(fn), m(std::move(m)) {}
  int size() const { unimplemented(); }
  void resolve(const Mapping& m);
  DistResult distTo(const FnInfo& o, Exec* e) const;
  std::string str() const { return "FnInfo(fn: " + fn->str() + ", m: " + m.str() + ")"; }
  COMPARISON(FnInfo, fn, m);
};

class FnSetInfo {
public:
  std::vector<FnInfo> fns;  // N.B. These are ordered by preference.
  Val self;  // May be INVL_VAL.

  explicit FnSetInfo(std::vector<FnInfo> fns, Val self) : fns(std::move(fns)), self(self) {}
  int size() const { unimplemented(); }
  void resolve(const Mapping& m);
  DistResult distTo(const FnSetInfo& o, Exec* e) const;
  std::string str() const {
    const std::string s = join(
        fns.begin(), fns.end(), [](const auto& fn) { return fn.str(); }, ", ");
    return "FnSetInfo(" + s + ")";
  }
  COMPARISON(FnSetInfo, fns, self);
};

using TypeInfo = std::variant<IntfInfo, StructInfo, EnumInfo, FnInfo, FnSetInfo, WildcardInfo,
    BuiltinStorageInfo, BuiltinFnInfo>;

struct Qualifier {
  int array = 0;
  bool ptr = false;
  bool cnst = false;

  bool isSubsetOf(const Qualifier& o) const;
  bool hasIntersection(const Qualifier& o) const;
  std::string str() const;
  COMPARISON(Qualifier, array, ptr, cnst);
};

class Type {
public:
  TypeInfo info;
  bool cnst;
  bool ref;
  // Holds qualifiers from right to left (innermost first).
  std::vector<Qualifier> quals;

  explicit Type(const TypeInfo& info) : Type(info, false, false, {}) {}
  Type(TypeInfo info, bool cnst, bool ref, std::vector<Qualifier> quals)
      : info(std::move(info)), cnst(cnst), ref(ref), quals(std::move(quals)) {}
  int size() const;
  bool isPtr() const { return !quals.empty() && quals.back().ptr; }
  bool isRefOrPtr() const { return ref || isPtr();}
  bool isArray() const { return !quals.empty() && quals.back().array != 0; }
  bool isSubsetOf(const Type& o) const;  // Computes if this type is a subset of |o|. (e.g. const)
  // Computes whether there is a type that is a subset of this type and |o|.
  bool hasIntersection(const Type& o) const;
  // Resolves wildcards recursively within this type given a mapping. Any mappings for contained
  // types will also be used.
  void resolve(const Mapping& m);
  std::string str() const;

  COMPARISON(Type, info, cnst, ref, quals);
};

// |a| must be a resolved type - |b| can have unresolved wildcards. Returns what the mapping
// should be for |b| to turn into |a|.
DistResult distTo(const Type& a, const Type& b, Exec* e);
// Converts the path in |type| to a string - this doesn't include template parameters.
std::string typepathToString(ast::Type* type);
Type resolveType(const Type& t, const Mapping& m);

}  // namespace memelang::exec

#endif  // MEMELANG_TYPE_H
