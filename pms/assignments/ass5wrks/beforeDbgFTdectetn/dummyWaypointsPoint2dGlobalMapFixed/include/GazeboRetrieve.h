#ifndef GAZEBORETRIVE_H
#define GAZEBORETRIVE_H

#include <ros/ros.h>

/* #include "gazebo_msgs/ModelStates.h" */
/* #include "tf/transform_datatypes.h" */

#include <sensor_msgs/LaserScan.h>
//#include "nav_msgs/Odometry.h"

/* #include <image_transport/image_transport.h> */
/* #include <opencv2/highgui/highgui.hpp> */
#include <cv_bridge/cv_bridge.h>



#include <a3_help/RequestGoal.h> // sm declaring namespace a3_help




// Declaration of GazeboRetrive class.
class GazeboRetrieve: public a3_help::RequestGoal{
  
public:
  // Public members are accessible from outside this class.

  // Declare methods:

  // Moves the robot to (req.x, req.x, angle)
  bool requestGoal(a3_help::RequestGoal::Request  &req,
		   a3_help::RequestGoal::Response &res);

  // Extracs the robot pose from the odometry msg and stores it and
  // timestamp in deques, to share accross threads.
  void odomCallback(const nav_msgs::OdometryConstPtr& msg);
    
  // Circulates through the scan and finds closest point to the robot.
  void laserCallback(const sensor_msgs::LaserScanConstPtr& msg);

  // Pushes the image and it's timestamp to a deques, to share accross
  // threads.
  void imageCallback(const sensor_msgs::ImageConstPtr& msg);

  // Processes laser, pose and image data.
  void seperateThread();

//cv_bridge::CvImagePtr cvPtr_; /// pointer to the current ogMap image

private:
// Private members are only accessible from within methods of the same class
    // This class has two integers to represent the sides of the rectangle
    // The trailing underscore is used to differentiate the member varibles
    // ..from local varibles in our code, this is not compulsary
    //int width_, height_;

};

#endif // GAZEBORETRIVE_H



