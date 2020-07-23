// This  program is  a  node  called randomNumTalker.   A  node is  an
// executable connected  to the  ROS network.
#include <chrono>


#include "ros/ros.h"
//#include "std_msgs/String.h"
//#include "std_msgs/float32.h"
//#include "std_msgs/Float32.msg"
#include "std_msgs/Float32.h"


// for this to work must have: include_directories(include) in CMakeLists.txt
#include "randomNum_node/randomNumTalker.h"

using namespace std;


namespace randomNum_node{

  // Constructor implementation
  randomNumTalker::randomNumTalker(ros::NodeHandle nh){
    
    
    // Generate  a  random value  from  a  normal distribution.   Normal
    // distribution is  aka gaussian distribution.  Note  that these are
    // pseudo-random numbers.
    
    int nodeBufSize = 1000;
    //    randomNumPubObj =
    //    nh.advertise<std_msgs::String>("randomNumTopic", nodeBufSize);
    randomNumPubObj =
      nh.advertise<std_msgs::Float32>("randomNumTopic", nodeBufSize);

    // timerCallback call rate is 1/rate, or rateHz. 
    //int rate = 10; // for 1/rate frequency
    int rate = 1; // for rate frequency
    
    // Create timer callback function.
    timerObj = nh.createTimer(ros::Duration(1/rate),
                              &randomNumTalker::timerCallback, this);
    
  } //  randomNumTalker::randomNumTalker(ros::NodeHandle nh){



  void randomNumTalker::timerCallback(const ros::TimerEvent& event){
   
    // Generate  time-based  seed  for  the  random  number  algorithim.
    // Initialise random numer generator with seed.
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator (seed);
    //generator.min(0.0);
    //generator.max(1.0);

    // Normal/Gaussian distributions, which has mean=6 and std deviation=5.
    //
    //std::normal_distribution<double> distributionGaussian(mean,
    //							  stddev, min, max);
    //std::normal_distribution<double> distributionGaussian(0.0, 1.0),
    //  min(0.0), max(1.0);
    std::normal_distribution<double> distributionGaussian(0.0, 1.0);
 
    std_msgs::Float32 msg;
    msg.data = distributionGaussian(generator);

    // Could choose values/msg.data that are between 0.0 and 1.0 only, and only 
    // send them accross to the subscriber node.

    ROS_INFO("%f", msg.data);
    fprintf(stderr,
	    "timerCbk: random number from gaussian distribution = %f\n",
	    msg.data);
    randomNumPubObj.publish(msg);
 
  }

} // namespace randomNum_node{
