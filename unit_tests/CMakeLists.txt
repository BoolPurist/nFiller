set(TEST_TARGET_NAME unit_tests)



add_executable(${TEST_TARGET_NAME} main_test.cpp)
target_link_libraries(${TEST_TARGET_NAME} PRIVATE shared_code)

cmake_path(GET CMAKE_CURRENT_LIST_DIR PARENT_PATH TMP_CURRENT_PARENT_PATH)
file(READ ${TMP_CURRENT_PARENT_PATH}/path_to_boost_include_path.txt PATH_TO_BOOST_INCLUDE_PATH)

target_include_directories(${TEST_TARGET_NAME} PRIVATE ${PATH_TO_BOOST_INCLUDE_PATH})