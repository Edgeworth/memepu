#ifndef MEMELANG_VM_H
#define MEMELANG_VM_H

#include <cctype>
#include <cstring>
#include <map>
#include <memory>
#include <vector>

#include "memelang/constants.h"
#include "verymeme/util.h"

namespace memelang::exec {

using Hnd = int32_t;
constexpr inline Hnd INVALID_HND = -1;

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
  std::vector<Qualifier> quals{};  // Holds qualifiers from right to left.
  std::vector<const Type*> params{};

  bool operator==(const Type& o) const { return !(*this < o) && !(o < *this); }
  bool operator!=(const Type& o) const { return (*this < o) || (o < *this); }
  bool operator<(const Type& o) const {
    if (name != o.name) return name < o.name;
    if (quals != o.quals) return quals < o.quals;
    return params < o.params;
  }

  int size() const {
    // TODO: size of user defined types
    auto iter = BUILTIN_SIZE.find(name);
    if (iter == BUILTIN_SIZE.end()) unimplemented();
    int size = iter->second;
    for (const auto& qual : quals) {
      if (qual.ptr) size = sizeof(Hnd);
      else if (qual.array)
        size *= qual.array;
    }
    return size;
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
  Hnd hnd{INVALID_HND};  // Handle into VM memory.
  const Type* type{nullptr};
};

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
  void write(Val v, const T& data) {
    ::memcpy(&mem_[v.hnd], &data, sizeof(T));
  }

  template <typename T>
  T& ref(Val v) {
    return *reinterpret_cast<T*>(&mem_[v.hnd]);
  }

  void memcpy(Val dst, Val src, int size) { ::memcpy(&mem_[dst.hnd], &mem_[src.hnd], size); }

  void memset(Val dst, uint8_t val, int size) { ::memset(&mem_[dst.hnd], val, size); }

private:
  constexpr static int STACK_SIZE = 1024 * 1024 * 8;  // 8 MB
  constexpr static int HEAP_SIZE = 1024 * 1024 * 32;  // 32 MB
  constexpr static int TMP_SIZE = 1024 * 1024 * 8;  // 8 MB
  constexpr static int STACK_OFFSET = 0;
  constexpr static int HEAP_OFFSET = STACK_OFFSET + STACK_SIZE;
  constexpr static int TMP_OFFSET = HEAP_OFFSET + HEAP_SIZE;

  Exec* exec_;
  std::vector<uint8_t> mem_;
  int stack_ptr_{STACK_OFFSET + STACK_SIZE - 1};  // Stack grows downward.
  int tmp_ptr_{TMP_OFFSET};
};

}  // namespace memelang::exec

#endif  // MEMELANG_VM_H
