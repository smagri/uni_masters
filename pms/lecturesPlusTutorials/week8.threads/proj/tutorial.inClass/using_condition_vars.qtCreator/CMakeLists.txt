# The minimum version of CMake Required 
cmake_minimum_required (VERSION 2.6)

# Any ppoject name will suffice, this has connotaions when using advanced CMake Features
project (using_cond_vars)

find_package (Threads)


#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++11 -pthread")

#add_executable(main main.cpp)
add_executable(usingCondVars main.cpp)

#target_link_libraries (test ${CMAKE_THREAD_LIBS_INIT})
