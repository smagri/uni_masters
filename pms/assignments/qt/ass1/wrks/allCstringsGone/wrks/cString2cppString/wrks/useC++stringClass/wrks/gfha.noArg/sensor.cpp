//
// Sensor base class implementation.
//
// 
// Class functions or methods(aka member functions) are defined here.
//


//#include <iostream>
#include <cstdio>  // fprintf...
#include <cstring> // strcpy...


#include "sensor.h"


Sensor::Sensor(){

  strcpy(model_, "");
  baud_ = 38400;
  strcpy(port_,"/dev/ttyACM0");
  
  
}


// Sensor::~Sensor(){

//   // destructor
  
// }


void Sensor::setConnectAttributes(char model[], int baud, char port[]){

  // This method, or member function, is required so code not within
  // this class can access member variables safely, without having to
  // understand all our code.
  
  // Initialise all the sensor connection variables.
  //
  strcpy(model_, model);
  baud_ = baud;
  strcpy(port_, port);
  
}

void Sensor::printConnectAttributes(void){
  
  fprintf(stderr, "model_=%s\n", model_);
  fprintf(stderr, "baud_=%d\n", baud_);
  fprintf(stderr, "port_=%s\n", port_);
  
}


// void Sensor::getFixedHdwAttributes(struct fixedHdwAttributes *ptr2fHA){
  
//   // fprintf(stderr, "model_=%s\n", model_);
//   // fprintf(stderr, "baud_=%d\n", baud_);
//   // fprintf(stderr, "port_=%s\n", port_);

//   // just data so can use struct
//   fixedHA_struct{
//     int fov_;             // Field Of View
//     double angularRes_;   // Angular Resplution
//     double scanTime_;     // Time to compleate one scan
//     double distanceMax;   // Maximum Distance
//     double distanceMin;   // Minimum Distance
//   };
//   fixedHA_struct fHA;
  
  
// }
int Sensor::getFixedHdwAttributes(){

  
  return 0;
}



// int Sensor::getArea(void){

//   // Sensor is assumed to be a square in the base class.
  
//   return (width_ * height_);
// }


// int Sensor::getPerimeter(void){
  
//   // Sensor is assumed to be a square in the base class.
  
//   return ((width_*2) + (height_*2));
// }

