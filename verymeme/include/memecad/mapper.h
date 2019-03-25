#ifndef VERYMEME_MAPPER_H
#define VERYMEME_MAPPER_H

#include "verymeme/common.h"
#include <boost/property_tree/ptree.hpp>
#include <kernel/rtlil.h>
#include "memecad/types.h"
#include "memecad/schematic.h"

namespace memecad {

namespace pt = boost::property_tree;

class Mapper {
public:
  Mapper(const std::string& memecad_json, const Lib& lib);

  void addCell(const Yosys::RTLIL::Cell& cell);
  Schematic& getSchematic() { return schematic_; }

private:
  void addLeafModule(const Yosys::RTLIL::Cell& cell, const pt::ptree& mapping);
  void addNonLeafModule(const Yosys::RTLIL::Cell& cell);

  Lib lib_;
  pt::ptree root_;
  Schematic schematic_;
};

}  // memecad

#endif  // VERYMEME_MAPPER_H
