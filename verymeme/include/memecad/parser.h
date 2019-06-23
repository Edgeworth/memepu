#ifndef MEMECAD_PARSER_H
#define MEMECAD_PARSER_H

#include <string>

#include "verymeme/common.h"
#include "memecad/types.h"

namespace memecad {

Sheet parseSheet(const std::string& data);
Lib parseLibrary(const std::string& data, const std::string& name);
std::string writeSheet(const Sheet& sheet);

}  // memecad

#endif  // MEMECAD_PARSER_H
