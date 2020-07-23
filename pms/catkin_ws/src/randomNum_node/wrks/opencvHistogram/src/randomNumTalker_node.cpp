#include "randomNum_node/randomNumTalker.h"


int main(int argc, char **argv){

  // Set up ROS.
  ros::init(argc, argv, "randomNumTalker");
  ros::NodeHandle nh;

  // eg. Create a new node_example::Talker object.
  //
  //     node_example::ExampleTalker node(nh);
  //
  // eg. voice_node::voiceSimplePub node(nh);
  randomNum_node::randomNumTalker node(nh);

  // Let ROS handle all callbacks.
  ros::spin();

  return 0;
} // end main()
