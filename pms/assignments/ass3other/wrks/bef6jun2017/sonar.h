//
// Sonar Class Interface.
//
#ifndef SONAR_H
#define SONAR_H

#include "ranger.h"

/*!
 *  \ingroup   ac_shapre Sonar
 *  \brief     Class Sonar.
 *  \details
 *  This class is derived from the base class Ranger.\n
 *  \author    Simone Magri
 *  \version   1.0
 *  \date      2017
 *  \pre       none
 *  \bug       none
 *  \warning   
 */


class Sonar : public Ranger{

  // Sonar Class derives from Ranger and RangerFusion base classes.
  
 public:
  
  // constructor
  Sonar(string model, int baud, string port);

  void setConfigFOV(double fov);
  
 private:
  // Access specifier 'private:', these variables and functions are only
  // available to member functions/class methods.

};


#endif // SONAR_H
