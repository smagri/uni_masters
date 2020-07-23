#include "gtest/gtest.h"
#include "project1.h"

TEST(fnReturnTrueTest, succedsAssert) { 
  ASSERT_TRUE (fnReturnTrue());
  //ASSERT_FALSE (fnReturnTrue());
}

TEST(fnReturnTrueTest, succedsExpects) { 
  EXPECT_TRUE (fnReturnTrue());
  //EXPECT_FALSE (fnReturnTrue());
}

double fnReturnTrue(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
