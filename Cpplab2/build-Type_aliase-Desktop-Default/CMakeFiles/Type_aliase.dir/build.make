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
CMAKE_SOURCE_DIR = /home/mateusz/Dokumenty/KursCpp/Cpplab2/Type_aliase

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mateusz/Dokumenty/KursCpp/Cpplab2/build-Type_aliase-Desktop-Default

# Include any dependencies generated for this target.
include CMakeFiles/Type_aliase.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Type_aliase.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Type_aliase.dir/flags.make

CMakeFiles/Type_aliase.dir/main.cpp.o: CMakeFiles/Type_aliase.dir/flags.make
CMakeFiles/Type_aliase.dir/main.cpp.o: /home/mateusz/Dokumenty/KursCpp/Cpplab2/Type_aliase/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mateusz/Dokumenty/KursCpp/Cpplab2/build-Type_aliase-Desktop-Default/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Type_aliase.dir/main.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Type_aliase.dir/main.cpp.o -c /home/mateusz/Dokumenty/KursCpp/Cpplab2/Type_aliase/main.cpp

CMakeFiles/Type_aliase.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Type_aliase.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mateusz/Dokumenty/KursCpp/Cpplab2/Type_aliase/main.cpp > CMakeFiles/Type_aliase.dir/main.cpp.i

CMakeFiles/Type_aliase.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Type_aliase.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mateusz/Dokumenty/KursCpp/Cpplab2/Type_aliase/main.cpp -o CMakeFiles/Type_aliase.dir/main.cpp.s

CMakeFiles/Type_aliase.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/Type_aliase.dir/main.cpp.o.requires

CMakeFiles/Type_aliase.dir/main.cpp.o.provides: CMakeFiles/Type_aliase.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Type_aliase.dir/build.make CMakeFiles/Type_aliase.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Type_aliase.dir/main.cpp.o.provides

CMakeFiles/Type_aliase.dir/main.cpp.o.provides.build: CMakeFiles/Type_aliase.dir/main.cpp.o


# Object files for target Type_aliase
Type_aliase_OBJECTS = \
"CMakeFiles/Type_aliase.dir/main.cpp.o"

# External object files for target Type_aliase
Type_aliase_EXTERNAL_OBJECTS =

Type_aliase: CMakeFiles/Type_aliase.dir/main.cpp.o
Type_aliase: CMakeFiles/Type_aliase.dir/build.make
Type_aliase: CMakeFiles/Type_aliase.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mateusz/Dokumenty/KursCpp/Cpplab2/build-Type_aliase-Desktop-Default/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Type_aliase"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Type_aliase.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Type_aliase.dir/build: Type_aliase

.PHONY : CMakeFiles/Type_aliase.dir/build

CMakeFiles/Type_aliase.dir/requires: CMakeFiles/Type_aliase.dir/main.cpp.o.requires

.PHONY : CMakeFiles/Type_aliase.dir/requires

CMakeFiles/Type_aliase.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Type_aliase.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Type_aliase.dir/clean

CMakeFiles/Type_aliase.dir/depend:
	cd /home/mateusz/Dokumenty/KursCpp/Cpplab2/build-Type_aliase-Desktop-Default && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mateusz/Dokumenty/KursCpp/Cpplab2/Type_aliase /home/mateusz/Dokumenty/KursCpp/Cpplab2/Type_aliase /home/mateusz/Dokumenty/KursCpp/Cpplab2/build-Type_aliase-Desktop-Default /home/mateusz/Dokumenty/KursCpp/Cpplab2/build-Type_aliase-Desktop-Default /home/mateusz/Dokumenty/KursCpp/Cpplab2/build-Type_aliase-Desktop-Default/CMakeFiles/Type_aliase.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Type_aliase.dir/depend

