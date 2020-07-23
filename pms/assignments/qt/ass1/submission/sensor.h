#ifndef SENSOR_H_
#define SENSOR_H_

#include <string>

#include "random.h"

using namespace std; // allow use as std::



// Sensor base class
//
class Sensor: public Random{

  // Sensor class derives from the Random class.
  
 public:
  // Sensor default constructor, no parameters or return value.
  //
  // This initialises all common sensor variables.
  //
  Sensor();

  // Sensor member fns
  //
  // Example of Polymorphisim as same name fn but different signature.
  // Which one is called depends on the object we are using.  We have
  // different fns for different types of objects???
      
  // virtual indicates  that these  fns can  be overloaded  in derived
  // classes.   This make  sence as  different objects  have different
  // formulas for area and perimitier.
  //
  // virtual qualifier  tells the  compiler that  the function  may be
  // overloaded and to  prefer the derived fn version  rather than the
  // base version.
  //
  //virtual int getPerimeter(void);
  //virtual int getFixedHdwAttributes(struct fixedAtt &refFixedHA);
  // 
  // At this stage max number of doubles is 3, other types later, and
  // variable argument list???
  virtual void setConnectAttributes(string model, int baud, string port);
  virtual void printConnectAttributes(void);
  virtual int getFixedHdwAttributes(double &att1, double &att2, double &att3);
  virtual int setConfigAttributes(double &att1, double &att2, double &att3);
  virtual int readSensor(double randNumRay[], int samplingRate,
			 double fMin, double fMax, Random &randSensor);

 protected:
  // protected: accessor type means that these member data of base
  // class Sensor are available to the base class and the derived
  // classes only.

  // Common to all sensors.
  //
  // *** Need to use 'new' here instead of fixed width arrays. ****
  string model_;	// model name
  int baud_;		// baud rate
  string port_; // usb port sensor is connected
				     // to /dev/ttyACMx

 private:
  
};


#endif // SENSOR_H_
