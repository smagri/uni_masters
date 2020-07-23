#ifndef RANDOMNUM_NODE_LISTNER_H
#define RANDOMNUM_NODE_LISTNER_H

// ROS includes.
#include "ros/ros.h"
#include "ros/time.h"
#include "std_msgs/Float64.h"

using namespace std;

namespace randomNum_node{

  class randomNumListner{
    
  public:
    // Constructor.
    randomNumListner(ros::NodeHandle nh);
    
    // Callback functions.
    //
    //void voiceNameTopicCallback(const std_msgs::String::ConstPtr& msg);
    void randomNumTopicCallback(const std_msgs::Float64::ConstPtr& msg);

    //std::string voice;
    //std::string sayText;

  private:
    
    // Message subsciber.
    //ros::Subscriber txt4TTSsubObj;
    //ros::Subscriber voiceNameSubObj;
    ros::Subscriber randomNumSubObj;

    // Each histogram bin contains the total number of random
    // histogram values falling within that bin.
    vector<int> histogramBin;
    int numBins = 10; // ie 0-9 at 0.1 increments
    

  }; // class randomNumListner{

} // namespace randomNum_node{

#endif // RANDOMNUM_NODE_LISTNER_H
