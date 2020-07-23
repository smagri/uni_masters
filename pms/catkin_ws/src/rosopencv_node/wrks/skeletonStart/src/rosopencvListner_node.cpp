#include "rosopencv_node/rosopencvListner.h"


int main(int argc, char **argv){

  // Set up ROS.
  ros::init(argc, argv, "rosopencvListner");
  ros::NodeHandle nh;

  // eg. Create a new node_example::Talker object.
  //     node_example::ExampleListener node(nh);
  // eg. Create a new node_example::Talker object.
  //     voice_node::voiceSimpleSub node(nh);
  rosopencv_node::rosopencvListner node(nh);  


  // // Let ROS handle all callbacks.
  // ros::spin();


  return 0;
} // end main()
