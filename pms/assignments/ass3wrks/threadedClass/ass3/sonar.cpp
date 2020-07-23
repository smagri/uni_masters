//
// Sonar Class Implementation.
//
#include <stdio.h>

#include "sonar.h"


Sonar::Sonar(string model, int baud, string port){

  /// Sonar object constructor.
  
  /// Set connection to sensor variables.
  model_ = model;
  baud_ = baud;
  port_ = port;
  
  /// Set Fixed Hardware parameters.
  fov_ = 90;         // Field Of View in degrees
  rangeMin_ = 0.2;   // minimum distance of operation
  rangeMax_ = 6.0;   // maximum distance of operation

  numSamples_ = 1;   // number of samples the sensor produces

  sensorRes_ = 1;    // sampling resolution

  samplingRate_ = 3; // sampling rate in Hz
  
  fprintf(stderr, "\nSonar class constructor:\n");
  fprintf(stderr, "model_=%s\n", model_.c_str());
  fprintf(stderr, "baud_=%d\n", baud_);
  fprintf(stderr, "port_=%s\n", port_.c_str());

  fprintf(stderr, "numSamples_=%d\n", numSamples_);
  fprintf(stderr, "samplingRate_=%d Hz\n", samplingRate_);
    
  fprintf(stderr, "fov_=%lf\n", fov_);
  fprintf(stderr, "rangeMin_=%lf\n", rangeMin_);
  fprintf(stderr, "rangeMax_=%lf\n", rangeMax_); 

}


void Sonar::setConfigFOV(double fov){

  /// Configure/Set radar Field of View, configurable attribute.
  
  fov_ = fov;
  
}

// void Sonar::setConfigFOV(void){

//   //fov_ = fov;
  
// }
// Sonar::~Sonar(){
// }
