#include "memelang/expression.h"

#include "verymeme/util.h"

namespace memelang {

namespace {

std::unordered_map<Tok::Type, Expr::Type> BINOP_MAP = {{Tok::DOT, Expr::MEMBER_ACCESS},
    {Tok::PLUS, Expr::ADD}, {Tok::ASTERISK, Expr::MUL}, {Tok::FSLASH, Expr::DIV},
    {Tok::MINUS, Expr::SUB}, {Tok::LSQUARE, Expr::ARRAY_ACCESS}, {Tok::LPAREN, Expr::FN_CALL},
    {Tok::LANGLE, Expr::LT}, {Tok::LTEQUAL, Expr::LEQ}, {Tok::RANGLE, Expr::GT},
    {Tok::GTEQUAL, Expr::GEQ}, {Tok::PERCENT, Expr::MOD}, {Tok::DEQUAL, Expr::EQ},
    {Tok::NEQUAL, Expr::NEQ}, {Tok::DAMPERSAND, Expr::LAND}, {Tok::AMPERSAND, Expr::BAND},
    {Tok::CARET, Expr::BXOR}, {Tok::DBAR, Expr::LOR}, {Tok::BAR, Expr::BOR},
    {Tok::EQUAL, Expr::ASSIGNMENT}};

std::unordered_map<Tok::Type, Expr::Type> POSTFIX_UNOP_MAP = {
    {Tok::DPLUS, Expr::POSTFIX_INC}, {Tok::DMINUS, Expr::POSTFIX_DEC}};

std::unordered_map<Tok::Type, Expr::Type> PREFIX_UNOP_MAP = {{Tok::DPLUS, Expr::PREFIX_INC},
    {Tok::DMINUS, Expr::PREFIX_DEC}, {Tok::MINUS, Expr::UNARY_NEGATE},
    {Tok::AMPERSAND, Expr::UNARY_ADDR}, {Tok::ASTERISK, Expr::UNARY_DEREF},
    {Tok::TILDE, Expr::UNARY_BINVERT}, {Tok::EXCLAMATION, Expr::UNARY_LINVERT}};

std::unordered_map<Expr::Type, int> PRECEDENCE = {{Expr::ARRAY_ACCESS, 15},
    {Expr::MEMBER_ACCESS, 15}, {Expr::FN_CALL, 15}, {Expr::POSTFIX_INC, 15},
    {Expr::POSTFIX_DEC, 15}, {Expr::PREFIX_INC, 14}, {Expr::PREFIX_DEC, 14},
    {Expr::UNARY_NEGATE, 14}, {Expr::UNARY_LINVERT, 14}, {Expr::UNARY_BINVERT, 14},
    {Expr::UNARY_DEREF, 14}, {Expr::UNARY_ADDR, 14}, {Expr::MUL, 13}, {Expr::DIV, 13},
    {Expr::MOD, 13}, {Expr::ADD, 12}, {Expr::SUB, 12}, {Expr::LSHIFT, 11}, {Expr::ARITH_RSHIFT, 11},
    {Expr::RSHIFT, 11}, {Expr::LEQ, 10}, {Expr::GEQ, 10}, {Expr::LT, 10}, {Expr::GT, 10},
    {Expr::EQ, 9}, {Expr::NEQ, 9}, {Expr::BAND, 8}, {Expr::BXOR, 7}, {Expr::BOR, 6},
    {Expr::LAND, 5}, {Expr::LOR, 4}, {Expr::TERNARY, 3}, {Expr::ASSIGNMENT, 2}};

const std::unordered_set<Expr::Type> RIGHT_ASSOC = {Expr::PREFIX_INC, Expr::PREFIX_DEC,
    Expr::UNARY_NEGATE, Expr::UNARY_LINVERT, Expr::UNARY_BINVERT, Expr::UNARY_DEREF,
    Expr::UNARY_ADDR, Expr::TERNARY, Expr::ASSIGNMENT};

}  // namespace

std::unique_ptr<Expr> ExpressionParser::parse() {
  // A top level expression must end either with semicolon (statement), comma (struct/array
  // literal, function call), closing paren (function call, for, if, match), closing brace
  // (compound literal), closing square bracket (array index).
  ExprCtx ectx(ctx_);
  while (!ctx_.hasToken({Tok::SEMICOLON, Tok::COMMA, Tok::RPAREN, Tok::RBRACE, Tok::RSQUARE})) {
    const auto* tok = ctx_.curToken();
    switch (tok->type) {
    // TODO handle bitshift, ternary, and types.
    case Tok::LPAREN: {
      // If we can do postfix, add function call operation. Otherwise, it's just a paren'd expr.
      ctx_.consumeToken();
      if (ectx.canDoPostfixOp()) {
        ectx.addOp(tok->type);
        ectx.addExpr(std::make_unique<FnCallArgs>(ctx_));
      } else {
        ectx.addExpr(parse());
      }
      ctx_.consumeToken(Tok::RPAREN);
      break;
    }
    case Tok::LSQUARE: {
      ectx.addOp(tok->type);
      ctx_.consumeToken();
      ectx.addExpr(parse());
      ctx_.consumeToken(Tok::RSQUARE);
      break;
    case Tok::LBRACE: ectx.addExpr(std::make_unique<CompoundLit>(ctx_)); break;
    }
    case Tok::IDENT: ectx.addExpr(std::make_unique<VarRef>(ctx_)); break;
    case Tok::BOOL_LIT: ectx.addExpr(std::make_unique<BoolLit>(ctx_)); break;
    case Tok::INT_LIT: ectx.addExpr(std::make_unique<IntLit>(ctx_)); break;
    case Tok::CHAR_LIT: ectx.addExpr(std::make_unique<CharLit>(ctx_)); break;
    case Tok::STR_LIT: ectx.addExpr(std::make_unique<StrLit>(ctx_)); break;
    default:
      ectx.addOp(tok->type);
      ctx_.consumeToken();
      break;
    }
  }
  return ectx.finish();
}

std::unique_ptr<Expr> ExpressionParser::ExprCtx::finish() {
  processStack(-1);
  if (s_.size() != 1 || !ops_.empty()) ctx_.compileError("error in expression");
  return std::move(s_[0]);
}

void ExpressionParser::ExprCtx::addOp(Tok::Type type) {
  if (canDoPostfixOp() && POSTFIX_UNOP_MAP.count(type)) {
    processStack(PRECEDENCE[POSTFIX_UNOP_MAP[type]]);
    ops_.emplace_back(std::make_unique<Op>(ctx_));
    ops_.back()->type = POSTFIX_UNOP_MAP[type];
  } else if (canDoPostfixOp() && BINOP_MAP.count(type)) {
    processStack(PRECEDENCE[BINOP_MAP[type]]);
    binop_count++;
    ops_.emplace_back(std::make_unique<Op>(ctx_));
    ops_.back()->type = BINOP_MAP[type];
    ops_.back()->is_binop = true;
  } else if (PREFIX_UNOP_MAP.count(type)) {
    processStack(PRECEDENCE[PREFIX_UNOP_MAP[type]]);
    ops_.emplace_back(std::make_unique<Op>(ctx_));
    ops_.back()->type = PREFIX_UNOP_MAP[type];
  } else {
    ctx_.compileError("unexpected token");
  }
}

bool ExpressionParser::ExprCtx::shouldPopStack(int precedence) const {
  if (ops_.empty() || s_.empty()) return false;
  return PRECEDENCE[ops_.back()->type] > precedence;  // If precedence goes down, we can pop.
}

void ExpressionParser::ExprCtx::processStack(int next_precedence) {
  while (shouldPopStack(next_precedence)) {
    const bool is_right = RIGHT_ASSOC.find(ops_.back()->type) != RIGHT_ASSOC.end();
    const int cur_precedence = PRECEDENCE[ops_.back()->type];
    std::vector<std::unique_ptr<Op>> curops;
    std::vector<std::unique_ptr<Expr>> curexpr;
    curexpr.emplace_back(std::move(s_.back()));
    s_.pop_back();
    while (!ops_.empty() && PRECEDENCE[ops_.back()->type] == cur_precedence) {
      if (ops_.back()->is_binop) {
        binop_count--;
        if (s_.empty()) ctx_.compileError("error in expression");
        curexpr.emplace_back(std::move(s_.back()));
        s_.pop_back();
      }
      curops.emplace_back(std::move(ops_.back()));
      ops_.pop_back();
    }
    if (is_right) {
      curops = reverse(std::move(curops));
      curexpr = reverse(std::move(curexpr));
    }
    collapseOps(curops, curexpr);
    s_.emplace_back(std::move(curexpr[0]));
  }
}

void ExpressionParser::ExprCtx::collapseOps(
    std::vector<std::unique_ptr<Op>>& ops, std::vector<std::unique_ptr<Expr>>& expr) {
  while (!ops.empty()) {
    verify_expr(!expr.empty(), "BUG");
    auto op = std::move(ops.back());
    ops.pop_back();
    if (op->is_binop) {
      op->right = std::move(expr.back());
      expr.pop_back();
    }
    verify_expr(!expr.empty(), "BUG");
    op->left = std::move(expr.back());
    expr.pop_back();
    expr.push_back(std::move(op));
  }
  if (expr.size() != 1 && !ops.empty()) ctx_.compileError("error in expression");
}

}  // namespace memelang
