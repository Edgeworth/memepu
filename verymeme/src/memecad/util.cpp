
#include <memecad/util.h>


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

std::string memecad::getIdForSigBit(const Yosys::SigBit& bit) {
  std::string parent_label;
  if (bit.wire) {
    parent_label = std::string(bit.wire->name.c_str() + 1);
    // A single child signal may connect to multiple different parent signals and wires, e.g.
    // .B(C[2:0], C_IN): The child signal B connects to C_IN and C[2:0]. So, use parent offset
    // and width values for deciding the parent label.
    if (bit.wire->width > 1) parent_label += std::to_string(bit.offset);
  } else {
    verify_expr(bit.data == Yosys::State::S0 || bit.data == Yosys::State::S1,
        "unsupported state for signal: %d", int(bit.data));
    parent_label = bit.data == Yosys::State::S1 ? "VCC" : "GND";
  }
  return parent_label;
}
