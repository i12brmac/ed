# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/carla/Escritorio/ED/ed/P3/rbtrees

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/carla/Escritorio/ED/ed/P3/build

# Include any dependencies generated for this target.
include CMakeFiles/test_bstree.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/test_bstree.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/test_bstree.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_bstree.dir/flags.make

CMakeFiles/test_bstree.dir/test_bstree.cpp.o: CMakeFiles/test_bstree.dir/flags.make
CMakeFiles/test_bstree.dir/test_bstree.cpp.o: /home/carla/Escritorio/ED/ed/P3/rbtrees/test_bstree.cpp
CMakeFiles/test_bstree.dir/test_bstree.cpp.o: CMakeFiles/test_bstree.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/carla/Escritorio/ED/ed/P3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test_bstree.dir/test_bstree.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test_bstree.dir/test_bstree.cpp.o -MF CMakeFiles/test_bstree.dir/test_bstree.cpp.o.d -o CMakeFiles/test_bstree.dir/test_bstree.cpp.o -c /home/carla/Escritorio/ED/ed/P3/rbtrees/test_bstree.cpp

CMakeFiles/test_bstree.dir/test_bstree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_bstree.dir/test_bstree.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/carla/Escritorio/ED/ed/P3/rbtrees/test_bstree.cpp > CMakeFiles/test_bstree.dir/test_bstree.cpp.i

CMakeFiles/test_bstree.dir/test_bstree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_bstree.dir/test_bstree.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/carla/Escritorio/ED/ed/P3/rbtrees/test_bstree.cpp -o CMakeFiles/test_bstree.dir/test_bstree.cpp.s

# Object files for target test_bstree
test_bstree_OBJECTS = \
"CMakeFiles/test_bstree.dir/test_bstree.cpp.o"

# External object files for target test_bstree
test_bstree_EXTERNAL_OBJECTS =

test_bstree: CMakeFiles/test_bstree.dir/test_bstree.cpp.o
test_bstree: CMakeFiles/test_bstree.dir/build.make
test_bstree: CMakeFiles/test_bstree.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/carla/Escritorio/ED/ed/P3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test_bstree"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_bstree.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_bstree.dir/build: test_bstree
.PHONY : CMakeFiles/test_bstree.dir/build

CMakeFiles/test_bstree.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_bstree.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_bstree.dir/clean

CMakeFiles/test_bstree.dir/depend:
	cd /home/carla/Escritorio/ED/ed/P3/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/carla/Escritorio/ED/ed/P3/rbtrees /home/carla/Escritorio/ED/ed/P3/rbtrees /home/carla/Escritorio/ED/ed/P3/build /home/carla/Escritorio/ED/ed/P3/build /home/carla/Escritorio/ED/ed/P3/build/CMakeFiles/test_bstree.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_bstree.dir/depend

