#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

// Class Rectangle is derived from the Shape base class.
// REMOVE: in rectangle.h

/*!
 *  \ingroup   ac_shapre Rectangle
 *  \brief     Rectangle class is derived from base class Shape
 *  \details
 *  This class is derived from the base class shape.\n
 *  \author    Simone Magri
 *  \version   1.0
 *  \date      2017
 *  \pre       none
 *  \bug       some reported as of 2016-04-25
 *  \bug       * fusion algorithim not complete
 *  \warning   
 */

class Rectangle : public Shape
{
public:
    Rectangle();
    
    /* /\** */
    /* This function sets the width and height of a Rectangle */

    /* @param[in]    width dimension of rectangle */
    /* @param[in]    height dimension of rectangle */
    /* *\/ */
    void setValues(double width, double height);
    void setValues(double side);
    double getArea (void);
    double getPerimeter(void);

private:
    double width_;//!< width of the rectangle
    double height_;///< height of the rectangle
};

#endif // RECTANGLE_H
