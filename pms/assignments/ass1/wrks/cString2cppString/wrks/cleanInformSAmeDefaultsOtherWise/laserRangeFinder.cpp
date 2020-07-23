//
// LaserRangeFinder class implementation.
//
// 
// Class functions or methods(aka member functions) are defined here.
//

// What is the pitfall of this class???


//#include <iostream>
#include <cstdio>

#include "laserRangeFinder.h"



// LaserRangeFinder::LaserRangeFinder():width_(0), height_(0){
//
// }

LaserRangeFinder::LaserRangeFinder(){

  // Hardware fixed parameters.
  fov_ = 180;		// Field Of View in degrees
  distanceMax_ = 8.0;	// maximum distance of operation
  distanceMin_ = 0.2;	// minimum distance of operation

  // Configurable sensor paramerters.
  //
  // These two variables are coupled, ie (1.0deg, 25ms) & (0.5deg, 50ms)
  angularRes_ = 1.0;	// 1.0 or 0.5 degrees allowed	
  //scantime_ = 0.025;	// 25ms or 50ms allowed, derived from angularRes_
}


LaserRangeFinder::~LaserRangeFinder(){

  // destructor
  
}



// POLYmorphism here as same fn name but different signature in base
// classs vs this triangle derived class.
//
// That is  derived class  can add  member fns to  the class,  and the
// derived  class  can  overload  members of  the  base  class.   Here
// setWidthHeight()/getAreaa()/getPerimiter() fns  are overloading the
// base  class member  fns  with  the same  name.   Which method  gets
// executed at  run time  depends on  the type  of the  object calling
// them.
//
// Class inheritance includes: overloading methods, polymorphism, and
// multiple inheritance.
//
// void LaserRangeFinder::setWidthHeight(int side){

//   side_ = side;
  
// }

int LaserRangeFinder::getFixedHdwAttributes(double &att1, double &att2,
					    double &att3){

  // Hardware fixed parameters.
  att1 = fov_;
  att2 = distanceMax_;
  att3 = distanceMin_;

  fprintf(stderr, "dbg: in LaserRangeFinder::getFixedHdwAttributes\n");
  
  return 0;
}


int LaserRangeFinder::setConfigAttributes(double &att1, double &att2,
					  double &att3){

  if ( (att1 == 0.5) || (att1 == 1.0) ){
    // Valid Angular Resolution entered by user.
    angularRes_ = att1;
  }
  else{
    // Ivalid Angular Resolution entered by user, output error message.
    fprintf(stderr,
	    " Error: Invalid Angular Resolution entered,"
	    " 0.5deg & 1.0deg valid,");
    fprintf(stderr, " defaulting to 0.5deg,\n");
    fprintf(stderr, "        so Scan Time is 50ms.\n");
    angularRes_ = 0.5;
  }
  
  //att2 = scanTime_;	// 25ms or 50ms allowed, derived from angular resoltion
  
  return 0;
}






// int LaserRangeFinder::getArea(void){

//   // Shape is assumed to be a square in the base class.
  
//   base_ = width_;
  
//   return ( (base_ * height_) / 2);
// }


// int LaserRangeFinder::getPerimeter(void){
  
//   // Shape is assumed to be a square in the base class.

//   base_ = width_;
    
//   return ( (2 * side_) + base_ );
// }
