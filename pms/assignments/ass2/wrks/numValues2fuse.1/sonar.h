//
// Sonar Class Interface.
//
#ifndef SONAR_H
#define SONAR_H

#include "sonar.h"
#include "ranger.h"


//class Sonar : public Ranger, public RangerFusion{
class Sonar : public Ranger{

  // Sonar Class derives from Ranger and RangerFusion base classes.
  
 public:
  
  // constructor
  Sonar(string model, int baud, string port);
  
 private:
  // Access specifier 'private:', these variables and functions are only
  // available to member functions/class methods.

};


#endif // SONAR_H
