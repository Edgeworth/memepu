#include "memelang/memory.h"

namespace memelang::interpreter {

Memory::Memory() {
  stack_.resize(STACK_SIZE);
  heap_.resize(HEAP_SIZE);
}

}  // namespace memelang::interpreter
