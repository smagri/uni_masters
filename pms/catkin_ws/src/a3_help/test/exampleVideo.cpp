// Fixture BankAccountTest video
struct BankAccount : testing::Test
{

  int balance;
  
  BankAccountTest()
  {
    balance = ;
  }
  virtual ~BankAccountTest()
  {

  }
};


TEST(AccountTest, BankAccountStartsEmpty){

  // BankAccount class object instantiated.
  BankAccount account;

  EXPECT_EQ(0, account.balance);

  
}
