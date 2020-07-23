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
