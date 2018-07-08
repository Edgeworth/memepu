#include "control.h"
#include "control_constants.h"

#define WRITE_NO_AUX(opcode, ...) { \
  uint32_t microops[] = {__VA_ARGS__}; \
  writeInstruction(opcode, microops, sizeof(microops) / sizeof(microops[0])); \
}

void ControlLogic::writeInstruction(uint8_t opcode0, uint32_t *microops, size_t num) {
  for (int microop = 0; microop < num; ++microop) {
    for (int aux = 0; aux < (1 << 4); ++aux) {
      for (int int_flag = 0; int_flag < 2; ++int_flag) {
        for (int mmu_fault_flag = 0; mmu_fault_flag < 2; ++mmu_fault_flag) {
          uint32_t addr = 0;
          addr |= addr_opcode(opcode0);
          addr |= addr_aux(aux);
          addr |= addr_microop(microop);
          addr |= addr_int_flag(static_cast<bool>(int_flag));
          addr |= addr_mmu_fault_flag(static_cast<bool>(mmu_fault_flag));
          put(addr, microops[microop]);
        }
      }
    }
  }
}

std::string ControlLogic::generateControlData() {
  // Instruction set:
  // 0: Boot sequence
  for (uint8_t i = 0; i < 255; ++i) {
    WRITE_NO_AUX(
        i,
        bus(i) | out(OUT_N_CTRLLOGIC) | in(IN_N_DISP),
        multi(MULTI_N_OPCODE0_INC),
        multi(MULTI_N_RESET_UOP_COUNT)
    );
  }


  // 1: Fetch opcode
  // TODO check interrupt, page fault
  // TODO what can AUX be? e.g. for fetch opcode need to be same for all AUX
  // WRITE_NO_AUX(1,
  //   // Set AUX opcode to 0
  //   bus(0) | out(OUT_N_CTRLLOGIC) | in(IN_N_OPCODE1),
  //   // Load PC into MMU registers
  //   out(OUT_N_PC0) | in(IN_N_MMU0),
  //   out(OUT_N_PC1) | in(IN_N_MMU1),
  //   out(OUT_N_PC2) | in(IN_N_MMU2),
  //   // Load new opcode and reset uop counter.
  //   out(OUT_N_MMU) | in(IN_N_OPCODE0) | multi(MULTI_N_RESET_UOP_COUNT),
  // );

  // 2: Page fault
  // 3: Handle interrupt
}
