// This  program is  a  node  called rosopencvTalker.   A  node is  an
// executable connected  to the  ROS network.
#include <stdio.h>
#include <opencv2/opencv.hpp>


//#include <image_transport/image_transport.h>
//#include <opencv2/highgui/highgui.hpp>
//#include <cv_bridge/cv_bridge.h>
#include "cv_bridge/cv_bridge.h"
#include "opencv2/highgui/highgui.hpp"
//#include "opencv2/imgcodecs.hpp"
#include "opencv2/imgproc/imgproc.hpp"


#include <chrono>


#include "ros/ros.h"
//#include "std_msgs/String.h"
//#include "std_msgs/float32.h"
//#include "std_msgs/Float64.msg"
#include "std_msgs/Float64.h"


// for this to work must have: include_directories(include) in CMakeLists.txt
#include "rosopencv_node/rosopencvTalker.h"

using namespace std;
using namespace cv;


namespace rosopencv_node{

  // Constructor implementation
  rosopencvTalker::rosopencvTalker(ros::NodeHandle nh){

    // Loads and image and converts it to greyscale.
    //
    Mat image; // image is a matrix

    // Load the image in greyscale.
    image =
      imread("/lu1/smagri/uni/subj/proj30cp/catkin_ws/images/lena.jpg",
	     CV_LOAD_IMAGE_GRAYSCALE);
//      imread("/lu1/smagri/uni/subj/proj30cp/catkin_ws/images/parkesLunar.jpg",
//	     CV_LOAD_IMAGE_GRAYSCALE);

    cv::namedWindow("Display Image", WINDOW_AUTOSIZE );
    imshow("Display Image", image);
    
    waitKey(0);
  }
  

  void rosopencvTalker::timerCallback(const ros::TimerEvent& event){

    // publish image to a topic.
    
  }
  
}
