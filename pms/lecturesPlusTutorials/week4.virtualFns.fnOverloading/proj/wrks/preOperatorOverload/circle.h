#ifndef CIRCLE_H
#define CIRCLE_H

// portable pi value
//
#include <cmath>
#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif

#include "shape.h"


class Circle{

 public:
  Circle(double radius);
  ~Circle();
  bool pointIsInShape(double x, double y);
  double getArea(void);
  
 private:
  double radius_; // radius of the circle
  
};


#endif // CIRCLE_H
