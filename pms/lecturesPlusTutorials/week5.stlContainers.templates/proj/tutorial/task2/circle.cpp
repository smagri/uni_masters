#include <cmath>  // for c++
#include <math.h> // for c

#include "circle.h"



Circle::Circle(double radius){

  radius_ = radius;
     
}

Circle::~Circle(){

  // default destructor
  
}


double Circle::area(void){
  
  // !wrks in c++, if do: return (pi * radius_^2);
  //
  // pow(double, double); used:
  return (M_PI * pow(radius_, 2.0));
  
}

    
bool Circle::pointIsInShape(double x, double y){

  // point is (x, y), is it in the circle shape?
  //
  // 
  // if (  (x < (xCentre + (radius_/2))) && (x > (xCentre - (radius_/2)))
  // 	&& (y < (yCenter + (radius_/2))) && (y > (yCentre - (radius_/2)))  ){
  //   return true;
  // }
  // else{
  //   return false;
  // }

  // error: ‘xCentre_’ was not declared in this scope
  //	This was a syntax error of xCentre_ vs xCenter.
  //
  return (pow(xCentre_-x,  2) + pow(yCentre_-y, 2) <= pow(radius_, 2));

}
