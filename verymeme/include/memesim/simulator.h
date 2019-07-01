#ifndef VERYMEME_SIMULATOR_H
#define VERYMEME_SIMULATOR_H

#include "verymeme/common.h"

#include "Vkpu.h"

namespace memesim {

class Simulator {
public:
  constexpr static int NUM_REG = 32;
  constexpr static int VGA_WIDTH = 256;
  constexpr static int VGA_HEIGHT = 256;

  struct CpuStateMessage {
    uint32_t bus;
    uint32_t tmp0;
    uint32_t tmp1;
    uint32_t opword_opcode;
    uint32_t opword_bits;
    uint32_t mlu;
    uint32_t opcode;
    uint32_t microop_count;
    uint32_t ctrl_data;
    uint32_t reg_sel;
    uint32_t out_plane;
    uint32_t in_plane;
    uint32_t misc_plane;
    uint32_t mlu_plane;
    uint32_t shifter_plane;
    uint32_t opcode_sel;
    uint32_t n_rst;
    std::string mnemonic;
    uint32_t regs[32];
  };

  struct VgaStateMessage {
    uint8_t pixels[VGA_HEIGHT * VGA_WIDTH];
  };

  struct Command {
    enum class Type { RUN, STOP, STEP, GET_CPU_STATE, GET_VGA_STATE, QUIT } type;
    std::shared_ptr<ConcurrentQueue<CpuStateMessage>> cpu_state_receiver;
    std::shared_ptr<ConcurrentQueue<VgaStateMessage>> vga_state_receiver;
  };

  void run();

  // This method is thread safe.
  void scheduleCommand(const Command& cmd);

  static void initializeKpu(Vkpu& kpu);
  static void clockKpu(Vkpu& kpu);
  static void resetKpu(Vkpu& kpu);

private:
  Vkpu kpu_;
  ConcurrentQueue<Command> command_queue_;

  CpuStateMessage generateCpuState();
  VgaStateMessage generateVgaState();

};

}  // memesim

#endif  // VERYMEME_SIMULATOR_H
