#include "memelang/type.h"

#include "memelang/constants.h"
#include "memelang/exec.h"
#include "verymeme/macros.h"
#include "verymeme/string_util.h"

namespace memelang::exec {

std::string Qualifier::str() const {
  std::string q;
  if (array) q += std::to_string(array);
  if (ptr) q += "ptr";
  if (cnst) q += "const";
  return q.empty() ? "no quals" : q;
}

int Type::size() const {
  int size = std::visit([](const auto& v) { return v.size(); }, info);
  for (const auto& qual : quals) {
    if (qual.ptr) size = sizeof(Hnd);
    else if (qual.array)
      size *= qual.array;
  }
  return size;
}

std::string Type::str() const {
  std::string info_str = std::visit([](const auto& v) { return v.str(); }, info);
  std::string rep = "Type(" + info_str + "; quals: ";
  rep += join(
      quals.rbegin(), quals.rend(), [](auto& i) { return i.str(); }, ", ");
  rep += "; mapping: " + m.str() + ")";
  return rep;
}

void Type::resolveWildcardWith(TypeId concrete) {
  const auto& t = e_->scope().t(concrete);
  info = t.info;
  m.merge(t.m);
  auto new_quals = t.quals;
  // TODO: handle const here.
  new_quals.insert(new_quals.end(), quals.begin(), quals.end());
  quals = std::move(new_quals);
}

std::string Mapping::str() const {
  auto f = [this](auto& kv) {
    if (kv.second == INVALID_TYPEID) return "unmapped " + kv.first.str();
    return kv.first.str() + ":" + e_->scope().t(kv.second).str();
  };
  return join(map.begin(), map.end(), f, ", ");
}

void Mapping::merge(const Mapping& m) {
  for (const auto& [wildcard, type] : m.map) {
    auto iter = map.find(wildcard);
    // Allow overwriting unmapped wildcards.
    if (iter != map.end() && iter->second != INVALID_TYPEID)
      e_->error("duplicate template parameter " + wildcard.str());
    map[wildcard] = type;
  }
}

void Mapping::unmerge(const Mapping& m) {
  for (const auto& [wildcard, _] : m.map) {
    bug_unless(map.contains(wildcard));
    map.erase(wildcard);
  }
}

std::pair<int, Mapping> dist(TypeId aid, TypeId bid, Exec* e) {
  const auto& a = e->scope().t(aid);
  const auto& b = e->scope().t(bid);
  if (aid == bid) return {0, a.m};  // Same types have no distance cost.

  // TODO: Our type must be fully specified for now.
  if (std::holds_alternative<WildcardInfo>(a.info)) unimplemented();
  // TODO: Match child template parameters too.
  if (!std::holds_alternative<WildcardInfo>(b.info)) return {Mapping::NOT_SUBTYPE, Mapping(e)};

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
  m.map[std::get<WildcardInfo>(b.info)] = e->scope().addType(wildcard_type);
  return {int(wildcard_type.quals.size()) + 1, std::move(m)};
}

Mapping typelistToMapping(ast::Typelist* tlist, Exec* e) {
  Mapping m(e);
  if (!tlist) return m;
  for (const auto& wildcard : tlist->names) m.map.emplace(WildcardInfo(wildcard), INVALID_TYPEID);
  return m;
}

}  // namespace memelang::exec
