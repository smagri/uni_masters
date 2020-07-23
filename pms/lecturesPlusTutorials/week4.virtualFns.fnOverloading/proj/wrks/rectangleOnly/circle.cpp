#include <cmath>  // for c++
#include <math.h> // for c

#include "circle.h"



// Do we need these default contructors or destructors.
Circle(double radius){

  radius_ = radius;
     
}

~Circle(){

  // default destructor
  
}


double getArea(){
  
  // !wrks in c++: return (pi * radius_^2);
  //
  // pow(double, double); used:
  return (M_PI * pow(radius_, 2.0));
  
}

    
bool pointIsInShape(x, y){

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

  return ( pow(xCentre_-x,  2) + pow(yCentre_, 2) 
	   <= pow(radius_, 2) );
  

}
