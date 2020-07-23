// Outline of code to be written:


// Use all that we have learn't so far using:
//
// abstraction(using abstract classes as a base class,ie using pure virtual fns)
// encapsulation??
// inheritance(base classes and derived classes)
// polymorphisim(fn overloading, or using virtual fn's)
// appropriate auto-generated documentation utilising inline source mark-up


// Using  a range  of sensors,  producing  data of  a similar  nature:
// radar/laser/sonar.  Use them in  an abstract manner when processing
// data.   The rest  of the  processing code  can be  agnostic to  the
// sensor type.

// Base sensor:  produces range  to the sensor  surrounding such  as a
// radar/laser/sonar???

// Use base class  'sensor', an abstract class, ie no  objects of this
// class  exist.  It  is purley  there  to provide  inherited fns  for
// derived classes.  In this case the derived classes are radar, lasor
// and sonar.


// Task:
//
// a)  create a base  sensor class and expand  it to a  range of
// sensors.    Let's   start   with  assignment   one   sensor.h   and
// sensor.cpp???   And expand  it  to a  range  of sensors  radar.cpp,
// laser.cpp, sonar.cpp.
//
// b)  a class(or  another class???)   to  process the  data, that  is
// agnostic to  the sensor type, and  process that data to  produce to
// produce data that is fused from sensor output.



Specifics:
----------

// The  physical sensors  are  collocated, placed  side  by side,  the
// spatial seperation of sensors can be disregarded.  So basically the
// sensors are in the same spot producing data.

// A) - looks similar to ass1
//
// * create a base sensor class called Ranger
// * and three derived sensor classes, Radar, Sonar and Laser.

// private: or protected: data placed in base class???:
	// fov(field of view)
        // number of samples(max sequence number???)
	// data. array of data???
	// usb port for connection(/tty/ACMx like string)


// B) common to all sensors??? - looks similar to ass1

// 1. init  vars to connect to  the sensor (as per  ass1: model, baud,
// port???), should this be a make a private/protected method???

// 2.  get hdw  fixed  values  of the  sensor(as  per ass1,  maxRange,
// minRange but no fov as need to put that in base class???   )

// 3. set  configurable parameters of  the sensor:
//
// appears just to be able to  set the sensor resolution(see 5.), like
// angular resolution in the laser range finder in ass1???

// 4. inform if values are sane, us default values otherwise, improve ass1

// 5. obtain sample sensor data & sensor resolution:
   // generated as a random value from a normal distribution, where
   // mean=6m and std. deviation is=5m, clipped to the maximum
   // specific sensor sensing range.

// C) the RangerFusion class will need to:
//
// 1. RangerFusion(string fusionMethod) fusionMethod=min/max/average string.

// 2. virtual void setRangers(vector<Ranger *> rangers) = 0
//
// Container of sensors called rangers.  The container is a vector of
// pointers to the Ranger base class(like <Student *> in tutorial work).
//

// 3. Produce a fusion of sensor reading with specified fusion method
// and dealing with readings that are on the bounday of the sensing
// range.
//
// ie determine  the min/max/average, =fusionMethod  already specified
// in constructor of the  class, foreach individual sensor(not combine
// the readings of all three sensors???).  If the fused readings are >
// maxRange(and  < minRange)  clip to  maxRange.  ie,  make reading  =
// maxRange.

// 4. Returns  a vector of  double type  values.  Number of  values to
// return  is dictated  by the  numSamples  in the  base class  called
// Ranger,  so size  of vector  is numSamples.   This would  then also
// indicate that  readSensor() returns an  array of sampled  values as
// randNumRay[numSamples].
//
// Perform fusionMethod on numSamples.

// 5. Returns an STL container of raw unfused data.  So probably just
// keep all the raw vectors of size numSamples in this container,
// another vector, so a vector of vectors that contain doubles.

// 6. RangerFusionClass: public RangerFusionInterface{
//    }
//
// Thus  RangerFusionInterface  class  is  an abstract  class  due  to
// virtual fns  = 0.  So  no object of this  class will ever  be made.
// Also,    no     member    fn's     will    be     implemented    in
// RangerFusionInterface.cpp.  So  it's ment for the  derived classes,
// that  is those  that  derive from  RangerFusionInterface class,  to
// implement  these fn's.   Note  that RangerFusion  class  is such  a
// derived class, as it inherites from RangerFusionInterface.


// D) as per main of ass1 but calls RangerFusion class, and obtains
// the fused data output...do we display output??? doesn't look like
// it.


// Forward Declaration is a declaration of a type, variable, fn... for
// which the programmer has not yet given the the complete definition.
// In  C++ you  should forward  declare classes  instead of  including
// headers.
