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
  vector<vector<double> > getRawRangeData();
  int readRangeData();
  
 protected:

  // User specified method of processing/fusing raw sampled data.
  string fusionMethod_;

  // The set of ranger(sensors) objects/pointers to do fusion on.
  //
  vector<Ranger *> rangers_;  // STL vector container.

  // Stored vector of: vectors that belong to each ranger/sensor that is
  // being fused/processed.
  //
  vector<vector<double> > rawRangeDataVV_; // STL vector of a vector of doubles.
  
};

#endif
