#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"
#include "rectangle.h"


// Class definition

// !wrks: class Rectangle: public Shape{ looks like if I derive from
// an abstract class the derived class becomes abstract too???
class Rectangle : public Shape {

 public:
  Rectangle(double width, double height);
  ~Rectangle();
  bool pointIsInShape(double x, double y);
  double area(void);
  //int operator=(Shaape *shape_array &lhs, Rectangle rectangle &rhs);
  
private:
  double width_; // width and height of the rectangle
  double height_;

};


#endif // RECTANGLE_H
