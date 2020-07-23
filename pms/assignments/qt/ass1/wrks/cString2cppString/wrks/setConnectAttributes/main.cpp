// system include files
#include <iostream>
#include <cstdio>
#include <cstring>


// non-system  include files
#include "laserRangeFinder.h"
#include "sensor.h"


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


  LaserRangeFinder lrf;

  strcpy(model, "UTM-XXL");
  baud = 115200;
  strcpy(port,"/dev/ttyACM0");

  fprintf(stderr, "\nDefault connection attributes:\n");
  lrf.Sensor::printConnectAttributes();
  
  lrf.Sensor::setConnectAttributes(model, baud, port);
  fprintf(stderr, "\nSet connection attributes:\n");
  fprintf(stderr, "model=%s\n", model);
  fprintf(stderr, "baud=%d\n", baud);
  fprintf(stderr, "port=%s\n", port);
  lrf.Sensor::printConnectAttributes();
    
  // 2. queries the fixed sensor parameters
  //
  // getParam1(), getParam2()...

  
  // 3. set sensor parameters as specified by the user
  //
  // read in sensor parameters from the cmd line with:
  // gets() or scanf(stdin,..., v1, v2,...)
  // setParam1(v1), setParam2(v2)...

  
  // 4. continuously queries and displays data from the sensor with a
  // sample sequence number until the program terminates.
  //
  // Use srand() and rand() here I think.

  
  return 0;
}
