# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /lu1/smagri/uni/subj/pms/essentialC++/Ex_Files_Cpp_EssT/ExerciseFiles/Chap02

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /lu1/smagri/uni/subj/pms/essentialC++/Ex_Files_Cpp_EssT/ExerciseFiles/Chap02/build

# Include any dependencies generated for this target.
include CMakeFiles/working.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/working.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/working.dir/flags.make

CMakeFiles/working.dir/working.cpp.o: CMakeFiles/working.dir/flags.make
CMakeFiles/working.dir/working.cpp.o: ../working.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/lu1/smagri/uni/subj/pms/essentialC++/Ex_Files_Cpp_EssT/ExerciseFiles/Chap02/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/working.dir/working.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/working.dir/working.cpp.o -c /lu1/smagri/uni/subj/pms/essentialC++/Ex_Files_Cpp_EssT/ExerciseFiles/Chap02/working.cpp

CMakeFiles/working.dir/working.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/working.dir/working.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /lu1/smagri/uni/subj/pms/essentialC++/Ex_Files_Cpp_EssT/ExerciseFiles/Chap02/working.cpp > CMakeFiles/working.dir/working.cpp.i

CMakeFiles/working.dir/working.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/working.dir/working.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /lu1/smagri/uni/subj/pms/essentialC++/Ex_Files_Cpp_EssT/ExerciseFiles/Chap02/working.cpp -o CMakeFiles/working.dir/working.cpp.s

CMakeFiles/working.dir/working.cpp.o.requires:

.PHONY : CMakeFiles/working.dir/working.cpp.o.requires

CMakeFiles/working.dir/working.cpp.o.provides: CMakeFiles/working.dir/working.cpp.o.requires
	$(MAKE) -f CMakeFiles/working.dir/build.make CMakeFiles/working.dir/working.cpp.o.provides.build
.PHONY : CMakeFiles/working.dir/working.cpp.o.provides

CMakeFiles/working.dir/working.cpp.o.provides.build: CMakeFiles/working.dir/working.cpp.o


# Object files for target working
working_OBJECTS = \
"CMakeFiles/working.dir/working.cpp.o"

# External object files for target working
working_EXTERNAL_OBJECTS =

working: CMakeFiles/working.dir/working.cpp.o
working: CMakeFiles/working.dir/build.make
working: CMakeFiles/working.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/lu1/smagri/uni/subj/pms/essentialC++/Ex_Files_Cpp_EssT/ExerciseFiles/Chap02/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable working"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/working.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/working.dir/build: working

.PHONY : CMakeFiles/working.dir/build

CMakeFiles/working.dir/requires: CMakeFiles/working.dir/working.cpp.o.requires

.PHONY : CMakeFiles/working.dir/requires

CMakeFiles/working.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/working.dir/cmake_clean.cmake
.PHONY : CMakeFiles/working.dir/clean

CMakeFiles/working.dir/depend:
	cd /lu1/smagri/uni/subj/pms/essentialC++/Ex_Files_Cpp_EssT/ExerciseFiles/Chap02/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /lu1/smagri/uni/subj/pms/essentialC++/Ex_Files_Cpp_EssT/ExerciseFiles/Chap02 /lu1/smagri/uni/subj/pms/essentialC++/Ex_Files_Cpp_EssT/ExerciseFiles/Chap02 /lu1/smagri/uni/subj/pms/essentialC++/Ex_Files_Cpp_EssT/ExerciseFiles/Chap02/build /lu1/smagri/uni/subj/pms/essentialC++/Ex_Files_Cpp_EssT/ExerciseFiles/Chap02/build /lu1/smagri/uni/subj/pms/essentialC++/Ex_Files_Cpp_EssT/ExerciseFiles/Chap02/build/CMakeFiles/working.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/working.dir/depend

