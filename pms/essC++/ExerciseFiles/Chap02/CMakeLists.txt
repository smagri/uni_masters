# The minimum version of CMake Required
cmake_minimum_required (VERSION 2.6)

# Any ppoject name will suffice, this has connotaions when using
# advanced CMake Features
project (Chap02)

# CMake will now ammend the Makefiles so that an executable
# "working" that requires "working.cpp" can be created
add_executable(working working.cpp)

add_executable(func func.cpp)

add_executable(func-fnValuePassByRef++ func-fnValuePassByRef++.cpp)

add_executable(jump jump.cpp)

add_executable(func-overload func-overload.cpp)

add_executable(func-operator func-operator.cpp)

add_executable(variadic variadic.cpp)
