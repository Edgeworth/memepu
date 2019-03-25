#ifndef VERYMEME_MEMECAD_UTIL_H
#define VERYMEME_MEMECAD_UTIL_H

#include <kernel/rtlil.h>
#include "verymeme/common.h"
#include "memecad/types.h"

namespace memecad {

std::string moduleType(const Yosys::Cell& cell);
std::string moduleName(const Yosys::Cell& cell);
std::string parentModuleType(const Yosys::Cell& cell);

// Describes the connection between a child and parent. A child is either a child sheet or a leaf
// kicad component. A parent is a sheet. For leaf kicad components, child labels are mapped to
// pins in the kicad component via a mapping file.
struct ConnectionData {
  // TODO: Support VCC/GND for parent_label properly.
  std::string parent_label;
  std::string child_label;
  Yosys::RTLIL::SigBit bit;
};

using PinMapping = std::unordered_map<const Lib::Pin*, ConnectionData>;
using ChildMapping = std::unordered_map<std::string, ConnectionData>;

// TODO: moduleTypePath moduleNamePath

}  // namespace memecad

#endif  // VERYMEME_MEMECAD_UTIL_H
