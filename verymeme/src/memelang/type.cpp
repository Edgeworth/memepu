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
  return q.empty() ? "no quals" : q;
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
  std::string rep = "Type(name: " + name + "; quals: ";
  for (auto i = quals.rbegin(); i != quals.rend(); ++i) rep += i->toString() + ", ";
  rep += "; params: ";
  for (auto i = params.rbegin(); i != params.rend(); ++i) rep += (*i)->toString() + ", ";
  rep += ")";
  return rep;
}

int Type::dist(const Type& o) const {
  printf("Compute dist from %s to %s\n", this->toString().c_str(), o.toString().c_str());
  if (o.name == "T" || o.name == "A" || o.name == "B" || o.name == "I")
    return 0;  // TODO don't do this, also need to handle sizes/etc for wildcards everywhere.
  if (name != o.name) return NOT_SUBTYPE;

  return 0;
}

}  // namespace memelang::exec
