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

  if ( (baud != 38400) && (baud != 115200) ){
    fprintf(stderr,
	    " Error: Invalid baud rate entered, 38400 or 115200 valid,");
    fprintf(stderr, " defaulting to 38400.\n");
    baud_ = 38400;
    //errBaud = 1;
  }

  if( (strcmp("/dev/ttyACM0", port) != 0)
      && (strcmp("/dev/ttyACM1", port) != 0) ){
    fprintf(stderr, " Error: Invalid serial port name entered,");
    fprintf(stderr, " defaulting to /dev/ttyACM0.\n");
    strcpy(port_, "/dev/ttyACM0");
    //errBaud = 1;
  }

}

void Sensor::printConnectAttributes(void){

  fprintf(stderr, "\ndbg: in Sensor::printConnectAttributes\n");
  
  fprintf(stderr, "model_=%s\n", model_);
  fprintf(stderr, "baud_=%d\n", baud_);
  fprintf(stderr, "port_=%s\n", port_);
  
}


//wrks:
// int Sensor::getFixedHdwAttributes(void){

  
//   return 0;
// }

// int Sensor::getFixedHdwAttributes(struct fixedAtt &refFixedHA){
  
//   refFixedHA.fov = fov_;
//   refFixedHA.distanceMax = distanceMax_;
//   refFixedHA.distanceMin = distanceMin_;
  
//   return 0;
// }
int Sensor::getFixedHdwAttributes(double &att1, double &att2, double &att3){
  
  //att1 = fov_;
  //att2 = distanceMax_;
  //att3 = distanceMin_;
  fprintf(stderr, "dbg: in Sensor::getFixedHdwAttributes\n");
  
  return 0;
}

int Sensor::setConfigAttributes(double &att1, double &att2, double &att3){
  
  fprintf(stderr, "in Sensor::setConfigAttributes\n");
  
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

