# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /var/lib/snapd/snap/clion/114/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /var/lib/snapd/snap/clion/114/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/yisus/Documentos/algo2/labo/2020-c1-tp3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/yisus/Documentos/algo2/labo/2020-c1-tp3/cmake-build-debug

# Utility rule file for correrValgrindSimCity.

# Include the progress variables for this target.
include CMakeFiles/correrValgrindSimCity.dir/progress.make

CMakeFiles/correrValgrindSimCity: correrTestsSimCity
	valgrind --leak-check=full -v ./correrTestsSimCity 2>&1

correrValgrindSimCity: CMakeFiles/correrValgrindSimCity
correrValgrindSimCity: CMakeFiles/correrValgrindSimCity.dir/build.make

.PHONY : correrValgrindSimCity

# Rule to build all files generated by this target.
CMakeFiles/correrValgrindSimCity.dir/build: correrValgrindSimCity

.PHONY : CMakeFiles/correrValgrindSimCity.dir/build

CMakeFiles/correrValgrindSimCity.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/correrValgrindSimCity.dir/cmake_clean.cmake
.PHONY : CMakeFiles/correrValgrindSimCity.dir/clean

CMakeFiles/correrValgrindSimCity.dir/depend:
	cd /home/yisus/Documentos/algo2/labo/2020-c1-tp3/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yisus/Documentos/algo2/labo/2020-c1-tp3 /home/yisus/Documentos/algo2/labo/2020-c1-tp3 /home/yisus/Documentos/algo2/labo/2020-c1-tp3/cmake-build-debug /home/yisus/Documentos/algo2/labo/2020-c1-tp3/cmake-build-debug /home/yisus/Documentos/algo2/labo/2020-c1-tp3/cmake-build-debug/CMakeFiles/correrValgrindSimCity.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/correrValgrindSimCity.dir/depend

