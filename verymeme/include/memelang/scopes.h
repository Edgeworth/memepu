#ifndef MEMELANG_SCOPES_H
#define MEMELANG_SCOPES_H

#include <map>
#include <vector>

#include "memelang/memory.h"

namespace memelang::interpreter {

class Interpreter;

class ScopeManager {
public:
  explicit ScopeManager(Interpreter* interpreter);

  void pushScope();  // Creates new scope-space
  void popScope();
  void nestScope();  // Nests scope inside current scope-space.
  void unnestScope();

  ValPtr maybeGetVar(const std::string& name) const;
  ValPtr getVar(const std::string& name) const;
  ValPtr declareVar(const std::string& name, ValPtr v);

private:
  Interpreter* interpreter_;
  std::vector<std::vector<std::map<std::string, ValPtr>>> vars_;
};

}  // namespace memelang::interpreter

#endif  // MEMELANG_SCOPES_H
