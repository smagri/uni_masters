#include "gtest/gtest.h"
#include "project1.h"

TEST(SRT, PositiveNos) { 
  EXPECT_FLOAT_EQ (18.0, squareroot (324.0));
  EXPECT_FLOAT_EQ (25.4, squareroot (645.16));
  // !wrks: EXPECT_EQ (50.332, squareroot (2533.3102));
  //
  // So this is safer. Tells the compiler to expect some rounding for
  // a float number.
  EXPECT_FLOAT_EQ (50.3320, squareroot (2533.3102));
}

TEST (SRT, ZeroAndNegativeNos) { 
  ASSERT_FLOAT_EQ (0.0, squareroot (0.0));
  //ASSERT_EQ (-1, squareroot (-22.0));
  ASSERT_TRUE (isnan(squareroot (-22.0)));
}

double squareroot(const double, int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
