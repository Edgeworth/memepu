#include "memelang/vm.h"

#include "memelang/exec.h"

namespace memelang::exec {

VM::VM(Exec* exec) : exec_(exec) { mem_.resize(STACK_SIZE + HEAP_SIZE + TMP_SIZE); }

Hnd VM::allocStack(int size) {
  stack_ptr_ -= size;
  Hnd hnd = stack_ptr_;
  if (hnd < 0) exec_->error("stack overflow");
  return hnd;
}

void VM::popStack() {
  // TODO
}

Hnd VM::allocTmp(int size) {
  Hnd hnd = tmp_ptr_;
  tmp_ptr_ += size;
  if (hnd >= TMP_OFFSET + TMP_SIZE) exec_->error("out of tmp space");
  return hnd;
}

void VM::expireTmp(Val) {
  // TODO(improvement): Free up memory
}

Hnd VM::mapFn(const FnRef& fn) {
  if (fn_map_.contains(fn)) return fn_map_[fn];
  fn_map_[fn] = allocTmp(sizeof(Hnd));
  write(fn_map_[fn], Hnd(fns_.size()));
  fns_.push_back(fn);
  return fn_map_[fn];
}

FnRef VM::getFn(Hnd hnd) { return fns_[ref<Hnd>(hnd)]; }

}  // namespace memelang::exec
