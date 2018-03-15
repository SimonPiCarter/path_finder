
cmake_minimum_required(VERSION 3.2)

project(Path)

file(GLOB_RECURSE SRC_LIB src/lib/*.cpp)

set(EXE_NAME exePath)
set(LIB_NAME libPath)

include_directories(src/lib/)

add_library(${LIB_NAME} ${SRC_LIB})

add_executable(${EXE_NAME} src/main.cpp)

target_link_libraries(${EXE_NAME} ${LIB_NAME})

find_package(GTest REQUIRED)

set(UNIT_TEST unit_tests)

file(GLOB_RECURSE SRC_TEST src/test/*.cpp)

add_executable(${UNIT_TEST} ${SRC_TEST})

target_include_directories (${UNIT_TEST} SYSTEM PRIVATE "${GTEST_INCLUDE_DIRS}")
target_link_libraries(${UNIT_TEST} ${LIB_NAME} ${GTEST_BOTH_LIBRARIES})
