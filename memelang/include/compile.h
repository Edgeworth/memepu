#ifndef MEMELANG_COMPILE_H
#define MEMELANG_COMPILE_H

#include "common.h"
#include "parser.h"
#include <unordered_map>
#include <functional>

class Compile {
public:
  Compile(FileContents* contents, const Parser::Node* ast) : contents_(contents), root_(ast) {}

  const std::string& generateCode();

  struct Type {
    std::string name;
    bool pointer;
    std::vector<Type> templates;
  };

  struct Variable {
    Type type;
    std::string name;
  };

  struct FuncSig {
    std::string name;
    std::vector<std::string> templates;
    std::vector<Variable> params;
    bool is_static;
  };

  struct Func {
    FuncSig sig;
    const Parser::Node* defn;
  };

  struct Struct {
    std::string name;
    std::vector<std::string> templates;
    std::vector<Func> funcs;
    std::vector<Variable> vars;
  };

  struct Interface {
    std::string name;
    std::vector<std::string> templates;
    std::vector<FuncSig> funcs;
  };

private:
  FileContents* contents_;
  const Parser::Node* root_;
  std::string code_;
  std::unordered_map<std::string, Func> funcs_;
  std::unordered_map<std::string, Struct> structs_;
  std::unordered_map<std::string, Interface> interfaces_;

  void generateCodeInternal(const Parser::Node* node);
  void extractSymbols(const Parser::Node* node);

  FuncSig extractFunctionSignature(const Parser::Node* node);
  Func extractFunctionDefinition(const Parser::Node* node);
  Struct extractStruct(const Parser::Node* node);
  Interface extractInterface(const Parser::Node* node);
  Type extractType(const Parser::Node* node);
  Variable extractVariable(const Parser::Node* node);
  std::string extractIdentifier(const Parser::Node* node);
  std::vector<Type> extractTemplateDefinition(const Parser::Node* node);
  std::vector<std::string> extractTemplateDeclaration(const Parser::Node* node);

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
  const Parser::Node* findOne(const Parser::Node* node, Parser::Node::Type type);
  std::vector<const Parser::Node*> findAll(const Parser::Node* node, Parser::Node::Type type);
};

#endif //MEMELANG_COMPILE_H
