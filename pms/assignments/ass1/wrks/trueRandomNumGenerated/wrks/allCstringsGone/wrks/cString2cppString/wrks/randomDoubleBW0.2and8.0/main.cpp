// system include files
#include <iostream>
#include <cstdio>
#include <cstring>

// system include files, read serial port
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>



// non-system  include files
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
  char model[10];      // model name
  int baud;            // baud rate
  char port[12];      // usb port sensor is connected to /dev/ttyACMx

  // Laser Range Finder Fixed Attributes
  double fov;
  double distanceMax;
  double distanceMin;

  double angularRes;
  //double scanTime;

  int samplingRate = 60; // need to put in sensor.h private member data?
  
  double nad = 0.0; // non-applicable double value, argument not used

  int retval;

  // array containg random numbers, returned by Sensor::readSensor()
  //int randNumRay[MAX_randNumRay_SIZE];
  double randNumRay[MAX_randNumRay_SIZE];
  int i;

  samplingRate; // Sensor Sampling Rate

  LaserRangeFinder lrf; // default constructor(ie no params or retrun value)
  
  
  strcpy(model, "UTM-XXL");
  baud = 115200;
  strcpy(port,"/dev/ttyACM0");

  fprintf(stderr, "\nDefault connection attributes:\n");
  lrf.Sensor::printConnectAttributes();
  //lrf.printConnectAttributes();
  
  lrf.Sensor::setConnectAttributes(model, baud, port);
  fprintf(stderr, "\nSet connection attributes:\n");
  fprintf(stderr, "model=%s\n", model);
  fprintf(stderr, "baud=%d\n", baud);
  fprintf(stderr, "port=%s\n", port);
  lrf.Sensor::printConnectAttributes();
    
  // 2. queries the fixed sensor parameters
  //
  lrf.getFixedHdwAttributes(fov, distanceMax, distanceMin);
  fprintf(stderr, "\nGet Fixed Hardware Attributes:\n");
  //cout << "fov=" << fov << endl;
  fprintf(stderr, "Field Of View=%f deg\n", fov);
  fprintf(stderr, "Maximum Range=%f m\n", distanceMax);
  fprintf(stderr, "Minimum Range=%f m\n", distanceMin);  
  
  // 3. set sensor parameters as specified by the user
  //
  fprintf(stderr, "\nEnter sensor paramter...:\n");
  //fscanf(stdin, "%d", &baud);
  //fprintf(stderr, "Print this sensor paramter, %d\n", baud);
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
  fscanf(stdin, "%s", port);
  lrf.Sensor::setConnectAttributes(model, baud, port);
  lrf.Sensor::printConnectAttributes();  

  
//  lrf.Sensor::setConnectAttributes(model, baud, port);
//  lrf.Sensor::printConnectAttributes();  
//  lrf.setConfigAttributes(angularRes, scanTime, nad);
  
  
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
  double num;
  
  // Loop forever until cntrl C recieved from command line.
  while(1){
    lrf.Sensor::readSensor(randNumRay, samplingRate);
    fprintf(stderr, "main.cpp: read number %d-"
    	    "Laser Range Finder sensor read random number=%f\n",
    	    numberRead++, randNumRay[0]);
    // num = lrf.Sensor::readSensor(randNumRay, samplingRate);
    // fprintf(stderr, "main.cpp: read number %d-"
    //  	    "Laser Range Finder sensor read random number=%d\n",
    // 	    numberRead++, num);
  }

  
  return 0;
}
