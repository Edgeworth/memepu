// Copyright 2019 E.
#ifndef MEMELANG_SCOPES_H_
#define MEMELANG_SCOPES_H_

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

  Val findValue(ast::Ref* ref);
  Val findValue(const std::string& name);
  Val declareVar(const std::string& name, Val v);

  TypeId addType(const Type& t);
  const Type& t(TypeId id);
  // Creates a type from |ast_type|, based on the current mapping. If |resolve| is true,
  // the type will be resolved (have its wildcards mapped to types in-place and baked in).
  TypeId typeFromAst(ast::Type* ast_type, bool resolve);
  Mapping typelistToMapping(ast::Typelist* tlist, ast::Ref* ref);
  Val coerceTo(Val l, TypeId tid);
  Val tryCoerceTo(Val l, TypeId tid);

  std::pair<bool, Mapping> maybeMappingForFnCall(ast::Fn* fn, const std::vector<Val>& args);
  // TODO: Should use ref instead of fn_name.
  FnSetInfo findImplFnSet(Val self, const std::string& intf_name, const std::string& fn_name);

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

  TypeInfo typeInfoForAstType(ast::Type* type);
  // Computes current mapping for an (optional) typelist.
  // Optional |ref| specifies explicit mappings.
  Val maybeFindVar(const std::string& name);
  TypeId addBuiltinStorage(const std::string& name);

  Exec* e_;
  std::vector<ScopeData> scopes_;
  Bimap<TypeId, Type> types_;  // Contains instantiated types.
  TypeId next_id_ = 1;
  std::map<std::string, FnSetInfo> fns_;
  std::map<std::string, EnumInfo> enums_;
  std::map<std::string, IntfInfo> intfs_;
  std::map<std::string, StructInfo> structs_;
  std::map<std::string, BuiltinStorageInfo> builtin_storage_;
  std::map<std::string, BuiltinFnInfo> builtin_fns_;
  std::vector<ast::Impl*> impls_;

 public:
  // Built-in types (initialize after).
  TypeId bool_t, i8_t, i16_t, i32_t, i64_t, u8_t, u16_t, u32_t, u64_t, f32_t, f64_t, u8_ptr_t;
};

}  // namespace memelang::exec

#endif  // MEMELANG_SCOPES_H_
