//
// smagri additions:
//
#include <time.h>
#include <vector>

// When set indicates code used for debuging in process of building program
//
//#define DEBUG



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

// // // attend to LATER: I think  this should be in class GazeboRetrive.h
// // //
// // /*!
// //  *  \ingroup   ac_shapre GazeboRetrive
// //  *  \brief     Class GazeboRetrive
// //  *  \details
// //  *  This class is a base class the GazeboRetrive Interface.\n
// //  *  \author    Simone Magri
// //  *  \version   1.0
// //  *  \date      2018
// //  *  \pre       none
// //  *  \bug 

// // All code perceeded by a LATER: sign for this class are tasks that need
// // to be attended to later.  They require further investigation and added
// // to the todo list for the code.

// //  *  \warning  



/// Class GazeboRetrive inherits from a3_help::RequestGoal.
///
/// That is, a3_help  is the ros node or package  name and RequestGoal
/// is the class name or type.
///
/// Also, this node shows some connections and publishing images.
///
///
///
/// Attend to LATER, Request & Responce structs:
///
/// 1) Should I move RequestGoal() into RequestGoal.h as member function.
///    This seems incorret as RequestGoal() seems a better fit to
///    GazeboRetrieve class.
///
/// 2) Leave as is but doxygen dosent work properly, where RequtestGoal.h
///    declares a class RequestGoal and RequestGoal() is defined in
///    GazeboRetrieve class.
///
/// 3) Define Request and Responce stucts as part of GazeboRetrieve class and
///    remove the need for RequestGoal.h.
///
class GazeboRetrieve : public a3_help::RequestGoal {

  // LATER: These variables all need to be put in a GazeboRetrieve.h file.
  //
  ros::NodeHandle nh_; ///< ROS node object.
  
  image_transport::ImageTransport it_;
  image_transport::Publisher image_pub_; /// image publisher object

  /// Object of the /cmd_vel topic.
  //
  /// When  we publish to this topic we are moving the robot.
  ros::Publisher cmd_vel_pub_;

  /// Subscription object  for the odom topic.
  //
  /// The callback  function for this  object is odomCallback().
  ros::Subscriber sub1_;
  
  /// Subscription object for the base_scan_1 topic.
  //
  /// The callback function for this object is laserCallback().
  ros::Subscriber sub2_;

  image_transport::Subscriber sub3_; /// ogMap image subscriber object
  cv_bridge::CvImagePtr cvPtr_; /// pointer to the current ogMap image


  /// Object for the reqest_goal service.
  ///
  /// The callback function of this service is RequestGoal().
  ros::ServiceServer service_;

  /// Client object for the  reqest_goal service.
  //
  /// On defeniton creates service server and its advertising over ROS.
  ros::ServiceClient client_;


  // Summary doxygen documentation:
  //
  // method one: //!
  // method two: ///<
  //
  // I prefer method two.
  
  int count_; ///< A counter to allow executing items on N iterations.
  double resolution_; ///< Size of OgMap in pixels.

  /// The   buffer  for   the  current   robot  pose(ie   positon  and
  /// orientation) and  the time  at which it  occured.  The  pose and
  /// corresponding  times are  put into  seprate ques,  the ques  are
  /// filled by  the odomCallback()/thread  in realtime.  The  data is
  /// aquired  form robot  sensors.  The  mutex locks  are reqired  to
  /// access the ques  as they are shared by a  number of theads. This
  /// thread is spawned by the  ROS main thread.  The sepreateThread()
  /// thread is used to process this data.
  //
  struct DataBuffer
  {
    std::deque<geometry_msgs::Pose> poseDeq; ///< pose que
    std::deque<ros::Time> timeStampDeq; ///< timestamp que
    std::mutex buffer_mutex_; ///< mutex lock for buffer access syncronisation
  };
  DataBuffer buffer; //! And now we have our container

  
  /// The buffer for the current ogMap  image and the time at which it
  /// occured.   The  images  and  corresponding times  are  put  into
  /// seperate ques, the ques are filled by the imageCallback()/thread
  /// in realtime.  The  images are generated from  robot sensor data.
  /// The mutex lock is reqired to  access the ques as they are shared
  /// by a number  of theads.  This thread is spawned  by the ROS main
  /// thread.   The sepreateThread()  thread is  used to  process this
  /// data.
  //
  struct ImageDataBuffer
  {
    std::deque<cv::Mat> imageDeq; ///< image que
    std::deque<ros::Time> timeStampDeq; ///< timestamp que
    std::mutex buffer_mutex_; ///< mutex lock for buffer access
			      ///syncronisatetion.
  };
  ImageDataBuffer imageBuffer;//! And now we have our container

  

public:
  GazeboRetrieve(ros::NodeHandle nh)
    : nh_(nh), it_(nh)
  {

    // LATER: This becomes the main() like of this class.
    //
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
    ///  Subscription object for base_scan_1 topic.
    sub2_ = nh_.subscribe("base_scan_1",
			  10, &GazeboRetrieve::laserCallback,this);
    image_transport::ImageTransport it(nh);
    //
    // ???map_to_image_node.cpp  or   map_to_image  node   publishes  the
    // images(ie ogMaps) on the map_image/full  ros node topic.  So we
    // must subscribe to this topic to recieve the current ogMap.
    //
    // ???The imageCallback function is called  by ROS foreach ogMap image
    // produced by map_to_image_node.cpp.
    //
    // The imageCallback() is called each time something publishes to
    // the "map_image/full" topic.
    sub3_ = it.subscribe("map_image/full", 1,
			 &GazeboRetrieve::imageCallback,this);

    // Publishing an image ... just to show how.
    // image_pub_ = it_.advertise("test/image", 1);
    //
    // Object image_pub_ is used to publish to the "map_image/full" topic.
    image_pub_ = it_.advertise("map_image/full", 1);

    
    // Allows incoming service request_goal:
    //
    // Callback function/method is requestGoal()
    // Works very similar to how the subscribe() method works
    // Service Object = service_
    //
    // Here the service server is created and advertised over ROS, the
    // string  name  of the  service  is  called "request_goal".   And
    // callback function pointer is &GazeboRetrieve::requestGoal
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
    
    
    // Publishing to /cmd_vel topic, thus moving the robot.
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


  //  LATER:  These   member  functions   need  to   be  defined/class
  //  implemntation    created    for   class    GazeboRetrieve,    in
  //  GazeboRetrieve.cpp.   And  they  must   be  declared  as  member
  //  functions of class GazeboRetrieve in GazeboRetrieve.h.
  //
  //
  void findClosestFrontier(int pixelX, int pixelY){

    /// Determines the frontier closest to the current robot location.

    // Determining frontier algorithims vary, so a breif search of the
    // literature was made.  Pick two easy 'papers to read' or at lest
    // the one with the least difficult algorithm to have any cance of
    // success here.  If  this does not give the  result required then
    // search for  more papers.  Stop  reading when you  can determine
    // frontiers that align with the in class examples.
    //
    // Also, 'papers  to read'  means just scan  these papers  for the
    // relevent  material,  abstract,   conclusion,  intro,  detecting
    // frontiers sections.
    //
    // This may be a massive time sync if you waste too much time
    // reading non relevant material.
    
    
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

    // Summary doxygen documentation methods:
    //
    //
    // method one: /** 
    //               * RequestGoal, request_goal service, callback fn.
    //               */
    //
    // method two: /// RequestGoal, request_goal service, callback fn.
    //
    // method three: //! RequestGoal, request_goal service, callback fn.
    //
    // Preferred method is two method three.

    
    /// RequestGoal  is the  callback  function  for the  request_goal
    /// service.
    ///
    /// This callback function does not return till all code within it
    /// is  executed.  That  is there  is no  queuing of  calls(as per
    /// publishing  and subscribing  to ros  topics) to  this callback
    /// function.
    ///
    
    // ???
    // 'rosservice list' outputs /a3_help/request_goal
    // a3_help is the package name and request_goal is the serice name.
    //
    // 'rossrv show /a3_help/request_goal'
    // Lists the member stuctures of the service, in this case:
    //

    // Current goal in world/global coordinates on OgMap are req.x,
    // req.y, req.angle.
    //
    // From original service RequestGoal.srv:
    //
    // original:
    // req struct is: int64 x,int64 y
    // res struct is: bool ack. 
    //
    //
    // ROS msg types in c++: (see http://wiki.ros.org/msg)
    //
    // x,y,angle are float32 from:
    // /opt/ros/indigo/include/sensor_msgs/LaserScan.h
    // OR
    // /opt/ros/indigo/share/sensor_msgs/msg/LaserScan.msg
    // OR
    // 'rosmsg show sensor_msgs/LaserScan'
    //
    // showes range in metres, angle in radians, scan_time in seconds
    // and all these values are float32 types.
    //
    // built in type float32 = float
    // built in type float64 = double, ie double precision floating point.
    //
    // However, 'rosmsg show geometry_msgs/Twist' outputs:
    //
    // float64 as  x,y,z, angle x,  angle y,  angle z.
    //
    // So float32 to float64 cast in laserCallback() doesn't loose any
    // information.
    //
    // Consequently,  our RequestGoal.srv  should contain  float64 for
    // x, y, angle, scanTime


    fprintf(stderr, "dbg: in requestGoal() service callback fn\n");
    
    // LATER: need to fix this, causes bad compilation erros.
    //    
    //    ROS_INFO("request: x=%f, y=%f, angle=%f, timeBtwScans", 
    //	     req.x, req.y, req.angle, req.scanTime);

    
    /// It moves the robot to  its new goal (req.x, req.y, req.angle):
    /// the goal  is specified in  the service client code  that calls
    /// this  callback   function,  more   specifically  in   the  req
    /// structure.
    //
    geometry_msgs::Twist robot_base_cmd;
    
    /// The robot is moved in the x,y plane relative to the centre of
    /// the ogMap.
    //
    robot_base_cmd.linear.x = req.x;
    robot_base_cmd.linear.y = req.y;
    //
    // Turn about the z axis.
    robot_base_cmd.angular.z = req.angle;
    
    // Publish  the assembled  command,  ie send  the  command to  the
    // robot, which gets the robot to move to the new position.
    //
    // LATER: set req.ack here???
    cmd_vel_pub_.publish(robot_base_cmd);
    

    // Notes to self???:
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
    
    /// A call to  this request_goal service returns  an indication of
    /// success or  failure of  the robot move(ie  callback() function
    /// return value).
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
    
    fprintf(stderr, "dbg: in odomCallback() fn\n");

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
    //std::this_thread::sleep_for (std::chrono::milliseconds(10));

  }



  void laserCallback(const sensor_msgs::LaserScanConstPtr& msg)
  {
    //! Below sample cicrulates through the scan and finds closest
    //! point to robot.

    // local_map node uses parameter _local_map/scan:=/base_scan_1
    //					Node/Topic/SubTopic
    // So you need to subscribe to /base_scan_1 to activate this callback.
    //
    fprintf(stderr, "dbg: in laserCallback() fn\n");

    // LaserScan is from a planar laser range-finder.
    
    // d is radius or distance to the obstacle from the current
    // robot position.  The closest point sits at the end of this
    // radial distance vector.
    //
    // http://docs.ros.org/jade/api/sensor_msgs/html/msg/LaserScan.html
    //  and
    // 'rosmsg show sensor_msgs/LaserScan'
    //
    // sensor_msgs/LaserScan.msg says that all these parameters are of
    // float32/float type.  And all the units are SI units:
    //
    // angle in metres
    // x = d cos(angle) in radians
    // y = d sin(angle) in radians
    // scanTime in seconds
    // This has implications for requestGoal() callback function.
    //
    //
    // All these values are  float32/float types, not float64/doubles,
    // we  will _not_  loose  information  if we  cast  the floats  to
    // doubles here.  Double check LATER???
    //
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
    
    //std::this_thread::sleep_for (std::chrono::milliseconds(10));

  } // end: laserCallback()

  
  void imageCallback(const sensor_msgs::ImageConstPtr& msg)
  {
    ///! Below code pushes the image and time to a deque, to share
    ///! across threads.

    fprintf(stderr, "dbg: in imageCallback() fn\n");
    
    /// Each  time ros  publishes  a  new ogMap  as  an  image on  the
    /// "map_image/full"  topic this  callback  function is  executed.
    ///
    /// Here  map_to_mag_node   does  the  image  publishing   on  the
    /// "map_image/full" topic.  These images  are stored in the dques
    /// here in realtime.
    ///
    /// Save the images and the time at which generated in deques, for
    /// later processing across various threads.
    ///

    try
    {
      if (enc::isColor(msg->encoding))
	cvPtr_ = cv_bridge::toCvCopy(msg, enc::BGR8);
      else
	cvPtr_ = cv_bridge::toCvCopy(msg, enc::MONO8);
	//cvPtr_ = cv_bridge::toCvCopy(msg, "mono8");
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
    
        
    /// The main thread (main()) allows aquiring of robot related data
    /// in   realtime.   This   thread,  seperateThread(),   does  the
    /// processing  of  this  data  in non-realtime.   Just  when  the
    /// system/cpu schedular allows it.
    ///
    /// LATER: The processing involves???

    // LATER: seems to be starved by callback fn's, may need to reread
    // ass3 on theads.
    
    // LATER:  appears to  be called  only  once, thus  a black  image
    // should be displayed once and  stay as such.  But intermediately
    // the black  image is replace  by what I  think map_to_image_node
    // outputs, the current ogMap image.

    
    fprintf(stderr, "dbg: in seperateThread() fn\n");

    double yaw,x,y;
      
    /// The below gets the current Ros Time
    ros::Time timeOdom = ros::Time::now();
    ros::Time timeImage = ros::Time::now();;
    cv::Mat image; /// generic image container

    // The below loop runs until ros is shutdown, to ensure this
    // thread does not remain a zombie thread.
    //
    // The  loop locks  the buffer,  checks the  size.  And  then pulls
    // items: the pose  and timer_t. You can think if  these could have
    // been combined into one ...
    //

    while (ros::ok()) {
      int deqSz =-1;

      // Only access  pose buffer  and imageBuffer contents  when the
      // deques in  them are  not empty,  that is  when we  have robot
      // poses and ogMap images available.

      // Mutex locking  is required for  access to the deques  as this
      // thread shares  them with the  main thread(or other  theads if
      // they  exist).  The  odomCallback  and imageCallback  callback
      // functions  that access  these deque's  are called  within the
      // main thread.
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


      // laserCallback function  produces a  set of closest  points to
      // the robot.   That is closest  obstacle.  Get this  value from
      // the que and corresponding time stamp???
      //


      // NOTE, given test, all black image output:
      //
      // Let's  do   something  with  the  current   pose  and  opencv
      // image/ogMap image; on every 100 iterations.
      //
      //
      // When seperateThread() is called you  count to 100, each count
      // interleaved with a sleep(), at this stage.
      //
      // When count reaches  100 the currnet ogMap  image is displayed
      // in the view window.  For testing this is an all black image.
      //
      // If seperateThread()  only gets  called once, as  current code
      // execution  seems   to  show,  the  image   stays  black.   So
      // seperateThread() needs  to be called  more than once  for the
      // next ogMap realtime  image in the que to be  displayed in the
      // view window.
      //
      // With subsequent  calls to  seperateThread(), we count  to 100
      // again  before   we  display  the   new  image  in   the  view
      // window....etc
      

      if (count_>100){
	count_=0;
	
	if(!image.empty()){

#ifdef DEBUG_DRAW_ON_IMAGE

	  // No imageCallback() function initiated here though.
	  //
	  //
	  
	  cv::Mat rgbImage;

	  // Convert  image  from  one   color  space  to  another,  ie
	  // image->rgbImage.
	  cv::cvtColor(image, rgbImage, CV_GRAY2RGB);

	    // Draw  a red  dot at  the  x/y metres  positon from  the
	    // centre  of  the  ogMap  image.   This  encompasses  the
	    // orientation of the robot as  theta is the angle between
	    // the radial line  at to the x/y position an  the x axis.
	    // That is x=r*cos(theta) and y=r*sin(theta)
	    //
	    // The red dot is of relevative thisckness 10, at and at
	    // the centre of the ogMap image.
	    //
	    // The current  pose of  the robot  is retrieved  from the
	    // curret poseDeq pose.  (note: if the robot starts at the
	    // centre of  the ogMap are  all pose values are  equal to
	    // 0).
	    //
	    // x = pose.position.x;
	    // y = pose.position.y;
	    // yaw = tf::getYaw(pose.orientation);
	    //
	    cv::circle(rgbImage,
	     	       cv::Point((x/resolution_)+(image.rows/2),
	    			 (y/resolution_)+(image.cols/2)),
	     	       10, CV_RGB(255,0,0),-1);

	    // Draw a blue dot at the centre of the ogMap image of
	    // relative thickness 7.
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

	    // Display current updated ogMap.
	    cv::imshow("view", rgbImage);
	    cv::waitKey(5);
#endif


	  // Determine the closest frontier to the robot and move it there.
	  //
	  // findClosestFrontier(int pixelX, int pixelY);
	  //
	  // Update  the 2d  image vector  using the  values from  the
	  // laserScan closest point que.
	  //
	  //

	  // Update the  ogMap image  with the current  FT, UK,  FS, O
	  // elements.
	  //
	  // imageCallback() has been called before the images are put
	  // in  the deque,  hence the  images in  the deque  are then
	  // accessed by cvPtr. LATER:???
	  //  
	  // For testing set all  image pixels to black==(uchar 0).
	  //
	  //fprintf(stderr, "dbg: in seperateThread()1 fn\n");
	  for (int y = 0; y<cvPtr_->image.rows; y++){
	    for (int x = 0; x<cvPtr_->image.cols; x++){
	      cvPtr_->image.at<uchar>(y, x) = 0;
	    }
	  }
	    

	  // Convert  cvImage to  a  ros image  message to  facilitate
	  // updating the ogMap image.
	  //
	  // Publishing   a   ros    image   message   here   triggers
	  // imageCallback().   The  cvPtr_  is  used  to  access  the
	  // current ros image message in imageCallback().
	  //
	  // sensor_msgs::ImagePtr msg
	  //   = cv_bridge::CvImage(std_msgs::Header(),
	  //  			 "rgb8", image).toImageMsg();
	  // image_pub_.publish(msg);

  
	  
	  // Call  the  service_   object/service  callback  function,
	  // requestGoal.   This  is  the service  cleint  code.   The
	  // callback   function   moves   the  robot   to   its   new
	  // location/goal (req.x,  req.y) in the x,y  plane.  It does
	  // not return  till it has complely  executed this function,
	  // that is  till the  robot is at  its goal.   This callback
	  // function should be called about every ten seconds.
	  //
	  double pixelX = 0.0;
	  double pixelY = 0.0;
	  
	  // Class,   GazeboRetrieve,    derives   from    the   class
	  // a3_help::RequestGoal,  hence  all  the  member  data  and
	  // methods   of   a3_help::RequestGoal  are   available   to
	  // GazeboRetrieve.
	  //
	  a3_help::RequestGoal::Request goalReq;
	  a3_help::RequestGoal::Response goalRes;
	  
          // Value of pi:
          //
          // M_PI is type double, M_PI1  is long double; or maybe use:
          // pi  =  2*acos(0.0) as  it's  more  portable, and  may  be
          // combined  with  templates  to future  proof  protability.
          //
          const double pi = 2*acos(0.0); // should be float/double??


          // Testing moving the robot via a call to service request_goal.
          //
          //
	  int moveAlgorithm = 3; // don't run the following
				 // tests (algorithm 1 or 2)
	  if (moveAlgorithm  == 1){
	    // CASE1: Testing robot moving only along the x-axis:
	    //
	    // There are  errors/wobbles in  the x-axis movement,  as observed
	    // via rviz.
	    //
	    // Move along x-axis one cell at a time, is 0.1m at a time
	    double deltaX = 1;
	    //
	    // goalReq.x starts at 0 since the robot starts in the
	    // centre of the ogMap where (x,y) = (0,0).
	    goalReq.x = goalReq.x + deltaX;
	    goalReq.y = 0;
	    //
	    double angleDegrees = 0.0;
	    goalReq.angle = (angleDegrees * (pi/180)); // angle in radians
	    //
	    goalReq.scanTime = 10; // time between scans in seconds
	  }
	  else if (moveAlgorithm  == 2){
	    // CASE2: Testing robot moving  at 45 degree incremnts about
	    //        the z-axis.
	    //
	    // That is, angle=yaw changes by  45 degree increments.  Note that
	    // the angle  wobbles as expected, pure  persuit algorithim should
	    // fix this.  Expand the view as  big as possible in rvix for best
	    // view.
	    //
	    // The next  required goal/pose for  the robot, that  is, no
	    // movement  in the  x,y  plane, so  robot  stays at  (x,y)=
	    // (0,0), or cenre of ogMap.
	    goalReq.x = 0;  // for compeatness here
	    goalReq.y = 0;
	    //
	    double angle = 0;      // only initialised here
	    double deltaAngle = 0;
	    deltaAngle = deltaAngle + 45; // deltaAngle in degrees
	    deltaAngle = (deltaAngle * (pi/180)); // deltaAngle in radians
	    goalReq.angle =  goalReq.angle + deltaAngle; // angle in radians
	    //
	    goalReq.scanTime = 10; // time between scans in seconds
	  }

	  
	  // Actually  call  the  request_goal  service,  which  won't
	  // return till  the service  is complete,  that is  till the
	  // robot has moved to the location.
	  if ((moveAlgorithm==1) || (moveAlgorithm==2)){
	    client_.call(goalReq, goalRes);
	    
	    if (goalRes.ack){
	      // goalRes.ack == true;
	      ROS_INFO_STREAM("client call to service SUCCEDED");
	    }
	    else{
	      // goalRes.ack == false;
	      ROS_INFO_STREAM("client call to service FAILED");
	    }
	  }
	  

	  
	  // Output current robot location/pose(position and orientatn):
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

	  
	  // Using data  from the  laserscan deque update  the current
	  // map 2d vector, or image, and publish the new map into the
	  // "view"  window.  This  should  be the  same  as the  rviz
	  // image???  OR do this in another window instead for view.
		    
	  // Update GUI Window
	  //
  	  //cv::imshow("view", image);
	  //
	  // Display current updated ogMap image.
	  cv::imshow("view", cvPtr_->image);
	  cv::waitKey(5);


	  // Convert cvImage to ROS image message.  To use with cvPtr_
	  // in imageCallback()
	  //
	  // NOTE: installing this code causes runtime errors???
	  //cv::imshow("view", cvPtr->image);
	  //cv::waitKey(3);
	  // sensor_msgs::ImagePtr msg
	  //   = cv_bridge::CvImage(std_msgs::Header(),
	  //   			 enc::MONO8, cvPtr_->image).toImageMsg();
	  // image_pub_.publish(msg);
	  
	} // end: if(!image.emptry()

	//std::this_thread::sleep_for (std::chrono::milliseconds(10));
	
      } // end: if(cout_<100)
      else{
	// count_ is still < 100
	count_++;
	// This delay slows the loop down for the sake of readability
	// in example code:
	//std::this_thread::sleep_for (std::chrono::milliseconds(10));
      }

      
    } // end: while(ros::ok())
    
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

