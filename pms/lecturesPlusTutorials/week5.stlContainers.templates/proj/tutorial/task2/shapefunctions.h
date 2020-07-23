#ifndef SHAPEFUNCTIONS_H
#define SHAPEFUNCTIONS_H

#include <vector>

#include "shape.h"

// Function prototype here should match fn definition in shapefunctions.cpp.
//
namespace shape_functions { 

  double getAreaOfBoundingShapes(vector<Shape *> &shapeContainer,
  				 int num_shapes,
  				 double x, double y);
}


#endif // SHAPEFUNCTIONS_H
