# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.29.5/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.29.5/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/chrisd/Desktop/jumping_physics/modules/SDL_ttf

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/chrisd/Desktop/jumping_physics/modules/SDL_ttf/build

# Include any dependencies generated for this target.
include CMakeFiles/showfont.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/showfont.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/showfont.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/showfont.dir/flags.make

CMakeFiles/showfont.dir/examples/showfont.c.o: CMakeFiles/showfont.dir/flags.make
CMakeFiles/showfont.dir/examples/showfont.c.o: /Users/chrisd/Desktop/jumping_physics/modules/SDL_ttf/examples/showfont.c
CMakeFiles/showfont.dir/examples/showfont.c.o: CMakeFiles/showfont.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/chrisd/Desktop/jumping_physics/modules/SDL_ttf/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/showfont.dir/examples/showfont.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/showfont.dir/examples/showfont.c.o -MF CMakeFiles/showfont.dir/examples/showfont.c.o.d -o CMakeFiles/showfont.dir/examples/showfont.c.o -c /Users/chrisd/Desktop/jumping_physics/modules/SDL_ttf/examples/showfont.c

CMakeFiles/showfont.dir/examples/showfont.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/showfont.dir/examples/showfont.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/chrisd/Desktop/jumping_physics/modules/SDL_ttf/examples/showfont.c > CMakeFiles/showfont.dir/examples/showfont.c.i

CMakeFiles/showfont.dir/examples/showfont.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/showfont.dir/examples/showfont.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/chrisd/Desktop/jumping_physics/modules/SDL_ttf/examples/showfont.c -o CMakeFiles/showfont.dir/examples/showfont.c.s

# Object files for target showfont
showfont_OBJECTS = \
"CMakeFiles/showfont.dir/examples/showfont.c.o"

# External object files for target showfont
showfont_EXTERNAL_OBJECTS =

showfont: CMakeFiles/showfont.dir/examples/showfont.c.o
showfont: CMakeFiles/showfont.dir/build.make
showfont: libSDL3_ttf.1.0.0.dylib
showfont: /usr/local/lib/libSDL3.1.0.0.dylib
showfont: CMakeFiles/showfont.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/chrisd/Desktop/jumping_physics/modules/SDL_ttf/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable showfont"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/showfont.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/showfont.dir/build: showfont
.PHONY : CMakeFiles/showfont.dir/build

CMakeFiles/showfont.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/showfont.dir/cmake_clean.cmake
.PHONY : CMakeFiles/showfont.dir/clean

CMakeFiles/showfont.dir/depend:
	cd /Users/chrisd/Desktop/jumping_physics/modules/SDL_ttf/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/chrisd/Desktop/jumping_physics/modules/SDL_ttf /Users/chrisd/Desktop/jumping_physics/modules/SDL_ttf /Users/chrisd/Desktop/jumping_physics/modules/SDL_ttf/build /Users/chrisd/Desktop/jumping_physics/modules/SDL_ttf/build /Users/chrisd/Desktop/jumping_physics/modules/SDL_ttf/build/CMakeFiles/showfont.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/showfont.dir/depend
