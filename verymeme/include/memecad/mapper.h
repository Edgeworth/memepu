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
  Mapper(const std::string& memecad_json, const std::vector<Lib>& libs);

  void addCell(const Yosys::RTLIL::Cell& cell);
  Schematic& getSchematic() { return schematic_; }

  void addModule(const Yosys::Module& module);
private:
  void addMappedModule(const Yosys::RTLIL::Cell& cell, const pt::ptree& mapping);
  void addUnmappedModule(const Yosys::RTLIL::Cell& cell);

  std::vector<Lib> libs_;
  pt::ptree root_;
  Schematic schematic_ = {};
};

}  // memecad

#endif  // VERYMEME_MAPPER_H
