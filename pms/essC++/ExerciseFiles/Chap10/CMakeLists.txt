# The minimum version of CMake Required
cmake_minimum_required (VERSION 2.6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Any ppoject name will suffice, this has connotaions when using
# advanced CMake Features
project (Chap10)

# CMake will now ammend the Makefiles so that an executable
# "working" that requires "working.cpp" can be created
#add_executable(working working.cpp)

# CMake will now ammend the Makefiles so that an executable
# "working" that requires "working.cpp" can be created
add_executable(vector vector.cpp)

add_executable(string string.cpp)

add_executable(iostream-formatting iostream-formatting.cpp)

add_executable(iostream-file iostream-file.cpp)

add_executable(iterator iterator.cpp)

add_executable(list list.cpp)

add_executable(working working.cpp)

add_executable(set set.cpp)

add_executable(map map.cpp)

add_executable(stack stack.cpp)
add_executable(queue queue.cpp)
add_executable(deque deque.cpp)

add_executable(exception exception.cpp)

