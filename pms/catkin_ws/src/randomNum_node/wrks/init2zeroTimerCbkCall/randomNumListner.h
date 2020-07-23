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
    //void txt4TTStopicCallback(const std_msgs::String::ConstPtr& msg);
    //void voiceNameTopicCallback(const std_msgs::String::ConstPtr& msg);
    void randomNumTopicCallback(const std_msgs::Float64::ConstPtr& msg);

    //std::string voice;
    //std::string sayText;

  private:
    
    // Message subsciber.
    //ros::Subscriber txt4TTSsubObj;
    //ros::Subscriber voiceNameSubObj;
    ros::Subscriber randomNumSubObj;

    // The actual message strings.
    // std_msgs::String txtTTS;
    // std::string txtTTS;

  }; // class randomNumListner{

} // namespace randomNum_node{

#endif // RANDOMNUM_NODE_LISTNER_H
