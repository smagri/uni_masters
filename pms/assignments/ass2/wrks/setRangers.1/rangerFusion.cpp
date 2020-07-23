#include <string>

#include "RangerFusionInterface.h"
#include "rangerFusion.h"


// RangerFusion::RangerFusion(){

//   // Fusion method is a method by which the raw sampled data is processed???
  
//   // Default fusion method is by minumum???
//   // Other methods are maximum and average???
//   fusionMethod_ = "min";

// }

// RangerFusion::RangerFusion(string fusionMethod){

//   fusionMethod_ = fusionMethod;
  
// }

RangerFusion::RangerFusion(){

  // or put this in RangerFusionInterface(); constructor.
  fusionMethod_ = "min";
  
}

void RangerFusion::setRangers(vector<Ranger *> rangers){

  rangers_ = rangers;

}

vector<double> RangerFusion::getFusedRangeData(){

}

vector<vector<double> > RangerFusion::getRawRangeData(){

}
