#include "memelang/scopes.h"

#include "memelang/exec.h"
#include "verymeme/util.h"

namespace memelang::exec {

ScopeManager::ScopeManager(Exec* exec) : exec_(exec) {}

void ScopeManager::pushScope() {
  vars_.emplace_back();
  nestScope();
}

void ScopeManager::popScope() {
  bug_unless(!vars_.empty());
  // TODO: Call destructors
  vars_.pop_back();
}

void ScopeManager::nestScope() { vars_.back().emplace_back(); }

void ScopeManager::unnestScope() {
  bug_unless(!vars_.back().empty());
  // TODO: Call destructors
  vars_.back().pop_back();
}

Val ScopeManager::maybeGetVar(const std::string& name) const {
  bug_unless(!vars_.empty());
  for (auto scope_iter = vars_.back().rbegin(); scope_iter != vars_.back().rend(); ++scope_iter) {
    auto iter = scope_iter->find(name);
    if (iter != scope_iter->end()) return iter->second;
  }
  return {};
}

Val ScopeManager::getVar(const std::string& name) const {
  auto val = maybeGetVar(name);
  if (val.hnd == INVALID_HND) exec_->error("undeclared variable " + name);
  return val;
}

Val ScopeManager::declareVar(const std::string& name, Val v) {
  if (maybeGetVar(name).hnd != INVALID_HND) exec_->error("redeclaration of var " + name);
  vars_.back().back()[name] = v;
  return v;
}

}  // namespace memelang::exec
