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
  runFn(getFn(Typename{.name = "main"}), {}, {});
  scope_.popScope();
  printf("===END PROGRAM===\n");
}

Val Exec::runFn(ast::Fn* fn, const std::vector<Val>& params, Val ths) {
  setContext(fn);

  scope_.pushScope();
  if (fn->sig->params.size() != params.size()) error("wrong number of arguments");
  if (ths.hnd != INVALID_HND) scope_.declareVar("this", addr(ths));
  for (int i = 0; i < int(fn->sig->params.size()); ++i) {
    auto& decl = fn->sig->params[i];
    runStmt(decl.get());
    printf("first type: %s, second: %s\n", scope_.getVar(decl->ref->name).type->toString().c_str(),
        params[i].type->toString().c_str());
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
  // If no type specifier, just use the definition directly.
  if (defn->decl->type->name.empty()) {
    scope_.declareVar(defn->decl->ref->name, eval(defn->defn.get()));
  } else {
    assign(runVarDecl(defn->decl.get()), eval(defn->defn.get()));
  }
}

Val Exec::runVarDecl(ast::VarDecl* decl) {
  return scope_.declareVar(decl->ref->name, valFromAstType(decl->type.get()));
}

Val Exec::runOp(ast::Op* op) {
  setContext(op);

  switch (op->type) {
  case ast::Expr::FN_CALL: {
    auto* args = g<ast::FnCallArgs>(op->right);

    // Type constructor / conversion
    if (typeid(*op->left) == typeid(ast::Type)) {
      auto* type = typeFromAst(g<ast::Type>(op->left));
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
      if (*read_ptr.type != Type{.name = U8, .quals = {{}, {.ptr = true}}})
        error("wrong type: " + read_ptr.type->toString());
      if (read_sz.type != u32_) error("wrong type: " + read_sz.type->toString());
      std::cin.getline(&vm_.ref<char>(deref(read_ptr)), vm_.ref<int32_t>(read_sz));

      auto ret = Val{.hnd = vm_.allocTmp(u32_->size()), .type = u32_};
      vm_.write(ret, uint32_t(std::cin.gcount()));
      return ret;
    } else if (call->name == "sizeof") {
      if (args->args.size() != 1) error("sizeof requires 1 argument");
      auto val = eval(args->args[0].get());
      auto ret = Val{.hnd = vm_.allocTmp(u32_->size()), .type = u32_};
      vm_.write(ret, uint32_t(val.type->size()));
      return ret;
    }

    std::vector<Val> params;
    for (auto& arg : args->args) params.emplace_back(eval(arg.get()));
    auto* fn = getFn(Typename{.name = call->name});
    return runFn(fn, params, {});
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

ast::Fn* Exec::getFn(const Typename& tname) {
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

// TODO: need to consider type wildcards
const Type* Exec::typeFromAst(ast::Type* ast_type) {
  if (ast_type_map_.count(ast_type)) return ast_type_map_[ast_type];

  Type new_type;
  new_type.name = ast_type->name;
  new_type.quals.emplace_back();  // Put one qualifier to hold const for the main type.
  new_type.quals.back().cnst = ast_type->cnst;

  // Look through qualifiers reversed.
  for (auto i = ast_type->quals.rbegin(); i != ast_type->quals.rend(); ++i) {
    new_type.quals.emplace_back();
    // TODO not only u32_t?
    if ((*i)->array) {
      auto array_val = eval((*i)->array.get());
      if (array_val.type != u32_) error("array size must be u32");
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
  // TODO not only u32 ?
  if (r.type != u32_ && r.type != i32_) error("array access index must be i32 or u32");
  if (!l.type->quals.back().array) error("array access on non-array type");
  Type new_type = *l.type;
  new_type.quals.pop_back();  // Remove array qualifier.
  const int32_t idx = vm_.ref<int32_t>(r);
  return Val{l.hnd + idx * l.type->size(), addType(std::move(new_type))};
}

Val Exec::preinc(Val l) {
  return unop(l, l.type, "preinc", [this, &l](auto v) {
    vm_.write(l, v + 1);
    return l;
  });
}

Val Exec::postinc(Val l) {
  return unop(l, l.type, "postinc", [this, &l](auto v) {
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
  Type new_type = *l.type;
  new_type.quals.pop_back();  // Remove ptr.
  Val res{.hnd = vm_.ref<Hnd>(l), .type = addType(std::move(new_type))};
  return res;
}

ast::Fn* Exec::lookupImplFn(Val obj, const std::string& impl_name, const std::string& fn_name) {
  printf("lookup: %s %s\n", impl_name.c_str(), fn_name.c_str());
  std::pair<int, int> best_dist{-1, -1};
  ast::Fn* best_fn = nullptr;
  for (const auto& [obj_type, impl_map] : impls_) {
    const int object_dist = obj.type->dist(*obj_type);
    if (object_dist == Type::NOT_SUBTYPE ||
        (best_dist.first != -1 && best_dist.first < object_dist))
      continue;

    for (const auto& [intf_type, impl] : impl_map) {
      // TODO: Need to decide which interface to use based on function arguments or something.
      if (intf_type->name == impl_name) {
        for (const auto& fn : impl->fns) {
          printf("check fn name: %s\n", fn->sig->tname->name.c_str());
          if (fn->sig->tname->name == fn_name) {
            best_fn = fn.get();
            best_dist.first = object_dist;
          }
        }
      }
    }
  }

  return best_fn;
}

}  // namespace memelang::exec
