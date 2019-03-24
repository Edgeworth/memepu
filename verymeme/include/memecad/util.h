#ifndef VERYMEME_MEMECAD_UTIL_H
#define VERYMEME_MEMECAD_UTIL_H

#include <kernel/rtlil.h>
#include "verymeme/common.h"

namespace memecad {

std::string moduleType(const Yosys::Cell& cell);
std::string moduleName(const Yosys::Cell& cell);
std::string parentModuleType(const Yosys::Cell& cell);

// TODO: moduleTypePath moduleNamePath

}  // namespace memecad

#endif  // VERYMEME_MEMECAD_UTIL_H
