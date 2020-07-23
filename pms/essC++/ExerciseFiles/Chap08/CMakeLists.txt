# The minimum version of CMake Required
cmake_minimum_required (VERSION 2.6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Any ppoject name will suffice, this has connotaions when using
# advanced CMake Features
project (Chap08)

# CMake will now ammend the Makefiles so that an executable
# "working" that requires "working.cpp" can be created
#add_executable(working working.cpp)

# CMake will now ammend the Makefiles so that an executable
# "working" that requires "working.cpp" can be created
add_executable(template-function template-function.cpp)

add_executable(template-class template-class.cpp)

add_executable(decltype decltype.cpp)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
