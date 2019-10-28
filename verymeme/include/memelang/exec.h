#ifndef MEMELANG_EXEC_H
#define MEMELANG_EXEC_H

#include <map>

#include "memelang/ast.h"
#include "memelang/scopes.h"
#include "memelang/type.h"
#include "memelang/vm.h"
#include "verymeme/macros.h"

namespace memelang::exec {

// TODO: Don't hardcode these.
const inline std::unordered_set<std::string> WILDCARD_HACK = {"T", "I", "A", "B"};

class Exec {
public:
  Exec(ast::File* file, const FileContents* cts);

  void run();
  void error(const std::string& msg) const;
  Val eval(ast::Node* n);
  VM& vm() { return vm_; }
  ast::File* file() { return f_; }
  void setContext(ast::Node* node) { node_ctx_ = node; }
  ast::Node* context() { return node_ctx_; }
  const FileContents* fileContents() const { return cts_; }

private:
  ast::File* f_;
  const FileContents* cts_;
  ast::Node* node_ctx_{};
  Scope s_;
  VM vm_;

  Val runFn(
      ast::Fn* fn, const std::vector<Mapping>& mappings, const std::vector<Val>& params, Val ths);
  Val runStmtBlk(ast::StmtBlk* blk);
  Val runStmt(ast::Node* stmt);
  void runVarDefn(ast::VarDefn* defn);
  Val runVarDecl(ast::VarDecl* decl);
  Val runFor(ast::For* fr);
  Val runWhile(ast::While* wh);
  Val runIf(ast::If* ifst);
  Val runOp(ast::Op* op);

  Val valFromAstType(ast::Type* type);

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
    if (!v.type || v.hnd == INVALID_HND) error("attempt operate on value with undeducible type");

    if (v.type == s_.bool_t) return std::invoke(op, vm_.ref<bool>(v));
    else if (v.type == s_.i8_t)
      return std::invoke(op, vm_.ref<int8_t>(v));
    else if (v.type == s_.i16_t)
      return std::invoke(op, vm_.ref<int16_t>(v));
    else if (v.type == s_.i32_t)
      return std::invoke(op, vm_.ref<int32_t>(v));
    else if (v.type == s_.i64_t)
      return std::invoke(op, vm_.ref<int64_t>(v));
    else if (v.type == s_.u8_t)
      return std::invoke(op, vm_.ref<uint8_t>(v));
    else if (v.type == s_.u16_t)
      return std::invoke(op, vm_.ref<uint16_t>(v));
    else if (v.type == s_.u32_t)
      return std::invoke(op, vm_.ref<uint32_t>(v));
    else if (v.type == s_.u64_t)
      return std::invoke(op, vm_.ref<uint64_t>(v));
    else if (v.type == s_.f32_t)
      return std::invoke(op, vm_.ref<float>(v));
    else if (v.type == s_.f64_t)
      return std::invoke(op, vm_.ref<double>(v));
    else if (v.type->isPtr())
      return std::invoke(op, vm_.ref<Hnd>(v));
    error("not builtin: " + v.type->toString());
    return std::invoke(op, vm_.ref<int8_t>(v));
  }

  template <typename F>
  Val binop(Val l, Val r, const Type* type_if_builtin, const std::string& op_name, F default_op) {
    if (!l.type || l.hnd == INVALID_HND || !r.type || r.hnd == INVALID_HND)
      error("attempt operate on value with undeducible type");

    if (auto res = s_.lookupImplFn(l, {addr(r)}, "Comparable", op_name); res.fn)
      return runFn(res.fn, res.type_mappings, {addr(r)}, l);
    if (auto res = s_.lookupImplFn(l, {addr(r)}, "BinaryArith", op_name); res.fn)
      return runFn(res.fn, res.type_mappings, {addr(r)}, l);

    if (l.type != r.type)
      error("no Comparable defined and types don't match: " + l.type->toString() + " " +
          r.type->toString());

    return invokeBuiltin(l, [this, &default_op, &r, &type_if_builtin](auto lt) {
      auto res = default_op(lt, vm_.ref<decltype(lt)>(r));
      Val v{.hnd = vm_.allocTmp(sizeof(res)), .type = type_if_builtin};
      vm_.ref<decltype(res)>(v) = res;
      return v;
    });
  }

  template <typename F>
  Val unop(Val l, const Type* type, const std::string& op_name, F default_op) {
    if (!l.type || l.hnd == INVALID_HND) error("attempt operate on value with undeducible type");

    if (auto res = s_.lookupImplFn(l, {}, "UnaryArith", op_name); res.fn)
      return runFn(res.fn, res.type_mappings, {}, l);
    auto res = invokeBuiltin(l, [this, &default_op](auto lt) { return default_op(lt); });
    Val v{.hnd = vm_.allocTmp(sizeof(res)), .type = type};
    vm_.ref<decltype(res)>(v) = res;
    return v;
  }
};

}  // namespace memelang::exec

#endif  // MEMELANG_EXEC_H
