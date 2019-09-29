#ifndef MEMELANG_INTERPRETER_H
#define MEMELANG_INTERPRETER_H

#include <map>
#include <set>
#include <variant>

#include "memelang/ast.h"

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

const inline static std::string BOOL = "bool";
const inline static std::string I8 = "i8";
const inline static std::string I16 = "i16";
const inline static std::string I32 = "i32";
const inline static std::string U8 = "u8";
const inline static std::string U16 = "u16";
const inline static std::string U32 = "u32";

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

  ValPtr runFn(ast::Fn* fn);
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
  ValPtr eq(ValPtr l, ValPtr r);
  ValPtr neq(ValPtr l, ValPtr r);
  ValPtr array_access(ValPtr l, ValPtr r);
  ValPtr preinc(ValPtr l);
  ValPtr postinc(ValPtr l);
  ValPtr addr(const ValPtr& l);
  ValPtr copy(const ValPtr& l);
  ValPtr deref(const ValPtr& l);
};

}  // namespace memelang::interpreter

#endif  // MEMELANG_INTERPRETER_H
