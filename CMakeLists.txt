cmake_minimum_required(VERSION 3.21)
project(nFiler)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(shared_code)
add_subdirectory(unit_tests)

add_executable(nFiler main.cpp)
target_link_libraries(nFiler PUBLIC shared_code)
