# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/christian/Local/KAI

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/christian/Local/KAI/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/PiLang.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/PiLang.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PiLang.dir/flags.make

CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiAstNode.cpp.o: CMakeFiles/PiLang.dir/flags.make
CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiAstNode.cpp.o: ../Library/Language/Pi/Source/PiAstNode.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/christian/Local/KAI/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiAstNode.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiAstNode.cpp.o -c /Users/christian/Local/KAI/Library/Language/Pi/Source/PiAstNode.cpp

CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiAstNode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiAstNode.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/christian/Local/KAI/Library/Language/Pi/Source/PiAstNode.cpp > CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiAstNode.cpp.i

CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiAstNode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiAstNode.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/christian/Local/KAI/Library/Language/Pi/Source/PiAstNode.cpp -o CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiAstNode.cpp.s

CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiAstNode.cpp.o.requires:

.PHONY : CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiAstNode.cpp.o.requires

CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiAstNode.cpp.o.provides: CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiAstNode.cpp.o.requires
	$(MAKE) -f CMakeFiles/PiLang.dir/build.make CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiAstNode.cpp.o.provides.build
.PHONY : CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiAstNode.cpp.o.provides

CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiAstNode.cpp.o.provides.build: CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiAstNode.cpp.o


CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiLexer.cpp.o: CMakeFiles/PiLang.dir/flags.make
CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiLexer.cpp.o: ../Library/Language/Pi/Source/PiLexer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/christian/Local/KAI/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiLexer.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiLexer.cpp.o -c /Users/christian/Local/KAI/Library/Language/Pi/Source/PiLexer.cpp

CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiLexer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiLexer.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/christian/Local/KAI/Library/Language/Pi/Source/PiLexer.cpp > CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiLexer.cpp.i

CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiLexer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiLexer.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/christian/Local/KAI/Library/Language/Pi/Source/PiLexer.cpp -o CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiLexer.cpp.s

CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiLexer.cpp.o.requires:

.PHONY : CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiLexer.cpp.o.requires

CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiLexer.cpp.o.provides: CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiLexer.cpp.o.requires
	$(MAKE) -f CMakeFiles/PiLang.dir/build.make CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiLexer.cpp.o.provides.build
.PHONY : CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiLexer.cpp.o.provides

CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiLexer.cpp.o.provides.build: CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiLexer.cpp.o


CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiParser.cpp.o: CMakeFiles/PiLang.dir/flags.make
CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiParser.cpp.o: ../Library/Language/Pi/Source/PiParser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/christian/Local/KAI/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiParser.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiParser.cpp.o -c /Users/christian/Local/KAI/Library/Language/Pi/Source/PiParser.cpp

CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiParser.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/christian/Local/KAI/Library/Language/Pi/Source/PiParser.cpp > CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiParser.cpp.i

CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiParser.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/christian/Local/KAI/Library/Language/Pi/Source/PiParser.cpp -o CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiParser.cpp.s

CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiParser.cpp.o.requires:

.PHONY : CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiParser.cpp.o.requires

CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiParser.cpp.o.provides: CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiParser.cpp.o.requires
	$(MAKE) -f CMakeFiles/PiLang.dir/build.make CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiParser.cpp.o.provides.build
.PHONY : CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiParser.cpp.o.provides

CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiParser.cpp.o.provides.build: CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiParser.cpp.o


CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiToken.cpp.o: CMakeFiles/PiLang.dir/flags.make
CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiToken.cpp.o: ../Library/Language/Pi/Source/PiToken.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/christian/Local/KAI/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiToken.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiToken.cpp.o -c /Users/christian/Local/KAI/Library/Language/Pi/Source/PiToken.cpp

CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiToken.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiToken.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/christian/Local/KAI/Library/Language/Pi/Source/PiToken.cpp > CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiToken.cpp.i

CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiToken.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiToken.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/christian/Local/KAI/Library/Language/Pi/Source/PiToken.cpp -o CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiToken.cpp.s

CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiToken.cpp.o.requires:

.PHONY : CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiToken.cpp.o.requires

CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiToken.cpp.o.provides: CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiToken.cpp.o.requires
	$(MAKE) -f CMakeFiles/PiLang.dir/build.make CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiToken.cpp.o.provides.build
.PHONY : CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiToken.cpp.o.provides

CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiToken.cpp.o.provides.build: CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiToken.cpp.o


CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiTranslator.cpp.o: CMakeFiles/PiLang.dir/flags.make
CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiTranslator.cpp.o: ../Library/Language/Pi/Source/PiTranslator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/christian/Local/KAI/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiTranslator.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiTranslator.cpp.o -c /Users/christian/Local/KAI/Library/Language/Pi/Source/PiTranslator.cpp

CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiTranslator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiTranslator.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/christian/Local/KAI/Library/Language/Pi/Source/PiTranslator.cpp > CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiTranslator.cpp.i

CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiTranslator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiTranslator.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/christian/Local/KAI/Library/Language/Pi/Source/PiTranslator.cpp -o CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiTranslator.cpp.s

CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiTranslator.cpp.o.requires:

.PHONY : CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiTranslator.cpp.o.requires

CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiTranslator.cpp.o.provides: CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiTranslator.cpp.o.requires
	$(MAKE) -f CMakeFiles/PiLang.dir/build.make CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiTranslator.cpp.o.provides.build
.PHONY : CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiTranslator.cpp.o.provides

CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiTranslator.cpp.o.provides.build: CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiTranslator.cpp.o


# Object files for target PiLang
PiLang_OBJECTS = \
"CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiAstNode.cpp.o" \
"CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiLexer.cpp.o" \
"CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiParser.cpp.o" \
"CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiToken.cpp.o" \
"CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiTranslator.cpp.o"

# External object files for target PiLang
PiLang_EXTERNAL_OBJECTS =

../lib/libPiLang.a: CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiAstNode.cpp.o
../lib/libPiLang.a: CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiLexer.cpp.o
../lib/libPiLang.a: CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiParser.cpp.o
../lib/libPiLang.a: CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiToken.cpp.o
../lib/libPiLang.a: CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiTranslator.cpp.o
../lib/libPiLang.a: CMakeFiles/PiLang.dir/build.make
../lib/libPiLang.a: CMakeFiles/PiLang.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/christian/Local/KAI/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX static library ../lib/libPiLang.a"
	$(CMAKE_COMMAND) -P CMakeFiles/PiLang.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PiLang.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PiLang.dir/build: ../lib/libPiLang.a

.PHONY : CMakeFiles/PiLang.dir/build

CMakeFiles/PiLang.dir/requires: CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiAstNode.cpp.o.requires
CMakeFiles/PiLang.dir/requires: CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiLexer.cpp.o.requires
CMakeFiles/PiLang.dir/requires: CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiParser.cpp.o.requires
CMakeFiles/PiLang.dir/requires: CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiToken.cpp.o.requires
CMakeFiles/PiLang.dir/requires: CMakeFiles/PiLang.dir/Library/Language/Pi/Source/PiTranslator.cpp.o.requires

.PHONY : CMakeFiles/PiLang.dir/requires

CMakeFiles/PiLang.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PiLang.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PiLang.dir/clean

CMakeFiles/PiLang.dir/depend:
	cd /Users/christian/Local/KAI/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/christian/Local/KAI /Users/christian/Local/KAI /Users/christian/Local/KAI/cmake-build-debug /Users/christian/Local/KAI/cmake-build-debug /Users/christian/Local/KAI/cmake-build-debug/CMakeFiles/PiLang.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PiLang.dir/depend

