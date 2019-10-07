#ifndef MEMELANG_TYPE_H
#define MEMELANG_TYPE_H

#include <climits>
#include <map>
#include <vector>

namespace memelang::exec {

struct Qualifier {
  int array = 0;
  bool ptr = false;
  bool cnst = false;

  bool operator==(const Qualifier& o) const { return !(*this < o) && !(o < *this); }
  bool operator<(const Qualifier& o) const {
    return std::tie(array, ptr, cnst) < std::tie(o.array, o.ptr, o.cnst);
  }

  std::string toString() const;
};

struct Type {
  constexpr static int NOT_SUBTYPE = INT_MAX / 2;

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

  int size() const;
  int dist(const Type& o) const;  // distance to other type, if subtype.

  std::string toString() const;
};

struct Typename {
  std::string name{};
  std::vector<std::string> tlist{};

  bool operator<(const Typename& o) const {
    return std::tie(name, tlist) < std::tie(o.name, o.tlist);
  }
};

}  // namespace memelang::exec

#endif  // MEMELANG_TYPE_H
