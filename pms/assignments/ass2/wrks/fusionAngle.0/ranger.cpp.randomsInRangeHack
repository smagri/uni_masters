//
// Base Ranger class called Ranger.
//
// Class implementation.  That is, class member fns or methods.
//
//
#include <iostream>
#include <chrono>
#include <vector>
#include <random>
#include <cstdio>
#include <string>


#include "random.h"
#include "ranger.h"


Ranger::Ranger(){

  // should this be blank?
  model_ = "model";
  baud_ = 38400;
  port_ = "/dev/ttyACM0";

  double fov_ = 180;
  double distanceMax = 8.0;
  double distanceMin = 0.2;
  
}


// Connecting to the Sensor:
//
void Ranger::setConnectnModel(string model){
  
  model_ = model;
  
}

void Ranger::setConnectnBaud(int baud){

  baud_ = baud;

  if ( (baud != 38400) && (baud != 115200) ){
    fprintf(stderr,
	    " Error: Invalid baud rate entered, 38400 or 115200 valid,");
    fprintf(stderr, " defaulting to 38400.\n");
    baud_ = 38400; // set default baud_ value
  }
  else{
    baud_ = baud;
  }
  
  fprintf(stderr, "dbg: baud_=%d\n", baud_);
}

void Ranger::setConnectnPort(string port){

  // Probably need to make this more modular, to accept more integers(?)
  // for /dev/ttyACM?.
  
  if( (port != "/dev/ttyACM0") && (port != "/dev/ttyACM1")
      && (port != "/dev/ttyACM2") ){
    
    fprintf(stderr, " Error: Invalid serial port name entered,");
    fprintf(stderr, " defaulting to /dev/ttyACM0.\n");

    port_ = "/dev/ttyACM0"; // set default port_ value

  }
  else{
    port_ = port;
  }

  fprintf(stderr, "dbg: port_=%s\n", port_.c_str());

  return;
  
}



// Get hardware specific fixed parameters of the sensor:
//
double Ranger::getHdwFixedFOV(void){

  return fov_;
}

double Ranger::getHdwFixedRangeMin(void){

  return rangeMin_;
}

double Ranger::getHdwFixedRangeMax(void){
  
  return rangeMax_;
}



// Set hardware specific fixed parameters of the sensor:
//
void Ranger::setConfigResolution(double resolution){

  if ( (resolution == 0.5) || (resolution == 1.0) ){
    // Valid Angular Resolution entered by user.
    resolution_ = resolution;
  }
  else{
    // Ivalid Angular Resolution entered by user, output error message.
    fprintf(stderr,
            " Error: Invalid Angular Resolution entered,"
            " 0.5deg & 1.0deg valid,");
    fprintf(stderr, " defaulting to 0.5deg,\n");
    fprintf(stderr, "        so Scan Time is 50ms.\n");
    resolution_ = 0.5;
  }
  
  
  // resolution_ = resolution;

  fprintf(stderr, "dbg: sensor resoution = %lf\n", resolution_);
}


int Ranger::readRanger(vector<double> &dataVec,
		       int samplingRate, int numSamples){

  

  double sensorRangeMin, sensorRangeMax;
  double curRandomNum; // current random number from distribution
  
  
  // Normally here you would open the sensor/device and read().
  //
  // And really this is a bit of a fudge, it's not guarantied exactly
  // 1/60s wait, could be longer, depends on context switch.
  //
  // So we sleep/block here for 1/sampleRate seconds.
  //
  // 1/samplingRate=1/60=0.0166667s=16667 uS
  //
  usleep((1/samplingRate) * 10^6);

  // Generate a random number for the readRanger object.
  //randRanger.genRandNum(randNumRay, fMin, fMax);
  
  // Generate  a  random value  from  a  normal distribution.   Normal
  // distribution is  aka gaussian distribution.  Note  that these are
  // pseudo-random numbers.

  // Generate  time-based  seed  for  the  random  number  algorithim.
  // Initialise random numer generator with seed.
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::default_random_engine generator (seed);

  // Normal/Gaussian distributions, which has mean=6 and std deviation=5.
  //
  std::normal_distribution<double> distributionGaussian(6.0, 5.0);

  // Need to scale these random values with sensor range/resolution.
  sensorRangeMin = getHdwFixedRangeMin();
  sensorRangeMax = getHdwFixedRangeMax();
  //
  fprintf(stderr, "dbg: sensorRangeMin=%f\n", sensorRangeMin);
  fprintf(stderr, "dbg: sensorRangeMax=%f\n", sensorRangeMax);
    
  // Fill data vector with random numbers.
//  for (int i=0; i<numSamples; i++){
  //for (int i=0; i<100; i++){
    //curRandomNum =
    //( distributionGaussian(generator) / distributionGaussian.max() );
//    double num =
//     ( distributionGaussian(generator) / (generator.max() - generator.min()));
//    double num =
//      ( distributionGaussian(generator) 
//      / (distributionGaussian.max() - distributionGaussian.min()) );
//    curRandomNum = distributionGaussian(generator);
//    curRandomNum = distributionGaussian(generator);
//    fprintf(stderr, "dbg: curRandomNum Unscaled=%.18f\n", curRandomNum);
//    fprintf(stderr, "dbg: curRandomNum Unscaled=%.18f\n", num);
    
//    curRandomNum = sensorRangeMin
    //    + (curRandomNum * (sensorRangeMax - sensorRangeMin));
    //fprintf(stderr, "dbg: curRandomNum Scaled(to sensor resoltn)=%.18f\n",
//	    curRandomNum);
//    curRandomNum = sensorRangeMin + (num * (sensorRangeMax - sensorRangeMin));
//    fprintf(stderr, "dbg: curRandomNum Scaled(to sensor resoltn)=%.18f\n",
//	    curRandomNum);

  int i=0;
  int j=0;
  for (int i=0; i<100; i++){
    
    curRandomNum = distributionGaussian(generator);
    fprintf(stderr, "dbg: curRandomNum Unscaled=%f\n", curRandomNum);
    
    
    if ((curRandomNum >= sensorRangeMin) && (curRandomNum <= sensorRangeMax)){
      dataVec.push_back(curRandomNum);
      fprintf(stderr, "dbg: curRandomNum scaled=%f\n", curRandomNum);
    }
    //cout << "dgb: dataVec.at(" << i << ")=" << dataVec.at(i) << endl;
  
  }
  //fprintf(stderr, "sensor.cpp: seed=%d\n", seed);
  //fprintf(stderr,"dbg: in Ranger::readRanger: random num=%d\n",randNumRay[0]);

  return 0;
  
}
