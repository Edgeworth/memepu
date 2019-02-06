#ifndef MEMEPU_CONTROL_H_
#define MEMEPU_CONTROL_H_

#include "common.h"
#include "asm.h"

class ControlLogic {
public:
  explicit ControlLogic(int eeprom_number) : data_(SIZE, 0), eeprom_number_(eeprom_number) {}

  std::string getBinaryData();

private:
  std::string data_;
  int eeprom_number_;
  static constexpr size_t SIZE = 1u << 19;

  // TODO: do more static analysis
  void put(uint32_t addr, uint32_t output) {
    verify_expr((addr & 0x03FFFF) == addr,
        "only 18 bits for address");  // 19th bit not currently used.
    data_[addr] = uint8_t((output >> (eeprom_number_ * 8)) & 0xFF);
  }

  // Writers:
  void writeNoAux(Opcode opcode0, uint32_t* microops, int num);
  void writeAux(Opcode opcode0, int aux, uint32_t* microops, int num);
  // Writes given that we only care about the aux bits set in aux_mask.
  void writeAuxMask(Opcode opcode0, int aux_mask, int aux, uint32_t* microops, int num);
  void writeIntFlag(Opcode opcode0, int int_flag, uint32_t* microops, int num);
  void writeMicroops(Opcode opcode0, int aux, int int_flag, int mmu_fault_flag, uint32_t* microops,
      int num);
  void write(Opcode opcode0, int aux, int int_flag, int mmu_flag, int microop_idx,
      uint32_t microop_data);

  // Instruction helpers:
  void writeLoadImmediate(Opcode opcode0, int in_signal);
};


#endif
