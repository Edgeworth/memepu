#include "compile.h"


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
      funcs_[name] = extractFunctionDefinition(node);
      break;
    }
    case Parser::Node::STRUCT: {
      auto iter = structs_.find(name);
      compile_error(iter == structs_.end(), node, "redefinition of struct %s", name.c_str());
      structs_[name] = extractStruct(node);
      break;
    }
    case Parser::Node::INTERFACE: {
      auto iter = interfaces_.find(name);
      compile_error(iter == interfaces_.end(), node, "redefinition of interface %s", name.c_str());
      interfaces_[name] = extractInterface(node);
      break;
    }
    default:
      compile_error(false, node, "unexpected construct %s", name.c_str());
      break;
  }
}

Compile::FuncSig Compile::extractFunctionSignature(const Parser::Node* node) {
  return FuncSig{
      extractIdentifier(node), // name
      map(findAll(findOne(node, Parser::Node::TEMPLATE), Parser::Node::IDENT),
          &Compile::extractIdentifier), // templates
      map(findAll(node, Parser::Node::VARIABLE_DECLARATION), &Compile::extractVariable), // params
      !findAll(node, Parser::Node::STATIC).empty(), // is_static
  };
}

Compile::Func Compile::extractFunctionDefinition(const Parser::Node* node) {
  return Func{
      extractFunctionSignature(node), // signature
      findOne(node, Parser::Node::BLOCK), // body
  };
}

Compile::Struct Compile::extractStruct(const Parser::Node* node) {
  return Struct{
      extractIdentifier(node), // name
      extractTemplateDeclaration(node), // templates
      map(findAll(node, Parser::Node::FUNCTION), &Compile::extractFunctionDefinition), // funcs
      map(findAll(node, Parser::Node::VARIABLE_DECLARATION), &Compile::extractVariable), // vars
  };
}

Compile::Interface Compile::extractInterface(const Parser::Node* node) {
  return Interface{
      extractIdentifier(node), // name
      extractTemplateDeclaration(node), // templates
      map(findAll(node, Parser::Node::FUNCTION), &Compile::extractFunctionSignature), // funcs
  };
}

Compile::Type Compile::extractType(const Parser::Node* node) {
  return Type{
      extractIdentifier(node), // name
      !findAll(node, Parser::Node::POINTER).empty(), // pointer
      extractTemplateDefinition(node), // templates
  };
}

Compile::Variable Compile::extractVariable(const Parser::Node* node) {
  return Compile::Variable();
}

std::string Compile::extractIdentifier(const Parser::Node* node) {
  return text(findOne(node, Parser::Node::IDENT));
}


std::vector<Compile::Type> Compile::extractTemplateDefinition(const Parser::Node* node) {
  return map(findAll(findOne(node, Parser::Node::TEMPLATE), Parser::Node::TYPE), &Compile::extractType);
}

std::vector<std::string> Compile::extractTemplateDeclaration(const Parser::Node* node) {
  return map(findAll(findOne(node, Parser::Node::TEMPLATE), Parser::Node::IDENT), &Compile::extractIdentifier);
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