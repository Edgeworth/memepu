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
  void addCell(const Yosys::RTLIL::Cell& cell);

private:
  // Each module corresponds to a module in verilog. The verilog module is composed of child
  // modules. If a module has no child modules, it must be a leaf module which maps to a Kicad
  // component.
  struct ModuleData {
    Sheet sheet = {};
    int pack_x = 1000;
    int pack_y = 1000;
  };

  void addLeafModule(const Yosys::RTLIL::Cell& cell);
  void addNonLeafModule(const Yosys::RTLIL::Cell& cell);

  std::unordered_map<std::string, ModuleData> modules_;
  Lib lib_;
  pt::ptree root_;
};

}  // memecad

#endif  // VERYMEME_MAPPER_H
