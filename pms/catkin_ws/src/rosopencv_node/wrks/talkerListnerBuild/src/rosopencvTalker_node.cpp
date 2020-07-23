#include "rosopencv_node/rosopencvTalker.h"



int main(int argc, char **argv){

  // Set up ROS.
  ros::init(argc, argv, "rosopencvTalker");
  ros::NodeHandle nh;
  
  // eg. Create a new node_example::Talker object.
  //
  //     node_example::ExampleTalker node(nh);
  //
  // Constructor declaration.
  rosopencv_node::rosopencvTalker node(nh);

  // Let ROS handle all callbacks.
  ros::spin();

  return 0;
} // end main()
