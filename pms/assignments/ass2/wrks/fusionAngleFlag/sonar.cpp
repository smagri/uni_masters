//
// Sonar Class Implementation.
//

#include "sonar.h"
#include "ranger.h"


Sonar::Sonar(string model, int baud, string port){

  // Sonar object constructor.
  
  // Connection related sensor variables.
  model_ = model;
  baud_ = baud;
  port_ = port;
  
  // Fixed hardware parameters.
  fov_ = 90;         // Field Of View in degrees
  rangeMin_ = 0.2;   // minimum distance of operation
  rangeMax_ = 4.0;   // maximum distance of operation

  numSamples_ = 1;
  
  fprintf(stderr, "Sonar class constructor:\n");
  fprintf(stderr, "model_=%s\n", model_.c_str());
  fprintf(stderr, "baud_=%d\n", baud_);
  fprintf(stderr, "port_=%s\n", port_.c_str());

  fprintf(stderr, "numSamples_=%d\n", numSamples_);
  
  fprintf(stderr, "fov_=%lf\n", fov_);
  fprintf(stderr, "rangeMin_=%lf\n", rangeMin_);
  fprintf(stderr, "rangeMax_=%lf\n", rangeMax_); 

}


// Sonar::~Sonar(){
// }
