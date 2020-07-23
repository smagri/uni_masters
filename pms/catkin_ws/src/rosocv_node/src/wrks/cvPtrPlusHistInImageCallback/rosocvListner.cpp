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

  //cv::imshow("view", cv_bridge::toCvShare(msg, "mono8")->image);
  //cv::waitKey(30);
  cv_bridge::CvImageConstPtr cvPtr;
  //cvPtr = cv_bridge::toCvCopy(msg, "mono8");
  
  try
  {
    //cv::imshow("view", cv_bridge::toCvShare(msg, "bgr8")->image);
    ////cv::imshow("view", cv_bridge::toCvShare(msg, "mono8")->image);
    cvPtr = cv_bridge::toCvCopy(msg, "mono8");
    
  }
  catch (cv_bridge::Exception& e)
  {
    //ROS_ERROR("Could not convert from '%s' to 'bgr8'.",msg->encoding.c_str());
    ROS_ERROR("Could not convert from '%s' to 'mono8'.", msg->encoding.c_str());
  }

  cv::imshow("view", cvPtr->image);
  cv::waitKey(30);

  
  //Produce grayscale image histogram.
  //
  int numberBins = 256;
  //int bin_width = 4;
  //int image_depth = 256;
  int scale = 10;
  //int numberBins = (image_depth / bin_width) + 1;
  vector<int> histogramBin(numberBins, 0); // vector initialised to 0
  int curBinCounter; // Current counter value of histogram bin.

  ////cv_bridge::CvImageConstPtr cvPtr;
  //cvPtr = cv_bridge::toCvShare(msg, "mono8");
  //sensor_msgs::ImagePtr msg;
  //// cvPtr = cv_bridge::toCvCopy(sensor_msgs::ImagePtr msg, "mono8");

  // Calculate the number of pixels for each intensity value.
  // for (int y = 0; y<image.rows; y++){
  //   for (int x = 0; x<image.cols; x++){
  //     //histogram[(int)image.at<uchar>(y,x)]++;
  //     curBinCounter = histogramBin[(int)image.at<uchar>(y,x)];
  //     histogramBin[(int)image.at<uchar>(y,x)] = ++curBinCounter;
  //   }
  // }
  // need to xfer image pointer properly from publisher to subscriber
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
      fprintf(stderr, "*");
      //cout << "*";
    }
    // if ((j % scale) == 0){
    //   // only output a * on the histogram every multiple of scale.
    //   fprintf(stderr, "*");
    // }
    //   //}
    fprintf(stderr, "\n");
    //   //cout << endl;
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
  //image_transport::Subscriber sub
  //  = it.subscribe("camera/image", 1, main);

  //cv_bridge::CvImageConstPtr cv_ptr;
  // cv_ptr
  //  = sensor_msgs::image_encodings cv_bridge::toCvShare(msg, "mono8")->image);
  //cv_ptr = cv_bridge::toCvShare(msg, "mono8")->image);
  
  // Produce grayscale image histogram.
  //
  int numberBins = 256;
  //int bin_width = 4;
  //int image_depth = 256;
  int scale = 10;
  //int numberBins = (image_depth / bin_width) + 1;
  vector<int> histogramBin(numberBins, 0); // vector initialised to 0
  int curBinCounter; // Current counter value of histogram bin.

  ////cv_bridge::CvImageConstPtr cvPtr;
  //cvPtr = cv_bridge::toCvShare(msg, "mono8");
  //sensor_msgs::ImagePtr msg;
  //// cvPtr = cv_bridge::toCvCopy(sensor_msgs::ImagePtr msg, "mono8");

  // Calculate the number of pixels for each intensity value.
  // for (int y = 0; y<image.rows; y++){
  //   for (int x = 0; x<image.cols; x++){
  //     //histogram[(int)image.at<uchar>(y,x)]++;
  //     curBinCounter = histogramBin[(int)image.at<uchar>(y,x)];
  //     histogramBin[(int)image.at<uchar>(y,x)] = ++curBinCounter;
  //   }
  // }
  // need to xfer image pointer properly from publisher to subscriber
  // for (int y = 0; y<cvPtr->image.rows; y++){
  //   for (int x = 0; x<cvPtr->image.cols; x++){
  //     //histogram[(int)image.at<uchar>(y,x)]++;
  //     curBinCounter = histogramBin[(int)cvPtr->image.at<uchar>(y,x)];
  //     histogramBin[(int)cvPtr->image.at<uchar>(y,x)] = ++curBinCounter;
  //   }
  // }

    
  // Printout the histogram.
  //
  //fprintf(stderr, "Current Histogram: [itteration %d]\n", numbersReceived);
  // for (int i=0; i<numberBins; i++){
  //   fprintf(stderr, "Bin %d: ", i);
  //   for(int j=0; j<histogramBin.at(i); j++){
  //     fprintf(stderr, "*");
  //     //cout << "*";
  //   }
  // // if ((j % scale) == 0){
  // //   // only output a * on the histogram every multiple of scale.
  // //   fprintf(stderr, "*");
  // // }
  // //   //}
  //   fprintf(stderr, "\n");
  // //   //cout << endl;
  // }

  
  ros::spin();
  cv::destroyWindow("view");
  
}
