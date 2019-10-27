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
    if (val.hnd != INVALID_HND) { \
      s_.unnestScope(); \
      return val; \
    } \
  } while (0)

// TODO: Handle const stuff?
Exec::Exec(ast::File* file, const FileContents* cts) : f_(file), cts_(cts), s_(this), vm_(this) {}

void Exec::run() {
  fprintf(stderr, "===BEGIN PROGRAM===\n");
  auto fn = s_.findFn("main");
  s_.pushScope(fn);
  runFn(fn, {}, {}, {});
  s_.popScope();
  fprintf(stderr, "===END PROGRAM===\n");
}

Val Exec::runFn(ast::Fn* fn, const Mapping& mapping, const std::vector<Val>& params, Val ths) {
  s_.pushScope(fn);
  s_.pushTypeMapping(mapping);

  setContext(fn);  // Set context after pushing scope to save caller location.
  if (fn->sig->params.size() != params.size()) error("wrong number of arguments");
  if (ths.hnd != INVALID_HND) s_.declareVar("this", addr(ths));
  for (int i = 0; i < int(fn->sig->params.size()); ++i) {
    auto& decl = fn->sig->params[i];
    runStmt(decl.get());
    fprintf(stderr, "first type: %s, second: %s\n",
        s_.findVar(decl->ref->name).type->toString().c_str(), params[i].type->toString().c_str());
    assign(s_.findVar(decl->ref->name), params[i]);
  }
  auto val = runStmtBlk(fn->blk.get());
  s_.popTypeMapping(mapping);
  s_.popScope();
  return val;
}

Val Exec::runStmtBlk(ast::StmtBlk* blk) {
  s_.nestScope();
  for (auto& stmt : blk->stmts) CHECK(runStmt(stmt.get()));
  s_.unnestScope();
  return {};
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
    error("unimplemented statement " + stmt->toString());
  }
  return {};
}

void Exec::runVarDefn(ast::VarDefn* defn) {
  bug_unless(defn->defn);
  if (defn->decl->type) {
    assign(runVarDecl(defn->decl.get()), eval(defn->defn.get()));
  } else {
    // If no type specifier, just use the definition directly.
    s_.declareVar(defn->decl->ref->name, eval(defn->defn.get()));
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

    // Type constructor / conversion
    if (typeid(*op->left) == typeid(ast::Type)) {
      auto* type = s_.typeFromAst(g<ast::Type>(op->left));
      if (args->args.size() != 1)
        error("conversion must have 1 arg");  // TODO: arbitrary conversions?
      Val val = eval(args->args[0].get());
      Val res{.hnd = vm_.allocTmp(type->size()), .type = type};
      invokeBuiltin(val, [this, &res](auto val_v) {
        invokeBuiltin(
            res, [this, &val_v, &res](auto res_v) { vm_.write(res, decltype(res_v)(val_v)); });
      });
      return res;
    }

    if (typeid(*op->left) != typeid(ast::VarRef)) error("invalid attempt at function call");

    // Otherwise, it's a var ref.
    auto* call = g<ast::VarRef>(op->left);

    if (call->name == "printf") {
      if (args->args.empty()) error("printf requires at least 1 argument");
      boost::format fmt = boost::format(g<ast::StrLit>(args->args[0])->val);
      // TODO(progress): Support other than int vars.
      for (int i = 1; i < int(args->args.size()); ++i)
        invokeBuiltin(eval(args->args[i].get()), [&fmt](auto& a) { fmt = fmt % a; });
      printf("%s", fmt.str().c_str());

      // TODO: Return proper value.
      return {};
    } else if (call->name == "readf") {
      if (args->args.size() != 2) error("readf requires 2 arguments");
      auto read_ptr = eval(args->args[0].get());
      auto read_sz = eval(args->args[1].get());

      auto u8_ptr_t =
          Type{.name = U8, .quals = {{}, {.ptr = true}}};  // TODO: move ptr type get to Type?
      if (*read_ptr.type != u8_ptr_t)
        error("wrong type: " + read_ptr.type->toString() + " need: " + u8_ptr_t.toString());
      if (read_sz.type != s_.u32_t) error("wrong type: " + read_sz.type->toString());
      std::cin.getline(&vm_.ref<char>(deref(read_ptr)), vm_.ref<int32_t>(read_sz));

      auto ret = Val{.hnd = vm_.allocTmp(s_.u32_t->size()), .type = s_.u32_t};
      vm_.write(ret, uint32_t(std::cin.gcount()));
      return ret;
    } else if (call->name == "sizeof") {
      if (args->args.size() != 1) error("sizeof requires 1 argument");
      auto val = eval(args->args[0].get());
      auto ret = Val{.hnd = vm_.allocTmp(s_.u32_t->size()), .type = s_.u32_t};
      vm_.write(ret, uint32_t(val.type->size()));
      return ret;
    }

    std::vector<Val> params;
    for (auto& arg : args->args) params.emplace_back(eval(arg.get()));
    auto* fn = s_.findFn(call->name);
    return runFn(fn, {} /* mapping */, params, {} /* this */);
  }
  case ast::Expr::ASSIGNMENT: return assign(eval(op->left.get()), eval(op->right.get()));
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
  return {};
}

Val Exec::runFor(ast::For* fr) {
  runVarDefn(fr->var_defn.get());
  while (true) {
    auto cond_val = eval(fr->cond.get());
    if (cond_val.type != s_.bool_t) error("for condition not boolean");
    if (!vm_.ref<bool>(cond_val)) break;
    CHECK(runStmtBlk(fr->blk.get()));
    eval(fr->update.get());
  }
  return {};
}

Val Exec::runWhile(ast::While* wh) {
  while (true) {
    auto cond_val = eval(wh->cond.get());
    if (cond_val.type != s_.bool_t) error("while condition not boolean");
    if (!vm_.ref<bool>(cond_val)) break;
    CHECK(runStmtBlk(wh->blk.get()));
  }
  return {};
}

Val Exec::runIf(ast::If* ifst) {
  auto cond_val = eval(ifst->cond.get());
  if (cond_val.type != s_.bool_t) error("if condition not boolean");
  if (vm_.ref<bool>(cond_val)) CHECK(runStmtBlk(ifst->then.get()));
  else if (ifst->els)
    CHECK(runStmtBlk(ifst->els.get()));
  return {};
}

Val Exec::eval(ast::Node* n) {
  setContext(n);

  if (typeid(*n) == typeid(ast::Op)) return runOp(g<ast::Op>(n));
  if (typeid(*n) == typeid(ast::VarRef)) return s_.findVar(g<ast::VarRef>(n)->name);
  if (typeid(*n) == typeid(ast::IntLit)) {
    const auto* type = g<ast::IntLit>(n)->unsign ? s_.u32_t : s_.i32_t;
    auto val = Val{.hnd = vm_.allocTmp(type->size()), .type = type};
    vm_.write(val, uint32_t(g<ast::IntLit>(n)->val));
    return val;
  }
  if (typeid(*n) == typeid(ast::CompoundLit)) {
    auto* lit = g<ast::CompoundLit>(n);
    // TODO set value
    return {};  // nullptr for deduced type
  }
  error("unimplemented eval node " + n->toString());
  return {};
}

Val Exec::valFromAstType(ast::Type* ast_type) {
  auto type = s_.typeFromAst(ast_type);
  Val val = Val{.hnd = vm_.allocStack(type->size()), .type = type};
  vm_.memset(val, 0, type->size());
  return val;
}

void Exec::error(const std::string& msg) const {
  if (node_ctx_)
    verify_expr(false, "error at '%s' (%s): %s\n%s\n",
        cts_->span(node_ctx_->tok.loc, node_ctx_->tok.size).c_str(),
        cts_->fpos(node_ctx_->tok.loc).c_str(), msg.c_str(), s_.stacktrace().c_str());
  else
    verify_expr(false, "error: %s\n%s\n", msg.c_str(), s_.stacktrace().c_str());
}

Val Exec::assign(Val l, Val r) {
  if (!r.type) {
    // TODO: For now, treat assignment from typeless value as memset to 0.
    vm_.memset(l, 0, l.type->size());
    return l;
  }
  if (l.type != r.type) error("assignment to value of different type");
  return copy(l, r);  // Deep copy.
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
  if (!l.type || l.hnd == INVALID_HND || !r.type || r.hnd == INVALID_HND)
    error("attempt operate on value with undeducible type");

  // TODO not only u32 ?
  if (r.type != s_.u32_t && r.type != s_.i32_t) error("array access index must be i32 or u32");
  if (!l.type->isArray()) error("array access on non-array type");
  Type new_type = *l.type;
  new_type.quals.pop_back();  // Remove array qualifier.
  const int32_t idx = vm_.ref<int32_t>(r);
  return Val{l.hnd + idx * l.type->size(), s_.addType(std::move(new_type))};
}

Val Exec::preinc(Val l) {
  if (!l.type || l.hnd == INVALID_HND) error("attempt operate on value with undeducible type");

  return unop(l, l.type, "preinc", [this, &l](auto v) {
    vm_.write(l, v + 1);
    return l;
  });
}

Val Exec::postinc(Val l) {
  if (!l.type || l.hnd == INVALID_HND) error("attempt operate on value with undeducible type");

  return unop(l, l.type, "postinc", [this, &l](auto v) {
    Val tmp = {.hnd = vm_.allocTmp(l.type->size()), .type = l.type};
    copy(tmp, l);
    vm_.write(l, v + 1);
    return tmp;
  });
}

Val Exec::addr(const Val& l) {
  if (!l.type || l.hnd == INVALID_HND) error("attempt operate on value with undeducible type");

  auto new_type = *l.type;
  new_type.quals.emplace_back();
  new_type.quals.back().ptr = true;
  auto new_value = Val{.hnd = vm_.allocTmp(sizeof(Hnd)), .type = s_.addType(std::move(new_type))};
  vm_.write(new_value, l.hnd);
  return new_value;
}

Val Exec::copy(Val dst, Val src) {
  if (!dst.type || dst.hnd == INVALID_HND || !src.type || src.hnd == INVALID_HND)
    error("attempt operate on value with undeducible type");

  vm_.memcpy(dst, src, src.type->size());
  return dst;
}

Val Exec::deref(const Val& l) {
  if (!l.type || l.hnd == INVALID_HND) error("attempt operate on value with undeducible type");
  if (!l.type->quals.back().ptr) error("attempt to dereference non-pointer type");

  Type new_type = *l.type;
  new_type.quals.pop_back();  // Remove ptr.
  return {.hnd = vm_.ref<Hnd>(l), .type = s_.addType(std::move(new_type))};
}

}  // namespace memelang::exec
