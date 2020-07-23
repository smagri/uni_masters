#include <cstdio>
#include <cstring>


// non-system include files
//
#include "sonar.h"
#include "radar.h"
#include "laser.h"
#include "ranger.h"


using namespace std;


//#define DEBUG
//#define MAX_NUM_SAMPLES 10


int main(int argc, char *argv[]){

  char tmpCstr[12]; // temporary c string for conversions of cppString= cString
  string tmpCppStr = "";
  string port;
  int baud;
  int l1numSamples, r1numSamples, s1numSamples;

  
  
  // 1. Initialise the sensors: laser, radar and sonar.
  //
  Laser l1("laser1", 115200, "/dev/ttyACM0");
  Radar r1("radar1", 115200, "/dev/ttyACM1");
  Sonar s1("sonar1", 115200, "/dev/ttyACM2");
  //
  // fprintf(stderr, "Laser:\n");
  // fprintf(stderr, "model=%s\n", l1.model_.c_str());
  // fprintf(stderr, "baud=%d\n", l1.baud_);
  // fprintf(stderr, "baud=%s\n", l1.port_.c_str());
  // fprintf(stderr, "baud=%slf\n", l1.fov_);
  
  
  // 2. Get hardware specific fixed parameters or the sensors.
  //
  fprintf(stderr, "Get Specific Fixed Hardware Parameters:\n");
  //
  fprintf(stderr, "Laser:\n");
  fprintf(stderr, "Field Of View=%f deg\n", l1.getHdwFixedFOV());
  fprintf(stderr, "Minimum Range=%f m\n", l1.getHdwFixedRangeMin());  
  fprintf(stderr, "Maximum Range=%f m\n", l1.getHdwFixedRangeMax());
  //
  fprintf(stderr, "Radar:\n");
  fprintf(stderr, "Field Of View=%f deg\n", r1.getHdwFixedFOV());
  fprintf(stderr, "Minimum Range=%f m\n", r1.getHdwFixedRangeMin());  
  fprintf(stderr, "Maximum Range=%f m\n", r1.getHdwFixedRangeMax());

  fprintf(stderr, "Sonar:\n");
  fprintf(stderr, "Field Of View=%f deg\n", s1.getHdwFixedFOV());
  fprintf(stderr, "Minimum Range=%f m\n", s1.getHdwFixedRangeMin());  
  fprintf(stderr, "Maximum Range=%f m\n", s1.getHdwFixedRangeMax());
  

  // X. Set configurable parameters of the sensors.
  //
  //fprintf(stderr, "Set Configurable Parameters:\n");
  //l1.setConfigResolution(0.5); // 0.5 or 1.0 for laser angular resolution
  // ???roll this into one???


  // 3. Sets sensor parameters specified by the user.
  //
  //
#ifdef DEBUG
  fprintf(stderr, "\nEnter sensor paramters...: "
	  "(if invalid values are entered defaults are used)\n");

  // Perhaps use <cr> to choose defaults???
  //
  //
  fprintf(stdout, "Laser:\n");
  fprintf(stdout, " Serial Port (/dev/ttyACMX where X=0,1,2)?...");
  fscanf(stdin, "%s", tmpCstr);
  port = tmpCstr;
  l1.setConnectnPort(port);
  
  fprintf(stderr, " Baud Rate (115200 or 38400)?...");
  fscanf(stdin, "%d", &baud);
  l1.setConnectnBaud(baud);

  // fprintf(stderr, " Number of samples in raw data vector?...");
  // fscanf(stdin, "%d", &numSamples);
  // l1.setConnectnBaud(numSamples);
  // s1numSamples = numSamples;

  // Need to add configuration of r1 and s1 objects.

  // Also, may need to let user set fov_, rangeMin_ & rangeMax_.
  // Perhaps even the sampling rate???
#endif

  // 4. Continuously calls the RangerFusion class, and obtains the
  // fused data output.

  //fprintf(stderr,"dbg: main.cpp: TERMINATE before while loop,for TESTING.\n");
  //return 0;

  
  // Read the raw data from the sensor.
  //
  vector<double> l1dataVec; // laser raw data vector
  vector<double> r1dataVec; // radar raw data vector
  vector<double> s1dataVec; // sonar raw data vector
  

  // Make  this a  fixed hardware  parameter, user  input parameter  &
  // configurable parameter.???
  int samplingRate = 60;
  
  // Should this be the same for each sensor???
  // And again as for samplingRate.
  int numSamples = MAX_NUM_SAMPLES;
  
  // wrks also:
  // l1.Ranger::readRanger(dataVec, samplingRate, numSamples);
  l1.readRanger(l1dataVec, samplingRate, numSamples);
  r1.readRanger(r1dataVec, samplingRate, numSamples);
  s1.readRanger(s1dataVec, samplingRate, numSamples);


  return 0;
  
}
