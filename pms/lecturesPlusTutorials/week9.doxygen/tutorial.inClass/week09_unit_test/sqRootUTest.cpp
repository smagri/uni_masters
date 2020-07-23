#include "gtest/gtest.h"

TEST(SquareRootTest, PositiveNos) { 
    EXPECT_DOUBLE_EQ (18.0, square-root (324.0));
    EXPECT_DOUBLE_EQ (25.4, square-root (645.16));
    EXPECT_DOUBLE_EQ (50.332, square-root (2533.310224));
}

TEST (SquareRootTest, ZeroAndNegativeNos) { 
    ASSERT_EQ (0.0, square-root (0.0));
    ASSERT_EQ (NAN, square-root (-22.0));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
