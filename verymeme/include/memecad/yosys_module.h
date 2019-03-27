#ifndef VERYMEME_YOSYS_MODULE_H
#define VERYMEME_YOSYS_MODULE_H

#include <kernel/yosys.h>
#include <kernel/rtlil.h>
#include "verymeme/common.h"
#include "memecad/mapper.h"

namespace memecad {

std::vector<Schematic::SchematicFile> convertVerilogToKicadSchematics(
    const std::string& memecad_map_filename, const std::vector<std::string>& verilog_filenames,
    const std::vector<std::string>& kicad_library_filenames);

class TestPass : public Yosys::Pass {
public:
  TestPass(const std::string& memecad_map_filename, const std::string& kicad_library_filename);

  void execute(std::vector<std::string> args, Yosys::RTLIL::Design* design) override;
  Mapper& getMapper() { return mapper_; }

private:
  Mapper mapper_;

  bool isLeafModule(Yosys::RTLIL::Module* module);
};

}  // namespace

#endif  // VERYMEME_YOSYS_MODULE_H
