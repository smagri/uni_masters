#include <string>

#include "RangerFusionInterface.h"
#include "rangerFusion.h"


RangerFusion::RangerFusion(){

  // Default contructor,  expected to be called  after constructors of
  // classes that derive from the RangerFusion class are executed.
  
}

RangerFusion::RangerFusion(string fusionMethod){

  // Or put this in RangerFusionInterface(); constructor.
  fusionMethod_ = fusionMethod;
  
}

void RangerFusion::setRangers(vector<Ranger *> rangers){

  rangers_ = rangers;

}

vector<double> RangerFusion::getFusedRangeData(){

}

vector<vector<double> > RangerFusion::getRawRangeData(){

}
