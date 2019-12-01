#ifndef MEMELANG_SCOPES_H
#define MEMELANG_SCOPES_H

#include <map>
#include <set>
#include <vector>

#include "memelang/ast.h"
#include "memelang/vm.h"
#include "verymeme/bimap.h"

namespace memelang::exec {

class Exec;

class Scope {
public:
  explicit Scope(Exec* exec);

  void pushScope(ast::Fn* fn);  // Creates new scope-space
  void popScope();
  void nestScope();  // Nests scope inside current scope-space.
  void unnestScope();

  void mergeMapping(const Mapping& m);
  void unmergeMapping(const Mapping& m);

  Val maybeFindVar(const std::string& name) const;
  Val findVar(const std::string& name) const;
  Val declareVar(const std::string& name, Val v);

  TypeId addType(const Type& t);
  const Type& get(TypeId id);
  TypeId typeFromAst(ast::Type* ast_type);

  FnRef maybeFindFn(const std::string& name);
  FnRef findStructFn(const std::string& structName, const std::string& fnName);
  FnRef findImplFn(Val ths, const std::vector<Val>& args, const std::string& impl_name,
      const std::string& fn_name);

  std::string stacktrace() const;

private:
  struct ScopeData {
    std::vector<std::map<std::string, Val>> vars;
    Mapping mapping;
    std::string ctx;

    explicit ScopeData(Exec* e) : mapping(e) {}
  };

  struct ImplKey {
    TypeId impler;
    TypeId intf;
    COMPARISON(ImplKey, impler, intf);
  };

  Exec* e_;
  std::vector<ScopeData> scopes_;
  Bimap<TypeId, Type> types_;

  TypeId next_id_ = 1;
  std::map<std::string, ast::Fn*> fns_;
  std::map<std::string, ast::Enum*> enums_;
  std::map<std::string, ast::Intf*> intfs_;
  std::map<std::string, ast::Struct*> structs_;
  std::map<ImplKey, ast::Impl*> impls_;

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
