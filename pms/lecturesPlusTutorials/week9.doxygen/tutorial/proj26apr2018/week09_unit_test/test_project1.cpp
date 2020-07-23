#include "gtest/gtest.h"
#include "project1.h"
//#include "gtest/gtest_pred_impl.h"

// Using  EXPECT_EQ vs  ASSERT_EQ.  EXPECT_EQ  continues execution  of
// file if there  has been a failure in a  test, but ASSERT_EQ dosent,
// it aborts execution.

TEST(SquareRootTest, PositiveNos) {
  // wrks: as 18==18.0, ie expected == actual:
  //
  // note: squareroot() wrks, squreRoot or SquareRoot does not wrk for eg
  EXPECT_EQ (18.0, squareroot (324.0));
  
  // wrks: expected == actual:
  EXPECT_EQ (25.4, squareroot (645.16));

  // !wrks: expected 50.3321 == actual 50.332:
  // EXPECT_EQ (50.3321, squareroot (2533.310224));
  EXPECT_EQ (50.332, squareroot (2533.310224));

  // All EXPECT_EQ tests here => texts contiunes to below.
}

TEST (SquareRootTest, ZeroAndNegativeNos) {

  // All ASSERT_EQ tests here => test abort at first failure.
  ASSERT_EQ (0.0, squareroot (0.0));

  // !wrks: exlpected -1, actual is -nan
  // !wrks: ASSERT_EQ (-1, squareroot (-22.0));
  // !wrks: ASSERT_EQ (-nan, squareroot (-22.0));
  // !wrks: ASSERT_EQ (-NAN, squareroot (-22.0));
  // !wrks: ASSERT_EQ (-NaN, squareroot (-22.0));
  // !wrks: -1 is not returned: ASSERT_EQ (-1, squareroot (-22.0));

  // wrks: known as  a death assertions: ie if  return from squareroot
  // is  not  -1 with  a  -ve  number as  input  this  test flags  it.
  // However, I don't like this  method, better to fix squareroot() fn
  // to return the correct -nan/-NAN value.
  //
  //ASSERT_EXIT(squareroot(-22.0),::testing::ExitedWithCode(-1),
  //"Error: Negative Input");
  ASSERT_EQ (-1, squareroot (-22.0));
  
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
