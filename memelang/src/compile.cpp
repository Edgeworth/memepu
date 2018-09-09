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

namespace meme {

const std::string& Compile::generateCode() {
  for (const auto& child : root_->children)
    extractSymbols(child.get());
  for (auto iter : funcs_) {
    generateCodeForBlock(iter.second.defn);
  }
  return code_;
}

void Compile::generateCodeForBlock(const Parser::Node* node) {

}

void Compile::extractSymbols(const Parser::Node* node) {
  switch (node->type) {
    case Parser::Node::FUNCTION: {
      auto func = extractFunctionDefinition(node);
      auto iter = funcs_.find(func.sig.name);
      compile_error(iter == funcs_.end(), node, "redefinition of function %s", func.sig.name.c_str());
      printf("Extracted func: %s\n", func.sig.name.c_str());
      funcs_[func.sig.name] = std::move(func);
      break;
    }
    case Parser::Node::STRUCT: {
      auto struc = extractStruct(node);
      auto iter = structs_.find(struc.name);
      compile_error(iter == structs_.end(), node, "redefinition of struct %s", struc.name.c_str());
      printf("Extracted struct: %s\n", struc.name.c_str());
      structs_[struc.name] = std::move(struc);
      break;
    }
    case Parser::Node::INTERFACE: {
      auto interface = extractInterface(node);
      auto iter = interfaces_.find(interface.name);
      compile_error(iter == interfaces_.end(), node, "redefinition of interface %s", interface.name.c_str());
      printf("Extracted interface: %s\n", interface.name.c_str());
      interfaces_[interface.name] = std::move(interface);
      break;
    }
    default:
      compile_error(false, node, "unexpected construct at %d:%d: %s", contents_->getLineNumber(node->loc),
                    contents_->getColNumber(node->loc), contents_->getSpan(node->loc, node->size).c_str());
      break;
  }
}

FuncSig Compile::extractFunctionSignature(const Parser::Node* node) {
  return FuncSig{
      extractIdentifier(node), // name
      maybeExtractTemplateDeclaration(node), // templates
      extractType(findOne(node, Parser::Node::TYPE)),  // return type
      map(findAll(node, Parser::Node::VARIABLE_DECLARATION), &Compile::extractVariableDeclaration), // params
      !findAll(node, Parser::Node::STATIC).empty(), // is_static
  };
}

Func Compile::extractFunctionDefinition(const Parser::Node* node) {
  return Func{
      extractFunctionSignature(node), // signature
      findOne(node, Parser::Node::BLOCK), // body
  };
}

Struct Compile::extractStruct(const Parser::Node* node) {
  return Struct{
      text(node), // name
      maybeExtractTemplateDeclaration(node), // templates
      map(findAll(node, Parser::Node::FUNCTION), &Compile::extractFunctionDefinition), // funcs
      map(findAll(node, Parser::Node::VARIABLE_DECLARATION), &Compile::extractVariableDeclaration), // vars
  };
}

Interface Compile::extractInterface(const Parser::Node* node) {
  return Interface{
      text(node), // name
      maybeExtractTemplateDeclaration(node), // templates
      map(findAll(node, Parser::Node::FUNCTION), &Compile::extractFunctionSignature), // funcs
  };
}

Type Compile::extractType(const Parser::Node* node) {
  return Type{
      text(node), // name
      !findAll(node, Parser::Node::POINTER).empty(), // pointer
      maybeExtractTemplateDefinition(node), // templates
  };
}

Variable Compile::extractVariableDeclaration(const Parser::Node* node) {
  return Variable{
      extractType(node), // type
      extractIdentifier(node), // name
  };
}

std::string Compile::extractIdentifier(const Parser::Node* node) {
  return text(findOne(node, Parser::Node::IDENT));
}

std::vector<Type> Compile::maybeExtractTemplateDefinition(const Parser::Node* node) {
  const auto* template_node = maybeFindOne(node, Parser::Node::TEMPLATE);
  if (!template_node) return {};
  return map(findAll(template_node, Parser::Node::TYPE), &Compile::extractType);
}

std::vector<std::string> Compile::maybeExtractTemplateDeclaration(const Parser::Node* node) {
  const auto* template_node = maybeFindOne(node, Parser::Node::TEMPLATE);
  if (!template_node) return {};
  return map(findAll(template_node, Parser::Node::IDENT), &Compile::text);
}

const Parser::Node* Compile::maybeFindOne(const Parser::Node* node, Parser::Node::Type type) {
  auto nodes = findAll(node, type);
  if (nodes.empty()) return nullptr;
  compile_error(nodes.size() <= 1, node, "expected no more than one node of type %d, found %d", int(type),
                int(nodes.size()));
  return nodes[0];
}

const Parser::Node* Compile::findOne(const Parser::Node* node, Parser::Node::Type type) {
  auto nodes = findAll(node, type);
  compile_error(nodes.size() == 1, node, "expected only one node of type %d, found %d", int(type), int(nodes.size()));
  return nodes[0];
}

std::vector<const Parser::Node*> Compile::findAll(const Parser::Node* node, Parser::Node::Type type) {
  std::vector<const Parser::Node*> matches;
  for (const auto& child : node->children) {
    if (child->type == type) matches.push_back(child.get());
  }
  return matches;
}

}  // namespace meme