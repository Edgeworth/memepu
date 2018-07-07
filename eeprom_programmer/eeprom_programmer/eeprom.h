#ifndef EEPROM_H_
#define EEPROM_H_
#include "common.h"

class EEPROM {
public:
  EEPROM(uint32_t delay_us_, bool debug_);

  void write(uint32_t base, uint8_t* data, int size);
  void print(uint32_t base, int bytes);
  void writeByte(uint32_t addr, uint8_t val) { writeByte(addr, val, true); }
  virtual void writeByte(uint32_t addr, uint8_t val, bool check);
  void updateLed();

  uint32_t numBytesWritten() { return num_bytes_written; }

private:
  // Time to complete a write operation properly.
	uint32_t delay_us;
  uint32_t last_blink = 0;;
  uint32_t num_bytes_written = 0;
  bool led_status = false;
  bool debug;
};

class AT28C64 : public EEPROM {
public:
  // 10 ms delay to finish byte write operation.
  // Page write doesn't seem to work well.
  explicit AT28C64(bool debug_ = false) : EEPROM(10 * 1000, debug_) {}
};

class SST39SF040 : public EEPROM {
public:
  explicit SST39SF040(bool debug_ = false) : EEPROM(10, debug_) {}

  using EEPROM::writeByte;

  void writeByte(uint32_t addr, uint8_t val, bool check) override {
    EEPROM::writeByte(0x5555, 0xAA, false);
    EEPROM::writeByte(0x2AAA, 0x55, false);
    EEPROM::writeByte(0x5555, 0xA0, false);
    EEPROM::writeByte(addr, val, check);
  }
};

#endif