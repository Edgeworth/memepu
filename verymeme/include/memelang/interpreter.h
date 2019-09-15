#ifndef MEMELANG_INTERPRETER_H
#define MEMELANG_INTERPRETER_H

#include "memelang/ast.h"

namespace memelang {

class Interpreter {
public:
  Interpreter(File* file, const FileContents* cts);

  void run();

private:
  struct Var {
    int64_t int_val;
    Type* type;
  };

  File* f_;
  const FileContents* cts_;
  std::unordered_map<std::string, Fn*> fns_;
  std::unordered_map<std::string, std::unique_ptr<Var>> sym_; // TODO

  void runFn(Fn* fn);
  void runStmt(Node* stmt);
  void runVar(VarDefn* var);
  void runOp(Op* op);

  Var* getVar(Node* n, const std::string& name) const;

  void error(Node* n, const std::string& msg) const;
};

}  // namespace memelang

#endif  // MEMELANG_INTERPRETER_H
