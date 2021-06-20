// Copyright 2019 E.
#ifndef MEMEPU_MLU_H_
#define MEMEPU_MLU_H_

#include "common.h"

class MLU {
 public:
  MLU() : data_(SIZE, 0) {}

  std::string getBinaryData();

 private:
  static constexpr size_t SIZE = 1u << 19;

  std::string data_;

  void put(uint32_t addr, uint8_t output) {
    verify((addr & 0x07FFFF) == addr && addr < SIZE,
        "only 19 bits for address");  // 19th bit not currently used.
    data_[addr] = output;
  }
};

#endif  // MEMEPU_MLU_H_
