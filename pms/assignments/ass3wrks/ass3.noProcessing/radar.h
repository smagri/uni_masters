//
// Radar Class interface.
//
#ifndef RADAR_H
#define RADAR_H

#include <string>

#include "ranger.h"

/*!
 *  \ingroup   ac_shapre Radar
 *  \brief     Class Radar
 *  \details
 *  This class is derived from the base class Ranger.\n
 *  \author    Simone Magri
 *  \version   1.0
 *  \date      2017
 *  \pre       none
 *  \bug       none
 *  \warning   
 */

class Radar : public Ranger{

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
