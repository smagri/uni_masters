/#include <iostream>
#include <thread>

using namespace std;

void fn1(){

  cout << "Beauty is only skin-deep" << endl;
  for (int i=0; i>-100; i--)
      cout << "From t1: " << i << endl;

}

int main(){

  thread t1(fn1); // t1 starts running

  // Race condition solved with a mutex.  Particularly data races.

  
  return 0;
}
