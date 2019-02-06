#include "control.h"
#include "control_constants.h"

#define WRITE_NO_AUX(opcode, ...) { \
  uint32_t microops[] = {__VA_ARGS__}; \
  writeNoAux(opcode, microops, sizeof(microops) / sizeof(microops[0])); \
}

#define WRITE_AUX_MASK(opcode, aux_mask, aux, ...) { \
  uint32_t microops[] = {__VA_ARGS__}; \
  writeAuxMask(opcode, aux_mask, aux, microops, sizeof(microops) / sizeof(microops[0])); \
}

#define WRITE_AUX(opcode, aux, ...) { \
  uint32_t microops[] = {__VA_ARGS__}; \
  writeAux(opcode, aux, microops, sizeof(microops) / sizeof(microops[0])); \
}

#define WRITE_INT_FLAG(opcode, int_flag, ...) { \
  uint32_t microops[] = {__VA_ARGS__}; \
  writeIntFlag(opcode, int_flag, microops, sizeof(microops) / sizeof(microops[0])); \
}

void ControlLogic::writeNoAux(Opcode opcode0, uint32_t* microops, int num) {
  // Write using aux mask set to not care about any bits.
  writeAuxMask(opcode0, 0, 0, microops, num);
}

void
ControlLogic::writeAuxMask(Opcode opcode0, int aux_mask, int aux, uint32_t* microops, int num) {
  verify_expr((~aux_mask & aux) == 0,
      "no point specifying aux bits for bits not in aux_mask: %x %x", aux_mask, aux);
  for (int aux_idx = 0; aux_idx < (1 << 4); ++aux_idx) {
    if ((aux_idx & aux_mask) == aux) {
      writeAux(opcode0, aux_idx, microops, num);
    }
  }
}


void ControlLogic::writeAux(Opcode opcode0, int aux, uint32_t* microops, int num) {
  writeMicroops(opcode0, aux, 0, 0, microops, num);
  writeMicroops(opcode0, aux, 0, 1, microops, num);
  writeMicroops(opcode0, aux, 1, 0, microops, num);
  writeMicroops(opcode0, aux, 1, 1, microops, num);
}

void ControlLogic::writeIntFlag(Opcode opcode0, int int_flag, uint32_t* microops, int num) {
  for (int aux = 0; aux < (1 << 4); ++aux) {
    writeMicroops(opcode0, aux, int_flag, 0, microops, num);
    writeMicroops(opcode0, aux, int_flag, 1, microops, num);
  }
}

void ControlLogic::writeMicroops(Opcode opcode0, int aux, int int_flag, int mmu_fault_flag,
    uint32_t* microops, int num) {
  verify_expr(num <= 16, "no more than 16 microops for opcode %d, has %d microops",
      static_cast<int>(opcode0), num);
  for (int microop_idx = 0; microop_idx < 16; ++microop_idx) {
    // Verify last micro-op resets micro-op counter, unless it's the final micro-op.
    if (microop_idx == num - 1 && microop_idx != 15)
      verify_expr(multi_from_microop(microops[microop_idx]) == MULTI_N_RESET_UOP_COUNT,
          "last micro-op must reset micro-op count, opcode: %d", static_cast<int>(opcode0));

    // For unused portions, reset uop count for debug purposes.
    if (microop_idx < num)
      write(opcode0, aux, int_flag, mmu_fault_flag, microop_idx, microops[microop_idx]);
    else write(opcode0, aux, int_flag, mmu_fault_flag, microop_idx, multi(MULTI_N_RESET_UOP_COUNT));
  }
}

void ControlLogic::write(Opcode opcode0, int aux, int int_flag, int mmu_fault_flag, int microop_idx,
    uint32_t microop_data) {
  uint32_t addr = 0;
  addr |= addr_opcode(static_cast<uint8_t>(opcode0));
  addr |= addr_aux(aux);
  addr |= addr_microop(microop_idx);
  addr |= addr_int_flag(static_cast<bool>(int_flag));
  addr |= addr_mmu_fault_flag(static_cast<bool>(mmu_fault_flag));
  put(addr, microop_data);
}

void ControlLogic::writeLoadImmediate(Opcode opcode0, int in_signal) {
  WRITE_NO_AUX(
      opcode0,
      out(OUT_N_PC0) | in(IN_N_MMU0),
      out(OUT_N_PC1) | in(IN_N_MMU1),
      out(OUT_N_PC2) | in(IN_N_MMU2),
      out(OUT_N_MMU) | in(in_signal) | multi(MULTI_N_PC_INC),
      bus(static_cast<uint8_t>(Opcode::FETCH)) | out(OUT_N_CTRLLOGIC) | in(IN_N_OPCODE0) |
      multi(MULTI_N_RESET_UOP_COUNT)
  );
}

std::string ControlLogic::getBinaryData() {
  // Instruction set:
  // Hack to reset micro-op counter before booting
  WRITE_NO_AUX(
      Opcode::MICROOP_RESET_HACK,
      bus(static_cast<uint8_t>(Opcode::BOOT)) | out(OUT_N_CTRLLOGIC) | in(IN_N_OPCODE0) |
      multi(MULTI_N_RESET_UOP_COUNT)
  // Rest of microops automatically filled to reset UOP count.
  );

  // Boot sequence / initialisation
  // TODO: Loads hard-coded address
  WRITE_NO_AUX(
      Opcode::BOOT,
      bus(0) | out(OUT_N_CTRLLOGIC) | in(IN_N_PC0) |
      multi(MULTI_N_UNSET_INT_ENABLE), // Interrupts disabled by default.
      bus(0) | out(OUT_N_CTRLLOGIC) | in(IN_N_PC1),
      bus(0x10) | out(OUT_N_CTRLLOGIC) | in(IN_N_PC2),  // EEPROM mapped in at 0x100000
      bus(0) | out(OUT_N_CTRLLOGIC) | in(IN_N_TASK),
  // Set up the memory protection stuff before fetching.
      bus(0) | out(OUT_N_CTRLLOGIC) | in(IN_N_OPCODE1),  // Reset opcode1
      bus(0) | out(OUT_N_CTRLLOGIC) | in(IN_N_A),  // SETUP_MEMORY_PROTECTION expects A to be 0.
      bus(0) | out(OUT_N_CTRLLOGIC) |
      in(IN_N_M0),  // Set everything to 0 - i.e. task 0 can do anything.
      bus(static_cast<uint8_t>(Opcode::SETUP_MEMORY_PROTECTION)) | out(OUT_N_CTRLLOGIC) |
      in(IN_N_OPCODE0) | multi(MULTI_N_RESET_UOP_COUNT)
  );

  // Checks:
  // Last microop resets uop counter. All cases?
  // Using bus() implies OUT_N_CTRLLOGIC

  // Fetch. Increments PC.
  WRITE_INT_FLAG(
      Opcode::FETCH,
      0,
      bus(0) | out(OUT_N_CTRLLOGIC) | in(IN_N_OPCODE1),  // Reset opcode1
  // After reading in the interrupt register, we may switch to processing this interrupt.
      in(IN_N_INT7),  // TODO: Bug - no way to clock interrupt register to read (INT_IN_CLK) so bodge IN_N_INT7 to do it.
      out(OUT_N_PC0) | in(IN_N_MMU0),
      out(OUT_N_PC1) | in(IN_N_MMU1),
      out(OUT_N_PC2) | in(IN_N_MMU2),
      multi(
          MULTI_N_PC_INC),  // Happens on falling edge, so make sure not to let it affect the load into MMU2.
      out(OUT_N_MMU) | in(IN_N_OPCODE0) |
      multi(MULTI_N_RESET_UOP_COUNT), // Fetch opcode and reset micro-op counter
  );
  // Check for interrupt on fetch
  WRITE_INT_FLAG(
      Opcode::FETCH,
      1,
      0, // Skip here. We start at 2.
      0,
      bus(static_cast<uint8_t>(Opcode::HANDLE_INTERRUPT)) | out(OUT_N_CTRLLOGIC) |
      in(IN_N_OPCODE0) | multi(MULTI_N_RESET_UOP_COUNT),
  );

  // Page fault

  // Handle interrupt
  // TODO: Loads hard-coded address to jump to. Use interrupt vector?
  WRITE_AUX(
      Opcode::HANDLE_INTERRUPT,
      0,
  // Save return address into memory at 0, 1, 2. Save A, B, TASK registers. Disable interrupts.
      bus(0) | out(OUT_N_CTRLLOGIC) | in(IN_N_MMU0) | multi(MULTI_N_UNSET_INT_ENABLE),
      bus(0) | out(OUT_N_CTRLLOGIC) | in(IN_N_MMU1),
      bus(0) | out(OUT_N_CTRLLOGIC) | in(IN_N_MMU2),
      out(OUT_N_PC0) | in(IN_N_MMU),
      bus(1) | out(OUT_N_CTRLLOGIC) | in(IN_N_MMU0),
      out(OUT_N_PC1) | in(IN_N_MMU),
      bus(2) | out(OUT_N_CTRLLOGIC) | in(IN_N_MMU0),
      out(OUT_N_PC2) | in(IN_N_MMU),
      bus(3) | out(OUT_N_CTRLLOGIC) | in(IN_N_MMU0),
      out(OUT_N_A) | in(IN_N_MMU),
      bus(4) | out(OUT_N_CTRLLOGIC) | in(IN_N_MMU0),
      out(OUT_N_B) | in(IN_N_MMU),
      bus(5) | out(OUT_N_CTRLLOGIC) | in(IN_N_MMU0),
      out(OUT_N_TASK) | in(IN_N_MMU),
      bus(0) | out(OUT_N_CTRLLOGIC) | in(IN_N_TASK),  // TASK = 0.
      bus(1) | out(OUT_N_CTRLLOGIC) | in(IN_N_OPCODE1),  // Continue instruction.
  )
  WRITE_AUX(
      Opcode::HANDLE_INTERRUPT,
      1,
      bus(0) | out(OUT_N_CTRLLOGIC) | in(IN_N_PC0),
      bus(0) | out(OUT_N_CTRLLOGIC) | in(IN_N_PC1),
      bus(0x14) | out(OUT_N_CTRLLOGIC) |
      in(IN_N_PC2),  // Load 0x140000 = 0x100000 + 0x040000 = 256K, halfway through EEPROM.
      bus(static_cast<uint8_t>(Opcode::FETCH)) | out(OUT_N_CTRLLOGIC) | in(IN_N_OPCODE0) |
      multi(MULTI_N_RESET_UOP_COUNT)
  );
  // LDA immediate
  writeLoadImmediate(Opcode::LDA_IMM, IN_N_A);
  // LDB immediate
  writeLoadImmediate(Opcode::LDB_IMM, IN_N_B);
  // LDM0 immediate
  writeLoadImmediate(Opcode::LDM0_IMM, IN_N_M0);

  // ADD
  WRITE_NO_AUX(
      Opcode::ADD,
      out(OUT_N_SUM) | in(IN_N_A),
      bus(static_cast<uint8_t>(Opcode::FETCH)) | out(OUT_N_CTRLLOGIC) | in(IN_N_OPCODE0) |
      multi(MULTI_N_RESET_UOP_COUNT)
  );

  // SUB
  WRITE_NO_AUX(
      Opcode::SUB,
      out(OUT_N_SUM) | in(IN_N_A) | multi(MULTI_N_SUB),
      bus(static_cast<uint8_t>(Opcode::FETCH)) | out(OUT_N_CTRLLOGIC) | in(IN_N_OPCODE0) |
      multi(MULTI_N_RESET_UOP_COUNT)
  );

  // JUMP
  WRITE_NO_AUX(
      Opcode::JUMP,
  // Load next 3 bytes into M0, M1, M2
      out(OUT_N_PC0) | in(IN_N_MMU0),
      out(OUT_N_PC1) | in(IN_N_MMU1),
      out(OUT_N_PC2) | in(IN_N_MMU2),
      out(OUT_N_MMU) | in(IN_N_M0) | multi(MULTI_N_PC_INC),
      out(OUT_N_PC0) | in(IN_N_MMU0),
      out(OUT_N_PC1) | in(IN_N_MMU1),
      out(OUT_N_PC2) | in(IN_N_MMU2),
      out(OUT_N_MMU) | in(IN_N_M1) | multi(MULTI_N_PC_INC),
      out(OUT_N_PC0) | in(IN_N_MMU0),
      out(OUT_N_PC1) | in(IN_N_MMU1),
      out(OUT_N_PC2) | in(IN_N_MMU2),
      out(OUT_N_MMU) | in(IN_N_M2) | multi(MULTI_N_PC_INC),
  // Load PC with value from memory.
      out(OUT_N_M0) | in(IN_N_PC0),
      out(OUT_N_M1) | in(IN_N_PC1),
      out(OUT_N_M2) | in(IN_N_PC2),
      bus(static_cast<uint8_t>(Opcode::FETCH)) | out(OUT_N_CTRLLOGIC) | in(IN_N_OPCODE0) |
      multi(MULTI_N_RESET_UOP_COUNT)
  );

  // DISPLAY
  WRITE_NO_AUX(
      Opcode::DISPLAY,
      out(OUT_N_A) | in(IN_N_DISP),
      bus(static_cast<uint8_t>(Opcode::FETCH)) | out(OUT_N_CTRLLOGIC) | in(IN_N_OPCODE0) |
      multi(MULTI_N_RESET_UOP_COUNT)
  );

  // SWAP
  WRITE_NO_AUX(
      Opcode::SWAP,
      out(OUT_N_A) | in(IN_N_M0),
      out(OUT_N_B) | in(IN_N_A),
      out(OUT_N_M0) | in(IN_N_B),
      bus(static_cast<uint8_t>(Opcode::FETCH)) | out(OUT_N_CTRLLOGIC) | in(IN_N_OPCODE0) |
      multi(MULTI_N_RESET_UOP_COUNT)
  );

  // LDA_INT
  WRITE_NO_AUX(
      Opcode::LDA_INT,
      out(OUT_N_INTERRUPT) | in(IN_N_A),
      bus(static_cast<uint8_t>(Opcode::FETCH)) | out(OUT_N_CTRLLOGIC) | in(IN_N_OPCODE0) |
      multi(MULTI_N_RESET_UOP_COUNT)
  );

  // DUMP
  // Dumps the state to a connected device.
  WRITE_NO_AUX(
      Opcode::DUMP,
      out(OUT_N_A) | in(IN_N_INT0),
      out(OUT_N_B) | in(IN_N_INT0),
      out(OUT_N_M0) | in(IN_N_INT0),
      out(OUT_N_M1) | in(IN_N_INT0),
      out(OUT_N_M2) | in(IN_N_INT0),
      out(OUT_N_SUM) | in(IN_N_INT0),
      out(OUT_N_STATUS) | in(IN_N_INT0),
      out(OUT_N_INTERRUPT) | in(IN_N_INT0),
      out(OUT_N_PC0) | in(IN_N_INT0),
      out(OUT_N_PC1) | in(IN_N_INT0),
      out(OUT_N_PC2) | in(IN_N_INT0),
      out(OUT_N_TASK) | in(IN_N_INT0),
      bus(static_cast<uint8_t>(Opcode::FETCH)) | out(OUT_N_CTRLLOGIC) | in(IN_N_OPCODE0) |
      multi(MULTI_N_RESET_UOP_COUNT)
  );

  // RETURN_FROM_ISR
  WRITE_NO_AUX(
      Opcode::RETURN_FROM_ISR,
      bus(0) | out(OUT_N_CTRLLOGIC) |
      in(IN_N_MMU0),  // Load return address into memory at 0, 1, 2. Load A, B, TASK registers.
      bus(0) | out(OUT_N_CTRLLOGIC) | in(IN_N_MMU1),
      bus(0) | out(OUT_N_CTRLLOGIC) | in(IN_N_MMU2),
      out(OUT_N_MMU) | in(IN_N_PC0),
      bus(1) | out(OUT_N_CTRLLOGIC) | in(IN_N_MMU0),
      out(OUT_N_MMU) | in(IN_N_PC1),
      bus(2) | out(OUT_N_CTRLLOGIC) | in(IN_N_MMU0),
      out(OUT_N_MMU) | in(IN_N_PC2),
      bus(3) | out(OUT_N_CTRLLOGIC) | in(IN_N_MMU0),
      out(OUT_N_MMU) | in(IN_N_A),
      bus(4) | out(OUT_N_CTRLLOGIC) | in(IN_N_MMU0),
      out(OUT_N_MMU) | in(IN_N_B),
      bus(5) | out(OUT_N_CTRLLOGIC) | in(IN_N_MMU0),
      out(OUT_N_MMU) | in(IN_N_TASK) | multi(
          MULTI_N_SET_INT_ENABLE),  // If we are executing this instruction, interrupts were enabled before.
      bus(static_cast<uint8_t>(Opcode::FETCH)) | out(OUT_N_CTRLLOGIC) | in(IN_N_OPCODE0) |
      multi(MULTI_N_RESET_UOP_COUNT)
  );

  // ENABLE_INTERRUPTS
  WRITE_NO_AUX(
      Opcode::ENABLE_INTERRUPTS,
      multi(MULTI_N_SET_INT_ENABLE),
      bus(static_cast<uint8_t>(Opcode::FETCH)) | out(OUT_N_CTRLLOGIC) | in(IN_N_OPCODE0) |
      multi(MULTI_N_RESET_UOP_COUNT)
  );

  // DISABLE_INTERRUPTS
  WRITE_NO_AUX(
      Opcode::DISABLE_INTERRUPTS,
      multi(MULTI_N_UNSET_INT_ENABLE),
      bus(static_cast<uint8_t>(Opcode::FETCH)) | out(OUT_N_CTRLLOGIC) | in(IN_N_OPCODE0) |
      multi(MULTI_N_RESET_UOP_COUNT)
  );

  // IN_DEV_0
  WRITE_NO_AUX(
      Opcode::IN_DEV_0,
      out(OUT_N_INT0) | in(IN_N_A),
      bus(static_cast<uint8_t>(Opcode::FETCH)) | out(OUT_N_CTRLLOGIC) | in(IN_N_OPCODE0) |
      multi(MULTI_N_RESET_UOP_COUNT)
  );

  // OUT_IMM_DEV_0
  WRITE_NO_AUX(
      Opcode::OUT_IMM_DEV_0,
      out(OUT_N_PC0) | in(IN_N_MMU0),  // Load next byte to send to device.
      out(OUT_N_PC1) | in(IN_N_MMU1),
      out(OUT_N_PC2) | in(IN_N_MMU2),
      out(OUT_N_MMU) | in(IN_N_INT0) | multi(MULTI_N_PC_INC),
      bus(static_cast<uint8_t>(Opcode::FETCH)) | out(OUT_N_CTRLLOGIC) | in(IN_N_OPCODE0) |
      multi(MULTI_N_RESET_UOP_COUNT)
  );

  // COMPARE
  // TODO: Can't tell ALU to save flags AND do subtraction at the same time. Need to bodge in a new IN signal for it.
  WRITE_NO_AUX(
      Opcode::COMPARE,
      multi(MULTI_N_SUB) | in(IN_N_INT6), // TODO: Bodged.
      bus(static_cast<uint8_t>(Opcode::FETCH)) | out(OUT_N_CTRLLOGIC) | in(IN_N_OPCODE0) |
      multi(MULTI_N_RESET_UOP_COUNT)
  );

  // JUMP_IF_ZERO
  // Bit 0: Interrupt enable
  // Bit 1: Carry flag
  // Bit 2: Zero flag
  WRITE_AUX_MASK(
      Opcode::JUMP_IF_ZERO,
      0b0100,  // Only care about zero flag
      0b0000,
      out(OUT_N_STATUS) | in(IN_N_OPCODE1),
      multi(MULTI_N_PC_INC), // Not zero, so don't branch. But still consume the address.
      multi(MULTI_N_PC_INC),
      multi(MULTI_N_PC_INC),
      bus(static_cast<uint8_t>(Opcode::FETCH)) | out(OUT_N_CTRLLOGIC) | in(IN_N_OPCODE0) |
      multi(MULTI_N_RESET_UOP_COUNT)
  );
  WRITE_AUX_MASK(
      Opcode::JUMP_IF_ZERO,
      0b1100,
      0b0100,
      0, // Part of common instruction.
  // On the second microop, we are here if the zero flag is true. So, branch.
      out(OUT_N_PC0) | in(IN_N_MMU0),
      out(OUT_N_PC1) | in(IN_N_MMU1),
      out(OUT_N_PC2) | in(IN_N_MMU2),
      out(OUT_N_MMU) | in(IN_N_M0) | multi(MULTI_N_PC_INC),
      out(OUT_N_PC0) | in(IN_N_MMU0),
      out(OUT_N_PC1) | in(IN_N_MMU1),
      out(OUT_N_PC2) | in(IN_N_MMU2),
      out(OUT_N_MMU) | in(IN_N_M1) | multi(MULTI_N_PC_INC),
      out(OUT_N_PC0) | in(IN_N_MMU0),
      out(OUT_N_PC1) | in(IN_N_MMU1),
      out(OUT_N_PC2) | in(IN_N_MMU2),
      out(OUT_N_MMU) | in(IN_N_M2) | multi(
          MULTI_N_PC_INC),  // TODO: Can optimise by loading last one into PC2, not M2? Incrementing at the same time though.
      out(OUT_N_M0) | in(IN_N_PC0),
      out(OUT_N_M1) | in(IN_N_PC1),
      bus(0b1100) | out(OUT_N_CTRLLOGIC) | in(IN_N_OPCODE1)  // Go to next part of the instruction.
  );
  WRITE_AUX_MASK(
      Opcode::JUMP_IF_ZERO,
      0b1100,
      0b1100,  // Continuation of previous instruction.
      out(OUT_N_M2) | in(IN_N_PC2),
      bus(static_cast<uint8_t>(Opcode::FETCH)) | out(OUT_N_CTRLLOGIC) | in(IN_N_OPCODE0) |
      multi(MULTI_N_RESET_UOP_COUNT)
  );

  // JUMP_IF_ZERO_HACKED - TODO: Remove.
  WRITE_NO_AUX(
      Opcode::JUMP_IF_ZERO_HACKED,
      0, // First step was to load into Opcode1.
      multi(MULTI_N_PC_INC), // Not zero, so don't branch. But still consume the address.
      multi(MULTI_N_PC_INC),
      multi(MULTI_N_PC_INC),
      bus(static_cast<uint8_t>(Opcode::FETCH)) | out(OUT_N_CTRLLOGIC) | in(IN_N_OPCODE0) |
      multi(MULTI_N_RESET_UOP_COUNT)
  );
  WRITE_AUX(
      Opcode::JUMP_IF_ZERO_HACKED,
      0,
      out(OUT_N_A) | in(IN_N_OPCODE1),
      out(OUT_N_PC0) | in(IN_N_MMU0),  // If we're still here, it's 0.
      out(OUT_N_PC1) | in(IN_N_MMU1),
      out(OUT_N_PC2) | in(IN_N_MMU2),
      out(OUT_N_MMU) | in(IN_N_M0) | multi(MULTI_N_PC_INC),
      out(OUT_N_PC0) | in(IN_N_MMU0),
      out(OUT_N_PC1) | in(IN_N_MMU1),
      out(OUT_N_PC2) | in(IN_N_MMU2),
      out(OUT_N_MMU) | in(IN_N_M1) | multi(MULTI_N_PC_INC),
      out(OUT_N_PC0) | in(IN_N_MMU0),
      out(OUT_N_PC1) | in(IN_N_MMU1),
      out(OUT_N_PC2) | in(IN_N_MMU2),
      out(OUT_N_MMU) | in(IN_N_M2) | multi(MULTI_N_PC_INC),
      out(OUT_N_M0) | in(IN_N_PC0),
      out(OUT_N_M1) | in(IN_N_PC1),
      out(OUT_N_M2) | in(IN_N_PC2),
      bus(static_cast<uint8_t>(Opcode::FETCH)) | out(OUT_N_CTRLLOGIC) | in(IN_N_OPCODE0) |
      multi(MULTI_N_RESET_UOP_COUNT)
  );

  // SETUP_MEMORY_PROTECTION
  // Write the contents of M0 into the memory protection data for the current task. Expects A to be 0.
  // Set the page protection bytes to the contents of M0.
  WRITE_NO_AUX(
      Opcode::SETUP_MEMORY_PROTECTION,
      bus(1 << 4) | out(OUT_N_CTRLLOGIC) | in(IN_N_B),
      mlu(MLU_MUL) | out(OUT_N_MLU) |
      in(IN_N_MMU1),  // Load low 4 bits of A into high 4 bits of MMU1, by shifting up 4.
      mlu(MLU_DIV) | out(OUT_N_MLU) |
      in(IN_N_MMU2),  // Load high 4 bits of A into low 4 bits of MMU2, by shifting down 4. 5th bit of MMU2 is 0.
      out(OUT_N_M0) | in(IN_N_MMU_CONTROL),
      out(OUT_N_A) | in(IN_N_M1),  // Save A.
      mlu(MLU_DIV) | out(OUT_N_MLU) | in(IN_N_A),  // A = (A >> 4).
      bus(0b10000) | out(OUT_N_CTRLLOGIC) | in(IN_N_B), // B = 0b10000.
      mlu(MLU_OR) | out(OUT_N_MLU) |
      in(IN_N_MMU2), // MMU2 = A | 0b10000.  // Now 5th bit of MMU2 is 1.
      out(OUT_N_M0) | in(IN_N_MMU_CONTROL),
      out(OUT_N_M1) | in(IN_N_A), // Restore A.
      bus(1) | out(OUT_N_CTRLLOGIC) |
      in(IN_N_B),  // If we are here, carry is 0 so we aren't done. Load B for incrementing.
      in(IN_N_INT6), // TODO: Bodged. Load ALU flags into status register.
      out(OUT_N_STATUS) | in(IN_N_OPCODE1),
      out(OUT_N_SUM) | in(IN_N_A) | multi(MULTI_N_RESET_UOP_COUNT), // Increment A and loop.
  );
  // Override in the case of the carry bit.
  WRITE_AUX_MASK(
      Opcode::SETUP_MEMORY_PROTECTION,
      0b0010,  // Only care about carry bit.
      0b0010,  // If we have the carry bit set, we are done.
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, // Skip the first 13 micro-ops.
      bus(static_cast<uint8_t>(Opcode::FETCH)) | out(OUT_N_CTRLLOGIC) | in(IN_N_OPCODE0) |
      multi(MULTI_N_RESET_UOP_COUNT)
  );

  // STA_ADDR
  WRITE_NO_AUX(
      Opcode::STA_ADDR,
      out(OUT_N_PC0) | in(IN_N_MMU0),
      out(OUT_N_PC1) | in(IN_N_MMU1),
      out(OUT_N_PC2) | in(IN_N_MMU2),
      out(OUT_N_MMU) | in(IN_N_M0) | multi(MULTI_N_PC_INC),
      out(OUT_N_PC0) | in(IN_N_MMU0),
      out(OUT_N_PC1) | in(IN_N_MMU1),
      out(OUT_N_PC2) | in(IN_N_MMU2),
      out(OUT_N_MMU) | in(IN_N_M1) | multi(MULTI_N_PC_INC),
      out(OUT_N_PC0) | in(IN_N_MMU0),
      out(OUT_N_PC1) | in(IN_N_MMU1),
      out(OUT_N_PC2) | in(IN_N_MMU2),
      out(OUT_N_MMU) | in(IN_N_MMU2) | multi(MULTI_N_PC_INC),
      out(OUT_N_M0) | in(IN_N_MMU0),
      out(OUT_N_M1) | in(IN_N_MMU1),
      out(OUT_N_A) | in(IN_N_MMU),
      bus(static_cast<uint8_t>(Opcode::FETCH)) | out(OUT_N_CTRLLOGIC) | in(IN_N_OPCODE0) |
      multi(MULTI_N_RESET_UOP_COUNT)
  );

  // LDA_ADDR
  WRITE_NO_AUX(
      Opcode::LDA_ADDR,
      out(OUT_N_PC0) | in(IN_N_MMU0),
      out(OUT_N_PC1) | in(IN_N_MMU1),
      out(OUT_N_PC2) | in(IN_N_MMU2),
      out(OUT_N_MMU) | in(IN_N_M0) | multi(MULTI_N_PC_INC),
      out(OUT_N_PC0) | in(IN_N_MMU0),
      out(OUT_N_PC1) | in(IN_N_MMU1),
      out(OUT_N_PC2) | in(IN_N_MMU2),
      out(OUT_N_MMU) | in(IN_N_M1) | multi(MULTI_N_PC_INC),
      out(OUT_N_PC0) | in(IN_N_MMU0),
      out(OUT_N_PC1) | in(IN_N_MMU1),
      out(OUT_N_PC2) | in(IN_N_MMU2),
      out(OUT_N_MMU) | in(IN_N_MMU2) | multi(MULTI_N_PC_INC),
      out(OUT_N_M0) | in(IN_N_MMU0),
      out(OUT_N_M1) | in(IN_N_MMU1),
      out(OUT_N_MMU) | in(IN_N_A),
      bus(static_cast<uint8_t>(Opcode::FETCH)) | out(OUT_N_CTRLLOGIC) | in(IN_N_OPCODE0) |
      multi(MULTI_N_RESET_UOP_COUNT)
  );

  // SYSCALL
  // TODO: Copied from HANDLE_INTERRUPT. Except, don't save A and B so they can be used for syscall result.
  WRITE_NO_AUX(
      Opcode::SYSCALL,
      bus(0) | out(OUT_N_CTRLLOGIC) | in(IN_N_MMU0) | multi(MULTI_N_UNSET_INT_ENABLE),
      bus(0) | out(OUT_N_CTRLLOGIC) | in(IN_N_MMU1),
      bus(0) | out(OUT_N_CTRLLOGIC) | in(IN_N_MMU2),
      out(OUT_N_PC0) | in(IN_N_MMU),
      bus(1) | out(OUT_N_CTRLLOGIC) | in(IN_N_MMU0),
      out(OUT_N_PC1) | in(IN_N_MMU),
      bus(2) | out(OUT_N_CTRLLOGIC) | in(IN_N_MMU0),
      out(OUT_N_PC2) | in(IN_N_MMU),
      bus(3) | out(OUT_N_CTRLLOGIC) | in(IN_N_MMU0),
      out(OUT_N_TASK) | in(IN_N_MMU),
      bus(0) | out(OUT_N_CTRLLOGIC) | in(IN_N_TASK),
      bus(0) | out(OUT_N_CTRLLOGIC) | in(IN_N_PC0),
      bus(0) | out(OUT_N_CTRLLOGIC) | in(IN_N_PC1),
      bus(0x12) | out(OUT_N_CTRLLOGIC) |
      in(IN_N_PC2),  // Load 0x140000 = 0x100000 + 0x040000 = 256K, halfway through EEPROM.
      bus(static_cast<uint8_t>(Opcode::FETCH)) | out(OUT_N_CTRLLOGIC) | in(IN_N_OPCODE0) |
      multi(MULTI_N_RESET_UOP_COUNT)
  )

  // RETURN_FROM_SYSCALL
  WRITE_NO_AUX(
      Opcode::RETURN_FROM_SYSCALL,
      bus(0) | out(OUT_N_CTRLLOGIC) |
      in(IN_N_MMU0),  // Load return address into memory at 0, 1, 2. Load A, B, TASK registers.
      bus(0) | out(OUT_N_CTRLLOGIC) | in(IN_N_MMU1),
      bus(0) | out(OUT_N_CTRLLOGIC) | in(IN_N_MMU2),
      out(OUT_N_MMU) | in(IN_N_PC0),
      bus(1) | out(OUT_N_CTRLLOGIC) | in(IN_N_MMU0),
      out(OUT_N_MMU) | in(IN_N_PC1),
      bus(2) | out(OUT_N_CTRLLOGIC) | in(IN_N_MMU0),
      out(OUT_N_MMU) | in(IN_N_PC2),
      bus(3) | out(OUT_N_CTRLLOGIC) | in(IN_N_MMU0),
      out(OUT_N_MMU) | in(IN_N_TASK) | multi(MULTI_N_SET_INT_ENABLE),
      bus(static_cast<uint8_t>(Opcode::FETCH)) | out(OUT_N_CTRLLOGIC) | in(IN_N_OPCODE0) |
      multi(MULTI_N_RESET_UOP_COUNT)
  );

  // START_TASK
  WRITE_NO_AUX(
      Opcode::START_TASK,
      out(OUT_N_PC0) | in(IN_N_MMU0),
      out(OUT_N_PC1) | in(IN_N_MMU1),
      out(OUT_N_PC2) | in(IN_N_MMU2),
      out(OUT_N_MMU) | in(IN_N_M0) | multi(MULTI_N_PC_INC),
      out(OUT_N_PC0) | in(IN_N_MMU0),
      out(OUT_N_PC1) | in(IN_N_MMU1),
      out(OUT_N_PC2) | in(IN_N_MMU2),
      out(OUT_N_MMU) | in(IN_N_M1) | multi(MULTI_N_PC_INC),
      out(OUT_N_PC0) | in(IN_N_MMU0),
      out(OUT_N_PC1) | in(IN_N_MMU1),
      out(OUT_N_PC2) | in(IN_N_MMU2),
      out(OUT_N_MMU) | in(IN_N_M2) | multi(MULTI_N_PC_INC),
      out(OUT_N_MMU) | in(IN_N_TASK),
      bus(static_cast<uint8_t>(Opcode::FETCH)) | out(OUT_N_CTRLLOGIC) | in(IN_N_OPCODE0) |
      multi(MULTI_N_RESET_UOP_COUNT)
  );
  return data_;
}
