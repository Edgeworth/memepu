// Copyright 2019 E.
#include "memecad/util.h"

#include "verymeme/macros.h"

namespace memecad {

namespace {

std::string checkModuleName(const std::string& name) {
  auto idx = name.find('\\');
  // Parametric modules and generated modules are prefixed with e.g. $gen$ or $paramod$, so just
  // check for the presence of a \. Cell name must be user defined cell.
  bug_unless(idx != std::string::npos);
  return name;
}

}  // namespace

std::string moduleType(const Yosys::Cell& cell) {
  return "$abstract" + checkModuleName(cell.type.str());
}

std::string moduleName(const Yosys::Cell& cell) { return checkModuleName(cell.name.str()); }

std::string moduleName(const Yosys::Module& module) { return checkModuleName(module.name.str()); }

std::string parentModuleType(const Yosys::Cell& cell) {
  return checkModuleName(cell.module->name.str());
}

std::string modulePath(const Yosys::Cell& cell) {
  // TODO(improvement): Output full path somehow?
  return parentModuleType(cell) + "/" + moduleName(cell) + "(" + moduleType(cell) + ")";
}

std::string getIdForSigBit(const Yosys::SigBit& bit) {
  std::string parent_label;
  if (bit.wire) {
    parent_label = std::string(bit.wire->name.c_str() + 1);

    // Empty string as special case for unused. This will be mapped to no-connect.
    if (parent_label.substr(0, 6) == "unused") return "";

    // A single child signal may connect to multiple different parent signals and wires, e.g.
    // .B(C[2:0], C_IN): The child signal B connects to C_IN and C[2:0]. So, use parent offset
    // and width values for deciding the parent label.
    if (bit.wire->width > 1) parent_label += std::to_string(bit.offset);
  } else if (bit.data == Yosys::State::Sz) {
    return "";  // Treat Z (high impedance) as no-connect.
  } else {
    verify_expr(bit.data == Yosys::State::S0 || bit.data == Yosys::State::S1,
        "unsupported state for signal: %d", int(bit.data));
    parent_label = bit.data == Yosys::State::S1 ? "VCC" : "GND";
  }
  return parent_label;
}

}  // namespace memecad
