#ifndef SHAPE_H_
#define SHAPE_H_

#include <string>

using namespace std; // allow use as std::


// Shape base class
//
// Things common to all shapes that derive from this base class.
//
// We need to make this class an  abstract class so no-one can make an
// object of  this type, it  doesn't make sence  to make an  object of
// this shape class.
class Shape{

 public:
  // Shape default constructor, no parameters or return value.
  Shape();


  // vitual, ie choose derived class version of these fn's.  Aka fn
  // overloading.
  //
  // When we make the virtual fn's = 0 it means that we are not going
  // to define these functions in the class implementation.
  //
  // It also makes the class abstract, so no object of this class can
  // be created.
  //
  //
  //
  // Virtual fns in this base class indicate to the compiler to prefer
  // the derived class version of these fn's, not the base class
  // version.
  //
  // If any of these fns are made = 0 it implies that this class
  // becomes an abstract class and thus no object of this class is
  // possible.
  //
  // This creates the problem, see:
  // output.abstractRectanglePureVirtual
  //
  virtual double area(void) = 0;
  virtual bool pointIsInShape(double x, double y) = 0;// point is (x,y)
//  virtual double area(void);
//  virtual bool pointIsInShape(double x, double y);// point is (x,y)

  // Set the centre of the shape be the (x,y) coordinate.
  void setCentre(double x, double y);

  // Get the centre of the shape for derived functions.  As derived
  // functions can't access the private member data of this Shape
  // class.
  void getCentre(double &xCentre_, double &yCentre_);
  
  
 private:
  // Cartesian coordinates in 2d space, entre of the shape.
  double xCentre_;
  double yCentre_;
  
};


#endif // SHAPE_H_
