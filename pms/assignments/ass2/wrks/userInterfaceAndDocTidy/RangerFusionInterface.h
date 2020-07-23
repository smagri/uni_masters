#ifndef RANGERFUSIONINTERFACE_H
#define RANGERFUSIONINTERFACE_H

#include <string>
#include <vector>

//#include "ranger.h"


using std::string;
using std::vector;

// This is a forward declaration of the Ranger class (google it)
// It tells the RangerFusionInterface that such a class exists
// but does not specify its details
class Ranger;

// The RangerFusionInterface is a class which specifies the minimum
// required interface for your RangerFusion class your ranger fusion
// class must inherit from it
class RangerFusionInterface{
  
 public: 
  RangerFusionInterface();

  // Accepts container of rangers as per requirement C2 of assignment 2
  virtual void setRangers(vector<Ranger*> rangers) = 0;

  // Returns a container of fused range readings as per C4 assignment 2
  virtual vector<double> getFusedRangeData() = 0;
  //virtual void getFusedRangeData() = 0;
  //virtual int getFusedRangeData() = 0;

  // Returns a container of raw/unfused range readings as per C5 assignment 2
  virtual vector<vector<double> > getRawRangeData() = 0;
  // wrks, for testing: virtual void getRawRangeData() = 0;
  //virtual void getRawRangeData() = 0;

 protected:
  // also wrks??? test again later: private:
// private:
  
  //vector<vector<double> > rawRangeData_;
  
  //string fusionMethod_; // method of processing raw sampled data
  
  // STL vector container stores Sensors/Rangers
  //vector<Ranger *> rangerContainer;

};

//#include "ranger.h"

#endif // RANGERFUSIONINTERFACE_H

