# The minimum version of CMake Required
cmake_minimum_required (VERSION 2.6)

# Any ppoject name will suffice, this has connotaions when using
# advanced CMake Features
project (TutorialWeek2)

# CMake will now ammend the Makefiles so that an executable
# "working" that requires "working.cpp" can be created

# CMake will now ammend the Makefiles so that an executable
# "ptrRef" that requires "ptrRef.cpp" can be created

# can be builing libraries or executables(need main fn) here
add_executable(test test.cpp)

add_executable(rectangle rectangle.cpp main.cpp)
