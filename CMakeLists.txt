cmake_minimum_required(VERSION 3.21)
project(consoleCalculator)

set(CMAKE_CXX_STANDARD 20)

file(GLOB SOURCES src/*.cpp)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
add_executable(${PROJECT_NAME} ${SOURCES})
set(CMAKE_CXX_FLAGS "-std=c++20")
