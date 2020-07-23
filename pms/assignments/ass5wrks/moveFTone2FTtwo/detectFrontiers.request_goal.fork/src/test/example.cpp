#include <gtest/gtest.h>

// Fixture BankAccountTest
struct BankAccountTest : testing::Test
{
  BankAccount* account;
  BankAccountTest()
  {
    account = new BankAccount;
  }
  virtual ~BankAccountTest()
  {
    delete account;
  }
};


TEST_F(BankAccountTest, CanDepositMoney)
{
  account->deposit(100);
  EXPECT_EQ(100,account->balance);
}



struct account_state
{
  int initial_balance;
  int withdraw_amount;
  int final_balance;
  bool success;
  friend std::ostream& operator<<(std::ostream& os, const account_state& obj)
  {
    return os
      << "initial_balance: " << obj.initial_balance
      << " withdraw_amount: " << obj.withdraw_amount
      << " final_balance: " << obj.final_balance
      << " success: " << obj.success;
  }
};


struct WithdrawAccountTest : BankAccountTest, testing::WithParamInterface<account_state>
{
  WithdrawAccountTest()
  {
    account->balance = GetParam().initial_balance;
  }
};

TEST_P(WithdrawAccountTest, FinalBalance)
{
  auto as = GetParam();
  auto success = account->withdraw(as.withdraw_amount);
  EXPECT_EQ(as.final_balance,account->balance);
  EXPECT_EQ(as.success,success);
}


INSTANTIATE_TEST_CASE_P(Default, WithdrawAccountTest,
  testing::Values(
  account_state{100,50,50,true},
  account_state{100,200,100,false}
  ));




int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);

    // InitGoogleTest parses  command line arguments, you  can specify
    // your own arguments.

    // Run your .exe/binary file for this test with the --help flag to
    // find which arguments google tests supports.

    
    // To allow running of google tests.
    return RUN_ALL_TESTS();
}