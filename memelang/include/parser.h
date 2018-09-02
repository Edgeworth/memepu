#include <utility>

#ifndef MEMELANG_PARSER_H
#define MEMELANG_PARSER_H

#include "common.h"
#include "tokeniser.h"
#include "file_contents.h"
#include <vector>
#include <memory>
#include <unordered_set>

class Parser {
public:
  struct Node {
    enum Type {
      BLOCK, FUNCTION, RETURN, INTERFACE, FOR, WHILE, TYPE, TEMPLATE, INDEX, INTEGER_LITERAL, IDENT, ADD, SUB, MUL,
      DIV, MOD, VARIABLE_DECLARATION, FUNCTION_CALL, POINTER, STRUCT
    } type;
    std::vector<std::unique_ptr<Node>> children;
    int loc;
    int size;
  };

  Parser(const FileContents* contents, std::vector<Token> tokens) : contents_(contents), tokens_(std::move(tokens)) {}

  void parse();
  const Node* root() { return root_.get(); }

  std::string astToString(const Node* root);

private:
  int idx_ = 0;
  const FileContents* contents_;
  std::vector<Token> tokens_;
  std::unique_ptr<Node> root_;
  std::string error_;

  // AST printing related.
  std::unordered_set<int> bars_;

  std::unique_ptr<Node> tryInternal();
  std::unique_ptr<Node> tryTopLevel();

  // Building blocks:
  std::unique_ptr<Node> tryFunctionSignature(bool allow_template);
  std::unique_ptr<Node> tryLiteral();
  std::unique_ptr<Node> tryIdentifier();
  std::unique_ptr<Node> tryType();
  std::unique_ptr<Node> tryBlock();
  std::unique_ptr<Parser::Node> tryTemplateDeclaration();
  void maybeAddTemplateDeclaration(Node* root);

  // Struct possibilities:
  std::unique_ptr<Node> tryStruct();
  std::unique_ptr<Node> tryVariableDeclaration();
  std::unique_ptr<Node> tryFunctionDefinition(bool allow_template);

  // Interface possibilities:
  std::unique_ptr<Node> tryInterface();
  std::unique_ptr<Node> tryFunctionDeclaration(bool allow_template);

  // Statement possibilities:
  std::unique_ptr<Node> tryStatement();
  std::unique_ptr<Node> tryVariableDefinition();
  std::unique_ptr<Node> tryIf();
  std::unique_ptr<Node> tryReturn();

  // Expression possibilities:
  std::unique_ptr<Node> tryExpression(int last_precedence = -1);
  std::unique_ptr<Node> tryFunctionCall();

  const Token* curToken();
  const Token* nextToken();
  const Token* peekToken(int ahead = 1);
  bool hasToken(int ahead = 0) { return idx_ + ahead < tokens_.size(); }
  void compileError();

  std::unique_ptr<Node> tri() {
    return nullptr;
  }

  template<typename T, typename... Args>
  std::unique_ptr<Node> tri(T func, Args... args) {
    int prev_idx = idx_;
    auto child = func();
    if (!child) {
      idx_ = prev_idx;
      child = tri(args...);
    }
    return child;
  }

  void astToStringInternal(const Parser::Node* const root, std::string& out, int indent);
};

#endif //MEMELANG_PARSER_H
