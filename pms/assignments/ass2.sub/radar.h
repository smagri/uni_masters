//
// Radar Class interface.
//
#ifndef RADAR_H
#define RADAR_H


#include <string>

#include "radar.h"
#include "ranger.h"


class Radar : public Ranger{

  // Sonar Class derives from Ranger and RangerFusion base classes.
  
 public:
  
  // constructor
  Radar(string model, int baud, string port);

  // Configurable attribute.
  void setConfigFOV(double fov);
  //double getConfigFOV(double fov);
  
 private:
  // Access specifier 'private:', these variables and functions are only
  // available to member functions/class methods.
  
};


#endif // RADAR_H
