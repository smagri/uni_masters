// This  program is  a  node  called rosopencvTalker.   A  node is  an
// executable connected  to the  ROS network.
#include <stdio.h>
#include <opencv2/opencv.hpp>


//#include <image_transport/image_transport.h>
#include "image_transport/image_transport.h"
//#include <opencv2/highgui/highgui.hpp>
//#include "opencv2/imgcodecs.hpp"
//#include <cv_bridge/cv_bridge.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "cv_bridge/cv_bridge.h"


#include <chrono>


#include "ros/ros.h"
//#include "std_msgs/String.h"
#include "std_msgs/Float64.h"


// for this to work must have: include_directories(include) in CMakeLists.txt
#include "rosopencv_node/rosopencvTalker.h"

using namespace std;
using namespace cv;


namespace rosopencv_node{

  sensor_msgs::ImagePtr msg; // OpenCV image pointer, msg.
  
  // Constructor implementation
  rosopencvTalker::rosopencvTalker(ros::NodeHandle nh){
    
    
    // Loads and image and converts it to greyscale.
    //
    image_transport::ImageTransport it(nh);
    image_transport::Publisher imagePubObj = it.advertise("camera/image", 1);
    //imagePubObj = it.advertise("camera/image", 1);
    
    //sensor_msgs::ImagePtr msg;

    // Load the image matrix in greyscale.
    //Mat image = imread("/lu1/smagri/images/parkesLunarSmall.jpg",
//		       CV_LOAD_IMAGE_GRAYSCALE);
//Mat image=imead("/lu1/smagri/images/parkesLunar.jpg",CV_LOAD_IMAGE_GRAYSCALE);

    // Display image to screen.
    //
    //cv::namedWindow("Display Image", WINDOW_AUTOSIZE );
    //imshow("Display Image", image);

    //Mat tmp = image.clone();
    //waitKey(30);

    // Convert image to a ROS type sensor_msgs/Image msgs.
    ////msg=cv_bridge::CvImage(std_msgs::Header(), "mono8", image).toImageMsg();
    //msg = cv_bridge::CvImage(std_msgs::Header(), "mono8", tmp).toImageMsg();
    //
    // Convert CvImage to ROS image message.
    //sensor_msgs::ImagePtr msg
    //  = cv_bridge::CvImage(std_msgs::Header(), "mono8", image).toImageMsg();

    // timerCallback call rate is 1/rate, or rateHz. 
    //int rate = 10; // for 1/rate frequency
    int rate = 1; // for rate frequency
    
    // Create timer callback function.
    timerObj = nh.createTimer(ros::Duration(1/rate),
                              &rosopencvTalker::timerCallback, this);
    
  }
  
  
  //void rosopencvTalker::timerCallback(&rosopencvTalker::timerCallback, this){
  void rosopencvTalker::timerCallback(const ros::TimerEvent& event){

    //Mat tmp = image.clone();
    Mat image = imread("/lu1/smagri/images/parkesLunarSmall.jpg",
		     CV_LOAD_IMAGE_GRAYSCALE);
  
    // Convert image to a ROS type sensor_msgs/Image msgs.
    msg = cv_bridge::CvImage(std_msgs::Header(), "mono8", image).toImageMsg();
        
    // Publish image to a topic.
    imagePubObj.publish(msg);
    fprintf(stderr, "timerCallabck: publish\n");
  }
  
}
