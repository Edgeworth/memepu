// Copyright 2019 E.
#ifndef MEMECAD_UTIL_H_
#define MEMECAD_UTIL_H_

#include <map>
#include <string>

#include "kernel/rtlil.h"
#include "memecad/types.h"

namespace memecad {

std::string moduleType(const Yosys::Cell& cell);
std::string moduleName(const Yosys::Cell& cell);
std::string moduleName(const Yosys::Module& module);
std::string parentModuleType(const Yosys::Cell& cell);
std::string modulePath(const Yosys::Cell& cell);
// Gets representative id (label) for a SigBit. This may be empty for a no-connect.
std::string getIdForSigBit(const Yosys::SigBit& bit);

// Describes the connection between a child and parent. A child is either a child sheet or a leaf
// kicad component. A parent is a sheet. For leaf kicad components, child labels are mapped to
// pins in the kicad component via a mapping file. It represents a single signal.
struct ConnectionData {
  std::string child_label;
  Yosys::RTLIL::SigBit bit;
};

using PinMapping = std::map<const Lib::Pin*, ConnectionData>;
using ChildMapping = std::map<std::string, ConnectionData>;

}  // namespace memecad

#endif  // MEMECAD_UTIL_H_
