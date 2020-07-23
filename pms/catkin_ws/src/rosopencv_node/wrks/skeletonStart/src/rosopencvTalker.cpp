// This  program is  a  node  called rosopencvTalker.   A  node is  an
// executable connected  to the  ROS network.
#include <chrono>


#include "ros/ros.h"
//#include "std_msgs/String.h"
//#include "std_msgs/float32.h"
//#include "std_msgs/Float64.msg"
#include "std_msgs/Float64.h"


// for this to work must have: include_directories(include) in CMakeLists.txt
#include "rosopencv_node/rosopencvTalker.h"

using namespace std;


namespace rosopencv_node{

  // Constructor implementation
  rosopencvTalker::rosopencvTalker(ros::NodeHandle nh){
  }

  void rosopencvTalker::timerCallback(const ros::TimerEvent& event){
    
  }
  
}
