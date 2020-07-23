#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

#include "RangerFusionInterface.h"
#include "rangerFusion.h"
#include "ranger.h"


RangerFusion::RangerFusion(){

  // Default contructor,  expected to be called  after constructors of
  // classes that derive from the RangerFusion class are executed.
  
}

RangerFusion::RangerFusion(string fusionMethod){

  // Initialises fusion  method/processing method of raw  ranger data.
  // It  is initialised  on  creaton of  a  RangerFusion object.   The
  // fusion method min/max/average is specified by the user.
  
  fusionMethod_ = fusionMethod;
  
}

void RangerFusion::setRangers(vector<Ranger *> rangers){

  // Accepts a vector of rangers,  or pointers to objects derived from
  // class  Ranger,  indicating   a  particular  sensor(laser,  radar,
  // sonar...).
  //

  rangers_ = rangers;
  
  cout << "rangers_ :" << endl << endl;
  //
  cout << "&l1=" << rangers_.at(0) << endl;
  cout << "&r1=" << rangers_.at(1) << endl;
  cout << "&s1=" << rangers_.at(2) << endl;

  cout << "rangers :" << endl << endl;
  //
  cout << "&l1=" << rangers.at(0) << endl;
  cout << "&r1=" << rangers.at(1) << endl;
  cout << "&s1=" << rangers.at(2) << endl;

  cout << "dbg: rangers_.size()=" << rangers_.size() << endl;

}


vector<double> RangerFusion::getFusedRangeData(){

  // This function uses the  Ranger Class readRanger() member function
  // to read data from the sensor,  this is the 'raw' sensor data.  It
  // then performs an algorithm on this  data to produce fused data as
  // detailed within this function.

  cout << "dbg: RangerFusion::getFusedRangeData()" << endl;
  
  vector<double> fusedRangeData; // fused sensor data

  double minFOV, maxFOV; // minimum and maximum of the sensor FOVs
  double overlapMinFOV; // lower limit of overlapping FOVs, degrees
  double overlapMaxFOV; // upper limit of overlapping FOVs, degrees
  
  double minRANGE, maxRANGE; // minimum and maximum of the sensor Range
  //int numRangerSamples; // number of samples for a particular ranger
  

  // This function uses the  Ranger Class readRanger() member function
  // to generate  the 'raw' sampled  data of the  sensors/rangers.  It
  // then   places   this   data    into   the   class   member   data
  // readRawRangeDataVV_.  This is the raw  data that this method will
  // use for fusion processing.
  //
  readRangeData();


  // Fusion algorithim:
  //
  //
  // Work out the FOV overlap and the Range overlap of sensors.
  //
  // All sensors have the same rangeMin_ value so only rangeMax_
  // will be considered.
  //
  // At this stage only the fusionMethod=average is implemented.
  //
  
  // Overlapping FOV range/region should be between minFOV and maxFOV.
  //
  // determine minimum of the FOV range
  double previousFOVmin = rangers_.at(0)->getHdwFixedFOV();
  int minFOVindex = 0;
  //
  for (int i=1; i<rangers_.size(); i++){
    
    minFOV = min(previousFOVmin, rangers_.at(i)->getHdwFixedFOV());
    
    if (minFOV < previousFOVmin){
      previousFOVmin = minFOV;
      minFOVindex = i;
    }	
  }

  // determine maximum of the FOV range
  double previousFOVmax = rangers_.at(0)->getHdwFixedFOV();
  int maxFOVindex = 0;
  //
  for (int i=1; i<rangers_.size(); i++){
    
    maxFOV = max(previousFOVmax, rangers_.at(i)->getHdwFixedFOV());
    
    if (maxFOV > previousFOVmax){
      previousFOVmax = maxFOV;
      maxFOVindex = i;
    }	
  }
  
  overlapMinFOV = 90 - minFOV/2;
  overlapMaxFOV = 90 + minFOV/2;

  fprintf(stderr, "dbg: getFusedRangeData: minFOV=%f\n", minFOV);
  fprintf(stderr, "dbg: getFusedRangeData: maxFOV=%f\n", maxFOV);
  fprintf(stderr, "dbg: getFusedRangeData: overlapMinFOV=%f\n", overlapMinFOV);
  fprintf(stderr, "dbg: getFusedRangeData: overlapMaxFOV=%f\n", overlapMaxFOV);
  

  // Overlapping Range should be between minRange and maxRange.
  //
  // determine minimum of the sensor ranges.
  double previousRANGEmin = rangers_.at(0)->getHdwFixedRangeMin();
  int minRANGEindex = 0;
  //
  for (int i=1; i<rangers_.size(); i++){
    
    minRANGE = min(previousRANGEmin, rangers_.at(i)->getHdwFixedRangeMin());
    
    if (minRANGE < previousRANGEmin){
      previousRANGEmin = minRANGE;
      minRANGEindex = i;
    }	
  }
    // determine the maximum of the sensor ranges.
  double previousRANGEmax = rangers_.at(0)->getHdwFixedRangeMax();
  int maxRANGEindex = 0;
  //
  for (int i=1; i<rangers_.size(); i++){
    
    maxRANGE = max(previousRANGEmax, rangers_.at(i)->getHdwFixedRangeMax());
    
    if (maxRANGE > previousRANGEmax){
      previousRANGEmax = maxRANGE;
      maxRANGEindex = i;
    }	
  }
  
  fprintf(stderr, "dbg: getFusedRangeData: minRANGE=%f\n", minRANGE);
  fprintf(stderr, "dbg: getFusedRangeData: maxRANGE=%f\n", maxRANGE);

  
  // LATER: write introduction to this secton.
  //
  // The sampled  data from each  Ranger/Sensor is  put into a  row of
  // curFusionVec, the current ranger fusion vector, or the samples of
  // the current ranger/sensor being processed.
  //
  // That is, each row of the rawRangeDataVV_ is extracted into a
  // curFusionVec row..

  // Each ranger's sampled data is a row of curFusionVec.
  vector<vector<double> > curFusionVec;

  // Number of samples for a particular ranger/sensor.
  int numRangerSamples[rangers_.size()];

  for (int i=0; i<rangers_.size(); i++){
    // Foreach Ranger/Sensor.

    // Add an empty row to curFusionVec.
    curFusionVec.push_back( vector<double>() );

    numRangerSamples[i] = rangers_.at(i)->getHdwFixedNumSamples();
    fprintf(stderr, "dbg: getFusedRangeData: numRangerSamples=%d\n",
	    numRangerSamples[i]);

    // Fill this empty row with rawRangeDataVV_ values.
    for (int j=0; j<numRangerSamples[i]; j++){
      curFusionVec[i].push_back(rawRangeDataVV_[i][j]);
    }
    
  }
  // Output contents of curFusionVec to see if it filled properly.
  for (int i=0; i<rangers_.size(); i++){
    for (int j=0; j<numRangerSamples[i]; j++){
      cout << "dbg: getFusedRangeData: curFusionVec[" << i << "]"
	   << "[" << j << "]="
	   << curFusionVec[i][j] <<endl;
    }
  }


  // Test if our current three points are in the overlapping FOV range
  // and overlapping  distance Range.  This  must occur to be  able to
  // fuse the current three points.
  //
  //

  // First implementing fusionMethod = average.

  // The maximum  number of fused  values to be determined  depends on
  // the  angular  resolution of  the  densest  ranger/sensor.  So  we
  // determine  the largest  sensor sample  vector out  of all  of our
  // rangers/sensors.
  //
  int preNumValues2fuse = numRangerSamples[0];
  int numValues2fuse;
  //
  for (int i=1; i<rangers_.size(); i++){
    
    numValues2fuse = max(preNumValues2fuse, numRangerSamples[i]);
    
    if (numValues2fuse > preNumValues2fuse){
       preNumValues2fuse = numValues2fuse;
    }	
  }
  fprintf(stderr, "dbg: getFusedRangeData: numValues2fuse=%d\n",
	  numValues2fuse);
  
  //
  //
  // Foreach vector in curFusionVec:
  //
  // for(int i=0; i<rangers_.size(); i++){
  //   curFusionVec[i][j] = 
  // }

  //fprintf(stderr, "dbg: getFusedRangeData: size of curFusionVec[0]=%ld\n",
  //	  curFusionVec[0].size());

  

 




  
  
    
  return fusedRangeData;
}


vector<vector<double> > RangerFusion::getRawRangeData(){

  // This function returns a _set_  of vectors, each vector containing
  // a set  of double  values, the sensor  sampled values.   Again the
  // 'raw' sampled  sensor values  are derived from  a call  to Ranger
  // Class  readRanger()   from  within  the   readRangeData()  member
  // function.  The  number of  returned vectors  is derived  from the
  // number  of pointers  in rangers_  vector, that  is the  number of
  // sensors we are dealing with.
  
  return rawRangeDataVV_;
}


int RangerFusion::readRangeData(){
  
  // This function generates class  member data rawRangeDataVV_ within
  // to provide the data for fusion in getFusedRangeData().

  // rawRangeDataVV_  contains   a  _set_  of  vectors,   each  vector
  // containing a  set of  double values,  the sensor  sampled values.
  // Again the 'raw' sampled sensor values  are derived from a call to
  // Ranger  Class  readRanger()  member   function.   The  number  of
  // returned  vectors  is derived  from  the  number of  pointers  in
  // rangers_ vector,  that is  the number of  sensors we  are dealing
  // with.

  
  // Note: standard says you must have a space between the last two
  // angle brackets in vector<vector<double> >.
  
  vector<double> rawRangeData;
  int rawRangeDataVecSize;
  int numRangerSamples; // number of samples for each sensor
    
  //vector<vector<double> > rawRangeDataVV_; // raw range data Vector of Vectors

  
  
  for (int i=0; i<rangers_.size(); i++){
    
    numRangerSamples = rangers_.at(i)->getHdwFixedNumSamples();

    rangers_.at(i)->readRanger(rawRangeData, 60, numRangerSamples);
    
    // Add an empty row.
    rawRangeDataVV_.push_back( vector<double>() );
    
    // File this row with the raw range data.
    for (int j=0; j<rawRangeData.size(); j++){
      rawRangeDataVV_[i].push_back(rawRangeData[j]);
    }
    rawRangeDataVecSize = rawRangeData.size(); // need to save for later
    
    // Need to clear rawRangeData vector, ready for next readRanger()
    // invocation.  Otherwise this vector grows infinatly with each
    // invocation.
    //
    // itterate the raw data vector backwards.
    //
    // However, could use rbegin() and rend() vector methods, it works
    // accross all containers.
    //
    // Containers and itterators, it acts like a pointer.
    //
    // NOTE: maybe use vector::clear() here instead, found it too late???
    //
    vector<double>::iterator it;
    vector<double>::iterator itbegin = rawRangeData.begin();
    vector<double>::iterator itend = rawRangeData.end()-1;
    
    for(vector<double>::iterator it=itend; it>=itbegin; --it){
      // pops last element in vector off the list
      cout<<"dbg: readRangeData: rawRangeData("
	  <<  (it-itbegin) << ")=" << *it << endl;
      rawRangeData.pop_back();
    }

    
    
  } // for (int i=0; i<rangers_.size(); i++){
  

  // Check output.
  for (int m=0; m<rangers_.size(); m++){
    for (int n=0; n<rawRangeDataVecSize; n++){
      cout << "dbg: readRangeData: rawRangeDataVV_["
	   << m << "]" << "[" << n << "]="
	   << rawRangeDataVV_[m][n] <<endl;
    }
  }

  cout << "dbg: pre return getRawRangeData()" << endl;
  

  //return rawRangeDataVV_;
  return 0;
}

