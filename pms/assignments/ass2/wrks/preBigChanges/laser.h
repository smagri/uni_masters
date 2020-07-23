//
// Laser Class Interface.
//
#ifndef LASER_H
#define LASER_H

#include <string>

#include "rangerFusion.h"
#include "laser.h"
#include "ranger.h"


class Laser : public Ranger, public RangerFusion{

  // Laser Class derives from Ranger and RangerFusion base classes.
  
 public:
  
  // constructor
  Laser(string model, int baud, string port);

  // Configurable attribute.
  int setConfigAngularRes(double angularRes);
  double getConfigAngularRes(void);
    
 private:
  // Access specifier 'private:', these variables and functions are only
  // available to member functions/class methods.

  double angularRes_; // angular resolution 15deg or 30deg, user decides
  
};


#endif // LASER_H
