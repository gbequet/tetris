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
CMAKE_SOURCE_DIR = /Users/florian/Desktop/Tetris2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/florian/Desktop/Tetris2

# Include any dependencies generated for this target.
include CMakeFiles/Tetris.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Tetris.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Tetris.dir/flags.make

CMakeFiles/Tetris.dir/window.cpp.o: CMakeFiles/Tetris.dir/flags.make
CMakeFiles/Tetris.dir/window.cpp.o: window.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/florian/Desktop/Tetris2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Tetris.dir/window.cpp.o"
	/usr/local/opt/gcc/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tetris.dir/window.cpp.o -c /Users/florian/Desktop/Tetris2/window.cpp

CMakeFiles/Tetris.dir/window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tetris.dir/window.cpp.i"
	/usr/local/opt/gcc/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/florian/Desktop/Tetris2/window.cpp > CMakeFiles/Tetris.dir/window.cpp.i

CMakeFiles/Tetris.dir/window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tetris.dir/window.cpp.s"
	/usr/local/opt/gcc/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/florian/Desktop/Tetris2/window.cpp -o CMakeFiles/Tetris.dir/window.cpp.s

CMakeFiles/Tetris.dir/surface.cpp.o: CMakeFiles/Tetris.dir/flags.make
CMakeFiles/Tetris.dir/surface.cpp.o: surface.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/florian/Desktop/Tetris2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Tetris.dir/surface.cpp.o"
	/usr/local/opt/gcc/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tetris.dir/surface.cpp.o -c /Users/florian/Desktop/Tetris2/surface.cpp

CMakeFiles/Tetris.dir/surface.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tetris.dir/surface.cpp.i"
	/usr/local/opt/gcc/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/florian/Desktop/Tetris2/surface.cpp > CMakeFiles/Tetris.dir/surface.cpp.i

CMakeFiles/Tetris.dir/surface.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tetris.dir/surface.cpp.s"
	/usr/local/opt/gcc/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/florian/Desktop/Tetris2/surface.cpp -o CMakeFiles/Tetris.dir/surface.cpp.s

CMakeFiles/Tetris.dir/GraphicsObject.cpp.o: CMakeFiles/Tetris.dir/flags.make
CMakeFiles/Tetris.dir/GraphicsObject.cpp.o: GraphicsObject.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/florian/Desktop/Tetris2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Tetris.dir/GraphicsObject.cpp.o"
	/usr/local/opt/gcc/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tetris.dir/GraphicsObject.cpp.o -c /Users/florian/Desktop/Tetris2/GraphicsObject.cpp

CMakeFiles/Tetris.dir/GraphicsObject.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tetris.dir/GraphicsObject.cpp.i"
	/usr/local/opt/gcc/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/florian/Desktop/Tetris2/GraphicsObject.cpp > CMakeFiles/Tetris.dir/GraphicsObject.cpp.i

CMakeFiles/Tetris.dir/GraphicsObject.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tetris.dir/GraphicsObject.cpp.s"
	/usr/local/opt/gcc/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/florian/Desktop/Tetris2/GraphicsObject.cpp -o CMakeFiles/Tetris.dir/GraphicsObject.cpp.s

CMakeFiles/Tetris.dir/Shapes.cpp.o: CMakeFiles/Tetris.dir/flags.make
CMakeFiles/Tetris.dir/Shapes.cpp.o: Shapes.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/florian/Desktop/Tetris2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Tetris.dir/Shapes.cpp.o"
	/usr/local/opt/gcc/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tetris.dir/Shapes.cpp.o -c /Users/florian/Desktop/Tetris2/Shapes.cpp

CMakeFiles/Tetris.dir/Shapes.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tetris.dir/Shapes.cpp.i"
	/usr/local/opt/gcc/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/florian/Desktop/Tetris2/Shapes.cpp > CMakeFiles/Tetris.dir/Shapes.cpp.i

CMakeFiles/Tetris.dir/Shapes.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tetris.dir/Shapes.cpp.s"
	/usr/local/opt/gcc/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/florian/Desktop/Tetris2/Shapes.cpp -o CMakeFiles/Tetris.dir/Shapes.cpp.s

CMakeFiles/Tetris.dir/sprite.cpp.o: CMakeFiles/Tetris.dir/flags.make
CMakeFiles/Tetris.dir/sprite.cpp.o: sprite.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/florian/Desktop/Tetris2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Tetris.dir/sprite.cpp.o"
	/usr/local/opt/gcc/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tetris.dir/sprite.cpp.o -c /Users/florian/Desktop/Tetris2/sprite.cpp

CMakeFiles/Tetris.dir/sprite.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tetris.dir/sprite.cpp.i"
	/usr/local/opt/gcc/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/florian/Desktop/Tetris2/sprite.cpp > CMakeFiles/Tetris.dir/sprite.cpp.i

CMakeFiles/Tetris.dir/sprite.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tetris.dir/sprite.cpp.s"
	/usr/local/opt/gcc/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/florian/Desktop/Tetris2/sprite.cpp -o CMakeFiles/Tetris.dir/sprite.cpp.s

CMakeFiles/Tetris.dir/game.cpp.o: CMakeFiles/Tetris.dir/flags.make
CMakeFiles/Tetris.dir/game.cpp.o: game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/florian/Desktop/Tetris2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Tetris.dir/game.cpp.o"
	/usr/local/opt/gcc/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tetris.dir/game.cpp.o -c /Users/florian/Desktop/Tetris2/game.cpp

CMakeFiles/Tetris.dir/game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tetris.dir/game.cpp.i"
	/usr/local/opt/gcc/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/florian/Desktop/Tetris2/game.cpp > CMakeFiles/Tetris.dir/game.cpp.i

CMakeFiles/Tetris.dir/game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tetris.dir/game.cpp.s"
	/usr/local/opt/gcc/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/florian/Desktop/Tetris2/game.cpp -o CMakeFiles/Tetris.dir/game.cpp.s

CMakeFiles/Tetris.dir/main.cpp.o: CMakeFiles/Tetris.dir/flags.make
CMakeFiles/Tetris.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/florian/Desktop/Tetris2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Tetris.dir/main.cpp.o"
	/usr/local/opt/gcc/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tetris.dir/main.cpp.o -c /Users/florian/Desktop/Tetris2/main.cpp

CMakeFiles/Tetris.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tetris.dir/main.cpp.i"
	/usr/local/opt/gcc/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/florian/Desktop/Tetris2/main.cpp > CMakeFiles/Tetris.dir/main.cpp.i

CMakeFiles/Tetris.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tetris.dir/main.cpp.s"
	/usr/local/opt/gcc/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/florian/Desktop/Tetris2/main.cpp -o CMakeFiles/Tetris.dir/main.cpp.s

# Object files for target Tetris
Tetris_OBJECTS = \
"CMakeFiles/Tetris.dir/window.cpp.o" \
"CMakeFiles/Tetris.dir/surface.cpp.o" \
"CMakeFiles/Tetris.dir/GraphicsObject.cpp.o" \
"CMakeFiles/Tetris.dir/Shapes.cpp.o" \
"CMakeFiles/Tetris.dir/sprite.cpp.o" \
"CMakeFiles/Tetris.dir/game.cpp.o" \
"CMakeFiles/Tetris.dir/main.cpp.o"

# External object files for target Tetris
Tetris_EXTERNAL_OBJECTS =

Tetris: CMakeFiles/Tetris.dir/window.cpp.o
Tetris: CMakeFiles/Tetris.dir/surface.cpp.o
Tetris: CMakeFiles/Tetris.dir/GraphicsObject.cpp.o
Tetris: CMakeFiles/Tetris.dir/Shapes.cpp.o
Tetris: CMakeFiles/Tetris.dir/sprite.cpp.o
Tetris: CMakeFiles/Tetris.dir/game.cpp.o
Tetris: CMakeFiles/Tetris.dir/main.cpp.o
Tetris: CMakeFiles/Tetris.dir/build.make
Tetris: /usr/local/Cellar/sdl2/2.0.14_1/lib/libSDL2.dylib
Tetris: /usr/local/Cellar/sdl2/2.0.14_1/lib/libSDL2main.a
Tetris: CMakeFiles/Tetris.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/florian/Desktop/Tetris2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable Tetris"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Tetris.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Tetris.dir/build: Tetris

.PHONY : CMakeFiles/Tetris.dir/build

CMakeFiles/Tetris.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Tetris.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Tetris.dir/clean

CMakeFiles/Tetris.dir/depend:
	cd /Users/florian/Desktop/Tetris2 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/florian/Desktop/Tetris2 /Users/florian/Desktop/Tetris2 /Users/florian/Desktop/Tetris2 /Users/florian/Desktop/Tetris2 /Users/florian/Desktop/Tetris2/CMakeFiles/Tetris.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Tetris.dir/depend

