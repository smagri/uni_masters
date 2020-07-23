#ifndef DATAFUSION_H
#define DATAFUSION_H

//#include <vector>
//#include <string>
#include <thread>
#include <queue>
#include <mutex>

#include "ranger.h"
#include "dataFusion.h"

using namespace std;

/// Declare the structure that will contain the sensor data buffer &
/// mutex lock.
struct DataBuffer{
  
  queue<double> buffQue_; ///< data buffer is a queue/FIFO
  mutex buffMutex_; ///< mutex lock for synconised access to data buffer
  
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
 *  \bug       none
 *  \warning   
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

  // Threaded sensor data processing.
  //
  //void fillBuffer(DataBuffer &dataBuff, int rangerNum);
  void fillBuffer(void);
  void processBuffer(void);
  //void setClearRawDataVector(void);  


  /// Threaded processing, needs to be accessed from main so made public.
  vector<DataBuffer> dataBuff0; ///< Sensor one data buffer & mutex lock.
  vector<DataBuffer> dataBuff1; ///< Sensor two data buffers & mutex lock.
  
  std::thread fillBuffer0Thread();
  
 protected:

  /// User specified method of processing/fusing raw sensor/ranger
  /// sampled data.
  string fusionMethod_;

  /// The set of sensor/ranger object pointers to do fusion on.
  //
  vector<Ranger *> rangers_;  // STL vector container.

  /// Set of vectors that contain the raw sampled data of each
  /// sensor/ranger we are processing, or fusing data with.
  ///
  // STL vector of a vector of doubles.
  //vector<vector<double> > rawRangeDataVV_;
  
};

#endif
