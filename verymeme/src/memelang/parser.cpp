#include "memelang/parser.h"

#include <climits>
#include <numeric>
#include <unordered_map>

#include "verymeme/string_util.h"
#include "verymeme/util.h"

namespace memelang {

using fmt = boost::format;

namespace {

const std::vector<Token::Type> BUILTIN_TYPES = {Token::AUTO, Token::I8, Token::I16, Token::I32,
    Token::U8, Token::U16, Token::U32, Token::BOOL, Token::BIT};

void fcInternal(std::vector<Node*>&) {}

template <typename T, typename... Args>
void fcInternal(std::vector<Node*>& cs, const T& head, const Args&... tail) {
  if constexpr (std::is_assignable_v<T, nullptr_t>) {
    if (head) cs.push_back(head.get());
  } else {
    for (const auto& p : head) {
      verify_expr(p != nullptr, "BUG");
      cs.push_back(p.get());
    }
  }
  fcInternal(cs, tail...);
}

template <typename... Args>
std::vector<Node*> flattenChildren(const Args&... args) {
  std::vector<Node*> cs;
  fcInternal(cs, args...);
  return cs;
}

}  // namespace

struct Parser::Context {
  const FileContents* contents;
  std::vector<Token> toks;
  int idx;

  const Token* curToken() const { return curToken(std::vector<Token::Type>{}); }
  const Token* curToken(Token::Type type) const { return curToken(std::vector<Token::Type>{type}); }
  const Token* curToken(const std::vector<Token::Type>& ts) const {
    if (!hasToken()) compileError("unexpected end of file");
    const auto* token = &toks[idx];
    if (!hasToken(ts))
      compileError("unexpected token, must be one of " +
          std::accumulate(ts.begin(), ts.end(), std::string(),
              [](const auto& a, const auto& b) { return tos(a) + tos(b) + ", "; }));
    return token;
  }

  const Token* consumeToken() { return consumeToken(std::vector<Token::Type>{}); }
  const Token* consumeToken(Token::Type type) {
    return consumeToken(std::vector<Token::Type>{type});
  }
  const Token* consumeToken(const std::vector<Token::Type>& ts) {
    const auto* token = curToken(ts);
    idx++;
    return token;
  }
  bool maybeConsumeToken(Token::Type type) {
    const Token* token = curToken();
    if (token->type == type) {
      idx++;
      return true;
    }
    return false;
  }

  bool hasToken() const { return hasToken(std::vector<Token::Type>{}); }
  bool hasToken(Token::Type type) const { return hasToken(std::vector<Token::Type>{type}); }
  bool hasToken(const std::vector<Token::Type>& ts) const {
    if (idx >= int(toks.size())) return false;
    if (ts.empty()) return true;
    const auto& token = toks[idx];
    return std::any_of(ts.begin(), ts.end(), [token](auto type) { return token.type == type; });
  }

  void compileError(const std::string& msg) const {
    std::string loc = "eof";
    if (hasToken()) {
      const auto* token = curToken();
      loc = (fmt("%d:%d - \"%s\"") % contents->getLineNumber(token->loc) %
          contents->getColNumber(token->loc) % token->toString(contents))
                .str();
    }
    throw std::runtime_error(
        (fmt("compile error at %s: %s\n%s") % loc % msg % getStacktrace()).str());
  }
};

namespace {

std::unordered_map<Token::Type, Expr::Type> BINOP_MAP = {
    {Token::DOT, Expr::MEMBER_ACCESS}, {Token::PLUS, Expr::ADD}, {Token::ASTERISK, Expr::MUL}};

// TODO how to decide if postfix/prefix.
std::unordered_map<Token::Type, Expr::Type> UNOP_MAP = {
    {Token::DPLUS, Expr::POSTFIX_INC}
};

std::unordered_map<Expr::Type, int> PRECEDENCE = {
    {Expr::ARRAY_ACCESS, 15},
    {Expr::MEMBER_ACCESS, 15},
    {Expr::FN_CALL, 15},
    {Expr::POSTFIX_INC, 15},
    {Expr::POSTFIX_DEC, 15},
    {Expr::PREFIX_INC, 14},
    {Expr::PREFIX_DEC, 14},
    {Expr::UNARY_NEGATE, 14},
    {Expr::UNARY_LINVERT, 14},
    {Expr::UNARY_BINVERT, 14},
    {Expr::UNARY_DEREF, 14},
    {Expr::UNARY_ADDR, 14},
    {Expr::MUL, 13},
    {Expr::DIV, 13},
    {Expr::MOD, 13},
    {Expr::ADD, 12},
    {Expr::SUB, 12},
    {Expr::LSHIFT, 11},
    {Expr::ARITH_RSHIFT, 11},
    {Expr::RSHIFT, 11},
    {Expr::LEQ, 10},
    {Expr::GEQ, 10},
    {Expr::LT, 10},
    {Expr::GT, 10},
    {Expr::EQ, 9},
    {Expr::NEQ, 9},
    {Expr::BAND, 8},
    {Expr::BXOR, 7},
    {Expr::BOR, 6},
    {Expr::LAND, 5},
    {Expr::LOR, 4},
    {Expr::TERNARY, 3},
    {Expr::ASSIGNMENT, 2},
};

const std::unordered_set<Expr::Type> RIGHT_ASSOC = {
    Expr::PREFIX_INC,
    Expr::PREFIX_DEC,
    Expr::UNARY_NEGATE,
    Expr::UNARY_LINVERT,
    Expr::UNARY_BINVERT,
    Expr::UNARY_DEREF,
    Expr::UNARY_ADDR,
    Expr::TERNARY,
    Expr::ASSIGNMENT,
};

class ExpressionParser {
public:
  explicit ExpressionParser(Parser::Context& ctx) : ctx_(ctx) {}

  std::unique_ptr<Expr> parse() {
    // A top level expression must end either with semicolon (statement), opening brace
    // (for, if, match), comma (struct/array literal, function call), closing paren
    // (function call), closing brace (struct literal), closing square bracket (array
    // literal).
    ExprCtx ectx;
    while (!ctx_.hasToken({Token::SEMICOLON, Token::LBRACE, Token::COMMA, Token::RPAREN,
        Token::RBRACE, Token::RSQUARE})) {
      const auto* tok = ctx_.curToken();
      switch (tok->type) {
      case Token::LPAREN: {
        // TODO: determine if FN call or just paren'd expr.
        ctx_.consumeToken();
        ectx.s.emplace_back(parse());
        ctx_.consumeToken(Token::RPAREN);
        continue;
      }
      case Token::IDENT: ectx.s.emplace_back(std::make_unique<VarRef>(ctx_)); continue;
      case Token::BOOL_LIT: ectx.s.emplace_back(std::make_unique<BoolLit>(ctx_)); continue;
      case Token::INT_LIT: ectx.s.emplace_back(std::make_unique<IntLit>(ctx_)); continue;
      case Token::CHAR_LIT: ectx.s.emplace_back(std::make_unique<CharLit>(ctx_)); continue;
      case Token::STR_LIT: ectx.s.emplace_back(std::make_unique<StrLit>(ctx_)); continue;
      default: break;
      }
      // TODO(fix)
//      if (EXPR_MAP.find(tok->type) != EXPR_MAP.end()) {
//        ectx.processStack(PRECEDENCE[EXPR_MAP[tok->type]], ctx_);
//        ectx.ops.emplace_back(std::make_unique<BinOp>(ctx_));
//      } else {
//        ctx_.compileError("unexpected token");
//      }
    }
    ectx.processStack(-1, ctx_);
    if (ectx.s.size() != 1 || !ectx.ops.empty()) ctx_.compileError("error in expression");
    return std::move(ectx.s[0]);
  }

private:
  Parser::Context& ctx_;

  class ExprCtx {
  public:
    std::vector<std::unique_ptr<Expr>> s = {};
    std::vector<std::unique_ptr<BinOp>> ops = {};

    void processStack(int next_precedence, Parser::Context& ctx) {
      while (shouldPopStack(next_precedence)) {
        const bool is_right = RIGHT_ASSOC.find(ops.back()->type) != RIGHT_ASSOC.end();
        const int cur_precedence = PRECEDENCE[ops.back()->type];
        std::vector<std::unique_ptr<BinOp>> curops;
        std::vector<std::unique_ptr<Expr>> curexpr;
        curexpr.emplace_back(std::move(s.back()));
        s.pop_back();
        while (!ops.empty() && PRECEDENCE[ops.back()->type] == cur_precedence) {
          // TODO: ONly push back expr if it's a binary op.
          if (s.empty()) ctx.compileError("error in expression");
          curexpr.emplace_back(std::move(s.back()));
          curops.emplace_back(std::move(ops.back()));
          s.pop_back();
          ops.pop_back();
        }
        if (is_right) {
          curops = reverse(std::move(curops));
          curexpr = reverse(std::move(curexpr));
        }
        collapseOps(curops, curexpr, ctx);
        s.emplace_back(std::move(curexpr[0]));
      }
    }

  private:
    bool shouldPopStack(int precedence) const {
      if (ops.empty() || s.empty()) return false;
      return PRECEDENCE[ops.back()->type] > precedence;  // If precedence goes down, we can pop.
    }

    static void collapseOps(std::vector<std::unique_ptr<BinOp>>& ops,
        std::vector<std::unique_ptr<Expr>>& expr, Parser::Context& ctx) {
      while (!ops.empty()) {
        verify_expr(expr.size() >= 2u, "BUG");
        auto op = std::move(ops.back());
        ops.pop_back();
        op->right = std::move(expr.back());
        expr.pop_back();
        op->left = std::move(expr.back());
        expr.pop_back();
        expr.push_back(std::move(op));
      }
      if (expr.size() != 1) ctx.compileError("error in expression");
    }
  };
};

}  // namespace

std::ostream& operator<<(std::ostream& str, const Expr::Type& o) {
  const static std::string EXPR_TYPES[] = {"ARRAY_ACCESS", "MEMBER_ACCESS", "FN_CALL",
      "POSTFIX_INC", "POSTFIX_DEC", "PREFIX_INC", "PREFIX_DEC", "UNARY_NEGATE", "UNARY_LINVERT",
      "UNARY_BINVERT", "UNARY_DEREF", "UNARY_ADDR", "MUL", "DIV", "MOD", "ADD", "SUB", "LSHIFT",
      "ARITH_RSHIFT", "RSHIFT", "LEQ", "GEQ", "LT", "GT", "EQ", "NEQ", "BAND", "BXOR", "BOR",
      "LAND", "LOR", "TERNARY", "ASSIGNMENT"};

  return outputEnum(str, o, EXPR_TYPES);
}

Parser::Parser(const FileContents* contents, std::vector<Token> tokens)
    : ctx_(new Context{contents, std::move(tokens), 0}), root_() {}

Parser::~Parser() = default;

bool Parser::parse() {
  try {
    root_ = std::make_unique<File>(*ctx_);
  } catch (const std::exception& e) { verify_expr(false, "%s\n", e.what()); }
  return true;
}

std::string Parser::astToString() {
  verify_expr(root_ != nullptr, "null root");
  std::string s;
  root_->visit(
      [&s](Node& n, int depth) { s += std::string(uint64_t(depth), ' ') + n.toString() + "\n"; });
  return s;
}

BoolLit::BoolLit(Parser::Context& ctx) { val = bool(ctx.consumeToken(Token::BOOL_LIT)->int_val); }
std::string BoolLit::toString() const {
  return (fmt("BoolLit(%s)") % (val ? "true" : "false")).str();
}
std::vector<Node*> BoolLit::children() { return {}; }
void BoolLit::generateIr() const {}

IntLit::IntLit(Parser::Context& ctx) { val = ctx.consumeToken(Token::INT_LIT)->int_val; }
std::string IntLit::toString() const { return (fmt("IntLit(%d)") % val).str(); }
std::vector<Node*> IntLit::children() { return {}; }
void IntLit::generateIr() const {}

CharLit::CharLit(Parser::Context& ctx) {
  val = int32_t(ctx.consumeToken(Token::CHAR_LIT)->int_val);
}
std::string CharLit::toString() const { return (fmt("CharLit(%c)") % val).str(); }
std::vector<Node*> CharLit::children() { return {}; }
void CharLit::generateIr() const {}

StrLit::StrLit(Parser::Context& ctx) { val = ctx.consumeToken(Token::STR_LIT)->str_val; }
std::string StrLit::toString() const { return (fmt("StrLit(%s)") % val).str(); }
std::vector<Node*> StrLit::children() { return {}; }
void StrLit::generateIr() const {}

BinOp::BinOp(Parser::Context& ctx) { /*type = EXPR_MAP[ctx.consumeToken()->type];*/ } // TODO(fix)
std::string BinOp::toString() const { return (fmt("BinOp(%s)") % type).str(); }
std::vector<Node*> BinOp::children() { return flattenChildren(left, right); }
void BinOp::generateIr() const {}

VarRef::VarRef(Parser::Context& ctx) {
  name = ctx.consumeToken(Token::IDENT)->toString(ctx.contents);
}
std::string VarRef::toString() const { return (fmt("VarRef(%s)") % name).str(); }
std::vector<Node*> VarRef::children() { return {}; }
void VarRef::generateIr() const {}

Typelist::Typelist(Parser::Context& ctx) {
  ctx.consumeToken(Token::LANGLE);
  while (true) {
    names.push_back(ctx.consumeToken(Token::IDENT)->toString(ctx.contents));
    if (ctx.hasToken(Token::COMMA)) ctx.consumeToken();
    else
      break;
  }
  ctx.consumeToken(Token::RANGLE);
}

std::string Typelist::toString() const { return "Typelist"; }
std::vector<Node*> Typelist::children() { return {}; }
void Typelist::generateIr() const {}

Typename::Typename(Parser::Context& ctx) {
  name = ctx.consumeToken(Token::IDENT)->toString(ctx.contents);
  if (ctx.hasToken(Token::LANGLE)) tlist = std::make_unique<Typelist>(ctx);
}
std::string Typename::toString() const { return (fmt("Typename %s") % name).str(); }
std::vector<Node*> Typename::children() { return flattenChildren(tlist); }
void Typename::generateIr() const {}

Qualifier::Qualifier(Parser::Context& ctx) {
  if (ctx.hasToken(Token::LSQUARE)) {
    ctx.consumeToken(Token::LSQUARE);
    array = ctx.consumeToken(Token::INT_LIT)->int_val;
    ctx.consumeToken(Token::RSQUARE);
  } else {
    if (ctx.maybeConsumeToken(Token::CONST)) cnst = true;
    ptr = true;
    ctx.consumeToken(Token::ASTERISK);
  }
}
std::string Qualifier::toString() const { return "Qualifier"; }
std::vector<Node*> Qualifier::children() { return {}; }
void Qualifier::generateIr() const {}

Type::Type(Parser::Context& ctx) {
  while (ctx.hasToken({Token::ASTERISK, Token::LSQUARE}))
    quals.emplace_back(std::make_unique<Qualifier>(ctx));
  cnst = ctx.maybeConsumeToken(Token::CONST);
  if (ctx.hasToken(Token::IDENT)) {
    name = ctx.consumeToken(Token::IDENT)->toString(ctx.contents);
    if (ctx.hasToken(Token::LANGLE)) {
      ctx.consumeToken(Token::LANGLE);
      while (ctx.curToken()->type != Token::RANGLE) {
        params.emplace_back(std::make_unique<Type>(ctx));
        if (!ctx.maybeConsumeToken(Token::COMMA)) break;
      }
      ctx.consumeToken(Token::RANGLE);
    }
  } else {
    name = ctx.consumeToken(BUILTIN_TYPES)->toString(ctx.contents);
  }
}
std::string Type::toString() const { return (fmt("Type %s") % name).str(); }
std::vector<Node*> Type::children() { return flattenChildren(quals, params); }
void Type::generateIr() const {}

FnVarDecl::FnVarDecl(Parser::Context& ctx) {
  name = ctx.consumeToken(Token::IDENT)->toString(ctx.contents);
  ctx.consumeToken(Token::COLON);
  type = std::make_unique<Type>(ctx);
}
std::string FnVarDecl::toString() const { return (fmt("FnVarDecl %s") % name).str(); }
std::vector<Node*> FnVarDecl::children() { return {type.get()}; }
void FnVarDecl::generateIr() const {}

FnSig::FnSig(Parser::Context& ctx) {
  ctx.consumeToken(Token::FN);
  tname = std::make_unique<Typename>(ctx);
  ctx.consumeToken(Token::LPAREN);
  while (ctx.curToken()->type != Token::RPAREN) {
    params.emplace_back(std::make_unique<FnVarDecl>(ctx));
    if (!ctx.maybeConsumeToken(Token::COMMA)) break;
  }
  ctx.consumeToken(Token::RPAREN);
  ret_type = std::make_unique<Type>(ctx);
}
std::string FnSig::toString() const { return "FnSig"; }
std::vector<Node*> FnSig::children() { return flattenChildren(tname, params, ret_type); }
void FnSig::generateIr() const {}

StmtBlk::StmtBlk(Parser::Context& ctx) {
  ctx.consumeToken(Token::LBRACE);
  while (!ctx.hasToken(Token::RBRACE)) {
    // TODO(Progress): var defn, decl, ret, for, if, match, asm
    ExpressionParser parser(ctx);
    stmts.emplace_back(parser.parse());
    ctx.consumeToken(Token::SEMICOLON);
  }
  ctx.consumeToken(Token::RBRACE);
}
std::string StmtBlk::toString() const { return "StmtBlk"; }
std::vector<Node*> StmtBlk::children() { return flattenChildren(stmts); }
void StmtBlk::generateIr() const {}

FnDefn::FnDefn(Parser::Context& ctx) {
  sig = std::make_unique<FnSig>(ctx);
  blk = std::make_unique<StmtBlk>(ctx);
}
std::string FnDefn::toString() const { return "FnDefn"; }
std::vector<Node*> FnDefn::children() { return flattenChildren(sig, blk); }
void FnDefn::generateIr() const {}

IntfDefn::IntfDefn(Parser::Context& ctx) {
  ctx.consumeToken(Token::INTF);
  tname = std::make_unique<Typename>(ctx);
  ctx.consumeToken(Token::LBRACE);
  while (ctx.hasToken(Token::FN)) {
    decls.emplace_back(std::make_unique<FnSig>(ctx));
    ctx.consumeToken(Token::SEMICOLON);
  }
  ctx.consumeToken(Token::RBRACE);
}
std::string IntfDefn::toString() const { return "Intf"; }
std::vector<Node*> IntfDefn::children() { return flattenChildren(decls); }
void IntfDefn::generateIr() const {}

File::File(Parser::Context& ctx) {
  while (ctx.hasToken()) {
    const auto* token = ctx.curToken({Token::INTF, Token::FN});
    if (token->type == Token::INTF) {
      intf_defns.emplace_back(std::make_unique<IntfDefn>(ctx));
    } else if (token->type == Token::FN) {
      fn_defns.emplace_back(std::make_unique<FnDefn>(ctx));
    }
  }
}
std::string File::toString() const { return "File"; }
std::vector<Node*> File::children() { return flattenChildren(intf_defns, fn_defns); }
void File::generateIr() const {}

}  // namespace memelang
