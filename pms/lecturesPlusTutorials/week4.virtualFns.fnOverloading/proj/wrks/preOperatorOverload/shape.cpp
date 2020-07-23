//
// Shape base class implementation.
//
// 
// Class functions or methods(aka member functions) are defined here.
//


//#include <iostream>
#include <cstdio>

#include "shape.h"


Shape::Shape():xCentre_(0.0), yCentre_(0.0){

  // Default shape centre is (0.0, 0.0);

  // Or do the following:
  // xCentre_ = 0;
  // yCentre_ = 0;
  
}


// Shape::~Shape(){

//   // destructor
  
// }


void  Shape::setCentre(double x, double y){

  xCentre_ = x;
  yCentre_ = y;

}


void  Shape::getCentre(double &x, double &y){

  x = xCentre_;
  y = yCentre_;

}


// This is a test stub to see if it works while fns in base class have
// not made virtual = 0 yet, that is base class is not abstract yet.
//
// Empty stub at this stage, probably need  to make fn virtual = 0, so
// no intance of shapefunctions class is ever permitted to be created.
// double Shape::area(void){

//   // getArea stub for testing
//   fprintf(stderr, "shap.cpp: getAread()\n");

// }


// bool Shape::pointIsInShape(double x, double y){

//   // getArea stub for testing
//   fprintf(stderr, "shap.cpp: pointIsInShape()\n");

// }
