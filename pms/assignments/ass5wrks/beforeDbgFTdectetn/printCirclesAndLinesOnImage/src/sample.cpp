//
// smagri additions:
//
#include <time.h>
#include <vector>

// When set indicates code used for debuging in process of building program
//
//#define DEBUG_DRAW_ON_IMAGE
#define DEBUG_CALL_SERVICE
//#define DEBUG_DRAW_BLACK_IMAGE

#include "ros/ros.h"

#include <geometry_msgs/Twist.h>

#include "std_msgs/String.h"
#include "gazebo_msgs/ModelStates.h"
#include "tf/transform_datatypes.h"

#include "sensor_msgs/LaserScan.h"
#include "nav_msgs/Odometry.h"
#include "geometry_msgs/PoseArray.h"

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
  cv_bridge::CvImagePtr cvPtr_; ///pointer to current ogMap as openCV image
  sensor_msgs::ImagePtr rosMsgPtr_;///pointer to current ogMap as ROS image msg
  std::string imageEncoding;

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

  struct LaserDataBuffer
  {
    std::deque<double> laserDeq; /// closest_point vector magnitude
    std::deque<double> laserAngleDeq; /// closest_point vector angle
    
    // LATER: check if this is always  the same value, would expect if
    // msg is comming from same laser???
    std::deque<double> laserRminDeq;
    std::deque<double> laserRmaxDeq;
    
    std::deque<ros::Time> timeStampDeq; ///< timestamp que
    std::mutex buffer_mutex_; ///< mutex lock for buffer access
			      /// syncronisatetion.
  };
  LaserDataBuffer laserBuffer;//! And now we have our container


  struct PathDataBuffer
  {
    std::deque<std::vector<double>> xWaypointDeq; ///< waypoint x coord
    std::deque<std::vector<double>> yWaypointDeq; ///< waypoint y coord
    std::deque<ros::Time> timeStampDeq; ///< timestamp que
    std::mutex buffer_mutex_; ///< mutex lock for buffer access syncronisation
  };
  PathDataBuffer pathBuffer; //! And now we have our container

  
  // These  are just  symbolic numbers  to reperesnt  the cell  types,
  // these  values are  mapped to  corresponding RBG  values when  the
  // ogMap is updated.
  // 
  int FS = 255; // Free Space/Cell
  int O = 0;    // Occupied Space/Cell
  int FT = 260; // Frontier Nodeier Cell
  int UK = 270; // Uknown Cell


  // Value of pi:
  //
  // M_PI is type double, M_PI1  is long double; or maybe use:
  // pi  =  2*acos(0.0) as  it's  more  portable, and  may  be
  // combined  with  templates  to future  proof  protability.
  //
  const double pi = 2*acos(0.0); // should be float/double??

  
  
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

    
    // local_map_node.cpp(ros  package local_map)  takes input  form a
    // LaserScan   message   and   outputs   a   local   map   as   an
    // OccupancyGrid(or   EvidenceGrid).     This   OccupancyGrid   is
    // converted to an openCV image by map_to_image_node.cpp
    //
    // map_to_image_node.cpp  publishes the  occupancyGrids as  openCV
    // images, ie ogMaps, to the  ros node topic "map_image/full".  We
    // subscribe to this  topic here so these ogMaps  are available to
    // us in  this node(sample.cpp).  The  ogMap is visualised  in the
    // "rqt_image_view" window???
    //
    // With  each  ogMap  published to  "map_image/full"  ROS  invokes
    // imageCallback().    The  callback   function  associated   with
    // subscribing to the "map_image/full" topic, as below.  It stores
    // the ogMap in a deque for use by other threads.
    //
    sub3_ = it.subscribe("map_image/full", 1,
			 &GazeboRetrieve::imageCallback,this);

    // sample.cpp.orig:  Publishing an  image  ... just  to show  how.
    // image_pub_ = it_.advertise("test/image", 1);
    //
    // Object  image_pub_ is  used to  publish to  the ros  node topic
    // "map_image/full".  Thus  sending our modified/updated  ogMap to
    // this  ros  topic.   Which  in   turn  produces  the  output  in
    // "rqt_image_view" by another node subscribed to this topic.
    //
    // OR does this mean, we need to make it:
    //
    // image_pub_ = 
    //  it_.advertise<sensor_msgs::ImagePtr>("map_image/full", 1);
    //
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

    void detectFrontiers(int py, int px,
			 double  &angleDeg, std::map<int, int> &unvisitedFT);
    void detectCellTypes(double closest_point, double angle,
			 double range_min, double range_max);


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
  void detectFrontiers(int py, int px, int &angleDeg,
		       std::map<int, int> &unvisitedFT){
  
    /// Determines  if  the  current  ogMap  image  cell(py,px)  is  a
    /// frontier cell,  symbolised by the  FT value here.   Hence, the
    /// respective ogMap image cell is updated to indicate this.
    ///
    ///
    /// Assuming image grid is:
    ///	cell x=0 -> x=mapSize
    ///	cell y=0 -> y=mapSize
    /// with (x,y)=(0,0) in the top left hand corner
    ///
    ///  Perhaps this should be 1->image.rows foreach axis???..and also set
    ///  it to mapSize???
    ///
    ///
    /// FT  cells  are on  the  boundary  between FS(Free  Space)  and
    /// UK(Uknown) cells.  Thus  we only need to test for  UK cells if
    /// the current cell is a FS cell.
    /// 
    /// FT cells are  a special case of FS cells.   That is, when
    /// we find  the FS->UK adjacent  cell combination the  FS is
    /// replaced by a FT cell.
    ///
    /// Only adjacent cells to the current image cell are probed
    /// for FT detection. (Yamachi???)
    ///
    if (cvPtr_->image.at<uchar>(py, px) == FS){
	  
      // Use  only _valid_  adjacent  cells to  the current  image
      // cell.   That is,  cells that  only exist  on the  map not
      // outside  the map.   Note  the  generic calcutations  here
      // sometimes generate an invalid adjacent cell, thus doesn't
      // need to be be tested to  determine if the current cell is
      // a frontier cell or not.
      //
      // If one  or more adjacent  cells to  this FS are  UK cells
      // this FS->FT cell.
	  
      // cell above robot cell
      int x=px;  int y=py-1;
      if ( (x>=0 && x<cvPtr_->image.cols) && (y>=0 && y<=cvPtr_->image.rows) ){
	if (cvPtr_->image.at<uchar>(y, x) == UK){
	  cvPtr_->image.at<uchar>(py, px) = FT;
	  angleDeg=90;
	  
	  // The map container  here will replace the old  y key value
	  // with the new x value.
	  unvisitedFT[py]=px;
	}
      }
	  
      // cell below robot cell
      x=py;  y=py+1;
      if ( (x>=0 && x<cvPtr_->image.cols) && (y>=0 && y<cvPtr_->image.rows) ){
	if (cvPtr_->image.at<uchar>(y, x) == UK){
	  cvPtr_->image.at<uchar>(py, px) = FT;
	  angleDeg=270;
	  unvisitedFT[py]=px;
	}
      }
	  
      // cell left of robot cell
      x=px-1;  y=py;
      if ( (x>=0 && x<cvPtr_->image.cols) && (y>=0 && y<cvPtr_->image.rows) ){
	if (cvPtr_->image.at<uchar>(y, x) == UK){
	  cvPtr_->image.at<uchar>(py, px) = FT;
	  angleDeg=180;
	  unvisitedFT[py]=px;
	}
      }
	  
      // cell right of robot cell
      x=px+1;  y=py;
      if ( (x>=0 && x<cvPtr_->image.cols) && (y>=0 && y<cvPtr_->image.rows) ){
	if (cvPtr_->image.at<uchar>(y, x) == UK){
	  cvPtr_->image.at<uchar>(py, px) = FT;
	  angleDeg=0;
	  unvisitedFT[py]=px;
	}
      }
	  
    } // end: if (cvPtr_->image.at<uchar>(px, py) == FS){


  } // end: void detectFrontiers(int py int px, &angleDeg, &unvisitedFT){


  void  rangeVectorNextPxPy(int angleDeg, int &px, int &py){
    
    // Depending on  the angle the shortest range vector is at the next
    // (px,py) values are determined by a different formula.
    
    if (angleDeg == 0){
      px = px+1;
      py = py;
    }
    else if (angleDeg == 180){
      px = px-1;
      py = py;
    }
    else if (angleDeg == 90){
      px = px;
      py = py-1;
    }
    else if (angleDeg == 270){
      px = px;
      py = py+1;
    }
  
  }

  void  detectCellTypes(double closest_point, double angle,
			double range_min, double range_max){

    /// At each  invocation of laserCallback() function  the LRF(Laser
    /// Range Finder)  smallest range magnitiude,  closeest_point, and
    /// its  direction  from the  current  robot  pose is  determined.
    /// These parameters are passed to this function.
    ///
    /// This function detects  the types of cells  along the magintude
    /// and  direction of  the  closest_point,  or smallest  magnitude
    /// radial vector.   The radial vector  starts at the  robot pose,
    /// the centre of the ogMap.
    ///
    /// The cell  types can be  determined as either:  FS(Free Space),
    /// UK(Unknown),  O(obstacle) here.   Note  that the  FT(Frontier)
    /// cells are detected in the detectFrontier() function.
    ///
    /// A  combiation  of  radial   vector  magnitude,  radial  vector
    /// direction  and   the  LRF's  minumim(range_min)   and  maximum
    /// range(range_max) values are used to determine this.


    
    // Bare in  mind that  the robot  is always at  the centre  of the
    // ogMap  image,   in  pixels  this  is   at  px=image.cols/2  and
    // py=image.rows/2.  Thus  the ogMap moves  with the robot  in the
    // environment to be mapped.
    //
    // LATER: centre of ogMap is at (truePX-1, truePY-1), where true
    // x,y map centre is (image.rows/2 image/.cols/2).???
    //
    // range component along the x-axis(x) and y-axis(y), in metres
    // from the ogMap image centre
    double x = closest_point * cos(angle);
    double y = closest_point * sin(angle);
    double angleDeg = angle * (180/pi);
    int pr = sqrt(pow(x,2) + pow(y,2));
    
            
    // rage_min and range_max in pixel values, ie cast double to int
    int pxyRangeMin = (range_min / resolution_);
    int pxyRangeMax = (range_max / resolution_);


    // (px,py) pixel  values for the  centre of the ogMap.   The robot
    // pose starts here, so this cell is FS.
    //
    // However, since we are using 0  to <mapSize pixels as indexes to
    // our  image   array  elements  the  affective   centre  cell  is
    // ( (image.rows/2 - 1),  (image.cols/2 - 1) )???
    //
    // Determine x,y in pixels from the ogMap image centre, by casting
    // double x,y int px,py.  LATER check:
    int px = cvPtr_->image.cols/2;
    int py = cvPtr_->image.rows/2;

    cvPtr_->image.at<uchar>(py, px) == FS;
    // or affective centre is cvPtr_->image.at<uchar>(py-1, px-1) == FS;

    
    // LRF valid  range readings are between  range_min and range_max.

    // Foreach case of range vector magnitute determine the type of
    // cells FS, UK, 0's, along it.
    //
    if (closest_point < range_min){
      // All cells along the range vector are UK.
      for (int i=0; i<cvPtr_->image.cols; i++){
	rangeVectorNextPxPy(angleDeg, px, py);
	cvPtr_->image.at<uchar>(py, px) == UK;
      }
    }
    else if (closest_point == range_min){
      // All cells along the range vector are FS till the range_min
      // cell.  The range_min cell O, rest of range vector is UK.
      for(int i= 0; i<pxyRangeMin; i++){
	rangeVectorNextPxPy(angleDeg, px, py);
	cvPtr_->image.at<uchar>(py, px) == FS;
      }

      rangeVectorNextPxPy(angleDeg, px, py);
      cvPtr_->image.at<uchar>(py, px) = O;

      for (int i=px; i<cvPtr_->image.cols; i++){
	rangeVectorNextPxPy(angleDeg, px, py);
	cvPtr_->image.at<uchar>(py, px) == UK;
      }
    }
    else if ( (closest_point > range_min)
	      && (closest_point < range_max) ){
      // All cells along the range vector are FS upto the magnitude of
      // the range vector.  The actual  range vector magnitude cell is
      // O, the rest of the range vector is UK.
      for (int i=0; i<pr; i++){
	rangeVectorNextPxPy(angleDeg, px, py);
	cvPtr_->image.at<uchar>(py, px) == FS;
      }

      rangeVectorNextPxPy(angleDeg, px, py);
      cvPtr_->image.at<uchar>(py, px) = O;

      for (int i=px; i<cvPtr_->image.cols; i++){
	rangeVectorNextPxPy(angleDeg, px, py);
	cvPtr_->image.at<uchar>(py, px) == UK;
      }
    }
    else if (closest_point == range_max){
      // All cells upto  range_max cell are FS.   The actual range_max
      // cell is 0, the rest of the range vector is UK.
      for (int i=0; i<pxyRangeMax; i++){
	rangeVectorNextPxPy(angleDeg, px, py);
	cvPtr_->image.at<uchar>(py, px) == FS;
      }
      
      rangeVectorNextPxPy(angleDeg, px, py);
      cvPtr_->image.at<uchar>(py, px) = O;
      
      for (int i=px; px<cvPtr_->image.cols; i++){
	rangeVectorNextPxPy(angleDeg, px, py);
	cvPtr_->image.at<uchar>(py, px) == UK;
      }
    }
    else if (closest_point > range_max){
      // All  cells upto  range_max cell  and including  the range_max
      // cell are FS,  the rest of the range vector  is UK.
      for (int i=0; i<pxyRangeMax; i++){
	rangeVectorNextPxPy(angleDeg, px, py);
	cvPtr_->image.at<uchar>(py, px) == FS;
      }

      rangeVectorNextPxPy(angleDeg, px, py);
      cvPtr_->image.at<uchar>(py, px) == FS;

      for (int i=px; px<cvPtr_->image.cols; i++){
	rangeVectorNextPxPy(angleDeg, px, py);
	cvPtr_->image.at<uchar>(py, px) == UK;
      }
    }

  }  // end: void detectCellTypes()

  
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

    /// Once a  FT cell has  been reached the LRF(Laser  Range Finder)
    /// does a 360 degree sweep to update the ogMap image with the UK,
    /// FS, and O cells determined from the current LRF range reading.
    ///
    /// The LRF  reading is from  a single planar  laser range-finder.
    //
    /// Assumption  [B. Yamauchi  1998]:  only adjacent  cells to  the
    /// current cell  the robot is  in are scanned. This  implies that
    /// sweep angles in degrees are 0,  90, 180 and 360 degrees.  Note
    /// however, for  sensor_msgs/LaserScan.msg angle is  specified in
    /// radians.
    ///

    
    // The  scan  chosen,  at  a   particular  sweep  angle,  for  the
    // determination of  UK, FS, 0  cells along  it's axis is  the one
    // that is  closest to the  robot.  The  movevent of the  robot is
    // best keept  at small distances  to avoid large  accumulation of
    // errors from its sensors.

    // local_map node uses parameter _local_map/scan:=/base_scan_1
    //					Node/Topic/SubTopic
    // So you need to subscribe to /base_scan_1 to activate this callback.
    //
    fprintf(stderr, "dbg: in laserCallback() fn\n");


    // LRF scan parameters:
    //
    // d range of the LFR
    // scan, angle, in radians
    // x = d cos(angle) in radians
    // y = d sin(angle) in radians
    // scanTime in seconds
    //
    //
    // Notes:
    //
    // http://docs.ros.org/jade/api/sensor_msgs/html/msg/LaserScan.html
    //  and
    // 'rosmsg show sensor_msgs/LaserScan'
    //
    // sensor_msgs/LaserScan.msg says that all these parameters are of
    // float32/float type.  And all the units are SI units:
    //
    // This has implications for requestGoal() callback function.
    //
    // All these values are  float32/float types, not float64/doubles,
    // these will loose  information if we cast the  floats to doubles
    // here.  ie -ve  numbers, may not matter here  if never expection
    // -ve numbers. Double check LATER???
    //
    //
    //
// These already set by LaserScan.msg LATER:???
//    double angleIncDeg = 90; // angle increment in degrees
//    double msg->angle_increment = (angleIncDeg*(pi/180));//angle increment rad
//    double angleDeg = 0; // start angle in degrees
//    double msg->angle_min = (angleDeg*(pi/180)); // start angle in radians

    double closest_point = msg->range_max; // closest range in metres
    double angle = 0; // scan angle rad around the z-axis, counter clockwise
    double x; // range component along the x-axis x=range * cos(angle) 
    double y; // range component along the y-axis y=range * sine(angle)


    for (unsigned int idx=0 ; idx < msg->ranges.size() ; idx++){
      if(msg->ranges.at(idx)<closest_point){
	closest_point = msg->ranges.at(idx);
	angle = msg->angle_min+(idx*msg->angle_increment);
      }
    }
    int angleDeg = (angle * (180/pi));


    // This is the  buffer of laser closest  points(or closest ranges)
    // // to the robot with each invocation of this laserCallback().
    // laserBuffer.buffer_mutex_.lock();
    // laserBuffer.laserDeq.push_back(closest_point);
    // laserBuffer.laserAngleDeq.push_back(angle);
    // laserBuffer.laserRminDeq.push_back(msg->range_min);
    // laserBuffer.laserRmaxDeq.push_back(msg->range_max);
    // laserBuffer.timeStampDeq.push_back(msg->header.stamp);
    // // LATER: is this really necessary???
    // // if(laserBuffer.laserDeq.size()>2){
    // laserBuffer.buffer_mutex_.unlock();


    // Hard to make fprintf work  here  The equivalent to fprintf, or
    // unbuffered output in c, is std::err in c++.
    
    // Timestamp(ie seconds  since the epoch)  of this scan,  or ogMap
    // image update
    ros::Time timeLaser = msg->header.stamp;
    std::cerr << timeLaser
	      << " Laser: [d, theta, x, y]=["
	      << closest_point <<","<< angle << "," << x << "," << y << "]"
	      << std::endl;


    std::cerr << "dbg: "
	      << timeLaser
	      << " Laser: [d, theta, x, y]=["
	      << closest_point <<","<< angleDeg << "," << x << "," << y << "]"
	      << std::endl;

    //std::this_thread::sleep_for (std::chrono::milliseconds(10));

    
  } // end: laserCallback()


    


    
  void imageCallback(const sensor_msgs::ImageConstPtr& msg)
  {

    /////! Below code pushes the image and time to a deque, to share
    /////! across threads.

    fprintf(stderr, "dbg: in imageCallback() fn\n");
    
    /// local_map_node.cpp,  takes as  input a  LaserScan message  and
    /// outputs a local_map as an OccupancyGrid.
    ///
    /// map_to_image_node.cpp, takes  this OccupancyGrid  and converts
    /// it into and image using openCV, it is known as the ogMap. This
    /// node publishes  the ogMap to the  topic "map_image/full".  The
    /// ogMap is visualised using the program rqt_image_view.
    ///
    /// sample.cpp subscribes  to the  topic "map_image/full"  and the
    /// callback    function   associated    with   this    topic   is
    /// imageCallback().   imageCallback()  stores  each  ogMap  in  a
    /// deque.   The  deque  is  used  to share  the  image  and  it's
    /// timestamp across threads.
    ///
    /// Each time a  local_map or OccupancyGrid is  created ros passes
    /// it  on   to  map_to_mage_node.cpp  producing   another  ogMap.
    /// map_to_image_node.cpp  then uses  ros  to  publish this  ogMap
    /// which triggers a call  to imageCallback() in sample.cpp, which
    /// in turn stores  the ogMap into a deque.  This  cycle of events
    /// continues till the ros event loop is exited.
    ///
    /// 

    // Convert ROS sensor_msgs/Image.msg format this callback function
    // receives,  sensor_msgs::ImageConstPtr&  msg,  to  openCV  image
    // format, cv::Mat.   The ROS  CVBridge library  allows you  to do
    // this, and visa versa.
    //
    try
    {
      if (enc::isColor(msg->encoding)){
	//
        // cvPtr_ is  the pointer to  the openCV image, ie  pointer to
        // cv::Mat;
	//
	// We make a  copy of the ROS  data to allow us  to modify the
	// openCV image.
	//
	// Colour image  with (blue, green, red  color) order.  openCV
	// requires this colour order.
	cvPtr_ = cv_bridge::toCvCopy(msg, enc::BGR8);
      }
      else{
	// greyscal image
	cvPtr_ = cv_bridge::toCvCopy(msg, enc::MONO8);
      }
    }
    catch (cv_bridge::Exception& e)
    {
      ROS_ERROR("cv_bridge exception: %s", e.what());
      return;
    }
    

    // Similarly, when publishing  an openCV image via  a ROS message,
    // the openCV  format cv::Mat is changed  to sensor_msgs/Image.msg
    // format.
    //
    // To convert  the openCV image  to a  ROS image message,  use the
    // toImageMsg() member function.
    //
    // Save the openCV cv::Mat image  and ROS image message pointer to
    // the deque for use accross threads???
    //
    // rosMsgPtr_ 
    //   = cv_bridge::CvImage(std_msgs::Header(),
    // 			   imageEncoding, cvPtr_->image).toImageMsg();
    // image_pub_.publish(rsMsgPtr_);
    imageBuffer.buffer_mutex_.lock();
    imageBuffer.imageDeq.push_back(cvPtr_->image);//store openCV, cv::Mat image
    imageBuffer.timeStampDeq.push_back(msg->header.stamp);
    if(imageBuffer.imageDeq.size()>2){
      imageBuffer.imageDeq.pop_front();
      imageBuffer.timeStampDeq.pop_front();
    }
    imageBuffer.buffer_mutex_.unlock();

  }



  void pathCallback(const geometry_msgs::PoseArrayConstPtr& msg){

    // Callback function for nodes subscribed to the ros "path" topic.
    geometry_msgs::Pose pose;
//    int numPathPoses = poses.size();
    
    std::vector<double> xWaypoint; // double is float64???
    std::vector<double> yWaypoint;
    
    for (int i=0; i<msg->poses.size(); i++){
      pose = msg->poses.at(i);
      //yaw = tf::getYaw(pose.orientation);
      xWaypoint.push_back(pose.position.x);
      yWaypoint.push_back(pose.position.y);
    }

    pathBuffer.buffer_mutex_.lock();
    pathBuffer.xWaypointDeq.push_back(xWaypoint);
    pathBuffer.yWaypointDeq.push_back(yWaypoint);
    pathBuffer.timeStampDeq.push_back(msg->header.stamp);
    pathBuffer.buffer_mutex_.unlock();
    
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

    /// The below gets the current Ros Time
    ros::Time timeOdom = ros::Time::now();
    double yaw,x,y;

    ros::Time timeImage = ros::Time::now();;
    cv::Mat image; /// generic image container, current openCV image ogMap

    ros::Time timeLaser = ros::Time::now();;
    double laser;
    double angle;
    int angleDeg;
    double range_min;
    double range_max;    
    
    ros::Time timePath = ros::Time::now();;

    
    // List of  unvisited FT cells determined  in laserCallback() with
    // the detectFrontiers() function.
    //
    // Note: the cplus  plus continer called map is used  as the FT' s
    // have random index values ie  random x,y or row,col pair values.
    // Otherwise  if the  indexes were  more uniform/incremental  a 2d
    // vector could be used.
    //
    // std::map<int, int> unvisitedFT; // y=key, value=x, ie key value pair
    // std::map<int, int>::iterator it = unvisitedFT.begin();


    // Robot starts at the centre of the ogMap, thus that cell must be a FS.
    // cvPtr_->image.at<uchar>((image.rows/2), (image.cols/2)) = FS;
    
    
    // The below loop runs until ros is shutdown, to ensure this
    // thread does not remain a zombie thread.
    //
    // The  loop locks  the buffer,  checks the  size.  And  then pulls
    // items: the pose  and timer_t. You can think if  these could have
    // been combined into one ...
    //

    while (ros::ok()) {
      int deqSz =-1;

      fprintf(stderr, "dbg: seperateThread: while(ros::ok)\n");
      
      // Only access  pose buffer  and imageBuffer contents  when the
      // deques in  them are  not empty,  that is  when we  have robot
      // poses and ogMap images available.

      // Mutex locking  is required for  access to the deques  as this
      // thread shares  them with the  main thread(or other  theads if
      // they   exist).     The   odomCallback,    imageCallback   and
      // laserCallback functions/threads that access these deque's are
      // called within the main thread.
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


     
      ////! Lock image buffer, take one message from deque and unlock it
      //
      // This   is  the   ogMap   image  buffer   visualised  by   the
      // rqt_image_view  program.  This  is  different  to the  'view'
      // image which is an image of  this ogMap containing FT, FS, UK,
      // O cell information of this image???
      //
      // Need  to make  a new  imageBuffer called  imageViewBuffer who
      // gets images from laserCallback()???
      //
      imageBuffer.buffer_mutex_.lock();
      if(imageBuffer.imageDeq.size()>0){
	image = imageBuffer.imageDeq.front();
	//sensor_msg::Image msg = imageBuffer.imageMsgDeq.front();
	timeImage = imageBuffer.timeStampDeq.front();
	imageBuffer.imageDeq.pop_front();
	imageBuffer.timeStampDeq.pop_front();
      }
      imageBuffer.buffer_mutex_.unlock();


      // This is the buffer of laser closest points(or closest ranges)
      // to the robot.
      // laserBuffer.buffer_mutex_.lock();
      // if(laserBuffer.laserDeq.size()>0){
      // 	laser = laserBuffer.laserDeq.front();
      // 	angle = laserBuffer.laserAngleDeq.front();
      // 	angleDeg = (angle * (180/pi));
      // 	range_min = laserBuffer.laserRminDeq.front();
      // 	range_max = laserBuffer.laserRmaxDeq.front();
      // 	timeLaser = laserBuffer.timeStampDeq.front();
      // 	laserBuffer.laserDeq.pop_front();
      // 	laserBuffer.laserAngleDeq.pop_front();
      // 	laserBuffer.laserRminDeq.pop_front();
      // 	laserBuffer.laserRmaxDeq.pop_front();
      // 	laserBuffer.timeStampDeq.pop_front();
      // }
      // laserBuffer.buffer_mutex_.unlock();
      


      // Let's  do   something  with  the  current   pose  and  opencv
      // image/ogMap image; on every 100 iterations.
      //
      // When seperateThread() is called you  count to 100, each count
      // interleaved with a sleep(), at this stage.
      //
      // When count reaches  100 the currnet ogMap  image is displayed
      // in the view window.  For testing this is an all black image.
      //
      // With subsequent  calls to  seperateThread(), we count  to 100
      // again  before   we  display  the   new  image  in   the  view
      // window....etc
      

      if (count_>100){
	count_=0;
	
	if(!image.empty()){

	  fprintf(stderr, "dbg: seperateThread: (!image.empty()\n");
		
	  // Update the current ogMap image with FS, UK, O cell types,
	  // by moving  along the closest_point/range  vector/laser at
	  // vector angle.
	  //
	  // LATER: range_min and range_max  should always be the same
	  // as we are using the same  laser, so no need deque of the,
	  // make just a single double variable???
	  //detectCellTypes(laser, angle, range_min, range_max);
		  
	  
	  // Update the  current ogMap  image with  FT cells.
	  // for (int py = 0; py<cvPtr_->image.rows; py++){
	  //   for (int px = 0; px<cvPtr_->image.cols; px++){
	  //     detectFrontiers(py, px, angleDeg, unvisitedFT);
	  //   }
	  // }



	  // Convert greyscale image stored in  image, to an RGB image
	  // stored in rgbImage.  Remember  image is the OccupancyGrid
	  // as an openCV image.
	  cv::Mat rgbImage;
	  cv::cvtColor(image, rgbImage, CV_GRAY2RGB);

	  
	  // Display FT cells, in blue,  on the current updated ogMap.
	  // This   is   visualised   in   the   "view"   window   and
	  // "rqt_image_view" window.
	  //
	  //
	  // Due to  assignment spec I  don't think we need  to update
	  // the current ogMap with new FT, FS, UK, O cell values???
	  //
	  // for (int y=0; y<cvPtr_->image.rows; y++){
	  //   for (int x=0; x<cvPtr_->image.cols; x++){
	  //     if (cvPtr_->image.at<uchar>(y, x) == FT){
	  // 	cv::circle(rgbImage, cv::Point(y, x), 2, CV_RGB(0,0,255), -1);
	  //     }
	  //   }
	  // }

	  


	  // Show given  BFS/DFS path from  robot start to  robot goal
	  // locations, the waypoints connected by lines.
	  //
	  // BFS/DFS path is determined here,  or it is requested from
	  // project one via the requestGoal() service,
	  //
	  // For, project two, people, that  is me, alen may provide a
	  // path to destination.
	  //
	  //
	  // 
	  // Publish  path by  drawing a  line between  the waypoints.
	  // Waypoints are published in red dots and line is published
	  // in green, as  blue is the FT cells.   colour is specified
	  // by CV_RGB(red, green, blue)
	  //
	  // FORMAT of commands may change due to version of openCV
	  // being used???
	  //
	  // Colour  is specified by CV_RGB(red, green, blue)
	  //
	  // LATER: does the Point(x,y) need to be specified in pixels
	  //        or metres, i think the Point template allows for
	  //        either???
	  //        See this file for pixel working one.
	  // ~/uni/subj/pms/assignments/ass5wrks/printCirclesAndLinesOnImage
	  //
	  //
          // Methods:
	  //
	  // 1) First we must subscribe to  the /path topic to give us
          // the path  from the  BFS/DFS algorithim of  project1.  The
          // path is given in the form of a PoseArray.msg.
	  //
	  // OR
	  //
	  // 2) Use  BSF/DFS implementation  in sample.cpp  node given
	  // here.
	  //
	  // OR
	  //
	  // 3) Make up a path here to at least show that i can draw a
	  // path on the ogMap. ie red dots and lines to connect them.
	  //
	  //
	  // NOTES:
	  //
	  // 1) -would require a subscribe to /path topic
	  //    -would require a pathCallback() function
	  //    -callback fn will interpret the PoseArray.msg and store the x,y 
	  //     coords or waypoints
	  //    -display the path on ogMap
	  // 2) write a bfs or dfs algorithim to go from FT to FT???
	  //
	  // 3) make up a random number of dots and plot the path.
/*	  
	  vector<double> xWaypoint; // double is float64???
	  vector<double> yWaypoint;

	  pathBuffer.buffer.buffer_mutex_.lock();
	  // if (xWaypointDeq.size() >0 )???
	  xWaypoint = pathBuffer.xWaypointdDeq.front(xWaypoint);
	  yWaypoint = pathBuffer.yWaypointdDeq.front(yWaypoint);
	  timePath = pathBuffer.timeStampDeq.front(msg->header.stamp);
	  pathBuffer.xWaypointDeq.pop_front(xWaypoint);
	  pathBuffer.yWaypointDeq.pop_front(yWaypoint);
	  buffer.timeStampDeq.pop_front(msg->header.stamp);
	  pathBuffer.buffer_mutex_.unlock();

	  // The  waypoints are  displayhed in  black dots  with green
	  // lines connecting them.
	  for (int i=0; i<xWaypoint.size(); i++){
	    cv::circle(rgbImage,
	  	       cv::Point(xWaypoint.at(i), yWaypoint.at(i)),
	  	       3, CV_RGB(0,0,0), -1);
	    cv::circle(rgbImage,
	  	       cv::Point(xWaypoint.at(i+1), yWaypoint.at(i+1)),
	  	       3, CV_RGB(0,0,0), -1);
	    cv::line(rgbImage, 
	  	     cv::Point(xWaypoint.at(i), yWaypoint.at(i)),
                     cv::Point(xWaypoint.at(i+1), yWaypoint.at(i+1)),
                     CV_RGB(0,255,0), 1);
	  }
*/	
	  // Template for drawing a path between waypoints, project
	  // requirement.
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
	  

	  // Output    current   robot    location/pose(position   and
	  // orientatn):
	  //
	  //
          // std::cout is bufferd but  std::cerr is not.  std::cerr is
	  // the eqivalent of stderr in C.
	  //
	  // That is,  print the  current FT  coord's relative  to the
	  // previous FT location.  The new FT cell becomes the centre
	  // of the new ogMap.
	  //
	  // Current FT global coordinates, from the centre of the ogMap.
	  std::cerr << "Odom in the global frame:"
		    << timeOdom
		    << " Odom: [x ,y ,yaw]=["
		    << x << "," << y << "," << yaw << "]"
		    << std::endl;
	  int yawDeg = (yaw * (180/pi));
	  std::cerr << "dbg: "
		    << " Odom: [x,y,yawDeg]=["
		    << x << "," << y << "," << yawDeg << "]"
		    << std::endl;
	  
	  // Current FT pixel coordinates, from the centre of the ogMap.
	  //
	  // Current FT pixel coordinates, from the centre of the ogMap.
	  std::cerr << " Odom:"
		    << "pixels from centre of ogMap, pos[px,py]=["
		    << (x/resolution_) << "," 
		    << (y/resolution_) << "] "
		    << std::endl
		    << " pixels on ogMap, pos[px,py]=[" 
		    << ((x/resolution_)+(image.cols/2)) << ","
		    << ((y/resolution_)+(image.rows/2)) << "]"
		    << std::endl;




	  // Send current  modified/updated openCV ogMap to  ros, this
	  // is done by  converting the ogMap image to  a ros message.
	  // ros then  publishes/sends the  message to the  nodes that
	  // subscibe  to   the  ros  topic  that   image_pub_  object
	  // publishes to, in our  case the "map_image/full".  Also in
	  // our   case  the   ros   node  that   displays  into   the
	  // "rqt_image_view" window  must be one of  those nodes.  As
	  // is   this    sample.cpp   node,   which    will   trigger
	  // imageCallback()???
          //
	  // Method  1: deque  ROS msg  from imageBuffer  struct.  see
	  // above:
	  // sensor_msg::Image msg =
	  // imageBuffer.imageMsgDeq.front();
	  // image_pub_.publish(msg)
	  //
	  // Method 2: this is best i think:
	  // Use  the current  modified/updated  ogMap, rgbImage,  and
	  // publish it  to ROS  in the  form of  a ros  message, msg.
	  //
/*          rosMsgPtr_ = cv_bridge::CvImage(std_msgs::Header(),
					  enc::BGR8, rgbImage).toImageMsg();
	  image_pub_.publish(rosMsgPtr_);
*/

	  


          // While  the  robot is  standing  still  in one  particular
	  // location the image and  laser/closest_point values in the
	  // respective buffer/deques are the same.
	  //
	  // Thus move  the robot to  the next unvisited  frontier and
	  // clear these deques ready for  the next invocation of this
	  // thread.
	  
	  // Move the  robot to  the next  FT, via  a service  call to
	  // requestGoal().
	  //
	  //
/*
	  // The robot starts in the centre of the ogMap, ie (x,y) =
	  // (0,0) in metres.
	  a3_help::RequestGoal::Request goalReq; 
	  a3_help::RequestGoal::Response goalRes;
	  // x,y in SI units, so metres here
	  goalReq.x = goalReq.x + (it->second * resolution_);
	  goalReq.y = goalReq.y + (it->first * resolution_);
	  goalReq.angle = 0.0; // LATER: ???
	  
          // Actually  call  the  request_goal  service,  which  won't
	  // return till  the service  is complete,  that is  till the
	  // robot has moved to the location.
	  client_.call(goalReq, goalRes);
	    
	  if (goalRes.ack){
	    // goalRes.ack == true;
	    ROS_INFO_STREAM("client call to service SUCCEDED");
	  }
	  else{
	    // goalRes.ack == false;
	    ROS_INFO_STREAM("client call to service FAILED");
	  }

	  // Remove last visited frontier from list of unvisitedFT's.
	  if (it != unvisitedFT.end()){
	    //unvisitedFT.erase(it++); // use current it before incrementing
	    unvisitedFT.erase(it);
	    it++;
	  }
*/

	  // *********************************************************
	  // *** NOTE: actually  assignment spec only  requires sending
	  // *** updated ogMap  to "view"  window OR published  on the
	  // *** "map_image/full"  topic.  So  only  one  of below  is
	  // *** required.  Bummer, I did  both, probably doesn't hurt
	  // *** though.
	  // *********************************************************
	  
	  // Display current updated ogMap image in the "view" window GUI.
	  //
	  fprintf(stderr, "dbg: seperateThread: before imshow view\n");
	  cv::imshow("view", rgbImage);
	  cv::waitKey(5);

	} // if(!image.empty)


      } // if(count>100)
      else{
	// count_ is still < 100
	count_++;

	// This delay slows the loop down for the sake of readability
	// in example code:
	// orig: std::this_thread::sleep_for (std::chrono::milliseconds(10));
	std::this_thread::sleep_for (std::chrono::milliseconds(10));

	// We have visited all FT cells in our environment.
	
	// Publish all frontiers:
	
	// Exit ROS
	//break; // breaks out of while loop: while(ros::ok())
      }

      std::this_thread::sleep_for (std::chrono::milliseconds(10));
    

    } // end: while(ros::ok)
      
  } // end: seperateThread()
    
    
    //////////////////////////////////////////////////////////////////
    //
    // From now  on we can ignore  the invocation of all  the callback
    // fn's as we have the whole map of the environment.
  
    // Do path finding  given a certain goal, that is  given a request
    // goal.
  
    // Print shortest path via a breath first search algorithim.
    //
    //////////////////////////////////////////////////////////////////
  
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
