# Build all tests for the KAI framework

cmake_minimum_required(VERSION 3.7)
FIND_PACKAGE(Boost 1.40 COMPONENTS filesystem REQUIRED )

set(name KaiTest)
project(${name})
set(TEST_SRC_ROOT ${TEST_HOME}/Source/*.cpp)
file(GLOB_RECURSE TEST_SRC_FILES ${TEST_SRC_ROOT})
include_directories(${TEST_HOME}/Include)
link_libraries(Executor Core PiLang RhoLang TauLang)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BIN_HOME}/Test")
add_executable(${name} ${TEST_SRC_FILES})
target_link_libraries(${name} gtest pthread boost_system boost_filesystem)
