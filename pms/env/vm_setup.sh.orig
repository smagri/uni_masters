#!/usr/bin/env bash

CATKIN_SHELL=bash

#CATKIN
mkdir -p ~/catkin_ws/src
cd ~/catkin_ws/src
catkin_init_workspace
cd ~/catkin_ws/
catkin_make
#ROSBUILD
mkdir ~/rosbuild_ws
cd ~/rosbuild_ws
rosws init . ~/catkin_ws/devel
mkdir ~/rosbuild_ws/sandbox
rosws set ~/rosbuild_ws/sandbox/

echo source /home/vmuser/rosbuild_ws/setup.bash >> ~/.bashrc
source ~/.bashrc

#RA_ROS SETUP
cd ~/catkin_ws/src
cd ~/catkin_ws/
catkin_make

