#ifndef MEMELANG_TYPE_H
#define MEMELANG_TYPE_H

#include <climits>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "verymeme/macros.h"

namespace memelang::exec {

struct Qualifier {
  int array = 0;
  bool ptr = false;
  bool cnst = false;

  std::string toString() const;

  COMPARISON(Qualifier, array, ptr, cnst);
};

struct Type {
  std::string name{};
  // Holds qualifiers from right to left (innermost first). By default must hold at least one item.
  std::vector<Qualifier> quals{{}};
  std::vector<const Type*> params{};

  int size() const;
  bool isPtr() const { return quals.back().ptr; }
  bool isArray() const { return quals.back().array != 0; }
  std::string toString() const;
  // E.g. *T => **u8. if parameter is *u8.
  void addInnerType(const Type& t);

  COMPARISON(Type, name, quals, params);
};

struct Mapping {
  int dist{INT_MAX / 2};
  std::map<std::string, Type> wildcard_map{};

  COMPARISON(Mapping, dist, wildcard_map);
};

const static Mapping NOT_SUBTYPE = {};

struct Typename {
  std::string name{};
  std::vector<std::string> tlist{};

  COMPARISON(Typename, name, tlist);
};

Mapping dist(const Type& a, const Type& b, const std::unordered_set<std::string>& wildcards);

}  // namespace memelang::exec

#endif  // MEMELANG_TYPE_H
