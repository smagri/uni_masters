# The minimum version of CMake Required
cmake_minimum_required (VERSION 2.6)

# Any ppoject name will suffice, this has connotaions when using
# advanced CMake Features
project (Assignment1)

# CMake will now ammend the Makefiles so that an executable
# "working" that requires "working.cpp" can be created

# CMake will now ammend the Makefiles so that an executable
# "ptrRef" that requires "ptrRef.cpp" can be created

# can be builing libraries or executables(need main fn) here
#add_executable(test test.cpp)

#add_executable(rectangle rectangle.cpp)

# builds rectangle binary only
#
#add_executable(rectangle rectangle.cpp shape.cpp main.cpp)

# builds triangle binary only
#
# main.cpp now uses rectangle and triangle objects so both .cpp's are
# required
#
#add_executable(triangle triangle.cpp rectangle.cpp shape.cpp main.cpp)

add_executable(laserRangeFinder laserRangeFinder.cpp sensor.cpp main.cpp)

