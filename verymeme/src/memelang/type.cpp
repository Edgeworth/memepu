#include "memelang/type.h"

#include "memelang/constants.h"
#include "memelang/exec.h"
#include "verymeme/macros.h"
#include "verymeme/string_util.h"

namespace memelang::exec {

std::pair<int, Mapping> distFrom(const Type& a, const Type& b, Exec* e) {
  if (a.isSubsetOf(b)) return {0, Mapping(e)};  // Same types have no distance cost.

  // TODO: Our type must be fully specified for now.
  if (std::holds_alternative<WildcardInfo>(a.info)) unimplemented();
  // TODO: Match child template parameters too.
  if (!std::holds_alternative<WildcardInfo>(b.info)) return {Mapping::NOT_SUBTYPE, Mapping(e)};

  int qual_idx = 0;
  Type wildcard_type = a;
  for (; qual_idx < b.quals.size(); ++qual_idx) {
    if (qual_idx >= a.quals.size())
      return {Mapping::NOT_SUBTYPE, Mapping(e)};  // Too many qualifiers on wildcard - can't match.
    if (a.quals[qual_idx] != b.quals[qual_idx])
      return {Mapping::NOT_SUBTYPE, Mapping(e)};  // Qualifiers don't match.
    wildcard_type.quals.erase(wildcard_type.quals.begin());  // Pop front.
  }
  // For now, distance is how many qualifiers that were pushed into the wildcard (didn't match),
  // plus one for actually having a wildcard.
  Mapping m(e);
  m.map[std::get<WildcardInfo>(b.info)] = e->scope().addType(wildcard_type);
  return {wildcard_type.quals.size() + 1, std::move(m)};
}

Type resolveType(const Type& t, const Mapping& m) {
  auto copy = t;
  copy.resolve(m);
  return copy;
}

std::string typepathToString(ast::Type* type) {
  return join(
      type->path.begin(), type->path.end(), [](const auto& t) { return t->name; }, ".");
}

bool Qualifier::isSubsetOf(const Qualifier& o) const {
  if (cnst && !o.cnst) return false;
  return hasIntersection(o);
}

bool Qualifier::hasIntersection(const Qualifier& o) const {
  if (array != o.array) return false;
  return ptr == o.ptr;
}

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

bool Type::isSubsetOf(const Type& o) const {
  if (info != o.info) return false;
  if (cnst && !o.cnst) return false;  // Can't assign const to non-const.
  if (quals.size() != o.quals.size()) return false;
  for (int i = 0; i < quals.size(); ++i)
    if (!quals[i].isSubsetOf(o.quals[i])) return false;
  return true;
}

bool Type::hasIntersection(const Type& o) const {
  if (info != o.info) return false;
  if (quals.size() != o.quals.size()) return false;
  for (int i = 0; i < quals.size(); ++i)
    if (!quals[i].hasIntersection(o.quals[i])) return false;
  return true;
}

void Type::resolve(const Mapping& m) {
  // E.g. *T => **u8. if parameter is *u8.
  // TODO: resolve types here. types should be resolved by default (always;
  // maybe mapping can be removed if can do something about functions?;).
  if (auto* wildcard = std::get_if<WildcardInfo>(&info); wildcard) {
    auto iter = m.map.find(*wildcard);
    if (iter != m.map.end() && iter->second != INVL_TID) {
      const auto& concrete = m.e->scope().t(iter->second);
      info = concrete.info;
      auto new_quals = concrete.quals;
      // TODO: handle const+ref here.
      new_quals.insert(new_quals.end(), quals.begin(), quals.end());
      quals = std::move(new_quals);
    }
  }
  std::visit([m](auto& inner) { inner.resolve(m); }, info);
}

std::string Type::str() const {
  std::string info_str = std::visit([](const auto& v) { return v.str(); }, info);
  std::string rep = "Type(" + info_str;
  if (cnst) rep += "; cnst";
  if (ref) rep += "; ref";
  if (!quals.empty()) {
    rep += "; ";
    rep += join(
        quals.rbegin(), quals.rend(), [](auto& i) { return i.str(); }, ", ");
  }
  rep += ")";
  return rep;
}

std::string Mapping::str() const {
  auto f = [this](auto& kv) {
    if (kv.second == INVL_TID) return "unmapped " + kv.first.str();
    return kv.first.str() + ":" + e->scope().t(kv.second).str();
  };
  return join(map.begin(), map.end(), f, ", ");
}

void Mapping::merge(const Mapping& m) {
  for (const auto& [wildcard, type] : m.map) {
    auto iter = map.find(wildcard);
    // Allow overwriting unmapped wildcards. Allow skipping unmapped wildcards in |m|.
    if (iter != map.end() && iter->second != INVL_TID) {
      if (type == INVL_TID) continue;
      else
        e->error("duplicate template parameter " + wildcard.str());
    }
    map[wildcard] = type;
  }
}

void Mapping::unmerge(const Mapping& m) {
  for (const auto& [wildcard, _] : m.map) {
    bug_unless(map.contains(wildcard));
    map.erase(wildcard);
  }
}

void WildcardInfo::resolve(const Mapping&) {
  // Implemented in Type::resolve.
}

void IntfInfo::resolve(const Mapping& m) {}

StructInfo::StructInfo(ast::Struct* st, Mapping m) : st(st), m(std::move(m)) {
  auto& s = m.e->scope();
  // Include wildcards from this struct.
  m.merge(s.typelistToMapping(st->tname->tlist.get(), nullptr));
  auto autoscope = s.autoScope(st, m);
  for (const auto& member : st->var_decls) {
    TypeId tid = s.typeFromAst(member->type.get());
    mems.emplace(member->name, MemberInfo{size_, tid});
    size_ += s.t(tid).size();
  }
}

void StructInfo::resolve(const Mapping& m) {
  // TODO: Resolve types.
}

Val StructInfo::access(Hnd hnd, const std::string& member) const {
  auto iter = mems.find(member);
  if (iter == mems.end()) return INVL_VAL;
  auto& s = m.e->scope();
  return Val(hnd + iter->second.offset, s.addType(resolveType(s.t(iter->second.type), m)));
}

Val StructInfo::access(Hnd hnd, int offset) const {
  auto& s = m.e->scope();
  for (const auto& kv : mems)
    if (kv.second.offset == offset)
      return Val(hnd + offset, s.addType(resolveType(s.t(kv.second.type), m)));
  m.e->error("no value at offset " + std::to_string(offset));
}

Val EnumInfo::access(const std::string& member) const {
  for (int i = 0; i < en->numbered_variants.size(); ++i)
    if (member == en->numbered_variants[i]) {
      Hnd hnd = m.e->vm().allocTmp(size());
      m.e->vm().write(hnd, int32_t(i));
      return Val(hnd, m.e->scope().addType(Type(*this)));
    }
  m.e->error("no enum variant " + member);
}

void EnumInfo::resolve(const Mapping& m) {
  // TODO: Resolve types.
}

void BuiltinStorageInfo::resolve(const Mapping&) {
  // Nothing to do.
}

void BuiltinFnInfo::resolve(const Mapping&) {
  // Nothing to do.
}

void FnInfo::resolve(const Mapping&) {
  // Nothing to do - functions need to keep a mapping around for execution.
}

void FnSetInfo::resolve(const Mapping& m) {
  for (auto& fninfo : fns) fninfo.resolve(m);
}

}  // namespace memelang::exec
