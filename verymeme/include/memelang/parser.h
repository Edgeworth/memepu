#ifndef MEMELANG_PARSER_H
#define MEMELANG_PARSER_H

#include "verymeme/common.h"
#include "memelang/tokeniser.h"
#include "memelang/file_contents.h"
#include "memelang/types.h"
#include <vector>
#include <memory>
#include <unordered_set>

namespace memelang {

class Parser {
public:

  Parser(const FileContents* contents, std::vector<Token> tokens)
    : contents_(contents), tokens_(std::move(tokens)) {}

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
  std::unique_ptr<Node> tryTemplateList(bool is_definition);
  std::unique_ptr<Node> tryStaticQualifier();
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
  bool hasToken(int ahead = 0) { return idx_ + ahead < int(tokens_.size()); }
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

  void astToStringInternal(const Node* const root, std::string& out, int indent);
};

}  // namespace memelang

#endif  // MEMELANG_PARSER_H
