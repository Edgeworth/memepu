#ifndef MEMELANG_COMPILE_H
#define MEMELANG_COMPILE_H

#include "verymeme/common.h"
#include "memelang/parser.h"
#include "memelang/types.h"
#include <unordered_map>
#include <functional>

namespace memelang {

class Compile {
public:
  Compile(FileContents* contents, const Parser::Node* ast) : contents_(contents), root_(ast) {}

  const std::string& generateCode();

  const std::unordered_map<std::string, Func>& getFunctions() const { return funcs_; }

private:
  FileContents* contents_;
  const Parser::Node* root_;
  std::string code_;
  std::unordered_map<std::string, Func> funcs_;
  std::unordered_map<std::string, Struct> structs_;
  std::unordered_map<std::string, Interface> interfaces_;

  void generateCodeForBlock(const Parser::Node* node);
  void extractSymbols(const Parser::Node* node);

  FuncSig extractFunctionSignature(const Parser::Node* node);
  Func extractFunctionDefinition(const Parser::Node* node);
  Struct extractStruct(const Parser::Node* node);
  Interface extractInterface(const Parser::Node* node);
  Type extractType(const Parser::Node* node);
  Variable extractVariableDeclaration(const Parser::Node* node);
  std::string extractIdentifier(const Parser::Node* node);
  std::vector<Type> maybeExtractTemplateDefinition(const Parser::Node* node);
  std::vector<std::string> maybeExtractTemplateDeclaration(const Parser::Node* node);

  template<typename T>
  using FuncType = T (Compile::*)(const Parser::Node*);

  template<typename T>
  std::vector<T> map(const std::vector<const Parser::Node*>& vec, FuncType<T> func) {
    std::vector<T> out;
    for (const auto* node : vec)
      out.push_back((this->*func)(node));
    return out;
  }

  std::string text(const Parser::Node* node) { return contents_->getSpan(node->loc, node->size); }
  const Parser::Node* maybeFindOne(const Parser::Node* node, Parser::Node::Type type);
  const Parser::Node* findOne(const Parser::Node* node, Parser::Node::Type type);
  std::vector<const Parser::Node*> findAll(const Parser::Node* node, Parser::Node::Type type);
};

}  // namespace memelang

#endif  // MEMELANG_COMPILE_H
