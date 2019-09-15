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
  }
}
void Interpreter::runVar(VarDefn* var) {
  const auto& name = var->decl->ref->name;
  printf("In var: %s\n", var->decl->ref->name.c_str());
  if (sym_.count(name)) error(var, "redeclaration of var " + name);
  sym_[name] = std::make_unique<Var>(Var{g<IntLit>(var->defn)->val, g<Type>(var->decl->type)});
}

void Interpreter::runOp(Op* op) {
  switch (op->type) {
  case Expr::FN_CALL: {
    auto* call = g<VarRef>(op->left);
    auto* args = g<FnCallArgs>(op->right);
    if (call->name == "printf") {
      if (args->args.empty()) error(op, "printf requires at least 1 argument");
      boost::format fmt = boost::format(g<StrLit>(args->args[0])->val);
      for (int i = 1; i < int(args->args.size()); ++i)
        fmt = fmt % getVar(args->args[i].get(), g<VarRef>(args->args[i])->name)->int_val;
      printf("%s", fmt.str().c_str());
    }
    break;
  }
  default: break;
  }
}

void Interpreter::error(Node* n, const std::string& msg) const {
  verify_expr(false, "error at '%s' (%d:%d): %s", cts_->getSpan(n->tok.loc, n->tok.size).c_str(),
      cts_->getLineNumber(n->tok.loc), cts_->getColNumber(n->tok.loc), msg.c_str());
}

Interpreter::Var* Interpreter::getVar(Node* n, const std::string& name) const {
  auto iter = sym_.find(name);
  if (iter == sym_.end()) error(n, "undeclared variable " + name);
  return iter->second.get();
}

}  // namespace memelang
