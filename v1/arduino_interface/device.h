// Copyright 2019 E.
#ifndef DEVICE_H_
#define DEVICE_H_

#include "common.h"

const int NUM_DUMP_REGS = 12;
const char* const DUMP_STRS[NUM_DUMP_REGS] = {
  "A", "B", "M0", "M1", "M2", "SUM", "STATUS", "INTERRUPT", "PC0",
  "PC1", "PC2", "TASK"
};

void peripheralIsr();

class DeviceConnection {
public:
  void checkData();
  void onRisingClock();
  void onFallingClock();

  void sendDumpDataCommand();
  void sendReadByteCommand();

private:
  volatile int cur_cmd_ = -1;
  volatile bool bus_mode_output_ = false;
  int cmd_seq_ = 0;
};

#endif  // DEVICE_H_