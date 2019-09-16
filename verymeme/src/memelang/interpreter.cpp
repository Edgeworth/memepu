#include "memelang/interpreter.h"

#include <memory>

#include "verymeme/util.h"

namespace memelang {

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

#define CHECK(expr) \
  do { \
    auto val = (expr); \
    if (val) { \
      unnestScope(); \
      return val; \
    } \
  } while (0)

Interpreter::Interpreter(memelang::File* file, const memelang::FileContents* cts)
    : f_(file), cts_(cts) {}

void Interpreter::run() {
  printf("===BEGIN PROGRAM===\n");
  for (auto& fn : f_->fns) {
    // TODO: typelist / fn selection
    fns_[fn->sig->tname->name] = fn.get();
  }
  pushScope();
  runFn(getFn(nullptr, "main"));
  popScope();
}

std::shared_ptr<Interpreter::Value> Interpreter::runFn(Fn* fn) { return runStmtBlk(fn->blk.get()); }

std::shared_ptr<Interpreter::Value> Interpreter::runStmtBlk(StmtBlk* blk) {
  nestScope();
  for (auto& stmt : blk->stmts) CHECK(runStmt(stmt.get()));
  unnestScope();
  return nullptr;
}

std::shared_ptr<Interpreter::Value> Interpreter::runStmt(Node* stmt) {
  if (typeid(*stmt) == typeid(VarDefn)) {
    runVarDefn(g<VarDefn>(stmt));
  } else if (typeid(*stmt) == typeid(VarDecl)) {
    return runVarDecl(g<VarDecl>(stmt));
  } else if (typeid(*stmt) == typeid(Op)) {
    return runOp(g<Op>(stmt));
  } else if (typeid(*stmt) == typeid(For)) {
    return runFor(g<For>(stmt));
  } else if (typeid(*stmt) == typeid(Return)) {
    return eval(g<Return>(stmt)->ret.get());
  } else if (typeid(*stmt) == typeid(If)) {
    return runIf(g<If>(stmt));
  } else {
    error(stmt, "unimplemented statement " + stmt->toString());
  }
  return nullptr;
}

void Interpreter::runVarDefn(VarDefn* defn) {
  auto var = runVarDecl(defn->decl.get());
  // TODO check type
  if (defn->defn)
    var->assign(eval(defn->defn.get()).get());
}

std::shared_ptr<Interpreter::Value> Interpreter::runVarDecl(VarDecl* decl) {
  const auto& name = decl->ref->name;
  if (maybeGetVar(name)) error(decl, "redeclaration of var " + name);
  vars_.back().back()[name] = std::make_shared<Value>(Value{{}, decl->type.get()});
  return vars_.back().back()[name];
}

std::shared_ptr<Interpreter::Value> Interpreter::runOp(Op* op) {
  switch (op->type) {
  case Expr::FN_CALL: {
    if (typeid(*(op->left.get())) != typeid(VarRef)) return std::make_shared<Value>();  // TODO don't skip types
    auto* call = g<VarRef>(op->left);  // TODO can be type.
    auto* args = g<FnCallArgs>(op->right);
    if (call->name == "printf") {
      if (args->args.empty()) error(op, "printf requires at least 1 argument");
      boost::format fmt = boost::format(g<StrLit>(args->args[0])->val);
      // TODO(progress): Support other than int vars.
      for (int i = 1; i < int(args->args.size()); ++i)
        fmt = fmt % eval(args->args[i].get())->int_val;
      printf("%s", fmt.str().c_str());

      // TODO: Return proper value.
      return nullptr;
    }

    std::vector<std::shared_ptr<Value>> params;
    for (auto& arg : args->args) params.emplace_back(eval(arg.get()));
    pushScope();
    auto* fn = getFn(call, call->name);
    if (fn->sig->params.size() != params.size()) error(op, "wrong number of arguments");
    for (int i = 0; i < int(fn->sig->params.size()); ++i) {
      auto* decl = fn->sig->params[i].get();
      runStmt(decl);
      getVar(decl->ref.get(), decl->ref->name)->assign(params[i].get());
    }
    auto val = runFn(fn);
    popScope();
    return val;
  }
  case Expr::ASSIGNMENT: return eval(op->left.get())->assign(eval(op->right.get()).get());
  case Expr::ADD: return eval(op->left.get())->add(eval(op->right.get()).get());
  case Expr::SUB: return eval(op->left.get())->sub(eval(op->right.get()).get());
  case Expr::LT: return eval(op->left.get())->lt(eval(op->right.get()).get());
  case Expr::PREFIX_INC: return eval(op->left.get())->preinc();
  case Expr::EQ: return eval(op->left.get())->eq(eval(op->right.get()).get());
  default: verify_expr(false, "unhandled op: %s", op->toString().c_str());
  }
}

std::shared_ptr<Interpreter::Value> Interpreter::runFor(For* fr) {
  runVarDefn(fr->var_defn.get());
  while (eval(fr->cond.get())->int_val) {
    CHECK(runStmtBlk(fr->blk.get()));
    eval(fr->update.get());
  }
  return nullptr;
}

std::shared_ptr<Interpreter::Value> Interpreter::runIf(If* ifst) {
  if (eval(ifst->cond.get())->int_val) CHECK(runStmtBlk(ifst->then.get()));
  else if (ifst->els)
    CHECK(runStmtBlk(ifst->els.get()));
  return nullptr;
}

std::shared_ptr<Interpreter::Value> Interpreter::eval(Node* n) {
  if (typeid(*n) == typeid(Op)) return runOp(g<Op>(n));
  if (typeid(*n) == typeid(VarRef)) return getVar(n, g<VarRef>(n)->name);
  // TODO use type
  if (typeid(*n) == typeid(IntLit))
    return std::make_shared<Value>(Value{g<IntLit>(n)->val, nullptr});
  error(n, "unimplemented eval node " + n->toString());
  return nullptr;
}

void Interpreter::pushScope() {
  vars_.emplace_back();
  nestScope();
}

void Interpreter::popScope() {
  bug_unless(!vars_.empty());
  vars_.pop_back();
}

void Interpreter::nestScope() { vars_.back().emplace_back(); }

void Interpreter::unnestScope() {
  bug_unless(!vars_.back().empty());
  vars_.back().pop_back();
}

Fn* Interpreter::getFn(Node* n, const std::string& name) {
  if (!fns_.count(name)) error(n, "no function " + name);
  return fns_[name];
}

std::shared_ptr<Interpreter::Value> Interpreter::getVar(Node* n, const std::string& name) const {
  auto val = maybeGetVar(name);
  if (!val) error(n, "undeclared variable " + name);
  return val;
}

std::shared_ptr<Interpreter::Value> Interpreter::maybeGetVar(const std::string& name) const {
  bug_unless(!vars_.empty());
  for (auto scope_iter = vars_.back().rbegin(); scope_iter != vars_.back().rend(); ++scope_iter) {
    auto iter = scope_iter->find(name);
    if (iter != scope_iter->end()) return iter->second;
  }
  return nullptr;
}

void Interpreter::error(Node* n, const std::string& msg) const {
  if (n)
    verify_expr(false, "error at '%s' (%d:%d): %s", cts_->getSpan(n->tok.loc, n->tok.size).c_str(),
        cts_->getLineNumber(n->tok.loc), cts_->getColNumber(n->tok.loc), msg.c_str());
  else
    verify_expr(false, "error: %s", msg.c_str());
}

std::shared_ptr<Interpreter::Value> Interpreter::Value::assign(Interpreter::Value* val) {
  // TODO support other vals.
  int_val = val->int_val;
  return std::make_shared<Value>(*this);
}

std::shared_ptr<Interpreter::Value> Interpreter::Value::add(Interpreter::Value* val) {
  // TODO support other vals.
  return std::make_shared<Value>(Value{int_val + val->int_val, type});
}

std::shared_ptr<Interpreter::Value> Interpreter::Value::sub(Interpreter::Value* val) {
  // TODO support other vals.
  return std::make_shared<Value>(Value{int_val - val->int_val, type});
}

std::shared_ptr<Interpreter::Value> Interpreter::Value::lt(Interpreter::Value* val) {
  // TODO support other vals.
  return std::make_shared<Value>(Value{int_val < val->int_val, nullptr});
}

std::shared_ptr<Interpreter::Value> Interpreter::Value::eq(Interpreter::Value* val) {
  // TODO support other vals.
  return std::make_shared<Value>(Value{int_val == val->int_val, nullptr});
}

std::shared_ptr<Interpreter::Value> Interpreter::Value::preinc() {
  // TODO support other vals.
  int_val++;
  return std::make_shared<Value>(*this);
}

}  // namespace memelang
