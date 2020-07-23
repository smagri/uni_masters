//
// Triangle class implementation.
//
// 
// Class functions or methods(aka member functions) are defined here.
//

// What is the pitfall of this class???


//#include <iostream>
#include <cstdio>

#include "triangle.h"



// Triangle::Triangle():width_(0), height_(0){
//
// }

Triangle::Triangle(){

}


Triangle::~Triangle(){

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
void Triangle::setWidthHeight(int side){

  side_ = side;
  
}


int Triangle::getArea(void){

  // Shape is assumed to be a square in the base class.
  
  //return (width_ * height_); // for rectangle
  
  base_ = width_;
  
  return ( (base_ * height_) / 2);
}


int Triangle::getPerimeter(void){
  
  // Shape is assumed to be a square in the base class.
  
  // return ((width_*2) + (height_*2)); for rectangle

  base_ = width_;
    
  return ( (2 * side_) + base_ );
}

