# The minimum version of CMake Required
cmake_minimum_required (VERSION 2.6)

# Any ppoject name will suffice, this has connotaions when using
# advanced CMake Features
project (LectureWeek1)

# CMake will now ammend the Makefiles so that an executable
# "working" that requires "working.cpp" can be created

# CMake will now ammend the Makefiles so that an executable
# "ptrRef" that requires "ptrRef.cpp" can be created

# can be builing libraries or executables(need main fn) here
add_executable(ptrRef ptrRef.cpp)

add_executable(craysMacros craysMacros.cpp)

add_executable(cStrings cStrings.cpp)

add_executable(loops loops.cpp)

add_executable(switchCase switchCase.cpp)

add_executable(functions functions.cpp)
