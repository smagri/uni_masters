#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <mutex>
#include <thread>

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


// Threaded processing of sensor/ranger data.
//


void DataFusion::fillBuffer(int rangerNum){
  
   /// Fill FIFO buffer of a given sensor using a mutex lock for
   /// syncronisation.

  int numSamples;
  int samplingRate;
  vector<double> rawRangeData;///< Raw sampled data read from the Sensor/Ranger.
  

  while(true){
    // Aquire the mutex lock of access to this buffer.
    dataBuff[rangerNum].buffMutex_.lock();

    fprintf(stderr, "dbg: fillBuffer: fillBuffer(%d) called, in Lock%d.\n",
            rangerNum, rangerNum);
    
    numSamples = rangers_.at(rangerNum)->getHdwFixedNumSamples();
    samplingRate = rangers_.at(rangerNum)->getHdwFixedSamplingRate();

    //fprintf(stderr, "dbg: fillBuffer: numSamples=%d, samplingRate=%d\n",
    //numSamples, samplingRate);
    
    //Read the ranger's/senor's data.
    rangers_.at(rangerNum)->readRanger(rawRangeData,
				       samplingRate, numSamples);

    // Put raw sensor/ranger data into our queue.
    for (int j=0; j<rawRangeData.size(); j++){
      dataBuff[rangerNum].buffQue_.push(rawRangeData[j]);

      fprintf(stderr, "dbg: fillBuffer: dataBuff[%d].buffQue_.push(=%f)\n",
	      rangerNum, rawRangeData[j]);
    }

    // Clear the raw sensor/ranger vector of sampled data, ready for
    // next sample set.
    rawRangeData.clear();
    
    fprintf(stderr, "dbg: fillBuffer: Before unLock of Lock%d.\n", rangerNum);
    
    dataBuff[rangerNum].buffMutex_.unlock();
    
    
    // Does this have to be condition_variable instead of sleep.
    //
    fprintf(stderr, "dbg: fillBuffer: Out of Lock%d.\n", rangerNum);
    //
    // This delay slows the loop down for the sake of readability,
    // notice it's not within the mutex lock.
    //
    //std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::this_thread::sleep_for(std::chrono::seconds(2));

  } // while (true)
  
}


void DataFusion::startThreads(){

  fprintf(stderr, "dbg: startThreads():\n");

  std::thread fillBuffer0Thread(&DataFusion::fillBuffer, this, 0);
  std::thread fillBuffer1Thread(&DataFusion::fillBuffer, this, 1);
  
  fillBuffer0Thread.join();
  fillBuffer1Thread.join();

}


void DataFusion::processBuffer(){

  
}
