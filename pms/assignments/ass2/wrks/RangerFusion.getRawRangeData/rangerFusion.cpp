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
  cout << "rangers_ :" << endl << endl;
  cout << "&l1=" << rangers_.at(0) << endl;
  cout << "&r1=" << rangers_.at(1) << endl;
  cout << "&s1=" << rangers_.at(2) << endl;
  cout << "rangers :" << endl << endl;
  cout << "&l1=" << rangers.at(0) << endl;
  cout << "&r1=" << rangers.at(1) << endl;
  cout << "&s1=" << rangers.at(2) << endl;

  cout << "dbg: rangers_.size()=" << rangers_.size() << endl;

  getRawRangeData();

  cout << "rangerFusion::getRawRangeData() just called" << endl;
}

vector<double> RangerFusion::getFusedRangeData(){

}

//vector<vector<double> > RangerFusion::getRawRangeData(){
void RangerFusion::getRawRangeData(){

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
