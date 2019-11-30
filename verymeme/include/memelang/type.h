#ifndef MEMELANG_TYPE_H
#define MEMELANG_TYPE_H

#include <climits>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#include "memelang/ast.h"
#include "verymeme/macros.h"

namespace memelang::exec {

class Type;
class Exec;
using TypeId = int32_t;
constexpr inline TypeId INVALID_TYPEID = -1;

class Mapping {
public:
  constexpr static int NOT_SUBTYPE = INT_MAX / 2;
  std::map<std::string, TypeId> wildcard_map;

  explicit Mapping(Exec* e) : e_(e) {}
  std::string toString() const;
  void merge(const Mapping& mapping);
  void unmerge(const Mapping& mapping);

  COMPARISON(Mapping, wildcard_map);

private:
  Exec* e_;
};

struct Qualifier {
  int array = 0;
  bool ptr = false;
  bool cnst = false;

  std::string toString() const;

  COMPARISON(Qualifier, array, ptr, cnst);
};

class Type {
public:
  std::string name;
  bool cnst;
  // Holds qualifiers from right to left (innermost first).
  std::vector<Qualifier> quals;
  Mapping mapping;

  Type(std::string name, Exec* e) : Type(std::move(name), false, {}, e) {}
  Type(std::string name, bool cnst, std::vector<Qualifier> quals, Exec* e)
      : name(std::move(name)), cnst(cnst), quals(std::move(quals)), mapping(e), e_(e) {}
  int size() const;
  bool isPtr() const { return !quals.empty() && quals.back().ptr; }
  bool isArray() const { return !quals.empty() && quals.back().array != 0; }
  std::string toString() const;
  // E.g. *T => **u8. if parameter is *u8.
  void addInnerType(TypeId id);

  COMPARISON(Type, name, quals, mapping);

private:
  Exec* e_;
};

using Hnd = int32_t;
constexpr inline Hnd INVALID_HND = -1;

struct Val {
  Hnd hnd;  // Handle into VM memory.
  TypeId type;

  constexpr Val(Hnd hnd, TypeId type) : hnd(hnd), type(type) {}
  constexpr Val() : hnd(INVALID_HND), type(INVALID_TYPEID) {}
};

constexpr inline Val INVALID_VAL = Val(INVALID_HND, INVALID_TYPEID);

// TODO: Replace with type?
struct FnRef {
  ast::Fn* fn;
  Val ths;
  Mapping mapping;

  FnRef(ast::Fn* fn, Val ths, Mapping mapping) : fn(fn), ths(ths), mapping(std::move(mapping)) {}

  // FnRef identified by the fn and its instantiation.
  COMPARISON(FnRef, fn, mapping);
};

const inline FnRef INVALID_FNREF(nullptr, INVALID_VAL, Mapping(nullptr));

std::pair<int, Mapping> dist(
    const Type& a, const Type& b, const std::unordered_set<std::string>& wildcards, Exec* e);

}  // namespace memelang::exec

#endif  // MEMELANG_TYPE_H
