#ifndef MEMELANG_INTERPRETER_H
#define MEMELANG_INTERPRETER_H

#include <map>
#include <set>

#include "memelang/ast.h"
#include "memelang/memory.h"
#include "memelang/scopes.h"
#include "verymeme/util.h"

namespace memelang::interpreter {

class Interpreter {
public:
  Interpreter(ast::File* file, const FileContents* cts);

  void run();

  void error(const std::string& msg) const;

private:
  ast::File* f_;
  const FileContents* cts_;
  ast::Node* node_ctx_{};

  ScopeManager scope_;
  Memory mem_;
  std::map<const ast::Type*, const Type*> ast_type_map_;
  std::set<Type> types_;
  std::map<Typename, ast::Fn*> fns_;
  std::map<Typename, ast::Enum*> enums_;
  std::map<Typename, ast::Intf*> intfs_;
  std::map<Typename, ast::Struct*> structs_;
  // Map from a type (may be set) to mapping from interface to the impl.
  std::map<const Type*, std::map<const Type*, ast::Impl*>> impls_;

  // Built-in types
  const Type* bool_{};
  const Type* i8_{};
  const Type* i16_{};
  const Type* i32_{};
  const Type* i64_{};
  const Type* u8_{};
  const Type* u16_{};
  const Type* u32_{};
  const Type* u64_{};
  const Type* f32_{};
  const Type* f64_{};

  void setContext(ast::Node* node);

  ValPtr runFn(ast::Fn* fn, const std::vector<ValPtr>& args);
  ValPtr runStmtBlk(ast::StmtBlk* blk);
  ValPtr runStmt(ast::Node* stmt);
  void runVarDefn(ast::VarDefn* defn);
  ValPtr runVarDecl(ast::VarDecl* decl);
  ValPtr runFor(ast::For* fr);
  ValPtr runWhile(ast::While* wh);
  ValPtr runIf(ast::If* ifst);
  ValPtr runOp(ast::Op* op);

  ValPtr eval(ast::Node* n);
  ast::Fn* getFn(const Typename& tname, ast::Node* n);

  const Type* addType(Type&& t);
  ValPtr valFromAstType(ast::Type* type);
  const Type* typeFromAst(ast::Type* ast_type);
  Typename typenameFromAst(ast::Typename* ast_typename);

  // Value operations:
  ValPtr assign(ValPtr l, ValPtr r);
  ValPtr add(ValPtr l, ValPtr r);
  ValPtr sub(ValPtr l, ValPtr r);
  ValPtr lt(ValPtr l, ValPtr r);
  ValPtr lor(ValPtr l, ValPtr r);
  ValPtr eq(ValPtr l, ValPtr r);
  ValPtr neq(ValPtr l, ValPtr r);
  ValPtr array_access(ValPtr l, ValPtr r);
  ValPtr preinc(ValPtr l);
  ValPtr postinc(ValPtr l);
  ValPtr addr(const ValPtr& l);
  ValPtr copy(const ValPtr& l);
  ValPtr deref(const ValPtr& l);

  template <typename F>
  ValPtr binop(ValPtr l, ValPtr r, const Type* type, const std::string& op_name, F default_op) {
    // Look in impls for l's type
    // TODO: Generalise look-up procedure, define rules for lookup.
    auto impl_iter = impls_.find(l->type);
    if (impl_iter != impls_.end()) {
      for (const auto& [impl_type, impl] : impl_iter->second) {
        if (impl_type->name != "Comparable") continue;
        if (impl->tintf->params.size() != 1) continue;
        // TODO: better lookup rules
        if (typeFromAst(impl->tintf->params[0].get()) != r->type) continue;
        for (const auto& fn : impl->fns) {
          if (fn->sig->tname->name == op_name) { return runFn(fn.get(), {r}); }
        }
      }
    }
    ValStorage res = std::visit(overloaded{[this, &r, &default_op](auto&& v) {
      using T = std::decay_t<decltype(v)>;
      if constexpr (std::is_integral_v<T>) return ValStorage{default_op(v, std::get<T>(r->v))};
      error("no matching operator for values");
      return ValStorage{};
    }},
        l->v);
    return std::make_shared<Val>(Val{res, type});
  }
};

}  // namespace memelang::interpreter

#endif  // MEMELANG_INTERPRETER_H
