# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

# Produce verbose output by default.
VERBOSE = 1

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = H:\repos\pss_hws\Homework4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = H:\repos\pss_hws\Homework4\build

# Utility rule file for ExperimentalUpdate.

# Include any custom commands dependencies for this target.
include _deps/sqliteorm-build/CMakeFiles/ExperimentalUpdate.dir/compiler_depend.make

# Include the progress variables for this target.
include _deps/sqliteorm-build/CMakeFiles/ExperimentalUpdate.dir/progress.make

_deps/sqliteorm-build/CMakeFiles/ExperimentalUpdate:
	cd /d H:\repos\pss_hws\Homework4\build\_deps\sqliteorm-build && "C:\Program Files\CMake\bin\ctest.exe" -D ExperimentalUpdate

ExperimentalUpdate: _deps/sqliteorm-build/CMakeFiles/ExperimentalUpdate
ExperimentalUpdate: _deps/sqliteorm-build/CMakeFiles/ExperimentalUpdate.dir/build.make
.PHONY : ExperimentalUpdate

# Rule to build all files generated by this target.
_deps/sqliteorm-build/CMakeFiles/ExperimentalUpdate.dir/build: ExperimentalUpdate
.PHONY : _deps/sqliteorm-build/CMakeFiles/ExperimentalUpdate.dir/build

_deps/sqliteorm-build/CMakeFiles/ExperimentalUpdate.dir/clean:
	cd /d H:\repos\pss_hws\Homework4\build\_deps\sqliteorm-build && $(CMAKE_COMMAND) -P CMakeFiles\ExperimentalUpdate.dir\cmake_clean.cmake
.PHONY : _deps/sqliteorm-build/CMakeFiles/ExperimentalUpdate.dir/clean

_deps/sqliteorm-build/CMakeFiles/ExperimentalUpdate.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" H:\repos\pss_hws\Homework4 H:\repos\pss_hws\Homework4\build\_deps\sqliteorm-src H:\repos\pss_hws\Homework4\build H:\repos\pss_hws\Homework4\build\_deps\sqliteorm-build H:\repos\pss_hws\Homework4\build\_deps\sqliteorm-build\CMakeFiles\ExperimentalUpdate.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : _deps/sqliteorm-build/CMakeFiles/ExperimentalUpdate.dir/depend

