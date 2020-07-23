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

int Triangle::getArea(void){

  // Shape is assumed to be a square in the base class.
  
  //return (width_ * height_); // for rectangle
  
  // width_ here is base of the isosceles triangle.
  // width_ = base
  int base = width_;
  return ( (base * height_) / 2);
}


int Triangle::getPerimeter(void){
  
  // Shape is assumed to be a square in the base class.
  
  // return ((width_*2) + (height_*2)); for rectangle

  // width_ here is base of the isosceles triangle.
  // width_ bace
  int base = width_;
  int side = height_;
    
  return ( (2 * side) + base );
}

