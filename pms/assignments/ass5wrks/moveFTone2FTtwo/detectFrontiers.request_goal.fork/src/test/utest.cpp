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
// // Those that arn't set default to 0???
// //double x = 15.0;
// //double y = 6.0;
// double x=0;
// double y=0;
// //int px=7;
// //int py=4;
// int px=0;
// int py=0;
// double yx;
// int pypx;

struct coord_state{
  double x;
  double y;
  int px;
  int py;

  // double yx;
  // int pypx;
};


struct coord_state coordObj;

double image2global(int pypx){

  // Robot is  always at the centre  of the ogMap, so  find the centre
  // first then the offset from it.
  //
  double yx;
  
  yx = ( ((image.cols / 2) * resolution) + (pypx * resolution) );

  return yx;
    
}


int global2image(double yx){

  
  // Robot is  always at the centre  of the ogMap, so  find the centre
  // first then the offset from it.
  //
  int pypx;
  
  pypx = ( (image.cols / 2) + (yx / resolution) );

  return pypx;
  
}


// TEST(sampleTest, pixel2metres){

//   std::cerr << "dbg: before.i2g:py=" << py << std::endl;
//   std::cerr << "dbg: before.i2g:px=" << px << std::endl;
  
//   yx = image2global(py);
//   EXPECT_EQ(yx, image2global(py));
//   std::cerr << "dbg: after.i2g: " << "y=" << yx << std::endl;

//   yx = image2global(px);
//   EXPECT_EQ(yx, image2global(px));
//   std::cerr << "dbg: after.i2g: " << "x=" << yx << std::endl;    

// }

// TEST(sampleTest, metres2pixels){

//   std::cerr << "dbg: before.g2i: y=" << y << std::endl;
//   std::cerr << "dbg: before.g2i: x=" << x << std::endl;

//   pypx = global2image(y);
//   EXPECT_EQ(pypx, global2image(y));
//   std::cerr << "dbg: after.g2i: py=" << pypx << std::endl;
  
//   pypx = global2image(x);
//   EXPECT_EQ(pypx, global2image(x));
//   std::cerr << "dbg: after.g2i: px=" << pypx << std::endl;
  
// }

//------------------------------------------------------------------------------

// Using parameterised tests:
//
// as we want to test  multiple instances of the coord structure/class.

struct CoordTest: testing::WithParamInterface<coord_state>{

  CoordTest(){
    // initialise coord_state struct
    coordObj.x = GetParam().x;
    coordObj.y = GetParam().y;
    coordObj.px = GetParam().px; 
    coordObj.py = GetParam().py;
  }
  
};


// struct coord_state{
//   double x;
//   double y;
//   int px;
//   int py;

//   double yx;
//   int pypx;
// };

TEST_P(CoordTest, pixels2metres){

  auto cs = GetParam();  // puts coord_state into as object                             
  // std::cerr << "dbg: before.i2g:py=" << py << std::endl;
  // std::cerr << "dbg: before.i2g:px=" << px << std::endl;
  
  cs.y = image2global(cs.py);
  EXPECT_EQ(cs.y, image2global(cs.py));
  // std::cerr << "dbg: after.i2g: " << "y=" << yx << std::endl;

  cs.x = image2global(cs.px);
  EXPECT_EQ(cs.x, image2global(cs.px));
  // std::cerr << "dbg: after.i2g: " << "x=" << yx << std::endl;    
}


TEST_P(CoordTest, metres2pixels){

  auto cs = GetParam();  // puts account_state into as object

  // std::cerr << "dbg: before.g2i: y=" << y << std::endl;
  // std::cerr << "dbg: before.g2i: x=" << x << std::endl;

  cs.py = global2image(cs.y);
  EXPECT_EQ(cs.py, global2image(cs.y));
  // std::cerr << "dbg: after.g2i: py=" << pypx << std::endl;
  
  cs.px = global2image(cs.x);
  EXPECT_EQ(cs.px, global2image(cs.x));
  // std::cerr << "dbg: after.g2i: px=" << pypx << std::endl;
  
}


INSTANTIATE_TEST_CASE_P(Default, CoordTest,
 testing::Values
 (
   
  // Create a couple of account states, or objects of coord_state struct.
                                                                                    // {initial_balance, withdraw_amount, final_balance, success}                          
  coord_state{0, 0, 0, 0}
      //   // coord_state{100, 200, 100, false}
  
  
  ));


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
