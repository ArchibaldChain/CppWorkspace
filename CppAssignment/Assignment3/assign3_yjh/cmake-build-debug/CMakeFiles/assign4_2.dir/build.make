# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = "E:\JetBrains\Clion 2019.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "E:\JetBrains\Clion 2019.2.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\CProjects\assign4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\CProjects\assign4\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/assign4_2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/assign4_2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/assign4_2.dir/flags.make

CMakeFiles/assign4_2.dir/assign4_2.cpp.obj: CMakeFiles/assign4_2.dir/flags.make
CMakeFiles/assign4_2.dir/assign4_2.cpp.obj: ../assign4_2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\CProjects\assign4\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/assign4_2.dir/assign4_2.cpp.obj"
	E:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\assign4_2.dir\assign4_2.cpp.obj -c E:\CProjects\assign4\assign4_2.cpp

CMakeFiles/assign4_2.dir/assign4_2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/assign4_2.dir/assign4_2.cpp.i"
	E:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\CProjects\assign4\assign4_2.cpp > CMakeFiles\assign4_2.dir\assign4_2.cpp.i

CMakeFiles/assign4_2.dir/assign4_2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/assign4_2.dir/assign4_2.cpp.s"
	E:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\CProjects\assign4\assign4_2.cpp -o CMakeFiles\assign4_2.dir\assign4_2.cpp.s

CMakeFiles/assign4_2.dir/utf8.c.obj: CMakeFiles/assign4_2.dir/flags.make
CMakeFiles/assign4_2.dir/utf8.c.obj: ../utf8.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\CProjects\assign4\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/assign4_2.dir/utf8.c.obj"
	E:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\assign4_2.dir\utf8.c.obj   -c E:\CProjects\assign4\utf8.c

CMakeFiles/assign4_2.dir/utf8.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/assign4_2.dir/utf8.c.i"
	E:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E E:\CProjects\assign4\utf8.c > CMakeFiles\assign4_2.dir\utf8.c.i

CMakeFiles/assign4_2.dir/utf8.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/assign4_2.dir/utf8.c.s"
	E:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S E:\CProjects\assign4\utf8.c -o CMakeFiles\assign4_2.dir\utf8.c.s

# Object files for target assign4_2
assign4_2_OBJECTS = \
"CMakeFiles/assign4_2.dir/assign4_2.cpp.obj" \
"CMakeFiles/assign4_2.dir/utf8.c.obj"

# External object files for target assign4_2
assign4_2_EXTERNAL_OBJECTS =

assign4_2.exe: CMakeFiles/assign4_2.dir/assign4_2.cpp.obj
assign4_2.exe: CMakeFiles/assign4_2.dir/utf8.c.obj
assign4_2.exe: CMakeFiles/assign4_2.dir/build.make
assign4_2.exe: CMakeFiles/assign4_2.dir/linklibs.rsp
assign4_2.exe: CMakeFiles/assign4_2.dir/objects1.rsp
assign4_2.exe: CMakeFiles/assign4_2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\CProjects\assign4\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable assign4_2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\assign4_2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/assign4_2.dir/build: assign4_2.exe

.PHONY : CMakeFiles/assign4_2.dir/build

CMakeFiles/assign4_2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\assign4_2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/assign4_2.dir/clean

CMakeFiles/assign4_2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\CProjects\assign4 E:\CProjects\assign4 E:\CProjects\assign4\cmake-build-debug E:\CProjects\assign4\cmake-build-debug E:\CProjects\assign4\cmake-build-debug\CMakeFiles\assign4_2.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/assign4_2.dir/depend
