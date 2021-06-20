// Copyright 2019 E.
#ifndef MEMELANG_VM_H
#define MEMELANG_VM_H

#include <cstdint>
#include <cstring>

#include "memelang/type.h"

namespace memelang::exec {

class Exec;

class VM {
public:
  explicit VM(Exec* exec);

  Hnd allocStack(int size);
  void popStack();
  Hnd allocTmp(int size);
  void expireTmp(Val tmp);

  // T should be packed.
  template <typename T>
  void write(Hnd hnd, const T& data) {
    ::memcpy(&mem_[hnd], &data, sizeof(T));
  }

  template <typename T>
  T& ref(Hnd hnd) {
    return *reinterpret_cast<T*>(&mem_[hnd]);
  }

  void memcpy(Val dst, Val src, int size) { ::memcpy(&mem_[dst.hnd], &mem_[src.hnd], size); }
  void memset(Val dst, uint8_t val, int size) { ::memset(&mem_[dst.hnd], val, size); }

private:
  constexpr static int STACK_SIZE = 1024 * 512;  // 512 KiB
  constexpr static int HEAP_SIZE = 1024 * 512;  // 512 KiB
  constexpr static int TMP_SIZE = 1024 * 512;  // 512 KiB
  constexpr static int STACK_OFFSET = 0;
  constexpr static int HEAP_OFFSET = STACK_OFFSET + STACK_SIZE;
  constexpr static int TMP_OFFSET = HEAP_OFFSET + HEAP_SIZE;

  int stack_ptr_{STACK_OFFSET + STACK_SIZE - 1};  // Stack grows downward.
  int tmp_ptr_{TMP_OFFSET};
  Exec* exec_;
  std::vector<uint8_t> mem_;
};

}  // namespace memelang::exec

#endif  // MEMELANG_VM_H
