# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /snap/clion/73/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/73/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mauske/Studium/ADS/ADS/Praktika/Praktikum3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mauske/Studium/ADS/ADS/Praktika/Praktikum3/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Praktikum3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Praktikum3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Praktikum3.dir/flags.make

CMakeFiles/Praktikum3.dir/main.cpp.o: CMakeFiles/Praktikum3.dir/flags.make
CMakeFiles/Praktikum3.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mauske/Studium/ADS/ADS/Praktika/Praktikum3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Praktikum3.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Praktikum3.dir/main.cpp.o -c /home/mauske/Studium/ADS/ADS/Praktika/Praktikum3/main.cpp

CMakeFiles/Praktikum3.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Praktikum3.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mauske/Studium/ADS/ADS/Praktika/Praktikum3/main.cpp > CMakeFiles/Praktikum3.dir/main.cpp.i

CMakeFiles/Praktikum3.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Praktikum3.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mauske/Studium/ADS/ADS/Praktika/Praktikum3/main.cpp -o CMakeFiles/Praktikum3.dir/main.cpp.s

CMakeFiles/Praktikum3.dir/Tree.cpp.o: CMakeFiles/Praktikum3.dir/flags.make
CMakeFiles/Praktikum3.dir/Tree.cpp.o: ../Tree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mauske/Studium/ADS/ADS/Praktika/Praktikum3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Praktikum3.dir/Tree.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Praktikum3.dir/Tree.cpp.o -c /home/mauske/Studium/ADS/ADS/Praktika/Praktikum3/Tree.cpp

CMakeFiles/Praktikum3.dir/Tree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Praktikum3.dir/Tree.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mauske/Studium/ADS/ADS/Praktika/Praktikum3/Tree.cpp > CMakeFiles/Praktikum3.dir/Tree.cpp.i

CMakeFiles/Praktikum3.dir/Tree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Praktikum3.dir/Tree.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mauske/Studium/ADS/ADS/Praktika/Praktikum3/Tree.cpp -o CMakeFiles/Praktikum3.dir/Tree.cpp.s

CMakeFiles/Praktikum3.dir/TreeNode.cpp.o: CMakeFiles/Praktikum3.dir/flags.make
CMakeFiles/Praktikum3.dir/TreeNode.cpp.o: ../TreeNode.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mauske/Studium/ADS/ADS/Praktika/Praktikum3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Praktikum3.dir/TreeNode.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Praktikum3.dir/TreeNode.cpp.o -c /home/mauske/Studium/ADS/ADS/Praktika/Praktikum3/TreeNode.cpp

CMakeFiles/Praktikum3.dir/TreeNode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Praktikum3.dir/TreeNode.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mauske/Studium/ADS/ADS/Praktika/Praktikum3/TreeNode.cpp > CMakeFiles/Praktikum3.dir/TreeNode.cpp.i

CMakeFiles/Praktikum3.dir/TreeNode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Praktikum3.dir/TreeNode.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mauske/Studium/ADS/ADS/Praktika/Praktikum3/TreeNode.cpp -o CMakeFiles/Praktikum3.dir/TreeNode.cpp.s

CMakeFiles/Praktikum3.dir/TreeTest.cpp.o: CMakeFiles/Praktikum3.dir/flags.make
CMakeFiles/Praktikum3.dir/TreeTest.cpp.o: ../TreeTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mauske/Studium/ADS/ADS/Praktika/Praktikum3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Praktikum3.dir/TreeTest.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Praktikum3.dir/TreeTest.cpp.o -c /home/mauske/Studium/ADS/ADS/Praktika/Praktikum3/TreeTest.cpp

CMakeFiles/Praktikum3.dir/TreeTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Praktikum3.dir/TreeTest.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mauske/Studium/ADS/ADS/Praktika/Praktikum3/TreeTest.cpp > CMakeFiles/Praktikum3.dir/TreeTest.cpp.i

CMakeFiles/Praktikum3.dir/TreeTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Praktikum3.dir/TreeTest.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mauske/Studium/ADS/ADS/Praktika/Praktikum3/TreeTest.cpp -o CMakeFiles/Praktikum3.dir/TreeTest.cpp.s

# Object files for target Praktikum3
Praktikum3_OBJECTS = \
"CMakeFiles/Praktikum3.dir/main.cpp.o" \
"CMakeFiles/Praktikum3.dir/Tree.cpp.o" \
"CMakeFiles/Praktikum3.dir/TreeNode.cpp.o" \
"CMakeFiles/Praktikum3.dir/TreeTest.cpp.o"

# External object files for target Praktikum3
Praktikum3_EXTERNAL_OBJECTS =

Praktikum3: CMakeFiles/Praktikum3.dir/main.cpp.o
Praktikum3: CMakeFiles/Praktikum3.dir/Tree.cpp.o
Praktikum3: CMakeFiles/Praktikum3.dir/TreeNode.cpp.o
Praktikum3: CMakeFiles/Praktikum3.dir/TreeTest.cpp.o
Praktikum3: CMakeFiles/Praktikum3.dir/build.make
Praktikum3: CMakeFiles/Praktikum3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mauske/Studium/ADS/ADS/Praktika/Praktikum3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable Praktikum3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Praktikum3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Praktikum3.dir/build: Praktikum3

.PHONY : CMakeFiles/Praktikum3.dir/build

CMakeFiles/Praktikum3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Praktikum3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Praktikum3.dir/clean

CMakeFiles/Praktikum3.dir/depend:
	cd /home/mauske/Studium/ADS/ADS/Praktika/Praktikum3/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mauske/Studium/ADS/ADS/Praktika/Praktikum3 /home/mauske/Studium/ADS/ADS/Praktika/Praktikum3 /home/mauske/Studium/ADS/ADS/Praktika/Praktikum3/cmake-build-debug /home/mauske/Studium/ADS/ADS/Praktika/Praktikum3/cmake-build-debug /home/mauske/Studium/ADS/ADS/Praktika/Praktikum3/cmake-build-debug/CMakeFiles/Praktikum3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Praktikum3.dir/depend

