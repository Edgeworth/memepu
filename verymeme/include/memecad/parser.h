#ifndef VERYMEME_MEMECAD_PARSER_H
#define VERYMEME_MEMECAD_PARSER_H

#include <string>

#include "common.h"
#include "memecad/types.h"

namespace memecad {

sheet_t parseSheet(const std::string& data);
std::string writeSheet(const sheet_t& sheet);
library_t parseLibrary(const std::string& data);

}  // memecad

#endif  // VERYMEME_MEMECAD_PARSER_H
