//
// Rectangle Class declaration.
//

#ifndef RECTANGLE_H_
#define RECTANGLE_H_

using namespace std; // allow used of <st


class Rectangle{

 // Access specifier 'public:', these variables and functions are
 // available to all other classes that inherit(?)from this class.
 public:
  //Rectangle(int width, int height); // class constructor
  Rectangle(); // class constructor
  ~Rectangle();// class destructor

  // void => return nothing or no parameters passed.
  void setWidthHeight(int width, int height);
  int getArea(void);
  int getPerimeter(void);

  // Access specifier 'private:', these variables and functions are only
  // available to member functions/class methods.
 private:
  int width_, height_;
  
};


#endif // RECTANGLE_H_
