#ifndef MEMELANG_SCOPE_H
#define MEMELANG_SCOPE_H

#include <cctype>
#include <map>
#include <memory>
#include <variant>
#include <vector>

namespace memelang::interpreter {

struct Type;
struct Val;

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
  std::vector<Qualifier> quals{};  // Holds qualifiers from left to right.
  std::vector<const Type*> params{};

  bool operator==(const Type& o) const { return !(*this < o) && !(o < *this); }
  bool operator!=(const Type& o) const { return (*this < o) || (o < *this); }
  bool operator<(const Type& o) const {
    if (name != o.name) return name < o.name;
    if (quals != o.quals) return quals < o.quals;
    return params < o.params;
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
  ValStorage v{};
  const Type* type{};
};

class Memory {
public:
  Memory();

private:
  constexpr static int STACK_SIZE = 1024 * 1024 * 8;  // 8 MB
  constexpr static int HEAP_SIZE = 1024 * 1024 * 32;  // 32 MB

  std::vector<uint8_t> stack_;
  std::vector<uint8_t> heap_;
};

}  // namespace memelang::interpreter

#endif  // MEMELANG_SCOPE_H
