#ifndef ROSOPENCV_NODE_LISTNER_H
#define ROSOPENCV_NODE_LISTNER_H

// ROS includes.
#include "ros/ros.h"
#include "ros/time.h"
#include "std_msgs/Float64.h"

using namespace std;

namespace rosopencv_node{

  class rosopencvListner{
    
  public:
    // Constructor.
    rosopencvListner(ros::NodeHandle nh);
    
    // Callback functions.
    //
    //void voiceNameTopicCallback(const std_msgs::String::ConstPtr& msg);
    void rosopencvTopicCallback(const std_msgs::Float64::ConstPtr& msg);

  private:
    
    // Message subsciber.
    //ros::Subscriber rosopencvSubObj;

    // Each histogram bin contains the total number of random
    // histogram values falling within that bin.
    //vector<int> histogramBin;
    //int numBins = 10; // ie 0-9 at 0.1 increments

    // Total number of doubles recieved by the subscriber node.
    //int numbersReceived;
    
  }; // class rosopencvListner{

} // namespace rosopencv_node{

#endif // ROSOPENCV_NODE_LISTNER_H
