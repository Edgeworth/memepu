// Copyright 2019 E.
#ifndef MEMECAD_SCHEMATIC_H_
#define MEMECAD_SCHEMATIC_H_

#include <map>
#include <string>
#include <vector>

#include "memecad/types.h"
#include "memecad/util.h"
#include "verymeme/geom.h"

namespace memecad {

class Schematic {
 public:
  struct SchematicFile {
    std::string filename;
    std::string contents;
  };

  void addChildSheetToParent(const std::string& title, const ChildMapping& mapping,
      const std::string& child_name, const std::string& parent_name);
  void addComponentToSheet(const std::string& lib_name, const Lib::Component& lib_component,
      const PinMapping& mapping, const std::string& sheet_name);
  // Each module (sheet) needs some connections inside the module (not just down to child
  // sheets or up to parent sheets) - e.g. for connections between local labels and hierarchical
  // labels or connecting some child sheet pins to unused labels.
  void addModuleConnectionsToSheet(
      const std::string& sheet_name, const std::vector<Yosys::SigSig>& sigs);
  std::vector<SchematicFile> writeHierarchy();

 private:
  struct SheetData {
    SheetData();

    Sheet sheet = {};
    Point cur;
    int64_t max_y = 0;

    Point packBox(Point box_size);
    Point packBoxesOffset(const std::vector<Rect>& rects);
  };

  std::map<std::string, SheetData> sheets_;
};

}  // namespace memecad

#endif  // MEMECAD_SCHEMATIC_H_
