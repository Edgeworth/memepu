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
  struct SheetData {
    Sheet sheet = {};
    int pack_x = 1000;
    int pack_y = 1000;
  };

  void addLeafComponent(const Yosys::RTLIL::Cell& cell);

  std::unordered_map<std::string, SheetData> sheet_map_;
  Lib lib_;
  pt::ptree root_;
};

}  // memecad

#endif  // VERYMEME_MAPPER_H
