// Class Implementation
//

#include "sonar.h"
#include "ranger.h"


Sonar::Sonar(string model, int baud, string port){

  // Connection to the sensor variables.
  model_ = model;
  baud_ = baud;
  port_ = port;
  
  // Fixed hardware parameters.
  fov_ = 200;           // Field Of View in degrees
  rangeMin_ = 0.4;   // minimum distance of operation
  rangeMax_ = 10.0;   // maximum distance of operation

  fprintf(stderr, "Sonar class constructor:\n");
  fprintf(stderr, "model_=%s\n", model_.c_str());
  fprintf(stderr, "baud_=%d\n", baud_);
  fprintf(stderr, "port_=%s\n", port_.c_str());
  fprintf(stderr, "fov_=%lf\n", fov_);
}


// Sonar::~Sonar(){
// }
