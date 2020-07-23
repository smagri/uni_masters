project(task1_condVar)

cmake_minimum_required(VERSION 2.8)

# For C++11 features you need to let the compiler know via CMake
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -pthread")

find_package(Threads)

aux_source_directory(. SRC_LIST)

add_executable(condVar ${SRC_LIST})
