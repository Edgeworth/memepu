#include "memecad/yosys_module.h"

#include <kernel/sigtools.h>
#include <memecad/yosys_module.h>


#include "memecad/parser.h"

namespace memecad {
USING_YOSYS_NAMESPACE

namespace {

constexpr const char* PASS_NAME = "memecad";

std::vector<Lib> parseLibraries(const std::vector<std::string>& filenames) {
  std::vector<Lib> libs;
  for (const auto& filename : filenames)
    libs.push_back(parseLibrary(filename));
  return libs;
}

}  // namespace

std::vector<Schematic::SchematicFile>
convertVerilogToKicadSchematics(const std::string& memecad_map_filename,
    const std::vector<std::string>& verilog_filenames,
    const std::vector<std::string>& kicad_library_filenames) {
  memecad::TestPass test_pass(memecad_map_filename, kicad_library_filenames);

  Yosys::yosys_setup();
  std::string yosys_cmd = "read -sv";
  for (const auto& filename : verilog_filenames)
    yosys_cmd += " " + filename;
  Yosys::run_pass(yosys_cmd);
  // Check all needed files exist. Also adjusts the port width so you can e.g. pass 32 bit
  // constant to a single bit port.
  Yosys::run_pass("hierarchy -check");
  Yosys::run_pass("check -assert");  // Check for misc problems.

  Yosys::run_pass(PASS_NAME);
  Yosys::yosys_shutdown();

  return test_pass.getMapper().getSchematic().writeHierarchy();
}

TestPass::TestPass(const std::string& memecad_map_filename,
    const std::vector<std::string>& kicad_library_filenames) : Pass(PASS_NAME), mapper_(
    readFile(memecad_map_filename, false /* binary */),
    parseLibraries(kicad_library_filenames)) {}

void TestPass::execute(std::vector<std::string> args, Design* design) {
  log_header(design, "Extracting modules...\n");
  extra_args(args, 1, design);

  std::unordered_map<Module*, std::vector<Module*>> adj;
  std::unordered_map<Module*, int> incoming;
  for (auto& module_iter : design->modules_) {
    const auto&[module_id, module] = module_iter;
    if (!design->selected_module(module)) continue;

    // Generate kicad sheet for this module.
    if (!isLeafModule(module)) {
      for (auto& cell_iter : module->cells_) {
        const auto&[cell_id, cell] = cell_iter;
        // Add edge from child to parent, for reverse top-sort.
        auto* child_module = design->module(cell->type);
        verify_expr(child_module != nullptr, "expected module '%s' to exist", cell->type.c_str());

        if (isLeafModule(child_module)) continue;  // Don't need to process leaf modules.
        adj[child_module].push_back(module);
        printf("Processing module: %s, %s\n", log_id(module_id), cell_id.c_str());
        incoming[module]++; // Parent module has incoming edge.
      }
    } else {
      printf("Skipping leaf module '%s'\n", log_id(module_id));
    }
  }

  std::vector<Module*> next;
  for (auto& kv : design->modules_) {
    if (!isLeafModule(kv.second) && incoming[kv.second] == 0)
      next.push_back(kv.second);
  }

  // Topological sort.
  int num_processed = 0;
  while (!next.empty()) {
    Module* module = next.back();
    next.pop_back();
    num_processed++;

    printModuleInfo(module);
    mapper_.addModule(*module);
    for (auto& cell_iter : module->cells_) {
      const auto&[cell_id, cell] = cell_iter;
      mapper_.addCell(*cell);
    }

    // Add new nodes with no incoming edges.
    for (auto* child : adj[module]) {
      incoming[child]--;
      if (incoming[child] == 0)
        next.push_back(child);
    }
  }
  verify_expr(num_processed == int(adj.size()), "BUG: did not process all modules");
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

void TestPass::printModuleInfo(Yosys::RTLIL::Module* module) {
  SigMap sigmap(module);
  log("Module %s\n", log_id(module->name));

  for (auto& cell_iter : module->cells_) {
    const auto&[cell_id, cell] = cell_iter;
    log("  Checking cell %s, name: %s, module: %s\n    type: %s\n", cell_id.c_str(),
        cell->name.c_str(), cell->module->name.c_str(), cell->type.c_str());
    for (auto& conn : cell->connections()) {
      const auto& sig = sigmap(conn.second);
      log("    Looking at connection: %s, signal: %s|%d\n",
          conn.first.c_str(), log_signal(sig), sig.size());
    }
  }

  log("  Looking at wires\n");
  for (auto& wire_iter : module->wires_) {
    const auto&[wire_id, wire] = wire_iter;
    log("    Looking at wire %s, start offset: %d, port id: %d\n", wire_id.c_str(),
        wire->start_offset, wire->port_id);
  }
  log("\n");

  log("  Looking at module connections\n");
  for (auto& sigsig : module->connections()) {
    log("   Looking at sigsig: %s (size: %d) <=> %s (size: %d)\n", log_signal(sigsig.first),
        sigsig.first.size(), log_signal(sigsig.second), sigsig.second.size());
  }
  log("\n");
}

}  // memecad
