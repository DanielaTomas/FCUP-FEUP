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
CMAKE_SOURCE_DIR = /home/daniela/2ºano/Programação/progp1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/daniela/2ºano/Programação/progp1/build

# Include any dependencies generated for this target.
include CMakeFiles/color_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/color_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/color_test.dir/flags.make

CMakeFiles/color_test.dir/test/color_test.cpp.o: CMakeFiles/color_test.dir/flags.make
CMakeFiles/color_test.dir/test/color_test.cpp.o: ../test/color_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/daniela/2ºano/Programação/progp1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/color_test.dir/test/color_test.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/color_test.dir/test/color_test.cpp.o -c /home/daniela/2ºano/Programação/progp1/test/color_test.cpp

CMakeFiles/color_test.dir/test/color_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/color_test.dir/test/color_test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/daniela/2ºano/Programação/progp1/test/color_test.cpp > CMakeFiles/color_test.dir/test/color_test.cpp.i

CMakeFiles/color_test.dir/test/color_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/color_test.dir/test/color_test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/daniela/2ºano/Programação/progp1/test/color_test.cpp -o CMakeFiles/color_test.dir/test/color_test.cpp.s

# Object files for target color_test
color_test_OBJECTS = \
"CMakeFiles/color_test.dir/test/color_test.cpp.o"

# External object files for target color_test
color_test_EXTERNAL_OBJECTS =

color_test: CMakeFiles/color_test.dir/test/color_test.cpp.o
color_test: CMakeFiles/color_test.dir/build.make
color_test: librgb.a
color_test: lib/libgtest.a
color_test: lib/libgtest_main.a
color_test: lib/libgtest.a
color_test: CMakeFiles/color_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/daniela/2ºano/Programação/progp1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable color_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/color_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/color_test.dir/build: color_test

.PHONY : CMakeFiles/color_test.dir/build

CMakeFiles/color_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/color_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/color_test.dir/clean

CMakeFiles/color_test.dir/depend:
	cd /home/daniela/2ºano/Programação/progp1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/daniela/2ºano/Programação/progp1 /home/daniela/2ºano/Programação/progp1 /home/daniela/2ºano/Programação/progp1/build /home/daniela/2ºano/Programação/progp1/build /home/daniela/2ºano/Programação/progp1/build/CMakeFiles/color_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/color_test.dir/depend

