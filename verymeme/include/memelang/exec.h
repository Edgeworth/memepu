#ifndef MEMELANG_EXEC_H
#define MEMELANG_EXEC_H

#include <map>
#include <variant>

#include "memelang/ast.h"
#include "memelang/scopes.h"
#include "memelang/type.h"
#include "memelang/vm.h"
#include "verymeme/macros.h"

namespace memelang::exec {

class Exec {
public:
  explicit Exec(ast::Module* m);

  void run();
  [[noreturn]] void error(const std::string& msg) const;
  Val eval(ast::Node* n, TypeId typectx);
  VM& vm() { return vm_; }
  Scope& scope() { return s_; }
  ast::Module* module() { return m_; }
  void setContext(ast::Node* node) { node_ctx_ = node; }
  ast::Node* context() { return node_ctx_; }

private:
  ast::Module* m_;
  ast::Node* node_ctx_{};
  Scope s_;
  VM vm_;

  std::optional<Val> runFn(const FnSetInfo& fnset, const std::vector<Val>& params, Val ths);
  Val runBuiltinFn(ast::Op* n);
  Val runStmtBlk(ast::StmtBlk* blk, TypeId typectx);
  Val runStmt(ast::Node* stmt, TypeId typectx);
  void runVarDefn(ast::VarDefn* defn);
  Val runVarDecl(ast::VarDecl* decl);
  Val runFor(ast::For* fr, TypeId typectx);
  Val runWhile(ast::While* wh, TypeId typectx);
  Val runIf(ast::If* ifst, TypeId typectx);
  Val runOp(ast::Op* op);

  Val valFromAstType(ast::Type* type);

  // Value operations:
  Val assign(Val l, Val r);
  Val mul(Val l, Val r);
  Val add(Val l, Val r);
  Val sub(Val l, Val r);
  Val lt(Val l, Val r);
  Val lor(Val l, Val r);
  Val eq(Val l, Val r);
  Val neq(Val l, Val r);
  Val array_access(Val l, Val r);
  Val preinc(Val l);
  Val postinc(Val l);
  Val addr(Val l);
  Val copy(Val dst, Val src);
  Val deref(Val l);

  template <typename F>
  auto invokeBuiltin(Val v, F op) {
    if (v.type == INVL_TID || v.hnd == INVL_HND)
      error("attempt operate on value with undeducible type");

    if (v.type == s_.bool_t) return std::invoke(op, vm_.ref<bool>(v.hnd));
    else if (v.type == s_.i8_t)
      return std::invoke(op, vm_.ref<int8_t>(v.hnd));
    else if (v.type == s_.i16_t)
      return std::invoke(op, vm_.ref<int16_t>(v.hnd));
    else if (v.type == s_.i32_t)
      return std::invoke(op, vm_.ref<int32_t>(v.hnd));
    else if (v.type == s_.i64_t)
      return std::invoke(op, vm_.ref<int64_t>(v.hnd));
    else if (v.type == s_.u8_t)
      return std::invoke(op, vm_.ref<uint8_t>(v.hnd));
    else if (v.type == s_.u16_t)
      return std::invoke(op, vm_.ref<uint16_t>(v.hnd));
    else if (v.type == s_.u32_t)
      return std::invoke(op, vm_.ref<uint32_t>(v.hnd));
    else if (v.type == s_.u64_t)
      return std::invoke(op, vm_.ref<uint64_t>(v.hnd));
    else if (v.type == s_.f32_t)
      return std::invoke(op, vm_.ref<float>(v.hnd));
    else if (v.type == s_.f64_t)
      return std::invoke(op, vm_.ref<double>(v.hnd));
    else if (s_.t(v.type).isPtr())
      return std::invoke(op, vm_.ref<Hnd>(v.hnd));
    error("not builtin: " + s_.t(v.type).str());
    return std::invoke(op, vm_.ref<int8_t>(v.hnd));
  }

  template <typename F>
  Val binop(Val l, Val r, TypeId type_if_builtin, const std::string& op_name, F default_op) {
    if (l.type == INVL_TID || l.hnd == INVL_HND || r.type == INVL_TID || r.hnd == INVL_HND)
      error("attempt operate on value with undeducible type");

    if (auto opt = runFn(s_.findImplFnSet(l.type, "Comparable", op_name), {addr(r)}, l); opt)
      return opt.value();
    if (auto opt = runFn(s_.findImplFnSet(l.type, "BinaryArith", op_name), {addr(r)}, l); opt)
      return opt.value();

    if (l.type != r.type)
      error("no binop intf defined and types don't match: " + s_.t(l.type).str() + " " +
          s_.t(r.type).str());

    return invokeBuiltin(l, [this, &default_op, &r, &type_if_builtin](auto lt) {
      auto res = default_op(lt, vm_.ref<decltype(lt)>(r.hnd));
      Val v(vm_.allocTmp(sizeof(res)), type_if_builtin);
      vm_.ref<decltype(res)>(v.hnd) = res;
      return v;
    });
  }

  template <typename F>
  Val unop(Val l, const std::string& op_name, F default_op) {
    if (l.type == INVL_TID || l.hnd == INVL_HND)
      error("attempt operate on value with undeducible type");

    if (auto opt = runFn(s_.findImplFnSet(l.type, "UnaryArith", op_name), {}, l); opt)
      return opt.value();
    return invokeBuiltin(l, [this, &default_op](auto lt) { return default_op(lt); });
  }
};

}  // namespace memelang::exec

#endif  // MEMELANG_EXEC_H
