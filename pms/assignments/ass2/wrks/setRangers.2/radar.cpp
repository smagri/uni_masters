// Class Implementation
//

#include "radar.h"
#include "ranger.h"



Radar::Radar(string model, int baud, string port){

  // Connection to the sensor variables.
  model_ = model;
  baud_ = baud;
  port_ = port;

  // Fixed hardware parameters
  fov_ = 190;           // Field Of View in degrees
  rangeMin_ = 0.3;   // minimum distance of operation
  rangeMax_ = 9.0;   // maximum distance of operation

  fprintf(stderr, "Radar class constructor:\n");
  fprintf(stderr, "model_=%s\n", model_.c_str());
  fprintf(stderr, "baud_=%d\n", baud_);
  fprintf(stderr, "port_=%s\n", port_.c_str());

  fprintf(stderr, "fov_=%lf\n", fov_);
  fprintf(stderr, "rangeMin_=%lf\n", rangeMin_);
  fprintf(stderr, "rangeMax_=%lf\n", rangeMax_); 
  
}

// Radar::~Radar(){
// }
