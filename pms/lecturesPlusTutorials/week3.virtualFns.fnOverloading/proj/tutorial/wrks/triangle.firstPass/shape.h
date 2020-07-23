#ifndef SHAPE_H_
#define SHAPE_H_

#include <string>

using namespace std; // allow use as std::


// Shape base class
//
class Shape{

 public:
  // Shape default constructor, no parameters or return value.
  Shape();

  // Shape member fns
  //
  // Example of Polymorphisim as same name fn but different signature.
  // Which one is called depends on the object we are using.  We have
  // different fns for different types of objects???
  void setWidthHeight(int width, int height);
  void setWidthHeight(int side);

  // virtual indicates that these fns can be overloaded in derived
  // classes.  This make sence as different objects have different
  // formulas for area and perimitier.
  virtual int getArea(void);
  virtual int getPerimeter(void);

  // What is a 'pure virtual' member fn?  A member fn declaration that
  // turns a normal class into an abstract class, (that is a class from
  // which no objects are made, it's there for inheritence only???).  You
  // only implement it in the derived class, not the base class.
  //
  // class Shape{
  // public:
  // virtual void draw() const = 0; // = 0 => it's 'pure virtual"
  //
  // virtual in functions of virtual = 0 is???
  // void printDescription(void);
  
 protected:
  // protected: accessor type means that these member data of base
  // class Shape are available to the base class and the derived class
  // only.
  //
  // really should be double width_, height_;
  int width_, height_;

 private:
  // string description;
  
};


#endif // SHAPE_H_
