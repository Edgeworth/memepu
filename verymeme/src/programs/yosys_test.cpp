#include "kernel/yosys.h"
#include "kernel/sigtools.h"

namespace {
USING_YOSYS_NAMESPACE

class TestPass : public Pass {
public:
  TestPass() : Pass("asdf") {}

  void execute(std::vector<string> args, Design* design) override {
    log_header(design, "Extracting modules...\n");

    extra_args(args, 1, design);

    for (auto& module_iter : design->modules_) {
      const auto&[module_id, module] = module_iter;
      if (!design->selected_module(module)) continue;

      SigMap sigmap(module);
      log("Checking module %s, bitcount: %d\n", log_id(module_id),
          static_cast<int>(sigmap.database.size()));
      for (auto& cell_iter : module->cells_) {
        const auto&[cell_id, cell] = cell_iter;
        log("\n\nChecking cell %s\n", log_id(cell_id));
        for (auto& conn : cell->connections()) {
          const auto& conn_id = conn.first;
          const auto& sig = sigmap(conn.second);
          log("Looking at connection: %s, signal: %s, signal size: %d\n", log_id(conn_id),
              log_signal(sig), sig.size());
        }
      }

      log("Looking at wires\n");
      for (auto& wire_iter : module->wires_) {
        const auto&[wire_id, wire] = wire_iter;
        log("Looking at wire %s\n", log_id(wire_id));

      }
    }
  }
} test_pass;

}  // namespace
