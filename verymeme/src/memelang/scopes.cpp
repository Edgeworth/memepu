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
  for (auto& fn : e_->file()->fns) {
    e_->setContext(fn.get());
    fns_[fn->sig->tname->name] = fn.get();
  }
  for (auto& enm : e_->file()->enums) {
    e_->setContext(enm.get());
    if (!enums_.emplace(enm->tname->name, enm.get()).second) e_->error("duplicate enum definition");
  }
  for (auto& intf : e_->file()->intfs) {
    e_->setContext(intf.get());
    if (!intfs_.emplace(intf->tname->name, intf.get()).second)
      e_->error("duplicate interface definition");
  }
  for (auto& strct : e_->file()->structs) {
    e_->setContext(strct.get());
    if (!structs_.emplace(strct->tname->name, strct.get()).second)
      e_->error("duplicate struct definition");
  }
  for (auto& impl : e_->file()->impls) {
    e_->setContext(impl.get());
    auto impl_type = typeFromAst(impl->type.get());
    if (!impls_[impl_type].emplace(typeFromAst(impl->tintf.get()), impl.get()).second)
      e_->error("duplicate implementation for (type, interface specialisation) pair");
  }
}

void Scope::pushScope() {
  vars_.emplace_back();
  nestScope();
}

void Scope::popScope() {
  bug_unless(!vars_.empty());
  // TODO: Call destructors
  vars_.pop_back();
}

void Scope::nestScope() { vars_.back().emplace_back(); }

void Scope::unnestScope() {
  bug_unless(!vars_.back().empty());
  // TODO: Call destructors
  // TODO: Pop from stack
  vars_.back().pop_back();
}

void Scope::pushTypeMapping(const Mapping& m) {
  for (const auto& [wildcard, type] : m.wildcard_map) {
    if (mappings_.contains(wildcard)) e_->error("reusing template paramter " + wildcard);
    mappings_[wildcard] = addType(Type{type});
  }
}

void Scope::popTypeMapping(const Mapping& m) {
  for (const auto& [wildcard, _] : m.wildcard_map) {
    bug_unless(mappings_.contains(wildcard));
    mappings_.erase(wildcard);
  }
}

Val Scope::maybeGetVar(const std::string& name) const {
  bug_unless(!vars_.empty());
  for (auto scope_iter = vars_.back().rbegin(); scope_iter != vars_.back().rend(); ++scope_iter) {
    auto iter = scope_iter->find(name);
    if (iter != scope_iter->end()) return iter->second;
  }
  return {};
}

Val Scope::getVar(const std::string& name) const {
  auto val = maybeGetVar(name);
  if (val.hnd == INVALID_HND) e_->error("undeclared variable " + name);
  return val;
}

Val Scope::declareVar(const std::string& name, Val v) {
  if (maybeGetVar(name).hnd != INVALID_HND) e_->error("redeclaration of var " + name);
  vars_.back().back()[name] = v;
  return v;
}

const Type* Scope::addType(Type&& t) { return &*types_.insert(std::move(t)).first; }

// TODO: need to consider type wildcards
// 1. save wildcards in current scope
// 2. match wildcards to type (type inference basically)
const Type* Scope::typeFromAst(ast::Type* ast_type) {
  if (ast_type_map_.count(ast_type)) return ast_type_map_[ast_type];

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

  ast_type_map_[ast_type] = addType(std::move(new_type));
  printf("Added new type: %s\n", ast_type_map_[ast_type]->toString().c_str());
  return ast_type_map_[ast_type];
}

ast::Fn* Scope::getFn(const std::string& name) {
  if (!fns_.contains(name)) e_->error("no function " + name);
  return fns_[name];
}

std::pair<ast::Fn*, Mapping> Scope::lookupImplFn(
    Val obj, const std::string& impl_name, const std::string& fn_name) {
  printf("lookup: %s %s\n", impl_name.c_str(), fn_name.c_str());
  Mapping best_mapping{};
  ast::Fn* best_fn = nullptr;
  // For each implementation, check the distance between types.
  // Select the implementation which has the closest distance that has a function that matches.
  for (const auto& [impl_obj_type, impl_map] : impls_) {
    // TODO: Don't hardcode these.
    const auto& mapping = dist(*obj.type, *impl_obj_type, {"T", "I", "A", "B"});
    if (mapping == NOT_SUBTYPE || best_mapping < mapping) continue;

    for (const auto& [intf_type, impl] : impl_map) {
      if (intf_type->name == impl_name) {
        for (const auto& fn : impl->fns) {
          printf("check fn name: %s\n", fn->sig->tname->name.c_str());
          if (fn->sig->tname->name == fn_name) {
            best_fn = fn.get();
            best_mapping = mapping;
          }
        }
      }
    }
  }

  return {best_fn, std::move(best_mapping)};
}

}  // namespace memelang::exec
