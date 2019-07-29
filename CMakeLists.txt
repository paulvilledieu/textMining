cmake_minimum_required(VERSION 3.15)

project(TextMining)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "-O0 -std=c++11")

include_directories("include/")

file(GLOB_RECURSE SRC_FILES src/*)
file(GLOB_RECURSE INCLUDE_FILES include/*)

add_library(TextMining SHARED ${SRC_FILES} ${INCLUDE_FILES})

include_directories(${PROJECT_SOURCE_DIR}/bin)

add_executable(TextMiningCompiler bin/main.cc)
target_link_libraries(TextMiningCompiler TextMining)

add_executable(TextMiningApp bin/main.cc)
target_link_libraries(TextMiningApp TextMining)