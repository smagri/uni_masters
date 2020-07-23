
#include <stdio.h>
#include <opencv2/opencv.hpp>

#include "opencv2/highgui/highgui.hpp"
//#include "opencv2/imgcodecs.hpp"
#include "opencv2/imgproc/imgproc.hpp"



// so no need the prefix cv class member fn's with cv::
using namespace cv;



int main(int argc, char** argv ){

  
  if ( argc != 2 ){
    printf("usage: DisplayImage.out <Image_Path>\n");
    return -1;
  }

    
  Mat image; // image is a matrix
  
  //int binWidth = 4;
  //int imageDepth = 256; // Number of bins in the histogram
  //int numberBins = ((imageDepth / binWidth) + 1);
  int numberBins = 256;
  //lenna.jpg int scale = 10; // only output a * on the histogram every multiple
  //parkes.jpg scale = 550.
  // scale=55 for parkesLunarSmall.jpg
  // scale=9 for lena.jpg
  int scale = 55; // only output a * on the histogram every multiple
		 // of scale.  can make this arg[3]
  
  vector<int> histogramBin(numberBins, 0); // vector initialised to 0
  int curBinCounter; // Current counter value of histogram bin.
  

  
  // Load the image in greyscale, 0 = CV_LOAD_IMAGE_GRAYSCALE.
  image = imread(argv[1], CV_LOAD_IMAGE_GRAYSCALE);
  
  
  // Initialise histogramBin vector, all 0s
  //
  // for (int i=0; i<imageDepth; i++){
  //   histogramBin.push_back(0);
  // }


  // Calculate the number of pixels for each intensity value.
  for (int y = 0; y<image.rows; y++){
    for (int x = 0; x<image.cols; x++){
      //histogram[(int)image.at<uchar>(y,x)]++;
      curBinCounter = histogramBin[(int)image.at<uchar>(y,x)];
      histogramBin[(int)image.at<uchar>(y,x)] = ++curBinCounter;
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
    
    
  if ( !image.data ){
    printf("No image data \n");
    return -1;
  }
    
  namedWindow("Display Image", WINDOW_AUTOSIZE );
  imshow("Display Image", image);
    
  waitKey(0);
    
  return 0;
  
}

	
