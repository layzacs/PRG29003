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
CMAKE_SOURCE_DIR = "/home/layzacs/Downloads/exercícios clion/lista_ordenada_inteiros/ListaOrdenadaInteiros"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/layzacs/Downloads/exercícios clion/lista_ordenada_inteiros/ListaOrdenadaInteiros/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/runTest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/runTest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/runTest.dir/flags.make

CMakeFiles/runTest.dir/test.cpp.o: CMakeFiles/runTest.dir/flags.make
CMakeFiles/runTest.dir/test.cpp.o: ../test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/layzacs/Downloads/exercícios clion/lista_ordenada_inteiros/ListaOrdenadaInteiros/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/runTest.dir/test.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/runTest.dir/test.cpp.o -c "/home/layzacs/Downloads/exercícios clion/lista_ordenada_inteiros/ListaOrdenadaInteiros/test.cpp"

CMakeFiles/runTest.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runTest.dir/test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/layzacs/Downloads/exercícios clion/lista_ordenada_inteiros/ListaOrdenadaInteiros/test.cpp" > CMakeFiles/runTest.dir/test.cpp.i

CMakeFiles/runTest.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runTest.dir/test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/layzacs/Downloads/exercícios clion/lista_ordenada_inteiros/ListaOrdenadaInteiros/test.cpp" -o CMakeFiles/runTest.dir/test.cpp.s

CMakeFiles/runTest.dir/questao.cpp.o: CMakeFiles/runTest.dir/flags.make
CMakeFiles/runTest.dir/questao.cpp.o: ../questao.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/layzacs/Downloads/exercícios clion/lista_ordenada_inteiros/ListaOrdenadaInteiros/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/runTest.dir/questao.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/runTest.dir/questao.cpp.o -c "/home/layzacs/Downloads/exercícios clion/lista_ordenada_inteiros/ListaOrdenadaInteiros/questao.cpp"

CMakeFiles/runTest.dir/questao.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runTest.dir/questao.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/layzacs/Downloads/exercícios clion/lista_ordenada_inteiros/ListaOrdenadaInteiros/questao.cpp" > CMakeFiles/runTest.dir/questao.cpp.i

CMakeFiles/runTest.dir/questao.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runTest.dir/questao.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/layzacs/Downloads/exercícios clion/lista_ordenada_inteiros/ListaOrdenadaInteiros/questao.cpp" -o CMakeFiles/runTest.dir/questao.cpp.s

# Object files for target runTest
runTest_OBJECTS = \
"CMakeFiles/runTest.dir/test.cpp.o" \
"CMakeFiles/runTest.dir/questao.cpp.o"

# External object files for target runTest
runTest_EXTERNAL_OBJECTS =

runTest: CMakeFiles/runTest.dir/test.cpp.o
runTest: CMakeFiles/runTest.dir/questao.cpp.o
runTest: CMakeFiles/runTest.dir/build.make
runTest: lib/libgtestd.a
runTest: lib/libgtest_maind.a
runTest: lib/libgtestd.a
runTest: CMakeFiles/runTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/layzacs/Downloads/exercícios clion/lista_ordenada_inteiros/ListaOrdenadaInteiros/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable runTest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/runTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/runTest.dir/build: runTest

.PHONY : CMakeFiles/runTest.dir/build

CMakeFiles/runTest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/runTest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/runTest.dir/clean

CMakeFiles/runTest.dir/depend:
	cd "/home/layzacs/Downloads/exercícios clion/lista_ordenada_inteiros/ListaOrdenadaInteiros/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/layzacs/Downloads/exercícios clion/lista_ordenada_inteiros/ListaOrdenadaInteiros" "/home/layzacs/Downloads/exercícios clion/lista_ordenada_inteiros/ListaOrdenadaInteiros" "/home/layzacs/Downloads/exercícios clion/lista_ordenada_inteiros/ListaOrdenadaInteiros/cmake-build-debug" "/home/layzacs/Downloads/exercícios clion/lista_ordenada_inteiros/ListaOrdenadaInteiros/cmake-build-debug" "/home/layzacs/Downloads/exercícios clion/lista_ordenada_inteiros/ListaOrdenadaInteiros/cmake-build-debug/CMakeFiles/runTest.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/runTest.dir/depend

