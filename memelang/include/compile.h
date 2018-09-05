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
  };

  struct Variable {
    Type type;
    std::string name;
  };

  struct Func {
    std::string name;
    std::vector<Variable> params;
    std::vector<Type> templates;
    bool is_static;
    const Parser::Node* defn;
  };

  struct Struct {
    std::string name;
    std::vector<Func> funcs;
    std::vector<Variable> vars;
  };

  struct Interface {
    std::string name;
    std::vector<Func> funcs;
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

  Func extractFunction(const Parser::Node* node);
  Struct extractStruct(const Parser::Node* node);
  Interface extractInterface(const Parser::Node* node);
  Type extractType(const Parser::Node* node);
  Variable extractVariable(const Parser::Node* node);

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
