# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/tang/myproject/tang_test/cTest

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tang/myproject/tang_test/cTest/build

# Include any dependencies generated for this target.
include CMakeFiles/queuetest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/queuetest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/queuetest.dir/flags.make

CMakeFiles/queuetest.dir/queuetest.cpp.o: CMakeFiles/queuetest.dir/flags.make
CMakeFiles/queuetest.dir/queuetest.cpp.o: ../queuetest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tang/myproject/tang_test/cTest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/queuetest.dir/queuetest.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/queuetest.dir/queuetest.cpp.o -c /home/tang/myproject/tang_test/cTest/queuetest.cpp

CMakeFiles/queuetest.dir/queuetest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/queuetest.dir/queuetest.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tang/myproject/tang_test/cTest/queuetest.cpp > CMakeFiles/queuetest.dir/queuetest.cpp.i

CMakeFiles/queuetest.dir/queuetest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/queuetest.dir/queuetest.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tang/myproject/tang_test/cTest/queuetest.cpp -o CMakeFiles/queuetest.dir/queuetest.cpp.s

# Object files for target queuetest
queuetest_OBJECTS = \
"CMakeFiles/queuetest.dir/queuetest.cpp.o"

# External object files for target queuetest
queuetest_EXTERNAL_OBJECTS =

bin/queuetest: CMakeFiles/queuetest.dir/queuetest.cpp.o
bin/queuetest: CMakeFiles/queuetest.dir/build.make
bin/queuetest: CMakeFiles/queuetest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tang/myproject/tang_test/cTest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bin/queuetest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/queuetest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/queuetest.dir/build: bin/queuetest

.PHONY : CMakeFiles/queuetest.dir/build

CMakeFiles/queuetest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/queuetest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/queuetest.dir/clean

CMakeFiles/queuetest.dir/depend:
	cd /home/tang/myproject/tang_test/cTest/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tang/myproject/tang_test/cTest /home/tang/myproject/tang_test/cTest /home/tang/myproject/tang_test/cTest/build /home/tang/myproject/tang_test/cTest/build /home/tang/myproject/tang_test/cTest/build/CMakeFiles/queuetest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/queuetest.dir/depend
