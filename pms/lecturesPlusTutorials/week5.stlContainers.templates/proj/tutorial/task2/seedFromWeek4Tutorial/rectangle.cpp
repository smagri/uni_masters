#include "rectangle.h"
#include "shape.h"


// Class implementation

// Do we need the default constructor and destructor at all???

Rectangle::Rectangle(double width, double height){

  width_ = width;
  height_ = height;
  
}

Rectangle::~Rectangle(){

}


double Rectangle::area(){

  return (width_ * height_);
}


bool Rectangle::pointIsInShape(double x, double y){

  // point is (x, y), is it in the rectangle shape?
  double xc, yc;
  
  //error:  ‘xCentre_’ was  not declared  in  this scope:  this was  a
  //spelling error in  the first mention of yCentre_  in the following
  //expression.
  //
  if (  (x < (xCentre_ + (width_/2))) && (x > (xCentre_ - (width_/2)))
    	&& (y < (yCentre_ + (height_/2))) && (y > (yCentre_ - (height_/2)))  ){
    return true;
  }
  else{
    return false;
  }

}
 

// lhs = shape_array[n]; is  pointer to  shape or  reference to  Shape, pass
// this as a reference.
//
// rhs = &rhs

// int operator=(Shape &lhs, Rectangle &rhs){
  
//   lhs = rhs;

// }
