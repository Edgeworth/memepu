
#include <memecad/util.h>

#include "memecad/util.h"


std::string memecad::moduleType(const Yosys::Cell& cell) {
  // Ignore leading '\'.
  verify_expr(cell.type.size() > 1 && cell.type[0] == '\\',
      "BUG: cell type '%s' must be user defined cell", cell.type.c_str());
  return cell.type.c_str() + 1;
}

std::string memecad::moduleName(const Yosys::Cell& cell) {
  // Ignore leading '\'.
  verify_expr(cell.name.size() > 1 && cell.name[0] == '\\',
      "BUG: cell name '%s' must be user defined cell", cell.name.c_str());
  return cell.name.c_str() + 1;
}

std::string memecad::parentModuleType(const Yosys::Cell& cell) {
  // Ignore leading '\'.
  verify_expr(cell.module->name.size() > 1 && cell.module->name[0] == '\\',
      "BUG: module type '%s' must be user defined", cell.module->name.c_str());
  return cell.module->name.c_str() + 1;
}

std::string memecad::modulePath(const Yosys::Cell& cell) {
  // TODO: Output full path somehow?
  return parentModuleType(cell) + "/" + moduleName(cell) + "(" + moduleType(cell) + ")";
}
