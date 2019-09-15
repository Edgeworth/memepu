#include "memelang/interpreter.h"

#include "verymeme/util.h"

namespace memelang {

namespace {

template <typename T>
T* g(Node* n) {
  verify_expr(typeid(*n) == typeid(T), "BUG");
  return reinterpret_cast<T*>(n);
}

template <typename T>
T* g(std::unique_ptr<Node>& n) {
  return g<T>(n.get());
}

}  // namespace

Interpreter::Interpreter(memelang::File* file, const memelang::FileContents* cts)
    : f_(file), cts_(cts) {}

void Interpreter::run() {
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
  }
}
void Interpreter::runVar(VarDefn* var) { printf("In var: %s\n", var->decl->ref->name.c_str()); }

void Interpreter::runOp(Op* op) {
  switch (op->type) {
  case Expr::FN_CALL: {
    auto* call = g<VarRef>(op->left);
    auto* args = g<FnCallArgs>(op->right);
    if (call->name == "printf") { printf("Printf: '%s'\n", g<StrLit>(args->args[0])->val.c_str()); }
    break;
  }
  default: break;
  }
}

}  // namespace memelang
