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
CMAKE_SOURCE_DIR = /home/layzacs/projetos/PRG29003/projetos/projeto-4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/layzacs/projetos/PRG29003/projetos/projeto-4/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/dicionario.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/dicionario.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/dicionario.dir/flags.make

CMakeFiles/dicionario.dir/verbete.cpp.o: CMakeFiles/dicionario.dir/flags.make
CMakeFiles/dicionario.dir/verbete.cpp.o: ../verbete.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/layzacs/projetos/PRG29003/projetos/projeto-4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/dicionario.dir/verbete.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dicionario.dir/verbete.cpp.o -c /home/layzacs/projetos/PRG29003/projetos/projeto-4/verbete.cpp

CMakeFiles/dicionario.dir/verbete.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dicionario.dir/verbete.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/layzacs/projetos/PRG29003/projetos/projeto-4/verbete.cpp > CMakeFiles/dicionario.dir/verbete.cpp.i

CMakeFiles/dicionario.dir/verbete.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dicionario.dir/verbete.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/layzacs/projetos/PRG29003/projetos/projeto-4/verbete.cpp -o CMakeFiles/dicionario.dir/verbete.cpp.s

CMakeFiles/dicionario.dir/main.cpp.o: CMakeFiles/dicionario.dir/flags.make
CMakeFiles/dicionario.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/layzacs/projetos/PRG29003/projetos/projeto-4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/dicionario.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dicionario.dir/main.cpp.o -c /home/layzacs/projetos/PRG29003/projetos/projeto-4/main.cpp

CMakeFiles/dicionario.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dicionario.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/layzacs/projetos/PRG29003/projetos/projeto-4/main.cpp > CMakeFiles/dicionario.dir/main.cpp.i

CMakeFiles/dicionario.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dicionario.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/layzacs/projetos/PRG29003/projetos/projeto-4/main.cpp -o CMakeFiles/dicionario.dir/main.cpp.s

# Object files for target dicionario
dicionario_OBJECTS = \
"CMakeFiles/dicionario.dir/verbete.cpp.o" \
"CMakeFiles/dicionario.dir/main.cpp.o"

# External object files for target dicionario
dicionario_EXTERNAL_OBJECTS =

libdicionario.a: CMakeFiles/dicionario.dir/verbete.cpp.o
libdicionario.a: CMakeFiles/dicionario.dir/main.cpp.o
libdicionario.a: CMakeFiles/dicionario.dir/build.make
libdicionario.a: CMakeFiles/dicionario.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/layzacs/projetos/PRG29003/projetos/projeto-4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libdicionario.a"
	$(CMAKE_COMMAND) -P CMakeFiles/dicionario.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dicionario.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/dicionario.dir/build: libdicionario.a

.PHONY : CMakeFiles/dicionario.dir/build

CMakeFiles/dicionario.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/dicionario.dir/cmake_clean.cmake
.PHONY : CMakeFiles/dicionario.dir/clean

CMakeFiles/dicionario.dir/depend:
	cd /home/layzacs/projetos/PRG29003/projetos/projeto-4/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/layzacs/projetos/PRG29003/projetos/projeto-4 /home/layzacs/projetos/PRG29003/projetos/projeto-4 /home/layzacs/projetos/PRG29003/projetos/projeto-4/cmake-build-debug /home/layzacs/projetos/PRG29003/projetos/projeto-4/cmake-build-debug /home/layzacs/projetos/PRG29003/projetos/projeto-4/cmake-build-debug/CMakeFiles/dicionario.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/dicionario.dir/depend

