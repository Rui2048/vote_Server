# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/ray/c++/vote_Server/vote_Server/protobuf

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ray/c++/vote_Server/vote_Server/protobuf/build_protolib

# Include any dependencies generated for this target.
include CMakeFiles/protolib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/protolib.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/protolib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/protolib.dir/flags.make

CMakeFiles/protolib.dir/voteServer_proto.pb.o: CMakeFiles/protolib.dir/flags.make
CMakeFiles/protolib.dir/voteServer_proto.pb.o: ../voteServer_proto.pb.cc
CMakeFiles/protolib.dir/voteServer_proto.pb.o: CMakeFiles/protolib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ray/c++/vote_Server/vote_Server/protobuf/build_protolib/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/protolib.dir/voteServer_proto.pb.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/protolib.dir/voteServer_proto.pb.o -MF CMakeFiles/protolib.dir/voteServer_proto.pb.o.d -o CMakeFiles/protolib.dir/voteServer_proto.pb.o -c /home/ray/c++/vote_Server/vote_Server/protobuf/voteServer_proto.pb.cc

CMakeFiles/protolib.dir/voteServer_proto.pb.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/protolib.dir/voteServer_proto.pb.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ray/c++/vote_Server/vote_Server/protobuf/voteServer_proto.pb.cc > CMakeFiles/protolib.dir/voteServer_proto.pb.i

CMakeFiles/protolib.dir/voteServer_proto.pb.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/protolib.dir/voteServer_proto.pb.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ray/c++/vote_Server/vote_Server/protobuf/voteServer_proto.pb.cc -o CMakeFiles/protolib.dir/voteServer_proto.pb.s

# Object files for target protolib
protolib_OBJECTS = \
"CMakeFiles/protolib.dir/voteServer_proto.pb.o"

# External object files for target protolib
protolib_EXTERNAL_OBJECTS =

/home/ray/c++/vote_Server/vote_Server/build/lib/libprotolib.a: CMakeFiles/protolib.dir/voteServer_proto.pb.o
/home/ray/c++/vote_Server/vote_Server/build/lib/libprotolib.a: CMakeFiles/protolib.dir/build.make
/home/ray/c++/vote_Server/vote_Server/build/lib/libprotolib.a: CMakeFiles/protolib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ray/c++/vote_Server/vote_Server/protobuf/build_protolib/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library /home/ray/c++/vote_Server/vote_Server/build/lib/libprotolib.a"
	$(CMAKE_COMMAND) -P CMakeFiles/protolib.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/protolib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/protolib.dir/build: /home/ray/c++/vote_Server/vote_Server/build/lib/libprotolib.a
.PHONY : CMakeFiles/protolib.dir/build

CMakeFiles/protolib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/protolib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/protolib.dir/clean

CMakeFiles/protolib.dir/depend:
	cd /home/ray/c++/vote_Server/vote_Server/protobuf/build_protolib && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ray/c++/vote_Server/vote_Server/protobuf /home/ray/c++/vote_Server/vote_Server/protobuf /home/ray/c++/vote_Server/vote_Server/protobuf/build_protolib /home/ray/c++/vote_Server/vote_Server/protobuf/build_protolib /home/ray/c++/vote_Server/vote_Server/protobuf/build_protolib/CMakeFiles/protolib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/protolib.dir/depend
