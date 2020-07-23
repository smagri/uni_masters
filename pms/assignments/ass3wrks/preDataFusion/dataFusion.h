#ifndef DATAFUSION_H
#define DATAFUSION_H

//#include <vector>
//#include <string>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>

#include "ranger.h"
//#include "dataFusion.h"

using namespace std;

/// Declares the structure that will primarily contain the sensor data
/// buffer; and to  syncronise access to this buffer a  mutex lock and
/// condition variables are used.
//
struct DataBuffer{
  
  queue<double> buffQue_; ///< data buffer is a queue/FIFO
  queue<double> buffQueTimestamp_; ///< data buffer timestamp queue/FIFO

  // Previous extrapolation's  (x, y) becomes  (x1, y1) in  the next
  // extrapolation.
  double xPrev = 0; ///< previous linearly extrapolated value
  double yPrev = 0; ///< previous linearly extrapolated value


  // Flag to  indicate the start of  the que, and hence  there is only
  // one sample in the que we need to have two samples to extrapolate data.
  int prevDatasetPointExists = 0; ///< flag, no previous data point in buffer

  mutex buffMutex_; ///< mutex lock for synconised access to data buffer

  std::condition_variable producer_; ///< for syncronised access to data buffer
  std::condition_variable consumer_; ///< for syncronised access to data buffer
  
};


/*!
 *  \ingroup   ac_shapre DataFusion
 *  \brief     Class DataFusion
 *  \details
 *  This class is derived from the base class DataFusionInterface.\n
 *  \author    Simone Magri
 *  \version   1.0
 *  \date      2017
 *  \pre       none
 *  \bug 

Possible bug in linear extrapolation of sensor 1(Sonar in this case) data.
 *  \warning  

 Perhaps linear extrapolation of polynominal range values of sensor 1,
 the Sonar,  doesn't fit the  data well.  With range  values deviating
 further and  further from the x  axis as time goes  on.  Perhaps, the
 Lagrange Polynomial extrapolation is more appropriate here.
 
 Linear extraploation  of a polynomial  functon is appropriate  if the
 samples  are not  far  apart.   Thus the  conclusion  drawn from  our
 datasets is  that a sampling  rate of 10Hz is  fast enough and  a 3Hz
 sampling rate is too slow.

 */


// Virtual functions in DataFusionInterface.h need to be implemented
// in DataFusion class here.  As  DataFusion class is derived from
// the DataFusionInterface class.  And with virtual functions = 0 in
// DataFusionInterface.h it means that DataFusionInterface.h is an
// abstract  class,  and  thus  the  virtual  functions  need  not  be
// implemented in DataFusionInterface.cpp.
//
//
class DataFusion{
  
 public:

  DataFusion();  // Here because derived classes require it.
  
  void setRangers(vector<Ranger*> rangers);
  //vector<double> getFusedRangeData();
  //vector<vector<double> > getRawRangeData();
  int readRangeData();

  // Other setter fns.
  void setFusionMethod(string fusionMethod);
  string getFusionMethod(void);

  /// Threaded sensor data processing.
  //
  void fillBuffer(int rangerNum);
  void processBuffers(void);
  //void setClearRawDataVector(void);  

  void linearExtrapolation(double x1, double y1,
			   double x2, double y2,
			   double &x, double &y,
			   int rangerNum);

  void startThreads();
  // wrks: std::thread fillBuffer0Thread(&DataFusion::fillBuffer, this);

  void getFusedRangeData(void);
  
  
 protected:

  /// User specified method of processing/fusing raw sensor/ranger
  /// sampled data.
  //
  string fusionMethod_;

  /// The set of sensor/ranger object pointers to do fusion on.
  //
  vector<Ranger *> rangers_;  // STL vector container.

  /// Buffer containes raw sampled data of each sensor/ranger we are
  /// processing, or fusing data with.  Buffer synchronisation is
  /// achieved with a mutex lock.
  ///
  // STL vector of a vector of doubles.
  //vector<vector<double> > rawRangeDataVV_;
  //int numSensors = 2;
  DataBuffer dataBuff[2]; ///< Sensor 1 & Sensor 2, data buffer & mutex lock.

  
    
};

#endif
