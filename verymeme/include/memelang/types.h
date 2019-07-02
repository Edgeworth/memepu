#ifndef MEMELANG_TYPES_H
#define MEMELANG_TYPES_H

#include "verymeme/common.h"
#include "memelang/compile.h"

namespace memelang {

#define DEFNLT(type, ...) \
  auto getTie() const { return std::tie(__VA_ARGS__); } \
  bool operator<(const type& o) const { return getTie() < o.getTie(); }

struct Type {
  std::string name;
  bool pointer = false;
  std::vector<Type> templates;

  DEFNLT(Type, name, pointer, templates);
};

struct Variable {
  Type type;
  std::string name;

  DEFNLT(Variable, type, name);
};

struct FuncSig {
  std::string name;
  std::vector<std::string> templates;
  Type return_type;
  std::vector<Variable> params;
  bool is_static = false;

  DEFNLT(FuncSig, name, templates, return_type, params, is_static);
};

struct Func {
  FuncSig sig;
  const Parser::Node* defn = nullptr;

  DEFNLT(Func, sig, defn);
};

struct Struct {
  std::string name;
  std::vector<std::string> templates;
  std::vector<Func> funcs;
  std::vector<Variable> vars;

  DEFNLT(Struct, name, templates, funcs, vars);
};

struct Interface {
  std::string name;
  std::vector<std::string> templates;
  std::vector<FuncSig> funcs;

  DEFNLT(Interface, name, templates, funcs);
};

#undef DEFNLT

const Type INT8 = {"int8", false, {}};
const Type INT16 = {"int16", false, {}};
const Type UINT8 = {"uint8", false, {}};
const Type UINT16 = {"uint16", false, {}};

}  // namespace meme

#endif  // MEMELANG_TYPES_H
