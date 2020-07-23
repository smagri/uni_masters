#ifndef LASER_H
#define LASER_H

#include <string>

#include "laser.h"
#include "ranger.h"


class Laser : public Ranger{

 public:
  
  // constructor
  Laser(string model, int baud, string port);
  
 private:
  // Access specifier 'private:', these variables and functions are only
  // available to member functions/class methods.
  
  // Fixed hardware parameters.
  //fov_ = 180;           // Field Of View in degrees
  //distanceMax_ = 8.0;   // maximum distance of operation
  //distanceMin_ = 0.2;   // minimum distance of operation
  
};


#endif // LASER_H
