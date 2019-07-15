#ifndef MEMELANG_PARSER_H
#define MEMELANG_PARSER_H

#include "verymeme/common.h"
#include "memelang/tokeniser.h"
#include "memelang/file_contents.h"
#include <vector>
#include <memory>
#include <unordered_set>

namespace memelang {

class Parser {
public:
  struct Node {
    enum Type {
      // Top level constructs:
      INTF_DEFN, STRUCT_DEFN, FN_DEFN, ENUM_DEFN, IMPL_DEFN,
      // Blocks:
      STMT_BLK, STRUCT_BLK,
      // Statements:
      FOR, RETURN, VARIABLE_DECLARATION, BLOCK, IF,
      // Qualifiers:
      TEMPLATE, STATIC,
      // Expressions:
      TYPE, INDEX, INTEGER_LITERAL, IDENT, ADD, SUB, MUL,
      DIV, MOD, FUNCTION_CALL, POINTER, EQUALS, NOT_EQUALS, ACCESS, ASSIGN,
      STRUCT_INITIALISER, LESS_THAN, GREATER_THAN, LESS_THAN_EQUAL, GREATER_THAN_EQUAL
    } type;
    std::vector<std::unique_ptr<Node>> children;
    int loc;
    int size;
    int intdata;
  };

  Parser(const FileContents* contents, std::vector<Token> tokens) : contents_(contents),
                                                                    tokens_(std::move(tokens)) {}

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
  std::unique_ptr<Parser::Node> tryTemplateList(bool is_definition);
  std::unique_ptr<Parser::Node> tryStaticQualifier();
  void maybeAddTemplateList(Node* root, bool is_definition);

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
  std::unique_ptr<Node> tryFor();

  // Expression possibilities:
  std::unique_ptr<Node> tryExpression(int last_precedence = -1);
  std::unique_ptr<Node> tryFunctionCall();
  std::unique_ptr<Node> tryIndex();
  std::unique_ptr<Node> tryStructInitialiser();

  const Token* curToken();
  const Token* nextToken();
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

}  // namespace memelang

#endif  // MEMELANG_PARSER_H
