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
CMAKE_COMMAND = "/cygdrive/c/Users/Archibald Chain/AppData/Local/JetBrains/CLion2020.1/cygwin_cmake/bin/cmake.exe"

# The command to remove a file.
RM = "/cygdrive/c/Users/Archibald Chain/AppData/Local/JetBrains/CLion2020.1/cygwin_cmake/bin/cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/i/Programming/Cpp_workspace/CppLearningCode/CppAssignment/opencv_test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/i/Programming/Cpp_workspace/CppLearningCode/CppAssignment/opencv_test/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/circle_detection.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/circle_detection.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/circle_detection.dir/flags.make

CMakeFiles/circle_detection.dir/Lab_10/detect_circles.cpp.o: CMakeFiles/circle_detection.dir/flags.make
CMakeFiles/circle_detection.dir/Lab_10/detect_circles.cpp.o: ../Lab_10/detect_circles.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/i/Programming/Cpp_workspace/CppLearningCode/CppAssignment/opencv_test/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/circle_detection.dir/Lab_10/detect_circles.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/circle_detection.dir/Lab_10/detect_circles.cpp.o -c /cygdrive/i/Programming/Cpp_workspace/CppLearningCode/CppAssignment/opencv_test/Lab_10/detect_circles.cpp

CMakeFiles/circle_detection.dir/Lab_10/detect_circles.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/circle_detection.dir/Lab_10/detect_circles.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/i/Programming/Cpp_workspace/CppLearningCode/CppAssignment/opencv_test/Lab_10/detect_circles.cpp > CMakeFiles/circle_detection.dir/Lab_10/detect_circles.cpp.i

CMakeFiles/circle_detection.dir/Lab_10/detect_circles.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/circle_detection.dir/Lab_10/detect_circles.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/i/Programming/Cpp_workspace/CppLearningCode/CppAssignment/opencv_test/Lab_10/detect_circles.cpp -o CMakeFiles/circle_detection.dir/Lab_10/detect_circles.cpp.s

# Object files for target circle_detection
circle_detection_OBJECTS = \
"CMakeFiles/circle_detection.dir/Lab_10/detect_circles.cpp.o"

# External object files for target circle_detection
circle_detection_EXTERNAL_OBJECTS =

bin/circle_detection.exe: CMakeFiles/circle_detection.dir/Lab_10/detect_circles.cpp.o
bin/circle_detection.exe: CMakeFiles/circle_detection.dir/build.make
bin/circle_detection.exe: /usr/lib/libopencv_highgui.dll.a
bin/circle_detection.exe: /usr/lib/libopencv_videoio.dll.a
bin/circle_detection.exe: /usr/lib/libopencv_imgcodecs.dll.a
bin/circle_detection.exe: /usr/lib/libopencv_imgproc.dll.a
bin/circle_detection.exe: /usr/lib/libopencv_core.dll.a
bin/circle_detection.exe: CMakeFiles/circle_detection.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/i/Programming/Cpp_workspace/CppLearningCode/CppAssignment/opencv_test/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bin/circle_detection.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/circle_detection.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/circle_detection.dir/build: bin/circle_detection.exe

.PHONY : CMakeFiles/circle_detection.dir/build

CMakeFiles/circle_detection.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/circle_detection.dir/cmake_clean.cmake
.PHONY : CMakeFiles/circle_detection.dir/clean

CMakeFiles/circle_detection.dir/depend:
	cd /cygdrive/i/Programming/Cpp_workspace/CppLearningCode/CppAssignment/opencv_test/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/i/Programming/Cpp_workspace/CppLearningCode/CppAssignment/opencv_test /cygdrive/i/Programming/Cpp_workspace/CppLearningCode/CppAssignment/opencv_test /cygdrive/i/Programming/Cpp_workspace/CppLearningCode/CppAssignment/opencv_test/cmake-build-debug /cygdrive/i/Programming/Cpp_workspace/CppLearningCode/CppAssignment/opencv_test/cmake-build-debug /cygdrive/i/Programming/Cpp_workspace/CppLearningCode/CppAssignment/opencv_test/cmake-build-debug/CMakeFiles/circle_detection.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/circle_detection.dir/depend

