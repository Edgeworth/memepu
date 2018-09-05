#include "compile.h"
#include <algorithm>

#define compile_error(expr, node, ...) \
  do { \
    if (!(expr)) { \
      fprintf(stderr, "compile error at %d:%d - ", \
          contents_->getLineNumber(node->loc), contents_->getColNumber(node->loc)); \
      fprintf(stderr, __VA_ARGS__); \
      fprintf(stderr, "\n"); \
      exit(1); \
    } \
  } while (0)

const std::string& Compile::generateCode() {
  extractSymbols(root_);
  return code_;
}

void Compile::generateCodeInternal(const Parser::Node* node) {

}

void Compile::extractSymbols(const Parser::Node* node) {
  auto name = text(node);
  switch (node->type) {
    case Parser::Node::FUNCTION: {
      auto iter = funcs_.find(name);
      compile_error(iter == funcs_.end(), node, "redefinition of function %s", name.c_str());
      funcs_[name] = extractFunction(node);
      break;
    }
    case Parser::Node::STRUCT:
      break;
    case Parser::Node::INTERFACE:
      break;
    default:
      compile_error(false, node, "unexpected construct %s", name.c_str());
      break;
  }
}

Compile::Func Compile::extractFunction(const Parser::Node* node) {
  return Func {
    text(findOne(node, Parser::Node::IDENT)),  // name
    map(findAll(node, Parser::Node::TYPE), &Compile::extractVariable), // templates
    map(findAll(node, Parser::Node::VARIABLE_DECLARATION), &Compile::extractType), // params
    !findAll(node, Parser::Node::STATIC).empty(), // is_static
    findOne(node, Parser::Node::BLOCK), // body
  };
}

Compile::Struct Compile::extractStruct(const Parser::Node* node) {
  return Compile::Struct();
}

Compile::Interface Compile::extractInterface(const Parser::Node* node) {
  return Compile::Interface();
}

Compile::Type Compile::extractType(const Parser::Node* node) {
  return Compile::Type();
}

Compile::Variable Compile::extractVariable(const Parser::Node* node) {
  return Compile::Variable();
}

const Parser::Node* Compile::findOne(const Parser::Node* node, Parser::Node::Type type) {
  auto nodes = findAll(node, type);
  compile_error(nodes.size() == 1, node, "internal error");
  return nodes[0];
}

std::vector<const Parser::Node*> Compile::findAll(const Parser::Node* node, Parser::Node::Type type) {
  std::vector<const Parser::Node*> matches;
  for (const auto& child : node->children) {
    if (child->type == type) matches.push_back(child.get());
  }
  return matches;
}
