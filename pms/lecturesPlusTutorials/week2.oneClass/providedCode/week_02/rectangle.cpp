#include "rectangle.h"

// Empty constructor
Rectangle::Rectangle()
{
}

// Implementation of the set values method
// ...accepts two integers, and sets the corresponding member variables
void Rectangle::set_values (int width, int height){
    width_ = width;
    height_ = height;
    return;
}
// Implementation of the area method
// ...calculates and returns the area of the rectangle based on the sides
int Rectangle::area(void) {
    return width_*height_;
}
