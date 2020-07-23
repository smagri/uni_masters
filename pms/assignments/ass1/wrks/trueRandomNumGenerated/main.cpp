// system include files
#include <iostream>
#include <cstdio>
#include <cstring>

// system include files, read serial port
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>



// non-system  include files
#include "random.h"
#include "laserRangeFinder.h"
#include "sensor.h"

#define MAX_randNumRay_SIZE 10



// So you can refer to std class member function just by their name,
// thus with no std:: prefix
using namespace std;



int main(int argc, char *argv[]){

    
  // 1. initialise the sensor
  //
  // Use 'new' here to dynamically allocate memory on the heap ??
  string model;
  int baud;    // baud rate
  string port; // usb port sensor is connected to /dev/ttyACMx

  char tmpCstr[12]; // temporary c string for conversions of cppString= cString
  
  // Laser Range Finder Fixed Attributes
  double fov;
  double distanceMax;
  double distanceMin;

  double angularRes;
  //double scanTime;

  int samplingRate = 60;  // Sensor Sampling Rate need to put in
			  // sensor.h private member data?
  
  double nad = 0.0; // non-applicable double value, argument not used

  int retval;

  // array containg random numbers, returned by Sensor::readSensor()
  double randNumRay[MAX_randNumRay_SIZE];
  unsigned int seed; // seed for random number generator rand()
  int numRands2gen;  // number of random numbers to generate
  int i;
  

  LaserRangeFinder lrf; // default constructor(ie no params or retrun value)
  
  model = "UTM-XXL";
  baud = 115200;
  port = "/dev/ttyACM0";

  fprintf(stderr, "Default connection attributes:\n");
  lrf.Sensor::printConnectAttributes();
  //lrf.printConnectAttributes();
  
  lrf.Sensor::setConnectAttributes(model, baud, port);
  fprintf(stderr, "\nSet connection attributes:\n");
  fprintf(stderr, "model=%s\n", model.c_str());
  fprintf(stderr, "baud=%d\n", baud);
  fprintf(stderr, "port=%s\n", port.c_str());
  lrf.Sensor::printConnectAttributes();
    
  // 2. queries the fixed sensor parameters
  //
  lrf.getFixedHdwAttributes(fov, distanceMax, distanceMin);
  fprintf(stderr, "Get Fixed Hardware Attributes:\n");
  fprintf(stderr, "Field Of View=%f deg\n", fov);
  fprintf(stderr, "Maximum Range=%f m\n", distanceMax);
  fprintf(stderr, "Minimum Range=%f m\n", distanceMin);  
  
  // 3. set sensor parameters as specified by the user
  //
  fprintf(stderr, "\nEnter sensor paramter...:\n");
  fprintf(stderr, " Angular Resolution is?...");
  fscanf(stdin, "%lf", &angularRes);
  lrf.setConfigAttributes(angularRes, nad, nad);
  
  // fprintf(stderr, " Scanning Time is?...");
  // fscanf(stdin, "%lf", &scanTime);
  // fprintf(stderr, " invalid scanning time, defaulting to 50ms\n");
  
  fprintf(stderr, " Baud Rate is?...");
  fscanf(stdin, "%d", &baud);
  lrf.Sensor::setConnectAttributes(model, baud, port);
  
  fprintf(stdout, " Serial Port is?...");
  fscanf(stdin, "%s", tmpCstr);
  port = tmpCstr;
  // !wrks: getline(cin, port);
  // wrks: cin >> port;
  // wrks: cout << port << endl;
  
  lrf.Sensor::setConnectAttributes(model, baud, port);
  lrf.Sensor::printConnectAttributes();  

  
  // 4. continuously queries and displays data from the sensor with a
  // sample sequence number until the program terminates.
  //
  // Use srand() and rand() here I think.
  //
  //
  // Create instance of class random, called rand, also,
  // initialiase private member data.
  //
  // Seed is  initialised to  a distinctive  runtime value,  ie return
  // value  of time(),  this gives  random-like numbers.   ie seed  is
  // initialised to  a value representing the  current time(or program
  // calling time).

  int numberRead = 0;
  //double num;

//  fprintf(stderr,"dbg: main.cpp: TERMINATE before while loop,for TESTING.\n");
//  return 0;
  
  // Loop forever until cntrl C recieved from command line.

  // Setup random number generation seed and object.
  seed = time(NULL); // current time in seconds since epoch/UTC
  numRands2gen = 1;
  Random randSensor(seed, numRands2gen);

  // Initialise random seed for sucessive calls to rand().
  while(1){
    lrf.Sensor::readSensor(randNumRay, samplingRate,
			   distanceMin, distanceMax, randSensor);
    fprintf(stderr, "main.cpp: read number %d-"
    	    "Laser Range Finder sensor read random number=%f\n",
    	    numberRead++, randNumRay[0]);
  }

  
  return 0;
}
