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

#include "RangerFusionInterface.h"
#include "rangerFusion.h"
#include "random.h"


#define MAX_NUM_SAMPLES 10  // Number of samples for fusion.


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

  // Other getter fns.
  //vector<double> getRawData(void);
  string getConnectnModel(void);
  int getConnectnBaud(void);
  string getConnectnPort(void);
  
  // Set configurable parameters of the sensor.
  //void setConfigResolution(double resolution);

  // Virtual fns  are overriden  in the  derived classes  that inherit
  // from  this class.   Making fn  = 0  implies that  this is  a pure
  // virtual function and makes this  class an abstract class.  For an
  // abstract class  it implies  that no  object can  be made  of this
  // class.
  //
  // This  should  be  a  virtual  function  with  an  interface  file
  // RangerInterface.h(similar  to RangerFusionInterface.h),  where it
  // can be  made pure  virtual so  no-one can make  an object  of the
  // Ranger base class. [no time left for this one]
  //
  int readRanger(vector<double> &rawData_, int samplingRate, int numSamples);

  //vector<double> rawData_;
  
 protected:

  // Accessable to the base class and the derived classes.

  // All related to the Sensor/Ranger
  string model_; // model name
  int baud_;	 // baud rate
  string port_;  // serial/usb port
  
  double fov_;     // Field Of View
  double rangeMin_; // Minimum Range, or derived class private data???
  double rangeMax_; // Maximum Range, or derived class private data???

  //wrks also: double rawData_[MAX_NUM_SAMPLES];
  //
  // rawData_ for each sensor, note we don't need to give it the numSamples
  vector<double> rawData_;
  
  // private: Accessable only to member fns of this class.
};


#endif // RANGER_H_
