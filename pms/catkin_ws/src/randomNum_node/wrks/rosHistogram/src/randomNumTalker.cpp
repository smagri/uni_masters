// This  program is  a  node  called randomNumTalker.   A  node is  an
// executable connected  to the  ROS network.
#include <chrono>


#include "ros/ros.h"
//#include "std_msgs/String.h"
//#include "std_msgs/float32.h"
//#include "std_msgs/Float64.msg"
#include "std_msgs/Float64.h"


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
      nh.advertise<std_msgs::Float64>("randomNumTopic", nodeBufSize);

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

    // Normal/Gaussian distributions, which has mean=6 and std deviation=5.
    //
    // mean=0.5 with +-0.5 stddev works quickly and well in producing
    // values between 0 and 1.
    //wrks: std::normal_distribution<double> distributionGaussian(0.5, 0.5);
    std::normal_distribution<double> distributionGaussian(0.5, 0.2);
 
    std_msgs::Float64 msg;
    msg.data = distributionGaussian(generator);

    // Could choose values/msg.data that are between 0.0 and 1.0 only, and only 
    // send them accross to the subscriber node.

    if ((msg.data >= 0) && (msg.data <= 1)){
      //ROS_INFO("%f", msg.data);
      fprintf(stderr,
	      "timerCbk: random number (0-1) from gaussian distribution = %f\n",
	      msg.data);
      randomNumPubObj.publish(msg);
    }
    
  } // void randomNumTalker::timerCallback(const ros::TimerEvent& event){

} // namespace randomNum_node{
