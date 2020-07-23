This program contains tests written using Google Test. You can use the
following command line flags to control its behavior:

Test Selection:
  --gtest_list_tests
      List the names of all tests instead of running them. The name of
      TEST(Foo, Bar) is "Foo.Bar".
  --gtest_filter=POSTIVE_PATTERNS[-NEGATIVE_PATTERNS]
      Run only the tests whose name matches one of the positive patterns but
      none of the negative patterns. '?' matches any single character; '*'
      matches any substring; ':' separates two patterns.
  --gtest_also_run_disabled_tests
      Run all disabled tests too.

Test Execution:
  --gtest_repeat=[COUNT]
      Run the tests repeatedly; use a negative count to repeat forever.
  --gtest_shuffle
      Randomize tests' orders on every iteration.
  --gtest_random_seed=[NUMBER]
      Random number seed to use for shuffling test orders (between 1 and
      99999, or 0 to use a seed based on the current time).

Test Output:
  --gtest_color=(yes|no|auto)
      Enable/disable colored output. The default is auto.
  --gtest_print_time=0
      Don't print the elapsed time of each test.
  --gtest_output=xml[:DIRECTORY_PATH/|:FILE_PATH]
      Generate an XML report in the given directory or with the given file
      name. FILE_PATH defaults to test_details.xml.
  --gtest_stream_result_to=HOST:PORT
      Stream test results to the given server.

Assertion Behavior:
  --gtest_death_test_style=(fast|threadsafe)
      Set the default death test style.
  --gtest_break_on_failure
      Turn assertion failures into debugger break-points.
  --gtest_throw_on_failure
      Turn assertion failures into C++ exceptions.
  --gtest_catch_exceptions=0
      Do not report exceptions as test failures. Instead, allow them
      to crash the program or throw a pop-up (on Windows).

Except for --gtest_list_tests, you can alternatively set the corresponding
environment variable of a flag (all letters in upper-case). For example, to
disable colored text output, you can either specify --gtest_color=no or set
the GTEST_COLOR environment variable to no.

For more information, please read the Google Test documentation at
http://code.google.com/p/googletest/. If you find a bug in Google Test
(not one in your own code or tests), please report it to
<googletestframework@googlegroups.com>.