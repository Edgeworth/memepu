#ifndef MEMELANG_LLVM_H
#define MEMELANG_LLVM_H

#include "common.h"
#include "file_contents.h"
#include "compile.h"
#include "types.h"

#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"

namespace meme {

class LlvmCodegen {
public:
  LlvmCodegen(FileContents* contents, const Compile& compile);

  void codegen();

private:
  FileContents* contents_;
  const Compile& compile_;

  std::map<Type, llvm::Type*> typemap_;
  llvm::LLVMContext ctx_;
  llvm::IRBuilder<> builder_;
  llvm::Module module_;

  llvm::Function* generateFunction(const Func& func);

  llvm::Type* getLlvmType(const Type& type);
  Type typeFromVariable(const Variable& var) { return var.type; }

  template<typename R, typename T>
  using FuncType = R (LlvmCodegen::*)(const T&);

  template<typename R, typename T>
  std::vector<R> map(const std::vector<T>& vec, FuncType<R, T> func) {
    std::vector<R> out;
    for (const auto& obj : vec)
      out.push_back((this->*func)(obj));
    return out;
  }
};

}  // namespace meme

#endif //MEMELANG_LLVM_H
