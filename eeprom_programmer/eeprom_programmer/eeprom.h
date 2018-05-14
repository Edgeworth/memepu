#ifndef EEPROM_H_
#define EEPROM_H_
#include "common.h"

class EEPROM {
public:
  explicit EEPROM(uint32_t delay_us_);

  void write(uint32_t base, uint8_t* data, int size);
  void print(uint32_t base, int bytes);
  void writeByte(uint32_t addr, uint8_t val) { writeByte(addr, val, true); }
  virtual void writeByte(uint32_t addr, uint8_t val, bool check);
  void updateLed();
private:
	uint32_t delay_us;
  uint32_t last_blink = 0;;
  bool led_status = false;
};

class AT28C64 : public EEPROM {
public:
  // 10 ms delay to finish byte write operation.
  // Page write doesn't seem to work well.
  AT28C64() : EEPROM(10 * 1000) {}
};

class SST39SF040 : public EEPROM {
public:
  SST39SF040() : EEPROM(0) {}

  using EEPROM::writeByte;

  void writeByte(uint32_t addr, uint8_t val, bool check) override {
    EEPROM::writeByte(0x5555, 0xAA, false);
    EEPROM::writeByte(0x2AAA, 0x55, false);
    EEPROM::writeByte(0x5555, 0xA0, false);
    EEPROM::writeByte(addr, val, check);
  }
};

#endif