//
// Base Ranger class called Ranger.
//
// Class implementation.  That is, class member fns or methods.
//
//
#include <cstdio>
#include <string>


#include "random.h"
#include "ranger.h"


Ranger::Ranger(){

  // should this be blank?
  model_ = "model";
  baud_ = 38400;
  port_ = "/dev/ttyACM0";

  double fov_ = 180;
  double distanceMax = 8.0;
  double distanceMin = 0.2;
  
}


// Connecting to the Sensor:
//
void Ranger::setConnectnModel(string model){
  
  model_ = model;
  
}

void Ranger::setConnectnBaud(int baud){

  baud_ = baud;

  if ( (baud != 38400) && (baud != 115200) ){
    fprintf(stderr,
	    " Error: Invalid baud rate entered, 38400 or 115200 valid,");
    fprintf(stderr, " defaulting to 38400.\n");
    baud_ = 38400; // set default baud_ value
  }
  else{
    baud_ = baud;
  }
  
  fprintf(stderr, "dbg: baud_=%d\n", baud_);
}

void Ranger::setConnectnPort(string port){

  // Probably need to make this more modular, to accept more integers(?)
  // for /dev/ttyACM?.
  
  if( (port != "/dev/ttyACM0") && (port != "/dev/ttyACM1")
      && (port != "/dev/ttyACM2") ){
    
    fprintf(stderr, " Error: Invalid serial port name entered,");
    fprintf(stderr, " defaulting to /dev/ttyACM0.\n");

    port_ = "/dev/ttyACM0"; // set default port_ value

  }
  else{
    port_ = port;
  }

  fprintf(stderr, "dbg: port_=%s\n", port_.c_str());

  return;
  
}



// Get hardware specific fixed parameters of the sensor:
//
double Ranger::getHdwFixedFOV(void){

  return fov_;
}

double Ranger::getHdwFixedRangeMin(void){

  return rangeMin_;
}

double Ranger::getHdwFixedRangeMax(void){
  
  return rangeMax_;
}



// Set hardware specific fixed parameters of the sensor:
//
void Ranger::setConfigResolution(double resolution){

  if ( (resolution == 0.5) || (resolution == 1.0) ){
    // Valid Angular Resolution entered by user.
    resolution_ = resolution;
  }
  else{
    // Ivalid Angular Resolution entered by user, output error message.
    fprintf(stderr,
            " Error: Invalid Angular Resolution entered,"
            " 0.5deg & 1.0deg valid,");
    fprintf(stderr, " defaulting to 0.5deg,\n");
    fprintf(stderr, "        so Scan Time is 50ms.\n");
    resolution_ = 0.5;
  }
  
  
  // resolution_ = resolution;

  fprintf(stderr, "dbg: sensor resoution = %lf\n", resolution_);
}


// int Ranger::readRanger(double randNumRay[], int samplingRate,
//                        double fMin, double fMax, Random &randRanger){
  
//   //  fprintf(stderr, "dbg: in Ranger::readRanger\n");

//   // Normally here you would open the sensor/device and read().
//   //
//   // And really this is a bit of a fudge, it's not guarantied exactly
//   // 1/60s wait, could be longer, depends on context switch.
//   //
//   //sleep/block for 1/sampleRate;
//   //
//   // 1 / samplingRate = 1/60 = 0.0166667s = 16667 uS
//   // usleep((1/samplingRate) * 1000000);
//   usleep((1/samplingRate) * 10^6);

//   // Generate a random number for the readRanger object.
//   randRanger.genRandNum(randNumRay, fMin, fMax);

// //fprintf(stderr, "sensor.cpp: seed=%d\n", seed);
// //fprintf(stderr,"dbg: in Ranger::readRanger: random num=%d\n", randNumRay[0]);   

//   return 0;
  
// }
