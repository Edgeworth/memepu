// Copyright 2019 E.
#ifndef MEMELANG_EXPRESSION_H_
#define MEMELANG_EXPRESSION_H_

#include "memelang/ast.h"
#include "memelang/parser.h"

namespace memelang::ast {

class ExprParser {
 public:
  explicit ExprParser(Parser::Ctx& ctx) : c_(ctx) {}

  std::unique_ptr<Node> parse();

 private:
  Parser::Ctx& c_;

  class ExprCtx {
   public:
    explicit ExprCtx(Parser::Ctx& c) : c_(c) {}

    std::unique_ptr<Node> finish();
    void pushTypeOrCompoundLit(std::unique_ptr<Type> type);
    void addExpr(std::unique_ptr<Node> e) { s_.emplace_back(std::move(e)); }
    void addOp(Tok::Type type);
    bool canFinish() const { return s_.size() - binop_count == 1; }

   private:
    Parser::Ctx& c_;
    std::vector<std::unique_ptr<Node>> s_ = {};
    std::vector<std::unique_ptr<Op>> ops_ = {};
    int binop_count = 0;

    bool shouldPopStack(int precedence) const;
    void processStack(int next_precedence);
    void collapseOps(
        std::vector<std::unique_ptr<Op>>& ops, std::vector<std::unique_ptr<Node>>& expr);
  };
};

}  // namespace memelang::ast

#endif  // MEMELANG_EXPRESSION_H_
