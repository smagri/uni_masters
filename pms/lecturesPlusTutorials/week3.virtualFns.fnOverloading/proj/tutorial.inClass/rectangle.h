//
// Rectangle Class declaration.
//

2#ifndef RECTANGLE_H_
#define RECTANGLE_H_

using namespace std; // allow used of <st

#include <cmath>


#include "shape.h"


class Rectangle: public Shape{

 // Access specifier 'public:', these variables and functions are
 // available to all other classes that inherit(?)from this class.
 public:
  //Rectangle(int width, int height); // class constructor
  Rectangle(); // class constructor
  ~Rectangle();// class destructor

  // Access specifier 'private:', these variables and functions are only
  // available to member functions/class methods.
  
};


#endif // RECTANGLE_H_
