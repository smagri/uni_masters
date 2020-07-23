

// system include files
#include <iostream>
#include <cstdio>


// non-system  include files
#include "rectangle.h"


// so you can refer to std class member function just by their name,
// thus with no std:: prefix
using namespace std;


int main(int argc, char *argv[]){

  int width, height;

  // create instance of class rectangle, called smRectangle, also,
  // initialiase width=height=0.
  Rectangle smRectangle;  
  
  fprintf(stderr, "main.cpp, in main():\n\n");
  
  std::cout << "Hello World via cout" << std::endl;
  fprintf(stderr, "Hello World via cstdio.h\n");

  
  fprintf(stderr, "\ndefault width=height=0\n");
  fprintf(stderr, "area of rectangle=%d\n", smRectangle.getArea());
  fprintf(stderr, "perimiter of rectangle=%d\n", smRectangle.getPerimeter());

  width = 1; height = 10;
  smRectangle.setWidthHeight(width, height);
  fprintf(stderr, "\nset width=%d, height=%d:\n", width, height);
  fprintf(stderr, "area of rectangle=%d\n", smRectangle.getArea());
  fprintf(stderr, "perimiter of rectangle %d\n", smRectangle.getPerimeter());

  width = 5; height = 10;
  smRectangle.setWidthHeight(width, height);
  fprintf(stderr, "\nset width=%d, height=%d:\n", width, height);
  fprintf(stderr, "area of rectangle=%d\n", smRectangle.getArea());
  fprintf(stderr, "perimiter of rectangle %d\n", smRectangle.getPerimeter());
  
  return 0;
}
