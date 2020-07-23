#ifndef SHAPE_H_
#define SHAPE_H_

#include <string>

using namespace std; // allow use as std::


class Shape{

  // Shape base class
 public:
  Shape();
  // void => return nothing or no parameters passed.
  void setWidthHeight(int width, int height);
  void setWidthHeight(int side);
  virtual int getArea(void);
  virtual

    int getPerimeter(void);
  // virtual in functions of virtual = 0
 protected:
  double width_, height_;
  
}
