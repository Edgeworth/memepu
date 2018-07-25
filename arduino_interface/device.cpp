#include "device.h"

namespace {

constexpr int RING_SIZE = 64;

volatile int ring_start = 0;
volatile int ring_end = 0;
volatile uint8_t ring_buf[RING_SIZE];

uint8_t readBus() {
  uint8_t value = 0;
  for (int pin : BUS_PINS) {
    value >>= 1;
    value |= int(digitalRead(pin) == HIGH) << 7;
  }
  return value;
}

void writeBus(uint8_t value) {
  for (int pin : BUS_PINS) {
    digitalWrite(pin, value & 1);
    value >>= 1;
  }
}

int ringBufferSize() {
  if (ring_start > ring_end) 
    return RING_SIZE - ring_end + ring_start;
  return ring_end - ring_start;
}

}  // namespace

void peripheralIsr() {
  digitalWrite(INT_FLAG, LOW);
  ring_buf[ring_end] = readBus();
  ring_end = (ring_end + 1) % RING_SIZE;
}

void DeviceConnection::checkData() {
  while (ringBufferSize() > 0) {
    if (cur_cmd_ == -1) {
      printf("Error: Unprompted data from device, size: %d\n", ringBufferSize());
    }

    if (cur_cmd_ == 0) {
      if (cmd_seq_ == 0)
        printf("Dump (ring buffer size: %d)\n", ringBufferSize());
      printf("%s: %d\n", DUMP_STRS[cmd_seq_], ring_buf[ring_start]);

      cmd_seq_ = (cmd_seq_ + 1) % NUM_DUMP_REGS;
      // Dump finished.
      if (cmd_seq_ == 0)
        cur_cmd_ = -1;
    } else if (cur_cmd_ == 1) {
      if (ring_buf[ring_start] == 0) {  // End of data.
        cur_cmd_ = -1;
      } else {
        printf("%c", char(ring_buf[ring_start]));
      }
    }

    ring_start = (ring_start + 1) % RING_SIZE;
  }
}

void DeviceConnection::onRisingClock() {
  if (cur_cmd_ != -1)
    setBusMode(INPUT);
}

void DeviceConnection::onFallingClock() {
  // Output data to the device if we are asked to and we have something to write.
  if (digitalRead(INT_OUT_NCLK) == HIGH || cur_cmd_ == -1) return;

  setBusMode(OUTPUT);
  writeBus(cur_cmd_);
}


void DeviceConnection::sendDumpDataCommand() {
  // Send interrupt.
  digitalWrite(INT_FLAG, HIGH);
  cur_cmd_ = 0;
}

void DeviceConnection::sendReadByteCommand() {
  // Send interrupt.
  digitalWrite(INT_FLAG, HIGH);
  cur_cmd_ = 1;  // TODO: magic numbers.
}