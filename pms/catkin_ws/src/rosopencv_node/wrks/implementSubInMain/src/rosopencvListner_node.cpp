
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

#include "rosopencv_node/rosopencvListner.h"

void imageCallback(const sensor_msgs::ImageConstPtr& msg){

  cv::imshow("view", cv_bridge::toCvShare(msg, "bgr8")->image);
  cv::waitKey(30);
}
    

int main(int argc, char **argv){

  // Set up ROS.
  ros::init(argc, argv, "rosopencvListner");
  ros::NodeHandle nh;

  // eg. Create a new node_example::Talker object.
  //     node_example::ExampleListener node(nh);
  // eg. Create a new node_example::Talker object.
  //     voice_node::voiceSimpleSub node(nh);
  rosopencv_node::rosopencvListner node(nh);  

  cv::namedWindow("view");
  cv::startWindowThread();

  image_transport::ImageTransport it(nh);
  image_transport::Subscriber imageSubObj;
//  imageSubObj 
  //  = it.subscribe("camera/image", 1, &rosopencvListner::imageCallback, this);
  imageSubObj = it.subscribe("camera/image", 1, imageCallback);
  
  // Let ROS handle all callbacks.
  ros::spin();

  return 0;
} // end main()
