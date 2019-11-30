#include "memelang/scopes.h"

#include "memelang/constants.h"
#include "memelang/exec.h"
#include "verymeme/macros.h"

namespace memelang::exec {

Scope::Scope(Exec* exec)
    : e_(exec), bool_t(addType(Type(BOOL, e_))), i8_t(addType(Type(I8, e_))),
      i16_t(addType(Type(I16, e_))), i32_t(addType(Type(I32, e_))), i64_t(addType(Type(I64, e_))),
      u8_t(addType(Type(U8, e_))), u16_t(addType(Type(U16, e_))), u32_t(addType(Type(U32, e_))),
      u64_t(addType(Type(U64, e_))), f32_t(addType(Type(F32, e_))), f64_t(addType(Type(F64, e_))) {
  pushScope(nullptr);

  for (const auto& file : e_->module()->files) {
    for (auto& fn : file->fns) {
      e_->setContext(fn.get());
      fns_[fn->sig->tname->name] = fn.get();
    }
    for (auto& enm : file->enums) {
      e_->setContext(enm.get());
      if (!enums_.emplace(enm->tname->name, enm.get()).second)
        e_->error("duplicate enum definition");
    }
    for (auto& intf : file->intfs) {
      e_->setContext(intf.get());
      if (!intfs_.emplace(intf->tname->name, intf.get()).second)
        e_->error("duplicate interface definition");
    }
    for (auto& strct : file->structs) {
      e_->setContext(strct.get());
      if (!structs_.emplace(strct->tname->name, strct.get()).second)
        e_->error("duplicate struct definition");
    }
    for (auto& impl : file->impls) {
      e_->setContext(impl.get());
      ImplKey key{.impler = typeFromAst(impl->type.get()), .intf = typeFromAst(impl->tintf.get())};
      if (!impls_.emplace(key, impl.get()).second)
        e_->error("duplicate implementation for (type, interface specialisation) pair");
    }
  }
}

void Scope::pushScope(ast::Fn* fn) {
  scopes_.emplace_back(ScopeData(e_));
  auto* ctx = e_->context();

  if (fn) {
    scopes_.back().ctx = fn->tok.fpos() + ":" + fn->sig->tname->name;
    scopes_.back().ctx +=
        ctx ? " called from " + ctx->tok.fpos() + ":" + ctx->tok.span() : " (no ctx)";
  } else {
    scopes_.back().ctx = "global ctx";
  }
  nestScope();
}

void Scope::popScope() {
  bug_unless(!scopes_.empty());
  // TODO: Call destructors
  scopes_.pop_back();
}

void Scope::nestScope() { scopes_.back().vars.emplace_back(); }

void Scope::unnestScope() {
  bug_unless(!scopes_.back().vars.empty());
  // TODO: Call destructors
  // TODO: Pop from stack
  scopes_.back().vars.pop_back();
}

void Scope::mergeMapping(const Mapping& m) {
  bug_unless(!scopes_.empty());
  scopes_.back().mapping.merge(m);
}

void Scope::unmergeMapping(const Mapping& m) {
  bug_unless(!scopes_.empty());
  scopes_.back().mapping.unmerge(m);
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

const Type& Scope::get(TypeId id) {
  if (!types_.containsKey(id)) e_->error("unknown type with id " + std::to_string(id));
  return types_[id];
}

// TODO: need to consider type wildcards
// 1. save wildcards in current scope
// 2. match wildcards to type (type inference basically)
TypeId Scope::typeFromAst(ast::Type* ast_type) {
  // Put one qualifier to hold const for the main type.
  Type new_type(ast_type->name, ast_type->cnst, {}, e_);

  // Look through qualifiers reversed.
  for (auto i = ast_type->quals.rbegin(); i != ast_type->quals.rend(); ++i) {
    auto& q = new_type.quals.emplace_back();
    // TODO not only u32_t?
    if ((*i)->array) {
      auto array_val = e_->eval((*i)->array.get());
      if (array_val.type != u32_t) e_->error("array size must be u32");
      q.array = e_->vm().ref<int32_t>(array_val.hnd);
    }
    q.ptr = (*i)->ptr;
    q.cnst = (*i)->cnst;

    bug_unless(q.array || q.ptr);  // Qualifier must either be array or pointer.
  }
  // TODO: create mappings from wildcards to types specified in ast type.
  //  for (const auto& param : ast_type->params)
  //  new_type.params.emplace_back(typeFromAst(param.get()));

  // TODO: Handle child parameters.
  if (scopes_.back().mapping.wildcard_map.contains(new_type.name))
    new_type.addInnerType(scopes_.back().mapping.wildcard_map[new_type.name]);

  return addType(new_type);
}

FnRef Scope::maybeFindFn(const std::string& name) {
  if (!fns_.contains(name)) return INVALID_FNREF;
  return FnRef(fns_[name], INVALID_VAL, Mapping(e_));
}

FnRef Scope::findImplFn(Val ths, const std::vector<Val>& args, const std::string& impl_name,
    const std::string& fn_name) {
  FnRef best_result(nullptr, ths, Mapping(e_));
  Mapping best_impler_mapping(e_);
  int best_impler_dist = Mapping::NOT_SUBTYPE;
  // For each implementation, check the distance between types.
  // Select the implementation which has the closest distance that has a function that matches.
  for (const auto& [impl_key, impl] : impls_) {
    const auto& [impler, intf] = impl_key;
    if (get(intf).name != impl_name) continue;  // wrong intf name

    auto [impler_dist, impler_mapping] = dist(get(ths.type), get(impler), WILDCARD_HACK, e_);
    if (impler_dist >= best_impler_dist) continue;

    pushScope(nullptr);  // Temporarily add mapping to resolve wildcards.
    mergeMapping(impler_mapping);
    for (const auto& fn : impl->fns) {
      if (fn->sig->tname->name != fn_name) continue;  // wrong name
      if (fn->sig->params.size() != args.size()) continue;  // wrong number of params

      bool can_do = true;
      FnRef result(fn.get(), ths, Mapping(e_));
      for (int param_idx = 0; param_idx < int(fn->sig->params.size()); ++param_idx) {
        TypeId param_type = typeFromAst(fn->sig->params[param_idx]->type.get());
        TypeId arg_type = args[param_idx].type;
        if (WILDCARD_HACK.contains(get(param_type).name)) {
          auto [param_dist, param_mapping] =
              dist(get(arg_type), get(param_type), WILDCARD_HACK, e_);
          if (param_dist == Mapping::NOT_SUBTYPE) {
            can_do = false;
            break;
          }
          mergeMapping(param_mapping);
          result.mapping.merge(param_mapping);
        } else if (param_type != arg_type) {
          can_do = false;
          break;  // wrong parameter type.
        }
      }
      unmergeMapping(result.mapping);
      if (!can_do) continue;
      best_result = std::move(result);
      best_impler_mapping = impler_mapping;
      best_impler_dist = impler_dist;
    }
    unmergeMapping(impler_mapping);
    popScope();
  }

  best_result.mapping.merge(best_impler_mapping);
  return best_result;
}

std::string Scope::stacktrace() const {
  std::string stack;
  for (auto iter = scopes_.rbegin(); iter != scopes_.rend(); ++iter) stack += iter->ctx + "\n";
  return stack;
}

}  // namespace memelang::exec
