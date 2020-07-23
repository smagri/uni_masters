    if [ -f /opt/ros/indigo/setup.bash ]; then
	source /opt/ros/indigo/setup.bash
	    export ROS_PACKAGE_PATH=~uni/subj/proj30cp/rosWrkSpace:$ROS_PACKAGE_PATH
		export ROS_PACKAGE_PATH=\
		\       ~/uni/subj/proj30cp/tmp/node_example:$ROS_PACKAGE_PATH
		    export ROS_PACKAGE_PATH=\
			\       ~/uni/subj/proj30cp/catkin_ws/src/node_example:$ROS_PACKAGE_PATH
		    export ROS_PACKAGE_PATH=\
			    \       ~/uni/subj/proj30cp/catkin_ws/src/voice_node:$ROS_PACKAGE_PATH
		    elif [ -f /opt/ros/hydro/setup.bash ]; then
		        source /opt/ros/hydro/setup.bash
			    fi
			



source ~/uni/subj/proj30cp/catkin_ws/devel/setup.bash
