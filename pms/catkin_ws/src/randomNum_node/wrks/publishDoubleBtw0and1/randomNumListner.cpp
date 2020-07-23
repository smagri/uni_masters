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

  }

  
  void randomNumListner::
  randomNumTopicCallback(const std_msgs::Float64::ConstPtr& msg){

    // Recives a ROS message, in this case is a float value.
    ROS_INFO("%f", msg->data);
    fprintf(stderr, "randomNumTopicCbk: recived value=%f\n", msg->data);

  }

} // data randomNum_node{

