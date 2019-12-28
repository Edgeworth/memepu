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
    auto val = (expr); \
    if (val.hnd != INVALID_HND) return val; \
  } while (0)

Exec::Exec(ast::Module* m) : m_(m), s_(this), vm_(this) {}

void Exec::run() {
  fprintf(stderr, "===BEGIN PROGRAM===\n");
  TypeId fnid = s_.maybeFindFn("main");
  if (fnid == INVALID_TYPEID) error("no main function to execute");
  runFn(fnid, {}, INVALID_VAL);
  fprintf(stderr, "===END PROGRAM===\n");
}

Val Exec::runFn(TypeId fnid, const std::vector<Val>& params, Val ths) {
  const auto& fninfo = std::get<FnInfo>(s_.t(fnid).info);
  auto* fn = fninfo.fn;
  Mapping fn_map = typelistToMapping(fn->sig->tname->tlist.get(), nullptr);
  fn_map.merge(s_.t(fnid).m);
  auto autoscope = s_.autoScope(fn, fn_map);
  printf("calling fn: %s\n", s_.t(fnid).str().c_str());

  if (fn->sig->params.size() != params.size()) error("wrong number of arguments");
  if (ths.hnd != INVALID_HND) s_.declareVar("this", addr(ths));
  for (int i = 0; i < int(fn->sig->params.size()); ++i) {
    auto& decl = fn->sig->params[i];
    runStmt(decl.get());
    assign(s_.findVar(decl->ref->name), params[i]);
  }
  auto val = runStmtBlk(fn->blk.get());
  return val;
}

Val Exec::runBuiltinFn(ast::Op* n) {
  const std::string& name = g<ast::Type>(n->left)->name;
  auto& args = g<ast::FnCallArgs>(n->right)->args;
  TypeId u8_ptr_t =
      s_.addType(Type(s_.t(s_.u8_t).info, false, {{.ptr = true}}, Mapping(this), this));
  if (name == "printf") {
    if (args.empty()) error("printf requires at least 1 argument");
    if (typeid(*args[0]) != typeid(ast::StrLit)) error("printf must take string literal for now");
    boost::format fmt = boost::format(g<ast::StrLit>(args[0])->val);
    for (int i = 1; i < int(args.size()); ++i)
      invokeBuiltin(eval(args[i].get()), [&fmt](auto& a) { fmt = fmt % a; });
    printf("%s", fmt.str().c_str());
    return INVALID_VAL;
  } else if (name == "readf") {
    if (args.size() != 2) error("readf requires 2 arguments");
    auto read_ptr = eval(args[0].get());
    auto read_sz = eval(args[1].get());

    if (read_ptr.type != u8_ptr_t)
      error("wrong type: " + s_.t(read_ptr.type).str() + " need: " + s_.t(u8_ptr_t).str());
    if (read_sz.type != s_.u32_t) error("wrong type: " + s_.t(read_sz.type).str());
    std::cin.getline(&vm_.ref<char>(deref(read_ptr).hnd), vm_.ref<int32_t>(read_sz.hnd));

    auto ret = Val(vm_.allocTmp(s_.t(s_.u32_t).size()), s_.u32_t);
    vm_.write(ret.hnd, uint32_t(std::cin.gcount()));
    return ret;
  } else if (name == "sizeof") {
    if (args.size() != 1) error("sizeof requires 1 argument");
    auto val = eval(args[0].get());
    if (val.type == INVALID_TYPEID) error("attempt operate on value with undeducible type");
    auto ret = Val(vm_.allocTmp(s_.t(s_.u32_t).size()), s_.u32_t);
    vm_.write(ret.hnd, uint32_t(s_.t(val.type).size()));
    return ret;
  } else if (name == "_malloc") {
    if (args.size() != 1) error("_malloc requires 1 argument");
    auto val = eval(args[0].get());
    if (val.type != s_.u32_t) error("_malloc requires u32 argument");
    return Val(vm_.allocTmp(vm_.ref<uint32_t>(val.hnd)), u8_ptr_t);
  }
  error("unknown builtin function " + name);
}

Val Exec::runStmtBlk(ast::StmtBlk* blk) {
  auto autonest = s_.autoNest();
  for (auto& stmt : blk->stmts) CHECK(runStmt(stmt.get()));
  return INVALID_VAL;
}

Val Exec::runStmt(ast::Node* stmt) {
  setContext(stmt);

  if (typeid(*stmt) == typeid(ast::VarDefn)) {
    runVarDefn(g<ast::VarDefn>(stmt));
  } else if (typeid(*stmt) == typeid(ast::VarDecl)) {
    runVarDecl(g<ast::VarDecl>(stmt));
  } else if (typeid(*stmt) == typeid(ast::Op)) {
    // Ignore return value as there won't ever be a return statement in an op.
    runOp(g<ast::Op>(stmt));
  } else if (typeid(*stmt) == typeid(ast::For)) {
    return runFor(g<ast::For>(stmt));
  } else if (typeid(*stmt) == typeid(ast::While)) {
    return runWhile(g<ast::While>(stmt));
  } else if (typeid(*stmt) == typeid(ast::Ret)) {
    return eval(g<ast::Ret>(stmt)->ret.get());
  } else if (typeid(*stmt) == typeid(ast::If)) {
    return runIf(g<ast::If>(stmt));
  } else {
    error("unimplemented statement " + stmt->str());
  }
  return INVALID_VAL;
}

void Exec::runVarDefn(ast::VarDefn* defn) {
  bug_unless(defn->defn);
  if (defn->decl->type) {
    assign(runVarDecl(defn->decl.get()), eval(defn->defn.get()));
  } else {
    // If no type specifier, just use the definition directly.
    auto init = eval(defn->defn.get());
    if (init.type == INVALID_TYPEID || init.hnd == INVALID_HND)
      error("attempt operate on value with undeducible type");
    auto val = Val(vm_.allocStack(s_.t(init.type).size()), init.type);
    copy(val, init);
    s_.declareVar(defn->decl->ref->name, val);
  }
}

Val Exec::runVarDecl(ast::VarDecl* decl) {
  return s_.declareVar(decl->ref->name, valFromAstType(decl->type.get()));
}

Val Exec::runOp(ast::Op* op) {
  setContext(op);

  switch (op->type) {
  case ast::Expr::FN_CALL: {
    auto* args = g<ast::FnCallArgs>(op->right);
    TypeId tid = eval(op->left.get()).type;
    const auto& type = s_.t(tid);

    // Type constructor / conversion
    if (std::holds_alternative<BuiltinStorageInfo>(type.info)) {
      if (args->args.size() != 1)
        error("conversion must have 1 arg");  // TODO: arbitrary conversions?
      Val val = eval(args->args[0].get());
      Val res(vm_.allocTmp(type.size()), tid);
      invokeBuiltin(val, [this, &res](auto val_v) {
        invokeBuiltin(
            res, [this, &val_v, &res](auto res_v) { vm_.write(res.hnd, decltype(res_v)(val_v)); });
      });
      return res;
    } else if (std::holds_alternative<BuiltinFnInfo>(type.info)) {
      return runBuiltinFn(op);
    } else {
      std::vector<Val> params;
      for (auto& arg : args->args) params.emplace_back(eval(arg.get()));
      return runFn(tid, params, INVALID_VAL);  // TODO: memebr call
    }
  }
  case ast::Expr::MEMBER_ACCESS: {
    // Left side must either be a type or an evaluated value.
    if (typeid(*op->left) == typeid(ast::Type)) {
      auto strct = g<ast::Type>(op->left);
      auto access = g<ast::Type>(op->right);
      // In this case we are calling a static member function.
      return Val(INVALID_HND, s_.findStructFn(strct->name, access->name));
    }
    auto left = eval(op->left.get());
    // TODO: finish
    break;
  }
  case ast::Expr::ASSIGNMENT: return assign(eval(op->left.get()), eval(op->right.get()));
  case ast::Expr::MUL: return mul(eval(op->left.get()), eval(op->right.get()));
  case ast::Expr::ADD: return add(eval(op->left.get()), eval(op->right.get()));
  case ast::Expr::SUB: return sub(eval(op->left.get()), eval(op->right.get()));
  case ast::Expr::LT: return lt(eval(op->left.get()), eval(op->right.get()));
  case ast::Expr::LOR: return lor(eval(op->left.get()), eval(op->right.get()));
  case ast::Expr::EQ: return eq(eval(op->left.get()), eval(op->right.get()));
  case ast::Expr::NEQ: return neq(eval(op->left.get()), eval(op->right.get()));
  case ast::Expr::ARRAY_ACCESS: return array_access(eval(op->left.get()), eval(op->right.get()));
  case ast::Expr::PREFIX_INC: return preinc(eval(op->left.get()));
  case ast::Expr::POSTFIX_INC: return postinc(eval(op->left.get()));
  case ast::Expr::UNARY_ADDR: return addr(eval(op->left.get()));
  case ast::Expr::UNARY_DEREF: return deref(eval(op->left.get()));
  default: error("unhandled op");
  }
  return INVALID_VAL;
}

Val Exec::runFor(ast::For* fr) {
  runVarDefn(fr->var_defn.get());
  while (true) {
    auto cond_val = eval(fr->cond.get());
    if (cond_val.type != s_.bool_t) error("for condition not boolean");
    if (!vm_.ref<bool>(cond_val.hnd)) break;
    CHECK(runStmtBlk(fr->blk.get()));
    eval(fr->update.get());
  }
  return INVALID_VAL;
}

Val Exec::runWhile(ast::While* wh) {
  while (true) {
    auto cond_val = eval(wh->cond.get());
    if (cond_val.type != s_.bool_t) error("while condition not boolean");
    if (!vm_.ref<bool>(cond_val.hnd)) break;
    CHECK(runStmtBlk(wh->blk.get()));
  }
  return INVALID_VAL;
}

Val Exec::runIf(ast::If* ifst) {
  auto cond_val = eval(ifst->cond.get());
  if (cond_val.type != s_.bool_t) error("if condition not boolean");
  if (vm_.ref<bool>(cond_val.hnd)) CHECK(runStmtBlk(ifst->then.get()));
  else if (ifst->els)
    CHECK(runStmtBlk(ifst->els.get()));
  return INVALID_VAL;
}

Val Exec::eval(ast::Node* n) {
  setContext(n);

  if (typeid(*n) == typeid(ast::Op)) return runOp(g<ast::Op>(n));
  if (typeid(*n) == typeid(ast::VarRef)) return s_.findVar(g<ast::VarRef>(n)->name);
  if (typeid(*n) == typeid(ast::IntLit)) {
    TypeId type = g<ast::IntLit>(n)->unsign ? s_.u32_t : s_.i32_t;
    auto val = Val(vm_.allocTmp(s_.t(type).size()), type);
    vm_.write(val.hnd, uint32_t(g<ast::IntLit>(n)->val));
    return val;
  }
  if (typeid(*n) == typeid(ast::CompoundLit)) {
    // TODO: fix this.
    return INVALID_VAL;
  }
  if (typeid(*n) == typeid(ast::Type)) return Val(INVALID_HND, s_.typeFromAst(g<ast::Type>(n)));
  error("unimplemented eval node " + n->str());
}

Val Exec::valFromAstType(ast::Type* ast_type) {
  auto type = s_.typeFromAst(ast_type);
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
  if (r.type == INVALID_TYPEID) {
    // TODO: For now, treat assignment from typeless value as memset to 0.
    vm_.memset(l, 0, s_.t(l.type).size());
    return l;
  }
  if (l.type != r.type)
    error("assignment to value of different type, " + s_.t(l.type).str() + " = " +
        s_.t(r.type).str().c_str());
  return copy(l, r);  // Deep copy.
}

Val Exec::mul(Val l, Val r) {
  return binop(l, r, l.type, "mul", [](auto a, auto b) { return a * b; });
}

Val Exec::add(Val l, Val r) {
  return binop(l, r, l.type, "add", [](auto a, auto b) { return a + b; });
}

Val Exec::sub(Val l, Val r) {
  return binop(l, r, l.type, "sub", [](auto a, auto b) { return a - b; });
}

Val Exec::lt(Val l, Val r) {
  return binop(l, r, s_.bool_t, "lt", [](auto a, auto b) { return a < b; });
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
  if (l.type == INVALID_TYPEID || l.hnd == INVALID_HND || r.type == INVALID_TYPEID ||
      r.hnd == INVALID_HND)
    error("attempt operate on value with undeducible type");

  if (auto fnid = s_.findImplFn(l.type, {addr(r)}, "Indexable", "index"); fnid != INVALID_TYPEID)
    return deref(runFn(fnid, {addr(r)}, l));

  if (r.type != s_.u32_t && r.type != s_.i32_t) error("array access index must be i32 or u32");
  if (!s_.t(l.type).isArray()) error("array access on non-array type");
  Type new_type = s_.t(l.type);
  new_type.quals.pop_back();  // Remove array qualifier.
  const Hnd new_hnd = l.hnd + vm_.ref<int32_t>(r.hnd) * new_type.size();
  return Val{new_hnd, s_.addType(new_type)};
}

Val Exec::preinc(Val l) {
  if (l.type == INVALID_TYPEID || l.hnd == INVALID_HND)
    error("attempt operate on value with undeducible type");

  return unop(l, "preinc", [this, &l](auto v) {
    vm_.write(l.hnd, v + 1);
    return l;
  });
}

Val Exec::postinc(Val l) {
  if (l.type == INVALID_TYPEID || l.hnd == INVALID_HND)
    error("attempt operate on value with undeducible type");

  return unop(l, "postinc", [this, &l](auto v) {
    Val tmp(vm_.allocTmp(s_.t(l.type).size()), l.type);
    copy(tmp, l);
    vm_.write(l.hnd, v + 1);
    return tmp;
  });
}

Val Exec::addr(Val l) {
  if (l.type == INVALID_TYPEID || l.hnd == INVALID_HND)
    error("attempt operate on value with undeducible type");

  auto new_type = s_.t(l.type);
  new_type.quals.emplace_back();
  new_type.quals.back().ptr = true;
  auto new_value = Val(vm_.allocTmp(sizeof(Hnd)), s_.addType(new_type));
  vm_.write(new_value.hnd, l.hnd);
  return new_value;
}

Val Exec::copy(Val dst, Val src) {
  if (dst.type == INVALID_TYPEID || dst.hnd == INVALID_HND || src.type == INVALID_TYPEID ||
      src.hnd == INVALID_HND)
    error("attempt operate on value with undeducible type");

  vm_.memcpy(dst, src, s_.t(src.type).size());
  return dst;
}

Val Exec::deref(Val l) {
  if (l.type == INVALID_TYPEID || l.hnd == INVALID_HND)
    error("attempt operate on value with undeducible type");

  Type new_type = s_.t(l.type);
  if (!new_type.isPtr()) error("attempt to dereference non-pointer type");
  new_type.quals.pop_back();  // Remove ptr.
  return Val(vm_.ref<Hnd>(l.hnd), s_.addType(new_type));
}

}  // namespace memelang::exec
