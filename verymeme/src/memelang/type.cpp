#include "memelang/type.h"

#include "memelang/constants.h"
#include "memelang/vm.h"
#include "verymeme/macros.h"

namespace memelang::exec {

std::string Qualifier::toString() const {
  std::string q;
  if (array) q += std::to_string(array);
  if (ptr) q += "ptr";
  if (cnst) q += "const";
  return q.empty() ? "no quals" : q;
}

int Type::size() const {
  printf("Computing size of type: %s\n", toString().c_str());
  auto iter = BUILTIN_SIZE.find(name);
  int size = 0;
  if (iter != BUILTIN_SIZE.end()) size = iter->second;
  for (const auto& qual : quals) {
    if (qual.ptr) size = sizeof(Hnd);
    else if (qual.array)
      size *= qual.array;
  }
  // TODO: size of user defined types
  if (!size) unimplemented();
  return size;
}

std::string Type::toString() const {
  std::string rep = "Type(name: " + name + "; quals: ";
  for (auto i = quals.rbegin(); i != quals.rend(); ++i) rep += i->toString() + ", ";
  rep += "; params: ";
  for (auto i = params.rbegin(); i != params.rend(); ++i) rep += (*i)->toString() + ", ";
  rep += ")";
  return rep;
}

Mapping dist(const Type& a, const Type& b, const std::unordered_set<std::string>& wildcards) {
  printf("Compute dist from %s to %s\n", a.toString().c_str(), b.toString().c_str());
  if (wildcards.contains(a.name))
    unimplemented();  // TODO: Our type must be fully specified for now.
  // TODO: Match child template parameters too.
  if (!wildcards.contains(b.name)) return a.name == b.name ? Mapping{.dist = 0} : NOT_SUBTYPE;

  int qual_idx = 0;
  Type wildcard_type = a;
  for (; qual_idx < int(b.quals.size()); ++qual_idx) {
    if (qual_idx >= int(a.quals.size()))
      return NOT_SUBTYPE;  // Too many qualifiers on wildcard - can't match.
    if (a.quals[qual_idx] != b.quals[qual_idx]) return NOT_SUBTYPE;  // Qualifiers don't match.
    wildcard_type.quals.erase(wildcard_type.quals.begin());  // Pop front.
  }
  // For now, distance is how many qualifiers that were pushed into the wildcard (didn't match).
  return {.dist = int(wildcard_type.quals.size()),
      .wildcard_map = {{b.name, std::move(wildcard_type)}}};
}

}  // namespace memelang::exec
