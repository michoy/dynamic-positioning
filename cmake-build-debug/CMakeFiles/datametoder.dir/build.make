# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.10

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.1.1\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.1.1\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\micha\Documents\GitHub\dynamic-positioning

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\micha\Documents\GitHub\dynamic-positioning\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/datametoder.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/datametoder.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/datametoder.dir/flags.make

CMakeFiles/datametoder.dir/src/main.c.obj: CMakeFiles/datametoder.dir/flags.make
CMakeFiles/datametoder.dir/src/main.c.obj: CMakeFiles/datametoder.dir/includes_C.rsp
CMakeFiles/datametoder.dir/src/main.c.obj: ../src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\micha\Documents\GitHub\dynamic-positioning\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/datametoder.dir/src/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\datametoder.dir\src\main.c.obj   -c C:\Users\micha\Documents\GitHub\dynamic-positioning\src\main.c

CMakeFiles/datametoder.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/datametoder.dir/src/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\micha\Documents\GitHub\dynamic-positioning\src\main.c > CMakeFiles\datametoder.dir\src\main.c.i

CMakeFiles/datametoder.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/datametoder.dir/src/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\micha\Documents\GitHub\dynamic-positioning\src\main.c -o CMakeFiles\datametoder.dir\src\main.c.s

CMakeFiles/datametoder.dir/src/main.c.obj.requires:

.PHONY : CMakeFiles/datametoder.dir/src/main.c.obj.requires

CMakeFiles/datametoder.dir/src/main.c.obj.provides: CMakeFiles/datametoder.dir/src/main.c.obj.requires
	$(MAKE) -f CMakeFiles\datametoder.dir\build.make CMakeFiles/datametoder.dir/src/main.c.obj.provides.build
.PHONY : CMakeFiles/datametoder.dir/src/main.c.obj.provides

CMakeFiles/datametoder.dir/src/main.c.obj.provides.build: CMakeFiles/datametoder.dir/src/main.c.obj


CMakeFiles/datametoder.dir/src/VoltageInput.c.obj: CMakeFiles/datametoder.dir/flags.make
CMakeFiles/datametoder.dir/src/VoltageInput.c.obj: CMakeFiles/datametoder.dir/includes_C.rsp
CMakeFiles/datametoder.dir/src/VoltageInput.c.obj: ../src/VoltageInput.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\micha\Documents\GitHub\dynamic-positioning\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/datametoder.dir/src/VoltageInput.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\datametoder.dir\src\VoltageInput.c.obj   -c C:\Users\micha\Documents\GitHub\dynamic-positioning\src\VoltageInput.c

CMakeFiles/datametoder.dir/src/VoltageInput.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/datametoder.dir/src/VoltageInput.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\micha\Documents\GitHub\dynamic-positioning\src\VoltageInput.c > CMakeFiles\datametoder.dir\src\VoltageInput.c.i

CMakeFiles/datametoder.dir/src/VoltageInput.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/datametoder.dir/src/VoltageInput.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\micha\Documents\GitHub\dynamic-positioning\src\VoltageInput.c -o CMakeFiles\datametoder.dir\src\VoltageInput.c.s

CMakeFiles/datametoder.dir/src/VoltageInput.c.obj.requires:

.PHONY : CMakeFiles/datametoder.dir/src/VoltageInput.c.obj.requires

CMakeFiles/datametoder.dir/src/VoltageInput.c.obj.provides: CMakeFiles/datametoder.dir/src/VoltageInput.c.obj.requires
	$(MAKE) -f CMakeFiles\datametoder.dir\build.make CMakeFiles/datametoder.dir/src/VoltageInput.c.obj.provides.build
.PHONY : CMakeFiles/datametoder.dir/src/VoltageInput.c.obj.provides

CMakeFiles/datametoder.dir/src/VoltageInput.c.obj.provides.build: CMakeFiles/datametoder.dir/src/VoltageInput.c.obj


CMakeFiles/datametoder.dir/src/RCServo.c.obj: CMakeFiles/datametoder.dir/flags.make
CMakeFiles/datametoder.dir/src/RCServo.c.obj: CMakeFiles/datametoder.dir/includes_C.rsp
CMakeFiles/datametoder.dir/src/RCServo.c.obj: ../src/RCServo.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\micha\Documents\GitHub\dynamic-positioning\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/datametoder.dir/src/RCServo.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\datametoder.dir\src\RCServo.c.obj   -c C:\Users\micha\Documents\GitHub\dynamic-positioning\src\RCServo.c

CMakeFiles/datametoder.dir/src/RCServo.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/datametoder.dir/src/RCServo.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\micha\Documents\GitHub\dynamic-positioning\src\RCServo.c > CMakeFiles\datametoder.dir\src\RCServo.c.i

CMakeFiles/datametoder.dir/src/RCServo.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/datametoder.dir/src/RCServo.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\micha\Documents\GitHub\dynamic-positioning\src\RCServo.c -o CMakeFiles\datametoder.dir\src\RCServo.c.s

CMakeFiles/datametoder.dir/src/RCServo.c.obj.requires:

.PHONY : CMakeFiles/datametoder.dir/src/RCServo.c.obj.requires

CMakeFiles/datametoder.dir/src/RCServo.c.obj.provides: CMakeFiles/datametoder.dir/src/RCServo.c.obj.requires
	$(MAKE) -f CMakeFiles\datametoder.dir\build.make CMakeFiles/datametoder.dir/src/RCServo.c.obj.provides.build
.PHONY : CMakeFiles/datametoder.dir/src/RCServo.c.obj.provides

CMakeFiles/datametoder.dir/src/RCServo.c.obj.provides.build: CMakeFiles/datametoder.dir/src/RCServo.c.obj


CMakeFiles/datametoder.dir/src/PhidgetHelperFunctions.c.obj: CMakeFiles/datametoder.dir/flags.make
CMakeFiles/datametoder.dir/src/PhidgetHelperFunctions.c.obj: CMakeFiles/datametoder.dir/includes_C.rsp
CMakeFiles/datametoder.dir/src/PhidgetHelperFunctions.c.obj: ../src/PhidgetHelperFunctions.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\micha\Documents\GitHub\dynamic-positioning\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/datametoder.dir/src/PhidgetHelperFunctions.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\datametoder.dir\src\PhidgetHelperFunctions.c.obj   -c C:\Users\micha\Documents\GitHub\dynamic-positioning\src\PhidgetHelperFunctions.c

CMakeFiles/datametoder.dir/src/PhidgetHelperFunctions.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/datametoder.dir/src/PhidgetHelperFunctions.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\micha\Documents\GitHub\dynamic-positioning\src\PhidgetHelperFunctions.c > CMakeFiles\datametoder.dir\src\PhidgetHelperFunctions.c.i

CMakeFiles/datametoder.dir/src/PhidgetHelperFunctions.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/datametoder.dir/src/PhidgetHelperFunctions.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\micha\Documents\GitHub\dynamic-positioning\src\PhidgetHelperFunctions.c -o CMakeFiles\datametoder.dir\src\PhidgetHelperFunctions.c.s

CMakeFiles/datametoder.dir/src/PhidgetHelperFunctions.c.obj.requires:

.PHONY : CMakeFiles/datametoder.dir/src/PhidgetHelperFunctions.c.obj.requires

CMakeFiles/datametoder.dir/src/PhidgetHelperFunctions.c.obj.provides: CMakeFiles/datametoder.dir/src/PhidgetHelperFunctions.c.obj.requires
	$(MAKE) -f CMakeFiles\datametoder.dir\build.make CMakeFiles/datametoder.dir/src/PhidgetHelperFunctions.c.obj.provides.build
.PHONY : CMakeFiles/datametoder.dir/src/PhidgetHelperFunctions.c.obj.provides

CMakeFiles/datametoder.dir/src/PhidgetHelperFunctions.c.obj.provides.build: CMakeFiles/datametoder.dir/src/PhidgetHelperFunctions.c.obj


CMakeFiles/datametoder.dir/src/animate.c.obj: CMakeFiles/datametoder.dir/flags.make
CMakeFiles/datametoder.dir/src/animate.c.obj: CMakeFiles/datametoder.dir/includes_C.rsp
CMakeFiles/datametoder.dir/src/animate.c.obj: ../src/animate.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\micha\Documents\GitHub\dynamic-positioning\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/datametoder.dir/src/animate.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\datametoder.dir\src\animate.c.obj   -c C:\Users\micha\Documents\GitHub\dynamic-positioning\src\animate.c

CMakeFiles/datametoder.dir/src/animate.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/datametoder.dir/src/animate.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\micha\Documents\GitHub\dynamic-positioning\src\animate.c > CMakeFiles\datametoder.dir\src\animate.c.i

CMakeFiles/datametoder.dir/src/animate.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/datametoder.dir/src/animate.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\micha\Documents\GitHub\dynamic-positioning\src\animate.c -o CMakeFiles\datametoder.dir\src\animate.c.s

CMakeFiles/datametoder.dir/src/animate.c.obj.requires:

.PHONY : CMakeFiles/datametoder.dir/src/animate.c.obj.requires

CMakeFiles/datametoder.dir/src/animate.c.obj.provides: CMakeFiles/datametoder.dir/src/animate.c.obj.requires
	$(MAKE) -f CMakeFiles\datametoder.dir\build.make CMakeFiles/datametoder.dir/src/animate.c.obj.provides.build
.PHONY : CMakeFiles/datametoder.dir/src/animate.c.obj.provides

CMakeFiles/datametoder.dir/src/animate.c.obj.provides.build: CMakeFiles/datametoder.dir/src/animate.c.obj


# Object files for target datametoder
datametoder_OBJECTS = \
"CMakeFiles/datametoder.dir/src/main.c.obj" \
"CMakeFiles/datametoder.dir/src/VoltageInput.c.obj" \
"CMakeFiles/datametoder.dir/src/RCServo.c.obj" \
"CMakeFiles/datametoder.dir/src/PhidgetHelperFunctions.c.obj" \
"CMakeFiles/datametoder.dir/src/animate.c.obj"

# External object files for target datametoder
datametoder_EXTERNAL_OBJECTS =

datametoder.exe: CMakeFiles/datametoder.dir/src/main.c.obj
datametoder.exe: CMakeFiles/datametoder.dir/src/VoltageInput.c.obj
datametoder.exe: CMakeFiles/datametoder.dir/src/RCServo.c.obj
datametoder.exe: CMakeFiles/datametoder.dir/src/PhidgetHelperFunctions.c.obj
datametoder.exe: CMakeFiles/datametoder.dir/src/animate.c.obj
datametoder.exe: CMakeFiles/datametoder.dir/build.make
datametoder.exe: CMakeFiles/datametoder.dir/linklibs.rsp
datametoder.exe: CMakeFiles/datametoder.dir/objects1.rsp
datametoder.exe: CMakeFiles/datametoder.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\micha\Documents\GitHub\dynamic-positioning\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable datametoder.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\datametoder.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/datametoder.dir/build: datametoder.exe

.PHONY : CMakeFiles/datametoder.dir/build

CMakeFiles/datametoder.dir/requires: CMakeFiles/datametoder.dir/src/main.c.obj.requires
CMakeFiles/datametoder.dir/requires: CMakeFiles/datametoder.dir/src/VoltageInput.c.obj.requires
CMakeFiles/datametoder.dir/requires: CMakeFiles/datametoder.dir/src/RCServo.c.obj.requires
CMakeFiles/datametoder.dir/requires: CMakeFiles/datametoder.dir/src/PhidgetHelperFunctions.c.obj.requires
CMakeFiles/datametoder.dir/requires: CMakeFiles/datametoder.dir/src/animate.c.obj.requires

.PHONY : CMakeFiles/datametoder.dir/requires

CMakeFiles/datametoder.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\datametoder.dir\cmake_clean.cmake
.PHONY : CMakeFiles/datametoder.dir/clean

CMakeFiles/datametoder.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\micha\Documents\GitHub\dynamic-positioning C:\Users\micha\Documents\GitHub\dynamic-positioning C:\Users\micha\Documents\GitHub\dynamic-positioning\cmake-build-debug C:\Users\micha\Documents\GitHub\dynamic-positioning\cmake-build-debug C:\Users\micha\Documents\GitHub\dynamic-positioning\cmake-build-debug\CMakeFiles\datametoder.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/datametoder.dir/depend
