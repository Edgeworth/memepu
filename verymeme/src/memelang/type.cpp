#include "memelang/type.h"

#include "memelang/constants.h"
#include "memelang/exec.h"
#include "verymeme/macros.h"
#include "verymeme/string_util.h"

namespace memelang::exec {

std::string Qualifier::toString() const {
  std::string q;
  if (array) q += std::to_string(array);
  if (ptr) q += "ptr";
  if (cnst) q += "const";
  return q.empty() ? "no quals" : q;
}

int Type::size() const {
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
  rep += join(
      quals.rbegin(), quals.rend(), [](auto& i) { return i.toString(); }, ", ");
  rep += "; mapping: " + mapping.toString() + ")";
  return rep;
}

void Type::addInnerType(TypeId id) {
  auto t = e_->scope().get(id);
  name = t.name;
  mapping.merge(t.mapping);
  auto new_quals = t.quals;
  // TODO: handle const here.
  new_quals.insert(new_quals.end(), quals.begin(), quals.end());
  quals = std::move(new_quals);
}

std::pair<int, Mapping> dist(
    const Type& a, const Type& b, const std::unordered_set<std::string>& wildcards, Exec* e) {
  // TODO: Our type must be fully specified for now.
  if (wildcards.contains(a.name)) unimplemented();
  // TODO: Match child template parameters too.
  // TODO: matching a wildcard should incur a distance cost?
  if (!wildcards.contains(b.name)) {
    if (a.name != b.name) return {Mapping::NOT_SUBTYPE, Mapping(e)};
    return {0, Mapping(e)};
  }

  int qual_idx = 0;
  Type wildcard_type = a;
  for (; qual_idx < int(b.quals.size()); ++qual_idx) {
    if (qual_idx >= int(a.quals.size()))
      return {Mapping::NOT_SUBTYPE, Mapping(e)};  // Too many qualifiers on wildcard - can't match.
    if (a.quals[qual_idx] != b.quals[qual_idx])
      return {Mapping::NOT_SUBTYPE, Mapping(e)};  // Qualifiers don't match.
    wildcard_type.quals.erase(wildcard_type.quals.begin());  // Pop front.
  }
  // For now, distance is how many qualifiers that were pushed into the wildcard (didn't match),
  // plus one for actually having a wildcard.
  Mapping m(e);
  m.wildcard_map[b.name] = e->scope().addType(wildcard_type);
  return {int(wildcard_type.quals.size()) + 1, std::move(m)};
}

std::string Mapping::toString() const {
  return join(
      wildcard_map.begin(), wildcard_map.end(),
      [this](auto& kv) { return kv.first + ":" + e_->scope().get(kv.second).toString(); }, ", ");
}

void Mapping::merge(const Mapping& m) {
  for (const auto& [wildcard, type] : m.wildcard_map) {
    if (wildcard_map.contains(wildcard)) e_->error("reusing template parameter " + wildcard);
    wildcard_map[wildcard] = type;
  }
}

void Mapping::unmerge(const Mapping& m) {
  for (const auto& [wildcard, _] : m.wildcard_map) {
    bug_unless(wildcard_map.contains(wildcard));
    wildcard_map.erase(wildcard);
  }
}

}  // namespace memelang::exec
