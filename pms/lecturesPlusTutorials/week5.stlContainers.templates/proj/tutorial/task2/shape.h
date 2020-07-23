#ifndef SHAPE_H_
#define SHAPE_H_

#include <string>

using namespace std; // allow use as std::


// Shape base class
//
// Things common to all shapes are derived from this base class.
//
// We need to make this class an  abstract class so no-one can make an
// object of  this type, it  doesn't make sence  to make an  object of
// this shape class.
//
class Shape{

 public:
  // Shape default constructor, no parameters or return value.
  Shape();

  // 'virtual' => choose derived class version of these fn's, instead
  // of this base class's.  Aka fn overloading.  'virtual' fns in this
  // base class indicate  to the compiler to prefer  the derived class
  // version of these fn's, not the base class version.
  //
  // When we  make the  'virtual' fn's =  0 it means  that we  are not
  // going to define these functions in the class implementation, that
  // is, here, in this Shape base class implementation.
  //
  // 'virtual' fn's = 0 also makes the class abstract, so no object of
  // this class can ever be created.  These functions are known as
  // pure virtual fn's.
  //
  virtual double area(void) = 0;
  virtual bool pointIsInShape(double x, double y) = 0;// point is (x,y)

  // Set the centre of the shape be the (x,y) coordinate.
  void setCentre(double x, double y);

  // Get the centre of the shape for derived functions.  As derived
  // functions can't access the private member data of this Shape
  // class.
  void getCentre(double &xCentre_, double &yCentre_);
  
  
 protected:
  // Cartesian coordinates in 2d space, centre of the shape.
  //
  // Make 'protected:' so derived classes can see them directly.
  double xCentre_;
  double yCentre_;
  
};


#endif // SHAPE_H_
