# The minimum version of CMake Required
cmake_minimum_required (VERSION 2.6)

# For C++11 features you need to let the compiler know via CMake
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


# Any ppoject name will suffice, this has connotaions when using
# advanced CMake Features
project (week11tutorial)

# CMake will now ammend the Makefiles so that an executable
# "working" that requires "working.cpp" can be created

# works for before class Random included
#add_executable(laserRangeFinder laserRangeFinder.cpp sensor.cpp main.cpp)

# include class Random
#add_executable(laserRangeFinder
#random.cpp laserRangeFinder.cpp sensor.cpp main.cpp)

#add_executable(shapeFns
#  circle.cpp rectangle.cpp shapefunctions.cpp shape.cpp main.cpp)

#add_executable(task3 task3.cpp)
#add_executable(usingTemplateFns usingTemplateFns.cpp)
#add_executable(student student.cpp main.cpp)
add_executable(displayImage main.cpp)
