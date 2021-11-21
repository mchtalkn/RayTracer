# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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
CMAKE_SOURCE_DIR = /mnt/d/ceng477hw1/ceng477hw1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/d/ceng477hw1/ceng477hw1

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /mnt/d/ceng477hw1/ceng477hw1/CMakeFiles /mnt/d/ceng477hw1/ceng477hw1//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /mnt/d/ceng477hw1/ceng477hw1/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named raytracer

# Build rule for target.
raytracer: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 raytracer
.PHONY : raytracer

# fast build rule for target.
raytracer/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/raytracer.dir/build.make CMakeFiles/raytracer.dir/build
.PHONY : raytracer/fast

Algebra.o: Algebra.cpp.o
.PHONY : Algebra.o

# target to build an object file
Algebra.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/raytracer.dir/build.make CMakeFiles/raytracer.dir/Algebra.cpp.o
.PHONY : Algebra.cpp.o

Algebra.i: Algebra.cpp.i
.PHONY : Algebra.i

# target to preprocess a source file
Algebra.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/raytracer.dir/build.make CMakeFiles/raytracer.dir/Algebra.cpp.i
.PHONY : Algebra.cpp.i

Algebra.s: Algebra.cpp.s
.PHONY : Algebra.s

# target to generate assembly for a file
Algebra.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/raytracer.dir/build.make CMakeFiles/raytracer.dir/Algebra.cpp.s
.PHONY : Algebra.cpp.s

CameraHandler.o: CameraHandler.cpp.o
.PHONY : CameraHandler.o

# target to build an object file
CameraHandler.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/raytracer.dir/build.make CMakeFiles/raytracer.dir/CameraHandler.cpp.o
.PHONY : CameraHandler.cpp.o

CameraHandler.i: CameraHandler.cpp.i
.PHONY : CameraHandler.i

# target to preprocess a source file
CameraHandler.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/raytracer.dir/build.make CMakeFiles/raytracer.dir/CameraHandler.cpp.i
.PHONY : CameraHandler.cpp.i

CameraHandler.s: CameraHandler.cpp.s
.PHONY : CameraHandler.s

# target to generate assembly for a file
CameraHandler.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/raytracer.dir/build.make CMakeFiles/raytracer.dir/CameraHandler.cpp.s
.PHONY : CameraHandler.cpp.s

Ray.o: Ray.cpp.o
.PHONY : Ray.o

# target to build an object file
Ray.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/raytracer.dir/build.make CMakeFiles/raytracer.dir/Ray.cpp.o
.PHONY : Ray.cpp.o

Ray.i: Ray.cpp.i
.PHONY : Ray.i

# target to preprocess a source file
Ray.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/raytracer.dir/build.make CMakeFiles/raytracer.dir/Ray.cpp.i
.PHONY : Ray.cpp.i

Ray.s: Ray.cpp.s
.PHONY : Ray.s

# target to generate assembly for a file
Ray.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/raytracer.dir/build.make CMakeFiles/raytracer.dir/Ray.cpp.s
.PHONY : Ray.cpp.s

SceneHandler.o: SceneHandler.cpp.o
.PHONY : SceneHandler.o

# target to build an object file
SceneHandler.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/raytracer.dir/build.make CMakeFiles/raytracer.dir/SceneHandler.cpp.o
.PHONY : SceneHandler.cpp.o

SceneHandler.i: SceneHandler.cpp.i
.PHONY : SceneHandler.i

# target to preprocess a source file
SceneHandler.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/raytracer.dir/build.make CMakeFiles/raytracer.dir/SceneHandler.cpp.i
.PHONY : SceneHandler.cpp.i

SceneHandler.s: SceneHandler.cpp.s
.PHONY : SceneHandler.s

# target to generate assembly for a file
SceneHandler.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/raytracer.dir/build.make CMakeFiles/raytracer.dir/SceneHandler.cpp.s
.PHONY : SceneHandler.cpp.s

parser.o: parser.cpp.o
.PHONY : parser.o

# target to build an object file
parser.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/raytracer.dir/build.make CMakeFiles/raytracer.dir/parser.cpp.o
.PHONY : parser.cpp.o

parser.i: parser.cpp.i
.PHONY : parser.i

# target to preprocess a source file
parser.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/raytracer.dir/build.make CMakeFiles/raytracer.dir/parser.cpp.i
.PHONY : parser.cpp.i

parser.s: parser.cpp.s
.PHONY : parser.s

# target to generate assembly for a file
parser.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/raytracer.dir/build.make CMakeFiles/raytracer.dir/parser.cpp.s
.PHONY : parser.cpp.s

ppm.o: ppm.cpp.o
.PHONY : ppm.o

# target to build an object file
ppm.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/raytracer.dir/build.make CMakeFiles/raytracer.dir/ppm.cpp.o
.PHONY : ppm.cpp.o

ppm.i: ppm.cpp.i
.PHONY : ppm.i

# target to preprocess a source file
ppm.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/raytracer.dir/build.make CMakeFiles/raytracer.dir/ppm.cpp.i
.PHONY : ppm.cpp.i

ppm.s: ppm.cpp.s
.PHONY : ppm.s

# target to generate assembly for a file
ppm.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/raytracer.dir/build.make CMakeFiles/raytracer.dir/ppm.cpp.s
.PHONY : ppm.cpp.s

raytracer.o: raytracer.cpp.o
.PHONY : raytracer.o

# target to build an object file
raytracer.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/raytracer.dir/build.make CMakeFiles/raytracer.dir/raytracer.cpp.o
.PHONY : raytracer.cpp.o

raytracer.i: raytracer.cpp.i
.PHONY : raytracer.i

# target to preprocess a source file
raytracer.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/raytracer.dir/build.make CMakeFiles/raytracer.dir/raytracer.cpp.i
.PHONY : raytracer.cpp.i

raytracer.s: raytracer.cpp.s
.PHONY : raytracer.s

# target to generate assembly for a file
raytracer.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/raytracer.dir/build.make CMakeFiles/raytracer.dir/raytracer.cpp.s
.PHONY : raytracer.cpp.s

tinyxml2.o: tinyxml2.cpp.o
.PHONY : tinyxml2.o

# target to build an object file
tinyxml2.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/raytracer.dir/build.make CMakeFiles/raytracer.dir/tinyxml2.cpp.o
.PHONY : tinyxml2.cpp.o

tinyxml2.i: tinyxml2.cpp.i
.PHONY : tinyxml2.i

# target to preprocess a source file
tinyxml2.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/raytracer.dir/build.make CMakeFiles/raytracer.dir/tinyxml2.cpp.i
.PHONY : tinyxml2.cpp.i

tinyxml2.s: tinyxml2.cpp.s
.PHONY : tinyxml2.s

# target to generate assembly for a file
tinyxml2.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/raytracer.dir/build.make CMakeFiles/raytracer.dir/tinyxml2.cpp.s
.PHONY : tinyxml2.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... raytracer"
	@echo "... Algebra.o"
	@echo "... Algebra.i"
	@echo "... Algebra.s"
	@echo "... CameraHandler.o"
	@echo "... CameraHandler.i"
	@echo "... CameraHandler.s"
	@echo "... Ray.o"
	@echo "... Ray.i"
	@echo "... Ray.s"
	@echo "... SceneHandler.o"
	@echo "... SceneHandler.i"
	@echo "... SceneHandler.s"
	@echo "... parser.o"
	@echo "... parser.i"
	@echo "... parser.s"
	@echo "... ppm.o"
	@echo "... ppm.i"
	@echo "... ppm.s"
	@echo "... raytracer.o"
	@echo "... raytracer.i"
	@echo "... raytracer.s"
	@echo "... tinyxml2.o"
	@echo "... tinyxml2.i"
	@echo "... tinyxml2.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

