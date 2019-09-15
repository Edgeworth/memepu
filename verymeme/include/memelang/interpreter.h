#ifndef MEMELANG_INTERPRETER_H
#define MEMELANG_INTERPRETER_H

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
  };

  File* f_;
  const FileContents* cts_;
  std::unordered_map<std::string, Fn*> fns_;
  std::unordered_map<std::string, std::shared_ptr<Value>> vars_; // TODO

  void runFn(Fn* fn);
  void runStmt(Node* stmt);
  void runVar(VarDefn* var);
  void runFor(For* fr);
  std::shared_ptr<Value> runOp(Op* op);
  std::shared_ptr<Value> eval(Node* n);

  std::shared_ptr<Value> getVar(Node* ref) const;

  void error(Node* n, const std::string& msg) const;
};

}  // namespace memelang

#endif  // MEMELANG_INTERPRETER_H
