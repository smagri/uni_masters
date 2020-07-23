#include <ros/ros.h>
#include "image_transport/image_transport.h"
#include "opencv2/highgui/highgui.hpp"
#include "cv_bridge/cv_bridge.h"

// talker.h
// OpenCV includes.
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"

// Using opencv images in ros.
#include "image_transport/image_transport.h"
// talker.h

#include "std_msgs/Float64.h"

#include "rosopencv_node/rosopencvListner.h"


namespace rosopencv_node{

  // Constructor implementation.
  rosopencvListner::rosopencvListner(ros::NodeHandle nh){

    //cv::namedWindow("view");
    //cv::startWindowThread();

    image_transport::ImageTransport it(nh);
    imageSubObj 
      = it.subscribe("camera/image", 1, &rosopencvListner::imageCallback, this);

  }

  
  void rosopencvListner::imageCallback(const sensor_msgs::ImageConstPtr& msg){

    // .orig file
    //cv::imshow("view", cv_bridge::toCvShare(msg, "bgr8")->image);
    //cv::waitKey(30);
    //
    //
    cv_bridge::CvImageConstPtr cvPtr;
    cvPtr = cv_bridge::toCvShare(msg, "mono8");
    cv::imshow("view", cvPtr->image);
    cv::waitKey(3);


    // image_subscriber.cpp
  //   // try{
  //   //   cv::imshow("view", cv_bridge::toCvShare(msg, "bgr8")->image);
  //   //   cv::waitKey(30);
  //   // }
  //   // catch (cv_bridge::Exception& e){
  //   //      ROS_ERROR("Could not convert from '%s' to 'bgr8'.",
    //  msg->encoding.c_str());
  //   // }
  }

  //cv::destroyWindow("view");  in destructor??

} // namespace rosopencv_node{
