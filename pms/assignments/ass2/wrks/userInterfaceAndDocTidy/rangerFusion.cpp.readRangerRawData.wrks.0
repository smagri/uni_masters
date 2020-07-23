#include <cstdio>
#include <iostream>
#include <string>

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

  // Accepts  a vector  or rangers,  or pointers  to objects  of class
  // Ranger, indicating a particular sensor(laser, radar, sonar...).

  // vector<Ranger *> rangersl;
  rangers_ = rangers;
  cout << "rangers_ :" << endl;
  cout << "&l1=" << rangers_.at(0) << endl;
  cout << "&r1=" << rangers_.at(1) << endl;
  cout << "&s1=" << rangers_.at(2) << endl;
  cout << "rangers :" << endl;
  cout << "&l1=" << rangers.at(0) << endl;
  cout << "&r1=" << rangers.at(1) << endl;
  cout << "&s1=" << rangers.at(2) << endl;

  cout << "dbg: rangers_.size()=" << rangers_.size() << endl;

  vector<double> readRangerRawData;
  
  for (int j=0; j<rangers_.size(); j++){
    rangers_.at(j)->readRanger(readRangerRawData,60,10);

    // itterate the raw data vector backwards.
    //
    // However, could use rbegin() and rend() vector methods, it works
    // accross all containers.
    //
    // Containers and itterators, it acts like a pointer.
    vector<double>::iterator it;
    vector<double>::iterator itbegin = readRangerRawData.begin();
    vector<double>::iterator itend = readRangerRawData.end()-1;

    for(vector<double>::iterator it=itend; it>=itbegin; --it){
      // pops last element in vector off the list
      cout << "dbg: readRangerRawData(" <<  (it-itbegin) << ")=" << *it << endl;
      readRangerRawData.pop_back();
    }
  }
  
}

vector<double> RangerFusion::getFusedRangeData(){

}

vector<vector<double> > RangerFusion::getRawRangeData(){

  //l1.getRawData();
  //vector<double> tmpVec;

  // vector<double> vec = rangers_.at(0)->getRawData();
  //rangers_.at(0)->getRawData();
  //cout << "rangers_.at(0)=" << rangers_.at(0) << endl;
  //cout << "rangers_.at(0)->rawData_=" << rangers_.at(0)->rawData_ << endl;
  
  //tmpVec = rangers_.at(0)->getRawData();
  // rangers_.at(1)->rawData_;
  // rangers_.at(2)->rawData_;

  // for (int i=0; i<rangers_.size(); i++){
  //   for (it=rangers_.at(i); it<rangers_.at(i)->size(); it++){
  //   }
  // }
		      
  // for (int i=0; i<rawData_.size(); i++){
  //   cout << "dgb: rawData_.at(" << i << ")=" << rawData_.at(i) << endl;
  // }

  //cout << "dbg: in printValues:" << endl;

  // long hand for the first time.
  // vector<double>::iterator it;
  // vector<double>::iterator itbegin = rangers_.at(0).begin();
  // vector<double>::iterator itend = rangers_.at(0).end();
  
  // for (it=itbegin; it<itend; it++){
  //   cout << *it << " ";
  // }
  // cout << endl;
  
  //vector<double>::iterator it;
  //vector<double>::iterator itbegin = tmpVec.begin();
  //vector<double>::iterator itend = tmpVec.end();
  // for (it=itbegin; it<itend; it++){
  //   cout << *it << " ";
  // }
  // cout << endl;
  // for (int i=0; i<tmpVec.size(); i++){
  //   cout << tmpVec.at(i);
  // }
  //cout << tmpVec.at(0);
  //cout << rangers_.at(0)->getRawData() << endl;
  

  //fprintf(stderr, "dbg:\n");
  
  
}
