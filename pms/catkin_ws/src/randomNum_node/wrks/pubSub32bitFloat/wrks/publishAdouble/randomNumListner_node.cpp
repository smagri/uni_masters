#include "randomNum_node/randomNumListner.h"


int main(int argc, char **argv){

  // Set up ROS.
  ros::init(argc, argv, "randomNumListner");
  ros::NodeHandle nh;

  // eg. Create a new node_example::Talker object.
  //     node_example::ExampleListener node(nh);
  // eg. Create a new node_example::Talker object.
  //     voice_node::voiceSimpleSub node(nh);
  randomNum_node::randomNumListner node(nh);  


  // Let ROS handle all callbacks.
  ros::spin();


  return 0;
} // end main()
