// Copyright 2019 E.
#ifndef MEMECAD_MAPPER_H_
#define MEMECAD_MAPPER_H_

#include <string>
#include <vector>

#include "boost/property_tree/ptree.hpp"
#include "kernel/rtlil.h"
#include "memecad/schematic.h"
#include "memecad/types.h"

namespace memecad {

namespace pt = boost::property_tree;

class Mapper {
 public:
  Mapper() = default;
  Mapper(const std::string& memecad_json, std::vector<Lib> libs);

  void addCell(const Yosys::RTLIL::Cell& cell);
  void addModule(const Yosys::Module& module);
  Schematic& schematic() { return schematic_; }
  bool isMappedModule(const Yosys::RTLIL::Module& module) const;

 private:
  void addMappedModule(const Yosys::RTLIL::Cell& cell, const pt::ptree& mapping);
  void addUnmappedModule(const Yosys::RTLIL::Cell& cell);

  std::vector<Lib> libs_;
  pt::ptree root_;
  Schematic schematic_ = {};
};

}  // namespace memecad

#endif  // MEMECAD_MAPPER_H_
