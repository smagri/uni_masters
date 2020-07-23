//
// Triangle Derived Class declaration(or interface).
//

#ifndef TRIANGLE_H_
#define TRIANGLE_H_

using namespace std; // allow used of <cstdio>

#include <cmath>


#include "shape.h"


// Triangle class is derived from the Shape base class.
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
class Triangle: public Shape{

 // Access specifier 'public:', these variables and functions are
 // available to all other classes that inherit(?)from this class.
 public:
  Triangle(); // class constructor
  ~Triangle();// class destructor

  // Access specifier 'private:', these variables and functions are only
  // available to member functions/class methods.

  int getArea(void);
  int getPerimeter(void);
};


#endif // TRIANGLE_H_
