cmake_minimum_required(VERSION 3.5)

project (xlwgLib)

SET(xlwgHomeDir ${PROJECT_SOURCE_DIR})

FILE(GLOB_RECURSE srcFiles ${homeDir}/*.cpp)

add_library (STATIC xlwg ${srcFiles})

# target_include_directories(${xlwgHomeDir} PUBLIC include)
