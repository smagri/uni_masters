#include <iostream>
#include <thread>

//
// This video doesn't seem that useful and is difficult to follow.
//
// Except for  passing string by  reference to the thread.   Where you
// must use  ref(stringName) to pass  string to thread.  Or  you could
// pass it  by good old  pointer to achieve  the same thing.   See ***
// bounded section below.
//
// Also, hardware_concurrency()  to determine  the number of  cores on
// your system.
//

using namespace std;

void fn1(){

  cout << "Beauty is only skin-deep" << endl;

}

int main(){

  thread t1(fn1); // t1 starts running

  // try catch block for parent can also be done with RAII:
  // Wrapper w(t1);
  //
  // and in destructor of the wrapper class call t1.join().

  // **********************************************************************
  // a perameter to a thread is _always_ passed by value!!!.
  // however, you can used std::ref(s) to force by reference.
  // pass by pointer wrks too.
  //
  // OR move string  from parent thread to  child thread std::move(s),
  // is both safe and efficent
  // **********************************************************************
  
  // in c++ there are many things that can be moved but not copied,
  // like a thread.
  //
  // ie this will not compile
  // std::thread t2 = t1;
  // std::thread t2 = move(t1); // moves ownership of t1 to t2
  // t2.join(); //as t1 is empty

  // each thread has a unique id set to it
  //
  cout << std::this_thread::get_id() << endl; // for parent thread
  cout << t1.get_id() << endl; // for child thread

  // how many threads, as many as the number of cpu cores!!! that you have.
  //
  // oversubscription:  making more  threads than  you have  resources
  // for,  or more  threads than  you have  cpu cores.   As this  will
  // create a lot of context switching, which degrades performance.
  //
  // Indication of how many threads can be truly run concurrently on
  // your system.
  //
  std::thread::hardware_concurrency(); // eg could return number of cpu
				       // cores on your system
  
  // try catch block for parent
  try{
    for (int=0; i<100; i++){
      cout << "from main:" << i << endl;
    } catch (...){  // stops parent/main termination when exception thrown
      t1.join(); // join with or without exception
      throw;
    }
    
  // once main detaches from your children you can't rejoin them so
  // this crashes
  t1.join(); // crash

  // so to avoid crash do:
  if (t1.joinable()){
    t1.join();
  }
  
  return 0;
}
