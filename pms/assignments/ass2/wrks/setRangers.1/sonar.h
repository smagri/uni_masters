#ifndef SONAR_H
#define SONAR_H

#include "sonar.h"
#include "ranger.h"


class Sonar : public Ranger{

 public:
  
  // constructor
  Sonar(string model, int baud, string port);
  
 private:
  // Access specifier 'private:', these variables and functions are only
  // available to member functions/class methods.

  // Fixed hardware parameters.
  //fov_ = 180;           // Field Of View in degrees
  //distanceMax_ = 8.0;   // maximum distance of operation
  ///distanceMin_ = 0.2;   // minimum distance of operation
  
};


#endif // SONAR_H
