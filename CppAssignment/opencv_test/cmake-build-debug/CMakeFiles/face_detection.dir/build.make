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
include CMakeFiles/face_detection.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/face_detection.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/face_detection.dir/flags.make

CMakeFiles/face_detection.dir/Lab_10/detect_face.cpp.o: CMakeFiles/face_detection.dir/flags.make
CMakeFiles/face_detection.dir/Lab_10/detect_face.cpp.o: ../Lab_10/detect_face.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/i/Programming/Cpp_workspace/CppLearningCode/CppAssignment/opencv_test/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/face_detection.dir/Lab_10/detect_face.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/face_detection.dir/Lab_10/detect_face.cpp.o -c /cygdrive/i/Programming/Cpp_workspace/CppLearningCode/CppAssignment/opencv_test/Lab_10/detect_face.cpp

CMakeFiles/face_detection.dir/Lab_10/detect_face.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/face_detection.dir/Lab_10/detect_face.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/i/Programming/Cpp_workspace/CppLearningCode/CppAssignment/opencv_test/Lab_10/detect_face.cpp > CMakeFiles/face_detection.dir/Lab_10/detect_face.cpp.i

CMakeFiles/face_detection.dir/Lab_10/detect_face.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/face_detection.dir/Lab_10/detect_face.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/i/Programming/Cpp_workspace/CppLearningCode/CppAssignment/opencv_test/Lab_10/detect_face.cpp -o CMakeFiles/face_detection.dir/Lab_10/detect_face.cpp.s

# Object files for target face_detection
face_detection_OBJECTS = \
"CMakeFiles/face_detection.dir/Lab_10/detect_face.cpp.o"

# External object files for target face_detection
face_detection_EXTERNAL_OBJECTS =

bin/face_detection.exe: CMakeFiles/face_detection.dir/Lab_10/detect_face.cpp.o
bin/face_detection.exe: CMakeFiles/face_detection.dir/build.make
bin/face_detection.exe: /usr/lib/libopencv_aruco.dll.a
bin/face_detection.exe: /usr/lib/libopencv_bgsegm.dll.a
bin/face_detection.exe: /usr/lib/libopencv_bioinspired.dll.a
bin/face_detection.exe: /usr/lib/libopencv_ccalib.dll.a
bin/face_detection.exe: /usr/lib/libopencv_dpm.dll.a
bin/face_detection.exe: /usr/lib/libopencv_face.dll.a
bin/face_detection.exe: /usr/lib/libopencv_freetype.dll.a
bin/face_detection.exe: /usr/lib/libopencv_fuzzy.dll.a
bin/face_detection.exe: /usr/lib/libopencv_hdf.dll.a
bin/face_detection.exe: /usr/lib/libopencv_hfs.dll.a
bin/face_detection.exe: /usr/lib/libopencv_img_hash.dll.a
bin/face_detection.exe: /usr/lib/libopencv_line_descriptor.dll.a
bin/face_detection.exe: /usr/lib/libopencv_optflow.dll.a
bin/face_detection.exe: /usr/lib/libopencv_reg.dll.a
bin/face_detection.exe: /usr/lib/libopencv_rgbd.dll.a
bin/face_detection.exe: /usr/lib/libopencv_saliency.dll.a
bin/face_detection.exe: /usr/lib/libopencv_shape.dll.a
bin/face_detection.exe: /usr/lib/libopencv_stereo.dll.a
bin/face_detection.exe: /usr/lib/libopencv_stitching.dll.a
bin/face_detection.exe: /usr/lib/libopencv_structured_light.dll.a
bin/face_detection.exe: /usr/lib/libopencv_superres.dll.a
bin/face_detection.exe: /usr/lib/libopencv_surface_matching.dll.a
bin/face_detection.exe: /usr/lib/libopencv_tracking.dll.a
bin/face_detection.exe: /usr/lib/libopencv_videostab.dll.a
bin/face_detection.exe: /usr/lib/libopencv_ximgproc.dll.a
bin/face_detection.exe: /usr/lib/libopencv_xobjdetect.dll.a
bin/face_detection.exe: /usr/lib/libopencv_xphoto.dll.a
bin/face_detection.exe: /usr/lib/libopencv_datasets.dll.a
bin/face_detection.exe: /usr/lib/libopencv_ml.dll.a
bin/face_detection.exe: /usr/lib/libopencv_plot.dll.a
bin/face_detection.exe: /usr/lib/libopencv_phase_unwrapping.dll.a
bin/face_detection.exe: /usr/lib/libopencv_calib3d.dll.a
bin/face_detection.exe: /usr/lib/libopencv_features2d.dll.a
bin/face_detection.exe: /usr/lib/libopencv_flann.dll.a
bin/face_detection.exe: /usr/lib/libopencv_highgui.dll.a
bin/face_detection.exe: /usr/lib/libopencv_photo.dll.a
bin/face_detection.exe: /usr/lib/libopencv_video.dll.a
bin/face_detection.exe: /usr/lib/libopencv_videoio.dll.a
bin/face_detection.exe: /usr/lib/libopencv_imgcodecs.dll.a
bin/face_detection.exe: /usr/lib/libopencv_objdetect.dll.a
bin/face_detection.exe: /usr/lib/libopencv_imgproc.dll.a
bin/face_detection.exe: /usr/lib/libopencv_core.dll.a
bin/face_detection.exe: CMakeFiles/face_detection.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/i/Programming/Cpp_workspace/CppLearningCode/CppAssignment/opencv_test/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bin/face_detection.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/face_detection.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/face_detection.dir/build: bin/face_detection.exe

.PHONY : CMakeFiles/face_detection.dir/build

CMakeFiles/face_detection.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/face_detection.dir/cmake_clean.cmake
.PHONY : CMakeFiles/face_detection.dir/clean

CMakeFiles/face_detection.dir/depend:
	cd /cygdrive/i/Programming/Cpp_workspace/CppLearningCode/CppAssignment/opencv_test/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/i/Programming/Cpp_workspace/CppLearningCode/CppAssignment/opencv_test /cygdrive/i/Programming/Cpp_workspace/CppLearningCode/CppAssignment/opencv_test /cygdrive/i/Programming/Cpp_workspace/CppLearningCode/CppAssignment/opencv_test/cmake-build-debug /cygdrive/i/Programming/Cpp_workspace/CppLearningCode/CppAssignment/opencv_test/cmake-build-debug /cygdrive/i/Programming/Cpp_workspace/CppLearningCode/CppAssignment/opencv_test/cmake-build-debug/CMakeFiles/face_detection.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/face_detection.dir/depend

