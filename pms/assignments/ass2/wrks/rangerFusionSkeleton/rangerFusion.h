#ifndef RANGERFUSION_H
#define RANGERFUSION_H

#include "RangerFusionInterface.h"


// Virtual functions in RangerFusionInterface.h need to be implemented
// in RangerFusion class here.  As  RangerFusion class is derived from
// the RangerFusionInterface class.  And with virtual functions = 0 in
// RangerFusionInterface.h it means that RangerFusionInterface.h is an
// abstract  class,  and  thus  the  virtual  functions  need  not  be
// implemented in RangerFusionInterface.cpp.
//
//
class RangerFusion: public RangerFusionInterface{


};

#endif
