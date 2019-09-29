#ifndef MEMELANG_INTERPRETER_H
#define MEMELANG_INTERPRETER_H

#include <map>
#include <variant>

#include "memelang/ast.h"

namespace memelang::interpreter {

struct Type;
struct Val;

using TypePtr = std::shared_ptr<Type>;
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

  bool operator==(const Qualifier& o) const {
    return array == o.array && ptr == o.ptr && cnst == o.cnst;
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
  std::vector<TypePtr> params{};

  bool operator==(const Type& o) const {
    if (name != o.name) return false;
    if (quals != o.quals) return false;
    if (params.size() != o.params.size()) return false;
    for (int i = 0; i < int(params.size()); ++i)
      if (*params[i] != *o.params[i]) return false;
    return true;
  }
  bool operator!=(const Type& o) const { return !(*this == o); }

  std::string toString() const {
    std::string rep = "Type(" + name + "; ";
    for (auto i = quals.rbegin(); i != quals.rend(); ++i) rep += i->toString() + ", ";
    rep += ")";
    return rep;
  }
};

// TODO:
struct Typename {
  std::string name{};
};

struct Val {
  ValStorage v{};
  TypePtr type{};

  static ValPtr assign(ValPtr l, ValPtr r);
  static ValPtr add(ValPtr l, ValPtr r);
  static ValPtr sub(ValPtr l, ValPtr r);
  static ValPtr lt(ValPtr l, ValPtr r);
  static ValPtr eq(ValPtr l, ValPtr r);
  static ValPtr neq(ValPtr l, ValPtr r);
  static ValPtr array_access(ValPtr l, ValPtr r);
  static ValPtr preinc(ValPtr l);
  static ValPtr postinc(ValPtr l);
  static ValPtr addr(const ValPtr& l);
  static ValPtr copy(const ValPtr& l);
  static ValPtr deref(const ValPtr& l);
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
  std::map<std::string, ast::Fn*> fns_;
  std::map<std::string, ast::Enum*> enums_;
  std::map<std::string, ast::Intf*> intfs_;
  std::map<std::string, ast::Struct*> structs_;
  std::map<std::string, ast::Impl*> impls_;

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
  void pushScope();  // Creates new scope-space
  void popScope();
  void nestScope();  // Nests scope inside current scope-space.
  void unnestScope();
  ast::Fn* getFn(const std::string& name, ast::Node* n);
  ValPtr getVar(const std::string& name, ast::Node* n) const;
  ValPtr maybeGetVar(const std::string& name) const;

  ValPtr valFromAstType(ast::Type* type);
  TypePtr typeFromAstType(ast::Type* ast_type);

  void error(const std::string& msg, ast::Node* n) const;
};

}  // namespace memelang::interpreter

#endif  // MEMELANG_INTERPRETER_H
