#include "memesim/simulator.h"

#include "Vkpu_kpu.h"
#include "Vkpu_control_logic.h"
#include "Vkpu_register_file.h"
#include "Vkpu_sram__D5_W20.h"
#include "Vkpu_mmu.h"
#include "Vkpu_vga.h"
#include "Vkpu_sram__De_W20.h"
#include "Vkpu_microcode.h"

namespace memesim {

namespace {

template<std::size_t N>
std::string convertToString(const WData (& data)[N]) {
  std::string str;
  str.reserve(N * sizeof(WData));
  static_assert(sizeof(WData) == 4, "bug");
  for (WData c : data) {
    str += char(c & 0xFF);
    str += char((c >> 8) & 0xFF);
    str += char((c >> 16) & 0xFF);
    str += char((c >> 24) & 0xFF);
  }
  std::string trimmed(str.c_str());  // Cut off at first 0 byte.
  return std::string(trimmed.rbegin(), trimmed.rend()); // Reverse
}

}  // namespace

void Simulator::run() {
  kpu_.N_RST_ASYNC = 1;
  kpu_.eval();  // Eval once to set up all signals (X => defined value).
  clockKpu();  // Clock twice to end any reset that happened from X => defined value.
  clockKpu();
  resetKpu();  // Actually reset.

  bool running = false;
  bool step = false;
  while (true) {
    usleep(10 * 1000);  // TODO: Remove.
    step = false;

    std::optional<Command> cmd;
    cmd = running ? command_queue_.tryYield() : command_queue_.yield();

    if (cmd) {
      switch (cmd->type) {
        case Command::Type::RUN:
          running = true;
          break;
        case Command::Type::STOP:
          running = false;
          break;
        case Command::Type::STEP:
          step = true;
          break;
        case Command::Type::QUIT:
          return;
        case Command::Type::GET_CPU_STATE:
          verify_expr(cmd->cpu_state_receiver, "require receiver for get cpu state cmd");
          cmd->cpu_state_receiver->push(generateCpuState());
          break;
        case Command::Type::GET_VGA_STATE:
          verify_expr(cmd->vga_state_receiver, "require receiver for get vga state cmd");
          cmd->vga_state_receiver->push(generateVgaState());
          break;
      }
    }
    if (running || step) clockKpu();
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
  msg.opcode = uint32_t(kpu_.kpu->control->opcode);
  msg.microop_count = uint32_t(kpu_.kpu->control->microop_count);
  msg.ctrl_data = uint32_t(kpu_.kpu->control->CTRL_DATA);
  msg.reg_sel = uint32_t(kpu_.kpu->control->REG_SEL);
  msg.out_plane = uint32_t(kpu_.kpu->control->control_out_plane);
  msg.in_plane = uint32_t(kpu_.kpu->control->control_in_plane);
  msg.misc_plane = uint32_t(kpu_.kpu->control->control_misc_plane);
  msg.mlu_plane = uint32_t(kpu_.kpu->control->MLU_PLANE);
  msg.shifter_plane = uint32_t(kpu_.kpu->control->SHIFTER_PLANE);
  msg.opcode_sel = uint32_t(kpu_.kpu->control->control_opcode_sel);
  msg.n_rst = uint32_t(kpu_.kpu->n_rst);
  msg.mnemonic = convertToString(kpu_.kpu->control->microcode->mnemonic);
  for (int i = 0; i < NUM_REG; ++i)
    msg.regs[i] = uint32_t(kpu_.kpu->regs->registers->mem[i]);

  return msg;
}

Simulator::VgaStateMessage Simulator::generateVgaState() {
  VgaStateMessage msg = {};

  static_assert(sizeof(kpu_.kpu->mmu->vga->vram0->mem[0]) == sizeof(uint32_t),
      "wrong size for vga memory");
  constexpr int NUM_ELTS = sizeof(kpu_.kpu->mmu->vga->vram0->mem) / sizeof(uint32_t);
  for (int i = 0; i < NUM_ELTS; ++i) {
    auto val = uint32_t(kpu_.kpu->mmu->vga->vram0->mem[i]);
    msg.pixels[4 * i] = val & 0xFFu;
    msg.pixels[4 * i + 1] = (val >> 8) & 0xFFu;
    msg.pixels[4 * i + 2] = (val >> 16) & 0xFFu;
    msg.pixels[4 * i + 3] = (val >> 24) & 0xFFu;
  }

  return msg;
}


void Simulator::scheduleCommand(const Simulator::Command& cmd) {
  command_queue_.push(cmd);
}

}  // memesim
