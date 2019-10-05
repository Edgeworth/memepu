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
      scope_.unnestScope(); \
      return val; \
    } \
  } while (0)

// TODO: Handle const stuff?
Exec::Exec(ast::File* file, const FileContents* cts)
    : f_(file), cts_(cts), scope_(this), vm_(this), bool_(addType({.name = BOOL, .quals = {{}}})),
      i8_(addType({.name = I8, .quals = {{}}})), i16_(addType({.name = I16, .quals = {{}}})),
      i32_(addType({.name = I32, .quals = {{}}})), i64_(addType({.name = I64, .quals = {{}}})),
      u8_(addType({.name = U8, .quals = {{}}})), u16_(addType({.name = U16, .quals = {{}}})),
      u32_(addType({.name = U32, .quals = {{}}})), u64_(addType({.name = U64, .quals = {{}}})),
      f32_(addType({.name = F32, .quals = {{}}})), f64_(addType({.name = F64, .quals = {{}}})) {}

void Exec::run() {
  printf("===BEGIN PROGRAM===\n");
  for (auto& fn : f_->fns) {
    setContext(fn.get());
    // TODO: typelist / fn selection
    fns_[typenameFromAst(fn->sig->tname.get())] = fn.get();
  }
  // TODO: Run all these intfs and structs.
  for (auto& enm : f_->enums) {
    setContext(enm.get());
    if (!enums_.emplace(typenameFromAst(enm->tname.get()), enm.get()).second)
      error("duplicate enum definition");
  }
  for (auto& intf : f_->intfs) {
    setContext(intf.get());
    if (!intfs_.emplace(typenameFromAst(intf->tname.get()), intf.get()).second)
      error("duplicate interface definition");
  }
  for (auto& strct : f_->structs) {
    setContext(strct.get());
    if (!structs_.emplace(typenameFromAst(strct->tname.get()), strct.get()).second)
      error("duplicate struct definition");
  }
  for (auto& impl : f_->impls) {
    setContext(impl.get());
    auto impl_type = typeFromAst(impl->type.get());
    if (!impls_[impl_type].emplace(typeFromAst(impl->tintf.get()), impl.get()).second)
      error("duplicate implementation for (type, interface specialisation) pair");
  }

  scope_.pushScope();
  runFn(getFn(Typename{.name = "main"}, nullptr), {});
  scope_.popScope();
  printf("===END PROGRAM===\n");
}

Val Exec::runFn(ast::Fn* fn, const std::vector<Val>& params) {
  setContext(fn);

  scope_.pushScope();
  if (fn->sig->params.size() != params.size()) error("wrong number of arguments");
  for (int i = 0; i < int(fn->sig->params.size()); ++i) {
    auto& decl = fn->sig->params[i];
    runStmt(decl.get());
    assign(scope_.getVar(decl->ref->name), params[i]);
  }
  auto val = runStmtBlk(fn->blk.get());
  scope_.popScope();
  return val;
}

Val Exec::runStmtBlk(ast::StmtBlk* blk) {
  scope_.nestScope();
  for (auto& stmt : blk->stmts) CHECK(runStmt(stmt.get()));
  scope_.unnestScope();
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
  } else if (typeid(*stmt) == typeid(ast::Return)) {
    return eval(g<ast::Return>(stmt)->ret.get());
  } else if (typeid(*stmt) == typeid(ast::If)) {
    return runIf(g<ast::If>(stmt));
  } else {
    error("unimplemented statement " + stmt->toString());
  }
  return {};
}

void Exec::runVarDefn(ast::VarDefn* defn) {
  auto var = runVarDecl(defn->decl.get());
  if (defn->defn) assign(var, eval(defn->defn.get()));
}

Val Exec::runVarDecl(ast::VarDecl* decl) {
  return scope_.declareVar(decl->ref->name, valFromAstType(decl->type.get()));
}

Val Exec::runOp(ast::Op* op) {
  setContext(op);

  switch (op->type) {
  case ast::Expr::FN_CALL: {
    if (typeid(*(op->left.get())) != typeid(ast::VarRef)) return {};  // TODO don't skip types
    auto* call = g<ast::VarRef>(op->left);  // TODO can be type.
    auto* args = g<ast::FnCallArgs>(op->right);
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
      if (*read_ptr.type != Type{.name = U8, .quals = {{}, {.ptr = true}}})
        error("wrong type: " + read_ptr.type->toString());
      if (read_sz.type != i32_)  // TODO: require U32.
        error("wrong type: " + read_sz.type->toString());
      std::cin.getline(&vm_.ref<char>(deref(read_ptr)), vm_.ref<int32_t>(read_sz));

      auto ret = Val{.hnd = vm_.allocStack(i32_->size()), .type = i32_};
      vm_.write(ret, int32_t(std::cin.gcount()));
      return ret;
    }

    std::vector<Val> params;
    for (auto& arg : args->args) params.emplace_back(eval(arg.get()));
    auto* fn = getFn(Typename{.name = call->name}, call);
    return runFn(fn, params);
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
  case ast::Expr::POSTFIX_INC: return preinc(eval(op->left.get()));
  case ast::Expr::UNARY_ADDR: return addr(eval(op->left.get()));
  default: error("unhandled op");
  }
  return {};
}

Val Exec::runFor(ast::For* fr) {
  runVarDefn(fr->var_defn.get());
  while (true) {
    auto cond_val = eval(fr->cond.get());
    if (cond_val.type != bool_) error("for condition not boolean");
    if (!vm_.ref<bool>(cond_val)) break;
    CHECK(runStmtBlk(fr->blk.get()));
    eval(fr->update.get());
  }
  return {};
}

Val Exec::runWhile(ast::While* wh) {
  while (true) {
    auto cond_val = eval(wh->cond.get());
    if (cond_val.type != bool_) error("while condition not boolean");
    if (!vm_.ref<bool>(cond_val)) break;
    CHECK(runStmtBlk(wh->blk.get()));
  }
  return {};
}

Val Exec::runIf(ast::If* ifst) {
  auto cond_val = eval(ifst->cond.get());
  if (cond_val.type != bool_) error("if condition not boolean");
  if (vm_.ref<bool>(cond_val)) CHECK(runStmtBlk(ifst->then.get()));
  else if (ifst->els)
    CHECK(runStmtBlk(ifst->els.get()));
  return {};
}

Val Exec::eval(ast::Node* n) {
  setContext(n);

  if (typeid(*n) == typeid(ast::Op)) return runOp(g<ast::Op>(n));
  if (typeid(*n) == typeid(ast::VarRef)) return scope_.getVar(g<ast::VarRef>(n)->name);
  if (typeid(*n) == typeid(ast::IntLit)) {
    const auto* type = g<ast::IntLit>(n)->unsign ? u32_ : i32_;
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

ast::Fn* Exec::getFn(const Typename& tname, ast::Node* n) {
  setContext(n);
  if (!fns_.count(tname)) error("no function " + tname.name);
  return fns_[tname];
}

const Type* Exec::addType(Type&& t) { return &*types_.insert(std::move(t)).first; }

Val Exec::valFromAstType(ast::Type* ast_type) {
  auto type = typeFromAst(ast_type);
  Val val = Val{.hnd = vm_.allocStack(type->size()), .type = type};
  vm_.memset(val, 0, type->size());
  return val;
}

const Type* Exec::typeFromAst(ast::Type* ast_type) {
  if (ast_type_map_.count(ast_type)) return ast_type_map_[ast_type];

  Type new_type;
  new_type.name = ast_type->name;
  new_type.quals.emplace_back();  // Put one qualifier to hold const for the main type.
  new_type.quals.back().cnst = ast_type->cnst;

  // Look through qualifiers reversed.
  for (auto i = ast_type->quals.rbegin(); i != ast_type->quals.rend(); ++i) {
    new_type.quals.emplace_back();
    // TODO not only int32_t
    if ((*i)->array) {
      auto array_val = eval((*i)->array.get());
      if (array_val.type != i32_) error("array size must be i32");
      new_type.quals.back().array = vm_.ref<int32_t>(array_val);
    }
    new_type.quals.back().ptr = (*i)->ptr;
    new_type.quals.back().cnst = (*i)->cnst;
  }
  for (const auto& param : ast_type->params) new_type.params.emplace_back(typeFromAst(param.get()));

  ast_type_map_[ast_type] = addType(std::move(new_type));
  return ast_type_map_[ast_type];
}

Typename Exec::typenameFromAst(ast::Typename* ast_typename) {
  auto tname = Typename{.name = ast_typename->name};
  if (ast_typename->tlist) tname.tlist = ast_typename->tlist->names;
  return tname;
}

void Exec::setContext(ast::Node* node) { node_ctx_ = node; }

void Exec::error(const std::string& msg) const {
  if (node_ctx_)
    verify_expr(false, "error at '%s' (%d:%d): %s",
        cts_->getSpan(node_ctx_->tok.loc, node_ctx_->tok.size).c_str(),
        cts_->getLineNumber(node_ctx_->tok.loc), cts_->getColNumber(node_ctx_->tok.loc),
        msg.c_str());
  else
    verify_expr(false, "error: %s", msg.c_str());
}

Val Exec::assign(Val l, Val r) {
  return copy(l, r);  // Deep copy.
}

Val Exec::add(Val l, Val r) {
  return binop(l, r, l.type, "add", [](auto a, auto b) { return a + b; });
}

Val Exec::sub(Val l, Val r) {
  return binop(l, r, l.type, "sub", [](auto a, auto b) { return a - b; });
}

Val Exec::lt(Val l, Val r) {
  return binop(l, r, bool_, "lt", [](auto a, auto b) { return a < b; });
}

Val Exec::lor(Val l, Val r) {
  return binop(l, r, bool_, "lor", [](auto a, auto b) { return a || b; });
}

Val Exec::eq(Val l, Val r) {
  return binop(l, r, bool_, "eq", [](auto a, auto b) { return a == b; });
}

Val Exec::neq(Val l, Val r) {
  return binop(l, r, bool_, "neq", [](auto a, auto b) { return a != b; });
}

Val Exec::array_access(Val l, Val r) {
  // TODO not only int32 ?
  if (r.type != i32_) error("array access index must be i32");
  if (!l.type->quals.back().array) error("array access on non-array type");
  Type new_type = *l.type;
  new_type.quals.erase(new_type.quals.begin());  // Remove array qualifier.
  const int32_t idx = vm_.ref<int32_t>(r);
  return Val{l.hnd + idx * l.type->size(), addType(std::move(new_type))};
}

Val Exec::preinc(Val l) {
  return unop(l, l.type, [this, &l](auto v) {
    vm_.write(l, v + 1);
    return l;
  });
}

Val Exec::postinc(Val l) {
  return unop(l, l.type, [this, &l](auto v) {
    Val tmp = {.hnd = vm_.allocTmp(l.type->size()), .type = l.type};
    copy(tmp, l);
    vm_.write(l, v + 1);
    return tmp;
  });
}

Val Exec::addr(const Val& l) {
  auto new_type = *l.type;
  new_type.quals.emplace_back();
  new_type.quals.back().ptr = true;
  auto new_value = Val{.hnd = vm_.allocTmp(sizeof(Hnd)), .type = addType(std::move(new_type))};
  vm_.write(new_value, l.hnd);
  return new_value;
}

Val Exec::copy(Val dst, Val src) {
  vm_.memcpy(dst, src, src.type->size());
  return dst;
}

Val Exec::deref(const Val& l) {
  Val res;
  res.hnd = vm_.ref<Hnd>(l);
  return res;
}

}  // namespace memelang::exec
