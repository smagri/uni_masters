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


#define DEBUG
//#define MAX_NUM_SAMPLES 10


int main(int argc, char *argv[]){

  char tmpCstr[12]; // temporary c string for conversions of cppString= cString
  string tmpCppStr = "";
  string port; // Connection port of sensor
  int baud; // Connetion baud rate of sensor
  int l1numSamples, r1numSamples, s1numSamples;
  double angularRes; // Laser Angular Resolution
  double fov; // sensor Field Of Vew
  string fusionMethod; // raw data processing/fusion method
  
  // 1. Initialise the sensors: laser, radar and sonar.
  //
  // Uses contructors to create objects of class.
  //
  Laser l1("UTM-XXL", 115200, "/dev/ttyACM0");
  Radar r1("RAD-001", 115200, "/dev/ttyACM1");
  Sonar s1("SONX-001", 115200, "/dev/ttyACM2");

  
  
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
  


  // 3. Sets configurable sensor parameters, specified by the user.
  //
  //
#ifdef DEBUG
  fprintf(stderr, "\nEnter sensor paramters...: "
	  "(if invalid values are entered defaults are used)\n\n");

  // Perhaps use <cr> to choose defaults???
  //
  //
  // fprintf(stderr, " Number of samples in raw data vector?...");
  // fscanf(stdin, "%d", &numSamples);
  // l1.setConnectnBaud(numSamples);
  // s1numSamples = numSamples;

  // Also, may need to let user set fov_, rangeMin_ & rangeMax_.
  // Perhaps even the sampling rate???

  
  fprintf(stdout, "Laser: *************************************************\n");

  fprintf(stdout, " Serial Port (/dev/ttyACMX where X=0,1,2)?...");
  fscanf(stdin, "%s", tmpCstr);
  port = tmpCstr;
  l1.setConnectnPort(port);
  
  fprintf(stderr, " Baud Rate (115200 or 38400)?...");
  fscanf(stdin, "%d", &baud);
  l1.setConnectnBaud(baud);

  fprintf(stderr, " Angular Resolution (15deg or 30deg)?...");
  fscanf(stdin, "%lf", &angularRes);
  l1.setConfigAngularRes(angularRes);

  fprintf(stderr, "dbg: Model set to %s\n", l1.getConnectnModel().c_str());
  fprintf(stderr, "dbg: Baud set to %d\n", l1.getConnectnBaud());
  fprintf(stderr, "dbg: Port set to %s\n", l1.getConnectnPort().c_str());
  fprintf(stderr, "dbg: Angular Resolution set to %f degrees\n",
	  l1.getConfigAngularRes());

  
  fprintf(stdout, "Radar: *************************************************\n");

  fprintf(stdout, " Serial Port (/dev/ttyACMX where X=0,1,2)?...");
  fscanf(stdin, "%s", tmpCstr);
  port = tmpCstr;
  r1.setConnectnPort(port);
  
  fprintf(stderr, " Baud Rate (115200 or 38400)?...");
  fscanf(stdin, "%d", &baud);
  r1.setConnectnBaud(baud);

  fprintf(stderr, " Field Of View (20deg or 40deg)?...");
  fscanf(stdin, "%lf", &fov);
  r1.setConfigFOV(fov);
  
  fprintf(stderr, "dbg: Model set to %s\n", r1.getConnectnModel().c_str());
  fprintf(stderr, "dbg: Baud set to %d\n", r1.getConnectnBaud());
  fprintf(stderr, "dbg: Port set to %s\n", r1.getConnectnPort().c_str());
  fprintf(stderr, "dbg: Field Of View is set to %f degrees\n",
	  r1.getHdwFixedFOV());
    
  fprintf(stdout, "Sonar: *************************************************\n");

  fprintf(stdout, " Serial Port (/dev/ttyACMX where X=0,1,2)?...");
  fscanf(stdin, "%s", tmpCstr);
  port = tmpCstr;
  s1.setConnectnPort(port);
  
  fprintf(stderr, " Baud Rate (115200 or 38400)?...");
  fscanf(stdin, "%d", &baud);
  s1.setConnectnBaud(baud);

  fprintf(stderr, "dbg: Model set to %s\n", s1.getConnectnModel().c_str());
  fprintf(stderr, "dbg: Baud set to %d\n", s1.getConnectnBaud());
  fprintf(stderr, "dbg: Port set to %s\n", s1.getConnectnPort().c_str());

  // fprintf(stdout, "Specify Fusion Method, common to all sensors: **********\n");
  // fprintf(stderr, " Fusion Method (min/max/average)?...");
  // fscanf(stdin, "%s", tmpCstr);
  // fusionMethod = tmpCstr;
  // fprintf(stderr, "Fusion Method Chosen=\n");

#endif

  // 4. Continuously calls the RangerFusion class, and obtains the
  // fused data output.

  //fprintf(stderr,"dbg: main: TERMINATE before while loop,for TESTING.\n");
  //return 0;

  
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


  //vector<Ranger *> laserRangers = {&l1}; // add to rangers_
  //vector<Ranger *> radarRangers = {&r1}; // add to rangers_
  //vector<Ranger *> sonarRangers = {&s1}; // add to rangers_
  //
  // vector<vector<double> > rawRangeDataVV = l1.getRawRangeData();

  
  vector<Ranger *> rangers;
  rangers = {&l1, &r1, &s1};
  cout << "main: rangers :" << endl;
  cout << "&l1=" << rangers.at(0) << endl;
  cout << "&r1=" << rangers.at(1) << endl;
  cout << "&s1=" << rangers.at(2) << endl;
     
  RangerFusion rf1("average");
  rf1.setRangers(rangers);

  rf1.getRawRangeData();
  //vector<vector<double> > retVec;
  //retVec = rf1.getRawRangeData();
  //
  // check returned vector
  // for (int m=0; m<rangers.size(); m++){
  //   for (int n=0; n<numSamples; n++){
  //     cout << "dbg: main: rawRangeDataVV[" << m << "]" << "[" << n << "]="
  // 	   << retVec[m][n] <<endl;
  //   }
  //  }
  
  

  // Loop forever until control C recieved from command line.
  //
  //while(1){
  //
  // for loop for testing:
  for (int i=0; i<1; i++){
    
    // Call RangerFusion class to return a fused ranger data vector.
    // vector<double> fusedData = l1.getFusedRangeData();
    //
    vector<double> fusedRangeData = rf1.getFusedRangeData();
    
    for(int i=0; i<fusedRangeData.size(); i++){
      cout << "dbg: main: fusedRangeData(" << i << ")="
     	   << fusedRangeData.at(i) << endl;
    }
  }
  
  return 0;
}
