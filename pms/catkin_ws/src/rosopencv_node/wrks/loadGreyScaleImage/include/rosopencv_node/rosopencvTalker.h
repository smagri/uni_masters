#ifndef ROSOPENCV_NODE_TALKER_H
#define ROSOPENCV_NODE_TALKER_H

// ROS includes.
#include "ros/ros.h"
#include "ros/time.h"

using namespace std;

namespace rosopencv_node{

  class rosopencvTalker{
    
  public:
    // Constructor.
    rosopencvTalker(ros::NodeHandle nh);
    
    // Timer callback for publishing data.
    void timerCallback(const ros::TimerEvent& event);
    
  private:
    // The timer variable used to go to callback function at specified rate.
    //ros::Timer timerObj;
    
    // Message publisher.
    //ros::Publisher rosopencvPubObj;

    // The actual message strings.
    // std_msgs::String txtTTS;
    // std::string txtTTS;

  }; // class rosopencvTalker{

} // namespace rosopencv_node{

#endif // ROSOPENCV_NODE_TALKER_H
