# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /home/layzacs/Downloads/CLion-2019.2.1/clion-2019.2.1/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/layzacs/Downloads/CLion-2019.2.1/clion-2019.2.1/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/layzacs/projetos/PRG29003/projetos/prglib

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/layzacs/projetos/PRG29003/projetos/prglib/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Prglib.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Prglib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Prglib.dir/flags.make

CMakeFiles/Prglib.dir/main.cpp.o: CMakeFiles/Prglib.dir/flags.make
CMakeFiles/Prglib.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/layzacs/projetos/PRG29003/projetos/prglib/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Prglib.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Prglib.dir/main.cpp.o -c /home/layzacs/projetos/PRG29003/projetos/prglib/main.cpp

CMakeFiles/Prglib.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Prglib.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/layzacs/projetos/PRG29003/projetos/prglib/main.cpp > CMakeFiles/Prglib.dir/main.cpp.i

CMakeFiles/Prglib.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Prglib.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/layzacs/projetos/PRG29003/projetos/prglib/main.cpp -o CMakeFiles/Prglib.dir/main.cpp.s

# Object files for target Prglib
Prglib_OBJECTS = \
"CMakeFiles/Prglib.dir/main.cpp.o"

# External object files for target Prglib
Prglib_EXTERNAL_OBJECTS =

Prglib: CMakeFiles/Prglib.dir/main.cpp.o
Prglib: CMakeFiles/Prglib.dir/build.make
Prglib: CMakeFiles/Prglib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/layzacs/projetos/PRG29003/projetos/prglib/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Prglib"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Prglib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Prglib.dir/build: Prglib

.PHONY : CMakeFiles/Prglib.dir/build

CMakeFiles/Prglib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Prglib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Prglib.dir/clean

CMakeFiles/Prglib.dir/depend:
	cd /home/layzacs/projetos/PRG29003/projetos/prglib/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/layzacs/projetos/PRG29003/projetos/prglib /home/layzacs/projetos/PRG29003/projetos/prglib /home/layzacs/projetos/PRG29003/projetos/prglib/cmake-build-debug /home/layzacs/projetos/PRG29003/projetos/prglib/cmake-build-debug /home/layzacs/projetos/PRG29003/projetos/prglib/cmake-build-debug/CMakeFiles/Prglib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Prglib.dir/depend

