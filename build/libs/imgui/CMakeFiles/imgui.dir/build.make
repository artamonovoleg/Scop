# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_SOURCE_DIR = /home/user/Documents/C++/Scop

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/user/Documents/C++/Scop/build

# Include any dependencies generated for this target.
include libs/imgui/CMakeFiles/imgui.dir/depend.make

# Include the progress variables for this target.
include libs/imgui/CMakeFiles/imgui.dir/progress.make

# Include the compile flags for this target's objects.
include libs/imgui/CMakeFiles/imgui.dir/flags.make

libs/imgui/CMakeFiles/imgui.dir/imgui.cpp.o: libs/imgui/CMakeFiles/imgui.dir/flags.make
libs/imgui/CMakeFiles/imgui.dir/imgui.cpp.o: ../libs/imgui/imgui.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/Documents/C++/Scop/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object libs/imgui/CMakeFiles/imgui.dir/imgui.cpp.o"
	cd /home/user/Documents/C++/Scop/build/libs/imgui && /bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/imgui.dir/imgui.cpp.o -c /home/user/Documents/C++/Scop/libs/imgui/imgui.cpp

libs/imgui/CMakeFiles/imgui.dir/imgui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/imgui.dir/imgui.cpp.i"
	cd /home/user/Documents/C++/Scop/build/libs/imgui && /bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/Documents/C++/Scop/libs/imgui/imgui.cpp > CMakeFiles/imgui.dir/imgui.cpp.i

libs/imgui/CMakeFiles/imgui.dir/imgui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/imgui.dir/imgui.cpp.s"
	cd /home/user/Documents/C++/Scop/build/libs/imgui && /bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/Documents/C++/Scop/libs/imgui/imgui.cpp -o CMakeFiles/imgui.dir/imgui.cpp.s

libs/imgui/CMakeFiles/imgui.dir/imgui_demo.cpp.o: libs/imgui/CMakeFiles/imgui.dir/flags.make
libs/imgui/CMakeFiles/imgui.dir/imgui_demo.cpp.o: ../libs/imgui/imgui_demo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/Documents/C++/Scop/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object libs/imgui/CMakeFiles/imgui.dir/imgui_demo.cpp.o"
	cd /home/user/Documents/C++/Scop/build/libs/imgui && /bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/imgui.dir/imgui_demo.cpp.o -c /home/user/Documents/C++/Scop/libs/imgui/imgui_demo.cpp

libs/imgui/CMakeFiles/imgui.dir/imgui_demo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/imgui.dir/imgui_demo.cpp.i"
	cd /home/user/Documents/C++/Scop/build/libs/imgui && /bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/Documents/C++/Scop/libs/imgui/imgui_demo.cpp > CMakeFiles/imgui.dir/imgui_demo.cpp.i

libs/imgui/CMakeFiles/imgui.dir/imgui_demo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/imgui.dir/imgui_demo.cpp.s"
	cd /home/user/Documents/C++/Scop/build/libs/imgui && /bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/Documents/C++/Scop/libs/imgui/imgui_demo.cpp -o CMakeFiles/imgui.dir/imgui_demo.cpp.s

libs/imgui/CMakeFiles/imgui.dir/imgui_draw.cpp.o: libs/imgui/CMakeFiles/imgui.dir/flags.make
libs/imgui/CMakeFiles/imgui.dir/imgui_draw.cpp.o: ../libs/imgui/imgui_draw.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/Documents/C++/Scop/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object libs/imgui/CMakeFiles/imgui.dir/imgui_draw.cpp.o"
	cd /home/user/Documents/C++/Scop/build/libs/imgui && /bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/imgui.dir/imgui_draw.cpp.o -c /home/user/Documents/C++/Scop/libs/imgui/imgui_draw.cpp

libs/imgui/CMakeFiles/imgui.dir/imgui_draw.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/imgui.dir/imgui_draw.cpp.i"
	cd /home/user/Documents/C++/Scop/build/libs/imgui && /bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/Documents/C++/Scop/libs/imgui/imgui_draw.cpp > CMakeFiles/imgui.dir/imgui_draw.cpp.i

libs/imgui/CMakeFiles/imgui.dir/imgui_draw.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/imgui.dir/imgui_draw.cpp.s"
	cd /home/user/Documents/C++/Scop/build/libs/imgui && /bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/Documents/C++/Scop/libs/imgui/imgui_draw.cpp -o CMakeFiles/imgui.dir/imgui_draw.cpp.s

libs/imgui/CMakeFiles/imgui.dir/imgui_impl_glfw.cpp.o: libs/imgui/CMakeFiles/imgui.dir/flags.make
libs/imgui/CMakeFiles/imgui.dir/imgui_impl_glfw.cpp.o: ../libs/imgui/imgui_impl_glfw.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/Documents/C++/Scop/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object libs/imgui/CMakeFiles/imgui.dir/imgui_impl_glfw.cpp.o"
	cd /home/user/Documents/C++/Scop/build/libs/imgui && /bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/imgui.dir/imgui_impl_glfw.cpp.o -c /home/user/Documents/C++/Scop/libs/imgui/imgui_impl_glfw.cpp

libs/imgui/CMakeFiles/imgui.dir/imgui_impl_glfw.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/imgui.dir/imgui_impl_glfw.cpp.i"
	cd /home/user/Documents/C++/Scop/build/libs/imgui && /bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/Documents/C++/Scop/libs/imgui/imgui_impl_glfw.cpp > CMakeFiles/imgui.dir/imgui_impl_glfw.cpp.i

libs/imgui/CMakeFiles/imgui.dir/imgui_impl_glfw.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/imgui.dir/imgui_impl_glfw.cpp.s"
	cd /home/user/Documents/C++/Scop/build/libs/imgui && /bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/Documents/C++/Scop/libs/imgui/imgui_impl_glfw.cpp -o CMakeFiles/imgui.dir/imgui_impl_glfw.cpp.s

libs/imgui/CMakeFiles/imgui.dir/imgui_impl_opengl3.cpp.o: libs/imgui/CMakeFiles/imgui.dir/flags.make
libs/imgui/CMakeFiles/imgui.dir/imgui_impl_opengl3.cpp.o: ../libs/imgui/imgui_impl_opengl3.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/Documents/C++/Scop/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object libs/imgui/CMakeFiles/imgui.dir/imgui_impl_opengl3.cpp.o"
	cd /home/user/Documents/C++/Scop/build/libs/imgui && /bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/imgui.dir/imgui_impl_opengl3.cpp.o -c /home/user/Documents/C++/Scop/libs/imgui/imgui_impl_opengl3.cpp

libs/imgui/CMakeFiles/imgui.dir/imgui_impl_opengl3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/imgui.dir/imgui_impl_opengl3.cpp.i"
	cd /home/user/Documents/C++/Scop/build/libs/imgui && /bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/Documents/C++/Scop/libs/imgui/imgui_impl_opengl3.cpp > CMakeFiles/imgui.dir/imgui_impl_opengl3.cpp.i

libs/imgui/CMakeFiles/imgui.dir/imgui_impl_opengl3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/imgui.dir/imgui_impl_opengl3.cpp.s"
	cd /home/user/Documents/C++/Scop/build/libs/imgui && /bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/Documents/C++/Scop/libs/imgui/imgui_impl_opengl3.cpp -o CMakeFiles/imgui.dir/imgui_impl_opengl3.cpp.s

libs/imgui/CMakeFiles/imgui.dir/imgui_widgets.cpp.o: libs/imgui/CMakeFiles/imgui.dir/flags.make
libs/imgui/CMakeFiles/imgui.dir/imgui_widgets.cpp.o: ../libs/imgui/imgui_widgets.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/Documents/C++/Scop/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object libs/imgui/CMakeFiles/imgui.dir/imgui_widgets.cpp.o"
	cd /home/user/Documents/C++/Scop/build/libs/imgui && /bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/imgui.dir/imgui_widgets.cpp.o -c /home/user/Documents/C++/Scop/libs/imgui/imgui_widgets.cpp

libs/imgui/CMakeFiles/imgui.dir/imgui_widgets.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/imgui.dir/imgui_widgets.cpp.i"
	cd /home/user/Documents/C++/Scop/build/libs/imgui && /bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/Documents/C++/Scop/libs/imgui/imgui_widgets.cpp > CMakeFiles/imgui.dir/imgui_widgets.cpp.i

libs/imgui/CMakeFiles/imgui.dir/imgui_widgets.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/imgui.dir/imgui_widgets.cpp.s"
	cd /home/user/Documents/C++/Scop/build/libs/imgui && /bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/Documents/C++/Scop/libs/imgui/imgui_widgets.cpp -o CMakeFiles/imgui.dir/imgui_widgets.cpp.s

# Object files for target imgui
imgui_OBJECTS = \
"CMakeFiles/imgui.dir/imgui.cpp.o" \
"CMakeFiles/imgui.dir/imgui_demo.cpp.o" \
"CMakeFiles/imgui.dir/imgui_draw.cpp.o" \
"CMakeFiles/imgui.dir/imgui_impl_glfw.cpp.o" \
"CMakeFiles/imgui.dir/imgui_impl_opengl3.cpp.o" \
"CMakeFiles/imgui.dir/imgui_widgets.cpp.o"

# External object files for target imgui
imgui_EXTERNAL_OBJECTS =

libs/imgui/libimgui.a: libs/imgui/CMakeFiles/imgui.dir/imgui.cpp.o
libs/imgui/libimgui.a: libs/imgui/CMakeFiles/imgui.dir/imgui_demo.cpp.o
libs/imgui/libimgui.a: libs/imgui/CMakeFiles/imgui.dir/imgui_draw.cpp.o
libs/imgui/libimgui.a: libs/imgui/CMakeFiles/imgui.dir/imgui_impl_glfw.cpp.o
libs/imgui/libimgui.a: libs/imgui/CMakeFiles/imgui.dir/imgui_impl_opengl3.cpp.o
libs/imgui/libimgui.a: libs/imgui/CMakeFiles/imgui.dir/imgui_widgets.cpp.o
libs/imgui/libimgui.a: libs/imgui/CMakeFiles/imgui.dir/build.make
libs/imgui/libimgui.a: libs/imgui/CMakeFiles/imgui.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/user/Documents/C++/Scop/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX static library libimgui.a"
	cd /home/user/Documents/C++/Scop/build/libs/imgui && $(CMAKE_COMMAND) -P CMakeFiles/imgui.dir/cmake_clean_target.cmake
	cd /home/user/Documents/C++/Scop/build/libs/imgui && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/imgui.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
libs/imgui/CMakeFiles/imgui.dir/build: libs/imgui/libimgui.a

.PHONY : libs/imgui/CMakeFiles/imgui.dir/build

libs/imgui/CMakeFiles/imgui.dir/clean:
	cd /home/user/Documents/C++/Scop/build/libs/imgui && $(CMAKE_COMMAND) -P CMakeFiles/imgui.dir/cmake_clean.cmake
.PHONY : libs/imgui/CMakeFiles/imgui.dir/clean

libs/imgui/CMakeFiles/imgui.dir/depend:
	cd /home/user/Documents/C++/Scop/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/user/Documents/C++/Scop /home/user/Documents/C++/Scop/libs/imgui /home/user/Documents/C++/Scop/build /home/user/Documents/C++/Scop/build/libs/imgui /home/user/Documents/C++/Scop/build/libs/imgui/CMakeFiles/imgui.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : libs/imgui/CMakeFiles/imgui.dir/depend

