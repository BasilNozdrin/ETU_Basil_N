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
CMAKE_COMMAND = /home/ice-jack/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/201.7223.86/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/ice-jack/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/201.7223.86/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ice-jack/Projects/ETU_Basil_N/2020/PR_2020/Nozdrin_Vasily_cw_CLI

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ice-jack/Projects/ETU_Basil_N/2020/PR_2020/Nozdrin_Vasily_cw_CLI/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/mypng.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/mypng.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mypng.dir/flags.make

CMakeFiles/mypng.dir/mypng.cpp.o: CMakeFiles/mypng.dir/flags.make
CMakeFiles/mypng.dir/mypng.cpp.o: ../mypng.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ice-jack/Projects/ETU_Basil_N/2020/PR_2020/Nozdrin_Vasily_cw_CLI/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mypng.dir/mypng.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mypng.dir/mypng.cpp.o -c /home/ice-jack/Projects/ETU_Basil_N/2020/PR_2020/Nozdrin_Vasily_cw_CLI/mypng.cpp

CMakeFiles/mypng.dir/mypng.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mypng.dir/mypng.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ice-jack/Projects/ETU_Basil_N/2020/PR_2020/Nozdrin_Vasily_cw_CLI/mypng.cpp > CMakeFiles/mypng.dir/mypng.cpp.i

CMakeFiles/mypng.dir/mypng.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mypng.dir/mypng.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ice-jack/Projects/ETU_Basil_N/2020/PR_2020/Nozdrin_Vasily_cw_CLI/mypng.cpp -o CMakeFiles/mypng.dir/mypng.cpp.s

# Object files for target mypng
mypng_OBJECTS = \
"CMakeFiles/mypng.dir/mypng.cpp.o"

# External object files for target mypng
mypng_EXTERNAL_OBJECTS =

libmypng.so: CMakeFiles/mypng.dir/mypng.cpp.o
libmypng.so: CMakeFiles/mypng.dir/build.make
libmypng.so: CMakeFiles/mypng.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ice-jack/Projects/ETU_Basil_N/2020/PR_2020/Nozdrin_Vasily_cw_CLI/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libmypng.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mypng.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mypng.dir/build: libmypng.so

.PHONY : CMakeFiles/mypng.dir/build

CMakeFiles/mypng.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mypng.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mypng.dir/clean

CMakeFiles/mypng.dir/depend:
	cd /home/ice-jack/Projects/ETU_Basil_N/2020/PR_2020/Nozdrin_Vasily_cw_CLI/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ice-jack/Projects/ETU_Basil_N/2020/PR_2020/Nozdrin_Vasily_cw_CLI /home/ice-jack/Projects/ETU_Basil_N/2020/PR_2020/Nozdrin_Vasily_cw_CLI /home/ice-jack/Projects/ETU_Basil_N/2020/PR_2020/Nozdrin_Vasily_cw_CLI/cmake-build-debug /home/ice-jack/Projects/ETU_Basil_N/2020/PR_2020/Nozdrin_Vasily_cw_CLI/cmake-build-debug /home/ice-jack/Projects/ETU_Basil_N/2020/PR_2020/Nozdrin_Vasily_cw_CLI/cmake-build-debug/CMakeFiles/mypng.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mypng.dir/depend

