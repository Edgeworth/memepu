#include "memesim/simulator.h"

#include "Vkpu_control_logic.h"
#include "Vkpu_kpu.h"
#include "Vkpu_microcode.h"
#include "Vkpu_mmu.h"
#include "Vkpu_register_file.h"
#include "Vkpu_sram__D5_W20.h"
#include "Vkpu_sram__De_W20.h"
#include "Vkpu_sram__De_W20_I626f6f742e686578.h"
#include "Vkpu_vga.h"
#include "memeasm/assembler.h"
#include "verymeme/string_util.h"

namespace memesim {

void Simulator::initializeKpu(Vkpu& kpu) {
  kpu.N_RST_ASYNC = 1;
  // Make sure to start with a high CLK so the two clockKpu's below produce two falling edges.
  kpu.CLK = 1;
  kpu.N_CLK = 0;
  kpu.eval();  // Eval once to set up all signals (X => defined value).
  clockKpu(kpu);  // Clock twice to end any reset that happened from X => defined value.
  clockKpu(kpu);
  resetKpu(kpu);  // Actually reset.
}

void Simulator::clockKpu(Vkpu& kpu) {
  kpu.CLK = 0;
  kpu.N_CLK = 1;
  kpu.eval();

  kpu.CLK = 1;
  kpu.N_CLK = 0;
  kpu.eval();
}

void Simulator::resetKpu(Vkpu& kpu) {
  kpu.CLK = 1;
  kpu.N_CLK = 0;
  kpu.N_RST_ASYNC = 0;
  kpu.eval();
  kpu.N_RST_ASYNC = 1;
  kpu.CLK = 0;
  kpu.N_CLK = 1;  // First falling edge.
  kpu.eval();
  kpu.CLK = 1;
  kpu.N_CLK = 0;
  kpu.eval();
  kpu.CLK = 0;
  kpu.N_CLK = 1;  // Second falling edge - KPU should be reset now.
  kpu.eval();
}

void Simulator::run() {
  initializeKpu(kpu_);

  bool running = false;
  bool step;
  while (true) {
    step = false;

    std::optional<Command> cmd;
    cmd = running ? command_queue_.tryYield() : command_queue_.yield();

    if (cmd) {
      switch (cmd->type) {
      case Command::Type::RUN: running = true; break;
      case Command::Type::STOP: running = false; break;
      case Command::Type::STEP: step = true; break;
      case Command::Type::QUIT: return;
      case Command::Type::GET_CPU_STATE: cmd->receiver->push(generateCpuState()); break;
      case Command::Type::GET_VGA_STATE: cmd->receiver->push(generateVgaState()); break;
      case Command::Type::SET_MOUSE:
        kpu_.kpu->mmu->ram->mem[0x10] = cmd->args.i0;  // TODO: use constant for this.
        kpu_.kpu->mmu->ram->mem[0x11] = cmd->args.i1;
        break;
      }
    }
    if (running || step) clockKpu(kpu_);
  }
}

Simulator::CpuStateMessage Simulator::generateCpuState() {
  CpuStateMessage msg = {};

  msg.bus = uint32_t(kpu_.kpu->bus);
  msg.tmp0 = uint32_t(kpu_.kpu->tmp0_val);
  msg.tmp1 = uint32_t(kpu_.kpu->tmp1_val);
  msg.opword_opcode = uint32_t(kpu_.kpu->opword_opcode);
  msg.opword_bits = uint32_t(kpu_.kpu->opword_bits);
  msg.mlu = uint32_t(kpu_.kpu->mlu_val);
  msg.cond_var = uint32_t(kpu_.kpu->control->cond_var);
  msg.opcode = uint32_t(kpu_.kpu->control->opcode);
  msg.microop_count = uint32_t(kpu_.kpu->control->microop_count);
  msg.ctrl_data = uint32_t(kpu_.kpu->control->CTRL_DATA);
  msg.reg_sel = uint32_t(kpu_.kpu->control->REG_SEL);
  msg.out_plane = uint32_t(kpu_.kpu->control->out_plane);
  msg.in_plane = uint32_t(kpu_.kpu->control->in_plane);
  msg.misc_plane = uint32_t(kpu_.kpu->control->misc_plane);
  msg.mlu_plane = uint32_t(kpu_.kpu->control->MLU_PLANE);
  msg.shifter_plane = uint32_t(kpu_.kpu->control->SHIFTER_PLANE);
  msg.opcode_sel = uint32_t(kpu_.kpu->control->opcode_sel);
  msg.cond_var_sel = uint32_t(kpu_.kpu->control->cond_var_sel);
  msg.n_rst = uint32_t(kpu_.kpu->n_rst);
  msg.mnemonic = memeasm::Assembler::generateMnemonicString(
      convertToString(kpu_.kpu->control->microcode->mnemonic), kpu_.kpu->opword_bits);
  for (int i = 0; i < NUM_REG; ++i) msg.regs[i] = uint32_t(kpu_.kpu->regs->registers->mem[i]);

  return msg;
}

Simulator::VgaStateMessage Simulator::generateVgaState() {
  VgaStateMessage msg = {};

  static_assert(
      sizeof(kpu_.kpu->mmu->vga->vram0->mem[0]) == sizeof(uint32_t), "wrong size for vga memory");
  constexpr int NUM_ELTS = sizeof(kpu_.kpu->mmu->vga->vram0->mem) / sizeof(uint32_t);
  for (int i = 0; i < NUM_ELTS; ++i) {
    auto val = uint32_t(kpu_.kpu->mmu->vga->vram0->mem[i]);
    msg.pixels[4 * i] = uint8_t(val & 0xFFu);
    msg.pixels[4 * i + 1] = uint8_t((val >> 8u) & 0xFFu);
    msg.pixels[4 * i + 2] = uint8_t((val >> 16u) & 0xFFu);
    msg.pixels[4 * i + 3] = uint8_t((val >> 24u) & 0xFFu);
  }

  return msg;
}

void Simulator::scheduleCommand(const Simulator::Command& cmd) { command_queue_.push(cmd); }

}  // namespace memesim
