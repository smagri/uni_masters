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
  // Would these be implicit default do nothing constructors anyhow
  // and thus no need to specify them here?
  //
  Triangle(); // class constructor
  ~Triangle();// class destructor


  void setWidthHeight(int side);
  
  int getArea(void);
  int getPerimeter(void);

 private:
  // Access specifier 'private:', these variables and functions are only
  // available to member functions/class methods.
  
  // The length of the two eqaual sides of an isosceles triangle is
  // specific to the isoseles triangle shape, not all shapes.  Hence
  // not put in base class but put here so it is only accessable to
  // the triangle class.
  int side_;
  int base_; // really just equal to the width_ of the shape
};


#endif // TRIANGLE_H_
