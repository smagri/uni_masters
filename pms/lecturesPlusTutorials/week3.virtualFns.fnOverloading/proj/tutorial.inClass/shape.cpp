//
// Shape base class implementation
//
// 
// Class functions or methods(aka member functions) are defined here.
//


//#include <iostream>
#include <cstdio>

//#include "rectangle.h"
#include "shape.h"


Shape::Shape(){

  width_ = 0;
  height_ = 0;
    

}


Shape::~Shape(){

  // destructor
  
}




void Shape::setWidthHeight(int width, int height){

  // This method, or  member function, is required so  code not within
  // this class can access member  variables safely, without having to
  // understand all our code.

  // takes to integer variables and returns nothing

  // It is principally used to initialise the width and height of the rectangle
  width_ = width;
  height_ = height;
  
}


void Shape::setWidthHeight(int side){

  setWidthHeight(side, side);
  
}



int Shape::getArea(void){

  // takes no variables and returns an integer
  return (width_ * height_);
}


int Shape::getPerimeter(void){
  
  // takes no variables and returns an integer
  return ((width_*2) + (height_*2));
}
