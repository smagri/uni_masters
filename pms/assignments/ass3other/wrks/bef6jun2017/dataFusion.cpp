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

// !wrks: void DataFusion::fillBuffer(DataBuffer &dataBuff, int rangerNum){
// wrks: void DataFusion::fillBuffer(int rangerNum){
void DataFusion::fillBuffer(int rangerNum){
// wrks: void DataFusion::fillBuffer(){

   /// Fill FIFO buffer of a given sensor using a mutex lock for
   /// syncronisation.

  int numSamples;
  int samplingRate;
  vector<double> rawRangeData;

  
  while(true){

    //fprintf(stderr, "%p\n", &dataBuff0);
    dataBuff[rangerNum].buffMutex_.lock();

    fprintf(stderr, "dbg: fillBuffer: fillBuffer(%d) called, in lock%d.\n",
            rangerNum, rangerNum);
    
    // fprintf(stderr, "dbg: fillBuffer: rangerNum=%d\n", rangerNum);

    //fprintf(stderr, "dbg: fillBuffer: readRangeData() called:\n");
    // df1.readRangeData();
    
    //fprintf(stderr, "dbg: fillBuffer: getRawRangeData() called:\n");
    //  dataVec = df1.getRawRangeData();

    numSamples = rangers_.at(rangerNum)->getHdwFixedNumSamples();
    samplingRate = rangers_.at(rangerNum)->getHdwFixedSamplingRate();
  
    //Read the ranger's/senor's data.
    //
    //rangers_.at(rangerNum)->readRanger(rawRangeData,
    //samplingRate, numRangerSamples);

    // dataBuff.buffQue_.push();

    // Put ranger raw data into our queue.
    // for (int j=0; j<rawRangeData.size(); j++){
    //   dataBuff.at(rangerNum).buffQue_.push(rawRangeData[j]);
    // }
        
    // for (int j=0; j<rawRangeData.size(); j++){
    //   fprintf(stderr, "dbg: fillBuffer: "
    // 	      dataBuff.at(%d).buffQue_[j]=%f\n", rangerNum
    //           dataBuff.at(rangerNum).buffQue_[i]);
    // }

    // // Need to remove last elements of rawRangeDataVV_[m][n]  
    // rangers_.at(rangerNum).setClearRawDataVector();
    
    // fprintf(stderr, "dbg: fillBuffer: before unlock of lock%d.\n", rangerNum);
        
    //dataBuff0.buffMutex_.unlock();
    dataBuff[rangerNum].buffMutex_.unlock();
    
    
    // Does this have to be condition_variable instead of sleep.
    //
    fprintf(stderr, "dbg: fillBuffer: out of lock%d.\n", rangerNum);
    //
    // This delay slows the loop down for the sake of readability,
    // notice it's not within the mutex lock.
    //
    //std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::this_thread::sleep_for(std::chrono::seconds(2));

  } // while (true)
  
}


void DataFusion::startThreads(){

  fprintf(stderr, "dbg: startThreads()\n");

  //fillBuffer(1);


  // wrks: std::thread fillBuffer0Thread(&DataFusion::fillBuffer, this, 0);
  // !wrks: std::thread fillBuffer0Thread(&DataFusion::fillBuffer, this,
  //				ref(&dataBuff0), 0);
  //std::thread fillBuffer0Thread(&DataFusion::fillBuffer, this, 0);
  std::thread fillBuffer0Thread(&DataFusion::fillBuffer, this, 0);
  
  fillBuffer0Thread.join();
  
  
}


void DataFusion::processBuffer(){

  
}
