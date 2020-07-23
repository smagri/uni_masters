//
// a3_help::RequestGoal Class Interface/declaration.
//

#ifndef A3_HELP_NODE_SAMPLE_H
#define A3_HELP_NODE_SAMPLE_H

/*!
 *  \ingroup   ac_shapre Sonar
 *  \brief     Class a3_help/Request_Goal.
 *  \details
 *  This class has no member functions(or methods) just structs.\n
 *  \author    Simone Magri
 *  \version   1.0
 *  \date      2018
 *  \pre       none
 *  \bug       none
 *  \warning   
 */


// A  struct is  a class  without member  fn's/methods, only  contains
// member data, use a struct in this case.
//
// Namespace/class is required but can  be defined in sample.cpp, thus
// no need of  a seperate file here.
//
// ie like essC==/ExerciseFiles/Chap04/namespace.cpp
//
// However, the inclusion of RequestGoal.h with
// #include "a3_help/RequestGoal.h"
// in sample.cpp sends you down the following path, a seperate .h file???


// ********************** This should all be changed to have x,y and
// x,y,ack as reqest and responce structures repectivaly, as they
// belong to a ros client and service. so the service should always
// return a responce should have identical except the ack.???
//
namespace a3_help{
  // a3_help is a class not a type, so can't be used as a varible type, 
  // eg a3_help::RequestGoal::Request &req

  /// Namespace is a3_help class, the Request Goal class derives from
  /// it.
  
  class RequestGoal{
  
  public:
    // Accessable methods and variables to all classes, not just member
    // fn's of this class.

    // The request of service request_goal is declared as this struct.
    //
    struct Request{

      // NOTE: you MUST enter these variable in RequestGoal.srv
      //
      
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
      double angle; // angle/yaw in radians, the robot is rotated
		    // about the z-axis at this angle
      double scanTime; // how often the request_goal service is
		       // called, ie how often the requestGoal()
		       // callback fn is called
      //int test;
  
    };


    // The responce to the service request_goal is declared as this struct.
    //
    struct Response{

      //int test;
      
      // The  responce struct  to  the "request_goal"  service is  the
      // obsticle free path to the next FT node.
      //
      //std::vector<double> path;
      
      // Call to "request_goal" sevice:
      // true=> request succeeded and  false=> request failed.
      bool ack;

    };
      
      
  }; // end: class a3_help::RequestGoal

    
    // No constructors needed I think, this class just creates two
    // types, the Request and the Reponse stuctures???
    //
    // OR
    //
    // Constructor for a3_help::RequestGoal object.
    //		 
    //bool a3_help::RequestGoal(a3_help::RequestGoal::Request &req,
    //			    a3_help::RequestGoal::Response &res);
    //
    // Default, do nothing constructors are implicity defined in
    // RequestGoal.cpp???
    //


  protected:
    // Available to this base class and derived classes.

  private:
    // Access specifier 'private:', these variables and functions are only
    // available to member functions/class methods.

    // Perhaps don't require these as no member function of this class
    // really uses or maniplulates them???
    //Request req_;
    //Response res_;
  
  } // class RequestGoal

} // end: namespace a3_help

#endif // A3_HELP_NODE_SAMPLE_H