// Copyright 2019 E.
#ifndef MEMESIM_SIMULATOR_H
#define MEMESIM_SIMULATOR_H

#include <unordered_set>
#include <variant>

#include "Vkpu.h"
#include "memeware/constants.h"
#include "verymeme/concurrent_queue.h"

namespace memesim {

void initializeKpu(Vkpu& kpu);
void clockKpu(Vkpu& kpu);
void resetKpu(Vkpu& kpu);

class Simulator {
 public:
  struct CpuStateMessage {
    uint32_t bus;
    uint32_t tmp0;
    uint32_t tmp1;
    uint32_t opword_opcode;
    uint32_t opword_bits;
    uint32_t mlu;
    uint32_t cond_var;
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
    uint32_t cond_var_sel;
    uint32_t n_rst;
    std::string mnemonic;
    uint32_t regs[32];
    uint32_t interrupts_enabled;
    uint32_t has_interrupt;
  };

  struct VgaStateMessage {
    uint8_t pixels[memeware::VGA_HEIGHT * memeware::VGA_WIDTH];
  };

  using Response = std::variant<CpuStateMessage, VgaStateMessage>;

  struct CmdArgs {
    int64_t i32_0 = 0;
    int64_t i32_1 = 0;
  };

  struct Cmd {
    // TODO(improvement): Simulate real VGA signal. Simulate real mouse and keyboard.
    enum class Type {
      RUN,
      STOP,
      STEP,
      SET_BREAKPOINT,
      GET_CPU_STATE,
      GET_VGA_STATE,
      SET_MOUSE,
      SET_KBD,
      QUIT,
    } type;
    CmdArgs args;
    std::shared_ptr<ConcurrentQueue<Response>> receiver;
  };

  void run();

  // This method is thread safe.
  void scheduleCommand(const Cmd& cmd);

 private:
  Vkpu kpu_;
  ConcurrentQueue<Cmd> command_queue_;
  std::unordered_set<uint32_t> breakpoints_;

  uint32_t getRegister(int reg) const;
  CpuStateMessage generateCpuState();
  VgaStateMessage generateVgaState();
  void clockKpu();
};

}  // namespace memesim

#endif  // MEMESIM_SIMULATOR_H
