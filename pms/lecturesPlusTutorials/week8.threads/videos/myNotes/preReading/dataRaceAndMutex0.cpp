#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

void fn1(){
  
  cout << "Beauty is only skin-deep" << endl;
  for (int i=0; i>-100; i--)
    cout << "From t1: " << i << endl;
  
}


int main(){

  // Race condition solved with a mutex.  Particularly data races.	

  // Race of t1 thread and main thread for 'cout' resource.
  //

  // Race condition is when the output is dependent on the execution
  // order of one or more threads.
  //

  // Best to try to avoid race conditions.

  
  
  std::thread t1(fn1); // t1 starts running

  for (int i=0; i<100; i++){
    cout << "From main:" << i << endl;
  }


  t1.join(); // wait for t1 to finish
  
  
  return 0;
}
