#ifndef RANGERFUSION_H
#define RANGERFUSION_H

//#include <vector>
//#include <string>

#include "ranger.h"
#include "RangerFusionInterface.h"

using namespace std;


// Virtual functions in RangerFusionInterface.h need to be implemented
// in RangerFusion class here.  As  RangerFusion class is derived from
// the RangerFusionInterface class.  And with virtual functions = 0 in
// RangerFusionInterface.h it means that RangerFusionInterface.h is an
// abstract  class,  and  thus  the  virtual  functions  need  not  be
// implemented in RangerFusionInterface.cpp.
//
//
class RangerFusion: public RangerFusionInterface{
  
 public:

  RangerFusion();  // Here because derived classes require it.
  RangerFusion(string fusionMethod);

  void setRangers(vector<Ranger*> rangers);
  vector<double> getFusedRangeData();
  //vector<vector<double> > getRawRangeData();
  void getRawRangeData();

 protected:

  string fusionMethod_; // method of processing raw sampled data

  // STL vector container stores Sensors/Rangers
  vector<Ranger *> rangers_;
  
  
};

#endif
