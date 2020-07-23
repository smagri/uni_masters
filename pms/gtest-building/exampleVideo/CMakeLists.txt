cmake_minimum_required(VERSION 2.8)

# Make PROJECT_SOURCE_DIR, PROJECT_BINARY_DIR, and PROJECT_NAME ava ilable.
set(PROJECT_NAME MyProject)
project(${PROJECT_NAME})

set(CMAKE_CXX_FLAGS "-g -Wall")

# For C++11 features you need to let the compiler know via CMake
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


################################
# Normal Libraries & Executables
################################
## sjm add_library(exampleVideo_lib exampleVideo.cpp)

#add_executable(exampleVideo main.cpp)
# Key idea: SEPARATE OUT your main() function into its own file so it can be its
# own executable. Separating out main() means you can add this library to be
# used elsewhere.

#target_link_libraries(exampleVideo exampleVideo_lib)


################################
# Testing
################################
# This adds another subdirectory, which has 'project(gtest)'.
add_subdirectory(lib/gtest-1.6.0)

enable_testing()

# Include the gtest library. gtest_SOURCE_DIR is available due to
# 'project(gtest)' above.
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR}
)

##############
# Unit Tests
##############
## sjm add_executable(runUnitTests exampleVideo.cpp)
add_executable(exampleVideo exampleVideo.cpp)

# Standard linking to gtest stuff.
target_link_libraries(exampleVideo gtest gtest_main)

# Extra linking for the project.
##sjm target_link_libraries(runUnitTests exampleVideo_lib)

# This is so you can do 'make test' to see all your tests run, instead of
# manually running the executable runUnitTests to see those specific tests.
## sjm add_test(NAME that-test-I-made COMMAND runUnitTests)

# You can also omit NAME and COMMAND. The second argument could be some other
# test executable.
## sjm add_test(that-other-test-I-made runUnitTests)
add_test(that-other-test-I-made exampleVideo)
