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
CMAKE_COMMAND = /home/layzacs/Downloads/CLion-2019.2.1/clion-2019.2.1/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/layzacs/Downloads/CLion-2019.2.1/clion-2019.2.1/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/layzacs/projetos/PRG29003/projetos/projeto-3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/layzacs/projetos/PRG29003/projetos/projeto-3/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Bacon.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Bacon.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Bacon.dir/flags.make

CMakeFiles/Bacon.dir/main.cpp.o: CMakeFiles/Bacon.dir/flags.make
CMakeFiles/Bacon.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/layzacs/projetos/PRG29003/projetos/projeto-3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Bacon.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Bacon.dir/main.cpp.o -c /home/layzacs/projetos/PRG29003/projetos/projeto-3/main.cpp

CMakeFiles/Bacon.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Bacon.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/layzacs/projetos/PRG29003/projetos/projeto-3/main.cpp > CMakeFiles/Bacon.dir/main.cpp.i

CMakeFiles/Bacon.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Bacon.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/layzacs/projetos/PRG29003/projetos/projeto-3/main.cpp -o CMakeFiles/Bacon.dir/main.cpp.s

CMakeFiles/Bacon.dir/proc.cpp.o: CMakeFiles/Bacon.dir/flags.make
CMakeFiles/Bacon.dir/proc.cpp.o: ../proc.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/layzacs/projetos/PRG29003/projetos/projeto-3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Bacon.dir/proc.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Bacon.dir/proc.cpp.o -c /home/layzacs/projetos/PRG29003/projetos/projeto-3/proc.cpp

CMakeFiles/Bacon.dir/proc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Bacon.dir/proc.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/layzacs/projetos/PRG29003/projetos/projeto-3/proc.cpp > CMakeFiles/Bacon.dir/proc.cpp.i

CMakeFiles/Bacon.dir/proc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Bacon.dir/proc.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/layzacs/projetos/PRG29003/projetos/projeto-3/proc.cpp -o CMakeFiles/Bacon.dir/proc.cpp.s

# Object files for target Bacon
Bacon_OBJECTS = \
"CMakeFiles/Bacon.dir/main.cpp.o" \
"CMakeFiles/Bacon.dir/proc.cpp.o"

# External object files for target Bacon
Bacon_EXTERNAL_OBJECTS =

Bacon: CMakeFiles/Bacon.dir/main.cpp.o
Bacon: CMakeFiles/Bacon.dir/proc.cpp.o
Bacon: CMakeFiles/Bacon.dir/build.make
Bacon: CMakeFiles/Bacon.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/layzacs/projetos/PRG29003/projetos/projeto-3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Bacon"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Bacon.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Bacon.dir/build: Bacon

.PHONY : CMakeFiles/Bacon.dir/build

CMakeFiles/Bacon.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Bacon.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Bacon.dir/clean

CMakeFiles/Bacon.dir/depend:
	cd /home/layzacs/projetos/PRG29003/projetos/projeto-3/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/layzacs/projetos/PRG29003/projetos/projeto-3 /home/layzacs/projetos/PRG29003/projetos/projeto-3 /home/layzacs/projetos/PRG29003/projetos/projeto-3/cmake-build-debug /home/layzacs/projetos/PRG29003/projetos/projeto-3/cmake-build-debug /home/layzacs/projetos/PRG29003/projetos/projeto-3/cmake-build-debug/CMakeFiles/Bacon.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Bacon.dir/depend
