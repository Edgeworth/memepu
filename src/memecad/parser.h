// Copyright 2019 E.
#ifndef MEMECAD_PARSER_H_
#define MEMECAD_PARSER_H_

#include <string>

#include "memecad/types.h"

namespace memecad {

Sheet parseSheet(const std::string& data);
Lib parseLibrary(const std::string& data, const std::string& name);
std::string writeSheet(const Sheet& sheet);

}  // namespace memecad

#endif  // MEMECAD_PARSER_H_
