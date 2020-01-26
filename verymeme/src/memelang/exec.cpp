#include "memelang/exec.h"

#include <iostream>

#include "memelang/constants.h"

namespace memelang::exec {

namespace {

template <typename T, typename R>
T* g(R* n) {
  bug_unless(typeid(*n) == typeid(T));
  return reinterpret_cast<T*>(n);
}

template <typename T, typename R>
T* g(std::unique_ptr<R>& n) {
  return g<T>(n.get());
}

}  // namespace

// See if the expression contains a return statement, and return it if it returns.
#define CHECK(expr) \
  do { \
    auto opt = (expr); \
    static_assert( \
        std::is_same<decltype(opt), std::optional<Val>>::value, "must use optional<Val>"); \
    if (opt) return opt; \
  } while (0)

Exec::Exec(ast::Module* m) : m_(m), s_(this), vm_(this) {}

void Exec::run() {
  fprintf(stderr, "===BEGIN PROGRAM===\n");
  const auto& type = s_.t(s_.findValue("main").type);
  if (!std::holds_alternative<FnSetInfo>(type.info)) error("main name does not refer to function");
  if (!runFn(std::get<FnSetInfo>(type.info), {})) error("no main function to execute");
  fprintf(stderr, "===END PROGRAM===\n");
}

std::optional<Val> Exec::runFn(const FnSetInfo& fnset, const std::vector<Val>& params) {
  // Look for first doable option based on parameters.
  for (const auto& fninfo : fnset.fns) {
    const auto& fn = fninfo.fn;
    const auto& m = fninfo.m;
    auto autoscope = s_.autoScope(fn, m);
    // Resolve any other wildcards + check types.
    const auto& [can_do, fn_mapping] = s_.maybeMappingForFnCall(fn, params);
    if (!can_do) continue;
    s_.mergeMapping(fn_mapping);

    if (fnset.self.hasStorage()) s_.declareVar("self", ref(fnset.self));
    for (int i = 0; i < fn->sig->params.size(); ++i) {
      auto& decl = fn->sig->params[i];
      runStmt(decl.get(), s_.typeFromAst(decl->type.get(), true));
      copy(s_.findValue(decl->name), params[i]);  // Use copy not assign so we can set const vals.
    }
    TypeId ret_type = s_.typeFromAst(fn->sig->ret_type.get(), true);
    auto val = runStmtBlk(fn->blk.get(), ret_type);
    // Successfully executed the function, so make sure to return something.
    return val ? val : INVL_VAL;
  }
  return std::nullopt;
}

Val Exec::runBuiltinFn(ast::Op* n) {
  const std::string& name = g<ast::Ref>(n->left)->name;
  auto& args = g<ast::FnCallArgs>(n->right)->args;
  if (name == "printf") {
    if (args.empty()) error("printf requires at least 1 argument");
    if (typeid(*args[0]) != typeid(ast::StrLit)) error("printf must take string literal for now");
    boost::format fmt = boost::format(g<ast::StrLit>(args[0])->val);
    for (int i = 1; i < args.size(); ++i)
      invokeBuiltin(eval(args[i].get(), INVL_TID), [&fmt](auto& a) { fmt = fmt % a; });
    printf("%s", fmt.str().c_str());
    return INVL_VAL;
  } else if (name == "readf") {
    if (args.size() != 2) error("readf requires 2 arguments");
    auto read_ptr = eval(args[0].get(), s_.u8_ptr_t);
    auto read_sz = eval(args[1].get(), s_.u32_t);

    if (read_ptr.type != s_.u8_ptr_t)
      error("wrong type: " + s_.t(read_ptr.type).str() + " need: " + s_.t(s_.u8_ptr_t).str());
    if (read_sz.type != s_.u32_t) error("wrong type: " + s_.t(read_sz.type).str());
    std::cin.getline(&vm_.ref<char>(deptr(read_ptr).hnd), vm_.ref<int32_t>(read_sz.hnd));

    auto ret = Val(vm_.allocTmp(s_.t(s_.u32_t).size()), s_.u32_t);
    vm_.write(ret.hnd, uint32_t(std::cin.gcount()));
    return ret;
  } else if (name == "sizeof") {
    if (args.size() != 1) error("sizeof requires 1 argument");
    auto val = eval(args[0].get(), INVL_TID);
    if (val.type == INVL_TID) error("attempt operate on value with undeducible type");
    auto ret = Val(vm_.allocTmp(s_.t(s_.u32_t).size()), s_.u32_t);
    vm_.write(ret.hnd, uint32_t(s_.t(val.type).size()));
    return ret;
  } else if (name == "_malloc") {
    if (args.size() != 1) error("_malloc requires 1 argument");
    auto arg = eval(args[0].get(), s_.u32_t);
    if (arg.type != s_.u32_t) error("_malloc requires u32 argument");
    Hnd data = vm_.allocTmp(vm_.ref<uint32_t>(arg.hnd));
    auto ret_val = Val(vm_.allocStack(s_.t(s_.u8_ptr_t).size()), s_.u8_ptr_t);
    vm_.write(ret_val.hnd, data);
    return ret_val;
  }
  error("unknown builtin function " + name);
}

std::optional<Val> Exec::runStmtBlk(ast::StmtBlk* blk, TypeId typectx) {
  auto autonest = s_.autoNest();
  for (auto& stmt : blk->stmts) CHECK(runStmt(stmt.get(), typectx));
  return std::nullopt;
}

std::optional<Val> Exec::runStmt(ast::Node* stmt, TypeId typectx) {
  setContext(stmt);

  if (typeid(*stmt) == typeid(ast::VarDefn)) {
    runVarDefn(g<ast::VarDefn>(stmt));
  } else if (typeid(*stmt) == typeid(ast::VarDecl)) {
    runVarDecl(g<ast::VarDecl>(stmt));
  } else if (typeid(*stmt) == typeid(ast::Op)) {
    // Ignore return value as there won't ever be a return statement in an op.
    runOp(g<ast::Op>(stmt));
  } else if (typeid(*stmt) == typeid(ast::For)) {
    return runFor(g<ast::For>(stmt), typectx);
  } else if (typeid(*stmt) == typeid(ast::While)) {
    return runWhile(g<ast::While>(stmt), typectx);
  } else if (typeid(*stmt) == typeid(ast::Ret)) {
    auto* ret = g<ast::Ret>(stmt);
    if (ret->ret) return eval(ret->ret.get(), typectx);
    return INVL_VAL;
  } else if (typeid(*stmt) == typeid(ast::If)) {
    return runIf(g<ast::If>(stmt), typectx);
  } else {
    error("unimplemented statement " + stmt->str());
  }
  return std::nullopt;
}

void Exec::runVarDefn(ast::VarDefn* defn) {
  auto val = eval(defn->defn.get(), s_.typeFromAst(defn->decl->type.get(), true));
  auto cpy = Val(vm_.allocStack(s_.t(val.type).size()), val.type);
  copy(cpy, val);  // Make sure to copy to not grab references to existing objects.
  s_.declareVar(defn->decl->name, cpy);
}

Val Exec::runVarDecl(ast::VarDecl* decl) {
  return s_.declareVar(decl->name, valFromAstType(decl->type.get()));
}

Val Exec::runOp(ast::Op* op) {
  setContext(op);

  Val left = eval(op->left.get(), INVL_TID);
  switch (op->type) {
  case ast::Expr::FN_CALL: {
    auto* args = g<ast::FnCallArgs>(op->right);

    TypeId tid = left.type;
    const auto& type = s_.t(tid);
    if (std::holds_alternative<BuiltinFnInfo>(type.info)) {
      return runBuiltinFn(op);
    } else if (std::holds_alternative<FnSetInfo>(type.info)) {
      std::vector<Val> params;
      // TODO: allow deduction of types of fn parameters.
      for (auto& arg : args->args) params.emplace_back(eval(arg.get(), INVL_TID));
      if (auto opt = runFn(std::get<FnSetInfo>(type.info), params); opt) return opt.value();
      else
        error("unable to resolve function " + type.str());
    } else {
      error("function call on non-function " + type.str());  // TODO: Paren operator?
    }
  }
  case ast::Expr::MEMBER_ACCESS: {
    if (typeid(*op->right) != typeid(ast::Ref)) error("member access must be ref");
    auto* ref = g<ast::Ref>(op->right);

    const auto& type = s_.t(left.type);
    Hnd data_hnd = type.isRefOrPtr() ? follow_refptr(left).hnd : left.hnd;
    if (std::holds_alternative<StructInfo>(type.info)) {
      const auto& info = std::get<StructInfo>(type.info);
      auto fnset = s_.findImplFnSet(left, "", ref->name);
      if (!fnset.fns.empty()) return Val(INVL_HND, s_.addType(Type(std::move(fnset))));
      if (auto val = info.access(data_hnd, ref->name); val != INVL_VAL) return val;
      error("unknown struct member " + ref->name);
    } else if (std::holds_alternative<EnumInfo>(type.info)) {
      const auto& info = std::get<EnumInfo>(type.info);
      // TODO: Typed enums
      return info.access(ref->name);
    } else {
      error("unimplemented member access");
    }
    break;
  }
  case ast::Expr::ASSIGNMENT: return assign(left, eval(op->right.get(), left.type));
  case ast::Expr::MUL: return mul(left, eval(op->right.get(), left.type));
  case ast::Expr::ADD: return add(left, eval(op->right.get(), left.type));
  case ast::Expr::SUB: return sub(left, eval(op->right.get(), left.type));
  case ast::Expr::LT: return lt(left, eval(op->right.get(), left.type));
  case ast::Expr::GT: return gt(left, eval(op->right.get(), left.type));
  case ast::Expr::LOR: return lor(left, eval(op->right.get(), left.type));
  case ast::Expr::EQ: return eq(left, eval(op->right.get(), left.type));
  case ast::Expr::NEQ: return neq(left, eval(op->right.get(), left.type));
  case ast::Expr::ARRAY_ACCESS: return array_access(left, eval(op->right.get(), left.type));
  case ast::Expr::PREFIX_INC: return preinc(left);
  case ast::Expr::POSTFIX_INC: return postinc(left);
  case ast::Expr::UNARY_ADDR: return addr(left);
  case ast::Expr::UNARY_DEREF: return deptr(left);
  default: error("unhandled op");
  }
}

std::optional<Val> Exec::runFor(ast::For* fr, TypeId typectx) {
  runVarDefn(fr->var_defn.get());
  while (true) {
    auto cond_val = eval(fr->cond.get(), s_.bool_t);
    if (cond_val.type != s_.bool_t) error("for condition not boolean");
    if (!vm_.ref<bool>(cond_val.hnd)) break;
    CHECK(runStmtBlk(fr->blk.get(), typectx));
    eval(fr->update.get(), INVL_TID);
  }
  return std::nullopt;
}

std::optional<Val> Exec::runWhile(ast::While* wh, TypeId typectx) {
  while (true) {
    auto cond_val = eval(wh->cond.get(), s_.bool_t);
    if (cond_val.type != s_.bool_t) error("while condition not boolean");
    if (!vm_.ref<bool>(cond_val.hnd)) break;
    CHECK(runStmtBlk(wh->blk.get(), typectx));
  }
  return std::nullopt;
}

std::optional<Val> Exec::runIf(ast::If* ifst, TypeId typectx) {
  auto cond_val = eval(ifst->cond.get(), s_.bool_t);
  if (cond_val.type != s_.bool_t) error("if condition not boolean");
  if (vm_.ref<bool>(cond_val.hnd)) CHECK(runStmtBlk(ifst->then.get(), typectx));
  else if (ifst->els)
    CHECK(runStmtBlk(ifst->els.get(), typectx));
  return std::nullopt;
}

Val Exec::eval(ast::Node* n, TypeId typectx) {
  setContext(n);

  if (typeid(*n) == typeid(ast::Op)) return runOp(g<ast::Op>(n));
  if (typeid(*n) == typeid(ast::Ref)) return s_.findValue(g<ast::Ref>(n));
  if (typeid(*n) == typeid(ast::IntLit)) {
    TypeId type = g<ast::IntLit>(n)->unsign ? s_.u32_t : s_.i32_t;
    auto val = Val(vm_.allocTmp(s_.t(type).size()), type);
    vm_.write(val.hnd, uint32_t(g<ast::IntLit>(n)->val));
    return val;
  }
    if (typeid(*n) == typeid(ast::BoolLit)) {
    auto val = Val(vm_.allocTmp(s_.t(s_.bool_t).size()), s_.bool_t);
    vm_.write(val.hnd, uint8_t(g<ast::BoolLit>(n)->val));
    return val;
  }
  if (typeid(*n) == typeid(ast::StrLit)) {
    const std::string& s = g<ast::StrLit>(n)->val;
    auto val = Val(vm_.allocTmp(s_.t(s_.u8_ptr_t).size()), s_.u8_ptr_t);
    auto storage_hnd = vm_.allocTmp(s.size());
    vm_.write(val.hnd, storage_hnd);
    for (int i = 0; i < s.size(); ++i) vm_.write(storage_hnd + i, s[i]);
    return val;
  }
  if (typeid(*n) == typeid(ast::CharLit)) {
    auto val = Val(vm_.allocTmp(s_.t(s_.u8_t).size()), s_.u8_t);
    vm_.write(val.hnd, uint8_t(g<ast::CharLit>(n)->val));
    return val;
  }
  if (typeid(*n) == typeid(ast::CompoundLit)) {
    const auto& cmpd = g<ast::CompoundLit>(n);
    // Use given type if it exists, otherwise use type context.
    TypeId tid = cmpd->type ? s_.typeFromAst(cmpd->type.get(), true) : typectx;
    if (tid == INVL_TID) error("undeducible type");
    const auto& type = s_.t(tid);
    Val res(vm_.allocTmp(type.size()), tid);
    vm_.memset(res, 0, s_.t(res.type).size());
    // Type constructor / conversion
    if (std::holds_alternative<BuiltinStorageInfo>(type.info) && !cmpd->frags.empty()) {
      if (cmpd->frags.size() != 1) error("conversion must have 1 arg");
      Val val = eval(cmpd->frags[0]->lit.get(), tid);
      invokeBuiltin(val, [this, &res](auto val_v) {
        invokeBuiltin(
            res, [this, &val_v, &res](auto res_v) { vm_.write(res.hnd, decltype(res_v)(val_v)); });
      });
    } else if (auto* st = std::get_if<StructInfo>(&type.info); st) {
      int offset = 0;
      for (const auto& frag : cmpd->frags) {
        if (!frag->name.empty()) {
          Val dst = st->access(res.hnd, frag->name);
          copy(dst, eval(frag->lit.get(), dst.type));
        } else {
          Val dst = st->access(res.hnd, offset);
          Val src = eval(frag->lit.get(), dst.type);
          copy(dst, src);
          offset += s_.t(src.type).size();
        }
      }
    }
    return res;
  }
  if (typeid(*n) == typeid(ast::Type)) return Val(INVL_HND, s_.typeFromAst(g<ast::Type>(n), true));
  error("unimplemented eval node " + n->str());
}

Val Exec::valFromAstType(ast::Type* ast_type) {
  auto type = s_.typeFromAst(ast_type, true);
  Val val = Val(vm_.allocStack(s_.t(type).size()), type);
  vm_.memset(val, 0, s_.t(type).size());
  return val;
}

[[noreturn]] void Exec::error(const std::string& msg) const {
  if (node_ctx_)
    verify_expr(false, "error at '%s' (%s): %s\n%s\n", node_ctx_->tok.span().c_str(),
        node_ctx_->tok.fpos().c_str(), msg.c_str(), s_.stacktrace().c_str());
  else
    verify_expr(false, "error: %s\n%s\n", msg.c_str(), s_.stacktrace().c_str());
}

Val Exec::assign(Val l, Val r) {
  if (!s_.t(l.type).isSubsetOf(s_.t(r.type)))
    error("assignment to value of different type, " + s_.t(l.type).str() + " = " +
        s_.t(r.type).str().c_str());
  return copy(l, r);
}

Val Exec::mul(Val l, Val r) {
  return binop(l, r, maybe_unref(l).type, "mul", [](auto a, auto b) { return a * b; });
}

Val Exec::add(Val l, Val r) {
  return binop(l, r, maybe_unref(l).type, "add", [](auto a, auto b) { return a + b; });
}

Val Exec::sub(Val l, Val r) {
  return binop(l, r, maybe_unref(l).type, "sub", [](auto a, auto b) { return a - b; });
}

Val Exec::lt(Val l, Val r) {
  return binop(l, r, s_.bool_t, "lt", [](auto a, auto b) { return a < b; });
}

Val Exec::gt(Val l, Val r) {
  return binop(l, r, s_.bool_t, "gt", [](auto a, auto b) { return a > b; });
}

Val Exec::lor(Val l, Val r) {
  return binop(l, r, s_.bool_t, "lor", [](auto a, auto b) { return a || b; });
}

Val Exec::eq(Val l, Val r) {
  return binop(l, r, s_.bool_t, "eq", [](auto a, auto b) { return a == b; });
}

Val Exec::neq(Val l, Val r) {
  return binop(l, r, s_.bool_t, "neq", [](auto a, auto b) { return a != b; });
}

Val Exec::array_access(Val l, Val r) {
  if (!l.hasStorage() || !r.hasStorage()) error("attempt operate on value without storage");

  if (auto opt = runFn(s_.findImplFnSet(l, "Indexable", "index"), {ref(r)}); opt)
    return opt.value();

  Type new_type = s_.t(maybe_unref(l).type);
  if (r.type != s_.u32_t && r.type != s_.i32_t) error("array access index must be i32 or u32");
  if (!new_type.isArray()) error("array access on non-array type " + new_type.str());
  new_type.quals.pop_back();  // Remove array qualifier.
  const Hnd new_hnd = l.hnd + vm_.ref<int32_t>(r.hnd) * new_type.size();
  return Val{new_hnd, s_.addType(new_type)};
}

Val Exec::preinc(Val l) {
  return unop(l, "preinc", [this, &l](auto v) {
    vm_.write(l.hnd, v + 1);
    return l;
  });
}

Val Exec::postinc(Val l) {
  return unop(l, "postinc", [this, &l](auto v) {
    Val tmp(vm_.allocTmp(s_.t(l.type).size()), maybe_unref(l).type);
    copy(tmp, l);
    vm_.write(l.hnd, v + 1);
    return tmp;
  });
}

Val Exec::addr(Val l) {
  if (!l.hasStorage()) error("attempt operate on value without storage");
  auto new_type = s_.t(l.type);
  new_type.quals.emplace_back();
  new_type.quals.back().ptr = true;
  auto new_value = Val(vm_.allocTmp(sizeof(Hnd)), s_.addType(new_type));
  vm_.write(new_value.hnd, l.hnd);
  return new_value;
}

Val Exec::ref(Val l) {
  auto ref_type = s_.t(l.type);
  ref_type.ref = true;
  return Val(l.hnd, s_.addType(ref_type));
}

Val Exec::maybe_unref(Val l) {
  auto unref_type = s_.t(l.type);
  unref_type.ref = false;
  return Val(l.hnd, s_.addType(unref_type));
}

Val Exec::follow_refptr(Val l) {
  const auto& type = s_.t(l.type);
  if (!type.isRefOrPtr()) error("attempt to follow non-ref/ptr");
  if (type.ref) return maybe_unref(l);
  return deptr(l);
}

Val Exec::copy(Val dst, Val src) {
  if (!src.hasStorage() || !dst.hasStorage()) error("attempt operate on value without storage");
  vm_.memcpy(dst, src, s_.t(src.type).size());
  return dst;
}

Val Exec::deptr(Val l) {
  if (!l.hasStorage()) error("attempt operate on value without storage");
  Type new_type = s_.t(maybe_unref(l).type);
  if (!new_type.isPtr()) error("attempt to dereference non-pointer type");
  new_type.quals.pop_back();  // Remove ptr.
  return Val(vm_.ref<Hnd>(l.hnd), s_.addType(new_type));
}

}  // namespace memelang::exec
