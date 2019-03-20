#include "memecad/yosys_module.h"

#include <kernel/sigtools.h>
#include "memecad/parser.h"

namespace memecad {
USING_YOSYS_NAMESPACE


TestPass::TestPass(const std::string& memecad_map_filename,
    const std::string& kicad_library_filename) : Pass("memecad"), mapper_(
    readFile(memecad_map_filename, false /* binary */),
    parseLibrary(kicad_library_filename)) {}

void TestPass::execute(std::vector<std::string> args, Design* design) {
  log_header(design, "Extracting modules...\n");

  extra_args(args, 1, design);

  for (auto& module_iter : design->modules_) {
    const auto&[module_id, module] = module_iter;
    if (!design->selected_module(module)) continue;

    SigMap sigmap(module);
    log("Checking module %s, bitcount: %d\n", log_id(module_id),
        static_cast<int>(sigmap.database.size()));
    log("Is leaf module: %d\n", int(isLeafModule(module)));

    for (auto& cell_iter : module->cells_) {
      const auto&[cell_id, cell] = cell_iter;
      log("  Checking cell %s, name: %s, type: %s\n", cell_id.c_str(),
          cell->name.c_str(), cell->type.c_str());
      for (auto& conn : cell->connections()) {
        const auto& conn_id = conn.first;
        const auto& sig = sigmap(conn.second);
        log("    Looking at connection: %s, signal: %s|%d\n",
            conn_id.c_str(), log_signal(sig), sig.size());
      }
    }

    log("  Looking at wires\n");
    for (auto& wire_iter : module->wires_) {
      const auto&[wire_id, wire] = wire_iter;
      log("    Looking at wire %s, offset: %d, port id: %d\n", wire_id.c_str(), int(wire->start_offset), int(wire->port_id));
    }
    printf("\n");

    // Generate kicad sheet containing this module.
    if (!isLeafModule(module)) {
      for (auto& cell_iter : module->cells_) {
        const auto&[cell_id, cell] = cell_iter;
        log("  Adding chip '%s'\n", cell->type.str().c_str());
        verify_expr(cell->type[0] == '\\', "unexpected non-user component");
        // TODO: compare verilog input/output to electrical type for kicad pins
        mapper_.addComponentFromCell(*cell);
      }
    }
  }

  mapper_.writeHierarchy("test");
}

bool TestPass::isLeafModule(RTLIL::Module* module) {
  for (auto& cell_iter : module->cells_) {
    const auto&[cell_id, cell] = cell_iter;
    verify_expr(!cell_id.empty(), "expected cell name not empty");
    // If there is a non-autogenerated cell, i.e. submodule, this isn't a leaf module.
    if (cell_id[0] != '$') return false;
  }
  return true;
}

}  // memecad
