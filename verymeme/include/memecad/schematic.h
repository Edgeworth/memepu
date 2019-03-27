#ifndef VERYMEME_MEMECAD_SCHEMATIC_H
#define VERYMEME_MEMECAD_SCHEMATIC_H

#include "verymeme/common.h"
#include "memecad/types.h"
#include "memecad/util.h"

namespace memecad {

class Schematic {
public:
  struct SchematicFile {
    std::string filename;
    std::string contents;
  };

  explicit Schematic(const Lib& lib) : lib_(lib) {}

  void addChildSheetToParent(const std::string& title, const ChildMapping& mapping,
      const std::string& child_name, const std::string& parent_name);
  void addComponentToSheet(const Lib::Component& lib_component, const PinMapping& mapping,
      const std::string& sheet_name);
  std::vector<SchematicFile> writeHierarchy();

private:
  struct SheetData {
    SheetData();

    Sheet sheet = {};
    Point cur;
    int max_y = 0;

    Point packBox(Point box_size);
  };

  std::unordered_map<std::string, SheetData> sheets_;
  Lib lib_;
};

}  // memecad

#endif  // VERYMEME_MEMECAD_SCHEMATIC_H
