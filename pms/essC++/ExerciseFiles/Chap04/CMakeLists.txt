# The minimum version of CMake Required
cmake_minimum_required (VERSION 2.6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Any ppoject name will suffice, this has connotaions when using
# advanced CMake Features
project (Chap04)

# CMake will now ammend the Makefiles so that an executable
# "working" that requires "working.cpp" can be created
add_executable(working working.cpp)

# CMake will now ammend the Makefiles so that an executable
# "working" that requires "working.cpp" can be created
add_executable(class class.cpp)

# CMake will now ammend the Makefiles so that an executable
# "working" that requires "working.cpp" can be created
add_executable(accessors accessors.cpp)

# CMake will now ammend the Makefiles so that an executable
# "working" that requires "working.cpp" can be created
add_executable(constructors constructors.cpp)

# CMake will now ammend the Makefiles so that an executable
# "working" that requires "working.cpp" can be created
add_executable(implicit-explicit implicit-explicit.cpp)

# CMake will now ammend the Makefiles so that an executable
# "working" that requires "working.cpp" can be created
add_executable(namespace namespace.cpp)

# CMake will now ammend the Makefiles so that an executable
# "working" that requires "working.cpp" can be created
add_executable(rational rational.cpp)

# CMake will now ammend the Makefiles so that an executable
# "working" that requires "working.cpp" can be created
add_executable(new-delete new-delete.cpp)

# CMake will now ammend the Makefiles so that an executable
# "working" that requires "working.cpp" can be created
add_executable(exceptions exceptions.cpp)

# CMake will now ammend the Makefiles so that an executable
# "working" that requires "working.cpp" can be created
add_executable(function-object function-object.cpp)

# CMake will now ammend the Makefiles so that an executable
# "working" that requires "working.cpp" can be created
#
# numword.cpp is class, numword-test.cpp is main.cpp
add_executable(numword-test numword.cpp numword-test.cpp)

# CMake will now ammend the Makefiles so that an executable
# "working" that requires "working.cpp" can be created
#add_executable(numword numword.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
