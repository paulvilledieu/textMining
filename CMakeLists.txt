cmake_minimum_required(VERSION 3.15)

project(TextMining)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "-O0 -std=c++11")

file(GLOB_RECURSE SRC_FILES src/*)
add_library(TextMining SHARED ${SRC_FILES})

add_executable(TextMiningCompiler src/main.cc)
target_link_libraries(TextMiningCompiler TextMining)

add_executable(TextMiningApp src/main.cc)
target_link_libraries(TextMiningApp TextMining)