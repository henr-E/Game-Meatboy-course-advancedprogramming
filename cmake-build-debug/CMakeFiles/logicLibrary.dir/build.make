# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = "/Users/henrikerch/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/222.4345.21/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/henrikerch/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/222.4345.21/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/henrikerch/Desktop/ALLLOCALPROJECTS/2022-project-henrey-T

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/henrikerch/Desktop/ALLLOCALPROJECTS/2022-project-henrey-T/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/logicLibrary.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/logicLibrary.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/logicLibrary.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/logicLibrary.dir/flags.make

CMakeFiles/logicLibrary.dir/Game_Logic/World.cpp.o: CMakeFiles/logicLibrary.dir/flags.make
CMakeFiles/logicLibrary.dir/Game_Logic/World.cpp.o: ../Game_Logic/World.cpp
CMakeFiles/logicLibrary.dir/Game_Logic/World.cpp.o: CMakeFiles/logicLibrary.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/henrikerch/Desktop/ALLLOCALPROJECTS/2022-project-henrey-T/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/logicLibrary.dir/Game_Logic/World.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/logicLibrary.dir/Game_Logic/World.cpp.o -MF CMakeFiles/logicLibrary.dir/Game_Logic/World.cpp.o.d -o CMakeFiles/logicLibrary.dir/Game_Logic/World.cpp.o -c /Users/henrikerch/Desktop/ALLLOCALPROJECTS/2022-project-henrey-T/Game_Logic/World.cpp

CMakeFiles/logicLibrary.dir/Game_Logic/World.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/logicLibrary.dir/Game_Logic/World.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/henrikerch/Desktop/ALLLOCALPROJECTS/2022-project-henrey-T/Game_Logic/World.cpp > CMakeFiles/logicLibrary.dir/Game_Logic/World.cpp.i

CMakeFiles/logicLibrary.dir/Game_Logic/World.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/logicLibrary.dir/Game_Logic/World.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/henrikerch/Desktop/ALLLOCALPROJECTS/2022-project-henrey-T/Game_Logic/World.cpp -o CMakeFiles/logicLibrary.dir/Game_Logic/World.cpp.s

CMakeFiles/logicLibrary.dir/Game_Logic/Stopwatch.cpp.o: CMakeFiles/logicLibrary.dir/flags.make
CMakeFiles/logicLibrary.dir/Game_Logic/Stopwatch.cpp.o: ../Game_Logic/Stopwatch.cpp
CMakeFiles/logicLibrary.dir/Game_Logic/Stopwatch.cpp.o: CMakeFiles/logicLibrary.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/henrikerch/Desktop/ALLLOCALPROJECTS/2022-project-henrey-T/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/logicLibrary.dir/Game_Logic/Stopwatch.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/logicLibrary.dir/Game_Logic/Stopwatch.cpp.o -MF CMakeFiles/logicLibrary.dir/Game_Logic/Stopwatch.cpp.o.d -o CMakeFiles/logicLibrary.dir/Game_Logic/Stopwatch.cpp.o -c /Users/henrikerch/Desktop/ALLLOCALPROJECTS/2022-project-henrey-T/Game_Logic/Stopwatch.cpp

CMakeFiles/logicLibrary.dir/Game_Logic/Stopwatch.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/logicLibrary.dir/Game_Logic/Stopwatch.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/henrikerch/Desktop/ALLLOCALPROJECTS/2022-project-henrey-T/Game_Logic/Stopwatch.cpp > CMakeFiles/logicLibrary.dir/Game_Logic/Stopwatch.cpp.i

CMakeFiles/logicLibrary.dir/Game_Logic/Stopwatch.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/logicLibrary.dir/Game_Logic/Stopwatch.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/henrikerch/Desktop/ALLLOCALPROJECTS/2022-project-henrey-T/Game_Logic/Stopwatch.cpp -o CMakeFiles/logicLibrary.dir/Game_Logic/Stopwatch.cpp.s

CMakeFiles/logicLibrary.dir/Game_Logic/Models/PlayerModel.cpp.o: CMakeFiles/logicLibrary.dir/flags.make
CMakeFiles/logicLibrary.dir/Game_Logic/Models/PlayerModel.cpp.o: ../Game_Logic/Models/PlayerModel.cpp
CMakeFiles/logicLibrary.dir/Game_Logic/Models/PlayerModel.cpp.o: CMakeFiles/logicLibrary.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/henrikerch/Desktop/ALLLOCALPROJECTS/2022-project-henrey-T/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/logicLibrary.dir/Game_Logic/Models/PlayerModel.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/logicLibrary.dir/Game_Logic/Models/PlayerModel.cpp.o -MF CMakeFiles/logicLibrary.dir/Game_Logic/Models/PlayerModel.cpp.o.d -o CMakeFiles/logicLibrary.dir/Game_Logic/Models/PlayerModel.cpp.o -c /Users/henrikerch/Desktop/ALLLOCALPROJECTS/2022-project-henrey-T/Game_Logic/Models/PlayerModel.cpp

CMakeFiles/logicLibrary.dir/Game_Logic/Models/PlayerModel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/logicLibrary.dir/Game_Logic/Models/PlayerModel.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/henrikerch/Desktop/ALLLOCALPROJECTS/2022-project-henrey-T/Game_Logic/Models/PlayerModel.cpp > CMakeFiles/logicLibrary.dir/Game_Logic/Models/PlayerModel.cpp.i

CMakeFiles/logicLibrary.dir/Game_Logic/Models/PlayerModel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/logicLibrary.dir/Game_Logic/Models/PlayerModel.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/henrikerch/Desktop/ALLLOCALPROJECTS/2022-project-henrey-T/Game_Logic/Models/PlayerModel.cpp -o CMakeFiles/logicLibrary.dir/Game_Logic/Models/PlayerModel.cpp.s

CMakeFiles/logicLibrary.dir/Game_Logic/Observer.cpp.o: CMakeFiles/logicLibrary.dir/flags.make
CMakeFiles/logicLibrary.dir/Game_Logic/Observer.cpp.o: ../Game_Logic/Observer.cpp
CMakeFiles/logicLibrary.dir/Game_Logic/Observer.cpp.o: CMakeFiles/logicLibrary.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/henrikerch/Desktop/ALLLOCALPROJECTS/2022-project-henrey-T/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/logicLibrary.dir/Game_Logic/Observer.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/logicLibrary.dir/Game_Logic/Observer.cpp.o -MF CMakeFiles/logicLibrary.dir/Game_Logic/Observer.cpp.o.d -o CMakeFiles/logicLibrary.dir/Game_Logic/Observer.cpp.o -c /Users/henrikerch/Desktop/ALLLOCALPROJECTS/2022-project-henrey-T/Game_Logic/Observer.cpp

CMakeFiles/logicLibrary.dir/Game_Logic/Observer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/logicLibrary.dir/Game_Logic/Observer.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/henrikerch/Desktop/ALLLOCALPROJECTS/2022-project-henrey-T/Game_Logic/Observer.cpp > CMakeFiles/logicLibrary.dir/Game_Logic/Observer.cpp.i

CMakeFiles/logicLibrary.dir/Game_Logic/Observer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/logicLibrary.dir/Game_Logic/Observer.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/henrikerch/Desktop/ALLLOCALPROJECTS/2022-project-henrey-T/Game_Logic/Observer.cpp -o CMakeFiles/logicLibrary.dir/Game_Logic/Observer.cpp.s

CMakeFiles/logicLibrary.dir/Game_Logic/Subject.cpp.o: CMakeFiles/logicLibrary.dir/flags.make
CMakeFiles/logicLibrary.dir/Game_Logic/Subject.cpp.o: ../Game_Logic/Subject.cpp
CMakeFiles/logicLibrary.dir/Game_Logic/Subject.cpp.o: CMakeFiles/logicLibrary.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/henrikerch/Desktop/ALLLOCALPROJECTS/2022-project-henrey-T/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/logicLibrary.dir/Game_Logic/Subject.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/logicLibrary.dir/Game_Logic/Subject.cpp.o -MF CMakeFiles/logicLibrary.dir/Game_Logic/Subject.cpp.o.d -o CMakeFiles/logicLibrary.dir/Game_Logic/Subject.cpp.o -c /Users/henrikerch/Desktop/ALLLOCALPROJECTS/2022-project-henrey-T/Game_Logic/Subject.cpp

CMakeFiles/logicLibrary.dir/Game_Logic/Subject.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/logicLibrary.dir/Game_Logic/Subject.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/henrikerch/Desktop/ALLLOCALPROJECTS/2022-project-henrey-T/Game_Logic/Subject.cpp > CMakeFiles/logicLibrary.dir/Game_Logic/Subject.cpp.i

CMakeFiles/logicLibrary.dir/Game_Logic/Subject.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/logicLibrary.dir/Game_Logic/Subject.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/henrikerch/Desktop/ALLLOCALPROJECTS/2022-project-henrey-T/Game_Logic/Subject.cpp -o CMakeFiles/logicLibrary.dir/Game_Logic/Subject.cpp.s

# Object files for target logicLibrary
logicLibrary_OBJECTS = \
"CMakeFiles/logicLibrary.dir/Game_Logic/World.cpp.o" \
"CMakeFiles/logicLibrary.dir/Game_Logic/Stopwatch.cpp.o" \
"CMakeFiles/logicLibrary.dir/Game_Logic/Models/PlayerModel.cpp.o" \
"CMakeFiles/logicLibrary.dir/Game_Logic/Observer.cpp.o" \
"CMakeFiles/logicLibrary.dir/Game_Logic/Subject.cpp.o"

# External object files for target logicLibrary
logicLibrary_EXTERNAL_OBJECTS =

liblogicLibrary.a: CMakeFiles/logicLibrary.dir/Game_Logic/World.cpp.o
liblogicLibrary.a: CMakeFiles/logicLibrary.dir/Game_Logic/Stopwatch.cpp.o
liblogicLibrary.a: CMakeFiles/logicLibrary.dir/Game_Logic/Models/PlayerModel.cpp.o
liblogicLibrary.a: CMakeFiles/logicLibrary.dir/Game_Logic/Observer.cpp.o
liblogicLibrary.a: CMakeFiles/logicLibrary.dir/Game_Logic/Subject.cpp.o
liblogicLibrary.a: CMakeFiles/logicLibrary.dir/build.make
liblogicLibrary.a: CMakeFiles/logicLibrary.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/henrikerch/Desktop/ALLLOCALPROJECTS/2022-project-henrey-T/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX static library liblogicLibrary.a"
	$(CMAKE_COMMAND) -P CMakeFiles/logicLibrary.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/logicLibrary.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/logicLibrary.dir/build: liblogicLibrary.a
.PHONY : CMakeFiles/logicLibrary.dir/build

CMakeFiles/logicLibrary.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/logicLibrary.dir/cmake_clean.cmake
.PHONY : CMakeFiles/logicLibrary.dir/clean

CMakeFiles/logicLibrary.dir/depend:
	cd /Users/henrikerch/Desktop/ALLLOCALPROJECTS/2022-project-henrey-T/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/henrikerch/Desktop/ALLLOCALPROJECTS/2022-project-henrey-T /Users/henrikerch/Desktop/ALLLOCALPROJECTS/2022-project-henrey-T /Users/henrikerch/Desktop/ALLLOCALPROJECTS/2022-project-henrey-T/cmake-build-debug /Users/henrikerch/Desktop/ALLLOCALPROJECTS/2022-project-henrey-T/cmake-build-debug /Users/henrikerch/Desktop/ALLLOCALPROJECTS/2022-project-henrey-T/cmake-build-debug/CMakeFiles/logicLibrary.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/logicLibrary.dir/depend

