#include <cstdio>
#include <vector>

#include "shape.h"
#include "circle.h"
#include "rectangle.h"
#include "shapefunctions.h"


#define NUM_SHAPES 6
//#define NUM_SHAPES 2


using namespace shape_functions;


int main(int argc, char *argv[]){

  // Use a vector instead of an array, vectors are like arrays but
  // have extra functionality.
  //
  // Also notice that this is a pointer to the Shape base class, which
  // both circle and rectangle classes are derived from.
  //
  vector<Shape *> shapeContainter;
  
  int numShapes;
  double x, y, totalArea;
  double *ptr;
  
  // Create/instantiate three rectangles and three circles.
  //
  // Three circles with radii 3,4,5 which are centred at (0.0, 0.0)
  // unless setCentre() is called with new centre coordinate values.
  Circle c1(3);
  Circle c2(4);
  Circle c3(5);
  // For simplicity lets make width_=height_ in this example.  Again
  // here, for the rectangles the squares are centred at (0.0, 0.0)
  // unless setCentre() is called with new centre coordinate values.
  Rectangle r1(1.0, 1.0);
  Rectangle r2(2.0, 2.0);
  Rectangle r3(3.0, 3.0);

  vector<Shape *> shapeContainer = {&c1, &c2, &c3, &r1, &r2, &r3};

  // howto do this with a vector???
  // shape_array[0]->setCentre(2.0, 1.0);
  shapeContainer.at(0)->setCentre(2.0, 1.0);
 
  // Does the area of the shape overlap with the origin?
  //
  numShapes = NUM_SHAPES;
  // coordinates of origin is the bounding point
  x = 0.0; y = 0.0;

  // shape_functions::  is  a  namespace  like std::,  thus  it  is  a
  // grouping of data and functions.
  totalArea =
    shape_functions::getAreaOfBoundingShapes(shapeContainer, numShapes, x, y);

  fprintf(stderr, "Bounding point is (%f, %f):\n", x, y);
  fprintf(stderr, "The total area of shapes which bound the point is %f\n",
  	  totalArea);
	  
}
