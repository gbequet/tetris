# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.19.1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.19.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/florian/Desktop/prog_av_tp1-master

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/florian/Desktop/prog_av_tp1-master

# Include any dependencies generated for this target.
include CMakeFiles/TP_SDL.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TP_SDL.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TP_SDL.dir/flags.make

CMakeFiles/TP_SDL.dir/base_tp1.cpp.o: CMakeFiles/TP_SDL.dir/flags.make
CMakeFiles/TP_SDL.dir/base_tp1.cpp.o: base_tp1.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/florian/Desktop/prog_av_tp1-master/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TP_SDL.dir/base_tp1.cpp.o"
	/usr/local/opt/gcc/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TP_SDL.dir/base_tp1.cpp.o -c /Users/florian/Desktop/prog_av_tp1-master/base_tp1.cpp

CMakeFiles/TP_SDL.dir/base_tp1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TP_SDL.dir/base_tp1.cpp.i"
	/usr/local/opt/gcc/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/florian/Desktop/prog_av_tp1-master/base_tp1.cpp > CMakeFiles/TP_SDL.dir/base_tp1.cpp.i

CMakeFiles/TP_SDL.dir/base_tp1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TP_SDL.dir/base_tp1.cpp.s"
	/usr/local/opt/gcc/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/florian/Desktop/prog_av_tp1-master/base_tp1.cpp -o CMakeFiles/TP_SDL.dir/base_tp1.cpp.s

# Object files for target TP_SDL
TP_SDL_OBJECTS = \
"CMakeFiles/TP_SDL.dir/base_tp1.cpp.o"

# External object files for target TP_SDL
TP_SDL_EXTERNAL_OBJECTS =

TP_SDL: CMakeFiles/TP_SDL.dir/base_tp1.cpp.o
TP_SDL: CMakeFiles/TP_SDL.dir/build.make
TP_SDL: /usr/local/Cellar/sdl2/2.0.14_1/lib/libSDL2.dylib
TP_SDL: /usr/local/Cellar/sdl2/2.0.14_1/lib/libSDL2main.a
TP_SDL: CMakeFiles/TP_SDL.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/florian/Desktop/prog_av_tp1-master/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TP_SDL"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TP_SDL.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TP_SDL.dir/build: TP_SDL

.PHONY : CMakeFiles/TP_SDL.dir/build

CMakeFiles/TP_SDL.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TP_SDL.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TP_SDL.dir/clean

CMakeFiles/TP_SDL.dir/depend:
	cd /Users/florian/Desktop/prog_av_tp1-master && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/florian/Desktop/prog_av_tp1-master /Users/florian/Desktop/prog_av_tp1-master /Users/florian/Desktop/prog_av_tp1-master /Users/florian/Desktop/prog_av_tp1-master /Users/florian/Desktop/prog_av_tp1-master/CMakeFiles/TP_SDL.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TP_SDL.dir/depend

