# The minimum version of CMake Required
cmake_minimum_required (VERSION 2.6)

# For C++11 features you need to let the compiler know via CMake
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Any ppoject name will suffice, this has connotaions when using
# advanced CMake Features
project (week5tutorial)

#add_executable(shapefunctions shapefunctions.cpp shape.cpp main.cpp)
#add_executable(shapefunctions rectangle.cpp shape.cpp main.cpp)
add_executable(shapeFns
  circle.cpp rectangle.cpp shapefunctions.cpp shape.cpp main.cpp)
