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
      BLOCK,
      FOR,
      FUNCTION,
      FUNCTION_PARAM,
      FUNCTION_CALL,
      INTERFACE,
      WHILE,
      TYPE,
      IDENT,
      INDEX,
    } type;
    std::vector<std::unique_ptr<Node>> children;
    int loc;
    int size;
  };

  Parser(const FileContents* contents, std::vector<Token> tokens) : contents_(contents), tokens_(std::move(tokens)) {}

  void parse();

  std::string astToString();

private:
  struct TraversalState {
    int idx = 0;
    int depth = 0;
  } state_;

  const FileContents* contents_;
  std::vector<Token> tokens_;
  std::unique_ptr<Node> root_;

  std::unordered_set<int> bars_;

  std::unique_ptr<Parser::Node> parseTopLevel();
  std::unique_ptr<Parser::Node> parseInterface();
  std::unique_ptr<Parser::Node> parseFunction();
  std::unique_ptr<Parser::Node> parseStruct();
  std::unique_ptr<Parser::Node> parseBlock();
  std::unique_ptr<Parser::Node> parseStatement();

  const Token& curToken() { return tokens_[state_.idx]; }
  const Token& nextToken();
  bool hasToken() { return state_.idx < tokens_.size(); }

  void astToStringInternal(const Parser::Node* const root, std::string& out, int indent);
};

#endif //MEMELANG_PARSER_H
