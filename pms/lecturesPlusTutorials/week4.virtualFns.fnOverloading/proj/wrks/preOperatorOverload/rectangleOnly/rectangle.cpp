#include "rectangle.h"


// Class implementation

// Do we need the default constructor and destructor at all???

Rectangle::Rectangle(double width, double height){

  width_ = width;
  height_ = height;
  
}

Rectangle::~Rectangle(){

}


Rectagle::double getArea(){

  return (width_ * height_);
}


bool pointIsInShape(x, y){

  // point is (x, y), is it in the rectangle shape?
 
  if (  (x < (xCentre + (width_/2))) && (x > (xCentre - (width_/2)))
	&& (y < (yCenter + (height_/2))) && (y > (yCentre - (height_/2)))  ){
    return true;
  }
  else{
    return false;
  }

}
 
