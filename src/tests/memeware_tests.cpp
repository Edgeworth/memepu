// Copyright 2019 Eliot Courtney.
#include "gtest/gtest.h"
#include "memeware/microcode.h"
#include "memeware/constants.h"

namespace {

using MemewareTest = testing::Test;

TEST_F(MemewareTest, GenerateMluSliceFirmware) {
  std::vector<uint8_t> firmware = memeware::generateMluSliceFirmware();
  int expected_size = (1 << memeware::MLU_SLICE_DEPTH);
  ASSERT_EQ(expected_size, firmware.size());
}

TEST_F(MemewareTest, GenerateMluLookaheadFirmware) {
  std::vector<uint8_t> firmware = memeware::generateMluLookaheadFirmware();
  int expected_size = (1 << memeware::MLU_LOOKAHEAD_DEPTH);
  ASSERT_EQ(expected_size, firmware.size());
}

TEST_F(MemewareTest, GenerateMicrocodeFirmware) {
  std::vector<uint32_t> firmware = memeware::generateMicrocodeFirmware();
  int expected_size = (1 << memeware::MICROCODE_DEPTH);
  ASSERT_EQ(expected_size, firmware.size());
}

TEST_F(MemewareTest, GenerateMemeasmModel) {
  std::string model = memeware::generateMemeasmModel();
  EXPECT_FALSE(model.empty());
  // Should be valid JSON
  EXPECT_NE(std::string::npos, model.find("["));
  EXPECT_NE(std::string::npos, model.find("]"));
}

TEST_F(MemewareTest, MemeasmModelContainsOpcodes) {
  std::string model = memeware::generateMemeasmModel();
  // Check for common opcodes
  EXPECT_NE(std::string::npos, model.find("opcode"));
  EXPECT_NE(std::string::npos, model.find("mnemonic"));
}

TEST_F(MemewareTest, MluSliceFirmwareConsistency) {
  std::vector<uint8_t> firmware1 = memeware::generateMluSliceFirmware();
  std::vector<uint8_t> firmware2 = memeware::generateMluSliceFirmware();
  ASSERT_EQ(firmware1.size(), firmware2.size());
  for (size_t i = 0; i < firmware1.size(); i++) {
    EXPECT_EQ(firmware1[i], firmware2[i]) << "Mismatch at index " << i;
  }
}

TEST_F(MemewareTest, MluLookaheadFirmwareConsistency) {
  std::vector<uint8_t> firmware1 = memeware::generateMluLookaheadFirmware();
  std::vector<uint8_t> firmware2 = memeware::generateMluLookaheadFirmware();
  ASSERT_EQ(firmware1.size(), firmware2.size());
  for (size_t i = 0; i < firmware1.size(); i++) {
    EXPECT_EQ(firmware1[i], firmware2[i]) << "Mismatch at index " << i;
  }
}

TEST_F(MemewareTest, MicrocodeFirmwareConsistency) {
  std::vector<uint32_t> firmware1 = memeware::generateMicrocodeFirmware();
  std::vector<uint32_t> firmware2 = memeware::generateMicrocodeFirmware();
  ASSERT_EQ(firmware1.size(), firmware2.size());
  for (size_t i = 0; i < firmware1.size(); i++) {
    EXPECT_EQ(firmware1[i], firmware2[i]) << "Mismatch at index " << i;
  }
}

TEST_F(MemewareTest, MemeasmModelContainsRelativeFlag) {
  std::string model = memeware::generateMemeasmModel();
  EXPECT_NE(std::string::npos, model.find("imm_relative"));
}

}  // namespace
