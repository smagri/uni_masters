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
  int fov_ = 180;		// Field Of View in degrees
  double distanceMax_ = 8.0;	// maximum distance of operation
  double distanceMin_ = 0.2;	// minimum distance of operation

  // Configurable sensor paramerters.
  //
  // These two variables are coupled, ie (1.0deg, 25ms) & (0.5deg, 50ms)
  double angularRes_ = 1.0;	// 1.0 or 0.5 degrees allowed	
  double scanTime_ = 0.025;	// 25ms or 50ms allowed
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
//void LaserRangeFinder::getFixedHdwAttributes(fov, distanceMax, distanceMin){
int LaserRangeFinder::getFixedHdwAttributes(void){

  // Hardware fixed parameters.
  // fov = fov_;
  // ddistanceMax = distanceMax_;
  // distanceMin = distanceMin_;
  // fov_;
  // distanceMax_;
  // distanceMin_;

  return fov_;
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
