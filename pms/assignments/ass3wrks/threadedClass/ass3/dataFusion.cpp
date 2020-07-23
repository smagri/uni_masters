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
// void DataFusion::fillBuffer(DataBuffer &dataBuff, int rangerNum){

//   /// Fill FIFO buffer of a given sensor.

//   int numSamples;
//   int samplingRate;

//   //dataBuff.buffMutex_.lock();

//   // vector<double> rawRangeData; ??? any of this stuff at all
  
//   numSamples = rangers_.at(rangerNum)->getHdwFixedNumSamples();
//   t samplingRate = rangers_.at(rangerNum)->getHdwFixedSamplingRate();
  
//   // Read the ranger's/senor's data.
//   //
//   // rangers_.at(i)->readRanger(rawRangeData, samplingRate, numRangerSamples);

//   // dataBuff.buffQue_.push();

//   // dataBuff.buffMutex_.unlock();

  
//   // This delay slows the loop down for the sake of readability,
//   // notice it's not within the mutex lock.
//   // std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  
// }



void DataFusion::fillBuffer(){
  
}


void DataFusion::processBuffer(){

  
}
