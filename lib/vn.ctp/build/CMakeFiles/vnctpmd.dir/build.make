# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /var/local/Heron/lib/vn.ctp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /var/local/Heron/lib/vn.ctp/build

# Include any dependencies generated for this target.
include CMakeFiles/vnctpmd.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/vnctpmd.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/vnctpmd.dir/flags.make

CMakeFiles/vnctpmd.dir/vnctpmd/vnctpmd/vnctpmd.cpp.o: CMakeFiles/vnctpmd.dir/flags.make
CMakeFiles/vnctpmd.dir/vnctpmd/vnctpmd/vnctpmd.cpp.o: ../vnctpmd/vnctpmd/vnctpmd.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/var/local/Heron/lib/vn.ctp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/vnctpmd.dir/vnctpmd/vnctpmd/vnctpmd.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/vnctpmd.dir/vnctpmd/vnctpmd/vnctpmd.cpp.o -c /var/local/Heron/lib/vn.ctp/vnctpmd/vnctpmd/vnctpmd.cpp

CMakeFiles/vnctpmd.dir/vnctpmd/vnctpmd/vnctpmd.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vnctpmd.dir/vnctpmd/vnctpmd/vnctpmd.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /var/local/Heron/lib/vn.ctp/vnctpmd/vnctpmd/vnctpmd.cpp > CMakeFiles/vnctpmd.dir/vnctpmd/vnctpmd/vnctpmd.cpp.i

CMakeFiles/vnctpmd.dir/vnctpmd/vnctpmd/vnctpmd.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vnctpmd.dir/vnctpmd/vnctpmd/vnctpmd.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /var/local/Heron/lib/vn.ctp/vnctpmd/vnctpmd/vnctpmd.cpp -o CMakeFiles/vnctpmd.dir/vnctpmd/vnctpmd/vnctpmd.cpp.s

CMakeFiles/vnctpmd.dir/vnctpmd/vnctpmd/vnctpmd.cpp.o.requires:

.PHONY : CMakeFiles/vnctpmd.dir/vnctpmd/vnctpmd/vnctpmd.cpp.o.requires

CMakeFiles/vnctpmd.dir/vnctpmd/vnctpmd/vnctpmd.cpp.o.provides: CMakeFiles/vnctpmd.dir/vnctpmd/vnctpmd/vnctpmd.cpp.o.requires
	$(MAKE) -f CMakeFiles/vnctpmd.dir/build.make CMakeFiles/vnctpmd.dir/vnctpmd/vnctpmd/vnctpmd.cpp.o.provides.build
.PHONY : CMakeFiles/vnctpmd.dir/vnctpmd/vnctpmd/vnctpmd.cpp.o.provides

CMakeFiles/vnctpmd.dir/vnctpmd/vnctpmd/vnctpmd.cpp.o.provides.build: CMakeFiles/vnctpmd.dir/vnctpmd/vnctpmd/vnctpmd.cpp.o


# Object files for target vnctpmd
vnctpmd_OBJECTS = \
"CMakeFiles/vnctpmd.dir/vnctpmd/vnctpmd/vnctpmd.cpp.o"

# External object files for target vnctpmd
vnctpmd_EXTERNAL_OBJECTS =

lib/vnctpmd.so: CMakeFiles/vnctpmd.dir/vnctpmd/vnctpmd/vnctpmd.cpp.o
lib/vnctpmd.so: CMakeFiles/vnctpmd.dir/build.make
lib/vnctpmd.so: /usr/lib/x86_64-linux-gnu/libboost_python.so
lib/vnctpmd.so: /usr/lib/x86_64-linux-gnu/libboost_thread.so
lib/vnctpmd.so: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
lib/vnctpmd.so: /usr/lib/x86_64-linux-gnu/libboost_system.so
lib/vnctpmd.so: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
lib/vnctpmd.so: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
lib/vnctpmd.so: /usr/lib/x86_64-linux-gnu/libpthread.so
lib/vnctpmd.so: /home/ubuntu/anaconda2/lib/libpython2.7.so
lib/vnctpmd.so: ../ctpapi/x64_linux/libthostmduserapi.so
lib/vnctpmd.so: CMakeFiles/vnctpmd.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/var/local/Heron/lib/vn.ctp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library lib/vnctpmd.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/vnctpmd.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/vnctpmd.dir/build: lib/vnctpmd.so

.PHONY : CMakeFiles/vnctpmd.dir/build

CMakeFiles/vnctpmd.dir/requires: CMakeFiles/vnctpmd.dir/vnctpmd/vnctpmd/vnctpmd.cpp.o.requires

.PHONY : CMakeFiles/vnctpmd.dir/requires

CMakeFiles/vnctpmd.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/vnctpmd.dir/cmake_clean.cmake
.PHONY : CMakeFiles/vnctpmd.dir/clean

CMakeFiles/vnctpmd.dir/depend:
	cd /var/local/Heron/lib/vn.ctp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /var/local/Heron/lib/vn.ctp /var/local/Heron/lib/vn.ctp /var/local/Heron/lib/vn.ctp/build /var/local/Heron/lib/vn.ctp/build /var/local/Heron/lib/vn.ctp/build/CMakeFiles/vnctpmd.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/vnctpmd.dir/depend

