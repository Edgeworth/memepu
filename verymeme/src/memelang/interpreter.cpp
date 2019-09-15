#include "memelang/interpreter.h"

#include <memory>

#include "verymeme/util.h"

namespace memelang {

namespace {

template <typename T, typename R>
T* g(R* n) {
  verify_expr(typeid(*n) == typeid(T), "BUG");
  return reinterpret_cast<T*>(n);
}

template <typename T, typename R>
T* g(std::unique_ptr<R>& n) {
  return g<T>(n.get());
}

}  // namespace

Interpreter::Interpreter(memelang::File* file, const memelang::FileContents* cts)
    : f_(file), cts_(cts) {}

void Interpreter::run() {
  printf("===BEGIN PROGRAM===");
  for (auto& fn : f_->fns) {
    // TODO: typelist / fn selection
    fns_[fn->sig->tname->name] = fn.get();
  }
  verify_expr(fns_.count("main"), "no main function");
  runFn(fns_["main"]);
}

void Interpreter::runFn(Fn* fn) {
  printf("In fn %s\n", fn->sig->tname->name.c_str());

  for (auto& stmt : fn->blk->stmts) { runStmt(stmt.get()); }
}

void Interpreter::runStmt(Node* stmt) {
  printf("In statement: %s\n", typeid(*stmt).name());
  if (typeid(*stmt) == typeid(VarDefn)) {
    runVar(g<VarDefn>(stmt));
  } else if (typeid(*stmt) == typeid(Op)) {
    runOp(g<Op>(stmt));
  } else if (typeid(*stmt) == typeid(For)) {
    runFor(g<For>(stmt));
  } else {
    error("unimplemented statement " + stmt->toString());
  }
}
void Interpreter::runVar(VarDefn* var) {
  const auto& name = var->decl->ref->name;
  printf("In var: %s\n", var->decl->ref->name.c_str());
  if (vars_.count(name)) error(var, "redeclaration of var " + name);
  vars_[name] = std::make_shared<Value>(Value{g<IntLit>(var->defn)->val, g<Type>(var->decl->type)});
}

std::shared_ptr<Interpreter::Value> Interpreter::runOp(Op* op) {
  switch (op->type) {
  case Expr::FN_CALL: {
    auto* call = g<VarRef>(op->left);
    auto* args = g<FnCallArgs>(op->right);
    if (call->name == "printf") {
      if (args->args.empty()) error(op, "printf requires at least 1 argument");
      boost::format fmt = boost::format(g<StrLit>(args->args[0])->val);
      // TODO(progress): Support other than int vars.
      for (int i = 1; i < int(args->args.size()); ++i)
        fmt = fmt % eval(args->args[i].get())->int_val;
      printf("%s", fmt.str().c_str());
    }
    // TODO: Return proper value.
    return std::make_shared<Value>();
  }
  case Expr::ASSIGNMENT: return eval(op->left.get())->assign(eval(op->right.get()).get());
  case Expr::ADD: return eval(op->left.get())->add(eval(op->right.get()).get());
  default: verify_expr(false, "unhandled op: %s", op->toString().c_str());
  }
}

void Interpreter::error(Node* n, const std::string& msg) const {
  verify_expr(false, "error at '%s' (%d:%d): %s", cts_->getSpan(n->tok.loc, n->tok.size).c_str(),
      cts_->getLineNumber(n->tok.loc), cts_->getColNumber(n->tok.loc), msg.c_str());
}

std::shared_ptr<Interpreter::Value> Interpreter::getVar(Node* ref) const {
  auto* var = g<VarRef>(ref);
  auto iter = vars_.find(var->name);
  if (iter == vars_.end()) error(ref, "undeclared variable " + var->name);
  return iter->second;
}

std::shared_ptr<Interpreter::Value> Interpreter::eval(Node* n) {
  if (typeid(*n) == typeid(Op)) return runOp(g<Op>(n));
  if (typeid(*n) == typeid(VarRef)) return getVar(n);
  // TODO use type
  if (typeid(*n) == typeid(IntLit))
    return std::make_shared<Value>(Value{g<IntLit>(n)->val, nullptr});
  error(n, "unimplemented eval node " + n->toString());
}

void Interpreter::runFor(For* fr) {}

std::shared_ptr<Interpreter::Value> Interpreter::Value::assign(Interpreter::Value* val) {
  // TODO support other vals.
  int_val = val->int_val;
  return std::make_shared<Value>(*this);
}

std::shared_ptr<Interpreter::Value> Interpreter::Value::add(Interpreter::Value* val) {
  // TODO support other vals.
  return std::make_shared<Value>(Value{int_val + val->int_val, type});
}

}  // namespace memelang
