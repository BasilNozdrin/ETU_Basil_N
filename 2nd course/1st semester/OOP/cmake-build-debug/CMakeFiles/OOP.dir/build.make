# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /home/ice-jack/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/202.7319.72/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/ice-jack/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/202.7319.72/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/ice-jack/Projects/ETU_Basil_N/2nd course/1st semester/OOP"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/ice-jack/Projects/ETU_Basil_N/2nd course/1st semester/OOP/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/OOP.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/OOP.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/OOP.dir/flags.make

CMakeFiles/OOP.dir/src/main.cpp.o: CMakeFiles/OOP.dir/flags.make
CMakeFiles/OOP.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/ice-jack/Projects/ETU_Basil_N/2nd course/1st semester/OOP/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/OOP.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OOP.dir/src/main.cpp.o -c "/home/ice-jack/Projects/ETU_Basil_N/2nd course/1st semester/OOP/src/main.cpp"

CMakeFiles/OOP.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OOP.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/ice-jack/Projects/ETU_Basil_N/2nd course/1st semester/OOP/src/main.cpp" > CMakeFiles/OOP.dir/src/main.cpp.i

CMakeFiles/OOP.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OOP.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/ice-jack/Projects/ETU_Basil_N/2nd course/1st semester/OOP/src/main.cpp" -o CMakeFiles/OOP.dir/src/main.cpp.s

CMakeFiles/OOP.dir/src/Buffs/Buff.cpp.o: CMakeFiles/OOP.dir/flags.make
CMakeFiles/OOP.dir/src/Buffs/Buff.cpp.o: ../src/Buffs/Buff.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/ice-jack/Projects/ETU_Basil_N/2nd course/1st semester/OOP/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/OOP.dir/src/Buffs/Buff.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OOP.dir/src/Buffs/Buff.cpp.o -c "/home/ice-jack/Projects/ETU_Basil_N/2nd course/1st semester/OOP/src/Buffs/Buff.cpp"

CMakeFiles/OOP.dir/src/Buffs/Buff.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OOP.dir/src/Buffs/Buff.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/ice-jack/Projects/ETU_Basil_N/2nd course/1st semester/OOP/src/Buffs/Buff.cpp" > CMakeFiles/OOP.dir/src/Buffs/Buff.cpp.i

CMakeFiles/OOP.dir/src/Buffs/Buff.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OOP.dir/src/Buffs/Buff.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/ice-jack/Projects/ETU_Basil_N/2nd course/1st semester/OOP/src/Buffs/Buff.cpp" -o CMakeFiles/OOP.dir/src/Buffs/Buff.cpp.s

CMakeFiles/OOP.dir/src/GameField/Cell.cpp.o: CMakeFiles/OOP.dir/flags.make
CMakeFiles/OOP.dir/src/GameField/Cell.cpp.o: ../src/GameField/Cell.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/ice-jack/Projects/ETU_Basil_N/2nd course/1st semester/OOP/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/OOP.dir/src/GameField/Cell.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OOP.dir/src/GameField/Cell.cpp.o -c "/home/ice-jack/Projects/ETU_Basil_N/2nd course/1st semester/OOP/src/GameField/Cell.cpp"

CMakeFiles/OOP.dir/src/GameField/Cell.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OOP.dir/src/GameField/Cell.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/ice-jack/Projects/ETU_Basil_N/2nd course/1st semester/OOP/src/GameField/Cell.cpp" > CMakeFiles/OOP.dir/src/GameField/Cell.cpp.i

CMakeFiles/OOP.dir/src/GameField/Cell.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OOP.dir/src/GameField/Cell.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/ice-jack/Projects/ETU_Basil_N/2nd course/1st semester/OOP/src/GameField/Cell.cpp" -o CMakeFiles/OOP.dir/src/GameField/Cell.cpp.s

CMakeFiles/OOP.dir/src/GameField/levels.cpp.o: CMakeFiles/OOP.dir/flags.make
CMakeFiles/OOP.dir/src/GameField/levels.cpp.o: ../src/GameField/levels.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/ice-jack/Projects/ETU_Basil_N/2nd course/1st semester/OOP/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/OOP.dir/src/GameField/levels.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OOP.dir/src/GameField/levels.cpp.o -c "/home/ice-jack/Projects/ETU_Basil_N/2nd course/1st semester/OOP/src/GameField/levels.cpp"

CMakeFiles/OOP.dir/src/GameField/levels.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OOP.dir/src/GameField/levels.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/ice-jack/Projects/ETU_Basil_N/2nd course/1st semester/OOP/src/GameField/levels.cpp" > CMakeFiles/OOP.dir/src/GameField/levels.cpp.i

CMakeFiles/OOP.dir/src/GameField/levels.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OOP.dir/src/GameField/levels.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/ice-jack/Projects/ETU_Basil_N/2nd course/1st semester/OOP/src/GameField/levels.cpp" -o CMakeFiles/OOP.dir/src/GameField/levels.cpp.s

CMakeFiles/OOP.dir/src/GameField/FieldRowIter.cpp.o: CMakeFiles/OOP.dir/flags.make
CMakeFiles/OOP.dir/src/GameField/FieldRowIter.cpp.o: ../src/GameField/FieldRowIter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/ice-jack/Projects/ETU_Basil_N/2nd course/1st semester/OOP/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/OOP.dir/src/GameField/FieldRowIter.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OOP.dir/src/GameField/FieldRowIter.cpp.o -c "/home/ice-jack/Projects/ETU_Basil_N/2nd course/1st semester/OOP/src/GameField/FieldRowIter.cpp"

CMakeFiles/OOP.dir/src/GameField/FieldRowIter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OOP.dir/src/GameField/FieldRowIter.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/ice-jack/Projects/ETU_Basil_N/2nd course/1st semester/OOP/src/GameField/FieldRowIter.cpp" > CMakeFiles/OOP.dir/src/GameField/FieldRowIter.cpp.i

CMakeFiles/OOP.dir/src/GameField/FieldRowIter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OOP.dir/src/GameField/FieldRowIter.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/ice-jack/Projects/ETU_Basil_N/2nd course/1st semester/OOP/src/GameField/FieldRowIter.cpp" -o CMakeFiles/OOP.dir/src/GameField/FieldRowIter.cpp.s

CMakeFiles/OOP.dir/src/GameField/FieldIter.cpp.o: CMakeFiles/OOP.dir/flags.make
CMakeFiles/OOP.dir/src/GameField/FieldIter.cpp.o: ../src/GameField/FieldIter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/ice-jack/Projects/ETU_Basil_N/2nd course/1st semester/OOP/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/OOP.dir/src/GameField/FieldIter.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OOP.dir/src/GameField/FieldIter.cpp.o -c "/home/ice-jack/Projects/ETU_Basil_N/2nd course/1st semester/OOP/src/GameField/FieldIter.cpp"

CMakeFiles/OOP.dir/src/GameField/FieldIter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OOP.dir/src/GameField/FieldIter.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/ice-jack/Projects/ETU_Basil_N/2nd course/1st semester/OOP/src/GameField/FieldIter.cpp" > CMakeFiles/OOP.dir/src/GameField/FieldIter.cpp.i

CMakeFiles/OOP.dir/src/GameField/FieldIter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OOP.dir/src/GameField/FieldIter.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/ice-jack/Projects/ETU_Basil_N/2nd course/1st semester/OOP/src/GameField/FieldIter.cpp" -o CMakeFiles/OOP.dir/src/GameField/FieldIter.cpp.s

CMakeFiles/OOP.dir/src/GameField/Field.cpp.o: CMakeFiles/OOP.dir/flags.make
CMakeFiles/OOP.dir/src/GameField/Field.cpp.o: ../src/GameField/Field.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/ice-jack/Projects/ETU_Basil_N/2nd course/1st semester/OOP/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/OOP.dir/src/GameField/Field.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OOP.dir/src/GameField/Field.cpp.o -c "/home/ice-jack/Projects/ETU_Basil_N/2nd course/1st semester/OOP/src/GameField/Field.cpp"

CMakeFiles/OOP.dir/src/GameField/Field.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OOP.dir/src/GameField/Field.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/ice-jack/Projects/ETU_Basil_N/2nd course/1st semester/OOP/src/GameField/Field.cpp" > CMakeFiles/OOP.dir/src/GameField/Field.cpp.i

CMakeFiles/OOP.dir/src/GameField/Field.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OOP.dir/src/GameField/Field.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/ice-jack/Projects/ETU_Basil_N/2nd course/1st semester/OOP/src/GameField/Field.cpp" -o CMakeFiles/OOP.dir/src/GameField/Field.cpp.s

CMakeFiles/OOP.dir/src/logic/Controls.cpp.o: CMakeFiles/OOP.dir/flags.make
CMakeFiles/OOP.dir/src/logic/Controls.cpp.o: ../src/logic/Controls.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/ice-jack/Projects/ETU_Basil_N/2nd course/1st semester/OOP/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/OOP.dir/src/logic/Controls.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OOP.dir/src/logic/Controls.cpp.o -c "/home/ice-jack/Projects/ETU_Basil_N/2nd course/1st semester/OOP/src/logic/Controls.cpp"

CMakeFiles/OOP.dir/src/logic/Controls.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OOP.dir/src/logic/Controls.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/ice-jack/Projects/ETU_Basil_N/2nd course/1st semester/OOP/src/logic/Controls.cpp" > CMakeFiles/OOP.dir/src/logic/Controls.cpp.i

CMakeFiles/OOP.dir/src/logic/Controls.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OOP.dir/src/logic/Controls.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/ice-jack/Projects/ETU_Basil_N/2nd course/1st semester/OOP/src/logic/Controls.cpp" -o CMakeFiles/OOP.dir/src/logic/Controls.cpp.s

CMakeFiles/OOP.dir/src/logic/Game.cpp.o: CMakeFiles/OOP.dir/flags.make
CMakeFiles/OOP.dir/src/logic/Game.cpp.o: ../src/logic/Game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/ice-jack/Projects/ETU_Basil_N/2nd course/1st semester/OOP/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/OOP.dir/src/logic/Game.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OOP.dir/src/logic/Game.cpp.o -c "/home/ice-jack/Projects/ETU_Basil_N/2nd course/1st semester/OOP/src/logic/Game.cpp"

CMakeFiles/OOP.dir/src/logic/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OOP.dir/src/logic/Game.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/ice-jack/Projects/ETU_Basil_N/2nd course/1st semester/OOP/src/logic/Game.cpp" > CMakeFiles/OOP.dir/src/logic/Game.cpp.i

CMakeFiles/OOP.dir/src/logic/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OOP.dir/src/logic/Game.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/ice-jack/Projects/ETU_Basil_N/2nd course/1st semester/OOP/src/logic/Game.cpp" -o CMakeFiles/OOP.dir/src/logic/Game.cpp.s

# Object files for target OOP
OOP_OBJECTS = \
"CMakeFiles/OOP.dir/src/main.cpp.o" \
"CMakeFiles/OOP.dir/src/Buffs/Buff.cpp.o" \
"CMakeFiles/OOP.dir/src/GameField/Cell.cpp.o" \
"CMakeFiles/OOP.dir/src/GameField/levels.cpp.o" \
"CMakeFiles/OOP.dir/src/GameField/FieldRowIter.cpp.o" \
"CMakeFiles/OOP.dir/src/GameField/FieldIter.cpp.o" \
"CMakeFiles/OOP.dir/src/GameField/Field.cpp.o" \
"CMakeFiles/OOP.dir/src/logic/Controls.cpp.o" \
"CMakeFiles/OOP.dir/src/logic/Game.cpp.o"

# External object files for target OOP
OOP_EXTERNAL_OBJECTS =

OOP: CMakeFiles/OOP.dir/src/main.cpp.o
OOP: CMakeFiles/OOP.dir/src/Buffs/Buff.cpp.o
OOP: CMakeFiles/OOP.dir/src/GameField/Cell.cpp.o
OOP: CMakeFiles/OOP.dir/src/GameField/levels.cpp.o
OOP: CMakeFiles/OOP.dir/src/GameField/FieldRowIter.cpp.o
OOP: CMakeFiles/OOP.dir/src/GameField/FieldIter.cpp.o
OOP: CMakeFiles/OOP.dir/src/GameField/Field.cpp.o
OOP: CMakeFiles/OOP.dir/src/logic/Controls.cpp.o
OOP: CMakeFiles/OOP.dir/src/logic/Game.cpp.o
OOP: CMakeFiles/OOP.dir/build.make
OOP: CMakeFiles/OOP.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/ice-jack/Projects/ETU_Basil_N/2nd course/1st semester/OOP/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable OOP"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/OOP.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/OOP.dir/build: OOP

.PHONY : CMakeFiles/OOP.dir/build

CMakeFiles/OOP.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/OOP.dir/cmake_clean.cmake
.PHONY : CMakeFiles/OOP.dir/clean

CMakeFiles/OOP.dir/depend:
	cd "/home/ice-jack/Projects/ETU_Basil_N/2nd course/1st semester/OOP/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/ice-jack/Projects/ETU_Basil_N/2nd course/1st semester/OOP" "/home/ice-jack/Projects/ETU_Basil_N/2nd course/1st semester/OOP" "/home/ice-jack/Projects/ETU_Basil_N/2nd course/1st semester/OOP/cmake-build-debug" "/home/ice-jack/Projects/ETU_Basil_N/2nd course/1st semester/OOP/cmake-build-debug" "/home/ice-jack/Projects/ETU_Basil_N/2nd course/1st semester/OOP/cmake-build-debug/CMakeFiles/OOP.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/OOP.dir/depend

