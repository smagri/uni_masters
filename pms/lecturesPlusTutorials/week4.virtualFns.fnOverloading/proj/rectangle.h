#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"
#include "rectangle.h"


// Class definition

// Looks like if you derive, or inherit, from an abstract class
// derived class becomes abstract too???
//
class Rectangle : public Shape {
  
 // class Rectangle, derives  from the base class shape.   Shape is an
 // abstract class, thus no object of this class can be made.
  
 public:
  Rectangle(double width, double height);
  ~Rectangle();
  bool pointIsInShape(double x, double y);
  double area(void);
  
 private:
  double width_; // width and height of the rectangle
  double height_;

};


#endif // RECTANGLE_H
