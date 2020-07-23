#ifndef CIRCLE_H
#define CIRCLE_H

// portable pi value
//
#include <cmath>
#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif

#include "shape.h"


class Circle : public Shape{

 // class Circle, as with class Rectangle, derive from the base class
 // shape.
 public:
  Circle(double radius);
  ~Circle();
  bool pointIsInShape(double x, double y);
  double area(void);
  
 private:
  double radius_; // radius of the circle
  
};


#endif // CIRCLE_H
