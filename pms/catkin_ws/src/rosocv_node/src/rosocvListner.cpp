#include <stdio.h>

#include <vector>
#include <iostream>

#include <ros/ros.h>

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>


#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>

//#include "rosocv_node/rosocv.h"

using namespace std;
using namespace cv;

void imageCallback(const sensor_msgs::ImageConstPtr& msg){

  cv_bridge::CvImageConstPtr cvPtr;
  try
  {
    //cv::imshow("view", cv_bridge::toCvShare(msg, "bgr8")->image);
    ////cv::imshow("view", cv_bridge::toCvShare(msg, "mono8")->image);
    cvPtr = cv_bridge::toCvShare(msg, "mono8");
    
  }
  catch (cv_bridge::Exception& e)
  {
    //ROS_ERROR("Could not convert from '%s' to 'bgr8'.",msg->encoding.c_str());
    ROS_ERROR("Could not convert from '%s' to 'mono8'.", msg->encoding.c_str());
  }

  cv::imshow("view", cvPtr->image);
  cv::waitKey(3);

  
  //Produce grayscale image histogram.
  //
  int numberBins = 256;
  int scaleLena = 10;
  int scalePks = 50;
  int scale = scalePks;
  vector<int> histogramBin(numberBins, 0); // vector initialised to 0
  int curBinCounter; // Current counter value of histogram bin.

  // Calculate the number of pixels for each intensity value.
  for (int y = 0; y<cvPtr->image.rows; y++){
    for (int x = 0; x<cvPtr->image.cols; x++){
      //histogram[(int)image.at<uchar>(y,x)]++;
      curBinCounter = histogramBin[(int) cvPtr->image.at<uchar>(y,x)];
      histogramBin[(int) cvPtr->image.at<uchar>(y,x)] = ++curBinCounter;
    }
  }

    
  // Printout the histogram.
  //
  //fprintf(stderr, "Current Histogram: [itteration %d]\n", numbersReceived);
  for (int i=0; i<numberBins; i++){
    fprintf(stderr, "Bin %d: ", i);
    for(int j=0; j<histogramBin.at(i); j++){
      //fprintf(stderr, "*");
      //}
      if ((j % scale) == 0){
	// only output a * on the histogram every multiple of scale.
	fprintf(stderr, "*");
      }
    }
    fprintf(stderr, "\n");
  }
  
}



int main(int argc, char **argv){
  
  ros::init(argc, argv, "image_listener");
  ros::NodeHandle nh;
  cv::namedWindow("view");
  cv::startWindowThread();
  image_transport::ImageTransport it(nh);
  image_transport::Subscriber sub
    = it.subscribe("camera/image", 1, imageCallback);
  
  ros::spin();
  cv::destroyWindow("view");
  
}
