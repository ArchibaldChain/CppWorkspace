# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.16

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.3.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.3.3\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = I:\Programming\CppWorkspace\CppAssignment\Assignment4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = I:\Programming\CppWorkspace\CppAssignment\Assignment4\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Assignment4.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Assignment4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Assignment4.dir/flags.make

CMakeFiles/Assignment4.dir/question1-3.cpp.obj: CMakeFiles/Assignment4.dir/flags.make
CMakeFiles/Assignment4.dir/question1-3.cpp.obj: ../question1-3.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=I:\Programming\CppWorkspace\CppAssignment\Assignment4\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Assignment4.dir/question1-3.cpp.obj"
	C:\Programming\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Assignment4.dir\question1-3.cpp.obj -c I:\Programming\CppWorkspace\CppAssignment\Assignment4\question1-3.cpp

CMakeFiles/Assignment4.dir/question1-3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Assignment4.dir/question1-3.cpp.i"
	C:\Programming\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E I:\Programming\CppWorkspace\CppAssignment\Assignment4\question1-3.cpp > CMakeFiles\Assignment4.dir\question1-3.cpp.i

CMakeFiles/Assignment4.dir/question1-3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Assignment4.dir/question1-3.cpp.s"
	C:\Programming\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S I:\Programming\CppWorkspace\CppAssignment\Assignment4\question1-3.cpp -o CMakeFiles\Assignment4.dir\question1-3.cpp.s

# Object files for target Assignment4
Assignment4_OBJECTS = \
"CMakeFiles/Assignment4.dir/question1-3.cpp.obj"

# External object files for target Assignment4
Assignment4_EXTERNAL_OBJECTS =

Assignment4.exe: CMakeFiles/Assignment4.dir/question1-3.cpp.obj
Assignment4.exe: CMakeFiles/Assignment4.dir/build.make
Assignment4.exe: CMakeFiles/Assignment4.dir/linklibs.rsp
Assignment4.exe: CMakeFiles/Assignment4.dir/objects1.rsp
Assignment4.exe: CMakeFiles/Assignment4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=I:\Programming\CppWorkspace\CppAssignment\Assignment4\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Assignment4.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Assignment4.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Assignment4.dir/build: Assignment4.exe

.PHONY : CMakeFiles/Assignment4.dir/build

CMakeFiles/Assignment4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Assignment4.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Assignment4.dir/clean

CMakeFiles/Assignment4.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" I:\Programming\CppWorkspace\CppAssignment\Assignment4 I:\Programming\CppWorkspace\CppAssignment\Assignment4 I:\Programming\CppWorkspace\CppAssignment\Assignment4\cmake-build-debug I:\Programming\CppWorkspace\CppAssignment\Assignment4\cmake-build-debug I:\Programming\CppWorkspace\CppAssignment\Assignment4\cmake-build-debug\CMakeFiles\Assignment4.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Assignment4.dir/depend

