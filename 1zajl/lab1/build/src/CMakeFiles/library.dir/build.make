# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/karl/obiektowe/1zajl/lab1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/karl/obiektowe/1zajl/lab1/build

# Include any dependencies generated for this target.
include src/CMakeFiles/library.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/library.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/library.dir/flags.make

src/CMakeFiles/library.dir/wire.cpp.o: src/CMakeFiles/library.dir/flags.make
src/CMakeFiles/library.dir/wire.cpp.o: ../src/wire.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/karl/obiektowe/1zajl/lab1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/library.dir/wire.cpp.o"
	cd /home/karl/obiektowe/1zajl/lab1/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/library.dir/wire.cpp.o -c /home/karl/obiektowe/1zajl/lab1/src/wire.cpp

src/CMakeFiles/library.dir/wire.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/library.dir/wire.cpp.i"
	cd /home/karl/obiektowe/1zajl/lab1/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/karl/obiektowe/1zajl/lab1/src/wire.cpp > CMakeFiles/library.dir/wire.cpp.i

src/CMakeFiles/library.dir/wire.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/library.dir/wire.cpp.s"
	cd /home/karl/obiektowe/1zajl/lab1/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/karl/obiektowe/1zajl/lab1/src/wire.cpp -o CMakeFiles/library.dir/wire.cpp.s

src/CMakeFiles/library.dir/wire.cpp.o.requires:

.PHONY : src/CMakeFiles/library.dir/wire.cpp.o.requires

src/CMakeFiles/library.dir/wire.cpp.o.provides: src/CMakeFiles/library.dir/wire.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/library.dir/build.make src/CMakeFiles/library.dir/wire.cpp.o.provides.build
.PHONY : src/CMakeFiles/library.dir/wire.cpp.o.provides

src/CMakeFiles/library.dir/wire.cpp.o.provides.build: src/CMakeFiles/library.dir/wire.cpp.o


# Object files for target library
library_OBJECTS = \
"CMakeFiles/library.dir/wire.cpp.o"

# External object files for target library
library_EXTERNAL_OBJECTS =

src/liblibrary.a: src/CMakeFiles/library.dir/wire.cpp.o
src/liblibrary.a: src/CMakeFiles/library.dir/build.make
src/liblibrary.a: src/CMakeFiles/library.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/karl/obiektowe/1zajl/lab1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library liblibrary.a"
	cd /home/karl/obiektowe/1zajl/lab1/build/src && $(CMAKE_COMMAND) -P CMakeFiles/library.dir/cmake_clean_target.cmake
	cd /home/karl/obiektowe/1zajl/lab1/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/library.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/library.dir/build: src/liblibrary.a

.PHONY : src/CMakeFiles/library.dir/build

src/CMakeFiles/library.dir/requires: src/CMakeFiles/library.dir/wire.cpp.o.requires

.PHONY : src/CMakeFiles/library.dir/requires

src/CMakeFiles/library.dir/clean:
	cd /home/karl/obiektowe/1zajl/lab1/build/src && $(CMAKE_COMMAND) -P CMakeFiles/library.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/library.dir/clean

src/CMakeFiles/library.dir/depend:
	cd /home/karl/obiektowe/1zajl/lab1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/karl/obiektowe/1zajl/lab1 /home/karl/obiektowe/1zajl/lab1/src /home/karl/obiektowe/1zajl/lab1/build /home/karl/obiektowe/1zajl/lab1/build/src /home/karl/obiektowe/1zajl/lab1/build/src/CMakeFiles/library.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/library.dir/depend

