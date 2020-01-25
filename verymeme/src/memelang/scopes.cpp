#include "memelang/scopes.h"

#include "memelang/constants.h"
#include "memelang/exec.h"
#include "verymeme/macros.h"

namespace memelang::exec {

Scope::Scope(Exec* exec)
    : e_(exec), bool_t(addBuiltinStorage(BOOL)), i8_t(addBuiltinStorage(I8)),
      i16_t(addBuiltinStorage(I16)), i32_t(addBuiltinStorage(I32)), i64_t(addBuiltinStorage(I64)),
      u8_t(addBuiltinStorage(U8)), u16_t(addBuiltinStorage(U16)), u32_t(addBuiltinStorage(U32)),
      u64_t(addBuiltinStorage(U64)), f32_t(addBuiltinStorage(F32)), f64_t(addBuiltinStorage(F64)),
      u8_ptr_t(addType(Type(t(u8_t).info, false, false, {{.ptr = true}}))) {
  pushScopeUnsafe(nullptr, Mapping(e_));

  for (const auto& fn : BUILTIN_FNS) builtin_fns_.emplace(fn, BuiltinFnInfo(fn));
  for (const auto& file : e_->module()->files) {
    for (auto& fn : file->fns) {
      e_->setContext(fn.get());
      fns_.emplace(fn->sig->tname->name, FnSetInfo({{fn.get(), Mapping(e_)}}, INVL_VAL));
    }
    for (auto& enm : file->enums) {
      e_->setContext(enm.get());
      if (!enums_.emplace(enm->tname->name, EnumInfo(enm.get(), Mapping(e_))).second)
        e_->error("duplicate enum definition");
    }
    for (auto& intf : file->intfs) {
      e_->setContext(intf.get());
      if (!intfs_.emplace(intf->tname->name, IntfInfo(intf.get(), Mapping(e_))).second)
        e_->error("duplicate interface definition");
    }
    for (auto& strct : file->structs) {
      e_->setContext(strct.get());
      if (!structs_.emplace(strct->tname->name, StructInfo(strct.get(), Mapping(e_))).second)
        e_->error("duplicate struct definition");
    }
    for (auto& impl : file->impls) {
      e_->setContext(impl.get());
      impls_.emplace_back(impl.get());
    }
  }
  e_->setContext(nullptr);  // Reset context.
}

void Scope::pushScopeUnsafe(ast::Node* ctx, const Mapping& m) {
  scopes_.emplace_back(ScopeData(m));
  const auto* prevctx = e_->context();
  e_->setContext(ctx);

  if (ctx) {
    scopes_.back().ctx = ctx->tok.fpos() + ":" + ctx->str();
    scopes_.back().ctx +=
        prevctx ? " from " + prevctx->tok.fpos() + ":" + prevctx->tok.span() : " (no ctx)";
  } else {
    scopes_.back().ctx = "<base>";
  }
  nestScopeUnsafe();
}

void Scope::popScopeUnsafe() {
  bug_unless(!scopes_.empty());
  // TODO: Call destructors
  scopes_.pop_back();
}

void Scope::nestScopeUnsafe() { scopes_.back().vars.emplace_back(); }

void Scope::unnestScopeUnsafe() {
  bug_unless(!scopes_.back().vars.empty());
  // TODO: Call destructors
  // TODO: Pop from stack
  scopes_.back().vars.pop_back();
}

void Scope::mergeMapping(const Mapping& m) {
  bug_unless(!scopes_.empty());
  scopes_.back().m.merge(m);
}

void Scope::unmergeMapping(const Mapping& m) {
  bug_unless(!scopes_.empty());
  scopes_.back().m.unmerge(m);
}

Val Scope::maybeFindVar(const std::string& name) {
  bug_unless(!scopes_.empty() && !scopes_.back().vars.empty());
  const auto& vars = scopes_.back().vars;
  for (auto scope_iter = vars.rbegin(); scope_iter != vars.rend(); ++scope_iter) {
    auto iter = scope_iter->find(name);
    if (iter != scope_iter->end()) return iter->second;
  }
  // Check typevalues that could be in scope:
  if (auto iter = fns_.find(name); iter != fns_.end())
    return Val(INVL_HND, addType(Type(iter->second)));
  if (auto iter = builtin_fns_.find(name); iter != builtin_fns_.end())
    return Val(INVL_HND, addType(Type(iter->second)));
  return INVL_VAL;
}

Val Scope::findValue(ast::Ref* ref) {
  auto val = findValue(ref->name);
  const auto& type = t(val.type);
  // Map functions if this is a FnSet.
  if (auto* fnset = std::get_if<FnSetInfo>(&type.info); fnset) {
    std::vector<FnInfo> mapped_fnset;
    mapped_fnset.reserve(fnset->fns.size());
    for (const FnInfo& fn : fnset->fns)
      mapped_fnset.emplace_back(fn.fn, typelistToMapping(fn.fn->sig->tname->tlist.get(), ref));
    return Val(INVL_HND, addType(Type(FnSetInfo(std::move(mapped_fnset), fnset->self))));
  }
  return val;
}

Val Scope::findValue(const std::string& name) {
  auto val = maybeFindVar(name);
  if (val == INVL_VAL) e_->error("undeclared variable " + name);
  return val;
}

Val Scope::declareVar(const std::string& name, Val v) {
  if (maybeFindVar(name) != INVL_VAL) e_->error("redeclaration of var " + name);
  scopes_.back().vars.back()[name] = v;
  return v;
}

TypeId Scope::addType(const Type& t) {
  if (!types_.insert(next_id_, t)) return types_.keyForValue(t);
  return next_id_++;
}

const Type& Scope::t(TypeId id) {
  if (!types_.containsKey(id)) e_->error("unknown type with id " + std::to_string(id));
  return types_[id];
}

TypeId Scope::typeFromAst(ast::Type* ast_type) {
  if (!ast_type) return INVL_TID;
  Type new_type(typeInfoForAstType(ast_type), ast_type->cnst, ast_type->ref, {});

  // Look through qualifiers reversed.
  for (auto i = ast_type->quals.rbegin(); i != ast_type->quals.rend(); ++i) {
    auto& q = new_type.quals.emplace_back();
    if ((*i)->array) {
      auto array_val = e_->eval((*i)->array.get(), u32_t);
      if (array_val.type != u32_t) e_->error("array size must be u32");
      q.array = e_->vm().ref<uint32_t>(array_val.hnd);
    }
    q.ptr = (*i)->ptr;
    q.cnst = (*i)->cnst;

    bug_unless(q.array || q.ptr);  // Qualifier must either be array or pointer.
  }

  auto* ref = ast_type->path.back().get();
  // Collect mapping from ast.
  auto visitfn = overloaded{[](const WildcardInfo&) {}, [](const BuiltinStorageInfo&) {},
      [](const BuiltinFnInfo&) {},
      [this, ref](FnSetInfo& fnset) {
        for (auto& fninfo : fnset.fns)
          fninfo.m = typelistToMapping(fninfo.fn->sig->tname->tlist.get(), ref);
      },
      [this, ref](
          IntfInfo& info) { info.m = typelistToMapping(info.intf->tname->tlist.get(), ref); },
      [this, ref](
          StructInfo& info) { info.m = typelistToMapping(info.st->tname->tlist.get(), ref); },
      [this, ref](EnumInfo& info) { info.m = typelistToMapping(info.en->tname->tlist.get(), ref); },
      [this, ref](
          FnInfo& info) { info.m = typelistToMapping(info.fn->sig->tname->tlist.get(), ref); }};
  std::visit(visitfn, new_type.info);

  // Resolev type and add.
  new_type.resolve(scopes_.back().m);
  return addType(new_type);
}

Mapping Scope::typelistToMapping(ast::Typelist* tlist, ast::Ref* ref) {
  Mapping m(e_);
  int wildcard_count = 0;
  if (tlist) {
    wildcard_count = tlist->names.size();
    for (const auto& wildcard : tlist->names) m.map.emplace(WildcardInfo(wildcard), INVL_TID);
  }

  if (ref) {
    // TODO: Handle wildcards in all parts of type path.
    // Allow ast type to specify fewer parameters than required - can deduce rest.
    // e.g. want to do memcpy(a, b, cnt) rather than memcpy<u8>(a, b, cnt).
    if (ref->params.size() > wildcard_count)
      e_->error("bad number of type parameters for " + ref->str());

    for (int i = 0; i < wildcard_count; ++i) {
      TypeId tid = INVL_TID;
      if (i < ref->params.size()) tid = typeFromAst(ref->params[i].get());
      m.map[WildcardInfo(tlist->names[i])] = tid;
    }
  }

  return m;
}

FnSetInfo Scope::findImplFnSet(Val self, const std::string& intf_name, const std::string& fn_name) {
  std::vector<std::pair<int, FnInfo>> fns;
  for (const auto& ast_impl : impls_) {
    // TODO: Scope resolution?
    // Skip if it doesn't match this interface or if it's an interface-less query and one is
    // specified.
    if (!ast_impl->tintf && !intf_name.empty()) continue;
    if (ast_impl->tintf && typepathToString(ast_impl->tintf.get()) != intf_name) continue;

    // Set up mapping in this impl typename.
    Mapping impl_mapping = typelistToMapping(ast_impl->tlist.get(), nullptr);
    auto autoscope = autoScope(ast_impl, impl_mapping);
    TypeId impl = typeFromAst(ast_impl->type.get());
    auto [impler_dist, impler_mapping] = distFrom(t(self.type), t(impl), e_);
    if (impler_dist == Mapping::NOT_SUBTYPE) continue;

    // TODO(hack): Need to match based on parameter list order, not wildcard character.
    // e.g. vector<T> vs for vector<I>
    const auto& self_t = t(self.type);
    if (auto* info = std::get_if<StructInfo>(&self_t.info); info) impler_mapping.merge(info->m);

    // Make sure to include types that might be resolved by function params.
    impler_mapping.merge(impl_mapping);
    for (const auto& fn : ast_impl->fns) {
      if (fn->sig->tname->name != fn_name) continue;  // wrong name
      fns.emplace_back(impler_dist, FnInfo(fn.get(), impler_mapping));
    }
  }
  std::sort(fns.begin(), fns.end());
  std::vector<FnInfo> flat_fns;
  flat_fns.reserve(fns.size());
  for (auto& v : fns) flat_fns.emplace_back(std::move(v.second));
  return FnSetInfo(std::move(flat_fns), self);
}

TypeInfo Scope::typeInfoForAstType(ast::Type* type) {
  const auto path = typepathToString(type);
  if (scopes_.back().m.map.contains(WildcardInfo(path))) return WildcardInfo(path);
  if (builtin_storage_.contains(path)) return builtin_storage_.find(path)->second;
  if (builtin_fns_.contains(path)) return builtin_fns_.find(path)->second;
  if (fns_.contains(path)) return FnSetInfo({fns_.find(path)->second});
  if (enums_.contains(path)) return enums_.find(path)->second;
  if (intfs_.contains(path)) return intfs_.find(path)->second;
  if (structs_.contains(path)) return structs_.find(path)->second;
  e_->error("unknown typename " + path);
}

std::string Scope::stacktrace() const {
  std::string stack;
  for (auto iter = scopes_.rbegin(); iter != scopes_.rend(); ++iter) stack += iter->ctx + "\n";
  return stack;
}

TypeId Scope::addBuiltinStorage(const std::string& name) {
  BuiltinStorageInfo info(name);
  builtin_storage_.emplace(name, info);
  return addType(Type(info));
}

std::pair<bool, Mapping> Scope::maybeMappingForFnCall(ast::Fn* fn, const std::vector<Val>& args) {
  Mapping fn_mapping(e_);
  if (fn->sig->params.size() != args.size()) return {false, fn_mapping};  // wrong number of params

  for (int i = 0; i < fn->sig->params.size(); ++i) {
    TypeId fn_arg_tid = typeFromAst(fn->sig->params[i]->type.get());
    TypeId arg_tid = args[i].type;
    auto [param_dist, param_mapping] = distFrom(t(arg_tid), t(fn_arg_tid), e_);
    if (param_dist == Mapping::NOT_SUBTYPE) {
      unmergeMapping(fn_mapping);
      return {false, fn_mapping};
    }
    mergeMapping(param_mapping);
    fn_mapping.merge(param_mapping);
  }
  unmergeMapping(fn_mapping);
  return {true, fn_mapping};
}

}  // namespace memelang::exec
