set(SHARED_CODE_TARGET_NAME shared_code)

add_library(${SHARED_CODE_TARGET_NAME} bufferController.h bufferController.cpp)
target_include_directories(${SHARED_CODE_TARGET_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR})