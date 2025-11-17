// Copyright 2019 Eliot Courtney.
#include "gtest/gtest.h"
#include "Vkpu.h"
#include "memesim/simulator.h"
#include "memesim/cli.h"
#include "memesim/display.h"
#include "memeware/constants.h"

namespace {

using MemesimTest = testing::Test;

TEST_F(MemesimTest, InitializeKpu) {
  Vkpu kpu;
  memesim::initializeKpu(kpu);
  // After initialization, KPU should be in a valid state
  EXPECT_NO_THROW(memesim::clockKpu(kpu));
}

TEST_F(MemesimTest, ResetKpu) {
  Vkpu kpu;
  memesim::initializeKpu(kpu);
  memesim::clockKpu(kpu);
  memesim::resetKpu(kpu);
  // After reset, should be able to clock again
  EXPECT_NO_THROW(memesim::clockKpu(kpu));
}

TEST_F(MemesimTest, ClockMultipleTimes) {
  Vkpu kpu;
  memesim::initializeKpu(kpu);
  for (int i = 0; i < 10; i++) {
    EXPECT_NO_THROW(memesim::clockKpu(kpu));
  }
}

TEST_F(MemesimTest, ResetAfterMultipleClocks) {
  Vkpu kpu;
  memesim::initializeKpu(kpu);
  for (int i = 0; i < 5; i++) {
    memesim::clockKpu(kpu);
  }
  memesim::resetKpu(kpu);
  // Should be able to continue after reset
  EXPECT_NO_THROW(memesim::clockKpu(kpu));
}

TEST_F(MemesimTest, SimulatorConstruction) {
  EXPECT_NO_THROW({
    memesim::Simulator sim;
  });
}

TEST_F(MemesimTest, SimulatorScheduleCommand) {
  memesim::Simulator sim;
  auto receiver = std::make_shared<ConcurrentQueue<memesim::Simulator::Response>>();

  memesim::Simulator::Cmd cmd;
  cmd.type = memesim::Simulator::Cmd::Type::GET_CPU_STATE;
  cmd.receiver = receiver;

  EXPECT_NO_THROW(sim.scheduleCommand(cmd));
}

TEST_F(MemesimTest, CpuStateMessageStructure) {
  memesim::Simulator::CpuStateMessage state;
  state.bus = 0x1234;
  state.tmp0 = 0x5678;
  state.tmp1 = 0x9abc;
  state.opcode = 0x10;

  EXPECT_EQ(0x1234u, state.bus);
  EXPECT_EQ(0x5678u, state.tmp0);
  EXPECT_EQ(0x9abcu, state.tmp1);
  EXPECT_EQ(0x10u, state.opcode);
}

TEST_F(MemesimTest, VgaStateMessageSize) {
  memesim::Simulator::VgaStateMessage vga_state;
  size_t expected_size = memeware::VGA_HEIGHT * memeware::VGA_WIDTH;
  EXPECT_EQ(expected_size, sizeof(vga_state.pixels));
}

TEST_F(MemesimTest, VgaStateMessageInitialization) {
  memesim::Simulator::VgaStateMessage vga_state;
  // Initialize some pixels
  vga_state.pixels[0] = 0xFF;
  vga_state.pixels[100] = 0x80;
  vga_state.pixels[memeware::VGA_HEIGHT * memeware::VGA_WIDTH - 1] = 0x00;

  EXPECT_EQ(0xFF, vga_state.pixels[0]);
  EXPECT_EQ(0x80, vga_state.pixels[100]);
  EXPECT_EQ(0x00, vga_state.pixels[memeware::VGA_HEIGHT * memeware::VGA_WIDTH - 1]);
}

TEST_F(MemesimTest, CommandTypes) {
  using CmdType = memesim::Simulator::Cmd::Type;

  memesim::Simulator::Cmd cmd1;
  cmd1.type = CmdType::RUN;
  EXPECT_EQ(CmdType::RUN, cmd1.type);

  memesim::Simulator::Cmd cmd2;
  cmd2.type = CmdType::STOP;
  EXPECT_EQ(CmdType::STOP, cmd2.type);

  memesim::Simulator::Cmd cmd3;
  cmd3.type = CmdType::STEP;
  EXPECT_EQ(CmdType::STEP, cmd3.type);

  memesim::Simulator::Cmd cmd4;
  cmd4.type = CmdType::SET_BREAKPOINT;
  EXPECT_EQ(CmdType::SET_BREAKPOINT, cmd4.type);

  memesim::Simulator::Cmd cmd5;
  cmd5.type = CmdType::GET_CPU_STATE;
  EXPECT_EQ(CmdType::GET_CPU_STATE, cmd5.type);

  memesim::Simulator::Cmd cmd6;
  cmd6.type = CmdType::GET_VGA_STATE;
  EXPECT_EQ(CmdType::GET_VGA_STATE, cmd6.type);

  memesim::Simulator::Cmd cmd7;
  cmd7.type = CmdType::QUIT;
  EXPECT_EQ(CmdType::QUIT, cmd7.type);
}

TEST_F(MemesimTest, CommandArgsDefault) {
  memesim::Simulator::CmdArgs args;
  EXPECT_EQ(0, args.i32_0);
  EXPECT_EQ(0, args.i32_1);
}

TEST_F(MemesimTest, CommandArgsValues) {
  memesim::Simulator::CmdArgs args;
  args.i32_0 = 42;
  args.i32_1 = -100;

  EXPECT_EQ(42, args.i32_0);
  EXPECT_EQ(-100, args.i32_1);
}

TEST_F(MemesimTest, RegistersInCpuState) {
  memesim::Simulator::CpuStateMessage state;
  // Set all registers
  for (int i = 0; i < 32; i++) {
    state.regs[i] = i * 100;
  }

  // Verify all registers
  for (int i = 0; i < 32; i++) {
    EXPECT_EQ(i * 100u, state.regs[i]);
  }
}

TEST_F(MemesimTest, PcRegisterIndex) {
  // PC should be register 31
  EXPECT_EQ(31, memeware::PC_REG);
}

TEST_F(MemesimTest, NumRegisters) {
  EXPECT_EQ(32, memeware::NUM_REG);
}

TEST_F(MemesimTest, VgaDimensions) {
  EXPECT_EQ(320, memeware::VGA_WIDTH);
  EXPECT_EQ(240, memeware::VGA_HEIGHT);
}

TEST_F(MemesimTest, MmioAddresses) {
  // Test that MMIO addresses are defined
  EXPECT_NE(0u, memeware::MMIO_VRAM_BASE);
  EXPECT_NE(0u, memeware::MMIO_MOUSE);
  EXPECT_NE(0u, memeware::MMIO_KEYBOARD);
  EXPECT_NE(0u, memeware::MMIO_INTERRUPT_CLEAR);
}

TEST_F(MemesimTest, MmioAddressesDistinct) {
  // Verify MMIO addresses are distinct
  EXPECT_NE(memeware::MMIO_VRAM_BASE, memeware::MMIO_MOUSE);
  EXPECT_NE(memeware::MMIO_VRAM_BASE, memeware::MMIO_KEYBOARD);
  EXPECT_NE(memeware::MMIO_VRAM_BASE, memeware::MMIO_INTERRUPT_CLEAR);
  EXPECT_NE(memeware::MMIO_MOUSE, memeware::MMIO_KEYBOARD);
  EXPECT_NE(memeware::MMIO_MOUSE, memeware::MMIO_INTERRUPT_CLEAR);
  EXPECT_NE(memeware::MMIO_KEYBOARD, memeware::MMIO_INTERRUPT_CLEAR);
}

TEST_F(MemesimTest, InterruptVector) {
  EXPECT_EQ(0u, memeware::INTERRUPT_VECTOR);
}

TEST_F(MemesimTest, OpwordSize) {
  EXPECT_EQ(1, memeware::OPWORD_SIZE);
}

using MemesimCliTest = testing::Test;

TEST_F(MemesimCliTest, CommandLineConstruction) {
  memesim::Simulator sim;
  EXPECT_NO_THROW({
    memesim::CommandLine cli(&sim);
  });
}

using MemesimDisplayTest = testing::Test;

TEST_F(MemesimDisplayTest, DisplayConstruction) {
  memesim::Simulator sim;
  EXPECT_NO_THROW({
    memesim::Display display(&sim);
  });
}

}  // namespace
