cmake_minimum_required(VERSION 3.21)
add_definitions("-std=c++20 -Werror")
project(consoleCalculator)

file(GLOB SOURCES src/*.cpp)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
add_executable(${PROJECT_NAME} ${SOURCES})