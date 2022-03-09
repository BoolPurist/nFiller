set(SHARED_CODE_TARGET_NAME shared_code)

list(APPEND SOURCES UserInput.cpp bufferController.cpp ArgumentHandler.cpp)


include(../functions_and_macros.cmake)



GET_HEADERS_FROM(HEADERS SOURCES)

add_library(${SHARED_CODE_TARGET_NAME} ${SOURCES} ${HEADERS})

print(PATH_TO_BOOST_INCLUDE_PATH)

target_include_directories(
    ${SHARED_CODE_TARGET_NAME}
    PUBLIC ${CMAKE_CURRENT_LIST_DIR}
)

