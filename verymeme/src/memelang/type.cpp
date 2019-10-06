#include "memelang/type.h"

#include "memelang/constants.h"
#include "memelang/vm.h"
#include "verymeme/util.h"

namespace memelang::exec {

std::string Qualifier::toString() const {
  std::string q;
  if (array) q += std::to_string(array);
  if (ptr) q += "ptr";
  if (cnst) q += "const";
  return q;
}

int Type::size() const {
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

std::string Type::toString() const {
  std::string rep = "Type(" + name + "; ";
  for (auto i = quals.rbegin(); i != quals.rend(); ++i) rep += i->toString() + ", ";
  rep += ")";
  return rep;
}

}  // namespace memelang::exec
