#ifndef RANDOMNUM_NODE_TALKER_H
#define RANDOMNUM_NODE_TALKER_H

// ROS includes.
#include "ros/ros.h"
#include "ros/time.h"

using namespace std;

namespace randomNum_node{

  class randomNumTalker{
    
  public:
    // Constructor.
    randomNumTalker(ros::NodeHandle nh);
    
    // Timer callback for publishing data.
    void timerCallback(const ros::TimerEvent& event);
    
  private:
    // The timer variable used to go to callback function at specified rate.
    ros::Timer timerObj;
    
    // Message publisher.
    ros::Publisher randomNumPubObj;

    // The actual message strings.
    // std_msgs::String txtTTS;
    // std::string txtTTS;

  }; // class randomNumTalker{

} // namespace randomNum_node{

#endif // RANDOMNUM_NODE_TALKER_H
