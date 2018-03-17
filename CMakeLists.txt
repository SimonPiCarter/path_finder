
cmake_minimum_required(VERSION 3.7)

project(Path)

set(EXE_NAME exePath)
set(LIB_NAME libPath)
set(VISU_LIB_NAME libVisuPath)

### PATH LIB

include_directories(src/lib/)
file(GLOB_RECURSE SRC_LIB src/lib/*.cpp)
add_library(${LIB_NAME} ${SRC_LIB})

### VISU LIB

include_directories(src/visu_lib/)
file(GLOB_RECURSE SRC_VISU_LIB src/visu_lib/*.cpp)
add_library(${VISU_LIB_NAME} ${SRC_VISU_LIB})
target_link_libraries(${VISU_LIB_NAME} ${LIB_NAME})

### EXE

add_executable(${EXE_NAME} src/main.cpp)
target_link_libraries(${EXE_NAME} ${VISU_LIB_NAME})

### SDL2

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

target_link_libraries(${VISU_LIB_NAME} ${SDL2_LIBRARIES})

### GTEST
find_package(GTest REQUIRED)

set(UNIT_TEST unit_tests)

file(GLOB_RECURSE SRC_TEST src/test/*.cpp)

add_executable(${UNIT_TEST} ${SRC_TEST})

target_include_directories (${UNIT_TEST} SYSTEM PRIVATE "${GTEST_INCLUDE_DIRS}")
target_link_libraries(${UNIT_TEST} ${LIB_NAME} ${GTEST_BOTH_LIBRARIES})


