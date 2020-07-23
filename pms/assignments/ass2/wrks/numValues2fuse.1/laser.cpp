//
// Laser Class Implementation.
//
#include <string>
#include <cstring>


#include "laser.h"
#include "ranger.h"


Laser::Laser(string model, int baud, string port){

  // Laser object constructor.
  
  // Connection related sensor variables.
  model_ = model;
  baud_ = baud;
  port_ = port;

  // Fixed hardware parameters.
  fov_ = 180;        // Field Of View in degrees
  rangeMin_ = 0.2;   // minimum distance of operation
  rangeMax_ = 8.0;   // maximum distance of operation
  
  angularRes_ = 30.0;

  numSamples_ = (fov_/angularRes_) + 1;
  
  fprintf(stderr, "Laser class constructor:\n");
  fprintf(stderr, "model_=%s\n", model_.c_str());
  fprintf(stderr, "baud_=%d\n", baud_);
  fprintf(stderr, "port_=%s\n", port_.c_str());

  fprintf(stderr, "numSamples_=%d\n", numSamples_);
  
  fprintf(stderr, "fov_=%lf\n", fov_);
  fprintf(stderr, "rangeMin_=%lf\n", rangeMin_);
  fprintf(stderr, "rangeMax_=%lf\n", rangeMax_);


}

// Laser::~Laser(){
// }

int Laser::setConfigAngularRes(double angularRes){

  // Configure/Set laser angular resolution, a configurable attribute.
  
  if ( (angularRes == 15) || (angularRes == 30) ){
    // Valid Angular Resolution entered by user.
    angularRes_ = angularRes;
  }
  else{
    // Ivalid Angular Resolution entered by user, output error message.
    fprintf(stderr,
            " Error: Invalid Angular Resolution entered,"
            " 15deg & 30deg valid,");
    fprintf(stderr, " defaulting to 30deg\n");
    //fprintf(stderr, "        so Scan Time is 50ms.\n");
    angularRes_ = 30; // default angular resolution
  }

  //fprintf(stderr, "dbg: angularRes_=%fdeg\n", angularRes_);
  //scanTime_;   // 25ms or 50ms allowed, derived from angular resoltion
  
  return 0;
}

double Laser::getConfigAngularRes(void){

  return angularRes_;
}
