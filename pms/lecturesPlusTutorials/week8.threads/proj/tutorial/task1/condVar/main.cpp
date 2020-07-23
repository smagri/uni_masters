#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>
//#include <unistd.h>
#include <chrono>
#include <condition_variable>


using namespace std;

std::condition_variable cv;


void printVar(mutex &utex, int &var){
  // consumer thread

  while (true){
    // loop forever here.
    
    // We can only obtain a lock in this thread if the mutex is not
    // locked anywhere else.
    //utex.lock();
    std::unique_lock<std::mutex> lck(utex);

    // Mutex is now locked, we only access var while mutex is locked.
    cout << "variable value is " << var << endl;
    //utex.unlock();
    cv.notify_one();

    // This delay is included to improve the readability of the
    // program output, and avoid hard-looping and consuming too much
    // cpu.
    // == to c fn: sleep(1);
    //std::this_thread::sleep_for(std::chrono::seconds(1));
    //
    // 200ms works as well, 1s is easier on the eye
    //
    //std::this_thread::sleep_for(std::chrono::milliseconds(200));
  }

  
  return;
}


void incrementVar(mutex &utex, int &var){
  // producer thread

  while (true){
    // loop forever here.

    // We can only obtain a lock in this thread if the mutex is not
    // locked anywhere else.
    //utex.lock();
    std::unique_lock<std::mutex> lck(utex);

    // Mutually exclusive critical sections, that is, one or the other
    // but not both at the same time.

    // We only access var while te mutex is locked.
    var++;
    cout << "increment variable" << endl;

    cv.wait(lck);
    //utex.unlock();
    
    //cout << "increment variable: " << var << endl;
    //std::this_thread::sleep_for(std::chrono::milliseconds(200));
    //std::this_thread::sleep_for(std::chrono::seconds(1));
  
  }
  
  
  return;
}



int main(){

  // mutex to syncronise access to num
  mutex utex; 
  //std::atomic<int> var = 0;
  int var = 0;
  
  // create the threads
  thread incrementVarThread(incrementVar, ref(utex), ref(var));
  thread printVarThread(printVar, ref(utex), ref(var));

  
  // Syncronise threads, that is, wait for printVarThread() and then
  // incrementVarThread() to finish executing.  They won't due to
  // infinate loop in each thread.
  incrementVarThread.join();
  printVarThread.join();

  return 0;
}