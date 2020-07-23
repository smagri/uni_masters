#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>
//#include <unistd.h>
#include <chrono>
#include <random>


#include "databuffer.h"


using namespace std;


void addNumber(DataBuffer &dataBuff){

  // Continuously adds numbers to the values vector contained in
  // structure dataBuff.
  
  // Initialise random number generation.
  std::default_random_engine generator;
  // produces random numbers between 0 and 100
  std::uniform_real_distribution<double> distributionUniform(0, 100);
  
  while(true){
    dataBuff.buffer_mutex_.lock();
    // Grab the mutex lock to access the buffer's critical data, so
    // access stays atomic.
    
    // Fill vector values with a random number.
    dataBuff.values.push_back(distributionUniform(generator));
    
    // Returns a reference to the last element in the vector and
    // prints it.  The last element is the last, or most recent,
    // element added to the values vector.
    cout << "Added value: " << dataBuff.values.back() << endl;

    dataBuff.buffer_mutex_.unlock();
    
    // This delay slows the loop down for the sake of readability,
    // notice it's not within the mutex lock.
    //noSleeps: std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  }
 
}


void removeNumbers(DataBuffer &dataBuff, double lowerBound, double upperBound){
  
  // Continuously removes numbers from the values vector contained in
  // structure dataBuff.  It removes numbers greater than upperBound
  // and lower than lowerBound.

  while(true){
    //
    // Need to syncornise access to dataBuff, for all three thread/fns.
    dataBuff.buffer_mutex_.lock();
    
    // Itterate  through the  whole  values vector  to  find and  remove
    // numbers less than 20(lowerBound) and greater than 80(upperBound).
    auto it = dataBuff.values.begin(); // what does auto do???
    
    while (it !=dataBuff.values.end()){
      // As values.end() is a reference to just past the last element of
      // the vector.
      if ( (*it < lowerBound) || (*it > upperBound) ){
	// Remove elements from the values vector.
	dataBuff.values.erase(it);
	cout << "Erased value: " << *it << endl;
      }
      else{
	it++;
      }
    }
    dataBuff.buffer_mutex_.unlock();

    // This short delay prevents this thread from hard-looping and
    // consuming too much cpu time.
    //noSleeps: std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  } // end: while(true)
  
}


void trimLength(DataBuffer &dataBuff){

  // Trims the values vector to a size of 20 elements, removes the
  // oldest elements first.

  while(true){
    dataBuff.buffer_mutex_.lock();

    while(dataBuff.values.size() > 20){
      // Removes the first and oldest element in the values vector.
      cout<<"Size is "<<dataBuff.values.size()<<" removing first value."<<endl;
      dataBuff.values.erase(dataBuff.values.begin());
    }

    dataBuff.buffer_mutex_.unlock();

    // This short delay prevents this thread from hard-looping and
    // consuming too much cpu time.  Using a condition variable to
    // make the thread wait provides a better solution to this
    // problem.
    //noSleeps: std::this_thread::sleep_for(std::chrono::milliseconds(100));
  } // end: while(true){

  
}




int main(){

// mutex to syncronise access to num
  mutex utex; 
  int var = 0;
  
  // Create the shared buffer which contains its own mutex.
  DataBuffer dataBuff;

  
  // Start all the threads
  thread addNumberThread(addNumber, ref(dataBuff));
  thread removeNumbersThread(removeNumbers, ref(dataBuff), 20, 80);
  thread trimLengthThread(trimLength, ref(dataBuff));


  // Syncronise threads,  that is, wait  for _all_ threads  to finish,
  // they wont in this case though  as the threads have infinate loops
  // in them.
  addNumberThread.join();
  removeNumbersThread.join();
  trimLengthThread.join();
  
  return 0;
}
