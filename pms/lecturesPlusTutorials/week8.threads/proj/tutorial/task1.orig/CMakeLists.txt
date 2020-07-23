project(task1)

cmake_minimum_required(VERSION 2.8)

find_package(Threads)

# For C++11 features you need to let the compiler know via CMake
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -pthread")

aux_source_directory(. SRC_LIST)
add_executable(${PROJECT_NAME} ${SRC_LIST})
