# The minimum version of CMake Required 
cmake_minimum_required (VERSION 2.6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Any project name will suffice, this has connotaions when using advanced CMake Features
project (Assignment2)

# CMake will now create the Makefiles that are needed to make an executable "main" that requires "main.cpp" and other stuff 
add_executable(main
laser.cpp
main.cpp
radar.cpp
ranger.cpp
sonar.cpp
rangerfusion.cpp
RangerFusionInterface.h)
