# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "G:\My Drive\MIPT LPR 2 semester\mipt_cpp\01032021"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "G:\My Drive\MIPT LPR 2 semester\mipt_cpp\01032021\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/01032021.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/01032021.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/01032021.dir/flags.make

CMakeFiles/01032021.dir/b.cpp.obj: CMakeFiles/01032021.dir/flags.make
CMakeFiles/01032021.dir/b.cpp.obj: ../b.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="G:\My Drive\MIPT LPR 2 semester\mipt_cpp\01032021\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/01032021.dir/b.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\01032021.dir\b.cpp.obj -c "G:\My Drive\MIPT LPR 2 semester\mipt_cpp\01032021\b.cpp"

CMakeFiles/01032021.dir/b.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/01032021.dir/b.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "G:\My Drive\MIPT LPR 2 semester\mipt_cpp\01032021\b.cpp" > CMakeFiles\01032021.dir\b.cpp.i

CMakeFiles/01032021.dir/b.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/01032021.dir/b.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "G:\My Drive\MIPT LPR 2 semester\mipt_cpp\01032021\b.cpp" -o CMakeFiles\01032021.dir\b.cpp.s

# Object files for target 01032021
01032021_OBJECTS = \
"CMakeFiles/01032021.dir/b.cpp.obj"

# External object files for target 01032021
01032021_EXTERNAL_OBJECTS =

01032021.exe: CMakeFiles/01032021.dir/b.cpp.obj
01032021.exe: CMakeFiles/01032021.dir/build.make
01032021.exe: CMakeFiles/01032021.dir/linklibs.rsp
01032021.exe: CMakeFiles/01032021.dir/objects1.rsp
01032021.exe: CMakeFiles/01032021.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="G:\My Drive\MIPT LPR 2 semester\mipt_cpp\01032021\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 01032021.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\01032021.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/01032021.dir/build: 01032021.exe

.PHONY : CMakeFiles/01032021.dir/build

CMakeFiles/01032021.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\01032021.dir\cmake_clean.cmake
.PHONY : CMakeFiles/01032021.dir/clean

CMakeFiles/01032021.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "G:\My Drive\MIPT LPR 2 semester\mipt_cpp\01032021" "G:\My Drive\MIPT LPR 2 semester\mipt_cpp\01032021" "G:\My Drive\MIPT LPR 2 semester\mipt_cpp\01032021\cmake-build-debug" "G:\My Drive\MIPT LPR 2 semester\mipt_cpp\01032021\cmake-build-debug" "G:\My Drive\MIPT LPR 2 semester\mipt_cpp\01032021\cmake-build-debug\CMakeFiles\01032021.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/01032021.dir/depend

