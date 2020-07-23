// Class Implementation
//
#include <string>
#include <cstring>


#include "laser.h"
#include "ranger.h"


Laser::Laser(string model, int baud, string port){

  // Connection to the sensor variables.
  model_ = model;
  baud_ = baud;
  port_ = port;

  // Fixed hardware parameters.
  fov_ = 180;           // Field Of View in degrees
  rangeMin_ = 0.2;   // minimum distance of operation
  rangeMax_ = 8.0;   // maximum distance of operation
  

  fprintf(stderr, "Laser class constructor:\n");
  fprintf(stderr, "model_=%s\n", model_.c_str());
  fprintf(stderr, "baud_=%d\n", baud_);
  fprintf(stderr, "port_=%s\n", port_.c_str());
  fprintf(stderr, "fov_=%lf\n", fov_);

}

// Laser::~Laser(){
// }
