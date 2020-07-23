//
// LaserRangeFinder Derived Class declaration(or interface).
//

#ifndef LASERRANGEFINDER_H__H_
#define LASERRANGEFINDER_H__H_

using namespace std; // allow used of <cstdio>

#include <cmath>


#include "sensor.h"


// LaserRangeFinder class is derived from the Sensor base class.
//
// Due to first line here:
// class rectangle: public Sensor{...
//
// A publicly derived class inherits access to every member of a base class:
// except:
//      its constructors & destructors
//      assignment operator, operator=
//      its friends
//      its private members
class LaserRangeFinder: public Sensor{

 // Access specifier 'public:', these variables and functions are
 // available to all other classes that inherit(?)from this class.
 public:
  // Would these be implicit default do nothing constructors anyhow
  // and thus no need to specify them here?
  //
  LaserRangeFinder(); // class constructor
  ~LaserRangeFinder();// class destructor

//  void setWidthHeight(int side);

  //virtual int getFixedAttributes(void);
  //virtual void setAttributes(int side); // sets configurable attributes

  //int setAttributes(void);
  //int getAttributes(void);
  //int getArea(void);
  //int getPerimeter(void);

 private:
  // Access specifier 'private:', these variables and functions are only
  // available to member functions/class methods.
  
  // Common to Laser Range Finder sensors only, ie not common to other sensors.
  // 
  // ie hardware specific fixed parameters of the sensor
  //
  int fov_;		// Field Of View
  double angularRes_;	// Angular Resplution
  double scanTime_;	// Time to compleate one scan
  double distanceMax;	// Maximum Distance
  double distanceMin;	// Minimum Distance

};


#endif // LASERRANGEFINDER_H_
