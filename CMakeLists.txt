
cmake_minimum_required(VERSION 3.2)

project(Path)

file(GLOB_RECURSE SRC_LIB
    src/lib/*.cpp)

set(EXE_NAME exePath)
set(LIB_NAME libPath)

include_directories(src/lib/)

add_library(${LIB_NAME} ${SRC_LIB})

add_executable(${EXE_NAME} src/main.cpp)

target_link_libraries(${EXE_NAME} ${LIB_NAME})

