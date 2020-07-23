#include "rectangle.h"



Rectangle::Rectangle():
width_(0.0), height_(0.0)
{
  /// Class Rectangle default constructor.  Where the width and height
  /// are initialised to 0.0

  description_="square";
}

void Rectangle::setValues(double width, double height)
{
  /// Sets the width and height of the Rectangle.
  width_ = width;
  height_ = height;
  if (width_==height_) {
    description_ = "square";
  } else {
    description_ = "rectangle";
  }
}

void Rectangle::setValues(double side) {

  /// This Rectangle is a square, were all sides are equal.  So width
  /// is equal to height.

  setValues(side, side);
}

double Rectangle::getArea(void)
{
  /// Returns the area of a Rectangle.
  /// 
  return width_ * height_;
}

double Rectangle::getPerimeter(void)
{
  /// Returns the perimeter of the Rectangle.
  
  return 2*width_ + 2*height_;
}
