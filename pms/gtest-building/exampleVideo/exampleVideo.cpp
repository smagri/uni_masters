#include<iostream>
#include<gtest/gtest.h>

// BankAccount class/struct definition used in Test Fixure class/struct.
struct BankAccount
{
  int balance = 0;
  
  BankAccount(){
  }
  
  ~BankAccount(){
  }

  void deposit(int amount){
    balance += amount;
  }

  bool withdraw(int amount){

    if (amount <= balance){
      balance -= amount;
      return true;
    }
    else{
      return false;
    }
  }
  

};


// Test Fixture, ie data shared by all TEST()'s.  It gives us  an instance of
// BankAccount struct/ a bank account as above.
 // 
struct BankAccountTest : testing::Test{

  BankAccount* account;

  BankAccountTest(){
 
    account = new BankAccount;
  }

  virtual ~BankAccountTest(){
     
    delete account;
  }


};
  

// TEST_F indicates that we are using a Test Fixture. 
//
// specifically, TEST_F(BankAccountTest, ....) referst to using the
// test fixture called BankAccountTest.
//  
TEST_F(BankAccountTest, BankAccountStartsEmpty){
  
   // BankAccount class object instantiated.
  //
  // You don't want  to create an object for every  test/TEST() so you
  // create a  test fixture to have  the account object shared  by all
  // tests.
  //
   // BankAccount account;
  // EXPECT_EQ(0, account.balance);

  EXPECT_EQ(0, account->balance);
  
}

TEST_F(BankAccountTest, CanDepositMoney){
  
  account->deposit(100);
  
   EXPECT_EQ(100, account->balance);
  
}



// Parameterised tests---------------------------------------------------------:
// 
// ie TEST()'s  include testing of multiple parameters.
//

// Here we use  multiple instances of account_state  in the withdraw() method
// of BankAccount to do this.
struct account_state{
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

// New test fixture to share data between multiple parameterised
// tests/TESTS_P()'s
//
// Template data for WithParamInterface is account_state struct.
struct WithdrawAccountTest: BankAccountTest,
			    testing::WithParamInterface<account_state>{

  
  WithdrawAccountTest(){

    // GetParam() is used as each object of account_state will have a
    // different value for initial_balance.
    account->balance = GetParam().initial_balance;
  }
  
};

TEST_P(WithdrawAccountTest, FinalBalance){

  auto as = GetParam();  // puts account_state into as object
  auto success = account->withdraw(as.withdraw_amount);
  EXPECT_EQ(as.final_balance, account->balance);
  EXPECT_EQ(as.success, success);
}
//
// Provides data for the TEST_P() above to run. 
//
INSTANTIATE_TEST_CASE_P(Default, WithdrawAccountTest,
  testing::Values
  (
   // Create a couple of account states, or objects of account_state struct.
   //
   // {initial_balance, withdraw_amount, final_balance, success}
   account_state{100, 50, 50, true},
   account_state{100, 200, 100, false}
   
   
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
