7sep2017

This file is the root of the doxygen documentation tree, eg for
assignment 3:

file:///lu1/smagri/uni/subj/pms/assignments/ass3/build/doc/html/index.html


This builds the revised documentation, ie after a change to the
documentation:

cd build
make doc or md.  The alias in .cshrc for md is: alias md make doc

----------------------------------------------------------------------------------------

When you write a ///< or ///  and you want auto commenting of a region
or all of  the following comments make sure that  you don't create any
\n, ie carrige return and line feeds, within the code you want to auto
comment.

----------------------------------------------------------------------------------------

// Summary doxygen documentation:	
//	     
// method one: //!
// method two: ///<
//
// I prefer method two.


// Summary doxygen documentation methods:
//
//
// method one:
// /**
//   * RequestGoal, request_goal service, callback fn.
//   */
//
// method two: /// RequestGoal, request_goal service, callback fn.
//
// method three:  //! RequestGoal,  request_goal service, callback fn.
//
// Preferred method is two method three.


----------------------------------------------------------------------------------------


/// Object for the reqest_goal service.
//
/// The callback function of this service is RequestGoal().
ros::ServiceServer service_;

Produces  the requied  turse discription  on line  one.  And  when you
click on more the first and second lines are printed.

Trying do do:

ros::Publisher cmd_vel_pub_; ///< Object of the /cmd_vel topic. When
			     /// we publish to this topic we are
			     /// moving the robot.

does not work.

----------------------------------------------------------------------------------------
