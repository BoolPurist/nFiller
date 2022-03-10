include(../functions_and_macros.cmake)

set(SHARED_CODE_TARGET_NAME shared_code)
list( APPEND SOURCES RepetitionRequest.cpp bufferController.cpp ArgumentHandler.cpp help.cpp)

GET_HEADERS_FROM(HEADERS SOURCES)

add_library(${SHARED_CODE_TARGET_NAME} ${SOURCES} ${HEADERS})

target_include_directories(
    ${SHARED_CODE_TARGET_NAME}
    PUBLIC ${CMAKE_CURRENT_LIST_DIR}
)

