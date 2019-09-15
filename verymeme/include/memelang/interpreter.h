#ifndef MEMELANG_INTERPRETER_H
#define MEMELANG_INTERPRETER_H

#include <map>

#include "memelang/ast.h"

namespace memelang {

class Interpreter {
public:
  Interpreter(File* file, const FileContents* cts);

  void run();

private:
  struct Value {
    int64_t int_val;
    Type* type;

    std::shared_ptr<Value> assign(Value* val);
    std::shared_ptr<Value> add(Value* val);
    std::shared_ptr<Value> sub(Value* val);
    std::shared_ptr<Value> lt(Value* val);
    std::shared_ptr<Value> eq(Value* val);
    std::shared_ptr<Value> preinc();
  };

  File* f_;
  const FileContents* cts_;
  std::unordered_map<std::string, Fn*> fns_;
  std::vector<std::vector<std::map<std::string, std::shared_ptr<Value>>>> vars_;

  std::shared_ptr<Value> runFn(Fn* fn);
  std::shared_ptr<Value> runStmtBlk(StmtBlk* blk);
  std::shared_ptr<Value> runStmt(Node* stmt);
  void runVarDefn(VarDefn* defn);
  std::shared_ptr<Value> runVarDecl(VarDecl* decl);
  std::shared_ptr<Value> runFor(For* fr);
  std::shared_ptr<Value> runIf(If* ifst);
  std::shared_ptr<Value> runOp(Op* op);

  std::shared_ptr<Value> eval(Node* n);
  void pushScope();  // Creates new scope-space
  void popScope();
  void nestScope();  // Nests scope inside current scope-space.
  void unnestScope();
  Fn* getFn(Node* n, std::string name);
  std::shared_ptr<Value> getVar(Node* n, const std::string& name) const;
  std::shared_ptr<Value> maybeGetVar(const std::string& name) const;

  void error(Node* n, const std::string& msg) const;
};

}  // namespace memelang

#endif  // MEMELANG_INTERPRETER_H
