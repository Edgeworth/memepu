#include "memelang/scopes.h"

#include "memelang/interpreter.h"
#include "verymeme/util.h"

namespace memelang::interpreter {

ScopeManager::ScopeManager(Interpreter* interpreter) : interpreter_(interpreter) {}

void ScopeManager::pushScope() {
  vars_.emplace_back();
  nestScope();
}

void ScopeManager::popScope() {
  bug_unless(!vars_.empty());
  vars_.pop_back();
}

void ScopeManager::nestScope() { vars_.back().emplace_back(); }

void ScopeManager::unnestScope() {
  bug_unless(!vars_.back().empty());
  vars_.back().pop_back();
}

ValPtr ScopeManager::maybeGetVar(const std::string& name) const {
  bug_unless(!vars_.empty());
  for (auto scope_iter = vars_.back().rbegin(); scope_iter != vars_.back().rend(); ++scope_iter) {
    auto iter = scope_iter->find(name);
    if (iter != scope_iter->end()) return iter->second;
  }
  return nullptr;
}

ValPtr ScopeManager::getVar(const std::string& name) const {
  auto val = maybeGetVar(name);
  if (!val) interpreter_->error("undeclared variable " + name);
  return val;
}

ValPtr ScopeManager::declareVar(const std::string& name, ValPtr v) {
  if (maybeGetVar(name)) interpreter_->error("redeclaration of var " + name);
  vars_.back().back()[name] = v;
  return v;
}

}  // namespace memelang::interpreter
