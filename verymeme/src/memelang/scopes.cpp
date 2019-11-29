#include "memelang/scopes.h"

#include "memelang/constants.h"
#include "memelang/exec.h"
#include "verymeme/macros.h"

namespace memelang::exec {

Scope::Scope(Exec* exec)
    : e_(exec), bool_t(addType({.name = BOOL})), i8_t(addType({.name = I8})),
      i16_t(addType({.name = I16})), i32_t(addType({.name = I32})), i64_t(addType({.name = I64})),
      u8_t(addType({.name = U8})), u16_t(addType({.name = U16})), u32_t(addType({.name = U32})),
      u64_t(addType({.name = U64})), f32_t(addType({.name = F32})), f64_t(addType({.name = F64})) {
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
  scopes_.emplace_back();
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

void Scope::pushTypeMapping(const Mapping& m) {
  bug_unless(!scopes_.empty());
  auto& wildcards = scopes_.back().wildcards;
  for (const auto& [wildcard, type] : m.wildcard_map) {
    if (wildcards.contains(wildcard)) e_->error("reusing template parameter " + wildcard);
    wildcards[wildcard] = addType(Type{type});
  }
}

void Scope::popTypeMapping(const Mapping& m) {
  bug_unless(!scopes_.empty());
  auto& wildcards = scopes_.back().wildcards;
  for (const auto& [wildcard, _] : m.wildcard_map) {
    bug_unless(wildcards.contains(wildcard));
    wildcards.erase(wildcard);
  }
}

Val Scope::maybeFindVar(const std::string& name) const {
  bug_unless(!scopes_.empty() && !scopes_.back().vars.empty());
  const auto& vars = scopes_.back().vars;
  for (auto scope_iter = vars.rbegin(); scope_iter != vars.rend(); ++scope_iter) {
    auto iter = scope_iter->find(name);
    if (iter != scope_iter->end()) return iter->second;
  }
  return {};
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

const Type* Scope::addType(Type&& t) { return &*types_.insert(std::move(t)).first; }

// TODO: need to consider type wildcards
// 1. save wildcards in current scope
// 2. match wildcards to type (type inference basically)
const Type* Scope::typeFromAst(ast::Type* ast_type) {
  // Put one qualifier to hold const for the main type.
  Type new_type = {.name = ast_type->name, .quals = {{.cnst = ast_type->cnst}}};

  // Look through qualifiers reversed.
  for (auto i = ast_type->quals.rbegin(); i != ast_type->quals.rend(); ++i) {
    auto& q = new_type.quals.emplace_back();
    // TODO not only u32_t?
    if ((*i)->array) {
      auto array_val = e_->eval((*i)->array.get());
      if (array_val.type != u32_t) e_->error("array size must be u32");
      q.array = e_->vm().ref<int32_t>(array_val);
    }
    q.ptr = (*i)->ptr;
    q.cnst = (*i)->cnst;

    bug_unless(q.array || q.ptr);  // Qualifier must either be array or pointer.
  }
  for (const auto& param : ast_type->params) new_type.params.emplace_back(typeFromAst(param.get()));

  // TODO: Handle child parameters.
  if (scopes_.back().wildcards.contains(new_type.name))
    new_type.addInnerType(*scopes_.back().wildcards[new_type.name]);

  return addType(std::move(new_type));
}

FnRef Scope::maybeFindFn(const std::string& name) {
  if (!fns_.contains(name)) return {};
  return {.fn = fns_[name], .ths = {}};
}

FnRef Scope::findImplFn(Val ths, const std::vector<Val>& args, const std::string& impl_name,
    const std::string& fn_name) {
  FnRef best_result{.fn = nullptr, .ths = ths};
  Mapping best_impl_mapping = {};
  // For each implementation, check the distance between types.
  // Select the implementation which has the closest distance that has a function that matches.
  for (const auto& [impl_key, impl] : impls_) {
    const auto& [impler, intf] = impl_key;
    if (intf->name != impl_name) continue;  // wrong intf name

    const auto& impler_mapping = dist(*ths.type, *impler, WILDCARD_HACK);
    if (impler_mapping == NOT_SUBTYPE || best_impl_mapping < impler_mapping) continue;

    pushScope(nullptr);  // Temporarily add mapping to resolve wildcards.
    pushTypeMapping(impler_mapping);
    for (const auto& fn : impl->fns) {
      if (fn->sig->tname->name != fn_name) continue;  // wrong name
      if (fn->sig->params.size() != args.size()) continue;  // wrong number of params

      bool can_do = true;
      FnRef result{.fn = fn.get(), .ths = ths, .type_mappings = {}};
      for (int param_idx = 0; param_idx < int(fn->sig->params.size()); ++param_idx) {
        const auto* param_type = typeFromAst(fn->sig->params[param_idx]->type.get());
        const auto* arg_type = args[param_idx].type;
        if (WILDCARD_HACK.contains(param_type->name)) {
          auto param_mapping = dist(*arg_type, *param_type, WILDCARD_HACK);
          if (param_mapping == NOT_SUBTYPE) {
            can_do = false;
            break;
          }
          pushTypeMapping(param_mapping);
          result.type_mappings.emplace_back(std::move(param_mapping));
        } else if (param_type != arg_type) {
          can_do = false;
          break;  // wrong parameter type.
        }
      }
      for (const auto& type_mapping : result.type_mappings) popTypeMapping(type_mapping);
      if (!can_do) continue;
      best_result = std::move(result);
      best_impl_mapping = impler_mapping;
    }
    popTypeMapping(impler_mapping);
    popScope();
  }

  best_result.type_mappings.emplace_back(std::move(best_impl_mapping));
  return best_result;
}

std::string Scope::stacktrace() const {
  std::string stack;
  for (auto iter = scopes_.rbegin(); iter != scopes_.rend(); ++iter) stack += iter->ctx + "\n";
  return stack;
}

}  // namespace memelang::exec
