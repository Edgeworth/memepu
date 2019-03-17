#ifndef VERYMEME_MEMECAD_PARSER_H
#define VERYMEME_MEMECAD_PARSER_H

#include <string>

#include "verymeme/common.h"
#include "memecad/types.h"

namespace memecad {

Sheet parseSheet(const std::string& data);
std::string writeSheet(const Sheet& sheet);
Lib parseLibrary(const std::string& data, const std::string& name);
Lib parseLibrary(const std::string& filename);

}  // memecad

#endif  // VERYMEME_MEMECAD_PARSER_H
