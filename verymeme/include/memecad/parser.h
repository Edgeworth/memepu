#ifndef VERYMEME_MEMECAD_PARSER_H
#define VERYMEME_MEMECAD_PARSER_H

#include <string>

#include "common.h"
#include "memecad/types.h"

namespace memecad {

sheet_t parseSheet(const std::string& data);
std::string writeSheet(const sheet_t& sheet);
lib_t parseLibrary(const std::string& data, const std::string& name);
lib_t parseLibrary(const std::string& filename);

}  // memecad

#endif  // VERYMEME_MEMECAD_PARSER_H
