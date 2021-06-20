// Copyright 2019 E.
#ifndef MEMECAD_YOSYS_MODULE_H_
#define MEMECAD_YOSYS_MODULE_H_

#include <kernel/rtlil.h>
#include <kernel/yosys.h>

#include "memecad/mapper.h"

namespace memecad {

std::vector<Schematic::SchematicFile> convertVerilogToKicadSchematics(
    const std::string& memecad_map_filename, std::vector<std::string> verilog_filenames,
    std::vector<std::string> kicad_library_filenames);

class TestPass : public Yosys::Pass {
 public:
  TestPass();

  void setup(const std::string& memecad_map_filename,
      const std::vector<std::string>& kicad_library_filenames);
  void execute(std::vector<std::string> args, Yosys::RTLIL::Design* design) override;
  Mapper& mapper() { return mapper_; }

 private:
  Mapper mapper_;

  static void printModuleInfo(Yosys::RTLIL::Module* module);
};

}  // namespace memecad

#endif  // MEMECAD_YOSYS_MODULE_H_
