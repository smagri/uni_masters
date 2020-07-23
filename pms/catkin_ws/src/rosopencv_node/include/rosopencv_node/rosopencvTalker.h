#ifndef ROSOPENCV_NODE_TALKER_H
#define ROSOPENCV_NODE_TALKER_H

// OpenCV includes.
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"

// Using opencv images in ros.
#include "image_transport/image_transport.h"
#include "cv_bridge/cv_bridge.h"

// ROS includes.
#include "ros/ros.h"
#include "ros/time.h"

using namespace std;
using namespace cv;


namespace rosopencv_node{

  class rosopencvTalker{
    
  public:
    // Constructor.
    rosopencvTalker(ros::NodeHandle nh);
    
    // Timer callback for publishing data.
    void timerCallback(const ros::TimerEvent& event);
    
  private:
    // The timer variable used to go to callback function at specified rate.
    ros::Timer timerObj;
    
    //ros::Publisher imagePubObj; // Message publisher object.
    image_transport::Publisher imagePubObj;
    
    //Mat image; // Image matrix.
    
    sensor_msgs::ImagePtr msg; // OpenCV image pointer, msg.

    
  }; // class rosopencvTalker{

} // namespace rosopencv_node{

#endif // ROSOPENCV_NODE_TALKER_H
