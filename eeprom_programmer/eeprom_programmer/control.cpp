#include "control.h"
#include "eeprom.h"

namespace {

const uint32_t MAX = 1L << 19;

}

void runControl() {
  unsigned long start = millis();
  
  SST39SF040 eeprom;

  for (uint32_t i = 0; i < 256; ++i) {
  	eeprom.writeByte(i, i % 256);
  }

  printf("Written in %ldms\n", millis() - start);
  // eeprom.print(MAX - 8192, 8192);
  eeprom.print(0, 256);
}