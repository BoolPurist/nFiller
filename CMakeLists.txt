cmake_minimum_required(VERSION 3.21)
project(nFiller)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(shared_code)
add_subdirectory(unit_tests)
include(functions_and_macros.cmake)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC shared_code)

install(TARGETS ${PROJECT_NAME} CONFIGURATIONS Debug)
