cmake_minimum_required(VERSION 3.21)
project(nFiler)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(unit_tests)

add_executable(nFiler main.cpp bufferController.cpp bufferController.h)
