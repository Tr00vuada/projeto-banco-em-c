# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/clion/250/bin/cmake/linux/x64/bin/cmake

# The command to remove a file.
RM = /snap/clion/250/bin/cmake/linux/x64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/tr00vuada/Área de Trabalho/Projetos de DEV/Conteúdos de C/projeto-banco"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/tr00vuada/Área de Trabalho/Projetos de DEV/Conteúdos de C/projeto-banco/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/projeto_banco.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/projeto_banco.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/projeto_banco.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/projeto_banco.dir/flags.make

CMakeFiles/projeto_banco.dir/main.c.o: CMakeFiles/projeto_banco.dir/flags.make
CMakeFiles/projeto_banco.dir/main.c.o: /home/tr00vuada/Área\ de\ Trabalho/Projetos\ de\ DEV/Conteúdos\ de\ C/projeto-banco/main.c
CMakeFiles/projeto_banco.dir/main.c.o: CMakeFiles/projeto_banco.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/tr00vuada/Área de Trabalho/Projetos de DEV/Conteúdos de C/projeto-banco/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/projeto_banco.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/projeto_banco.dir/main.c.o -MF CMakeFiles/projeto_banco.dir/main.c.o.d -o CMakeFiles/projeto_banco.dir/main.c.o -c "/home/tr00vuada/Área de Trabalho/Projetos de DEV/Conteúdos de C/projeto-banco/main.c"

CMakeFiles/projeto_banco.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/projeto_banco.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/tr00vuada/Área de Trabalho/Projetos de DEV/Conteúdos de C/projeto-banco/main.c" > CMakeFiles/projeto_banco.dir/main.c.i

CMakeFiles/projeto_banco.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/projeto_banco.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/tr00vuada/Área de Trabalho/Projetos de DEV/Conteúdos de C/projeto-banco/main.c" -o CMakeFiles/projeto_banco.dir/main.c.s

# Object files for target projeto_banco
projeto_banco_OBJECTS = \
"CMakeFiles/projeto_banco.dir/main.c.o"

# External object files for target projeto_banco
projeto_banco_EXTERNAL_OBJECTS =

projeto_banco: CMakeFiles/projeto_banco.dir/main.c.o
projeto_banco: CMakeFiles/projeto_banco.dir/build.make
projeto_banco: CMakeFiles/projeto_banco.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/tr00vuada/Área de Trabalho/Projetos de DEV/Conteúdos de C/projeto-banco/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable projeto_banco"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/projeto_banco.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/projeto_banco.dir/build: projeto_banco
.PHONY : CMakeFiles/projeto_banco.dir/build

CMakeFiles/projeto_banco.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/projeto_banco.dir/cmake_clean.cmake
.PHONY : CMakeFiles/projeto_banco.dir/clean

CMakeFiles/projeto_banco.dir/depend:
	cd "/home/tr00vuada/Área de Trabalho/Projetos de DEV/Conteúdos de C/projeto-banco/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/tr00vuada/Área de Trabalho/Projetos de DEV/Conteúdos de C/projeto-banco" "/home/tr00vuada/Área de Trabalho/Projetos de DEV/Conteúdos de C/projeto-banco" "/home/tr00vuada/Área de Trabalho/Projetos de DEV/Conteúdos de C/projeto-banco/cmake-build-debug" "/home/tr00vuada/Área de Trabalho/Projetos de DEV/Conteúdos de C/projeto-banco/cmake-build-debug" "/home/tr00vuada/Área de Trabalho/Projetos de DEV/Conteúdos de C/projeto-banco/cmake-build-debug/CMakeFiles/projeto_banco.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/projeto_banco.dir/depend

