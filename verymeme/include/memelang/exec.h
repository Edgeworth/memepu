#ifndef MEMELANG_EXEC_H
#define MEMELANG_EXEC_H

#include <map>
#include <set>

#include "memelang/ast.h"
#include "memelang/scopes.h"
#include "memelang/type.h"
#include "memelang/vm.h"
#include "verymeme/util.h"

namespace memelang::exec {

class Exec {
public:
  Exec(ast::File* file, const FileContents* cts);

  void run();

  void error(const std::string& msg) const;

private:
  ast::File* f_;
  const FileContents* cts_;
  ast::Node* node_ctx_{};

  ScopeManager scope_;
  VM vm_;
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

  Val runFn(ast::Fn* fn, const std::vector<Val>& args, Val ths);
  Val runStmtBlk(ast::StmtBlk* blk);
  Val runStmt(ast::Node* stmt);
  void runVarDefn(ast::VarDefn* defn);
  Val runVarDecl(ast::VarDecl* decl);
  Val runFor(ast::For* fr);
  Val runWhile(ast::While* wh);
  Val runIf(ast::If* ifst);
  Val runOp(ast::Op* op);

  Val eval(ast::Node* n);
  ast::Fn* getFn(const Typename& tname);
  ast::Fn* lookupImplFn(Val obj, const std::string& impl_name, const std::string& fn_name);

  const Type* addType(Type&& t);
  Val valFromAstType(ast::Type* type);
  const Type* typeFromAst(ast::Type* ast_type);
  Typename typenameFromAst(ast::Typename* ast_typename);

  // Value operations:
  Val assign(Val l, Val r);
  Val add(Val l, Val r);
  Val sub(Val l, Val r);
  Val lt(Val l, Val r);
  Val lor(Val l, Val r);
  Val eq(Val l, Val r);
  Val neq(Val l, Val r);
  Val array_access(Val l, Val r);
  Val preinc(Val l);
  Val postinc(Val l);
  Val addr(const Val& l);
  Val copy(Val dst, Val src);
  Val deref(const Val& l);

  template <typename F>
  auto invokeBuiltin(Val v, F op) {
    if (v.type == bool_) return std::invoke(op, vm_.ref<bool>(v));
    else if (v.type == i8_)
      return std::invoke(op, vm_.ref<int8_t>(v));
    else if (v.type == i16_)
      return std::invoke(op, vm_.ref<int16_t>(v));
    else if (v.type == i32_)
      return std::invoke(op, vm_.ref<int32_t>(v));
    else if (v.type == i64_)
      return std::invoke(op, vm_.ref<int64_t>(v));
    else if (v.type == u8_)
      return std::invoke(op, vm_.ref<uint8_t>(v));
    else if (v.type == u16_)
      return std::invoke(op, vm_.ref<uint16_t>(v));
    else if (v.type == u32_)
      return std::invoke(op, vm_.ref<uint32_t>(v));
    else if (v.type == u64_)
      return std::invoke(op, vm_.ref<uint64_t>(v));
    else if (v.type == f32_)
      return std::invoke(op, vm_.ref<float>(v));
    else if (v.type == f64_)
      return std::invoke(op, vm_.ref<double>(v));
    error("not builtin");
    return std::invoke(op, vm_.ref<int8_t>(v));
  }

  template <typename F>
  Val binop(Val l, Val r, const Type* type, const std::string& op_name, F default_op) {
    bug_unless(type && l.type && r.type);

    if (auto* fn = lookupImplFn(l, "Comparable", op_name)) return runFn(fn, {addr(r)}, l);

    if (l.type != r.type)
      error("no Comparable defined and types don't match: " + l.type->toString() + " " +
          r.type->toString());

    return invokeBuiltin(l, [this, &default_op, &r, &type](auto lt) {
      auto res = default_op(lt, vm_.ref<decltype(lt)>(r));
      Val v{.hnd = vm_.allocTmp(sizeof(res)), .type = type};
      vm_.ref<decltype(res)>(v) = res;
      return v;
    });
  }

  template <typename F>
  Val unop(Val l, const Type* type, const std::string& op_name, F default_op) {
    bug_unless(type && l.type);
    if (auto* fn = lookupImplFn(l, "UnaryArith", op_name)) return runFn(fn, {}, l);
    auto res = invokeBuiltin(l, [this, &default_op](auto lt) { return default_op(lt); });
    Val v{.hnd = vm_.allocTmp(sizeof(res)), .type = type};
    vm_.ref<decltype(res)>(v) = res;
    return v;
  }
};

}  // namespace memelang::exec

#endif  // MEMELANG_EXEC_H
