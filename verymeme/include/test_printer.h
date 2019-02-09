#ifndef VERYMEME_TEST_PRINTER_H
#define VERYMEME_TEST_PRINTER_H

#include "common.h"

#include "gtest/gtest.h"

class TestPrinter : public ::testing::EmptyTestEventListener {
public:
  using UnitTest = ::testing::UnitTest;
  using TestSuite = ::testing::TestSuite;
  using TestPartResult = ::testing::TestPartResult;
  using TestInfo = ::testing::TestInfo;

  TestPrinter(bool print_individual_tests) : print_individual_tests_(print_individual_tests) {}

  void OnTestIterationStart(const UnitTest& unit_test, int iteration) override;
  void OnTestPartResult(const TestPartResult& result) override;
  void OnTestEnd(const TestInfo& test_info) override;
  void OnTestCaseEnd(const TestSuite& test_suite) override;
  void OnTestIterationEnd(const UnitTest& unit_test, int iteration) override;

private:
  bool print_individual_tests_ = false;
};

#endif  // VERYMEME_TEST_PRINTER_H
