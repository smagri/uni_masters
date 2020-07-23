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

  // Initialises fusion method on object creatrion.
  
  // Or put this in RangerFusionInterface(); constructor.
  fusionMethod_ = fusionMethod;
  
}

void RangerFusion::setRangers(vector<Ranger *> rangers){

  // Accepts a vector of rangers,  or pointers to objects derived from
  // class  Ranger,  indicating   a  particular  sensor(laser,  radar,
  // sonar...).
  //

  // vector<Ranger *> rangersl;
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
  // detailed within the function.

  cout << "dbg: RangerFusion::getFusedRangeData()" << endl;
  
  //getRawRangeData();
  //vector<double> retVecd = {0.1, 2.2, 3.0};

  vector<double> fusedRangeData;

  vector<double> rawRangeData;
  vector<double>::iterator it;
  vector<double>::iterator itbegin = rawRangeData.begin();
  vector<double>::iterator itend = rawRangeData.end()-1;
    
  vector<double> laserRawRangeData;
  vector<double> radarRawRangeData;
  vector<double> sonarRawRangeData;

  // NOTE: needs to be made independent of ranger_ we are using.
  // NOTE: need to clear rawRangeData before next invocation.
  //
  // NOTE:
  // this is cluge as ran out of time to fix it, just needed three
  // vectors I could play with for displaying the rest of the algorithm.

  
  for (int k=0; k<3; k++){
    rangers_.at(k)->readRanger(rawRangeData, 60, 10);
    //laserRawRangeData = rawRangeData;
    for (int i=0; i<laserRawRangeData.size(); i++){
      cout<< "laserRawRangeData(" << i << ")" << laserRawRangeData.at(i) <<endl;
    }
  }

//   for (int j=0; j<laserRawRangeData.size(); j++){
//     cout<< "rawRangeData(" << j << ")" << rawRangeData.at(j) <<endl;
//     //rawRangeData.pop_back();
//   }
// //  }

  
//  for (int k=0; k<rangers_.size(); k++){
//   rangers_.at(0)->readRanger(rawRangeData, 60, 10);
//   laserRawRangeData = rawRangeData;
//   for (int i=0; i<laserRawRangeData.size(); i++){
//     cout<< "laserRawRangeData(" << i << ")" << laserRawRangeData.at(i) <<endl;
//   }
//   for (int j=0; j<laserRawRangeData.size(); j++){
//     cout<< "rawRangeData(" << j << ")" << rawRangeData.at(j) <<endl;
//     //rawRangeData.pop_back();
//   }
// //  }
 
//   rangers_.at(1)->readRanger(rawRangeData, 60, 10);
//   radarRawRangeData = rawRangeData;
//   for (int i=0; i<radarRawRangeData.size(); i++){
//     cout<< "radarRawRangeData(" << i << ")" << radarRawRangeData.at(i) <<endl;
//   }
//   for (int j=0; j<radarRawRangeData.size(); j++){
//     cout<< "rawRangeData(" << j << ")" << rawRangeData.at(j) <<endl;
//     //rawRangeData.pop_back();
//   }

//   rangers_.at(2)->readRanger(rawRangeData, 60, 10);
//   sonarRawRangeData = rawRangeData;
//   for (int i=0; i<sonarRawRangeData.size(); i++){
//     cout<< "sonarRawRangeData(" << i << ")" << sonarRawRangeData.at(i) <<endl;
//   }
//   for (int j=0; j<sonarRawRangeData.size(); j++){
//     cout<< "rawRangeData(" << j << ")" << rawRangeData.at(j) <<endl;
//     //rawRangeData.pop_back();
//   }

  // rangers_.at(i)->readRanger(rawRangeData, 60, 10);
  // //sonarRawRangeData = rawRangeData;
  // for(vector<double>::iterator it=itend; it>=itbegin; --it){
  //   // pops last element in vector off the list
  //   cout<<"dbg: rawRangeData(" <<  (it-itbegin) << ")=" << *it<<endl;
  //   rawRangeData.pop_back();
  // }    
  // rawRangeData.clear();


  // Work out the FOV overlap and the Range overlap of sensors.
  
  // Get minimum value of overlapping FOV's.
  // for (int m=0; m<rangers_.size(); m++){
  //   rangers_.at(i).rawRangeData();
  // }
  
  // fovl = rangers_.at(0).fov;
  // fovr = rangers_.at(1).fov;
  // fovs = rangers_.at(2).fov;

  // // Determine overlapping FOV range.
  //
  // minFOV = getMinimum(fovl, fovr, fovs);
  // overlapMinFOV = 90 - minFOV/2;
  // overlapMaxFOV = 90 + minFOV/2;

  // foreach ranger_.at(i); should be some loop in i and then foreach j
  // valueInFOVRange(ranger.at(0).rawRangeData(j));
  //
  // Where valueInFOVrange tests if  range value between overlapMinFOV
  // and  overlapMaxFOV.  If  so flag that this is so.
  //  
  // If value not in FOV range make
  // into any min/max/average values???
  //  
  // value1 = valueInFOVrange(ranger.at(1).rawRangeData(j));
  // value2 = valueInFOVrange(ranger.at(2).rawRangeData(j));
  // value3 = valueInFOVrange(ranger.at(3).rawRangeData(j));

  // For value1, value2, value3, where inOverlappingFOVflag = 1
  // (ie flag is set). Perform fusion according to that chosen by the
  // user(min/max/average).
  // 
  // Use getFusionMethod() return value = string (ie min/max/average);
  //
  // use c++ functions  to determine the min/max/average of those values.
  //

    
  return fusedRangeData;
}


vector<vector<double> > RangerFusion::getRawRangeData(){

  // This function returns a _set_  of vectors, each vector containing
  // a set  of double  values, the sensor  sampled values.   Again the
  // 'raw' sampled  sensor values  are derived from  a call  to Ranger
  // Class  readRanger()  member  function.  The  number  of  returned
  // vectors  is  derived from  the  number  of pointers  in  rangers_
  // vector, that is the number of sensors we are dealing with.

  
  // Note: standard says you must have a space between the last two
  // angle brackets in vector<vector<double> >.
  
  vector<double> rawRangeData;
  int rawRangeDataVecSize;

  vector<vector<double> > rawRangeDataVV; // raw range data Vector of Vectors
  
  for (int i=0; i<rangers_.size(); i++){
    rangers_.at(i)->readRanger(rawRangeData, 60, 10);
    
    // Add an empty row.
    rawRangeDataVV.push_back( vector<double>() );
    
    // File this row with the raw range data.
    for (int j=0; j<rawRangeData.size(); j++){
      rawRangeDataVV[i].push_back(rawRangeData[j]);
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
      cout<<"dbg: rawRangeData(" <<  (it-itbegin) << ")=" << *it<<endl;
      rawRangeData.pop_back();
    }

    
    
  } // for (int i=0; i<rangers_.size(); i++){
  

  // Check output.
  for (int m=0; m<rangers_.size(); m++){
    for (int n=0; n<rawRangeDataVecSize; n++){
      cout << "dbg: rawRangeDataVV[" << m << "]" << "[" << n << "]="
	   << rawRangeDataVV[m][n] <<endl;
    }
  }

  cout << "dbg: pre return getRawRangeData()" << endl;
  

  return rawRangeDataVV;
}

  // vector<double> readRangerRawData;
  
  // for (int j=0; j<rangers_.size(); j++){
  //   rangers_.at(j)->readRanger(readRangerRawData,60,10);

  //   // vector copy, save raw ranger data vector of doubles
  //   //rawRangeData_.at(j) = readRangerRawData;

  //   // itterate the raw data vector backwards.
  //   //
  //   // However, could use rbegin() and rend() vector methods, it works
  //   // accross all containers.
  //   //
  //   // Containers and itterators, it acts like a pointer.
  //   vector<double>::iterator it;
  //   vector<double>::iterator itbegin = readRangerRawData.begin();
  //   vector<double>::iterator itend = readRangerRawData.end()-1;

  //   for(vector<double>::iterator it=itend; it>=itbegin; --it){
  //     // pops last element in vector off the list
  //     cout<<"dbg: readRangerRawData(" <<  (it-itbegin) << ")=" << *it<<endl;
  //     readRangerRawData.pop_back();
  //   }
  // }
