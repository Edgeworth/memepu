#ifndef MEMELANG_SCOPES_H
#define MEMELANG_SCOPES_H

#include <map>
#include <set>
#include <vector>

#include "memelang/ast.h"
#include "memelang/vm.h"

namespace memelang::exec {

class Exec;

class Scope {
public:
  explicit Scope(Exec* exec);

  void pushScope();  // Creates new scope-space
  void popScope();
  void nestScope();  // Nests scope inside current scope-space.
  void unnestScope();

  void pushTypeMapping(const Mapping& m);
  void popTypeMapping(const Mapping& m);

  Val maybeGetVar(const std::string& name) const;
  Val getVar(const std::string& name) const;
  Val declareVar(const std::string& name, Val v);

  const Type* addType(Type&& t);
  const Type* typeFromAst(ast::Type* ast_type);

  ast::Fn* getFn(const std::string& name);
  std::pair<ast::Fn*, Mapping> lookupImplFn(
      Val obj, const std::string& impl_name, const std::string& fn_name);

private:
  Exec* e_;
  std::vector<std::vector<std::map<std::string, Val>>> vars_;
  std::set<Type> types_;
  std::map<std::string, const Type*> mappings_;
  std::map<const ast::Type*, const Type*> ast_type_map_;

  std::map<std::string, ast::Fn*> fns_;
  std::map<std::string, ast::Enum*> enums_;
  std::map<std::string, ast::Intf*> intfs_;
  std::map<std::string, ast::Struct*> structs_;
  // Map from a type (may be set) to mapping from interface to the impl.
  std::map<const Type*, std::map<const Type*, ast::Impl*>> impls_;

public:
  // Built-in types (initialize after).
  const Type* bool_t{};
  const Type* i8_t{};
  const Type* i16_t{};
  const Type* i32_t{};
  const Type* i64_t{};
  const Type* u8_t{};
  const Type* u16_t{};
  const Type* u32_t{};
  const Type* u64_t{};
  const Type* f32_t{};
  const Type* f64_t{};
};

}  // namespace memelang::exec

#endif  // MEMELANG_SCOPES_H
