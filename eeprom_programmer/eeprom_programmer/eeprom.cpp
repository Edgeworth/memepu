#include "eeprom.h"

namespace {

enum {
  IO0 = A0,
  IO1 = A1,
  IO2 = A2,
  IO3 = A3,
  IO4 = A4,
  IO5 = A5,
  IO6 = 9,
  IO7 = 10,
  REG_CLK = 4,
  SFT_CLK = 3,
  SER = 2,
  NWE = 5,
  NOE = 6,
  LED_GREEN = 7,
  LED_RED = 8
};

const int IO_PINS[8] = {IO0, IO1, IO2, IO3, IO4, IO5, IO6, IO7};

// Shift register:
void writeShiftBit(bool b) {
  digitalWrite(SER, b ? HIGH : LOW);
  digitalWrite(SFT_CLK, HIGH);
  digitalWrite(SFT_CLK, LOW);
}

void loadAddress(uint32_t addr) {
  for (int i = 23; i >= 0; --i)
    writeShiftBit(addr & (1uL << i));
  digitalWrite(REG_CLK, HIGH);
  digitalWrite(REG_CLK, LOW);
}

// IO pins:
void setupIOPins(int mode) {
  for (int pin : IO_PINS) {
    if (mode == INPUT) digitalWrite(pin, LOW);
    pinMode(pin, mode);
  }
}

uint8_t readIoPins() {
  uint8_t data = 0;
  for (int i = 7; i >= 0; --i) {
    data <<= 1;
    data |= (digitalRead(IO_PINS[i]) == HIGH);
  }
  return data;
}

void writeIoPins(uint8_t val) {
  for (int i = 0; i < 8; ++i)
    digitalWrite(IO_PINS[i], val & (1 << i) ? HIGH : LOW);
}

}

EEPROM::EEPROM(uint32_t delay_us_, bool debug_) : delay_us(delay_us_), debug(debug_) {
  // Never changes:
  pinMode(REG_CLK, OUTPUT);
  pinMode(SFT_CLK, OUTPUT);
  pinMode(SER, OUTPUT);
  pinMode(NWE, OUTPUT);
  pinMode(NOE, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_RED, OUTPUT);

  // Default state: Input, no output, no write, no LEDs
  setupIOPins(INPUT);
  digitalWrite(NOE, HIGH);
  digitalWrite(NWE, HIGH);
  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_RED, LOW);

  // Clocked:
  digitalWrite(REG_CLK, LOW);
  digitalWrite(SFT_CLK, LOW);
}

void EEPROM::print(uint32_t base, int bytes) {
  printf("Memory from %08lX (%d bytes):\n", base, bytes);

  digitalWrite(NOE, LOW);
  int rows = bytes / 16 + bool(bytes % 16);
  uint8_t vals[16];
  char ascii[16];
  for (int r = 0; r < rows; ++r) {
    for (int i = 0; i < 16; ++i) {
      loadAddress(base++);
      delayMicroseconds(1);
      vals[i] = readIoPins();
      ascii[i] = '.';
      if (isprint(vals[i])) ascii[i] = vals[i];
    }
    printf(
        "%08lX: %02hhX %02hhX %02hhX %02hhX %02hhX %02hhX %02hhX %02hhX %02hhX "
        "%02hhX %02hhX %02hhX %02hhX %02hhX %02hhX %02hhX %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",
        base, vals[0], vals[1], vals[2], vals[3], vals[4], vals[5], vals[6], vals[7], 
        vals[8], vals[9], vals[10], vals[11], vals[12], vals[13], vals[14], vals[15],
        ascii[0], ascii[1], ascii[2], ascii[3], ascii[4], ascii[5], ascii[6], ascii[7], 
        ascii[8], ascii[9], ascii[10], ascii[11], ascii[12], ascii[13], ascii[14], ascii[15]);
  }
  digitalWrite(NOE, HIGH);
}

void EEPROM::writeByte(uint32_t addr, uint8_t val, bool check) {
  updateLed();
  if (debug) printf("Writing %02hhX to %08lX\n", val, addr);
  setupIOPins(OUTPUT);

  loadAddress(addr);
  writeIoPins(val);
  digitalWrite(NWE, LOW);
  delayMicroseconds(1); 
  digitalWrite(NWE, HIGH);
  delayMicroseconds(delay_us);
  num_bytes_written++;

  if (check) {
    setupIOPins(INPUT);
    digitalWrite(NOE, LOW);
    delayMicroseconds(1);
    uint8_t read_val = readIoPins();
    if (read_val != val) {
      printf("FAILED to write %d at %08lX - read %d\n", val, addr, read_val);
      digitalWrite(LED_RED, HIGH);
    }
    digitalWrite(NOE, HIGH);
  }
}

void EEPROM::write(uint32_t base, uint8_t* data, int size) {
  if (size == 0) return;

  if (debug) printf("Writing %d bytes from %08lX.\n", size, base);
  uint32_t offset = 0;
  for (int i = 0; i < size; ++i) {
    writeByte(base + offset, data[offset]);
    offset++;
  }
}

void EEPROM::updateLed() {
  uint32_t now = millis();
  if (now - last_blink > 200) {
    led_status = !led_status;
    last_blink = now;
    digitalWrite(LED_GREEN, led_status ? HIGH : LOW);
  }
}