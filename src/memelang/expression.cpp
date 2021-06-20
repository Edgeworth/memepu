// Copyright 2019 E.
#include "memelang/expression.h"

#include "verymeme/util.h"

namespace memelang::ast {

namespace {

std::unordered_map<Tok::Type, Expr> BINOP_MAP = {{Tok::DOT, Expr::MEMBER_ACCESS},
    {Tok::PLUS, Expr::ADD}, {Tok::ASTERISK, Expr::MUL}, {Tok::FSLASH, Expr::DIV},
    {Tok::MINUS, Expr::SUB}, {Tok::LSQUARE, Expr::ARRAY_ACCESS}, {Tok::LPAREN, Expr::FN_CALL},
    {Tok::LANGLE, Expr::LT}, {Tok::LTEQUAL, Expr::LEQ}, {Tok::RANGLE, Expr::GT},
    {Tok::GTEQUAL, Expr::GEQ}, {Tok::PERCENT, Expr::MOD}, {Tok::DEQUAL, Expr::EQ},
    {Tok::NEQUAL, Expr::NEQ}, {Tok::DAMPERSAND, Expr::LAND}, {Tok::AMPERSAND, Expr::BAND},
    {Tok::CARET, Expr::BXOR}, {Tok::DBAR, Expr::LOR}, {Tok::BAR, Expr::BOR},
    {Tok::PERCENT, Expr::MOD}, {Tok::EQUAL, Expr::ASSIGNMENT}, {Tok::QUESTION, Expr::TERNARY},
    {Tok::COLON, Expr::TERNARY}};

std::unordered_map<Tok::Type, Expr> POSTFIX_UNOP_MAP = {
    {Tok::DPLUS, Expr::POSTFIX_INC}, {Tok::DMINUS, Expr::POSTFIX_DEC}};

std::unordered_map<Tok::Type, Expr> PREFIX_UNOP_MAP = {{Tok::DPLUS, Expr::PREFIX_INC},
    {Tok::DMINUS, Expr::PREFIX_DEC}, {Tok::MINUS, Expr::UNARY_NEGATE},
    {Tok::AMPERSAND, Expr::UNARY_ADDR}, {Tok::ASTERISK, Expr::UNARY_DEREF},
    {Tok::TILDE, Expr::UNARY_BINVERT}, {Tok::EXCLAMATION, Expr::UNARY_LINVERT}};

std::unordered_map<Expr, int> PRECEDENCE = {{Expr::ARRAY_ACCESS, 15}, {Expr::MEMBER_ACCESS, 15},
    {Expr::FN_CALL, 15}, {Expr::POSTFIX_INC, 15}, {Expr::POSTFIX_DEC, 15}, {Expr::PREFIX_INC, 14},
    {Expr::PREFIX_DEC, 14}, {Expr::UNARY_NEGATE, 14}, {Expr::UNARY_LINVERT, 14},
    {Expr::UNARY_BINVERT, 14}, {Expr::UNARY_DEREF, 14}, {Expr::UNARY_ADDR, 14}, {Expr::MUL, 13},
    {Expr::DIV, 13}, {Expr::MOD, 13}, {Expr::ADD, 12}, {Expr::SUB, 12}, {Expr::LSHIFT, 11},
    {Expr::ARITH_RSHIFT, 11}, {Expr::RSHIFT, 11}, {Expr::LEQ, 10}, {Expr::GEQ, 10}, {Expr::LT, 10},
    {Expr::GT, 10}, {Expr::EQ, 9}, {Expr::NEQ, 9}, {Expr::BAND, 8}, {Expr::BXOR, 7}, {Expr::BOR, 6},
    {Expr::LAND, 5}, {Expr::LOR, 4}, {Expr::TERNARY, 3}, {Expr::ASSIGNMENT, 2}};

const std::unordered_set<Expr> RIGHT_ASSOC = {Expr::PREFIX_INC, Expr::PREFIX_DEC,
    Expr::UNARY_NEGATE, Expr::UNARY_LINVERT, Expr::UNARY_BINVERT, Expr::UNARY_DEREF,
    Expr::UNARY_ADDR, Expr::TERNARY, Expr::ASSIGNMENT, Expr::TERNARY};

}  // namespace

std::unique_ptr<Node> ExprParser::parse() {
  // A top level expression must end either with semicolon (statement), comma (struct/array
  // literal, function call), closing paren (function call), closing brace
  // (compound literal), closing square bracket (array index).
  ExprCtx ec(c_);
  while (!c_.hasTok({Tok::SEMICOLON, Tok::COMMA, Tok::RPAREN, Tok::RBRACE, Tok::RSQUARE})) {
    const auto* tok = c_.curTok();

    switch (tok->type) {
    // TODO(progress): handle bitshift, ternary, and types starting with * or lparen.
    case Tok::LPAREN:
      // If we can do postfix, add function call operation. Otherwise, it's just a paren'd expr.
      c_.consumeTok();
      if (ec.canFinish()) {
        ec.addOp(tok->type);
        ec.addExpr(std::make_unique<FnCallArgs>(c_));
      } else {
        ec.addExpr(parse());
      }
      c_.consumeTok(Tok::RPAREN);
      break;
    case Tok::LSQUARE:
      if (ec.canFinish()) {  // If we can finish it's an array access.
        ec.addOp(tok->type);
        c_.consumeTok();
        ec.addExpr(parse());
        c_.consumeTok(Tok::RSQUARE);
      } else {  // Otherwise it's the start of a type or compound literal.
        ec.pushTypeOrCompoundLit(std::make_unique<Type>(c_));
      }
      break;
    case Tok::LBRACE:
      // finish if we can - handles e.g. if a == b { vs if a == {} {
      if (ec.canFinish()) return ec.finish();
      ec.addExpr(std::make_unique<CompoundLit>(c_));
      break;
    case Tok::IDENT:
      // If it's the name of a type, take type or compound literal.
      // TODO: Need to handle namespaces etc?
      if (c_.types.count(tok->str_val))
        ec.pushTypeOrCompoundLit(std::make_unique<Type>(c_));
      else
        ec.addExpr(std::make_unique<Ref>(c_));
      break;
    case Tok::BOOL_LIT: ec.addExpr(std::make_unique<BoolLit>(c_)); break;
    case Tok::UINT_LIT:  // fallthrough
    case Tok::INT_LIT: ec.addExpr(std::make_unique<IntLit>(c_)); break;
    case Tok::CHAR_LIT: ec.addExpr(std::make_unique<CharLit>(c_)); break;
    case Tok::STR_LIT: ec.addExpr(std::make_unique<StrLit>(c_)); break;
    case Tok::ASTERISK: {
      // Only try to parse as a type if we can't finish here; means that this asterisk
      // should be part of the type. If we can finish, then including the asterisk in
      // the type will put two complete expressions next to each-other.
      // e.g. count * fn(a) vs count * *fn(a).
      if (!ec.canFinish()) {
        if (auto type = Type::tryParseType(c_)) {
          ec.pushTypeOrCompoundLit(std::move(type));
          break;
        }
      }
    }
      // fallthrough
    default:
      ec.addOp(tok->type);
      c_.consumeTok();
      break;
    }
  }
  return ec.finish();
}

std::unique_ptr<Node> ExprParser::ExprCtx::finish() {
  processStack(-1);
  if (s_.size() != 1 || !ops_.empty()) c_.error("error in expression");
  return std::move(s_[0]);
}

void ExprParser::ExprCtx::pushTypeOrCompoundLit(std::unique_ptr<Type> type) {
  // If there is a brace following, it's a compound literal - otherwise, just a type.
  if (c_.hasTok(Tok::LBRACE))
    addExpr(std::make_unique<CompoundLit>(c_, std::move(type)));
  else
    addExpr(std::move(type));
}

void ExprParser::ExprCtx::addOp(Tok::Type type) {
  if (canFinish() && POSTFIX_UNOP_MAP.count(type)) {
    processStack(PRECEDENCE[POSTFIX_UNOP_MAP[type]]);
    ops_.emplace_back(std::make_unique<Op>(c_));
    ops_.back()->type = POSTFIX_UNOP_MAP[type];
  } else if (canFinish() && BINOP_MAP.count(type)) {
    processStack(PRECEDENCE[BINOP_MAP[type]]);
    binop_count++;
    ops_.emplace_back(std::make_unique<Op>(c_));
    ops_.back()->type = BINOP_MAP[type];
    ops_.back()->is_binop = true;
  } else if (PREFIX_UNOP_MAP.count(type)) {
    processStack(PRECEDENCE[PREFIX_UNOP_MAP[type]]);
    ops_.emplace_back(std::make_unique<Op>(c_));
    ops_.back()->type = PREFIX_UNOP_MAP[type];
  } else {
    c_.error("unexpected token: ");
  }
}

bool ExprParser::ExprCtx::shouldPopStack(int precedence) const {
  if (ops_.empty() || s_.empty()) return false;
  return PRECEDENCE[ops_.back()->type] > precedence;  // If precedence goes down, we can pop.
}

void ExprParser::ExprCtx::processStack(int next_precedence) {
  while (shouldPopStack(next_precedence)) {
    const bool is_right = RIGHT_ASSOC.find(ops_.back()->type) != RIGHT_ASSOC.end();
    const int cur_precedence = PRECEDENCE[ops_.back()->type];
    std::vector<std::unique_ptr<Op>> curops;
    std::vector<std::unique_ptr<Node>> curexpr;
    curexpr.emplace_back(std::move(s_.back()));
    s_.pop_back();
    while (!ops_.empty() && PRECEDENCE[ops_.back()->type] == cur_precedence) {
      if (ops_.back()->is_binop) {
        binop_count--;
        if (s_.empty()) c_.error("error in expression");
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

void ExprParser::ExprCtx::collapseOps(
    std::vector<std::unique_ptr<Op>>& ops, std::vector<std::unique_ptr<Node>>& expr) {
  while (!ops.empty()) {
    bug_unless(!expr.empty());
    auto op = std::move(ops.back());
    ops.pop_back();
    if (op->is_binop) {
      op->right = std::move(expr.back());
      expr.pop_back();
    }
    bug_unless(!expr.empty());
    op->left = std::move(expr.back());
    expr.pop_back();
    // Processing in reverse order for left associative, so fix individual node orientations.
    if (op->is_binop && !RIGHT_ASSOC.count(op->type)) std::swap(op->left, op->right);
    expr.push_back(std::move(op));
  }
  if (expr.size() != 1 && !ops.empty()) c_.error("error in expression");
}

}  // namespace memelang::ast
