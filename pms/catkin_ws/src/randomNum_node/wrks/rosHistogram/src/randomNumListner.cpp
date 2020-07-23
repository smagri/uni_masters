#include "std_msgs/Float64.h"

#include "randomNum_node/randomNumListner.h"

namespace randomNum_node{

  // Constructor implementation
  randomNumListner::randomNumListner(ros::NodeHandle nh){

    // Subscribe to the topic that generates random double numbers.
    int nodeBufSize = 1000;
    randomNumSubObj =
      nh.subscribe("randomNumTopic", nodeBufSize,
                   &randomNumListner::randomNumTopicCallback, this);


    // Initialise histogramBin vector, all 0s
    //
    // segfaults: histogramBin[0] = 0;
    // no build: histogramBin.at(0).push_back(0);
    //
    for (int i=0; i<numBins; i++){
      histogramBin.push_back(0);
    }

    // Counts the number of numbers  the subscriber node recieves from
    // the puplisher node.  This value resets after a max value of 50.
    numbersReceived = 0;
    
  }

  
  void randomNumListner::
  randomNumTopicCallback(const std_msgs::Float64::ConstPtr& msg){

    int curBinCounter;
    int histogramBinIndex;

    
    // Recives a ROS message, in this case is a float value btw 0 and 1.
    //ROS_INFO("%f", msg->data);
    //fprintf(stderr, "dbg: randomNumTopicCbk: recived value=%f", msg->data);
    
    
    // Create a histogram of the numbers.
    histogramBinIndex = floor(msg->data / 0.1);
    //fprintf(stderr, ": histogramBinIndex=%d\n", histogramBinIndex);

    numbersReceived++;

    
    curBinCounter = histogramBin[histogramBinIndex];
        
    histogramBin.at(histogramBinIndex) = ++curBinCounter;
    
    //fprintf(stderr, "dbg: randomNumTopicCbk: histogramBin.at(%d)=%d\n",
    //	    histogramBinIndex, histogramBin.at(histogramBinIndex));

    
    // Printout the histogram.
    //
    // There are 10 bins, representing 0.1 each. between 0 and 1.
    fprintf(stderr, "Current Histogram: [itteration %d]\n", numbersReceived);
    for (int i=0; i<numBins; i++){
      fprintf(stderr, "Bin %.1f: ", (i*0.1));
      for(int j=0; j<histogramBin.at(i); j++){
    	fprintf(stderr, "*");
      }
      if ( (numbersReceived % 50) == 0 ){
	// Total number of values recieved is a factor of 50, so every
	// 50th number received.
	//
	// Show the percentage  of numbers out of  all numbers recieved,
	// foreach bin.
      	fprintf( stderr, " %d%%",
		 ((histogramBin.at(i) * 100) / numbersReceived) );
      }
      fprintf(stderr, "\n");
    }
    
    

    
  } // void randomNumListner::
    // randomNumTopicCallback(const std_msgs::Float64::ConstPtr& msg){
  
} // data randomNum_node{

