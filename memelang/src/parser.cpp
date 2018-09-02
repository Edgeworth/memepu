#include "parser.h"

#include <sstream>
#include <unordered_map>
#include <parser.h>

#define compile_error(msg) \
  do { \
    error_ = msg; \
    return nullptr; \
  } while (0)

#define token_error(expr, token, ...) \
  do { \
    if (!(expr)) { \
      char buf0[4096], buf1[4096]; \
      snprintf(buf0, sizeof(buf0), "%s:%d: compile error at %s - ", __func__, \
               __LINE__, (token)->toString(contents_).c_str()); \
      snprintf(buf1, sizeof(buf1), __VA_ARGS__); \
      compile_error(std::string(buf0) + std::string(buf1) + "\n") ; \
    } \
  } while (0)

#define peek_token(name) \
  const auto* name = curToken(); \
  if (!name) return nullptr;

#define discard_token() \
  if (!nextToken()) return nullptr;

#define consume_token(name, expected_type, note) \
  const auto* name = nextToken(); \
  if (!name) return nullptr; \
  token_error(name->type == expected_type, token, "expecting " note);

#define expect_token(expected_type, note) \
  do { \
    consume_token(token, expected_type, note); \
  } while (0)

#define expect_parse(name, ...) \
  auto name = tri(__VA_ARGS__); \
  if (!name) return nullptr;

namespace {

std::unique_ptr<Parser::Node> nodeFromToken(Parser::Node::Type type, const Token* token) {
  auto node = std::make_unique<Parser::Node>();
  *node = Parser::Node{type, {}, token->loc, token->size};
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
  idx_ = 0;

  root_ = tryInternal();
  if (!root_) compileError();
}


std::unique_ptr<Parser::Node> Parser::tryInternal() {
  auto node = std::make_unique<Parser::Node>();

  while (hasToken()) {
    expect_parse(child, [this] { return tryTopLevel(); });
    node->children.push_back(std::move(child));
  }

  return node;
}

std::unique_ptr<Parser::Node> Parser::tryTopLevel() {
  peek_token(token);
  switch (token->type) {
    case Token::INTERFACE:
      return tryInterface();
    case Token::STRUCT:
      return tryStruct();
    case Token::FUNCTION:
      return tryFunctionDefinition(true);
    default:
      token_error(false, token, "unexpected token");
  }
  return nullptr;
}

std::unique_ptr<Parser::Node> Parser::tryInterface() {
  expect_token(Token::INTERFACE, "interface");

  auto node = tri([this] { return tryIdentifier(); });
  node->type = Node::INTERFACE;  // This is actually an interface.

  // Don't consider it an error to be missing a template list.
  auto template_list = tri([this] { return tryTemplateList(); });
  if (template_list)
    node->children.push_back(std::move(template_list));
  expect_token(Token::LBRACE, "left brace");

  while (true) {
    peek_token(token);
    if (token->type == Token::RBRACE) break;

    expect_parse(child, [this] { return tryFunctionDeclaration(false); });

    node->children.push_back(std::move(child));
  }
  expect_token(Token::RBRACE, "right brace");

  return node;
}

std::unique_ptr<Parser::Node> Parser::tryFunctionDeclaration(bool allow_template) {
  expect_parse(node, [this, allow_template] { return tryFunctionSignature(allow_template); });
  expect_token(Token::SEMICOLON, "semicolon");
  return node;
}

std::unique_ptr<Parser::Node> Parser::tryFunctionDefinition(bool allow_template) {
  expect_parse(node, [this, allow_template] { return tryFunctionSignature(allow_template); });
  expect_parse(child, [this] { return tryBlock(); });
  node->children.push_back(std::move(child));
  return node;
}

std::unique_ptr<Parser::Node> Parser::tryFunctionSignature(bool allow_template) {
  peek_token(function_token)
  auto node = nodeFromToken(Node::FUNCTION, function_token);
  expect_token(Token::FUNCTION, "function declaration");

  peek_token(name_token);
  node->children.push_back(nodeFromToken(Node::IDENT, name_token));
  expect_token(Token::LITERAL, "function name");

  if (allow_template) {
    auto template_list = tri([this] { return tryTemplateList(); });
    if (template_list)
      node->children.push_back(std::move(template_list));
  }

  expect_token(Token::LPAREN, "opening paren");
  expect_token(Token::RPAREN, "closing paren");

  expect_parse(child, [this] { return tryType(); });
  node->children.push_back(std::move(child));

  return node;
}

std::unique_ptr<Parser::Node> Parser::tryStruct() {
//  auto node = nodeFromToken(Node::FUNCTION, tokens_[idx_++]);
  return std::unique_ptr<Parser::Node>();
}

std::unique_ptr<Parser::Node> Parser::tryBlock() {
  peek_token(block_token)
  auto node = nodeFromToken(Node::BLOCK, block_token);
  expect_token(Token::LBRACE, "left brace");

  while (true) {
    peek_token(token);
    if (token->type == Token::RBRACE) break;

    expect_parse(child, [this] { return tryStatement(); });
    node->children.push_back(std::move(child));
  }
  expect_token(Token::RBRACE, "right brace");

  return node;
}

std::unique_ptr<Parser::Node> Parser::tryStatement() {
  peek_token(token);
  auto node = std::make_unique<Node>();
  switch (token->type) {
    case Token::LITERAL: {
      expect_parse(literal, [this] { return tryVariableDeclaration(); }, [this] { return tryExpression(); });
      node = std::move(literal);
      break;
    }
    case Token::RETURN: {
      consume_token(return_token, Token::RETURN, "return");
      node = nodeFromToken(Node::RETURN, return_token);
      expect_parse(child, [this] { return tryExpression(); });
      node->children.push_back(std::move(child));
      break;
    }
    default:
      token_error(false, token, "unexpected token");
  }

  expect_token(Token::SEMICOLON, "semicolon");
  return node;
}

std::unique_ptr<Parser::Node> Parser::tryExpression(int last_precedence) {
  std::unique_ptr<Node> node;
  while (true) {
    peek_token(token);
    if (token->type == Token::SEMICOLON || token->type == Token::RPAREN)
      break;

    auto iter = OPMAP.find(token->type);
    if (iter != OPMAP.end()) {
      auto type = iter->second;
      auto precedence = PRECEDENCE[type];

      // If current precedence isn't high enough to keep going, stop parsing here.
      if (precedence <= last_precedence)
        break;

      discard_token();
      auto child = nodeFromToken(type, token);
      std::swap(child, node);
      node->children.push_back(std::move(child));

      expect_parse(subexpr, [this, precedence] { return tryExpression(precedence); });
      node->children.push_back(std::move(subexpr));
      continue;
    }

    // Don't want hanging exprs.
    token_error(!node, token, "unexpected token in expression");

    switch (token->type) {
      case Token::LITERAL: {
        expect_parse(literal, [this] { return tryFunctionCall(); }, [this] { return tryLiteral(); });
        node = std::move(literal);
        continue;
      }
      case Token::LPAREN: {
        discard_token();
        expect_parse(subexpr, [this] { return tryExpression(); });
        node = std::move(subexpr);
        expect_token(Token::RPAREN, "closing paren");
        continue;
      }
      default:
        break;
    }

    token_error(false, token, "unexpected token");
  }

  return node;
}

std::unique_ptr<Parser::Node> Parser::tryLiteral() {
  consume_token(token, Token::LITERAL, "literal");
  auto node = std::make_unique<Node>();
  int lit = parseInt(contents_->getSpan(token->loc, token->size));
  if (lit != INT_MIN) {
    node = nodeFromToken(Node::INTEGER_LITERAL, token);
  } else {
    node = nodeFromToken(Node::IDENT, token);
  }
  return node;
}

std::unique_ptr<Parser::Node> Parser::tryIdentifier() {
  peek_token(token);
  expect_parse(node, [this] { return tryLiteral(); });
  token_error(node->type == Node::IDENT, token, "token not identifier");
  return node;
}


std::unique_ptr<Parser::Node> Parser::tryType() {
  expect_parse(node, [this] { return tryIdentifier(); });
  auto template_list = tri([this] { return tryTemplateList(); });
  if (template_list)
    node->children.push_back(std::move(template_list));
  peek_token(pointer_token);
  if (pointer_token->type == Token::ASTERISK) {
    node->children.push_back(nodeFromToken(Node::POINTER, pointer_token));
    discard_token();
  }
  return node;
}

std::unique_ptr<Parser::Node> Parser::tryVariableDeclaration() {
  peek_token(token);
  auto node = nodeFromToken(Node::VARIABLE_DECLARATION, token);

  expect_parse(type, [this] { return tryType(); });
  node->children.push_back(std::move(type));

  expect_parse(name, [this] { return tryIdentifier(); });
  node->children.push_back(std::move(name));

  expect_token(Token::EQUAL, "equals sign");

  expect_parse(initialiser, [this] { return tryExpression(); });
  node->children.push_back(std::move(initialiser));

  return node;
}

std::unique_ptr<Parser::Node> Parser::tryTemplateList() {
  peek_token(template_token);
  auto node = nodeFromToken(Node::TEMPLATE, template_token);
  expect_token(Token::LANGLE, "left angle bracket");
  while (true) {
    expect_parse(type, [this] { return tryIdentifier(); });
    node->children.push_back(std::move(type));

    peek_token(token)
    if (token->type == Token::RANGLE) break;

    peek_token(comma_token);
    if (comma_token->type == Token::COMMA)
      discard_token();
  }
  expect_token(Token::RANGLE, "closing right angle brace");

  return node;
}

std::unique_ptr<Parser::Node> Parser::tryFunctionCall() {
  expect_parse(node, [this] { return tryIdentifier(); });
  node->type = Node::FUNCTION_CALL;  // Actually this is a function call.

  expect_token(Token::LPAREN, "left paren");
  while (true) {
    peek_token(token);
    if (token->type == Token::RPAREN) break;

    expect_parse(child, [this] { return tryIdentifier(); });
    node->children.push_back(std::move(child));

    peek_token(comma_token);
    if (comma_token->type == Token::COMMA)
      discard_token();
  }
  expect_token(Token::RPAREN, "right paren");

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

const Token* Parser::nextToken() {
  token_error(hasToken(), &tokens_.back(), "unexpected end of file");
  return &tokens_[idx_++];
}

const Token* Parser::curToken() {
  token_error(hasToken(), &tokens_.back(), "unexpected end of file");
  return &tokens_[idx_];
}

const Token* Parser::peekToken(int ahead) {
  token_error(hasToken() && hasToken(1), &tokens_.back(), "unexpected end of file");
  return &tokens_[idx_ + ahead];
}

void Parser::compileError() {
  fprintf(stderr, "Compile error:\n%s\n", error_.empty() ? "unknown error" : error_.c_str());
  exit(1);
}
