# The minimum version of CMake Required. note 2.7+ could enable c++11
cmake_minimum_required (VERSION 2.8)

# Any project name will suffice, this has connotaions when using advanced CMake Features
project (assignmentonesensor)

# CMake will now create the Makefiles that are needed to execute the sensor.
add_executable(main main.cpp sensor.h sensor.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

