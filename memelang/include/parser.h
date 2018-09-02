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
      BLOCK, FUNCTION, RETURN, INTERFACE, FOR, WHILE, TYPE, INDEX, INTEGER_LITERAL, IDENT, ADD, SUB, MUL, DIV, MOD
    } type;
    std::vector<std::unique_ptr<Node>> children;
    int loc;
    int size;
  };

  Parser(const FileContents* contents, std::vector<Token> tokens) : contents_(contents), tokens_(std::move(tokens)) {}

  void parse();

  std::string astToString();

private:
  int idx_ = 0;
  const FileContents* contents_;
  std::vector<Token> tokens_;
  std::unique_ptr<Node> root_;

  std::unordered_set<int> bars_;

  std::unique_ptr<Node> parseTopLevel();
  std::unique_ptr<Node> parseInterface();
  std::unique_ptr<Node> parseFunctionDeclaration();
  std::unique_ptr<Node> parseFunctionDefinition();
  std::unique_ptr<Node> parseFunctionSignature();
  std::unique_ptr<Node> parseStruct();
  std::unique_ptr<Node> parseBlock();
  std::unique_ptr<Node> parseStatement();
  std::unique_ptr<Node> parseExpression(int last_precedence = -1);
  std::unique_ptr<Node> parseLiteral();

  const Token& curToken();
  const Token& nextToken();
  bool hasToken() { return idx_ < tokens_.size(); }

  void astToStringInternal(const Parser::Node* const root, std::string& out, int indent);
};

#endif //MEMELANG_PARSER_H
