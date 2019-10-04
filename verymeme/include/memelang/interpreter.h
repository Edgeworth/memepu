#ifndef MEMELANG_INTERPRETER_H
#define MEMELANG_INTERPRETER_H

#include <map>
#include <set>
#include <variant>

#include "memelang/ast.h"
#include "verymeme/util.h"

namespace memelang::interpreter {

struct Type;
struct Val;

using ValPtr = std::shared_ptr<Val>;
using PtrVal = uintptr_t;
using ArrayVal = std::vector<ValPtr>;
using StructVal = std::map<std::string, ValPtr>;
using ValStorage = std::variant<bool, int8_t, int16_t, int32_t, uint8_t, uint16_t, uint32_t, PtrVal,
    ArrayVal, StructVal>;

struct Qualifier {
  int array = 0;
  bool ptr = false;
  bool cnst = false;

  bool operator==(const Qualifier& o) const { return !(*this < o) && !(o < *this); }
  bool operator<(const Qualifier& o) const {
    return std::tie(array, ptr, cnst) < std::tie(o.array, o.ptr, o.cnst);
  }

  std::string toString() const {
    std::string q;
    if (array) q += std::to_string(array);
    if (ptr) q += "ptr";
    if (cnst) q += "const";
    return q;
  }
};

struct Type {
  std::string name{};
  std::vector<Qualifier> quals{};  // Holds qualifiers from left to right.
  std::vector<const Type*> params{};

  bool operator==(const Type& o) const { return !(*this < o) && !(o < *this); }
  bool operator!=(const Type& o) const { return (*this < o) || (o < *this); }
  bool operator<(const Type& o) const {
    if (name != o.name) return name < o.name;
    if (quals != o.quals) return quals < o.quals;
    return params < o.params;
  }

  std::string toString() const {
    std::string rep = "Type(" + name + "; ";
    for (auto i = quals.rbegin(); i != quals.rend(); ++i) rep += i->toString() + ", ";
    rep += ")";
    return rep;
  }
};

struct Typename {
  std::string name{};
  std::vector<std::string> tlist{};

  bool operator<(const Typename& o) const {
    return std::tie(name, tlist) < std::tie(o.name, o.tlist);
  }
};

struct Val {
  ValStorage v{};
  const Type* type{};
};

class Interpreter {
public:
  Interpreter(ast::File* file, const FileContents* cts);

  void run();

private:
  ast::File* f_;
  const FileContents* cts_;

  std::vector<std::vector<std::map<std::string, ValPtr>>> vars_;
  std::map<const ast::Type*, const Type*> ast_type_map_;
  std::set<Type> types_;
  std::map<Typename, ast::Fn*> fns_;
  std::map<Typename, ast::Enum*> enums_;
  std::map<Typename, ast::Intf*> intfs_;
  std::map<Typename, ast::Struct*> structs_;
  // Map from a type (may be set) to mapping from interface to the impl.
  std::map<const Type*, std::map<const Type*, ast::Impl*>> impls_;

  // Built-in types
  const Type* bool_;
  const Type* i8_;
  const Type* i16_;
  const Type* i32_;
  const Type* i64_;
  const Type* u8_;
  const Type* u16_;
  const Type* u32_;
  const Type* u64_;
  const Type* f32_;
  const Type* f64_;

  ValPtr runFn(ast::Fn* fn, const std::vector<ValPtr>& args);
  ValPtr runStmtBlk(ast::StmtBlk* blk);
  ValPtr runStmt(ast::Node* stmt);
  void runVarDefn(ast::VarDefn* defn);
  ValPtr runVarDecl(ast::VarDecl* decl);
  ValPtr runFor(ast::For* fr);
  ValPtr runWhile(ast::While* wh);
  ValPtr runIf(ast::If* ifst);
  ValPtr runOp(ast::Op* op);

  ValPtr eval(ast::Node* n);
  ast::Fn* getFn(const Typename& tname, ast::Node* n);
  ValPtr getVar(const std::string& name, ast::Node* n) const;
  ValPtr maybeGetVar(const std::string& name) const;

  void pushScope();  // Creates new scope-space
  void popScope();
  void nestScope();  // Nests scope inside current scope-space.
  void unnestScope();
  const Type* addType(Type&& t);
  void error(const std::string& msg, ast::Node* n) const;

  ValPtr valFromAstType(ast::Type* type);
  const Type* typeFromAst(ast::Type* ast_type);
  Typename typenameFromAst(ast::Typename* ast_typename);

  // Value operations:
  ValPtr assign(ValPtr l, ValPtr r);
  ValPtr add(ValPtr l, ValPtr r);
  ValPtr sub(ValPtr l, ValPtr r);
  ValPtr lt(ValPtr l, ValPtr r);
  ValPtr lor(ValPtr l, ValPtr r);
  ValPtr eq(ValPtr l, ValPtr r);
  ValPtr neq(ValPtr l, ValPtr r);
  ValPtr array_access(ValPtr l, ValPtr r);
  ValPtr preinc(ValPtr l);
  ValPtr postinc(ValPtr l);
  ValPtr addr(const ValPtr& l);
  ValPtr copy(const ValPtr& l);
  ValPtr deref(const ValPtr& l);

  template <typename F>
  ValPtr binop(ValPtr l, ValPtr r, const Type* type, const std::string& op_name, F default_op) {
    // Look in impls for l's type
    // TODO: Generalise look-up procedure, define rules for lookup.
    auto impl_iter = impls_.find(l->type);
    if (impl_iter != impls_.end()) {
      for (const auto& [impl_type, impl] : impl_iter->second) {
        if (impl_type->name != "Comparable") continue;
        if (impl->tintf->params.size() != 1) continue;
        if (typeFromAst(impl->tintf->params[0].get()) != r->type) continue;
        for (const auto& fn : impl->fns) {
          if (fn->sig->tname->name == op_name) { return runFn(fn.get(), {r}); }
        }
      }
    }
    ValStorage res = std::visit(overloaded{[this, &r, &default_op](auto&& v) {
      using T = std::decay_t<decltype(v)>;
      if constexpr (std::is_integral_v<T>) return ValStorage{default_op(v, std::get<T>(r->v))};
      error("no matching operator for values", nullptr);
      return ValStorage{};
    }},
        l->v);
    return std::make_shared<Val>(Val{res, type});
  }
};

}  // namespace memelang::interpreter

#endif  // MEMELANG_INTERPRETER_H
