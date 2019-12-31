#ifndef MEMELANG_SCOPES_H
#define MEMELANG_SCOPES_H

#include <map>
#include <set>
#include <utility>
#include <vector>

#include "memelang/ast.h"
#include "memelang/vm.h"
#include "verymeme/bimap.h"
#include "verymeme/util.h"

namespace memelang::exec {

class Exec;

class Scope {
public:
  explicit Scope(Exec* exec);

  [[nodiscard]] auto autoScope(ast::Node* ctx, const Mapping& m) {
    pushScopeUnsafe(ctx, m);
    return AutoReset([this]() { popScopeUnsafe(); });
  }
  [[nodiscard]] auto autoNest() {
    nestScopeUnsafe();
    return AutoReset([this]() { unnestScopeUnsafe(); });
  }
  void mergeMapping(const Mapping& m);
  void unmergeMapping(const Mapping& m);
  Val findVar(const std::string& name) const;
  Val declareVar(const std::string& name, Val v);
  std::pair<bool, Mapping> maybeMappingForFnCall(ast::Fn* fn, const std::vector<Val>& args);

  TypeId addType(const Type& t);
  const Type& t(TypeId id);
  TypeId typeFromAst(ast::Type* ast_type);

  TypeId maybeFindFn(const std::string& name);
  TypeId findStructFn(const std::string& struct_name, const std::string& fn_name);
  TypeId findImplFn(TypeId this_type, const std::vector<Val>& args, const std::string& intf_name,
      const std::string& fn_name);

  std::string stacktrace() const;

private:
  struct ScopeData {
    std::vector<std::map<std::string, Val>> vars;
    Mapping m;
    std::string ctx;

    explicit ScopeData(Mapping m) : m(std::move(m)) {}
    std::string str() const { return "Scope{" + ctx + ", mapping: " + m.str() + "}"; }
  };

  void pushScopeUnsafe(ast::Node* ctx, const Mapping& m);  // Creates new scope-space
  void popScopeUnsafe();
  void nestScopeUnsafe();  // Nests scope inside current scope-space.
  void unnestScopeUnsafe();
  TypeInfo typeInfoForTypename(const std::string& name);
  Val maybeFindVar(const std::string& name) const;
  TypeId addBuiltinStorage(const std::string& name);

  Exec* e_;
  std::vector<ScopeData> scopes_;
  Bimap<TypeId, Type> types_;  // Contains instantiated types.
  TypeId next_id_ = 1;
  std::map<std::string, FnInfo> fns_;
  std::map<std::string, EnumInfo> enums_;
  std::map<std::string, IntfInfo> intfs_;
  std::map<std::string, StructInfo> structs_;
  std::map<std::string, BuiltinStorageInfo> builtin_storage_;
  std::map<std::string, BuiltinFnInfo> builtin_fns_;
  std::vector<ast::Impl*> impls_;

public:
  // Built-in types (initialize after).
  TypeId bool_t;
  TypeId i8_t;
  TypeId i16_t;
  TypeId i32_t;
  TypeId i64_t;
  TypeId u8_t;
  TypeId u16_t;
  TypeId u32_t;
  TypeId u64_t;
  TypeId f32_t;
  TypeId f64_t;
};

}  // namespace memelang::exec

#endif  // MEMELANG_SCOPES_H
