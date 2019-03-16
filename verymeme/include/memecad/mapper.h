#ifndef VERYMEME_MAPPER_H
#define VERYMEME_MAPPER_H

#include "verymeme/common.h"
#include "memecad/types.h"

namespace memecad {

class Mapper {
public:
  Mapper(const std::string& data, lib_t& lib);

  std::string mapComponents();
private:
  void addComponent(const std::string& kicad_name);

  sheet_t sheet_;
  lib_t& lib_;
};

}  // memecad

#endif  // VERYMEME_MAPPER_H
