#include "parser.h"

#include <sstream>

#define token_error(expr, token, ...) \
  do { \
    if (!(expr)) { \
      fprintf(stderr, "compile error at %s - ", token.toString(contents_).c_str()); \
      fprintf(stderr, __VA_ARGS__); \
      fprintf(stderr, "\n"); \
      exit(1); \
    } \
  } while (0)

#define expect_token(type, note) \
  do { \
    auto token = nextToken(); \
    token_error(token.type == type, token, "expecting " note); \
  } while (0)

namespace {

std::unique_ptr<Parser::Node> nodeFromToken(Parser::Node::Type type, const Token& token) {
  auto node = std::make_unique<Parser::Node>();
  *node = Parser::Node{type, {}, token.loc, token.size};
  return node;
}

int parseInt(const std::string& str) {
  std::istringstream s(str);
  int out = INT_MIN;
  if (!(s >> out)) return INT_MIN;
  if (!s.eof()) return INT_MIN;
  return out;
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
      return parseFunctionDefinition();
    default:
      token_error(false, token, "unexpected token");
  }
}

std::unique_ptr<Parser::Node> Parser::parseInterface() {
  auto node = nodeFromToken(Node::INTERFACE, nextToken());
  expect_token(Token::LBRACE, "left brace");

  while (true) {
    auto token = curToken();
    if (token.type == Token::RBRACE) break;
    node->children.push_back(parseFunctionDeclaration());
  }
  expect_token(Token::RBRACE, "right brace");

  return node;
}


std::unique_ptr<Parser::Node> Parser::parseFunctionDeclaration() {
  auto node = parseFunctionSignature();
  expect_token(Token::SEMICOLON, "semicolon");
  return node;
}

std::unique_ptr<Parser::Node> Parser::parseFunctionDefinition() {
  auto node = parseFunctionSignature();
  node->children.push_back(parseBlock());
  return node;
}

std::unique_ptr<Parser::Node> Parser::parseFunctionSignature() {
  auto node = nodeFromToken(Node::FUNCTION, curToken());
  expect_token(Token::FUNCTION, "function declaration");

  node->children.push_back(nodeFromToken(Node::IDENT, curToken()));
  expect_token(Token::LITERAL, "function name");

  expect_token(Token::LPAREN, "opening paren");
  expect_token(Token::RPAREN, "closing paren");

  node->children.push_back(nodeFromToken(Node::IDENT, curToken()));
  expect_token(Token::LITERAL, "return type");

  return node;
}

std::unique_ptr<Parser::Node> Parser::parseStruct() {
//  auto node = nodeFromToken(Node::FUNCTION, tokens_[state_.idx++]);
  return std::unique_ptr<Parser::Node>();
}

std::unique_ptr<Parser::Node> Parser::parseBlock() {
  auto node = nodeFromToken(Node::BLOCK, curToken());
  expect_token(Token::LBRACE, "left brace");

  while (true) {
    auto token = curToken();
    if (token.type == Token::RBRACE) break;
    node->children.push_back(parseStatement());
  }
  expect_token(Token::RBRACE, "right brace");

  return node;
}

std::unique_ptr<Parser::Node> Parser::parseStatement() {
  auto token = curToken();
  auto node = std::make_unique<Node>();
  switch (token.type) {
    case Token::RETURN:
      node = nodeFromToken(Node::RETURN, nextToken());
      node->children.push_back(parseExpression());
      break;
    default:
      token_error(false, token, "unexpected token");
  }

  expect_token(Token::SEMICOLON, "expected semicolon");
  return node;
}

std::unique_ptr<Parser::Node> Parser::parseExpression() {
  auto token = nextToken();
  auto node = std::make_unique<Node>();
  switch (token.type) {
    case Token::LITERAL: {
      int lit = parseInt(contents_->getSpan(token.loc, token.size));
      if (lit != INT_MIN) {
        node = nodeFromToken(Node::INTEGER_LITERAL, token);
      } else {
        token_error(false, token, "expected integer literal");
      }
      break;
    }
    default:
      token_error(false, token, "unexpected token");
  }
  return node;
}

std::string Parser::astToString() {
  std::string out;
  for (const auto& child : root_->children) {
    bars_.clear();
    astToStringInternal(child.get(), out, 0);
  }
  return out;
}

void Parser::astToStringInternal(const Parser::Node* const root, std::string& out, int indent) {
  if (root == nullptr) return;

  out += contents_->getSpan(root->loc, root->size);
  out += '\n';
  bars_.insert(indent);
  for (int i = 0; i < root->children.size(); ++i) {
    const auto* child = root->children[i].get();
    for (int k = 0; k < indent; ++k)
      out += bars_.count(k) ? "│" : " ";
    if (i == root->children.size() - 1) {
      out += "└";
      bars_.erase(indent);
    } else {
      out += "├";
    }
    out += "──";
    astToStringInternal(child, out, indent + 2);
  }
}

const Token& Parser::nextToken() {
  token_error(hasToken(), tokens_.back(), "unexpected end of file");
  return tokens_[state_.idx++];
}

const Token& Parser::curToken() {
  token_error(hasToken(), tokens_.back(), "unexpected end of file");
  return tokens_[state_.idx];
}