

// system include files
#include <iostream>
#include <cstdio>


// non-system  include files
#include "rectangle.h"
#include "shape.h"


// so you can refer to std class member function just by their name,
// thus with no std:: prefix
using namespace std;


int main(int argc, char *argv[]){

  int width, height, side;

  // create instance of class rectangle, called smRectangle, also,
  // initialiase width=height=0.
  // Rectangle smRectangle;
  // Rectangle smRectangle;  

  
  // fprintf(stderr, "main.cpp, in main():\n\n");
  
  // fprintf(stderr, "\ndefault width=height=0\n");
  // fprintf(stderr, "area of rectangle=%d\n", smRectangle.getArea());
  // fprintf(stderr, "perimiter of rectangle=%d\n", smRectangle.getPerimeter());

  // width = 1; height = 10;
  // smRectangle.setWidthHeight(width, height);
  // fprintf(stderr, "\nset width=%d, height=%d:\n", width, height);
  // fprintf(stderr, "area of rectangle=%d\n", smRectangle.getArea());
  // fprintf(stderr, "perimiter of rectangle %d\n", smRectangle.getPerimeter());

  // side = 5;
  // fprintf(stderr, "side, start=%d\n", side);
  // smRectangle.setWidthHeight(side);
  // fprintf(stderr, "\nset side=\n", side);
  // fprintf(stderr, "area of rectangle=%d\n", smRectangle.getArea());
  // fprintf(stderr, "perimiter of rectangle %d\n", smRectangle.getPerimeter())
    ;

    //Shape shape;
    //Shape::Rectangle rectangle;
    //Shape::setWidthHight(width, height);
    
    Rectangle rectangle;
    width = 4; height = 6;
    // Derived class rectangle object, derived from base class Shape,
    // accessing base class member fn.
    rectangle.Shape::setWidthHeight(width, height);
    
    fprintf(stderr, "\nset width=%d, height=%d:\n", width, height);
    fprintf(stderr, "area of rectangle=%d\n", rectangle.getArea());
    fprintf(stderr, "perimiter of rectangle=%d\n", rectangle.getPerimeter());

  //Triangle triangle;
  //triangle.setWidthHeight(4,6);

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
