# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/henrikerch/Desktop/ADVANCED PROGRAMMING/2022-project-henrey-T"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/henrikerch/Desktop/ADVANCED PROGRAMMING/2022-project-henrey-T/cmake-build-debug"

# Include any dependencies generated for this target.
include src/CMakeFiles/hw.dir/depend.make
# Include the progress variables for this target.
include src/CMakeFiles/hw.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/hw.dir/flags.make

src/CMakeFiles/hw.dir/main.cpp.o: src/CMakeFiles/hw.dir/flags.make
src/CMakeFiles/hw.dir/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/henrikerch/Desktop/ADVANCED PROGRAMMING/2022-project-henrey-T/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/hw.dir/main.cpp.o"
	cd "/Users/henrikerch/Desktop/ADVANCED PROGRAMMING/2022-project-henrey-T/cmake-build-debug/src" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hw.dir/main.cpp.o -c "/Users/henrikerch/Desktop/ADVANCED PROGRAMMING/2022-project-henrey-T/src/main.cpp"

src/CMakeFiles/hw.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw.dir/main.cpp.i"
	cd "/Users/henrikerch/Desktop/ADVANCED PROGRAMMING/2022-project-henrey-T/cmake-build-debug/src" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/henrikerch/Desktop/ADVANCED PROGRAMMING/2022-project-henrey-T/src/main.cpp" > CMakeFiles/hw.dir/main.cpp.i

src/CMakeFiles/hw.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw.dir/main.cpp.s"
	cd "/Users/henrikerch/Desktop/ADVANCED PROGRAMMING/2022-project-henrey-T/cmake-build-debug/src" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/henrikerch/Desktop/ADVANCED PROGRAMMING/2022-project-henrey-T/src/main.cpp" -o CMakeFiles/hw.dir/main.cpp.s

src/CMakeFiles/hw.dir/input.cpp.o: src/CMakeFiles/hw.dir/flags.make
src/CMakeFiles/hw.dir/input.cpp.o: ../src/input.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/henrikerch/Desktop/ADVANCED PROGRAMMING/2022-project-henrey-T/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/hw.dir/input.cpp.o"
	cd "/Users/henrikerch/Desktop/ADVANCED PROGRAMMING/2022-project-henrey-T/cmake-build-debug/src" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hw.dir/input.cpp.o -c "/Users/henrikerch/Desktop/ADVANCED PROGRAMMING/2022-project-henrey-T/src/input.cpp"

src/CMakeFiles/hw.dir/input.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw.dir/input.cpp.i"
	cd "/Users/henrikerch/Desktop/ADVANCED PROGRAMMING/2022-project-henrey-T/cmake-build-debug/src" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/henrikerch/Desktop/ADVANCED PROGRAMMING/2022-project-henrey-T/src/input.cpp" > CMakeFiles/hw.dir/input.cpp.i

src/CMakeFiles/hw.dir/input.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw.dir/input.cpp.s"
	cd "/Users/henrikerch/Desktop/ADVANCED PROGRAMMING/2022-project-henrey-T/cmake-build-debug/src" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/henrikerch/Desktop/ADVANCED PROGRAMMING/2022-project-henrey-T/src/input.cpp" -o CMakeFiles/hw.dir/input.cpp.s

src/CMakeFiles/hw.dir/update.cpp.o: src/CMakeFiles/hw.dir/flags.make
src/CMakeFiles/hw.dir/update.cpp.o: ../src/update.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/henrikerch/Desktop/ADVANCED PROGRAMMING/2022-project-henrey-T/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/hw.dir/update.cpp.o"
	cd "/Users/henrikerch/Desktop/ADVANCED PROGRAMMING/2022-project-henrey-T/cmake-build-debug/src" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hw.dir/update.cpp.o -c "/Users/henrikerch/Desktop/ADVANCED PROGRAMMING/2022-project-henrey-T/src/update.cpp"

src/CMakeFiles/hw.dir/update.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw.dir/update.cpp.i"
	cd "/Users/henrikerch/Desktop/ADVANCED PROGRAMMING/2022-project-henrey-T/cmake-build-debug/src" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/henrikerch/Desktop/ADVANCED PROGRAMMING/2022-project-henrey-T/src/update.cpp" > CMakeFiles/hw.dir/update.cpp.i

src/CMakeFiles/hw.dir/update.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw.dir/update.cpp.s"
	cd "/Users/henrikerch/Desktop/ADVANCED PROGRAMMING/2022-project-henrey-T/cmake-build-debug/src" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/henrikerch/Desktop/ADVANCED PROGRAMMING/2022-project-henrey-T/src/update.cpp" -o CMakeFiles/hw.dir/update.cpp.s

src/CMakeFiles/hw.dir/draw.cpp.o: src/CMakeFiles/hw.dir/flags.make
src/CMakeFiles/hw.dir/draw.cpp.o: ../src/draw.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/henrikerch/Desktop/ADVANCED PROGRAMMING/2022-project-henrey-T/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/hw.dir/draw.cpp.o"
	cd "/Users/henrikerch/Desktop/ADVANCED PROGRAMMING/2022-project-henrey-T/cmake-build-debug/src" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hw.dir/draw.cpp.o -c "/Users/henrikerch/Desktop/ADVANCED PROGRAMMING/2022-project-henrey-T/src/draw.cpp"

src/CMakeFiles/hw.dir/draw.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw.dir/draw.cpp.i"
	cd "/Users/henrikerch/Desktop/ADVANCED PROGRAMMING/2022-project-henrey-T/cmake-build-debug/src" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/henrikerch/Desktop/ADVANCED PROGRAMMING/2022-project-henrey-T/src/draw.cpp" > CMakeFiles/hw.dir/draw.cpp.i

src/CMakeFiles/hw.dir/draw.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw.dir/draw.cpp.s"
	cd "/Users/henrikerch/Desktop/ADVANCED PROGRAMMING/2022-project-henrey-T/cmake-build-debug/src" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/henrikerch/Desktop/ADVANCED PROGRAMMING/2022-project-henrey-T/src/draw.cpp" -o CMakeFiles/hw.dir/draw.cpp.s

src/CMakeFiles/hw.dir/player.cpp.o: src/CMakeFiles/hw.dir/flags.make
src/CMakeFiles/hw.dir/player.cpp.o: ../src/player.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/henrikerch/Desktop/ADVANCED PROGRAMMING/2022-project-henrey-T/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/hw.dir/player.cpp.o"
	cd "/Users/henrikerch/Desktop/ADVANCED PROGRAMMING/2022-project-henrey-T/cmake-build-debug/src" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hw.dir/player.cpp.o -c "/Users/henrikerch/Desktop/ADVANCED PROGRAMMING/2022-project-henrey-T/src/player.cpp"

src/CMakeFiles/hw.dir/player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw.dir/player.cpp.i"
	cd "/Users/henrikerch/Desktop/ADVANCED PROGRAMMING/2022-project-henrey-T/cmake-build-debug/src" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/henrikerch/Desktop/ADVANCED PROGRAMMING/2022-project-henrey-T/src/player.cpp" > CMakeFiles/hw.dir/player.cpp.i

src/CMakeFiles/hw.dir/player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw.dir/player.cpp.s"
	cd "/Users/henrikerch/Desktop/ADVANCED PROGRAMMING/2022-project-henrey-T/cmake-build-debug/src" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/henrikerch/Desktop/ADVANCED PROGRAMMING/2022-project-henrey-T/src/player.cpp" -o CMakeFiles/hw.dir/player.cpp.s

# Object files for target hw
hw_OBJECTS = \
"CMakeFiles/hw.dir/main.cpp.o" \
"CMakeFiles/hw.dir/input.cpp.o" \
"CMakeFiles/hw.dir/update.cpp.o" \
"CMakeFiles/hw.dir/draw.cpp.o" \
"CMakeFiles/hw.dir/player.cpp.o"

# External object files for target hw
hw_EXTERNAL_OBJECTS =

src/hw: src/CMakeFiles/hw.dir/main.cpp.o
src/hw: src/CMakeFiles/hw.dir/input.cpp.o
src/hw: src/CMakeFiles/hw.dir/update.cpp.o
src/hw: src/CMakeFiles/hw.dir/draw.cpp.o
src/hw: src/CMakeFiles/hw.dir/player.cpp.o
src/hw: src/CMakeFiles/hw.dir/build.make
src/hw: src/CMakeFiles/hw.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/henrikerch/Desktop/ADVANCED PROGRAMMING/2022-project-henrey-T/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable hw"
	cd "/Users/henrikerch/Desktop/ADVANCED PROGRAMMING/2022-project-henrey-T/cmake-build-debug/src" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hw.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/hw.dir/build: src/hw
.PHONY : src/CMakeFiles/hw.dir/build

src/CMakeFiles/hw.dir/clean:
	cd "/Users/henrikerch/Desktop/ADVANCED PROGRAMMING/2022-project-henrey-T/cmake-build-debug/src" && $(CMAKE_COMMAND) -P CMakeFiles/hw.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/hw.dir/clean

src/CMakeFiles/hw.dir/depend:
	cd "/Users/henrikerch/Desktop/ADVANCED PROGRAMMING/2022-project-henrey-T/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/henrikerch/Desktop/ADVANCED PROGRAMMING/2022-project-henrey-T" "/Users/henrikerch/Desktop/ADVANCED PROGRAMMING/2022-project-henrey-T/src" "/Users/henrikerch/Desktop/ADVANCED PROGRAMMING/2022-project-henrey-T/cmake-build-debug" "/Users/henrikerch/Desktop/ADVANCED PROGRAMMING/2022-project-henrey-T/cmake-build-debug/src" "/Users/henrikerch/Desktop/ADVANCED PROGRAMMING/2022-project-henrey-T/cmake-build-debug/src/CMakeFiles/hw.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : src/CMakeFiles/hw.dir/depend

