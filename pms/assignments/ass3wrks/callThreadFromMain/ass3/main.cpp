#include <iostream>
#include <cstdio>
#include <cstring>
#include <thread>
#include <mutex>
#include <vector>

// non-system include files
//
#include "dataFusion.h"
#include "sonar.h"
#include "radar.h"
#include "ranger.h"


using namespace std;

//extern void fillBuffer();


int main(int argc, char *argv[]){

  char tmpCstr[12]; // temporary c string for conversions of cppString= cString
  string tmpCppStr = "";
  string port; // Connection port of sensor
  int baud; // Connetion baud rate of sensor
  double angularRes; // Laser Angular Resolution
  double fov; // sensor Field Of Vew
  string fusionMethod; // raw data processing/fusion method
  int numSamples;
    
  // 1. Initialise the sensors: radar and sonar.
  //
  // Uses contructors to create objects of class.
  //
  Radar r1("RAD-001", 115200, "/dev/ttyACM1");
  Sonar s1("SONX-001", 115200, "/dev/ttyACM2");


  // Instantiate DataFusion class, create object called df1, for use
  // later.
  //
  DataFusion df1;
    

  // Testing PURE  virtual fn in  ranger.h.  This works, that  is, can
  // _not_ instansiate this  object, only if at least  one function in
  // ranger.h is virtual fnName() = 0;
  //
  //Ranger rangerObj;

  
  // 2. Get hardware specific fixed parameters or the sensors.
  //
  fprintf(stderr, "\nGet Specific Fixed Hardware Parameters:\n");
  //
  fprintf(stderr, "\nRadar:\n");
  fprintf(stderr, "Field Of View=%f deg\n", r1.getHdwFixedFOV());
  fprintf(stderr, "Minimum Range=%f m\n", r1.getHdwFixedRangeMin());  
  fprintf(stderr, "Maximum Range=%f m\n", r1.getHdwFixedRangeMax());

  fprintf(stderr, "\nSonar:\n");
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

  fprintf(stdout, "Radar: *************************************************");
  fprintf(stdout, "**********************************\n");

  fprintf(stderr, "\n"); // for readability
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
  
  fprintf(stderr, "\ndbg: Model set to %s\n", r1.getConnectnModel().c_str());
  fprintf(stderr, "dbg: Baud set to %d\n", r1.getConnectnBaud());
  fprintf(stderr, "dbg: Port set to %s\n", r1.getConnectnPort().c_str());
  fprintf(stderr, "dbg: Field Of View is set to %f degrees\n",
	  r1.getHdwFixedFOV());
  fprintf(stderr, "\n");
  
  fprintf(stdout, "Sonar: *************************************************");
  fprintf(stdout, "**********************************\n");

  fprintf(stderr, "\n");
  fprintf(stdout, " Serial Port (/dev/ttyACMX where X=0,1,2)?...");
  fscanf(stdin, "%s", tmpCstr);
  port = tmpCstr;
  s1.setConnectnPort(port);
  
  fprintf(stderr, " Baud Rate (115200 or 38400)?...");
  fscanf(stdin, "%d", &baud);
  s1.setConnectnBaud(baud);

  fprintf(stderr, "\ndbg: Model set to %s\n", s1.getConnectnModel().c_str());
  fprintf(stderr, "dbg: Baud set to %d\n", s1.getConnectnBaud());
  fprintf(stderr, "dbg: Port set to %s\n", s1.getConnectnPort().c_str());
  fprintf(stderr, "\n");


  fprintf(stdout, "Specify Fusion Method, common to all sensors: **********");
  fprintf(stdout, "**********************************\n");
  
  fprintf(stderr, "\n");
  fprintf(stderr, " Fusion Method (min/max/avg)?...");
  fscanf(stdin, "%s", tmpCstr);
  fusionMethod = tmpCstr;
  df1.setFusionMethod(fusionMethod);

#endif

  // 4. Continuously calls the DataFusion class, and obtains the
  // fused data output.

  vector<Ranger *> rangers;
  rangers = {&r1, &s1};

  cout << endl;
  cout << "dbg: main: rangers :" << endl;
  cout << "dbg: main: &r1=" << rangers.at(0) << endl;
  cout << "dbg: main: &s1=" << rangers.at(1) << endl;

  df1.setRangers(rangers);

  
  // Threaded sensor/ranger data processing.
  //
  
  // Start all the threads
  //
  //thread df1.fillBuffer0Thread(fillBuffer, ref(dataBuff), 0, ref(df1));
  //thread df1.fillBuffer1Thread(fillBuffer, ref(dataBuff), 1, ref(df1));
  //thread df1.processBufferThread(processBuffer, ref(dataBuff), ref(df1));
  //thread fillBiffer0Thread(df1.fillBuffer, ref(df1.dataBuff0), 0);
  //std::thread fillBufferThread(fillBuffer);
  //thread df1.fillBuffer0Thread(df1.fillBuffer);
  thread fillBuffer0Thread();
  

  // Syncronise threads,  that is, wait  for _all_ threads  to finish,
  // they wont in this case though  as the threads have infinate loops
  // in them.
  //fillBuffer0Thread.join();
  //df1.fillBuffer1Thread.join();
  //df1.processBufferThread.join();
  

  // Loop forever until control C recieved from command line.
  //
  //while(1){
  //
  // for loop for testing:
  for (int i=0; i<1; i++){
    
    // Call RangerFusion class to return a fused ranger data vector.
    // vector<double> fusedData = l1.getFusedRangeData();
    //
    //vector<double> fusedRangeData = df1.getFusedRangeData();
    
    // for(int i=0; i<fusedRangeData.size(); i++){
    //   cout << "dbg: main: fusedRangeData(" << i << ")="
    //  	   << fusedRangeData.at(i) << endl;
    // }
  }
  
  return 0;
}
