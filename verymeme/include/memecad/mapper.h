#ifndef VERYMEME_MAPPER_H
#define VERYMEME_MAPPER_H

#include "verymeme/common.h"
#include <boost/property_tree/ptree.hpp>
#include <kernel/rtlil.h>
#include "memecad/types.h"

namespace memecad {

namespace pt = boost::property_tree;

class Mapper {
public:
  Mapper(const std::string& memecad_json, const Lib& lib);

  void writeHierarchy(const std::string& directory);
  void addComponentFromCell(const Yosys::RTLIL::Cell& cell);

private:
  Sheet sheet_;
  Lib lib_;
  pt::ptree root_;
  int x_ = 1000;
  int y_ = 1000;
};

}  // memecad

#endif  // VERYMEME_MAPPER_H
