project(Assignment2)
cmake_minimum_required(VERSION 2.8)
aux_source_directory(. SRC_LIST)
add_executable(main main.cpp ranger.cpp radar.cpp sonar.cpp laser.cpp rangerfusioninterface.cpp rangerfusion.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
