#include "memelang/interpreter.h"

#include <iostream>
#include <memory>

#include "verymeme/util.h"

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

#define CHECK(expr) \
  do { \
    auto val = (expr); \
    if (val) { \
      unnestScope(); \
      return val; \
    } \
  } while (0)

Interpreter::Interpreter(memelang::File* file, const memelang::FileContents* cts)
    : f_(file), cts_(cts) {}

void Interpreter::run() {
  printf("===BEGIN PROGRAM===\n");
  for (auto& fn : f_->fns) {
    // TODO: typelist / fn selection
    fns_[fn->sig->tname->name] = fn.get();
  }
  pushScope();
  runFn(getFn(nullptr, "main"));
  popScope();
}

ValPtr Interpreter::runFn(Fn* fn) { return runStmtBlk(fn->blk.get()); }

ValPtr Interpreter::runStmtBlk(StmtBlk* blk) {
  nestScope();
  for (auto& stmt : blk->stmts) CHECK(runStmt(stmt.get()));
  unnestScope();
  return nullptr;
}

ValPtr Interpreter::runStmt(Node* stmt) {
  if (typeid(*stmt) == typeid(VarDefn)) {
    runVarDefn(g<VarDefn>(stmt));
  } else if (typeid(*stmt) == typeid(VarDecl)) {
    return runVarDecl(g<VarDecl>(stmt));
  } else if (typeid(*stmt) == typeid(Op)) {
    return runOp(g<Op>(stmt));
  } else if (typeid(*stmt) == typeid(For)) {
    return runFor(g<For>(stmt));
  } else if (typeid(*stmt) == typeid(Return)) {
    return eval(g<Return>(stmt)->ret.get());
  } else if (typeid(*stmt) == typeid(If)) {
    return runIf(g<If>(stmt));
  } else {
    error(stmt, "unimplemented statement " + stmt->toString());
  }
  return nullptr;
}

void Interpreter::runVarDefn(VarDefn* defn) {
  auto var = runVarDecl(defn->decl.get());
  if (defn->defn) Val::assign(var, eval(defn->defn.get()));
}

ValPtr Interpreter::runVarDecl(VarDecl* decl) {
  const auto& name = decl->ref->name;
  if (maybeGetVar(name)) error(decl, "redeclaration of var " + name);
  vars_.back().back()[name] = valFromAstType(decl->type.get());
  return vars_.back().back()[name];
}

ValPtr Interpreter::runOp(Op* op) {
  switch (op->type) {
  case Expr::FN_CALL: {
    if (typeid(*(op->left.get())) != typeid(VarRef))
      return std::make_shared<Val>();  // TODO don't skip types
    auto* call = g<VarRef>(op->left);  // TODO can be type.
    auto* args = g<FnCallArgs>(op->right);
    if (call->name == "printf") {
      if (args->args.empty()) error(op, "printf requires at least 1 argument");
      boost::format fmt = boost::format(g<StrLit>(args->args[0])->val);
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
      if (args->args.size() != 2) error(op, "readf requires 2 arguments");
      auto read_ptr = eval(args->args[0].get());
      auto read_sz = eval(args->args[1].get());
      if (*read_ptr->type != Type{.name = U8, .quals = {{}, {.ptr = true}}})
        error(op, "wrong type: " + read_ptr->type->toString());
      if (*read_sz->type != Type{.name = I32})  // TODO: require U32.
        error(op, "wrong type: " + read_sz->type->toString());
      std::cin.getline(
          reinterpret_cast<char*>(std::get<uintptr_t>(read_ptr->v)), std::get<int32_t>(read_sz->v));

      return std::make_shared<Val>(
          Val{.v = int32_t(std::cin.gcount()), .type = std::make_shared<Type>(Type{.name = I32})});
    }

    std::vector<std::shared_ptr<Val>> params;
    for (auto& arg : args->args) params.emplace_back(eval(arg.get()));
    pushScope();
    auto* fn = getFn(call, call->name);
    if (fn->sig->params.size() != params.size()) error(op, "wrong number of arguments");
    for (int i = 0; i < int(fn->sig->params.size()); ++i) {
      auto& decl = fn->sig->params[i];
      runStmt(decl.get());
      Val::assign(getVar(decl->ref.get(), decl->ref->name), params[i]);
    }
    auto val = runFn(fn);
    popScope();
    return val;
  }
  case Expr::ASSIGNMENT: return Val::assign(eval(op->left.get()), eval(op->right.get()));
  case Expr::ADD: return Val::add(eval(op->left.get()), eval(op->right.get()));
  case Expr::SUB: return Val::sub(eval(op->left.get()), eval(op->right.get()));
  case Expr::LT: return Val::lt(eval(op->left.get()), eval(op->right.get()));
  case Expr::EQ: return Val::eq(eval(op->left.get()), eval(op->right.get()));
  case Expr::ARRAY_ACCESS: return Val::array_access(eval(op->left.get()), eval(op->right.get()));
  case Expr::PREFIX_INC: return Val::preinc(eval(op->left.get()));
  case Expr::UNARY_ADDR: return Val::addr(eval(op->left.get()));
  default: error(op, "unhandled op");
  }
  return nullptr;
}

ValPtr Interpreter::runFor(For* fr) {
  runVarDefn(fr->var_defn.get());
  while (std::get<bool>(eval(fr->cond.get())->v)) {
    CHECK(runStmtBlk(fr->blk.get()));
    eval(fr->update.get());
  }
  return nullptr;
}

ValPtr Interpreter::runIf(If* ifst) {
  if (std::get<bool>(eval(ifst->cond.get())->v)) CHECK(runStmtBlk(ifst->then.get()));
  else if (ifst->els)
    CHECK(runStmtBlk(ifst->els.get()));
  return nullptr;
}

ValPtr Interpreter::eval(Node* n) {
  if (typeid(*n) == typeid(Op)) return runOp(g<Op>(n));
  if (typeid(*n) == typeid(VarRef)) return getVar(n, g<VarRef>(n)->name);
  if (typeid(*n) == typeid(IntLit))
    return std::make_shared<Val>(
        Val{.v = int32_t(g<IntLit>(n)->val), .type = std::make_shared<Type>(Type{.name = I32})});
  if (typeid(*n) == typeid(CompoundLit)) {
    auto* lit = g<CompoundLit>(n);
    // TODO set value
    return std::make_shared<Val>(Val{.type = nullptr});  // nullptr for deduced type
  }
  error(n, "unimplemented eval node " + n->toString());
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

Fn* Interpreter::getFn(Node* n, const std::string& name) {
  if (!fns_.count(name)) error(n, "no function " + name);
  return fns_[name];
}

ValPtr Interpreter::getVar(Node* n, const std::string& name) const {
  auto val = maybeGetVar(name);
  if (!val) error(n, "undeclared variable " + name);
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

void Interpreter::error(Node* n, const std::string& msg) const {
  if (n)
    verify_expr(false, "error at '%s' (%d:%d): %s", cts_->getSpan(n->tok.loc, n->tok.size).c_str(),
        cts_->getLineNumber(n->tok.loc), cts_->getColNumber(n->tok.loc), msg.c_str());
  else
    verify_expr(false, "error: %s", msg.c_str());
}

ValPtr Val::assign(ValPtr l, ValPtr r) {
  auto cpy = Val::copy(r);  // Deep copy.
  l->v = cpy->v;
  l->type = cpy->type;
  return l;
}

ValPtr Val::add(ValPtr l, ValPtr r) {
  // TODO: Need to look at type, not variant.
  // TODO: Implement for non-integral.
  auto res = std::visit(overloaded{[&r](auto&& v) -> ValStorage {
    using T = std::decay_t<decltype(v)>;
    if constexpr (std::is_integral<T>::value) return v + std::get<T>(r->v);
    unimplemented();
    return 0;
  }},
      l->v);
  return std::make_shared<Val>(Val{res, std::make_shared<Type>(*l->type)});
}

ValPtr Val::sub(ValPtr l, ValPtr r) {
  // TODO: Implement for non-integral.
  auto res = std::visit(overloaded{[&r](auto&& v) -> ValStorage {
    using T = std::decay_t<decltype(v)>;
    if constexpr (std::is_integral<T>::value) return v - std::get<T>(r->v);
    unimplemented();
    return 0;
  }},
      l->v);
  return std::make_shared<Val>(Val{res, std::make_shared<Type>(*l->type)});
}

ValPtr Val::lt(ValPtr l, ValPtr r) {
  // TODO: Implement for non-integral.
  bool res = std::visit(overloaded{[&r](auto&& v) {
    using T = std::decay_t<decltype(v)>;
    return v < std::get<T>(r->v);
  }},
      l->v);
  return std::make_shared<Val>(Val{res, std::make_shared<Type>(Type{.name = BOOL})});
}

ValPtr Val::eq(ValPtr l, ValPtr r) {
  // TODO: Implement for non-integral.
  bool res = std::visit(overloaded{[&r](auto&& v) {
    using T = std::decay_t<decltype(v)>;
    return v == std::get<T>(r->v);
  }},
      l->v);
  return std::make_shared<Val>(Val{res, std::make_shared<Type>(Type{.name = BOOL})});
}

ValPtr Val::array_access(ValPtr l, ValPtr r) {
  auto& array_val = std::get<ArrayVal>(l->v);
  const int64_t idx = std::get<int32_t>(r->v);  // TODO not only int32 ?
  return array_val[idx];
}

ValPtr Val::preinc(ValPtr l) {
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

ValPtr Val::addr(const ValPtr& l) {
  auto new_type = std::make_shared<Type>(*l->type);
  new_type->quals.emplace_back();
  new_type->quals.back().ptr = true;
  auto new_value = std::make_shared<Val>();
  new_value->v = reinterpret_cast<uintptr_t>(l.get());
  new_value->type = new_type;
  return new_value;
}

ValPtr Val::copy(const ValPtr& l) {
  auto new_storage = std::visit(overloaded{[](auto&& v) -> ValStorage {
    using T = std::decay_t<decltype(v)>;
    if constexpr (std::is_integral<T>::value) return v;
    else if constexpr (std::is_same_v<T, ArrayVal>) {
      ArrayVal arr;
      for (auto& item : v) arr.emplace_back(Val::copy(item));
      return arr;
    } else {
      StructVal strct;
      for (auto& kv : v) strct[kv.first] = Val::copy(kv.second);
      return strct;
    }
  }},
      l->v);

  auto new_type = std::make_shared<Type>(*l->type);
  return std::make_shared<Val>(Val{new_storage, new_type});
}

ValPtr Val::deref(const ValPtr& l) {
  auto new_storage = ValStorage{};
  auto new_type = std::make_shared<Type>(*l->type);
  return std::make_shared<Val>(Val{new_storage, new_type});
}

ValPtr Interpreter::valFromAstType(memelang::Type* ast_type) {
  auto type = typeFromAstType(ast_type);
  std::vector<Qualifier> partial_quals;
  ValPtr val;
  for (const auto& qual : type->quals) {
    partial_quals.emplace_back(qual);
    ValStorage new_storage;
    auto new_type = std::make_shared<Type>(
        Type{.name = type->name, .quals = partial_quals, .params = type->params});

    // Qualifiers only hold one bit of info.
    bug_unless(!(qual.array && qual.ptr));
    if (qual.array) {
      bug_unless(!qual.ptr && val);
      ArrayVal arr;
      for (int idx = 0; idx < qual.array - 1; ++idx) arr.emplace_back(Val::copy(val));
      arr.emplace_back(std::move(val));
      new_storage = std::move(arr);
    } else if (qual.ptr) {
      bug_unless(!qual.array && val);
      unimplemented();
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

    val = std::make_shared<Val>(Val{std::move(new_storage), std::move(new_type)});
  }
  return val;
}

TypePtr Interpreter::typeFromAstType(memelang::Type* type) {
  auto new_type = std::make_shared<Type>();
  new_type->name = type->name;
  new_type->quals.emplace_back();  // Put one qualifier to hold const for the main type.
  new_type->quals.back().cnst = type->cnst;

  // Look through qualifiers reversed.
  for (auto i = type->quals.rbegin(); i != type->quals.rend(); ++i) {
    new_type->quals.emplace_back();
    // TODO not only int32_t
    new_type->quals.back().array = std::get<int32_t>(eval((*i)->array.get())->v);
    new_type->quals.back().ptr = (*i)->ptr;
    new_type->quals.back().cnst = (*i)->cnst;
  }

  for (const auto& param : type->params)
    new_type->params.emplace_back(typeFromAstType(param.get()));
  return new_type;
}

}  // namespace memelang::interpreter
