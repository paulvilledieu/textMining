cmake_minimum_required(VERSION 3.15)

project(TextMining)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "-O0 -std=c++11")
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

include_directories("include/")

file(GLOB_RECURSE SRC_FILES src/*)
file(GLOB_RECURSE INCLUDE_FILES include/*)

add_library(TextMining SHARED ${SRC_FILES} ${INCLUDE_FILES})

include_directories(${PROJECT_SOURCE_DIR}/bin)

add_executable(TextMiningCompiler bin/compiler.cc)
target_link_libraries(TextMiningCompiler TextMining)

add_executable(TextMiningApp bin/app.cc)
target_link_libraries(TextMiningApp TextMining)