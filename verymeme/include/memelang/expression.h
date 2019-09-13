#ifndef MEMELANG_EXPRESSION_H
#define MEMELANG_EXPRESSION_H

#include "memelang/ast.h"
#include "memelang/parser.h"

namespace memelang {

class ExpressionParser {
public:
  explicit ExpressionParser(Parser::Context& ctx) : ctx_(ctx) {}

  std::unique_ptr<Expr> parse();

private:
  Parser::Context& ctx_;

  class ExprCtx {
  public:
    explicit ExprCtx(Parser::Context& ctx) : ctx_(ctx) {}

    std::unique_ptr<Expr> finish();
    void addExpr(std::unique_ptr<Expr> e) { s_.emplace_back(std::move(e)); }
    void addOp(Tok::Type type);
    bool canDoPostfixOp() const { return s_.size() - binop_count == 1; }

  private:
    Parser::Context& ctx_;
    std::vector<std::unique_ptr<Expr>> s_ = {};
    std::vector<std::unique_ptr<Op>> ops_ = {};
    int binop_count = 0;

    bool shouldPopStack(int precedence) const;
    void processStack(int next_precedence);
    void collapseOps(
        std::vector<std::unique_ptr<Op>>& ops, std::vector<std::unique_ptr<Expr>>& expr);
  };
};

}  // namespace memelang

#endif  // MEMELANG_EXPRESSION_H
