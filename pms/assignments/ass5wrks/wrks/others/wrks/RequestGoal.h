//
// a3_help::RequestGoal Class Interface/declaration.
//

#ifndef A3_HELP_NODE_SAMPLE_H
#define A3_HELP_NODE_SAMPLE_H




class a3_help::RequestGoal{
  
 public:
  // Accessable methods and variables to all classes, not just member
  // fn's of this class.

  // The request to the service request_goal is declared as this struct.
  //
  struct Request{
    
    // The robot moves in the x,y plane and around the z-axis(this angle
    // is aka yaw).
    //
    // All these members define the robot 'goal', or goto pose, required
    // for the next move.
    //
    // Pose = Position and Orientation.
    //
    double x; // postion of robot along x-axis in metres
    double y; // postion of robot along y-axis in metres
    double angle; // angle/yaw in radians, the robot is rotated about
    // the z-axis at this angle
    double scanTime; // how often the request_goal service is called,
    // ie how often the requestGoal() callback fn is called
  
  };

  // The responce to the service request_goal is declared as this struct.
  //
  struct Response{

    bool ack; // true=> robot move succeeded, ie requestGoal() returns true
    // false=> robot move failed, requestGoal() returns false

  };

  // Constructor for a3_help::RequestGoal object.
  //bool a3_help::RequestGoal(a3_help::RequestGoal::Request &req,
  //			    a3_help::RequestGoal::Response &res);
  bool RequestGoal(Request &req, Response &res);

 protected:
  // Available to this base class and derived classes.
  // available to derived classes

  // works but we know where in this class, so unecssary.
  //a3_help::RequestGoal::Request req;
  //a3_help::RequestGoal::Response req;

  Request req;
  Response res;
  
  
 private:
  // Access specifier 'private:', these variables and functions are only
  // available to member functions/class methods.
  
}


#endif // A3_HELP_NODE_SAMPLE_H
