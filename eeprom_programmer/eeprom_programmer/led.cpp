#include "led.h"
#include "eeprom.h"

namespace {
enum {
  B = 1 << 0,
  BR = 1 << 6,
  DOT = 1 << 5,
  BL = 1 << 1,
  M = 1 << 2,
  TL = 1 << 7,
  T = 1 << 3,
  TR = 1 << 4
};

uint8_t digitToLed(int digit) {
  constexpr uint8_t map[16] = {
    T | TL | TR | BL | BR | B,
    TR | BR,
    T | TR | M | BL | B,
    T | TR | M | BR | B,
    TL | TR | M | BR,
    T | TL | M | BR | B,
    T | TL | BL | M | B | BR,
    T | TR | BR,
    T | TL | TR | BL | BR | B | M,
    T | TL | TR | M | BR,
    T | TL | TR | M | BR | BL,
    TL | M | BL | B | BR,
    T | TL | BL | B,
    TL | M | BL | B | BR,
    T | M | B | TL | BL,
    T | M | TL | BL
  };
  return map[digit];
}

template<int Size>
uint8_t buildByte(uint16_t addr, const int(&bits)[Size]) {
  uint8_t byte = 0;
  for (int bit : bits) {
    byte <<= 1;
    byte |= (bool)(addr & (1uL << bit));
  }
  return byte;
}

uint8_t buildDataByte(uint16_t addr) {
  return buildByte(addr, {7, 6, 5, 4, 3, 2, 1, 0});
}

uint8_t buildSegByte(uint16_t addr) {
  return buildByte(addr, {9, 8});
}

uint8_t buildModeByte(uint16_t addr) {
  return buildByte(addr, {12, 11, 10});
}

int getDigit(uint8_t val, int dig, int base) {
  for (int i = 0; i < dig; ++i) {
    val /= base;
    if (val == 0) return -i - 1;
  }
  return val % base;
}
}

void runLed(bool debug) {
  AT28C64 eeprom;
  // Delay because hardware data protection prevents write for 5 ms on startup.
  delay(10);

  printf("Writing LED bytes");
  for (int i = 0; i < 8192; ++i) {
    const uint8_t data = buildDataByte(i);
    const int8_t data_signed = *reinterpret_cast<const int8_t*>(&data);
    const uint8_t seg = buildSegByte(i);
    const uint8_t mode = buildModeByte(i);
    const bool sign = mode & 1;
    const int base = (mode & (1 << 1)) ? 16 : 10;
    const int place = 3 - seg;  // digits place
    const int digit = getDigit(sign ? abs(data_signed) : data, place, base);

    if (debug) {
      printf("data %d, signed data %d, place: %d, base: %d, sign: %d, digit: %d\n",
    	    int(data), int(data_signed), int(place), int(base), int(sign), int(digit));
    }
    uint8_t val = digit;
    if (digit >= 0) {
    	if (debug) printf("writing normal digit\n");
    	val = digitToLed(digit);
    } else if (digit == -place && base == 16) {  // (h)FF
    	if (debug) printf("writing h\n");
    	val = TL | BL | M | BR;
    } else if (digit == -place + 1 && base == 16 && sign && data_signed < 0) {  // (-)hAF
    	if (debug) printf("writing neg sign (base 16)\n");
    	val = M;
    } else if (digit == -place && base == 10 && sign && data_signed < 0) {  // (-)10
    	if (debug) printf("writing neg sign (base 10)\n");
    	val = M;
    } else {
    	if (debug) printf("writing no dig\n");
    	val = 0;
    }
    eeprom.writeByte(i, val);
  }
}
