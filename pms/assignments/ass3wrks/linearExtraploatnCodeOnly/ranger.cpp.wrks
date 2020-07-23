//
// Base class called Ranger.
//
//
// Class implementation.  That is, class member fns or methods defined.
//
//
#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include <random>
#include <cstdio>
#include <string>
#include <cmath>
#include <ctime>
#include <sys/time.h>

#include "ranger.h"


Ranger::Ranger(){

  /// Default constructor
  //  -  no return type or parameters.
  
  // should this be blank?
  model_ = "model";
  baud_ = 38400;
  port_ = "/dev/ttyACM0";

  double fov_ = 180;
  double distanceMax = 8.0;
  double distanceMin = 0.2;
  
}


// Connecting to the Sensor, via serial over usb port:
//
// void Ranger::setConnectnModel(string model){
  
//   model_ = model;

//   // fprintf(stderr, "dbg: model_=%\n", model_.c_str());
// }

string Ranger::getConnectnModel(void){

  return model_;
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
  
  //fprintf(stderr, "dbg: baud_=%d\n", baud_);
}

int Ranger::getConnectnBaud(void){

  return baud_;
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

  //fprintf(stderr, "dbg: port_=%s\n", port_.c_str());

  return;
  
}

string Ranger::getConnectnPort(void){

  return port_;
}

// Get hardware specific fixed parameters of the sensor:
//
// Should this be user configurable???
double Ranger::getHdwFixedFOV(void){

  return fov_;
}

double Ranger::getHdwFixedRangeMin(void){

  return rangeMin_;
}

double Ranger::getHdwFixedRangeMax(void){
  
  return rangeMax_;
}

int Ranger::getHdwFixedNumSamples(void){
  
  return numSamples_;
}

int Ranger::getHdwFixedSamplingRate(void){
  
  return samplingRate_;
}

double Ranger::getHdwFixedSensorResolution(void){
  
  return sensorRes_;
}


vector<double> Ranger::getRawData(void){

  /// Retruns the raw sensor data vector/buffer.
  
  return rawData_;
}


void Ranger::clearRawData(void){

  /// Clears the raw sensor data vector/buffer.
  rawData_.clear();
}


int Ranger::readRanger(vector<double> &rawData_,
		       int samplingRate, int numSamples){

  /// Reads raw sampled data from the sensor/ranger.  Random numbers
  /// are used to simulate data from the sensor.
  
  double sensorRangeMin, sensorRangeMax;
  double curRandomNum; // current random number from distribution
  double t; // current system time
  //double sampleSleepTime;

  // This process sleeps for this length of time to simulate sampling
  // the sensor data.
  int sleepTime;

  
  // Normally here you would open() the sensor/device and read().
  //
  // And really this is a bit of a fudge, it's not guarantied exactly
  // 1/60s wait, could be longer, depends on context switch.
  //
  // So we sleep/block here for 1/sampleRate seconds.
  //
  // 1.0/samplingRate=1/60=0.0166667s=16667 uS
  //
  
  // noWorks:
  // 1/samplingRate=0 as is an int & == 0, dauh!:
  //
  // wrks:
  //sleepTimeD = ( ((double) 1) / ((double) 3) ) * 1000;
  //sleepTime = (int) sleepTimeD;
  // wrks, in c: sleepTime = pow(samplingRate, -1) * 1000;
  // wrks, in c++: sleepTime = pow( (1.0*samplingRate), -1.0) * 1000;
  //
  // wrks, simplest & quickest:
  // chrono::nanoseconds(sleepTime) would give greater precision
  ////sleepTime = (1.0 / samplingRate) * 1000; //in ms
  //sleepTime = (1.0 / samplingRate) * 1000000; // in us
  
  // fprintf(stderr, "dbg: readRanger: sampleRate=%dHz => sleepTime=%dms\n",
  // 	  samplingRate, sleepTime);
  ////std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));
  
  //
  // nowrks, 1/samplingRate is an integer=0:
  // usleep((1/samplingRate) * 10^6); OR usleep((1/samplingRate) * 1000000);
  // should wrk: usleep((1.0/samplingRate) * 10^6);
  //usleep((unsigned int) sleepTime);

  
  // Generate  a  random value  from  a  normal distribution.   Normal
  // distribution is  aka gaussian distribution.  Note  that these are
  // pseudo-random numbers.

  // Generate  time-based  seed  for  the  random  number  algorithim.
  // Initialise random numer generator with seed.
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::default_random_engine generator (seed);

  // Normal/Gaussian distributions, which has mean=6 and std deviation=5.
  //
  std::normal_distribution<double> distributionGaussian(0.0, 0.1);


  // Determine sensor range/resolution, for clipping values later.
  sensorRangeMin = getHdwFixedRangeMin();
  sensorRangeMax = getHdwFixedRangeMax();
  //
  //fprintf(stderr, "dbg: readRanger: sensorRangeMin=%f\n", sensorRangeMin);
  //fprintf(stderr, "dbg: readRanger: sensorRangeMax=%f\n", sensorRangeMax);

  // Fill data vector with random numbers.
  for (int i=0; i<numSamples; i++){
    
    // Determine the current time, t, since the epoch of 1Jan1970.
    //time_t t =  time(NULL);
    //fprintf(stderr,
    //"dbg: readRanger: t=%ld seconds since 01-Jan-1970 epoch.\n", t);
    timeval time;
    gettimeofday(&time, NULL);
    t = time.tv_sec + (time.tv_usec / 1000000.0);
    fprintf(stderr,
	    "dbg: readRanger: t=%f seconds since 01-Jan-1970 epoch.\n", t);
    
    curRandomNum =
      6 + (4 * sin(2 * M_PI * 0.01 * t)) + distributionGaussian(generator);
    
    //fprintf(stderr, "dbg: readRanger: curRandomNum Unclipped=%f\n",
    // curRandomNum);
    
    
    // Need to scale/clip these random values to sensor range/resolution.
    if (curRandomNum <= sensorRangeMin){
      curRandomNum = sensorRangeMin;
    }
    
    if (curRandomNum >= sensorRangeMax){
      curRandomNum = sensorRangeMax;
    }
    
    //fprintf(stderr, "dbg: readRanger: curRandomNum clipped=%f\n",
    //curRandomNum);
    
    rawData_.push_back(curRandomNum);
    // maybe should use rawData_.at(i) instead???
    
  } // for (int i=0; i<numSamples; i++){
  
  for (int i=0; i<rawData_.size(); i++){
    // rawData_ vector is numSamples long at this stage.
    //
    // don't use cout as it is buffered:
    // cout << "dgb: readRanger: rawData_.at("
    // 	 << i << ")=" << rawData_.at(i) << endl;
    fprintf(stderr, "dbg: readRanger: rawData_.at(%d)=%f\n", i, rawData_.at(i));
  }

  
  return 0;
  
}
