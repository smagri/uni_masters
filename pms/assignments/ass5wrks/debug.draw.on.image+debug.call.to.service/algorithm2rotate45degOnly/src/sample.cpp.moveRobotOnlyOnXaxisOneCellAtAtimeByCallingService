// smagri additions:

#include <time.h>


#include "ros/ros.h"

#include <geometry_msgs/Twist.h>

#include "std_msgs/String.h"
#include "gazebo_msgs/ModelStates.h"
#include "tf/transform_datatypes.h"

#include "sensor_msgs/LaserScan.h"
#include "nav_msgs/Odometry.h"

#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>

#include "a3_help/RequestGoal.h"

#include <cstdio> // use C functions eg fprinf()

#include <sstream>
#include <iostream>
#include <string>

#include <map>
#include <thread>
#include <chrono>
#include <deque>
#include <mutex>
#include <random>

namespace enc = sensor_msgs::image_encodings;

/**
 * This node shows some connections and publishing images
 */


// class GazeboRetrive inherits from a3_help::RequestGoal class
//
class GazeboRetrieve : public a3_help::RequestGoal {

  ros::NodeHandle nh_;
  image_transport::ImageTransport it_;
  image_transport::Publisher image_pub_;
  ros::Publisher cmd_vel_pub_;
  ros::Subscriber sub1_;
  ros::Subscriber sub2_;
  image_transport::Subscriber sub3_;
  cv_bridge::CvImagePtr cvPtr_;
  ros::ServiceServer service_;
  ros::ServiceClient client_;


  int count_;//! A counter to allow executing items on N iterations
  double resolution_;//! size of OgMap in pixels

  struct DataBuffer
  {
    std::deque<geometry_msgs::Pose> poseDeq;
    std::deque<ros::Time> timeStampDeq;
    std::mutex buffer_mutex_;
  };
  DataBuffer buffer;//! And now we have our container

  struct ImageDataBuffer
  {
    std::deque<cv::Mat> imageDeq;
    std::deque<ros::Time> timeStampDeq;
    std::mutex buffer_mutex_;
  };
  ImageDataBuffer imageBuffer;//! And now we have our container


public:
  GazeboRetrieve(ros::NodeHandle nh)
    : nh_(nh), it_(nh)
  {
    sub1_ = nh_.subscribe("odom", 1000, &GazeboRetrieve::odomCallback,this);

    // .orig:
    //  sub2_ = nh_.subscribe("scan", 10, &GazeboRetrieve::laserCallback,this);
    //
    // local_map node uses parameter _local_map/scan:=/base_scan_1
    //					Node/Topic/SubTopic
    //
    // So  the following  is  required to  activate the  laserCallback()
    // callback fn.
    //
    sub2_ = nh_.subscribe("base_scan_1",
			  10, &GazeboRetrieve::laserCallback,this);
    image_transport::ImageTransport it(nh);
    sub3_ = it.subscribe("map_image/full", 1,
			 &GazeboRetrieve::imageCallback,this);

    // Publishing an image ... just to show how.
    image_pub_ = it_.advertise("test/image", 1);

    // Allowing an incoming service.
    //
    // Service name = request_goal
    // Callback/method/fn is requestGoal()
    // Works very similar to how the subscribe() method works
    // Service Object = service_
    //
    // Here the service  server is created and advertised  over ROS, the
    // string  name  of  the  service  is  called  "request_goal".   And
    // callback fn pointer is &GazeboRetrieve::requestGoal
    //
    service_ = nh_.advertiseService("request_goal",
    				    &GazeboRetrieve::requestGoal, this);
    
    
    // The client code(called  from cmdline or code),  or client node,
    // sends some data  called a request to the server  node and waits
    // for  a reply,  the response  data.  The  server node  sends the
    // response data after preforming an action, like moving the robot
    // here.
    //
    // Create  a client  object  for the  request_goal service.   This
    // needs to know the data type of the service and its name.
    // ie clientObject = node_handle.serviceClient<service_type>(service_name);
    client_ = nh_.serviceClient<a3_help::RequestGoal>("request_goal");
    
    
    // Publishing to cmd_vel topic, thus moving the robot.
    cmd_vel_pub_ = nh_.advertise<geometry_msgs::Twist>("/cmd_vel", 1);
    
    // Below  is  how to  get  parameters  from command  line,  on
    // command line they need to be _param:=value
    //
    ros::NodeHandle pn("~");
    double mapSize;
    double resolution;
    pn.param<double>("map_size", mapSize, 20.0);
    pn.param<double>("resolution", resolution_, 0.1);

    count_ =0;
    cv::namedWindow("view",CV_WINDOW_NORMAL);
    cv::startWindowThread();
    cv::waitKey(5);

  }

  ~GazeboRetrieve()
  {
    cv::destroyWindow("view");
  }

  
  void findClosestFrontier(int pixelX, int pixelY){

    /// Determines the frontier closest to the current robot location.
    
   // pixelX = current robot location x pixel
   // pixelY = current robot location y pixel
    
    
   // For TESTING location is origin of ogmap.
   // int x=100;
   // int y=100;
   //
   // int curCellVal = ((int) cvPtr_->image.at<uchar>(y,x));
   // fprintf(stderr, "curCellVal=%d\n", curCellVal);

    /*int curCellValue, x, y;
    
    if (curCellValue == 255);{
      // is free space
      x=pixelX; // local x,y are current robot pose in pixels
      y=pixelY;
    }
    
    // Map of frontierNodes map<key,value> sorted by key=x, with
    // corresponding value=y.
    std::map<int, int> frontierNode;
    

    curCellValue = ((int) cvPtr_->image.at<uchar>(y,x+1));
    if( (curCellValue != 255) || (curCellValue != 0) ){
    // Current cell is:
    //   !white=FS(FreeSpace) OR black=O(Obsticle)
    //   thus it's grey=UnKownSpace.
      frontierNode.insert(y, x); // store this frontier node
      return; // no need to check other cells around (x,y)
    }
    curCellValue = ((int) cvPtr_->image.at<uchar>(y,x-1));
    if( (curCellValue != 255) || (curCellValue != 0) ){
      frontierNode.insert(y, x);
      return;
    }

    
    curCellValue = ((int) cvPtr_->image.at<uchar>(y+1,x));
    if( (curCellValue != 255) || (curCellValue != 0) ){
      frontierNode.insert(y, x);
      return;
    }
    curCellValue = ((int) cvPtr_->image.at<uchar>(y-1,x));
    if( (curCellValue != 255) || (curCellValue != 0) ){
      frontierNode.insert(y, x);
      return;
    }

    
    curCellValue = ((int) cvPtr_->image.at<uchar>(y+1,x-1));
    if( (curCellValue != 255) || (curCellValue != 0) ){
      frontierNode.insert(y, x);
      return;
    }
    curCellValue = ((int) cvPtr_->image.at<uchar>(y-1,x-1));
    if( (curCellValue != 255) || (curCellValue != 0) ){
      frontierNode.insert(y, x);
      return;
    }

    
    curCellValue = ((int) cvPtr_->image.at<uchar>(y+1,x+1));
    if( (curCellValue != 255) || (curCellValue != 0) ){
      frontierNode.insert(y, x);
      return;
    }
    curCellValue = ((int) cvPtr_->image.at<uchar>(y-1,x+1));
    if( (curCellValue != 255) || (curCellValue != 0) ){
      frontierNode.insert(y, x);
      return;
    }
    */
      
  } // end: findClosestFrontier()

  
  
  bool requestGoal(a3_help::RequestGoal::Request  &req,
		   a3_help::RequestGoal::Response &res)
  {
    // RequestGoal, request_goal service, callback fn.

    // This callback function does not return till all its contents
    // are executed.

    // ???
    // 'rosservice list' outputs /a3_help/request_goal
    // a3_help is the package name and request_goal is the serice name.
    //
    // 'rossrv show /a3_help/request_goal'
    // Lists the member stuctures of the service, in this case:
    //

    // Current goal in world/global coordinates on OgMap are req.x,
    // req.y, req.angle???
    //
    // From service RequestGoal.srv:
    //
    // original:
    // req struct is: int64 x,int64 y,(should be float32 from laserCallback()??)
    // res struct is: bool ack. 
    //
    //
    // ROS msg types in c++: (see http://wiki.ros.org/msg)
    //
    // x,y,angle are float32 from:
    // /opt/ros/indigo/include/sensor_msgs/LaserScan.h
    // OR
    // /opt/ros/indigo/share/sensor_msgs/msg/LaserScan.msg
    //
    // built in type float32 = float
    // built in type float64 = double, ie double precision floating point.
    //
    // However, 'rosmsg show geometry_msgs/Twist' ouputs:
    // float64 as x,y,z, angle x, angle y, angle z.
    //
    // in laserCallback() x,y,angle,scanTime float32 values are cast as float64.
    // so float64=float32 done here is safe.
    //
    // This cast is done due to geometry_msgs/Twist messages require a
    // double or  float64 for x,y,angle.   These messages are  used to
    // move the robot below.
    //
    // see 'rosmsg show geometry_msgs/Twist'
    //
    // Consequently,  our RequestGoal.srv  should contain  float64 for
    // x,y,angle,scanTime


    fprintf(stderr, "dbg: in requestGoal() service callback fn\n");

// LATER: need to fix this, causes bad compilation erros.
//    
//    ROS_INFO("request: x=%f, y=%f, angle=%f, timeBtwScans", 
//	     req.x, req.y, req.angle, req.scanTime);
    
    // Moving the Robot to its new goal (req.x, req.y, req.angle):
    // this is specified in the service client code that calls this
    // callback function.
    //
    geometry_msgs::Twist robot_base_cmd;

    // Sets the loop to publish at a rate of 10Hz.
    // ros::Rate rate(10);
    //
    // NOTE: maybe !need while loop as this callback is called by a
    // node publishing to the scan topic, thus giving us a new robot
    // pose, used to move the robot to a new/next location.
    //
    //while(nh_.ok()){
    // Always  returns true  unless it  receives a  command to  shut
    // down, either  by using the  'rosnode kill' command or  by the
    // user issuing cntrl-C in the terminal.

    // All other linear and angular vector component values are = 0.
    //
    // rviz  should  show  pose  of  robot  at  (x,y)=(0,0)  and
    // angle=yaw changes by 45  degree incremnts.  Note that the
    // angle wobbles as expected, pure persuit algorithim should
    // fix this.   Expand the view  as big as possible  for best
    // view.
    //
    double deltaX, deltaY,  deltaAngle;
    //
    // Robot position  is always at  (0, 0) meters ie  center of
    // ogMap.
    //deltaX = deltaY = 0;
    //
    // Robot moves  along the x-axis,  thus is always at  (x, 0)
    // metres, from the centre of the ogMap.
    //
    // There are errors/wobbles in the x-axis movement.
    //
    deltaX = 1.0; // movement along the x-axis, 1 is 1 cell at a time,
		  // thus 0.1m at a time.
    //deltaX = 0.1; // moves 10 times in one cell.
    deltaY = 0.0; // no movement alonge the y-axis
    //
    // yaw or rotation about the z-axis
    //
    // M_PI is type double, M_PI1  is long double; or maybe use:
    // pi  =  2*acos(0.0) as  it's  more  portable, and  may  be
    // combined  with  templates  to future  proof  protability.
    // deltaAngle = (45 * (M_PI / 180)); // 45 deg to radians
    //const double pi = 2*acos(0.0);
    //deltaAngle = (45 * (pi/180));
    //
    // Otherwise this is 0 degrees/radians.
    const double pi = 2*acos(0.0);
    double angleDegrees = 0.0;
    deltaAngle = (angleDegrees * (pi/180)); // no movement or rotation
					    // about the z-axis
	    
    // Move in the x y plane, relative to the centre of ogMap.???
    robot_base_cmd.linear.x = req.x + deltaX;
    robot_base_cmd.linear.y = req.y + deltaY;
    //
    // Turn about the z axis.
    robot_base_cmd.angular.z = req.angle + deltaAngle;
      
    // Publish  the assembled  command,  ie send  the  command to  the
    // robot, which gets the robot to move to the new position.
    cmd_vel_pub_.publish(robot_base_cmd);

    // Delays untill it is time to send another robot_base_cmd
    // message.  ros::spinOnce(); // ie allow processing of
    // incoming messages. needed???
    // rate.sleep(); }

    // Notes to self???:
    //
    //
    // Determine   closest   point   to  robot,   perhaps   from   deque
    // laserCallback() closest point ranger value.
    //
    // Or from the req.x, and req.y  values passed in here.  Where these
    // values  are the  co-ordinates of  the next  frontier node  on the
    // ogMap.
    //
    // Move robot there.
    //
    //
    // A call  to this request_goal  service returns an  indication of
    // success or failure of this callback fn.
    //
    res.ack = true;
    // LATER: How to i setup res.ack = false.
    ROS_INFO("sending back response: [%d]", res.ack);

    return res.ack;
  }

  void odomCallback(const nav_msgs::OdometryConstPtr& msg)
  {
    // Let's get the pose out from odometry message.
    //
    // REMEBER: on command line you can view entire msg as:
    // rosmsg show nav_msgs/Odometry
      
    // Each time ROS publishes a  new Odometry message, that is data
    // from the  robot's motion sensors,  determine the pose  of the
    // robot.  Pose  being the  position and  rotation of  the robot
    // relative to a coordinate system.
    //
    // Save the  poses and  the time  at which  they occured  into a
    // deque.
    //

    // NOTE: A callback fn should consume a minimum amount of time.
    
    fprintf(stderr, "dbg: in odomCallbak() fn\n");

    geometry_msgs::Pose pose=msg->pose.pose;
    buffer.buffer_mutex_.lock();
    buffer.poseDeq.push_back(pose);
    buffer.timeStampDeq.push_back(msg->header.stamp);

    // // Print current Pose, ie robot position and orientation.
    // yaw = tf::getYaw(pose.orientation);
    // x = pose.position.x;
    // y = pose.position.y;
    // ROS_INFO("odomCallback: %f: x=%.2f, y=%.2f, yaw=%.2f degrees\n",
    // x, y, yaw);
    
    buffer.buffer_mutex_.unlock();

    // This delay slows the loop down for the sake of readability
    std::this_thread::sleep_for (std::chrono::milliseconds(10));

  }



  void laserCallback(const sensor_msgs::LaserScanConstPtr& msg)
  {
    //! Below sample cicrulates through the scan and finds closest
    //! point to robot.

    // local_map node uses parameter _local_map/scan:=/base_scan_1
    //					Node/Topic/SubTopic
    // So you need to subscribe to /base_scan_1 to activate this callback.
    //
    fprintf(stderr, "dbg: in laserCallbak() fn\n");

    // LaserScan is from a planar laser range-finder.
    
    // d is radius or distance to the obstacle from the current
    // robot position.  The closest point sits at the end of this
    // radial distance vector.
    //
    // angle is angle is float32 from sensor_msgs/LaserScan.msg
    // x = d cos(angle)
    // y = d sin(angle)
    //
    // /opt/ros/indigo/share/sensor_msgs/msg/LaserScan.msg says: x, y,
    // angle and range values are float32's or floats according to:
    // http://wiki.ros.org/msg
    //
    // Units from/opt/ros/indigo/include/sensor_msgs/LaserScan.h indicate
    // x,y range values in metres and angle in radians.
    //
    // This has implications for requestGoal() callback function.
    //
    // Casting here of float32(float) to float64(double) doesn't loose
    // info, so ok.
    double closest_point=msg->range_max;
    double angle=0;
    double x,y;
    for (unsigned int idx=0 ; idx < msg->ranges.size() ; idx++){
      if(msg->ranges.at(idx)<closest_point){
	closest_point=msg->ranges.at(idx);
	angle=msg->angle_min+(idx*msg->angle_increment);
      }
    }
    // Here timeLaser is set by executing the Time(double t) constructor???
    //double timeLaser;
    //ros::Time ((double) timeLaser) = msg->header.stamp;
    ros::Time timeLaser = msg->header.stamp;
    
    x = closest_point * cos(angle);
    y = closest_point * sin(angle);

    // Hard to make work:
    //fprintf(stderr, "%lf Laser: [d, angle, x, y]=[%lf, %lf, %f, %lf]\n",
    //timeLaser, closest_point, angle, x, y);
    // This delay slows the loop down for the sake of readability.
    //
    //
    // 
    // cout is buffered so use fprintf() above(hard to make work) or
    // its equivalent in c++ being std::err:
    //
    std::cerr << timeLaser
	      << " Laser: [d, theta, x, y]=["
	      << closest_point <<","<< angle << "," << x << "," << y << "]"
	      << std::endl;
    
    std::this_thread::sleep_for (std::chrono::milliseconds(10));

  } // end: laserCallback()

  
  void imageCallback(const sensor_msgs::ImageConstPtr& msg)
  {
    //! Below code pushes the image and time to a deque, to share
    //! across threads.

    fprintf(stderr, "dbg: in imageCallbak() fn\n");
    
    // Each  time ROS  publishes  a new  ogMap as  an  image on  the
    // "map_image/full" topic(see  map_to_mage_node.cpp), which this
    // node subscribes to:
    //
    // Save the  images and the  time at  which they occured  into a
    // deque.
    //
      
    // Also,  map_to_image_node.cpp publishes  to "map_image/full"
    // topic  and   this  node,  sample.cpp,  subscribes   to  the
    // "map_image/full"  topic.  See  rosocv_node/rosocvTalker.cpp
    // and  rosocv_node/rosocvListner.cpp  for example  code  that
    // does this.	

    try
    {
      if (enc::isColor(msg->encoding))
	cvPtr_ = cv_bridge::toCvCopy(msg, enc::BGR8);
      else
	cvPtr_ = cv_bridge::toCvCopy(msg, enc::MONO8);
    }
    catch (cv_bridge::Exception& e)
    {
      ROS_ERROR("cv_bridge exception: %s", e.what());
      return;
    }

    imageBuffer.buffer_mutex_.lock();
    imageBuffer.imageDeq.push_back(cvPtr_->image);
    imageBuffer.timeStampDeq.push_back(msg->header.stamp);
    if(imageBuffer.imageDeq.size()>2){
      imageBuffer.imageDeq.pop_front();
      imageBuffer.timeStampDeq.pop_front();
    }
    imageBuffer.buffer_mutex_.unlock();

  }



  
  void seperateThread() {
    /**
     * The below loop runs until ros is shutdown, to ensure this
     * thread does not remain a zombie thread.
     *
     * The loop locks the buffer, checks the size
     * And then pulls items: the pose and timer_t
     * You can think if these could have been combined into one ...
     */

    fprintf(stderr, "dbg: in seperateThread() fn\n");
    
    double yaw,x,y;
    /// The below gets the current Ros Time
    ros::Time timeOdom = ros::Time::now();
    ros::Time timeImage = ros::Time::now();;
    cv::Mat image;


    while (ros::ok()) {
      int deqSz =-1;

      // Only  access pose  buffer and  imageBuffer contents  when the
      // deques in  them are  not empty,  that is  when we  have robot
      // poses and ogMap images available.
      //
      // Mutex locking  is required for  access to the deques  as this
      // thread shares  them with the  main thread(or other  theads if
      // they  exist).  The  odomCallback  and imageCallback  callback
      // functions  that access  these deque's  are called  within the
      // main thread.
      //
      // The  main thread  allows aquiring  of robot  related data  in
      // realtime.  This thread, seperateThread(), does the processing
      // of  this  data in  non-realtime.   Just  when the  system/cpu
      // schedular allows it.
      //
      buffer.buffer_mutex_.lock();
      deqSz = buffer.poseDeq.size();
      if (deqSz > 0) {
	geometry_msgs::Pose pose=buffer.poseDeq.front();
	yaw = tf::getYaw(pose.orientation);
	x = pose.position.x;
	y = pose.position.y;
	timeOdom = buffer.timeStampDeq.front();
	buffer.poseDeq.pop_front();
	buffer.timeStampDeq.pop_front();
      }
      buffer.buffer_mutex_.unlock();

      //! Lock image buffer, take one message from deque and unlock it
      imageBuffer.buffer_mutex_.lock();
      if(imageBuffer.imageDeq.size()>0){
	image = imageBuffer.imageDeq.front();
	timeImage = imageBuffer.timeStampDeq.front();
	imageBuffer.imageDeq.pop_front();
	imageBuffer.timeStampDeq.pop_front();
      }
      imageBuffer.buffer_mutex_.unlock();

      // Let's  do   something  with  the  current   pose  and  opencv
      // image/ogMap; on every 100 iterations.
      //
      if (count_>100){
	count_=0;
	
	if(!image.empty()){
	  cv::Mat rgbImage;
          // Convert  image  from  on   color  space  to  another,  ie
	  // image->rgbImage.
	  cv::cvtColor(image, rgbImage, CV_GRAY2RGB);
	  
	  if (image.rows > 60 && image.cols > 60){
	    // Draw a red dot of tickness 7, at the centre of the
	    // ogMap image.
	    //

	    // Draw  a red  dot at  the  x/y metres  positon from  the
	    // centre  of  the  ogMap  image.   This  encompasses  the
	    // orientation of the robot as  theta is the angle between
	    // the radial line  at to the x/y position an  the x axis.
	    // That is x=r*cos(theta) and y=r*sin(theta)
	    //
	    cv::circle(rgbImage,
	     	       cv::Point((x/resolution_)+(image.rows/2),
	    			 (y/resolution_)+(image.cols/2)),
	     	       10, CV_RGB(255,0,0),-1);

	    // Draw a blue dot at the centre of the ogMap image.
	    cv::circle(rgbImage,
		       cv::Point((image.rows/2), (image.cols/2)),
		       7, CV_RGB(0,0,255),-1);

	    // NOTE: The ogMap moves with  the robot at its centre and
	    // that the  velocity Forward  and Back commands  move the
	    // robot  on the  radial  line of  it's orientation.   The
	    // robot is always at the  centre of the ogMap.  Of course
	    // a non-zero angular velocity  changes the orientation of
	    // the robot and thus the orientation of the ogMap image.
	    
	    // Draw a red line from centre of ogMap image to the right
	    // most edge of it. Also placing blue dots on both ends of
	    // the line.
	    //
	    cv::circle(rgbImage,
	    	       cv::Point((image.rows/2), (image.cols/2)),
	     	       2, CV_RGB(0,0,255), -1);
	    cv::circle(rgbImage,
	     	       cv::Point(image.rows, image.cols),
	     	       4, CV_RGB(0,0,255), -1);
	    cv::line(rgbImage, 
	     	     cv::Point((image.rows/2), (image.cols/2)),
	     	     cv::Point(image.rows, image.cols),
	     	     CV_RGB(255,0,0), 1);
	    //cv::circle(rgbImage,
	    //       cv::Point((image.rows/2), (image.cols/2)),
	    //	       7, CV_RGB(0,0,255),-1);

	  }


	  // Determine the closest frontier to the robot and move it there.

	  // findClosestFrontier(int pixelX, int pixelY);
    
    
	  // Need to store these closest points in a deque for processing in
	  // seperateThread() later???


	  // Call  the  service_   object/service  callback  function,
	  // requestGoal.   This  is  the service  cleint  code.   The
	  // callback   function   moves   the  robot   to   its   new
	  // location/goal (req.x,  req.y) in the x,y  plane.  It does
	  // not return  till it has complely  executed this function,
	  // that is  till the  robot is at  its goal.   This callback
	  // function should be called about every ten seconds.
	  //
	  double pixelX = 1.0;
	  double pixelY = 0.0;

	  // Class,   GazeboRetrieve,    derives   from    the   class
	  // a3_help::RequestGoal,  hence  all  the  member  data  and
	  // methods   of   a3_help::RequestGoal  are   available   to
	  // GazeboRetrieve.
	  //
	  a3_help::RequestGoal::Request goalReq;
	  a3_help::RequestGoal::Response goalRes;

	  // The next required goal/pose for the robot.
	  goalReq.x = pixelX;
	  goalReq.y = pixelY;
	  //
	  const double pi = 2*acos(0.0); // should be float/double??
	  double angleDegrees = 0.0;
	  goalReq.angle = (angleDegrees * (pi/180)); // angle in radians
	  //
	  goalReq.scanTime = 10; // time between scans in seconds


	  //a3_help::RequestGoal::Request(goalReq, goalRes);
	     
	  // Actually  call  the  request_goal  service,  which  won't
	  // return till  the service  is complete,  that is  till the
	  // robot has moved to the location.
	  client_.call(goalReq, goalRes);
	  	  
	  if (goalRes.ack){
	    // goalRes.ack == true;
	    fprintf(stderr, "client called service, service SUCCEDED\n");
	    ROS_INFO_STREAM("client called service, service SUCCEDED");
	  }
	  else{
	    // goalRes.ack == false;
	    fprintf(stderr, "client called service, service FAILED\n");
	    ROS_INFO_STREAM("client called service, service FAILED");
	  }


	  
	  // Output current robot location/pose(position and orientatn):
	  //
	  //fprintf(stderr, "dbg: seperateThread:"
	  //"%lf Odom: [x, y, yaw] = [%lf, %lf, %lf]\n",
	  //timeOdom, x, y, yaw);
	  //
	  // fprintf(stderr, "dbg: seperateThread:"
	  //	  " Odom: (x/resoln_, y/resoln_) metres from ogMap centre:"
	  //	  " pos [x, y]=[%lf,%lf]\n", (x/resolution_), (y/resolution_) );
	  //
	  //fprintf(stderr, "dbg: seperateThread:"
	  //	  " Odom: Pixel coordinates on the ogMap for this"
	  //	  " pos [x, y]=[%lf, %lf]\n",
	  //	  (x/resolution_)+(image.rows/2),
	  //	  (y/resolution_)+(image.cols/2) );
	  //
	  //
	  // fprintf(stderr,.. with timeOdom is hard to make work.
	  //
	  // std::cout is bufferd but  std::cerr is not.  std::cerr is
	  // the eqivalent of stderr in C.
	  //
	  std::cerr << timeOdom
	  	    << " Odom: [x,y,yaw]=["
	  	    << x << "," << y << "," << yaw << "]"
	  	    << std::endl;
	  
	  std::cerr << " x/y m/resoln_ from ogMap centre: pos [x,y]=["
	  	    << (x/resolution_) << "," 
	  	    << (y/resolution_) << "] "
	  	    << std::endl 
	  	    << " Pixel coordinates on the ogMap for this pos [x,y]=[" 
	  	    << (x/resolution_)+(image.rows/2) << ","
	  	    << (y/resolution_)+(image.cols/2) << "]"
	  	    << std::endl;

	  
	  // Determine closest frontier to current robot location.
	  //
	  // findClosestFrontier(pixelX, pixelY);
	  //
	  // Move robot to closest Frontier.
	  //
	  // Use laserscan deque to do this???

		    
	  // Update GUI Window
	  //
	  //cv::imshow("view", image);
	  //
	  // Display coloured image.
	  cv::imshow("view", rgbImage);
	  cv::waitKey(5);

	  // Convert cvImage to ROS image message.  To use with cvPtr_
	  // in imageCallback()
	  //
	  //cv::imshow("view", cvPtr->image);
	  //cv::waitKey(3);
	  sensor_msgs::ImagePtr msg
	    = cv_bridge::CvImage(std_msgs::Header(),
				 "rgb8", rgbImage).toImageMsg();
	  image_pub_.publish(msg);

	}
	std::this_thread::sleep_for (std::chrono::milliseconds(10));
      }
      else{
	count_++;
	// This delay slows the loop down for the sake of readability
	std::this_thread::sleep_for (std::chrono::milliseconds(10));
      }

    } // End: while(ros::ok())
    
  } // end: seperateThread()

  
}; // end: GazeboRetrive class definition.



int main(int argc, char **argv)
{


  /**
   
   * The ros::init()  function needs to see  argc and argv so  that it
   * can  perform  any ROS  arguments  and  name remapping  that  were
   * provided at  the command  line.  For programmatic  remappings you
   * can  use a  different version  of init()  which takes  remappings
   * directly, but  for most  command-line programs, passing  argc and
   * argv is the  easiest way to do it.  The  third argument to init()
   * is the name of the node.
   *
   * You must call one of the versions of ros::init() before using any
   * other part of the ROS system.
   */
  ros::init(argc, argv, "gazebo_retrieve");

  /**
   * NodeHandle is the main access point to communications with the
   * ROS system.  The first NodeHandle constructed will fully
   * initialize this node, and the last NodeHandle destructed will
   * close down the node.
   */
  ros::NodeHandle nh;

  /**
   * Let's start seperate thread first, to do that we need to create
   * object and thereafter start the thread on the function desired
   */
  std::shared_ptr<GazeboRetrieve> gc(new GazeboRetrieve(nh));
  std::thread t(&GazeboRetrieve::seperateThread,gc);

  /**
   * ros::spin() will enter a loop, pumping callbacks.  With this
   * version, all callbacks will be called from within this thread
   * (the main one).  ros::spin() will exit when Ctrl-C is pressed, or
   * the node is shutdown by the master.
   */
  ros::spin();

  /**
   * Let's cleanup everything, shutdown ros and join the thread
   */
  ros::shutdown();
  t.join();

  return 0;
}

