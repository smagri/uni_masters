#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <mutex>
#include <thread>
#include <chrono>

#include "dataFusion.h"
#include "ranger.h"


 
DataFusion::DataFusion(){

  // Default contructor,  expected to be called  after constructors of
  // classes that derive from the DataFusion class are executed.

  
}


void DataFusion::setFusionMethod(string fusionMethod){
  
  /// Fusion method min/max/average is specified by the user.

  if( (fusionMethod != "min") && (fusionMethod != "max")
      && (fusionMethod != "avg") ){
    
    fprintf(stderr, " Error: invalid fusionMethod name entered,");
    fprintf(stderr, " defaulting to, min.\n");
    
    fusionMethod_ = "min"; // set default fusionMethod_ value
    
  }
  else{
    fusionMethod_ = fusionMethod;
  }
  
  fprintf(stderr, "\ndbg: fusionMethod_=%s\n", fusionMethod_.c_str());
  
  return;
  
}

string DataFusion::getFusionMethod(void){

  return fusionMethod_;

}

void DataFusion::setRangers(vector<Ranger *> rangers){
  
  /// Accepts a vector of rangers,  or pointers to objects derived from
  /// class  Ranger,  indicating   a  particular  sensor(laser,  radar,
  /// sonar...).
  //

  rangers_ = rangers;
  
  cout << "dbg: setRangers: rangers_ :" << endl << endl;
  //
  //cout << "&l1=" << rangers_.at(0) << endl;
  cout << "dbg: setRangers: &r1=" << rangers_.at(0) << endl;
  cout << "dbg: setRangers: &s1=" << rangers_.at(1) << endl;

  cout << "rangers :" << endl << endl;
  //
  //cout << "&l1=" << rangers.at(0) << endl;
  cout << "dbg: setRangers: &r1=" << rangers.at(0) << endl;
  cout << "dbg: setRangers: &s1=" << rangers.at(1) << endl;

  cout << "dbg: setRangers: rangers_.size()=" << rangers_.size() << endl;

}



// vector<vector<double> > DataFusion::getRawRangeData(){

//   /// This function returns a _set_  of vectors, each vector containing
//   /// a set  of double  values, the sensor  sampled values.   Again the
//   /// 'raw' sampled  sensor values  are derived from  a call  to Ranger
//   /// Class  readRanger()   from  within  the   readRangeData()  member
//   /// function.  The  number of  returned vectors  is derived  from the
//   /// number  of pointers  in rangers_  vector, that  is the  number of
//   /// sensors we are dealing with.
  
//   return rawRangeDataVV_;
// }


int DataFusion::readRangeData(){
  
  /// This function generates class  member data rawRangeDataVV_ within
  /// to provide the data for fusion in getFusedRangeData().

  // rawRangeDataVV_  contains   a  _set_  of  vectors,   each  vector
  // containing a  set of  double values,  the sensor  sampled values.
  // Again the 'raw' sampled sensor values  are derived from a call to
  // Ranger  Class  readRanger()  member   function.   The  number  of
  // returned  vectors  is derived  from  the  number of  pointers  in
  // rangers_ vector,  that is  the number of  sensors we  are dealing
  // with.
}


//
// Threaded processing of sensor/ranger data.
//


void DataFusion::fillBuffer(int rangerNum){
  
   /// Fill FIFO buffer of a given sensor using a mutex lock for
   /// syncronisation.

  int numSamples;
  int samplingRate;
  int sleepTime;
  
  vector<double> rawRangeData;// Raw sampled data read from the Sensor/Ranger.
  vector<double> rawRangeDataTimestamp;// Raw sampled data timestamp,
				       // for the Sensor/Ranger.
  

  while(true){
    // Aquire the mutex lock of access to this buffer.
    //
    // mutex: dataBuff[rangerNum].buffMutex_.lock();
    //
    // producer/consumer condition variable: aquire mutex lock.
    std::unique_lock<std::mutex> lck(dataBuff[rangerNum].buffMutex_);

    fprintf(stderr, "dbg: fillBuffer: fillBuffer(%d) called, in Lock%d.\n",
            rangerNum, rangerNum);
    
    numSamples = rangers_.at(rangerNum)->getHdwFixedNumSamples();
    samplingRate = rangers_.at(rangerNum)->getHdwFixedSamplingRate();


    // Read the  ranger's/senor's data.
    //
    // It's  important not  to sleep  here as  this thread  will block
    // while holding a lock, thus  starving other threads that require
    // the lock.
    //
    rangers_.at(rangerNum)->readRanger(rawRangeData, rawRangeDataTimestamp,
				       samplingRate, numSamples);

    // Put raw sensor/ranger data into our queue.
    for (int j=0; j<rawRangeData.size(); j++){
      dataBuff[rangerNum].buffQue_.push(rawRangeData[j]);
      dataBuff[rangerNum].buffQueTimestamp_.push(rawRangeDataTimestamp[j]);

      fprintf(stderr, "dbg: fillBuffer: dataBuff[%d].buffQue_.push(=%f)\n",
	      rangerNum, rawRangeData[j]);
    }

    // Clear the raw sensor/ranger vector of sampled data, ready for
    // next sample set.
    rawRangeData.clear();
    rawRangeDataTimestamp.clear();
    
    
    fprintf(stderr, "dbg: fillBuffer: Before unLock of Lock%d.\n", rangerNum);
    
    // mutex: dataBuff[rangerNum].buffMutex_.unlock();
    //
    // producer/consumer condition variable:
    dataBuff[rangerNum].consumer_.notify_one();//wake consumer/processBuffers()
    dataBuff[rangerNum].producer_.wait(lck);//block/sleep producer/fillBuffer()
    
    
    // Does this have to be condition_variable instead of sleep.
    //
    fprintf(stderr, "dbg: fillBuffer: Out of Lock%d.\n", rangerNum);
    //
    // This delay slows the loop down for the sake of readability,
    // notice it's not within the mutex lock.
    //

    // Sampling is simulated here with  a delay/blocking of the thread
    // for 1.0/samplingRate seconds.  So this  buffer is filled at the
    // correct rate for a particular sensor.  Notice this delay is not
    // within the mutex lock, hence other processes are not starved of
    // the mutex lock by it.
    sleepTime = (1.0 / samplingRate) * 1000; //in ms
    std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));
    fprintf(stderr, "dbg: fillBuffer: sampleRate=%dHz => sleepTime=%dms\n",
	      samplingRate, sleepTime);
    

    
  } // while (true)
  
}


void DataFusion::processBuffers(){

  /// Process  data in  FIFOs(buffers/ques) using  condition variables
  /// for syncronisation.

  
  int rangerNum; // current sensor being processed
  int i;
  int samplingRate; // should this be a double

  // Linear extrapolation variables:
  //
  double x, y; // Point (x, y) extrapolated from the, previous and
               // nearest, two points (x1, y1) & (x2, y2).
  double x1, y1; // Point from previous extrapolation.
  double x2, y2; // Current sample point to use for current extrapolation.

  double sensorRangeMin;
  double sensorRangeMax;
 
  
  
  while(true){
    // Aquire the mutex locks and process the buffers/FIFO's/Que's of
    // all the sensor.


    for (i=0; i<rangers_.size(); i++){
      rangerNum = i;
      
      // Process data for each sensor that we have.
      //
      // mutex: dataBuff[rangerNum].buffMutex_.lock();
      //
      // producer/consumer condition variable:
      std::unique_lock<std::mutex> lck(dataBuff[rangerNum].buffMutex_);
 
      fprintf(stderr,
	      "dbg: processBuffers: processBuffer(%d) called, in Lock%d.\n",
	      rangerNum, rangerNum);
      
      fprintf(stderr, "dbg: processBuffers: fifo(%d) size is %ld\n",
	      rangerNum, dataBuff[rangerNum].buffQue_.size());
      
      
      // Pop data off the fifo, if the fifo isn't empty, to preform
      // processing/fusion.
      if ( (!dataBuff[rangerNum].buffQue_.empty()) &&
	   (!dataBuff[rangerNum].buffQueTimestamp_.empty()) ){
	
	fprintf(stderr,
		"dbg: processBuffers: before pop, front of fifo is %f\n",
		dataBuff[rangerNum].buffQue_.front());
	
	
	if (!dataBuff[rangerNum].prevDatasetPointExists){
	  // No previous sample in the que yet.
	  
	  fprintf(stderr,
		  "dbg: processBuffers: No previous point in dataset.\n");
		  
	  dataBuff[rangerNum].xPrev
	    = dataBuff[rangerNum].buffQueTimestamp_.front();
	  dataBuff[rangerNum].buffQueTimestamp_.pop();

	  dataBuff[rangerNum].yPrev =
	    dataBuff[rangerNum].buffQue_.front();
	  dataBuff[rangerNum].buffQue_.pop();

	  fprintf(stderr, "dbg: processBuffers: (dataBuff[%d].xPrev, "
		  "dataBuff[%d].yPrev)=(%f,%f)\n",
		  rangerNum, rangerNum,
		  dataBuff[rangerNum].xPrev, dataBuff[rangerNum].yPrev);

	  dataBuff[rangerNum].prevDatasetPointExists = 1;
	}
	else{
	  //
	  // Extrapolate  for   each  new  sample,  with   the  previous
	  // extraploated value (x,y) -> (x1,  y1) to determine the next
	  // extrapolated value.
	  //
	  x1 = dataBuff[rangerNum].xPrev;
	  x2 = dataBuff[rangerNum].buffQueTimestamp_.front();
	  dataBuff[rangerNum].buffQueTimestamp_.pop();

	  y1 = dataBuff[rangerNum].yPrev;
	  y2 = dataBuff[rangerNum].buffQue_.front();
	  dataBuff[rangerNum].buffQue_.pop();
	  
	  fprintf(stderr,
		  "dbg: processBuffers: after pop, front of fifo is %f\n",
		  dataBuff[rangerNum].buffQue_.front());

	  // Extrapolate next sample.
	  samplingRate = rangers_.at(rangerNum)->getHdwFixedSamplingRate();
	  x = x2 + (1.0 / samplingRate);
	  
	  linearExtrapolation(x1, y1, x2, y2, x, y, rangerNum);

	  // If necessory,  set linearly  extrapolated value  (x,y) to
	  // within the sensors range.
	  sensorRangeMin  = rangers_.at(rangerNum)->getHdwFixedRangeMin();
	  sensorRangeMax  = rangers_.at(rangerNum)->getHdwFixedRangeMax();
	  if (y <= sensorRangeMin){
	    y = sensorRangeMin;
	  }
	  if (y >= sensorRangeMax){
	    y = sensorRangeMax;
	  }
	  fprintf(stderr, "dbg: processBuffers: "
		  "linearExtrapolation(%d): (x, y) = (%f, %f))\n",
		  rangerNum, x, y);

	  /// Perhaps linear extrapolation of polynominal range values
	  /// of sensor 1, the Sonar, doesn't fit the data well.  With
	  /// range values  deviating further  and further from  the x
	  /// axis as time goes  on.  Perhaps, the Lagrange Polynomial
	  /// extrapolation is more appropriate here.
	  ///
	  /// Linear   extraploation  of   a  polynomial   functon  is
	  /// appropriate if the samples are not far appart.  Thus the
	  /// conclusion drawn from our datasets is samples at 10Hz is
	  /// fast enough to represent  a polynomial function and that
	  /// a 3Hz sampling rate is too slow.
	  

	  dataBuff[rangerNum].xPrev = x;
	  dataBuff[rangerNum].yPrev = y;
	
	  fprintf(stderr,
	  	  "dbg: processBuffers: (x1, y1) = (%f, %f);\n"
	   	  "dbg: processBuffers: (x2, y2) = (%f, %f);\n"
	  	  "dbg: processBuffers: (dataBuff[%d].xPrev, "
	  	  "dataBuff[%d].yPrev) = \n"
	  	  "dbg: processBuffers: (%f, %f);\n"
	  	  "dbg: processBuffers: (x, y) = (%f, %f)\n",
	  	  x1, y1, x2, y2, rangerNum, rangerNum,
	  	  dataBuff[rangerNum].xPrev, dataBuff[rangerNum].yPrev, x, y);
	  
	  
	} //end: if (!dataBuff[rangerNum].prevDatasetPointExists){

	
	fprintf(stderr,
		"dbg: processBuffers: Before unLock of Lock%d.\n", rangerNum);
	
	// mutex: dataBuff[rangerNum].buffMutex_.unlock();
	// condition variable: 
	dataBuff[rangerNum].producer_.notify_one();//wake producer/fillBuffer()
	dataBuff[rangerNum].consumer_.wait(lck);//block consumer/processBuffers
	
	fprintf(stderr, "dbg: processBuffers: Out of Lock%d.\n", rangerNum);

      }	//end: if ( (!dataBuff[rangerNum].buffQue_.empty())...
      
    } // end: for (i=0; i< rangers_.size(); i++){

    
  } // end: while(true)
  
}


void DataFusion::startThreads(){

  /// Starts seperate threads  for the reading of  each sensor's data,
  /// and a thread which processes all the data appropriately.
  
  fprintf(stderr, "dbg: startThreads():\n");

  std::thread fillBuffer0Thread(&DataFusion::fillBuffer, this, 0);
  std::thread fillBuffer1Thread(&DataFusion::fillBuffer, this, 1);
  std::thread processBuffersThread(&DataFusion::processBuffers, this);

  
  fillBuffer0Thread.join();
  fillBuffer1Thread.join();
  processBuffersThread.join();

}


void DataFusion::linearExtrapolation(double x1, double y1,
				     double x2, double y2,
				     double &x, double &y,
				     int rangerNum){

  /// By the  method of  linear extrapolation the  next data  point is
  /// extrapolated from the previous two data points.

  /// Given the  previous points (x1,  y1) and the next  nearest point
  /// (x2, y2), the linear extrapolation formula is:
  ///
  /// y(x) = y1 + ((x - x1) / (x2 - x1)) * (y2 - y1);
  ///
  /// Where (x, y) is the extrapolated point.
  ///
  /// Linear extrapolation is generally suited  to data that is linear
  /// in nature.   However, it can  sometimes produce a  better result
  /// than polynominal extrapolation for  datasets that are polynomial
  /// in nature, as long as the time between samples is small enough.

  /// Returns the extrapolated point (x, y) from the two previous
  /// points given, (x1, y1) and (x2, y2).

  y = y1 + ((x - x1) / (x2 - x1)) * (y2 - y1);


  fprintf(stderr, "dbg: linearExtrapolation(%d): (x1, y1)= (%f, %f);\n"
	  "dbg: linearExtrapolation(%d): (x2, y2) = (%f, %f);\n"
	  "dbg: linearExtrapolation(%d): (x, y) = (%f, %f))\n",
	  rangerNum, x1, y1, rangerNum, x2, y2, rangerNum, x, y);
  
  return;
  
}



void DataFusion::getFusedRangeData(void){

}
