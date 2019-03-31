#include "verymeme/test_printer.h"

namespace {
constexpr std::chrono::milliseconds TEST_UPDATE_INTERVAL{200};
}  // namespace

void TestPrinter::OnTestIterationStart(
    const UnitTest& unit_test, int iteration) {
  if (::testing::FLAGS_gtest_repeat != 1)
    printf("\nRepeating all tests (iteration %d) . . .\n\n", iteration + 1);

  if (::testing::FLAGS_gtest_shuffle)
    printf("Note: Randomizing tests' orders with a seed of %d .\n", unit_test.random_seed());

  printf("Running %d test(s) from %d test suite(s).\n", unit_test.test_to_run_count(),
      unit_test.test_suite_to_run_count());
  fflush(stdout);

  // Set-up test stuff:
  last_time_ = std::chrono::steady_clock::now();
  start_time_ = last_time_;
  total_test_count_ = unit_test.test_to_run_count();
  cur_test_count_ = 0;
  if (needs_newline_) {
    printf("\n");
    needs_newline_ = false;
  }
}

void TestPrinter::OnTestPartResult(const TestPartResult& result) {
  if (!result.failed()) return;
  printf("%s:%d: Failure\n%s\n", result.file_name(), result.line_number(), result.message());
  fflush(stdout);
}

void TestPrinter::OnTestEnd(const TestInfo& test_info) {
  cur_test_count_++;

  if (test_info.result()->Failed()) printf("[ FAILED  ] ");
  else if (print_individual_tests_) printf("[ TEST    ] ");
  else {
    auto now = std::chrono::steady_clock::now();
    if (now - last_time_ > TEST_UPDATE_INTERVAL) {
      last_time_ = now;
      const double elapsed_time = std::chrono::duration_cast<std::chrono::seconds>(
          now - start_time_).count();
      const double remaining_time =
          total_test_count_ * elapsed_time / cur_test_count_ - elapsed_time;
      printf("\r  %s [run %d/%d tests, %.2fs elapsed, ~%.2fs remaining]",
          test_info.test_case_name(),
          cur_test_count_, total_test_count_, elapsed_time, remaining_time);
      needs_newline_ = true;
    }
    return;
  }

  printf("%s.%s (%lld ms)", test_info.test_suite_name(), test_info.name(),
      test_info.result()->elapsed_time());
  if (test_info.value_param())
    printf(", where GetParam() = %s", test_info.value_param());
  printf("\n");
  fflush(stdout);
}

void TestPrinter::OnTestSuiteStart(const TestSuite& test_suite) {
  printf("[-RUNNING-] %d test(s) from %s\n", test_suite.test_to_run_count(), test_suite.name());
}

void TestPrinter::OnTestSuiteEnd(const TestSuite& test_suite) {
  printf("[-FINISH--] %d test(s) from %s (%lld ms total)", test_suite.test_to_run_count(),
      test_suite.name(), test_suite.elapsed_time());
  if (test_suite.type_param())
    printf(", with type param = %s", test_suite.type_param());
  printf("\n");
  fflush(stdout);
}

void TestPrinter::OnTestIterationEnd(const UnitTest& unit_test, int /*iteration*/) {
  printf("[=========] %d test(s) from %d test suite(s) ran. (%lld ms total)\n",
      unit_test.test_to_run_count(), unit_test.test_suite_to_run_count(), unit_test.elapsed_time());
  printf("[ PASSED  ] %d test(s)\n", unit_test.successful_test_count());
  printf("[ SKIPPED ] %d test(s)\n", unit_test.skipped_test_count());
  printf("[ FAILED  ] %d test(s)\n", unit_test.failed_test_count());
  printf("[ DISABLED] %d test(s)\n", unit_test.reportable_disabled_test_count());
  fflush(stdout);
}
