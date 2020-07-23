

// system include files
#include <iostream>
#include <cstdio>


// non-system  include files
#include "triangle.h"
#include "rectangle.h"
#include "shape.h"


// so you can refer to std class member function just by their name,
// thus with no std:: prefix
using namespace std;


int main(int argc, char *argv[]){

  int width, height, side;


    //Shape shape;
    //Shape::Rectangle rectangle;
    //Shape::setWidthHight(width, height);
    
    Rectangle rectangle;
    width = 4; height = 6; side = 1;
    // Derived class rectangle object, derived from base class Shape,
    // accessing base class member fn.
    //
    rectangle.Shape::setWidthHeight(width, height);
    fprintf(stderr, "\nset rectangle: width=%d, height=%d:\n", width, height);
    fprintf(stderr, "area of rectangle=%d\n", rectangle.getArea());
    fprintf(stderr, "perimiter of rectangle=%d\n", rectangle.getPerimeter());

    side = 5;
    rectangle.Shape::setWidthHeight(side);
    fprintf(stderr, "\nset rectangle: width=%d, height=%d:\n", side, side);
    fprintf(stderr, "area of rectangle=%d\n", rectangle.getArea());
    fprintf(stderr, "perimiter of rectangle=%d\n", rectangle.getPerimeter());
	
    
    // Where triangle type is an isoseles triangle, with two equal sides.
    //
    Triangle triangle;
    width = 4; height = 6; side = 5;
    triangle.Shape::setWidthHeight(width, height);
    triangle.setWidthHeight(side);

    fprintf(stderr, "\nset isoseles triangle: base=%d, height=%d, side=%d:\n",
	    width, height, side);
    fprintf(stderr, "area of isosceles triangle=%d\n", triangle.getArea());
    fprintf(stderr,
	    "perimiter of isosceles triangle=%d\n", triangle.getPerimeter());

    
  // Makes no sence to do this as it is an abstract class, ie no
  // objects created for this class, it is only there to be derived
  // from or inherited from???
  //
  // Shape shape;
  // shape.area();
  // shape.perimitirer();
  // shape.setWidthHeight(5, 5);

  //Shape *shape_ptr = &triangle; // same for tringle and shape instance
  //shape_ptr->area();
  //shape_ptr->perimiter();
  //ans: -1, -1  
  
  return 0;
}
