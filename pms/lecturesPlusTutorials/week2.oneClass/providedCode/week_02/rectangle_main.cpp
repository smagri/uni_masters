// We need to include the declaration of our new rectangle class in order to use it.
#include "rectangle.h"

#include <iostream>

int main () {

    // Create a rectangle object
    Rectangle rectangle;

    // Set the values of the sides
    rectangle.set_values(5,2);

    // Get the area and print it to screen
    int result = rectangle.area();
    std::cout << result << std::endl;

    return 0;
}
