#include <iostream>
#include <cstdio>
#include <cstring>

#include <unistd.h>
#include <fcntl.h>
#include <termios.h>



#include "random.h"
#include "laserRangeFinder.h"
#include "sensor.h"

#define MAX_randNumRay_SIZE 10



using namespace std;



int main(int argc, char *argv[]){

    
  string model;

  
  double fov;
  double distanceMax;
  double distanceMin;

  double angularRes;

  

  int retval;

  double randNumRay[MAX_randNumRay_SIZE];
  int i;
  

  
  model = "UTM-XXL";
  baud = 115200;
  port = "/dev/ttyACM0";


  fprintf(stderr, "Default connection attributes:\n");
  lrf.printConnectAttributes();
 
  fprintf(stderr, "Set connection attributes to:\n");
  fprintf(stderr, "model=%s\n", model.c_str());
  fprintf(stderr, "baud=%d\n", baud);
  fprintf(stderr, "port=%s\n", port.c_str());
  lrf.setConnectAttributes(model, baud, port);
  lrf.printConnectAttributes();
  
  lrf.getFixedHdwAttributes(fov, distanceMax, distanceMin);
  fprintf(stderr, "Get Fixed Hardware Attributes:\n");
  fprintf(stderr, "Field Of View=%f deg\n", fov);
  fprintf(stderr, "Maximum Range=%f m\n", distanceMax);
  fprintf(stderr, "Minimum Range=%f m\n", distanceMin);  
  
  fprintf(stderr, "\nEnter sensor paramter...:\n");
  fprintf(stderr, " Angular Resolution is?...");
  fscanf(stdin, "%lf", &angularRes);
  lrf.setConfigAttributes(angularRes, nad, nad);
  
  
  fprintf(stderr, " Baud Rate is?...");
  fscanf(stdin, "%d", &baud);
  lrf.Sensor::setConnectAttributes(model, baud, port);
  
  fprintf(stdout, " Serial Port is?...");
  fscanf(stdin, "%s", tmpCstr);
  port = tmpCstr;
  
  lrf.Sensor::setConnectAttributes(model, baud, port);
  lrf.Sensor::printConnectAttributes();  

  

  int numberRead = 0;

  

  numRands2gen = 1;
  Random randSensor(seed, numRands2gen);

  while(1){
    lrf.Sensor::readSensor(randNumRay, samplingRate,
			   distanceMin, distanceMax, randSensor);
    fprintf(stderr, "main.cpp: read number %d-"
    	    "Laser Range Finder sensor read random number=%f\n",
    	    numberRead++, randNumRay[0]);
  }

  
  return 0;
}
