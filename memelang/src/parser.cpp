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
  token_error(name->type == expected_type, name, "expecting " note);

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
    {Token::Type::EQUAL, Parser::Node::ASSIGN},
    {Token::Type::DEQUAL, Parser::Node::EQUALS},
    {Token::Type::NEQUAL, Parser::Node::NOT_EQUALS},
    {Token::Type::DOT, Parser::Node::ACCESS},
    {Token::Type::LANGLE, Parser::Node::LESS_THAN},
    {Token::Type::RANGLE, Parser::Node::GREATER_THAN},
    {Token::Type::LTEQUAL, Parser::Node::LESS_THAN_EQUAL},
    {Token::Type::GTEQUAL, Parser::Node::GREATER_THAN_EQUAL},
};

std::unordered_map<Parser::Node::Type, int> PRECEDENCE = {
    {Parser::Node::ACCESS, 4},
    {Parser::Node::MUL, 3},
    {Parser::Node::DIV, 3},
    {Parser::Node::ADD, 2},
    {Parser::Node::SUB, 2},
    {Parser::Node::LESS_THAN, 1},
    {Parser::Node::GREATER_THAN, 1},
    {Parser::Node::LESS_THAN_EQUAL, 1},
    {Parser::Node::GREATER_THAN_EQUAL, 1},
    {Parser::Node::EQUALS, 1},
    {Parser::Node::NOT_EQUALS, 1},
    {Parser::Node::ASSIGN, 0},
};

}  // namespace

void Parser::parse() {
  idx_ = 0;

  root_ = tryInternal();
  if (!root_) {
    compileError();
  }
}

// Top level

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

// Building blocks:
std::unique_ptr<Parser::Node> Parser::tryFunctionSignature(bool allow_template) {
  consume_token(function_token, Token::FUNCTION, "function declaraton");
  auto node = nodeFromToken(Node::FUNCTION, function_token);

  auto static_node = tri([this] { return tryStaticQualifier(); });
  if (static_node)
    node->children.push_back(std::move(static_node));

  consume_token(name_token, Token::LITERAL, "function name");
  node->children.push_back(nodeFromToken(Node::IDENT, name_token));

  if (allow_template)
    maybeAddTemplateDeclaration(node.get());

  expect_token(Token::LPAREN, "opening paren");
  while (true) {
    peek_token(token);
    if (token->type == Token::RPAREN) break;

    expect_parse(type, [this] { return tryType(); });
    expect_parse(identifier, [this] { return tryIdentifier(); });

    node->children.push_back(std::move(type));
    node->children.push_back(std::move(identifier));

    peek_token(comma_token);
    if (comma_token->type == Token::COMMA)
      discard_token();
  }
  expect_token(Token::RPAREN, "closing paren");

  expect_parse(child, [this] { return tryType(); });
  node->children.push_back(std::move(child));

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
  maybeAddTemplateDeclaration(node.get());
  peek_token(pointer_token);
  if (pointer_token->type == Token::ASTERISK) {
    node->children.push_back(nodeFromToken(Node::POINTER, pointer_token));
    discard_token();
  }
  return node;
}

std::unique_ptr<Parser::Node> Parser::tryBlock() {
  consume_token(block_token, Token::LBRACE, "left brace");
  auto node = nodeFromToken(Node::BLOCK, block_token);

  while (true) {
    peek_token(token);
    if (token->type == Token::RBRACE) break;

    expect_parse(child, [this] { return tryStatement(); });
    node->children.push_back(std::move(child));
  }
  expect_token(Token::RBRACE, "right brace");

  return node;
}

std::unique_ptr<Parser::Node> Parser::tryTemplateDeclaration() {
  consume_token(template_token, Token::LANGLE, "left angle bracket");
  auto node = nodeFromToken(Node::TEMPLATE, template_token);
  while (true) {
    expect_parse(type, [this] { return tryIdentifier(); });
    node->children.push_back(std::move(type));

    peek_token(token);
    if (token->type == Token::RANGLE) break;

    peek_token(comma_token);
    if (comma_token->type == Token::COMMA)
      discard_token();
  }
  expect_token(Token::RANGLE, "closing right angle brace");

  return node;
}

void Parser::maybeAddTemplateDeclaration(Parser::Node* root) {
  auto template_declaration = tri([this] { return tryTemplateDeclaration(); });
  if (template_declaration)
    root->children.push_back(std::move(template_declaration));
}

std::unique_ptr<Parser::Node> Parser::tryStaticQualifier() {
  consume_token(token, Token::STATIC, "static");
  return nodeFromToken(Node::STATIC, token);
}

// Struct possibilities:
std::unique_ptr<Parser::Node> Parser::tryStruct() {
  expect_token(Token::STRUCT, "struct");
  expect_parse(node, [this] { return tryIdentifier(); });

  maybeAddTemplateDeclaration(node.get());

  expect_token(Token::LBRACE, "left brace");
  while (true) {
    peek_token(token);
    if (token->type == Token::RBRACE) break;

    expect_parse(child, [this] { return tryVariableDeclaration(); }, [this] { return tryFunctionDefinition(false); });

    if (child->type != Node::FUNCTION)
      expect_token(Token::SEMICOLON, "semicolon");

    node->children.push_back(std::move(child));
  }
  expect_token(Token::RBRACE, "right brace");

  return node;
}

std::unique_ptr<Parser::Node> Parser::tryVariableDeclaration() {
  peek_token(token);
  auto node = nodeFromToken(Node::VARIABLE_DECLARATION, token);

  expect_parse(type, [this] { return tryType(); });
  node->children.push_back(std::move(type));

  expect_parse(name, [this] { return tryIdentifier(); });
  node->children.push_back(std::move(name));

  return node;
}

std::unique_ptr<Parser::Node> Parser::tryFunctionDefinition(bool allow_template) {
  expect_parse(node, [this, allow_template] { return tryFunctionSignature(allow_template); });
  expect_parse(child, [this] { return tryBlock(); });
  node->children.push_back(std::move(child));
  return node;
}

// Interface possibilities:
std::unique_ptr<Parser::Node> Parser::tryInterface() {
  expect_token(Token::INTERFACE, "interface");

  auto node = tri([this] { return tryIdentifier(); });
  node->type = Node::INTERFACE;  // This is actually an interface.

  maybeAddTemplateDeclaration(node.get());

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

// Statement possibilities:
std::unique_ptr<Parser::Node> Parser::tryStatement() {
  peek_token(token);
  expect_parse(node, [this] { return tryVariableDefinition(); },
      [this] { return tryExpression(); }, [this] { return tryReturn(); },
      [this] { return tryIf(); }, [this] { return tryFor(); });
  if (node->type != Node::IF && node->type != Node::FOR)
    expect_token(Token::SEMICOLON, "semicolon");
  return node;
}

std::unique_ptr<Parser::Node> Parser::tryVariableDefinition() {
  expect_parse(node, [this] { return tryVariableDeclaration(); });
  expect_token(Token::EQUAL, "equals sign");
  expect_parse(initialiser, [this] { return tryExpression(); });
  node->children.push_back(std::move(initialiser));

  return node;
}

std::unique_ptr<Parser::Node> Parser::tryIf() {
  consume_token(if_token, Token::IF, "if");
  expect_token(Token::LPAREN, "left parent");
  auto node = nodeFromToken(Node::IF, if_token);
  expect_parse(cond, [this] { return tryExpression(); });
  expect_token(Token::RPAREN, "right parent");
  expect_parse(block, [this] { return tryBlock(); });
  node->children.push_back(std::move(cond));
  node->children.push_back(std::move(block));
  return node;
}

std::unique_ptr<Parser::Node> Parser::tryReturn() {
  consume_token(return_token, Token::RETURN, "return");
  auto node = nodeFromToken(Node::RETURN, return_token);
  expect_parse(child, [this] { return tryExpression(); });
  node->children.push_back(std::move(child));
  return node;
}

std::unique_ptr<Parser::Node> Parser::tryFor() {
  consume_token(for_token, Token::FOR, "for");
  auto node = nodeFromToken(Node::FOR, for_token);

  expect_token(Token::LPAREN, "left parent");
  expect_parse(initialiser, [this] { return tryStatement(); });
  expect_parse(cond, [this] { return tryExpression(); });
  expect_token(Token::SEMICOLON, "semicolon");
  expect_parse(update, [this] { return tryExpression(); });
  expect_token(Token::RPAREN, "right parent");

  node->children.push_back(std::move(initialiser));
  node->children.push_back(std::move(cond));
  node->children.push_back(std::move(update));

  expect_parse(block, [this] { return tryBlock(); });
  node->children.push_back(std::move(block));

  return node;
}


// Expression possibilities:
std::unique_ptr<Parser::Node> Parser::tryExpression(int last_precedence) {
  std::unique_ptr<Node> node;
  while (true) {
    peek_token(token);
    // Stop parsing at the end of a statement, sub-expression, start of a block (e.g. if statement),
    // end of an indexing, or part of a list (comma).
    if (token->type == Token::SEMICOLON || token->type == Token::RPAREN ||
        token->type == Token::LBRACE || token->type == Token::RSQUARE || token->type == Token::COMMA)
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
        // Parse literal last - it might be an index,  function call, or struct initialiser.
        expect_parse(literal, [this] { return tryFunctionCall(); }, [this] { return tryIndex(); },
            [this] { return tryStructInitialiser(); }, [this] { return tryLiteral(); });
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

std::unique_ptr<Parser::Node> Parser::tryFunctionCall() {
  expect_parse(node, [this] { return tryIdentifier(); });
  node->type = Node::FUNCTION_CALL;  // Actually this is a function call.

  expect_token(Token::LPAREN, "left paren");
  while (true) {
    peek_token(token);
    if (token->type == Token::RPAREN) break;

    expect_parse(child, [this] { return tryExpression(); });
    node->children.push_back(std::move(child));

    peek_token(comma_token);
    if (comma_token->type == Token::COMMA)
      discard_token();
  }
  expect_token(Token::RPAREN, "right paren");

  return node;
}

std::unique_ptr<Parser::Node> Parser::tryIndex() {
  expect_parse(node, [this] { return tryIdentifier(); });
  node->type = Node::INDEX;  // Actually this is an indexing operation.
  expect_token(Token::LSQUARE, "left square bracket");
  expect_parse(index, [this] { return tryExpression(); });
  node->children.push_back(std::move(index));
  expect_token(Token::RSQUARE, "right square bracket");
  return node;
}

std::unique_ptr<Parser::Node> Parser::tryStructInitialiser() {
  expect_parse(node, [this] { return tryType(); });
  node->type = Node::STRUCT_INITIALISER;  // Actually this is an initialisation operation.
  expect_token(Token::LBRACE, "left brace");
  while (true) {
    peek_token(token);
    if (token->type == Token::RBRACE) break;

    expect_parse(member, [this] { return tryIdentifier(); });
    node->children.push_back(std::move(member));
    expect_token(Token::COLON, "colon");

    expect_parse(expr, [this] { return tryExpression(); });
    node->children.push_back(std::move(expr));

    expect_token(Token::COMMA, "comma");
  }

  expect_token(Token::RBRACE, "right brace");
  return node;
}

std::string Parser::astToString(const Node* root) {
  verify_expr(root, "astToString called with null root");

  std::string out;
  for (const auto& child : root->children) {
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

void Parser::compileError() {
  fflush(stdout);
  fprintf(stderr, "Compile error:\n%s\n", error_.empty() ? "unknown error" : error_.c_str());
  exit(1);
}