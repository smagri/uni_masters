# The minimum version of CMake Required
cmake_minimum_required (VERSION 2.6)

#find_package(Threads)

# For C++11 features you need to let the compiler know via CMake
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -pthread")

# Any ppoject name will suffice, this has connotaions when using
# advanced CMake Features
project (Assignment3)

# partA
#add_executable(ranger sonar.cpp radar.cpp ranger.cpp main.cpp)

# partB
##add_executable(ranger rangerFusion.cpp RangerFusionInterface.cpp
##  sonar.cpp radar.cpp laser.cpp ranger.cpp main.cpp)
#add_executable(ranger rangerFusion.cpp
#  sonar.cpp radar.cpp laser.cpp random.cpp ranger.cpp main.cpp)

#add_executable(ranger rangerFusion.cpp RangerFusionInterface.cpp
# sonar.cpp radar.cpp ranger.cpp main.cpp)
add_executable(dataFusion dataFusion.cpp
  sonar.cpp radar.cpp ranger.cpp main.cpp)

# works for testing:
#
#add_executable(ranger shape.cpp rectangle.cpp main.cpp)


# add a target to generate API documentation with Doxygen
find_package(Doxygen)
if(DOXYGEN_FOUND)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)
add_custom_target(doc
    ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Generating API documentation with Doxygen" VERBATIM
)
endif(DOXYGEN_FOUND)
