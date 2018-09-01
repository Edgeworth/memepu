#include "parser.h"

#define token_error(expr, token, ...) \
  do { \
    if (!(expr)) { \
      fprintf(stderr, "compile error at %s - ", token.toString(contents_).c_str()); \
      fprintf(stderr, __VA_ARGS__); \
      fprintf(stderr, "\n"); \
      exit(1); \
    } \
  } while (0)

namespace {

std::unique_ptr<Parser::Node> nodeFromToken(Parser::Node::Type type, const Token& token) {
  auto node = std::make_unique<Parser::Node>();
  *node = Parser::Node{type, {}, token.loc, token.size};
  return node;
}

}  // namspace

void Parser::parse() {
  root_ = std::make_unique<Parser::Node>();
  state_ = TraversalState();

  while (hasToken()) {
    root_->children.push_back(parseTopLevel());
  }
}

std::unique_ptr<Parser::Node> Parser::parseTopLevel() {
  auto token = curToken();
  switch (token.type) {
    case Token::INTERFACE:
      return parseInterface();
    case Token::STRUCT:
      return parseStruct();
    case Token::FUNCTION:
      return parseFunction();
    default:
      token_error(false, token, "unexpected token");
  }
}

std::unique_ptr<Parser::Node> Parser::parseInterface() {
  auto node = nodeFromToken(Node::INTERFACE, tokens_[state_.idx++]);
  node->children.push_back(parseBlock());
  return node;
}

std::unique_ptr<Parser::Node> Parser::parseFunction() {
//  auto node = nodeFromToken(Node::FUNCTION, tokens_[state_.idx++]);
  return std::unique_ptr<Parser::Node>();
}

std::unique_ptr<Parser::Node> Parser::parseStruct() {
//  auto node = nodeFromToken(Node::FUNCTION, tokens_[state_.idx++]);
  return std::unique_ptr<Parser::Node>();
}

std::unique_ptr<Parser::Node> Parser::parseBlock() {
  auto token = nextToken();
  token_error(token.type == Token::LBRACE, token, "expecting left brace");
  auto node = nodeFromToken(Node::BLOCK, token);

  state_.depth++;  // TODO need depth?
  token = nextToken();
  while (token.type != Token::RBRACE) {
    node->children.push_back(parseStatement());
  }
  state_.depth--;

  return node;
}

std::unique_ptr<Parser::Node> Parser::parseStatement() {
  return std::unique_ptr<Parser::Node>();
}

std::string Parser::astToString() {
  std::string out;
  bars_.clear();
  for (const auto& child : root_->children) {
    astToStringInternal(child.get(), out, 0);
  }
  return out;
}

void Parser::astToStringInternal(const Parser::Node* const root, std::string& out, int indent) {
  if (root == nullptr) return;

  printf("NODE: %s\n", contents_->getSpan(root->loc, root->size).c_str());
  out += contents_->getSpan(root->loc, root->size);
  out += '\n';
  for (int i = 0; i < root->children.size(); ++i) {
    const auto* child = root->children[i].get();
    for (int k = 0; k < indent; ++k)
      out += bars_.count(k) ? "│" : " ";
    out += i != root->children.size() - 1 ? "├" : "└";
    out += "──";
    bars_.insert(indent);
    astToStringInternal(child, out, indent + 2);
  }
}

const Token& Parser::nextToken() {
  token_error(hasToken(), tokens_.back(), "unexpected end of file");
  return tokens_[state_.idx++];
}
