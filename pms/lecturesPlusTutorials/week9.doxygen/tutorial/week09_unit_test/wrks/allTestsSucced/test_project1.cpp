#include "gtest/gtest.h"
#include "project1.h" // required as squareroot() is declared here.

TEST(SquareRootTest, PositiveNos) {
  // Gives a non-fatal error so futher failures in the unit test are
  // picked up.
  EXPECT_EQ (18.0, squareroot (324.0));
  EXPECT_EQ (25.4, squareroot (645.16));
  EXPECT_EQ (50.332, squareroot (2533.310224));
}

TEST (SquareRootTest, ZeroAndNegativeNos) {
  // Gives a fatal error which aborts the current unit test.
  ASSERT_EQ (0.0, squareroot (0.0));
  // !noWrks: ASSERT_EQ (-NAN, squareroot (-22.0));
  ASSERT_TRUE (isnan(squareroot(-22.0)));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
