//
// Radar Class Implementation
//

#include "radar.h"
#include "ranger.h"



Radar::Radar(string model, int baud, string port){

  // Radar object constructor.
  
  // Connection to the sensor variables.
  model_ = model;
  baud_ = baud;
  port_ = port;

  // Fixed hardware parameters
  fov_ = 20;         // Field Of View in degrees, 20deg or 40deg, user decides
  rangeMin_ = 0.2;   // minimum distance of operation
  rangeMax_ = 16.0;  // maximum distance of operation

  numSamples_ = 1;

  sensorRes_ = 1; 
  
  fprintf(stderr, "Radar class constructor:\n");
  fprintf(stderr, "model_=%s\n", model_.c_str());
  fprintf(stderr, "baud_=%d\n", baud_);
  fprintf(stderr, "port_=%s\n", port_.c_str());

  fprintf(stderr, "numSamples_=%d\n", numSamples_);
  
  fprintf(stderr, "fov_=%lf\n", fov_);
  fprintf(stderr, "rangeMin_=%lf\n", rangeMin_);
  fprintf(stderr, "rangeMax_=%lf\n", rangeMax_); 
  
}

// Radar::~Radar(){
// }

void Radar::setConfigFOV(double fov){

   // Configure/Set radar Field of View, configurable attribute.

  if ( (fov == 20) || (fov == 40) ){
    // Valid FOV entered by user.
    fov_ = fov;
  }
  else{
    // Ivalid FOV entered by user, output error message.
    fprintf(stderr,
            " Error: Invalid Field Of View,"
            " 20deg & 40deg valid,");
    fprintf(stderr, " defaulting to 15deg\n");
    //fprintf(stderr, "        so Scan Time is 50ms.\n");
    fov_ = 20; // default radar FOV
  }
 
}

// void Radar::getConfigFOV(double fov){

//   return fov_;
// }

