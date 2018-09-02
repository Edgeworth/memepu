#include "parser.h"

#include <sstream>
#include <unordered_map>
#include <parser.h>


#define token_error(expr, token, ...) \
  do { \
    if (!(expr)) { \
      fprintf(stderr, "%s:%d: ", __func__, __LINE__); \
      fprintf(stderr, "compile error at %s - ", token.toString(contents_).c_str()); \
      fprintf(stderr, __VA_ARGS__); \
      fprintf(stderr, "\n"); \
      exit(1); \
    } \
  } while (0)

#define expect_token(expected_type, note) \
  do { \
    auto token = nextToken(); \
    token_error(token.type == expected_type, token, "expecting " note); \
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

std::unordered_map<Token::Type, Parser::Node::Type> OPMAP = {
    {Token::Type::PLUS, Parser::Node::ADD},
    {Token::Type::MINUS, Parser::Node::SUB},
    {Token::Type::ASTERISK, Parser::Node::MUL},
    {Token::Type::FSLASH, Parser::Node::DIV},
};

std::unordered_map<Parser::Node::Type, int> PRECEDENCE = {
    {Parser::Node::MUL, 1},
    {Parser::Node::DIV, 1},
    {Parser::Node::MOD, 1},
    {Parser::Node::ADD, 0},
    {Parser::Node::SUB, 0},
};

}  // namespace

void Parser::parse() {
  root_ = std::make_unique<Parser::Node>();
  idx_ = 0;

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
      return parseFunctionDefinition(true);
    default:
      token_error(false, token, "unexpected token");
  }
}

std::unique_ptr<Parser::Node> Parser::parseInterface() {
  auto node = nodeFromToken(Node::INTERFACE, nextToken());
  maybeParseTemplateSpecifier(node.get());
  expect_token(Token::LBRACE, "left brace");

  while (true) {
    auto token = curToken();
    if (token.type == Token::RBRACE) break;
    node->children.push_back(parseFunctionDeclaration(false));
  }
  expect_token(Token::RBRACE, "right brace");

  return node;
}


std::unique_ptr<Parser::Node> Parser::parseFunctionDeclaration(bool allow_template) {
  auto node = parseFunctionSignature(allow_template);
  expect_token(Token::SEMICOLON, "semicolon");
  return node;
}

std::unique_ptr<Parser::Node> Parser::parseFunctionDefinition(bool allow_template) {
  auto node = parseFunctionSignature(allow_template);
  node->children.push_back(parseBlock());
  return node;
}

std::unique_ptr<Parser::Node> Parser::parseFunctionSignature(bool allow_template) {
  auto node = nodeFromToken(Node::FUNCTION, curToken());
  expect_token(Token::FUNCTION, "function declaration");

  node->children.push_back(nodeFromToken(Node::IDENT, curToken()));
  expect_token(Token::LITERAL, "function name");

  if (allow_template)
    maybeParseTemplateSpecifier(node.get());

  expect_token(Token::LPAREN, "opening paren");
  expect_token(Token::RPAREN, "closing paren");

  node->children.push_back(parseType());

  return node;
}

std::unique_ptr<Parser::Node> Parser::parseStruct() {
//  auto node = nodeFromToken(Node::FUNCTION, tokens_[idx_++]);
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

std::unique_ptr<Parser::Node> Parser::parseExpression(int last_precedence) {
  auto node = std::make_unique<Node>();
  while (true) {
    auto token = curToken();
    if (token.type == Token::SEMICOLON || token.type == Token::RPAREN)
      break;

    switch (token.type) {
      case Token::LITERAL:
        node = parseLiteral();
        continue;
      case Token::LPAREN:
        nextToken();
        node = parseExpression();
        expect_token(Token::RPAREN, "expected closing paren");
        continue;
      default:
        break;
    }

    auto iter = OPMAP.find(token.type);
    if (iter != OPMAP.end()) {
      auto type = iter->second;
      auto precedence = PRECEDENCE[type];

      // If current precedence isn't high enough to keep going, stop parsing here.
      if (precedence <= last_precedence)
        break;

      nextToken();
      auto child = nodeFromToken(type, token);
      std::swap(child, node);
      node->children.push_back(std::move(child));
      node->children.push_back(parseExpression(precedence));
      continue;
    }

    token_error(false, token, "unexpected token");
  }

  return node;
}

std::unique_ptr<Parser::Node> Parser::parseLiteral() {
  auto token = nextToken();
  auto node = std::make_unique<Node>();
  int lit = parseInt(contents_->getSpan(token.loc, token.size));
  if (lit != INT_MIN) {
    node = nodeFromToken(Node::INTEGER_LITERAL, token);
  } else {
    node = nodeFromToken(Node::IDENT, token);
  }
  return node;
}

std::unique_ptr<Parser::Node> Parser::parseIdentifier() {
  auto token = curToken();
  auto node = parseLiteral();
  token_error(node->type == Node::IDENT, token, "token not identifier");
  return node;
}


std::unique_ptr<Parser::Node> Parser::parseType() {
  auto node = parseIdentifier();
  maybeParseTemplateSpecifier(node.get());
  return node;
}

void Parser::maybeParseTemplateSpecifier(Node* root) {
  auto token = curToken();
  if (token.type != Token::LANGLE) return;

  auto node = nodeFromToken(Node::TEMPLATE, token);
  nextToken();
  while (true) {
    node->children.push_back(parseIdentifier());

    token = curToken();
    if (token.type == Token::RANGLE) break;

    expect_token(Token::COMMA, "expected comma");
  }
  expect_token(Token::RANGLE, "expected closing right angle brace");

  root->children.push_back(std::move(node));
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
  return tokens_[idx_++];
}

const Token& Parser::curToken() {
  token_error(hasToken(), tokens_.back(), "unexpected end of file");
  return tokens_[idx_];
}