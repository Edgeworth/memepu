#ifndef MEMESIM_CLI_H
#define MEMESIM_CLI_H

#include "memesim/simulator.h"
#include "verymeme/concurrent_queue.h"

namespace memesim {

class CommandLine {
public:
  explicit CommandLine(Simulator* simulator);

  void run();

private:
  Simulator* simulator_;
  std::shared_ptr<ConcurrentQueue<Simulator::Response>> receiver_;

  static void printCpuState(const Simulator::CpuStateMessage& state);
};

}  // namespace memesim

#endif  // MEMESIM_CLI_H
