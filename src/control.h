#ifndef CONTROL_H_
#define CONTROL_H_

#include "common.h"

class ControlLogic {
public:
  explicit ControlLogic(int eeprom_number) : data_(SIZE, 0), eeprom_number_(eeprom_number) {}

  std::string generateControlData();

private:
  std::string data_;
  int eeprom_number_;
  static constexpr size_t SIZE = 1u << 19;

  // TODO: do more static analysis
  void put(uint32_t addr, uint32_t output) {
    verify_expr((addr & 0x03FFFF) == addr, "only 18 bits for address");  // Check only 18 bits
    data_[addr] = uint8_t((output >> (eeprom_number_ * 8)) & 0xFF);
  }

  void writeInstruction(uint8_t opcode0, uint32_t *microops, size_t num);
};


#endif
