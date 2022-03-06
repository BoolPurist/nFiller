set(TEST_TARGET_NAME unit_tests)

add_executable(${TEST_TARGET_NAME} main_test.cpp)
target_include_directories(${TEST_TARGET_NAME} PRIVATE "/home/nicegraphic/Code/external/boost_1_77_0")