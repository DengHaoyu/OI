# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /home/dhy/Develop/C++/clion-2018.1.5/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/dhy/Develop/C++/clion-2018.1.5/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dhy/Develop/OI

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dhy/Develop/OI/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/OI.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/OI.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/OI.dir/flags.make

CMakeFiles/OI.dir/P1309.cpp.o: CMakeFiles/OI.dir/flags.make
CMakeFiles/OI.dir/P1309.cpp.o: ../P1309.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dhy/Develop/OI/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/OI.dir/P1309.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OI.dir/P1309.cpp.o -c /home/dhy/Develop/OI/P1309.cpp

CMakeFiles/OI.dir/P1309.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OI.dir/P1309.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dhy/Develop/OI/P1309.cpp > CMakeFiles/OI.dir/P1309.cpp.i

CMakeFiles/OI.dir/P1309.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OI.dir/P1309.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dhy/Develop/OI/P1309.cpp -o CMakeFiles/OI.dir/P1309.cpp.s

CMakeFiles/OI.dir/P1309.cpp.o.requires:

.PHONY : CMakeFiles/OI.dir/P1309.cpp.o.requires

CMakeFiles/OI.dir/P1309.cpp.o.provides: CMakeFiles/OI.dir/P1309.cpp.o.requires
	$(MAKE) -f CMakeFiles/OI.dir/build.make CMakeFiles/OI.dir/P1309.cpp.o.provides.build
.PHONY : CMakeFiles/OI.dir/P1309.cpp.o.provides

CMakeFiles/OI.dir/P1309.cpp.o.provides.build: CMakeFiles/OI.dir/P1309.cpp.o


# Object files for target OI
OI_OBJECTS = \
"CMakeFiles/OI.dir/P1309.cpp.o"

# External object files for target OI
OI_EXTERNAL_OBJECTS =

OI: CMakeFiles/OI.dir/P1309.cpp.o
OI: CMakeFiles/OI.dir/build.make
OI: CMakeFiles/OI.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dhy/Develop/OI/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable OI"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/OI.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/OI.dir/build: OI

.PHONY : CMakeFiles/OI.dir/build

CMakeFiles/OI.dir/requires: CMakeFiles/OI.dir/P1309.cpp.o.requires

.PHONY : CMakeFiles/OI.dir/requires

CMakeFiles/OI.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/OI.dir/cmake_clean.cmake
.PHONY : CMakeFiles/OI.dir/clean

CMakeFiles/OI.dir/depend:
	cd /home/dhy/Develop/OI/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dhy/Develop/OI /home/dhy/Develop/OI /home/dhy/Develop/OI/cmake-build-debug /home/dhy/Develop/OI/cmake-build-debug /home/dhy/Develop/OI/cmake-build-debug/CMakeFiles/OI.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/OI.dir/depend

