#include "std_msgs/Float32.h"

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
  randomNumTopicCallback(const std_msgs::Float32::ConstPtr& msg){

    ROS_INFO("%f", msg->data);
    fprintf(stderr, "randomNumTopicCbk: recived value=%f\n", msg->data);

  }

} // namespace randomNum_node{

