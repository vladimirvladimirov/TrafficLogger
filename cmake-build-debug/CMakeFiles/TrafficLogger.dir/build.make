# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.2.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.2.2\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = X:\TrafficLogger

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = X:\TrafficLogger\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/TrafficLogger.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TrafficLogger.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TrafficLogger.dir/flags.make

CMakeFiles/TrafficLogger.dir/main.cpp.obj: CMakeFiles/TrafficLogger.dir/flags.make
CMakeFiles/TrafficLogger.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=X:\TrafficLogger\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TrafficLogger.dir/main.cpp.obj"
	C:\win-builds\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\TrafficLogger.dir\main.cpp.obj -c X:\TrafficLogger\main.cpp

CMakeFiles/TrafficLogger.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TrafficLogger.dir/main.cpp.i"
	C:\win-builds\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E X:\TrafficLogger\main.cpp > CMakeFiles\TrafficLogger.dir\main.cpp.i

CMakeFiles/TrafficLogger.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TrafficLogger.dir/main.cpp.s"
	C:\win-builds\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S X:\TrafficLogger\main.cpp -o CMakeFiles\TrafficLogger.dir\main.cpp.s

# Object files for target TrafficLogger
TrafficLogger_OBJECTS = \
"CMakeFiles/TrafficLogger.dir/main.cpp.obj"

# External object files for target TrafficLogger
TrafficLogger_EXTERNAL_OBJECTS =

TrafficLogger.exe: CMakeFiles/TrafficLogger.dir/main.cpp.obj
TrafficLogger.exe: CMakeFiles/TrafficLogger.dir/build.make
TrafficLogger.exe: CMakeFiles/TrafficLogger.dir/linklibs.rsp
TrafficLogger.exe: CMakeFiles/TrafficLogger.dir/objects1.rsp
TrafficLogger.exe: CMakeFiles/TrafficLogger.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=X:\TrafficLogger\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TrafficLogger.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\TrafficLogger.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TrafficLogger.dir/build: TrafficLogger.exe

.PHONY : CMakeFiles/TrafficLogger.dir/build

CMakeFiles/TrafficLogger.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\TrafficLogger.dir\cmake_clean.cmake
.PHONY : CMakeFiles/TrafficLogger.dir/clean

CMakeFiles/TrafficLogger.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" X:\TrafficLogger X:\TrafficLogger X:\TrafficLogger\cmake-build-debug X:\TrafficLogger\cmake-build-debug X:\TrafficLogger\cmake-build-debug\CMakeFiles\TrafficLogger.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TrafficLogger.dir/depend

