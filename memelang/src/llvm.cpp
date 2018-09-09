
#include <llvm.h>

#include "llvm.h"

#include "types.h"

#include "llvm/ADT/APFloat.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Verifier.h"

namespace meme {

LlvmCodegen::LlvmCodegen(FileContents* contents, const Compile& compile) : contents_(contents), compile_(compile), ctx_(), builder_(ctx_), module_("module", ctx_) {
  typemap_[INT8] = llvm::Type::getInt8Ty(ctx_);
  typemap_[INT16] = llvm::Type::getInt16Ty(ctx_);
  typemap_[UINT8] = llvm::Type::getInt8Ty(ctx_);
  typemap_[UINT16] = llvm::Type::getInt16Ty(ctx_);
}


void LlvmCodegen::codegen() {
  auto funcs = compile_.getFunctions();
  for (auto iter : funcs) {
    const auto& func = iter.second;
    generateFunction(func);
  }
}

llvm::Function *LlvmCodegen::generateFunction(const Func& func) {
  auto* return_type = getLlvmType(func.sig.return_type);
  auto param_types = map(map(func.sig.params, &LlvmCodegen::typeFromVariable), &LlvmCodegen::getLlvmType);
  auto* llvm_func_type = llvm::FunctionType::get(return_type, param_types, false);
  auto* llvm_func = llvm::Function::Create(llvm_func_type, llvm::Function::ExternalLinkage, func.sig.name, &module_);

  int idx = 0;
  for (auto& arg : llvm_func->args())
    arg.setName(func.sig.params[idx++].name);

  auto* block = llvm::BasicBlock::Create(ctx_, "entry", llvm_func);
  builder_.SetInsertPoint(block);  // Start writing stuff into the block.
  builder_.CreateRet(llvm::ConstantInt::get(ctx_, llvm::APInt(8, 42, false)));  // TODO: test uint8 = 42

  llvm::verifyFunction(*llvm_func);
  fprintf(stderr, "Made function: ");
  llvm_func->print(llvm::errs());
  fprintf(stderr, "\n");
  return llvm_func;
}

llvm::Type* LlvmCodegen::getLlvmType(const Type& type) {
  auto iter = typemap_.find(type);
  verify_expr(iter != typemap_.end(), "unknown type");
  return iter->second;
}

}  // namespace meme