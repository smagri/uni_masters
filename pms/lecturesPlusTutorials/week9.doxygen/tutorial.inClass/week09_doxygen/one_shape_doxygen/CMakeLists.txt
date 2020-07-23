# The minimum version of CMake Required 
cmake_minimum_required (VERSION 2.6)

# Any ppoject name will suffice, this has connotaions when using advanced CMake Features
project (one_shape)

# CMake will now create the Makefiles that are needed to make an
# executable "hello" that requires "hello.cpp"
add_library(shapes shape.cpp rectangle.cpp)
add_executable(shape_eg main.cpp)
target_link_libraries(shape_eg shapes)

add_subdirectory(lib/gtest-1.6.0)
rectory(lib/gtest-1.6.0)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR}
  )
add_executable(shape_eg shape_test.cpp)

# Standard linking to gtest stuff.
target_link_libraries(shape_tests gtest gtest_main)

# Extra linking for the project.
target_link_libraries(shapes_test shapes)

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
