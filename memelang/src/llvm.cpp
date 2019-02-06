
#include <llvm.h>

#include "llvm/IR/LegacyPassManager.h"
#include "llvm/IR/Verifier.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/Support/TargetRegistry.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Transforms/Utils/Cloning.h"

namespace meme {

LlvmCodegen::LlvmCodegen(FileContents* contents, const Compile& compile) : contents_(contents),
                                                                           compile_(compile),
                                                                           ctx_(), builder_(ctx_),
                                                                           module_("module", ctx_) {
  typemap_[INT8] = llvm::Type::getInt8Ty(ctx_);
  typemap_[INT16] = llvm::Type::getInt16Ty(ctx_);
  typemap_[UINT8] = llvm::Type::getInt8Ty(ctx_);
  typemap_[UINT16] = llvm::Type::getInt16Ty(ctx_);

  LLVMInitializeX86TargetInfo();
  LLVMInitializeX86Target();
  LLVMInitializeX86TargetMC();
  LLVMInitializeX86AsmParser();
  LLVMInitializeX86AsmPrinter();
  auto triple = llvm::sys::getDefaultTargetTriple();
  std::string err;
  auto* target = llvm::TargetRegistry::lookupTarget(triple, err);
  verify_expr(target, "error with llvm target %s: %s", triple.c_str(), err.c_str());
  machine_ = target->createTargetMachine(triple, "generic", "", llvm::TargetOptions(),
      llvm::Optional<llvm::Reloc::Model>());
  module_.setDataLayout(machine_->createDataLayout());
  module_.setTargetTriple(triple);

  machine_->Options.MCOptions.AsmVerbose = true;
}


void LlvmCodegen::codegen() {
  auto funcs = compile_.getFunctions();
  for (auto iter : funcs) {
    const auto& func = iter.second;
    generateFunction(func);
  }

  outputLlvmFile("a.asm", llvm::TargetMachine::CGFT_AssemblyFile);
  outputLlvmFile("a.o", llvm::TargetMachine::CGFT_ObjectFile);
}

llvm::Function* LlvmCodegen::generateFunction(const Func& func) {
  auto* return_type = getLlvmType(func.sig.return_type);
  auto param_types = map(map(func.sig.params, &LlvmCodegen::typeFromVariable),
      &LlvmCodegen::getLlvmType);
  auto* llvm_func_type = llvm::FunctionType::get(return_type, param_types, false);
  auto* llvm_func = llvm::Function::Create(llvm_func_type, llvm::Function::ExternalLinkage,
      func.sig.name, &module_);

  int idx = 0;
  for (auto& arg : llvm_func->args())
    arg.setName(func.sig.params[idx++].name);

  auto* block = llvm::BasicBlock::Create(ctx_, "entry", llvm_func);
  builder_.SetInsertPoint(block);  // Start writing stuff into the block.

  generateBlock(func.defn->children.at(0).get());

  llvm::verifyFunction(*llvm_func);
  fprintf(stderr, "Made function: ");
  llvm_func->print(llvm::errs());
  fprintf(stderr, "\n");
  return llvm_func;
}

void LlvmCodegen::generateBlock(const Parser::Node* node) {
  for (const auto& child : node->children) {
    generateStatement(child.get());
  }
}

void LlvmCodegen::generateStatement(const Parser::Node* node) {
  switch (node->type) {
    default:
      generateExpression(node);
  }
}

llvm::Value* LlvmCodegen::generateExpression(const Parser::Node* node) {
  std::vector<llvm::Value*> values;
  for (const auto& child : node->children)
    values.push_back(generateExpression(child.get()));

  fprintf(stderr, "")

  switch (node->type) {
    case Parser::Node::ADD:
      return builder_.CreateAdd(values.at(0), values.at(1), "add");
    case Parser::Node::INTEGER_LITERAL:
      return llvm::ConstantInt::get(ctx_, llvm::APInt(8, uint64_t(node->intdata), false));
    default:
      verify_expr(false, "should never happen, node of type: %d", int(node->type));
  }
}

llvm::Type* LlvmCodegen::getLlvmType(const Type& type) {
  auto iter = typemap_.find(type);
  verify_expr(iter != typemap_.end(), "unknown type");
  return iter->second;
}

void
LlvmCodegen::outputLlvmFile(const std::string& name, llvm::TargetMachine::CodeGenFileType type) {
  std::error_code error_code;
  llvm::raw_fd_ostream file(name, error_code, llvm::sys::fs::F_None);
  verify_expr(!error_code, "could not open llvm file for writing: %s",
      error_code.message().c_str());

  llvm::legacy::PassManager pass;
  verify_expr(!machine_->addPassesToEmitFile(pass, file, type), "could not write llvm file");

  auto module = llvm::CloneModule(&module_);
  pass.run(*module);
  file.flush();
}

}  // namespace meme