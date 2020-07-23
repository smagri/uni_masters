# The minimum version of CMake Required
cmake_minimum_required (VERSION 2.6)

# For C++11 features you need to let the compiler know via CMake
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g")

# Any ppoject name will suffice, this has connotaions when using
# advanced CMake Features
project (Week7tutorial)

#add_executable(ranger rangerFusion.cpp
#  sonar.cpp radar.cpp laser.cpp random.cpp ranger.cpp main.cpp)
add_executable(bfs main.cpp)
