//
// Rectangle Derived Class declaration(or interface).
//

#ifndef RECTANGLE_H_
#define RECTANGLE_H_

using namespace std; // allow used of <cstdio>

#include <cmath>


#include "shape.h"


// Rectangle class is derived from the Shape base class.
//
// Due to first line here:
// class rectangle: public Shape{...
//
// A publicly derived class inherits access to every member of a base class:
// except:
//	its constructors & destructors
//	assignment operator, operator=
//	its friends
//	its private members
class Rectangle: public Shape{

 // Access specifier 'public:', these variables and functions are
 // available to all other classes that inherit(?)from this class.
 public:
  Rectangle(); // class constructor
  ~Rectangle();// class destructor

  // Access specifier 'private:', these variables and functions are only
  // available to member functions/class methods.
  
};


#endif // RECTANGLE_H_
