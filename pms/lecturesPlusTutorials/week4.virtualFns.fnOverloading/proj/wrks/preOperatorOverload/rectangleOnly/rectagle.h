#ifndef RECTANGLE_H
#define RECTANGLE_H


class Rectangle: public Shape{
  
  bool pointIsInShape(x, y);
  double getArea();
  
private:
  double width_; // width and height of the rectangle
  double height_;

}


#endif // RECTANGLE_H
