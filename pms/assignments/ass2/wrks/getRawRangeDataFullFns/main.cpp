#include <iostream>
#include <cstdio>
#include <cstring>


// non-system include files
//
#include "rangerFusion.h"
#include "RangerFusionInterface.h"
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
  // l1.readRanger(l1dataVec, samplingRate, numSamples);
  // r1.readRanger(r1dataVec, samplingRate, numSamples);
  // s1.readRanger(s1dataVec, samplingRate, numSamples);


  vector<Ranger *> rangers;
  rangers = {&l1, &r1, &s1};
  cout << "main.cpp: rangers :" << endl;
  cout << "&l1=" << rangers.at(0) << endl;
  cout << "&r1=" << rangers.at(1) << endl;
  cout << "&s1=" << rangers.at(2) << endl;
  
  // wrks: l1.Laser::RangerFusion::setRangers(rangers);
  l1.setRangers(rangers);
  //r1.setRangers(rangers);
  //s1.setRangers(rangers);

  vector<vector<double> > rawRangeDataVV = l1.getRawRangeData();
  // check output
  for (int m=0; m<rangers.size(); m++){
    for (int n=0; n<numSamples; n++){
      cout << "dbg: main: rawRangeDataVV[" << m << "]" << "[" << n << "]="
	   << rawRangeDataVV[m][n] <<endl;
    }
  }
 
  //RangerFusion rf1("min");
  //rf1.getRawRangeData();
    


  // Loop forever until control C recieved from command line.
  //
  //while(1){
  //
  // for loop for testing:
  for (int i=0; i<5; i++){
    
    // Call RangerFusion class to return a fused ranger data vector.
    vector<double> fusedData = l1.getFusedRangeData();
    
    // for(int i=0; i<fusedData.size(); i++){
    //   cout << "dbg: fusedData(" << i << ")=" << fusedData.at(i) << endl;
    // }
  }
    //}
  
   return 0;
}
