21dec2017

This is a summary of the paper  notes taken during the time of working
on assignment 5 for pms during the autumn semester of 2017.


Move to frontiers closest to the robot.

Ogmap  needs to  take into  account  the robot  size/radius.  That  is
enlarge map to dimensions of the  robot, this is known as c-space, the
space the  robot can actually  move in.  To do  this cells need  to be
enlarged by diameter/2 of the robot base.



Moving the robot:
----------------						  

Firstly  point the  robot  in  the right  direction,  that  is at  the
frontier, using turn rate.  Then move  the robot with a velociy at the
trun rate=0 towards  the frontier.  The angle of rotation  is known as
yaw, that  is rotation  about the  z axis.   Robot moves  in the  x, y
plane.  Moving  to the frontier  (x,y) location  is executed as  a ROS
service request,  request_goal(from cmdline or from  the source code).
The request_goal service should be called every 10 seconds or so.

Request a goal(via a ros service  call) to the frontier location (x,y)
pixels.

There is a fixed distance from one cell to the next, being one unit.

The  robot base  is moved  in  the x,y  plane and  around the  z-axis.
Rotation around the z-axis is known as the yaw angle.

Understanding c-space is critical in moving the robot:

c-space  is the  area  where the  robot  can move  on  the ogMap.   It
restricts the robot  movement to points along a linear  line.  So that
it can move diagonally on ogMap grid and avoid obstacles.


* Pure Persuit Algorithim:
  -----------------------
						  
In Summary, this is:

Determine the current  location of the robot.  

Find the  point closest  to the  robot in  world/pixel??? coordinates,
this is the current goal point.

Turn the robot, done by setting the turn rate of the robot, till it is
on the line  between the current and goal coordinates.   At this point
set the turn rate of the robot to 0(ie not turning).

Move the robot along the straight line between the curret position and
the goal position.  Here the robot will wobble about the straight line
so the  angle of the robot  wobbles.  You must correct  for the wobbly
angle all the time as you go.


  
Determining frontier nodes, ie FT nodes, algorithim:
---------------------------------------------------

Ground work for algorithim:
--------------------------
				    
Relating Global Space  with Pixel Space of ogMap.  Need  to do this or
you wont know howto relate the  new ogMap with the old/previous ogMap.
That is, which points of old map are in the new map.

OgMap node key(ogmap is a greyscale image):

FT = Frontier Node
FS = Free Space Node (white in ogmap image)
UK = Uknown Node (grey in oogmap image)
0 = Obsticale/Occupied (black in ogmap image)

local_map is ogMap, contains values:
0=black=Obsticle=O; 255=white=FS; 125=grey=UK.

Note that FT is a special case of FS.  FT or frontier node is the cell
between FS and UK space.

By persuing each FT node the robot can build a map of it's environment???

Refer to  diagram ass5flowCtrlBtwSftwModules.jpg  showing the  flow of
control  between  stage,  local_map,  ogmap  and  a3_help/request_goal
module.

Once you have  a map/2Dvector full of 0's of  FS's publish this OpenCV
image as a ROS msg???


algorithm:
----------

Test all nine cells around the current cell/FS node???

If any are UK then FS -> FT node???

Repeat  the following  untill all  FT nodes  are found,  or have  been
visited:

Get rhe current robot POSE(x,y,theta)

[POSE is  the postion and  orientation of  the robot relative  to some
coordinate system.]

[Odometry using date from robot  motion sensors to estimate the change
in position over time]


Rememger the range of the laser needs to be taken into account to when
determining the type of node.

If a  valid laser readin  is returned, there  are FS cels  between the
robot and the laser target/obsticale.

If  reading/distance  is >=  Laser  MaxRange  we  know that  cells  to
MaxRange distance are FS and beyond those cells are UK cells.

If we have a  laser readin < MaxRange we have an  obstical, O, at that
distance.

The robot  stars at the centre  of the ogMap,  rviz shows it as  a red
arrow.  The  ogMap moves with the  robot as it moves  from frontier to
frontier.  The robot is always at the centre of the ogMap as it moves.							      

ROS:
---

Publish all: goals and frontiers(x,y) pixels

ROS callbacks or threads get invoked when it recieves new data, eg new
odom values, new laser readings...

ROS callbacks or threads are launched by the ROS call spin().

rviz shows ORIENTATION OF ROBOT, stage blue eminating from dot???

PASS/CREDIT opencv -> back to ROS

apt-get install ros-indigo-lite

This is a ROS based doxygen.








