//
// Sensor base class implementation.
//
// 
// Class functions or methods(aka member functions) are defined here.
//


//#include <iostream>
#include <cstdio>  // fprintf...
#include <cstring> // strcpy...
#include <unistd.h>

#include "sensor.h"
#include "random.h"



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


int Sensor::readSensor(double randNumRay[], int samplingRate){
  
//  fprintf(stderr, "dbg: in Sensor::readSensor\n");

  unsigned int seed = time(NULL);
  int numRands2gen = 1;

  // Normally here you would open the sensor/device and read().
  //
  // And really this is a bit of a fudge, it's not guarantied exactly
  // 1/60s wait, could be longer, depends on context switch.
  //
  //sleep/block for 1/sampleRate;
  //
  // 1 / samplingRate = 1/60 = 0.0166667s = 16667 uS
  //usleep((1/samplingRate) * 1000000);
  usleep((1/samplingRate) * 10^6);
  
  Random randNum(seed, numRands2gen);
  randNum.genRandNum(randNumRay);

//fprintf(stderr, "sensor.cpp: seed=%d\n", seed);
//fprintf(stderr,"dbg: in Sensor::readSensor: random num=%d\n", randNumRay[0]);   

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
