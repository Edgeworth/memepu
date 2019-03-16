#ifndef VERYMEME_YOSYS_MODULE_H
#define VERYMEME_YOSYS_MODULE_H

#include <kernel/yosys.h>
#include <kernel/rtlil.h>
#include "verymeme/common.h"

namespace memecad {

class TestPass : public Yosys::Pass {
public:
  TestPass();

  void execute(std::vector<std::string> args, Yosys::RTLIL::Design* design) override;
private:
  bool isLeafModule(Yosys::RTLIL::Module* module);
};

}  // namespace

#endif  // VERYMEME_YOSYS_MODULE_H
