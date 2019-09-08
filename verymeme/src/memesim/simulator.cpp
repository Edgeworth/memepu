#include "memesim/simulator.h"

#include "Vkpu_control_logic.h"
#include "Vkpu_kpu.h"
#include "Vkpu_microcode.h"
#include "Vkpu_mmu.h"
#include "Vkpu_register_file.h"
#include "Vkpu_sram__D10_W20.h"
#include "Vkpu_sram__D5_W20.h"
#include "Vkpu_sram__pi1.h"
#include "Vkpu_vga.h"
#include "memeasm/assembler.h"
#include "memeware/constants.h"
#include "verymeme/string_util.h"

namespace memesim {

namespace {

const int PRINT_SPEED_MS = 5000;

}  // namespace

using namespace std::chrono;

void initializeKpu(Vkpu& kpu) {
  kpu.N_RST_ASYNC = 1;
  // Make sure to start with a high CLK so the two clockKpu's below produce two falling edges.
  kpu.CLK = 1;
  kpu.N_CLK = 0;
  kpu.eval();  // Eval once to set up all signals (X => defined value).
  clockKpu(kpu);  // Clock twice to end any reset that happened from X => defined value.
  clockKpu(kpu);
  resetKpu(kpu);  // Actually reset.
}

void clockKpu(Vkpu& kpu) {
  kpu.CLK = 0;
  kpu.N_CLK = 1;
  kpu.eval();

  kpu.CLK = 1;
  kpu.N_CLK = 0;
  kpu.eval();
}

void resetKpu(Vkpu& kpu) {
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

void Simulator::clockKpu() {
  kpu_.INTERRUPT_ASYNC = kpu_.kpu->mmu->ram->mem[memeware::MMIO_INTERRUPT_CLEAR] ? 1 : 0;
  ::memesim::clockKpu(kpu_);
}

void Simulator::run() {
  initializeKpu(kpu_);

  bool running = false;
  bool step;
  auto time = steady_clock::now();
  int64_t cycle_count = 0;
  while (true) {
    step = false;

    std::optional<Cmd> cmd;
    cmd = running ? command_queue_.tryYield() : command_queue_.yield();

    if (cmd) {
      switch (cmd->type) {
      case Cmd::Type::RUN: running = true; break;
      case Cmd::Type::STOP: running = false; break;
      case Cmd::Type::STEP: step = true; break;
      case Cmd::Type::SET_BREAKPOINT: breakpoints_.insert(cmd->args.i32_0); break;
      case Cmd::Type::QUIT: return;
      case Cmd::Type::GET_CPU_STATE: cmd->receiver->push(generateCpuState()); break;
      case Cmd::Type::GET_VGA_STATE: cmd->receiver->push(generateVgaState()); break;
      case Cmd::Type::SET_MOUSE:
        // TODO: use constant for this memory mapped address.
        kpu_.kpu->mmu->ram->mem[memeware::MMIO_MOUSE] =
            (cmd->args.i32_0 & 0xFFFF) | ((cmd->args.i32_1 << 16) & 0xFFFF0000);
        //        kpu_.kpu->mmu->ram->mem[memeware::MMIO_INTERRUPT_CLEAR] = 1;
        // TODO set interrupt? - need some way to distinguish.
        break;
      case Cmd::Type::SET_KBD:
        printf("Got kbd: %d\n", int(cmd->args.i32_0));
        kpu_.kpu->mmu->ram->mem[memeware::MMIO_KEYBOARD] = cmd->args.i32_0;
        kpu_.kpu->mmu->ram->mem[memeware::MMIO_INTERRUPT_CLEAR] = 1;
        break;
      }
    }
    if (running || step) {
      clockKpu();
      cycle_count++;
    }
    if (running && breakpoints_.count(getRegister(memeware::PC_REG))) {
      printf("Breakpoint at %u.\n", getRegister(memeware::PC_REG));
      running = false;
    }
    int64_t dur = duration_cast<milliseconds>(steady_clock::now() - time).count();
    if (running && dur > PRINT_SPEED_MS) {
      printf("%f MHz - %" PRId64 " cycles in %" PRId64 " ms\n", double(cycle_count) / dur / 1000.f,
          cycle_count, dur);
      cycle_count = 0;
      time = steady_clock::now();
    }
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
  msg.interrupts_enabled = uint32_t(kpu_.kpu->control->interrupts_enabled);
  msg.has_interrupt = uint32_t(kpu_.kpu->control->has_interrupt);
  for (int i = 0; i < memeware::NUM_REG; ++i) msg.regs[i] = getRegister(i);

  return msg;
}

Simulator::VgaStateMessage Simulator::generateVgaState() {
  VgaStateMessage msg = {};

  const auto& mem = kpu_.kpu->mmu->vga->vram0->mem;
  static_assert(sizeof(mem[0]) == sizeof(uint32_t), "wrong vga word size");
  static_assert(memeware::VGA_WIDTH % 4 == 0, "vga width not divisible by word size");
  static_assert(memeware::VGA_HEIGHT % 4 == 0, "vga height not divisible by word size");
  static_assert(
      sizeof(mem) >= memeware::VGA_WIDTH * memeware::VGA_HEIGHT / 4, "wrong size for vga memory");
  for (int i = 0; i < memeware::VGA_WIDTH * memeware::VGA_HEIGHT / 4; ++i) {
    msg.pixels[4 * i] = mem[i] & 0xFF;
    msg.pixels[4 * i + 1] = (mem[i] >> 8) & 0xFF;
    msg.pixels[4 * i + 2] = (mem[i] >> 16) & 0xFF;
    msg.pixels[4 * i + 3] = (mem[i] >> 24) & 0xFF;
  }

  return msg;
}

void Simulator::scheduleCommand(const Simulator::Cmd& cmd) { command_queue_.push(cmd); }

uint32_t Simulator::getRegister(int reg) const {
  return uint32_t(kpu_.kpu->regs->registers->mem[reg]);
}

}  // namespace memesim
