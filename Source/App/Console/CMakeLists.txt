cmake_minimum_required(VERSION 3.7)

project(Console)

set(SOURCE_ROOT ${SOURCE_HOME}/App/Console/Source/*.cpp)
file(GLOB_RECURSE SOURCE_FILES ${SOURCE_ROOT})

link_libraries(Executor Core PiLang RhoLang)# platform-Linux)

add_executable(Console ${SOURCE_FILES})
cotire(Console)
