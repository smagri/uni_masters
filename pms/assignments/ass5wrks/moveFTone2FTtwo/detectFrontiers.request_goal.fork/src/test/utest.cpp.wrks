#include <gtest/gtest.h>
#include <climits>

#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>

//#include "og_help/dtf.h"

#include <iostream>

// global to all tests

double mapSize=20.0;
double resolution=0.1;

int pixels = (int) mapSize / resolution;

// Create an OgMap which is a grayscale (mono) image of size pixels
cv::Mat image = cv::Mat::zeros(pixels, pixels, CV_8UC1);

  

TEST(ImageSize, ShouldPass){

    //! I would STRONGLY suggest to write two functions
    //! image2global and global2image and Unit test them
    //! The functions would allow to go from image space
    //! To Global coordinate system and vice versa

    //! The below code does not do this, it merley sets up the framework
    //! For testing and allows accessing an OPENCV image

    // Let's check map size compared to allocation, just in case
    ASSERT_EQ(pixels, image.rows);
    ASSERT_EQ(pixels, image.cols);

    // Let's check the map is allocated all zeros
    ASSERT_EQ(0, image.at<uchar>(0,0));

    // Draw a link from top left to botom right corner
    cv::line(image,cv::Point(0,0), cv::Point(pixels,pixels), 
	     cv::Scalar(255,255,255),1);

    // Let's check the centre is now white (255)
    ASSERT_EQ(255, image.at<uchar>(pixels/2,pixels/2));

}

// utest.cpp.xy2pxpyVisaVersa
//
// OR, make this global and run image2global/global2image twice in TEST's:
//
// Those that arn't set default to 0???
//double x = 15.0;
//double y = 6.0;
double x=0;
double y=0;
//int px=7;
//int py=4;
int px=0;
int py=0;
double yx;
int pypx;


double image2global(int pypx){

  // Robot is  always at the centre  of the ogMap, so  find the centre
  // first then the offset from it.
  //
  yx = ( ((image.cols / 2) * resolution) + (pypx * resolution) );

  return yx;
    
}


int global2image(double yx){

  
  // Robot is  always at the centre  of the ogMap, so  find the centre
  // first then the offset from it.
  //
  pypx = ( (image.cols / 2) + (yx / resolution) );

  return pypx;
  
}


TEST(sampleTest, pixel2metres){

  std::cerr << "dbg: before.i2g:py=" << py << std::endl;
  std::cerr << "dbg: before.i2g:px=" << px << std::endl;
  
  yx = image2global(py);
  EXPECT_EQ(yx, image2global(py));
  std::cerr << "dbg: after.i2g: " << "y=" << yx << std::endl;

  yx = image2global(px);
  EXPECT_EQ(yx, image2global(px));
  std::cerr << "dbg: after.i2g: " << "x=" << yx << std::endl;    

}

TEST(sampleTest, metres2pixels){

  std::cerr << "dbg: before.g2i: y=" << y << std::endl;
  std::cerr << "dbg: before.g2i: x=" << x << std::endl;

  pypx = global2image(y);
  EXPECT_EQ(pypx, global2image(y));
  std::cerr << "dbg: after.g2i: py=" << pypx << std::endl;
  
  pypx = global2image(x);
  EXPECT_EQ(pypx, global2image(x));
  std::cerr << "dbg: after.g2i: px=" << pypx << std::endl;
  
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
