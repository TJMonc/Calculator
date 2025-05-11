cmake_minimum_required(VERSION 3.21)
project(consoleCalculator)

file(GLOB SOURCES src/*.cpp)

include_directories(${CMAKE_SOURCE_DIR}/src)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
add_executable(stuff ${SOURCES})
set(CMAKE_CXX_FLAGS "-std=c++20")
