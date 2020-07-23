#ifndef RANGER_H_
#define RANGER_H_


//
// Base Sensor class called Ranger.
//
// Class declaration/definition/interface???
//
//
#include <vector>
#include <string>
#include <unistd.h>

#include "random.h"


#define NUM_SAMPLES 10  // Number of samples for fusion.


using namespace std; // allow use as std::


class Ranger{

 public:

  // Accessable to all classes.
  Ranger();
  
  
  // Connecting to the sensor member fns, all sensors require these.
  void setConnectnModel(string model);
  void setConnectnBaud(int baud);
  void setConnectnPort(string port);

  // Getting hardware specific fixed parameters of the sensor.
  double getHdwFixedFOV(void);
  double getHdwFixedRangeMin(void);
  double getHdwFixedRangeMax(void);

  // Set configurable parameters of the sensor.
  void setConfigResolution(double resolution);

  // Virtual fns  are overriden  in the  derived classes  that inherit
  // from  this class.   Making fn  = 0  implies that  this is  a pure
  // virtual function and makes this  class an abstract class.  For an
  // abstract class  it implies  that no  object can  be made  of this
  // class.
  //
  int readRanger(vector<double> &dataVec, int samplingRate, int numSamples);
  
 protected:

  // Accessable to the base class and the derived classes.

  // All related to the Sensor/Ranger
  string model_; // model name
  int baud_;	 // baud rate
  string port_;  // serial/usb port
  
  double fov_;     // Field Of View
  double rangeMin_; // Minimum Range
  double rangeMax_; // Maximum Range
  
  double data_[NUM_SAMPLES];// NUM_SAMPLES in data vector for performing fusion.
  
  double resolution_;

  // private: Accessable to those classes that derive from this base class.
};


#endif // RANGER_H_
