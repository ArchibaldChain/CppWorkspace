# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /usr/bin/cmake.exe

# The command to remove a file.
RM = /usr/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/i/Programming/CppWorkspace/CppAssignment/opencv_test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/i/Programming/CppWorkspace/CppAssignment/opencv_test/build

# Include any dependencies generated for this target.
include CMakeFiles/test5.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test5.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test5.dir/flags.make

CMakeFiles/test5.dir/Lab_10/main.cpp.o: CMakeFiles/test5.dir/flags.make
CMakeFiles/test5.dir/Lab_10/main.cpp.o: ../Lab_10/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/i/Programming/CppWorkspace/CppAssignment/opencv_test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test5.dir/Lab_10/main.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test5.dir/Lab_10/main.cpp.o -c /cygdrive/i/Programming/CppWorkspace/CppAssignment/opencv_test/Lab_10/main.cpp

CMakeFiles/test5.dir/Lab_10/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test5.dir/Lab_10/main.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/i/Programming/CppWorkspace/CppAssignment/opencv_test/Lab_10/main.cpp > CMakeFiles/test5.dir/Lab_10/main.cpp.i

CMakeFiles/test5.dir/Lab_10/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test5.dir/Lab_10/main.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/i/Programming/CppWorkspace/CppAssignment/opencv_test/Lab_10/main.cpp -o CMakeFiles/test5.dir/Lab_10/main.cpp.s

# Object files for target test5
test5_OBJECTS = \
"CMakeFiles/test5.dir/Lab_10/main.cpp.o"

# External object files for target test5
test5_EXTERNAL_OBJECTS =

bin/test5.exe: CMakeFiles/test5.dir/Lab_10/main.cpp.o
bin/test5.exe: CMakeFiles/test5.dir/build.make
bin/test5.exe: /usr/lib/libopencv_highgui.dll.a
bin/test5.exe: /usr/lib/libopencv_videoio.dll.a
bin/test5.exe: /usr/lib/libopencv_imgcodecs.dll.a
bin/test5.exe: /usr/lib/libopencv_imgproc.dll.a
bin/test5.exe: /usr/lib/libopencv_core.dll.a
bin/test5.exe: CMakeFiles/test5.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/i/Programming/CppWorkspace/CppAssignment/opencv_test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bin/test5.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test5.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test5.dir/build: bin/test5.exe

.PHONY : CMakeFiles/test5.dir/build

CMakeFiles/test5.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test5.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test5.dir/clean

CMakeFiles/test5.dir/depend:
	cd /cygdrive/i/Programming/CppWorkspace/CppAssignment/opencv_test/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/i/Programming/CppWorkspace/CppAssignment/opencv_test /cygdrive/i/Programming/CppWorkspace/CppAssignment/opencv_test /cygdrive/i/Programming/CppWorkspace/CppAssignment/opencv_test/build /cygdrive/i/Programming/CppWorkspace/CppAssignment/opencv_test/build /cygdrive/i/Programming/CppWorkspace/CppAssignment/opencv_test/build/CMakeFiles/test5.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test5.dir/depend

