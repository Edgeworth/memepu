#include "memelang/interpreter.h"

#include <iostream>
#include <memory>

#include "memelang/constants.h"

namespace memelang::interpreter {

namespace {

template <typename T, typename R>
T* g(R* n) {
  bug_unless(typeid(*n) == typeid(T));
  return reinterpret_cast<T*>(n);
}

template <typename T, typename R>
T* g(std::unique_ptr<R>& n) {
  return g<T>(n.get());
}

}  // namespace

// See if the expression contains a return statement, and return it if it returns.
#define CHECK(expr) \
  do { \
    auto val = (expr); \
    if (val) { \
      unnestScope(); \
      return val; \
    } \
  } while (0)

Interpreter::Interpreter(ast::File* file, const FileContents* cts)
    : f_(file), cts_(cts), bool_(addType({.name = BOOL})), i8_(addType({.name = I8})),
      i16_(addType({.name = I16})), i32_(addType({.name = I32})), i64_(addType({.name = I64})),
      u8_(addType({.name = U8})), u16_(addType({.name = U16})), u32_(addType({.name = U32})),
      u64_(addType({.name = U64})), f32_(addType({.name = F32})), f64_(addType({.name = F64})) {}

void Interpreter::run() {
  printf("===BEGIN PROGRAM===\n");
  for (auto& fn : f_->fns) {
    // TODO: typelist / fn selection
    fns_[typenameFromAst(fn->sig->tname.get())] = fn.get();
  }
  // TODO: Run all these intfs and structs.
  for (auto& enm : f_->enums) {
    if (!enums_.emplace(typenameFromAst(enm->tname.get()), enm.get()).second)
      error("duplicate enum definition", enm.get());
  }
  for (auto& intf : f_->intfs) {
    if (!intfs_.emplace(typenameFromAst(intf->tname.get()), intf.get()).second)
      error("duplicate interface definition", intf.get());
  }
  for (auto& strct : f_->structs) {
    if (!structs_.emplace(typenameFromAst(strct->tname.get()), strct.get()).second)
      error("duplicate struct definition", strct.get());
  }
  for (auto& impl : f_->impls) {
    auto impl_type = typeFromAst(impl->type.get());
    if (!impls_[impl_type].emplace(typeFromAst(impl->tintf.get()), impl.get()).second)
      error("duplicate implementation for (type, interface specialisation) pair", impl.get());
  }

  pushScope();
  runFn(getFn(Typename{.name = "main"}, nullptr), {});
  popScope();
  printf("===END PROGRAM===\n");
}

ValPtr Interpreter::runFn(ast::Fn* fn, const std::vector<ValPtr>& params) {
  pushScope();
  if (fn->sig->params.size() != params.size()) error("wrong number of arguments", fn);
  for (int i = 0; i < int(fn->sig->params.size()); ++i) {
    auto& decl = fn->sig->params[i];
    runStmt(decl.get());
    assign(getVar(decl->ref->name, decl->ref.get()), params[i]);
  }
  auto val = runStmtBlk(fn->blk.get());
  popScope();
  return val;
}

ValPtr Interpreter::runStmtBlk(ast::StmtBlk* blk) {
  nestScope();
  for (auto& stmt : blk->stmts) CHECK(runStmt(stmt.get()));
  unnestScope();
  return nullptr;
}

ValPtr Interpreter::runStmt(ast::Node* stmt) {
  if (typeid(*stmt) == typeid(ast::VarDefn)) {
    runVarDefn(g<ast::VarDefn>(stmt));
  } else if (typeid(*stmt) == typeid(ast::VarDecl)) {
    runVarDecl(g<ast::VarDecl>(stmt));
  } else if (typeid(*stmt) == typeid(ast::Op)) {
    // Ignore return value as there won't ever be a return statement in an op.
    runOp(g<ast::Op>(stmt));
  } else if (typeid(*stmt) == typeid(ast::For)) {
    return runFor(g<ast::For>(stmt));
  } else if (typeid(*stmt) == typeid(ast::While)) {
    return runWhile(g<ast::While>(stmt));
  } else if (typeid(*stmt) == typeid(ast::Return)) {
    return eval(g<ast::Return>(stmt)->ret.get());
  } else if (typeid(*stmt) == typeid(ast::If)) {
    return runIf(g<ast::If>(stmt));
  } else {
    error("unimplemented statement " + stmt->toString(), stmt);
  }
  return nullptr;
}

void Interpreter::runVarDefn(ast::VarDefn* defn) {
  auto var = runVarDecl(defn->decl.get());
  if (defn->defn) assign(var, eval(defn->defn.get()));
}

ValPtr Interpreter::runVarDecl(ast::VarDecl* decl) {
  const auto& name = decl->ref->name;
  if (maybeGetVar(name)) error("redeclaration of var " + name, decl);
  vars_.back().back()[name] = valFromAstType(decl->type.get());
  return vars_.back().back()[name];
}

ValPtr Interpreter::runOp(ast::Op* op) {
  switch (op->type) {
  case ast::Expr::FN_CALL: {
    if (typeid(*(op->left.get())) != typeid(ast::VarRef))
      return std::make_shared<Val>();  // TODO don't skip types
    auto* call = g<ast::VarRef>(op->left);  // TODO can be type.
    auto* args = g<ast::FnCallArgs>(op->right);
    if (call->name == "printf") {
      if (args->args.empty()) error("printf requires at least 1 argument", op);
      boost::format fmt = boost::format(g<ast::StrLit>(args->args[0])->val);
      // TODO(progress): Support other than int vars.
      for (int i = 1; i < int(args->args.size()); ++i)
        std::visit(overloaded{[&fmt](auto&& v) {
          using T = std::decay_t<decltype(v)>;
          if constexpr (std::is_same_v<uintptr_t, T>) fmt = fmt % reinterpret_cast<char*>(v);
          else if constexpr (std::is_integral_v<T>)
            fmt = fmt % v;
          else
            unimplemented();
        }},
            eval(args->args[i].get())->v);
      printf("%s", fmt.str().c_str());

      // TODO: Return proper value.
      return nullptr;
    } else if (call->name == "readf") {
      if (args->args.size() != 2) error("readf requires 2 arguments", op);
      auto read_ptr = eval(args->args[0].get());
      auto read_sz = eval(args->args[1].get());
      if (*read_ptr->type != Type{.name = U8, .quals = {{}, {.ptr = true}}})
        error("wrong type: " + read_ptr->type->toString(), op);
      if (*read_sz->type != *i32_)  // TODO: require U32.
        error("wrong type: " + read_sz->type->toString(), op);
      std::cin.getline(
          reinterpret_cast<char*>(std::get<uintptr_t>(read_ptr->v)), std::get<int32_t>(read_sz->v));

      return std::make_shared<Val>(Val{.v = int32_t(std::cin.gcount()), .type = i32_});
    }

    std::vector<ValPtr> params;
    for (auto& arg : args->args) params.emplace_back(eval(arg.get()));
    auto* fn = getFn(Typename{.name = call->name}, call);
    return runFn(fn, params);
  }
  case ast::Expr::ASSIGNMENT: return assign(eval(op->left.get()), eval(op->right.get()));
  case ast::Expr::ADD: return add(eval(op->left.get()), eval(op->right.get()));
  case ast::Expr::SUB: return sub(eval(op->left.get()), eval(op->right.get()));
  case ast::Expr::LT: return lt(eval(op->left.get()), eval(op->right.get()));
  case ast::Expr::LOR: return lor(eval(op->left.get()), eval(op->right.get()));
  case ast::Expr::EQ: return eq(eval(op->left.get()), eval(op->right.get()));
  case ast::Expr::NEQ: return neq(eval(op->left.get()), eval(op->right.get()));
  case ast::Expr::ARRAY_ACCESS: return array_access(eval(op->left.get()), eval(op->right.get()));
  case ast::Expr::PREFIX_INC: return preinc(eval(op->left.get()));
  case ast::Expr::POSTFIX_INC: return preinc(eval(op->left.get()));
  case ast::Expr::UNARY_ADDR: return addr(eval(op->left.get()));
  default: error("unhandled op", op);
  }
  return nullptr;
}

ValPtr Interpreter::runFor(ast::For* fr) {
  runVarDefn(fr->var_defn.get());
  while (std::get<bool>(eval(fr->cond.get())->v)) {
    CHECK(runStmtBlk(fr->blk.get()));
    eval(fr->update.get());
  }
  return nullptr;
}

ValPtr Interpreter::runWhile(ast::While* wh) {
  while (std::get<bool>(eval(wh->cond.get())->v)) CHECK(runStmtBlk(wh->blk.get()));
  return nullptr;
}

ValPtr Interpreter::runIf(ast::If* ifst) {
  if (std::get<bool>(eval(ifst->cond.get())->v)) CHECK(runStmtBlk(ifst->then.get()));
  else if (ifst->els)
    CHECK(runStmtBlk(ifst->els.get()));
  return nullptr;
}

ValPtr Interpreter::eval(ast::Node* n) {
  if (typeid(*n) == typeid(ast::Op)) return runOp(g<ast::Op>(n));
  if (typeid(*n) == typeid(ast::VarRef)) return getVar(g<ast::VarRef>(n)->name, n);
  if (typeid(*n) == typeid(ast::IntLit))
    return std::make_shared<Val>(Val{.v = int32_t(g<ast::IntLit>(n)->val), .type = i32_});
  if (typeid(*n) == typeid(ast::CompoundLit)) {
    auto* lit = g<ast::CompoundLit>(n);
    // TODO set value
    return std::make_shared<Val>(Val{.type = nullptr});  // nullptr for deduced type
  }
  error("unimplemented eval node " + n->toString(), n);
  return nullptr;
}

ast::Fn* Interpreter::getFn(const Typename& tname, ast::Node* n) {
  if (!fns_.count(tname)) error("no function " + tname.name, n);
  return fns_[tname];
}

ValPtr Interpreter::getVar(const std::string& name, ast::Node* n) const {
  auto val = maybeGetVar(name);
  if (!val) error("undeclared variable " + name, n);
  return val;
}

ValPtr Interpreter::maybeGetVar(const std::string& name) const {
  bug_unless(!vars_.empty());
  for (auto scope_iter = vars_.back().rbegin(); scope_iter != vars_.back().rend(); ++scope_iter) {
    auto iter = scope_iter->find(name);
    if (iter != scope_iter->end()) return iter->second;
  }
  return nullptr;
}

void Interpreter::pushScope() {
  vars_.emplace_back();
  nestScope();
}

void Interpreter::popScope() {
  bug_unless(!vars_.empty());
  vars_.pop_back();
}

void Interpreter::nestScope() { vars_.back().emplace_back(); }

void Interpreter::unnestScope() {
  bug_unless(!vars_.back().empty());
  vars_.back().pop_back();
}

const Type* Interpreter::addType(Type&& t) { return &*types_.insert(std::move(t)).first; }

ValPtr Interpreter::valFromAstType(ast::Type* ast_type) {
  auto type = typeFromAst(ast_type);
  std::vector<Qualifier> partial_quals;
  ValPtr val;
  for (const auto& qual : type->quals) {
    partial_quals.emplace_back(qual);
    ValStorage new_storage;
    const auto* new_type =
        addType({.name = type->name, .quals = partial_quals, .params = type->params});

    // Qualifiers only hold one bit of info.
    bug_unless(!(qual.array && qual.ptr));
    if (qual.array) {
      bug_unless(!qual.ptr && val);
      ArrayVal arr;
      for (int idx = 0; idx < qual.array - 1; ++idx) arr.emplace_back(copy(val));
      arr.emplace_back(std::move(val));
      new_storage = std::move(arr);
    } else if (qual.ptr) {
      bug_unless(!qual.array && val);
      new_storage = uintptr_t(0);
    } else {
      // Handle base type.
      bug_unless(!val);
      if (type->name == BOOL) {
        new_storage = false;
      } else if (type->name == I8) {
        new_storage = int8_t(0);
      } else if (type->name == I16) {
        new_storage = int16_t(0);
      } else if (type->name == I32) {
        new_storage = int32_t(0);
      } else if (type->name == U8) {
        new_storage = uint8_t(0);
      } else if (type->name == U16) {
        new_storage = uint16_t(0);
      } else if (type->name == U32) {
        new_storage = uint32_t(0);
      } else {
        bug_unless(false);
      }
    }

    val = std::make_shared<Val>(Val{std::move(new_storage), new_type});
  }
  return val;
}

const Type* Interpreter::typeFromAst(ast::Type* ast_type) {
  if (ast_type_map_.count(ast_type)) return ast_type_map_[ast_type];

  Type new_type;
  new_type.name = ast_type->name;
  new_type.quals.emplace_back();  // Put one qualifier to hold const for the main type.
  new_type.quals.back().cnst = ast_type->cnst;

  // Look through qualifiers reversed.
  for (auto i = ast_type->quals.rbegin(); i != ast_type->quals.rend(); ++i) {
    new_type.quals.emplace_back();
    // TODO not only int32_t
    new_type.quals.back().array = (*i)->array ? std::get<int32_t>(eval((*i)->array.get())->v) : 0;
    new_type.quals.back().ptr = (*i)->ptr;
    new_type.quals.back().cnst = (*i)->cnst;
  }
  for (const auto& param : ast_type->params) new_type.params.emplace_back(typeFromAst(param.get()));

  ast_type_map_[ast_type] = addType(std::move(new_type));
  return ast_type_map_[ast_type];
}

Typename Interpreter::typenameFromAst(ast::Typename* ast_typename) {
  auto tname = Typename{.name = ast_typename->name};
  if (ast_typename->tlist) tname.tlist = ast_typename->tlist->names;
  return tname;
}

void Interpreter::error(const std::string& msg, ast::Node* n) const {
  if (n)
    verify_expr(false, "error at '%s' (%d:%d): %s", cts_->getSpan(n->tok.loc, n->tok.size).c_str(),
        cts_->getLineNumber(n->tok.loc), cts_->getColNumber(n->tok.loc), msg.c_str());
  else
    verify_expr(false, "error: %s", msg.c_str());
}

ValPtr Interpreter::assign(ValPtr l, ValPtr r) {
  auto cpy = copy(r);  // Deep copy.
  l->v = cpy->v;
  l->type = cpy->type;
  return l;
}

ValPtr Interpreter::add(ValPtr l, ValPtr r) {
  return binop(l, r, l->type, "add", [](auto a, auto b) { return a + b; });
}

ValPtr Interpreter::sub(ValPtr l, ValPtr r) {
  return binop(l, r, l->type, "sub", [](auto a, auto b) { return a - b; });
}

ValPtr Interpreter::lt(ValPtr l, ValPtr r) {
  return binop(l, r, bool_, "lt", [](auto a, auto b) { return a < b; });
}

ValPtr Interpreter::lor(ValPtr l, ValPtr r) {
  return binop(l, r, bool_, "lor", [](auto a, auto b) { return a || b; });
}

ValPtr Interpreter::eq(ValPtr l, ValPtr r) {
  return binop(l, r, bool_, "eq", [](auto a, auto b) { return a == b; });
}

ValPtr Interpreter::neq(ValPtr l, ValPtr r) {
  return binop(l, r, bool_, "neq", [](auto a, auto b) { return a != b; });
}

ValPtr Interpreter::array_access(ValPtr l, ValPtr r) {
  const int64_t idx = std::get<int32_t>(r->v);  // TODO not only int32 ?
  if (auto ptr_val = std::get_if<uintptr_t>(&l->v)) {
    // todo: arrays need to be actually contiguous to do this now? what about valstorage sizes?
  }

  auto& array_val = std::get<ArrayVal>(l->v);
  return array_val[idx];
}

ValPtr Interpreter::preinc(ValPtr l) {
  // TODO: Implement for non-integral.
  std::visit(overloaded{[](auto&& v) {
    using T = std::decay_t<decltype(v)>;
    if constexpr (std::is_integral<T>::value && !std::is_same_v<T, bool>) ++v;
    else
      unimplemented();
  }},
      l->v);
  return l;
}

ValPtr Interpreter::postinc(ValPtr l) {
  auto cp = copy(l);
  // TODO: Implement for non-integral.
  std::visit(overloaded{[](auto&& v) {
    using T = std::decay_t<decltype(v)>;
    if constexpr (std::is_integral<T>::value && !std::is_same_v<T, bool>) ++v;
    else
      unimplemented();
  }},
      l->v);
  return cp;
}

ValPtr Interpreter::addr(const ValPtr& l) {
  auto new_type = *l->type;
  new_type.quals.emplace_back();
  new_type.quals.back().ptr = true;
  auto new_value = std::make_shared<Val>();
  new_value->v = reinterpret_cast<uintptr_t>(l.get());
  new_value->type = addType(std::move(new_type));
  return new_value;
}

ValPtr Interpreter::copy(const ValPtr& l) {
  auto new_storage = std::visit(overloaded{[this](auto&& v) -> ValStorage {
    using T = std::decay_t<decltype(v)>;
    if constexpr (std::is_integral<T>::value) return v;
    else if constexpr (std::is_same_v<T, ArrayVal>) {
      ArrayVal arr;
      for (auto& item : v) arr.emplace_back(copy(item));
      return arr;
    } else {
      StructVal strct;
      for (auto& kv : v) strct[kv.first] = copy(kv.second);
      return strct;
    }
  }},
      l->v);

  return std::make_shared<Val>(Val{new_storage, l->type});
}

ValPtr Interpreter::deref(const ValPtr& l) { return std::make_shared<Val>(Val{{}, l->type}); }

}  // namespace memelang::interpreter
