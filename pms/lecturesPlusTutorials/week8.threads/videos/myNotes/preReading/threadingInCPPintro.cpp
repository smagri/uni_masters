#include <iostream>
#include <thread>

using namespace std;

void fn1(){

  cout << "Beauty is only skin-deep" << endl;r

}

int main(){

  thread t1(fn1); // t1 starts running
  
  //t1.join(); // main thread waits for child thread t1 to finish

  t1.detach(); // t1 will run freely on its own, thus main thread
	       // !wait for it to finish; thus t1 becomes a daemon process

  // it is not deterministic when you have two threads running, you
  // don't know which will finish fists.  Some syncronisation methods
  // are required.

  // once main detaches from your children you can't rejoin them so
  // this crashes
  t1.join(); // crash

  // so to avoid crash do:
  if (t1.joinable()){
    t1.join();
  }
  
  return 0;
}
