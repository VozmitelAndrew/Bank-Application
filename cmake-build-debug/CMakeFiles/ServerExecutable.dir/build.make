# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/Users/andre/CLionProjects/BankMasterv3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/andre/CLionProjects/BankMasterv3/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ServerExecutable.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ServerExecutable.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ServerExecutable.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ServerExecutable.dir/flags.make

CMakeFiles/ServerExecutable.dir/Server.cpp.o: CMakeFiles/ServerExecutable.dir/flags.make
CMakeFiles/ServerExecutable.dir/Server.cpp.o: /mnt/c/Users/andre/CLionProjects/BankMasterv3/Server.cpp
CMakeFiles/ServerExecutable.dir/Server.cpp.o: CMakeFiles/ServerExecutable.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/c/Users/andre/CLionProjects/BankMasterv3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ServerExecutable.dir/Server.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ServerExecutable.dir/Server.cpp.o -MF CMakeFiles/ServerExecutable.dir/Server.cpp.o.d -o CMakeFiles/ServerExecutable.dir/Server.cpp.o -c /mnt/c/Users/andre/CLionProjects/BankMasterv3/Server.cpp

CMakeFiles/ServerExecutable.dir/Server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ServerExecutable.dir/Server.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/andre/CLionProjects/BankMasterv3/Server.cpp > CMakeFiles/ServerExecutable.dir/Server.cpp.i

CMakeFiles/ServerExecutable.dir/Server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ServerExecutable.dir/Server.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/andre/CLionProjects/BankMasterv3/Server.cpp -o CMakeFiles/ServerExecutable.dir/Server.cpp.s

# Object files for target ServerExecutable
ServerExecutable_OBJECTS = \
"CMakeFiles/ServerExecutable.dir/Server.cpp.o"

# External object files for target ServerExecutable
ServerExecutable_EXTERNAL_OBJECTS =

ServerExecutable: CMakeFiles/ServerExecutable.dir/Server.cpp.o
ServerExecutable: CMakeFiles/ServerExecutable.dir/build.make
ServerExecutable: CMakeFiles/ServerExecutable.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/mnt/c/Users/andre/CLionProjects/BankMasterv3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ServerExecutable"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ServerExecutable.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ServerExecutable.dir/build: ServerExecutable
.PHONY : CMakeFiles/ServerExecutable.dir/build

CMakeFiles/ServerExecutable.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ServerExecutable.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ServerExecutable.dir/clean

CMakeFiles/ServerExecutable.dir/depend:
	cd /mnt/c/Users/andre/CLionProjects/BankMasterv3/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/andre/CLionProjects/BankMasterv3 /mnt/c/Users/andre/CLionProjects/BankMasterv3 /mnt/c/Users/andre/CLionProjects/BankMasterv3/cmake-build-debug /mnt/c/Users/andre/CLionProjects/BankMasterv3/cmake-build-debug /mnt/c/Users/andre/CLionProjects/BankMasterv3/cmake-build-debug/CMakeFiles/ServerExecutable.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/ServerExecutable.dir/depend

