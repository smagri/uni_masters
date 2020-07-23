#include "gtest/gtest.h"

TEST(RectangleTests, Area) {
  Rectangle rectangle;
  rectangle.setValues(2.0, 3.0)
  EXPECT_DOUBLE_EQ (18.0, square-root (324.0));
  
}

TEST (SquareRootTest, ZeroAndNegativeNos) { 
    ASSERT_EQ (0.0, square-root (0.0));
    ASSERT_EQ (NAN, square-root (-22.0));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

