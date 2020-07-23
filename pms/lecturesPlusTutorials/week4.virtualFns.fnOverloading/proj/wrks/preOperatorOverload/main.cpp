#include <cstdio>

#include "shape.h"
#include "circle.h"
#include "rectangle.h"
#include "shapefunctions.h"


//#define NUM_SHAPES 6
#define NUM_SHAPES 2


using namespace shape_functions;


int main(int argc, char *argv[]){

  // Array of pointers to shapes
  //Shape **shape_array;
  Shape *shape_array[NUM_SHAPES];
  int numShapes;
  double x, y, totalArea;
  double *ptr;
  
  // Create/instantiate three rectangles and three circles.
  //
  // Three circles with radii 3,4,5 which are centred at (0.0, 0.0)
  // unless setCentre() is called with new centre coordinate values.
  Circle c1(3);
  // Circle c2(4);
  // Circle c3(5);
  // For simplicity lets make width_=height_ in this example.  Again
  // here, for the rectangles the squares are centred at (0.0, 0.0)
  // unless setCentre() is called with new centre coordinate values.
  //    Rectangle r1(1.0, 1.0);
  Rectangle r1(1.0, 1.0);
  // Rectangle r2(2,2);
  // Rectangle r3(3,3);

  // shape_array[0] = &c1;
  // shape_array[0]->setCentre(2.0, 1.0);
  // shape_array[1] = &c2;
  // shape_array[2] = &c3;
  // shape_array[3] = &r1;
  // shape_array[4] = &r2;
  // shape_array[5] = &r3;
 
  shape_array[0] = &c1;
  shape_array[1] = &r1;
 
  // Does the area of the shape overlap with the origin?
  //
  numShapes = NUM_SHAPES;
  // coordinates of origin
  x = 0.0;
  y = 0.0;

  // shape_functions:: is like std in std::, ie it is a namespace, or
  // a grouping of data and functions.
  totalArea = shape_functions::getAreaOfBoundingShapes(shape_array, numShapes,
  						       x, y);
  fprintf(stderr, "Bounding point is (%f, %f):\n", x, y);
  fprintf(stderr, "The total area of shapes which bound the point is %f\n",
  	  totalArea);
	  
}
