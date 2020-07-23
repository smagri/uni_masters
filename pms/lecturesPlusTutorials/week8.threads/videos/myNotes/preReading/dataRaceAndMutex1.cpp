#include <iostream>
#include <thread>
#include <mutex>

//
// Uses mutexes to solve data race conditions.
//
// Can ignore rest of video from about 7min mark/half way.

using namespace std;

std::mutex mu;

// Races condition, data race condition: solutn:
// 1. use mutex to syncrohnise data acess;
// 2. never leak a handle of data to the outside world
// 3. design interface appropriately.

void shared_print(string msg, int id){

  // if an exeption is thown the process is forever in the
  // mutex.lock(), so use guard instead.
  //mu.lock();

  // RAII, when guard goes out of SCOPE to mutex is UNLOCKED, with or
  // without exception.
  std::lock_guard<std::mutex> guard(mu);
    cout << msg << id << endl;

    
  //mu.unlock();
}


void fn1(){
  
  cout << "Beauty is only skin-deep" << endl;
  for (int i=0; i>-100; i--)
    shared_print(string("From t1: "), i);
  
}


int main(){

  // Race condition solved with a mutex.  Particularly data races.	

  // That is access to the 'cout' resource is dictated by mutex called
  // mu.  No two threads can access cout now at the one time.  Acesss
  // is only one thread at a time.
  
  std::thread t1(fn1); // t1 starts running

  for (int i=0; i<100; i++){
    shared_print(string("From main: "), i);
  }


  t1.join(); // wait for t1 to finish
  
  
  return 0;
}
