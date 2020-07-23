//
// Rectangle class implementation.
//
// 
// Class functions or methods(aka member functions) are defined here.
//

// What is the pitfall of this class???


//#include <iostream>
#include <cstdio>

#include "rectangle.h"



Rectangle::Rectangle():width_(0), height_(0){

}


Rectangle::~Rectangle(){

  // destructor
  
}


void Rectangle::setWidthHeight(int width, int height){

  // This method, or  member function, is required so  code not within
  // this class can access member  variables safely, without having to
  // understand all our code.

  // takes to integer variables and returns nothing

  // It is principally used to initialise the width and height of the rectangle
  width_ = width;
  height_ = height;
  
}


int Rectangle::getArea(void){

  // takes no variables and returns an integer
  return (width_ * height_);
}


int Rectangle::getPerimeter(void){
  
  // takes no variables and returns an integer
  return ((width_*2) + (height_*2));
}
