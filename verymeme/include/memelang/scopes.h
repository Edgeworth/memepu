#ifndef MEMELANG_SCOPES_H
#define MEMELANG_SCOPES_H

#include <map>
#include <vector>

#include "memelang/vm.h"

namespace memelang::exec {

class Exec;

class ScopeManager {
public:
  explicit ScopeManager(Exec* exec);

  void pushScope();  // Creates new scope-space
  void popScope();
  void nestScope();  // Nests scope inside current scope-space.
  void unnestScope();

  Val maybeGetVar(const std::string& name) const;
  Val getVar(const std::string& name) const;
  Val declareVar(const std::string& name, Val v);

private:
  Exec* exec_;
  std::vector<std::vector<std::map<std::string, Val>>> vars_;
};

}  // namespace memelang::exec

#endif  // MEMELANG_SCOPES_H
