#include <iostream>

using namespace std;

// Create two theads that access a variable
// Both threads read and increment variable only

int main(){

  thread t1(f1);
  thread t2(f2);
  thread t3(f3);
  
  return 0;
}
