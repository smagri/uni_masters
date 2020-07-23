# The minimum version of CMake Required 
cmake_minimum_required (VERSION 2.6)

# Any ppoject name will suffice, this has connotaions when using advanced CMake Features
project (Assign2)

# CMake will now create the Makefiles that are needed to make an executable "hello" that requires "hello.cpp" 
add_executable(Assign2 Assign2.cpp RangerFusionInterface.cpp Ranger.cpp Radar.cpp Sonar.cpp Laser.cpp RangerFusion.cpp)
 
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
