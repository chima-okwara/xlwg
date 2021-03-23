cmake_minimum_required(VERSION 3.5)

project (xlwgLib)

add_subdirectory(exampleCode)

# SET(xlwgHomeDir "${PROJECT_SOURCE_DIR}")

FILE(GLOB_RECURSE srcFiles ./*.cpp)

add_library (${PROJECT_NAME} ${srcFiles})

target_include_directories(${PROJECT_NAME} PUBLIC ./)
