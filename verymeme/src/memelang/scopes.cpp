#include "memelang/scopes.h"

#include "memelang/constants.h"
#include "memelang/exec.h"
#include "verymeme/macros.h"

namespace memelang::exec {

Scope::Scope(Exec* exec)
    : e_(exec), bool_t(addBuiltinStorage(BOOL)), i8_t(addBuiltinStorage(I8)),
      i16_t(addBuiltinStorage(I16)), i32_t(addBuiltinStorage(I32)), i64_t(addBuiltinStorage(I64)),
      u8_t(addBuiltinStorage(U8)), u16_t(addBuiltinStorage(U16)), u32_t(addBuiltinStorage(U32)),
      u64_t(addBuiltinStorage(U64)), f32_t(addBuiltinStorage(F32)), f64_t(addBuiltinStorage(F64)) {
  pushScopeUnsafe(nullptr, Mapping(e_));

  for (const auto& fn : BUILTIN_FNS) builtin_fns_.emplace(fn, BuiltinFnInfo(fn));
  for (const auto& file : e_->module()->files) {
    for (auto& fn : file->fns) {
      e_->setContext(fn.get());
      fns_.emplace(fn->sig->tname->name, FnInfo(fn.get()));
    }
    for (auto& enm : file->enums) {
      e_->setContext(enm.get());
      if (!enums_.emplace(enm->tname->name, EnumInfo(enm.get())).second)
        e_->error("duplicate enum definition");
    }
    for (auto& intf : file->intfs) {
      e_->setContext(intf.get());
      if (!intfs_.emplace(intf->tname->name, IntfInfo(intf.get())).second)
        e_->error("duplicate interface definition");
    }
    for (auto& strct : file->structs) {
      e_->setContext(strct.get());
      if (!structs_.emplace(strct->tname->name, StructInfo(strct.get())).second)
        e_->error("duplicate struct definition");
    }
    for (auto& impl : file->impls) {
      e_->setContext(impl.get());
      impls_.emplace_back(impl.get());
    }
  }
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
    scopes_.back().ctx = "global ctx";
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

Val Scope::maybeFindVar(const std::string& name) const {
  bug_unless(!scopes_.empty() && !scopes_.back().vars.empty());
  const auto& vars = scopes_.back().vars;
  for (auto scope_iter = vars.rbegin(); scope_iter != vars.rend(); ++scope_iter) {
    auto iter = scope_iter->find(name);
    if (iter != scope_iter->end()) return iter->second;
  }
  return INVALID_VAL;
}

Val Scope::findVar(const std::string& name) const {
  auto val = maybeFindVar(name);
  if (val.hnd == INVALID_HND) e_->error("undeclared variable " + name);
  return val;
}

Val Scope::declareVar(const std::string& name, Val v) {
  if (maybeFindVar(name).hnd != INVALID_HND) e_->error("redeclaration of var " + name);
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
  Type new_type(typeInfoForAstType(ast_type), ast_type->cnst, {}, Mapping(e_), e_);

  // Look through qualifiers reversed.
  for (auto i = ast_type->quals.rbegin(); i != ast_type->quals.rend(); ++i) {
    auto& q = new_type.quals.emplace_back();
    if ((*i)->array) {
      auto array_val = e_->eval((*i)->array.get());
      if (array_val.type != u32_t) e_->error("array size must be u32");
      q.array = e_->vm().ref<int32_t>(array_val.hnd);
    }
    q.ptr = (*i)->ptr;
    q.cnst = (*i)->cnst;

    bug_unless(q.array || q.ptr);  // Qualifier must either be array or pointer.
  }
  if (std::holds_alternative<WildcardInfo>(new_type.info)) {
    // Maybe resolve if wildcard type.
    const auto& wildcard = std::get<WildcardInfo>(new_type.info);
    auto iter = scopes_.back().m.map.find(wildcard);
    if (iter != scopes_.back().m.map.end() && iter->second != INVALID_TYPEID)
      new_type.resolveWildcardWith(iter->second);
  } else if (!std::holds_alternative<BuiltinStorageInfo>(new_type.info) &&
      !std::holds_alternative<BuiltinFnInfo>(new_type.info)) {
    // Map type parameters to wildcards based on typename.
    const auto* tname = std::visit([](auto&& v) { return v.tname(); }, new_type.info);
    bug_unless(tname);
    // Allow ast type to specify fewer parameters than required - can deduce rest.
    // e.g. want to do memcpy(a, b, cnt) rather than memcpy<u8>(a, b, cnt).
    const auto wildcard_count = tname->tlist ? tname->tlist->names.size() : 0;
    // TODO: Handle wildcards in all parts of type path.
    const auto& params = ast_type->path.back()->params;
    if (params.size() > wildcard_count)
      e_->error("bad number of type parameters for " + new_type.str());
    for (int i = 0; i < int(wildcard_count); ++i) {
      TypeId tid = INVALID_TYPEID;
      if (i < int(params.size())) tid = typeFromAst(params[i].get());
      new_type.m.map[WildcardInfo(tname->tlist->names[i])] = tid;
    }
  }

  return addType(new_type);
}

TypeId Scope::maybeFindFn(const std::string& name) {
  if (!fns_.contains(name)) return INVALID_TYPEID;
  // TODO: generate mapping between fn typelist and type params.
  return addType(Type(fns_.find(name)->second, e_));
}

TypeId Scope::findImplFn(TypeId this_type, const std::vector<Val>& args,
    const std::string& intf_name, const std::string& fn_name) {
  ast::Fn* best_fn = nullptr;
  Mapping best_fn_mapping(e_);
  Mapping best_impler(e_);
  int best_impler_dist = Mapping::NOT_SUBTYPE;
  // For each implementation, check the distance between types.
  // Select the implementation which has the closest distance that has a function that matches.
  for (const auto& ast_impl : impls_) {
    // TODO: Scope resolution?
    if (typepathToString(ast_impl->tintf.get()) != intf_name) continue;

    // Set up mapping in this impl typename.
    auto autoscope = autoScope(ast_impl, typelistToMapping(ast_impl->tlist.get(), e_));
    TypeId impl = typeFromAst(ast_impl->type.get());
    auto [impler_dist, impler_mapping] = dist(this_type, impl, e_);
    if (impler_dist >= best_impler_dist) continue;

    for (const auto& fn : ast_impl->fns) {
      if (fn->sig->tname->name != fn_name) continue;  // wrong name
      const auto& [can_do, fn_mapping] = maybeMappingForFnCall(fn.get(), args);
      if (!can_do) continue;
      best_fn = fn.get();
      best_fn_mapping = fn_mapping;
      best_impler = impler_mapping;
      best_impler_dist = impler_dist;
    }
  }
  if (!best_fn) return INVALID_TYPEID;
  best_fn_mapping.merge(best_impler);
  return addType(Type(FnInfo(best_fn), false, {}, best_fn_mapping, e_));
}

TypeInfo Scope::typeInfoForAstType(ast::Type* type) {
  const auto path = typepathToString(type);
  if (scopes_.back().m.map.contains(WildcardInfo(path))) return WildcardInfo(path);
  if (builtin_storage_.contains(path)) return builtin_storage_.find(path)->second;
  if (builtin_fns_.contains(path)) return builtin_fns_.find(path)->second;
  if (fns_.contains(path)) return fns_.find(path)->second;
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
  return addType(Type(info, e_));
}

std::pair<bool, Mapping> Scope::maybeMappingForFnCall(ast::Fn* fn, const std::vector<Val>& args) {
  Mapping fn_mapping(e_);
  if (fn->sig->params.size() != args.size()) return {false, fn_mapping};  // wrong number of params

  for (int param_idx = 0; param_idx < int(fn->sig->params.size()); ++param_idx) {
    TypeId param_type = typeFromAst(fn->sig->params[param_idx]->type.get());
    TypeId arg_type = args[param_idx].type;
    auto [param_dist, param_mapping] = dist(arg_type, param_type, e_);
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
