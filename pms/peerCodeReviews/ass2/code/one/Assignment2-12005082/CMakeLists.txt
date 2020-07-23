# The minimum version of CMake Required 
cmake_minimum_required (VERSION 2.6)

# Any ppoject name will suffice, this has connotaions when using advanced CMake Features
project (Assignment2-12005082)

# CMake will now create the Makefiles that are needed to make an executable "hello" that requires "hello.cpp" 
add_executable(Main Main.cpp ranger.cpp ranger.h rangerfusioninterface.h rangerfusioninterface.cpp laser.cpp laser.h radar.cpp radar.h sonar.cpp sonar.h rangerfusion.cpp rangerfusion.h)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
