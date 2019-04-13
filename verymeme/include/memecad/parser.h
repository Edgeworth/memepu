#ifndef VERYMEME_MEMECAD_PARSER_H
#define VERYMEME_MEMECAD_PARSER_H

#include <string>

#include "verymeme/common.h"
#include "memecad/types.h"

namespace memecad {

Sheet parseSheet(const std::string& data);
Lib parseLibrary(const std::string& data, const std::string& name);
std::string writeSheet(const Sheet& sheet);

}  // memecad

#endif  // VERYMEME_MEMECAD_PARSER_H
