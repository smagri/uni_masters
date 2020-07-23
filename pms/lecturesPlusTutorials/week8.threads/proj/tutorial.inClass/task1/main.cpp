#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>


using namespace std;

//std::mutex mu;
//int var;

void f1(mutex &mu, int &var){

  mu.lock();
  cout << var;
  mu.unlock();
  
  return;
}


void f2(mutex &mu, int &var){

  mu.lock();
  // mutually exclusive critical sections
  cout << var++;
  mu.unlock();
  
  return;
}



int main(){

  mutex mu;
  int var;
  

  thread t1(f1, ref(mu), ref(var));
  thread t2(f2, ref(mu), ref(var));
  
  t1.join();
  t2.join();

  return 0;
}

//output
// num++
// num is 14
// num is 14
// num is 14
