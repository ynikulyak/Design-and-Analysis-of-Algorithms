# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/jane/CLionProjects/assignment

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/jane/CLionProjects/assignment/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/assignment.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/assignment.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/assignment.dir/flags.make

CMakeFiles/assignment.dir/assignment.cpp.o: CMakeFiles/assignment.dir/flags.make
CMakeFiles/assignment.dir/assignment.cpp.o: ../assignment.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jane/CLionProjects/assignment/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/assignment.dir/assignment.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/assignment.dir/assignment.cpp.o -c /Users/jane/CLionProjects/assignment/assignment.cpp

CMakeFiles/assignment.dir/assignment.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/assignment.dir/assignment.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jane/CLionProjects/assignment/assignment.cpp > CMakeFiles/assignment.dir/assignment.cpp.i

CMakeFiles/assignment.dir/assignment.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/assignment.dir/assignment.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jane/CLionProjects/assignment/assignment.cpp -o CMakeFiles/assignment.dir/assignment.cpp.s

# Object files for target assignment
assignment_OBJECTS = \
"CMakeFiles/assignment.dir/assignment.cpp.o"

# External object files for target assignment
assignment_EXTERNAL_OBJECTS =

assignment: CMakeFiles/assignment.dir/assignment.cpp.o
assignment: CMakeFiles/assignment.dir/build.make
assignment: CMakeFiles/assignment.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/jane/CLionProjects/assignment/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable assignment"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/assignment.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/assignment.dir/build: assignment

.PHONY : CMakeFiles/assignment.dir/build

CMakeFiles/assignment.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/assignment.dir/cmake_clean.cmake
.PHONY : CMakeFiles/assignment.dir/clean

CMakeFiles/assignment.dir/depend:
	cd /Users/jane/CLionProjects/assignment/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jane/CLionProjects/assignment /Users/jane/CLionProjects/assignment /Users/jane/CLionProjects/assignment/cmake-build-debug /Users/jane/CLionProjects/assignment/cmake-build-debug /Users/jane/CLionProjects/assignment/cmake-build-debug/CMakeFiles/assignment.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/assignment.dir/depend

