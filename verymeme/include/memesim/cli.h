#ifndef MEMESIM_CLI_H
#define MEMESIM_CLI_H

#include "verymeme/common.h"
#include "simulator.h"

namespace memesim {

class CommandLine {
public:
  explicit CommandLine(Simulator* simulator);

  void run();

private:
  Simulator* simulator_;
  std::shared_ptr<ConcurrentQueue<Simulator::CpuStateMessage>> cpu_state_receiver_;

  void printCpuState(const Simulator::CpuStateMessage& state);
};

}  // memesim

#endif  // MEMESIM_CLI_H
