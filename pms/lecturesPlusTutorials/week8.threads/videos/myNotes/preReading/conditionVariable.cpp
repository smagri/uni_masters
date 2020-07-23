
// start from 3min mark in the video
std::condition_variable cond; // take the guesswork out of the sleep time.


f1(){
std::unique_lock<mutex> locker(mu);
 ...
  locker.unlock();
  cond.notify_one();
  //cond.notify_all(); wake up all threads
 sleep_for(seconds(1))

   }


f2(){
std::unique_lock<mutex> locker(mu);

// will unlock the locker and then  go to sleep
 cond.wait(locker); // puts thread 2 to sleep untill notified by
		    // thread one that the resource is available.
// lock the locker again before q is used 
 locker.unlock();

 // deal with spurious wake, us conditional

 
 // to avoid busy wait
 // sleep_for(milliseconds(10))
 //   }
