#ifndef MEMELANG_INTERPRETER_H
#define MEMELANG_INTERPRETER_H

#include "memelang/ast.h"
namespace memelang {

class Interpreter {
public:
  Interpreter(File* file, const FileContents* cts);

  void run();

private:

  File* f_;
  const FileContents* cts_;
  std::unordered_map<std::string, Fn*> fns_;
  std::unordered_map<std::string, void*> sym_; // TODO

  void runFn(Fn* fn);
  void runStmt(Node* stmt);
  void runVar(VarDefn* var);
  void runOp(Op* op);
};

}  // namespace memelang

#endif  // MEMELANG_INTERPRETER_H
