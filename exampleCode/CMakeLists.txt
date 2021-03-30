cmake_minimum_required(VERSION 3.5)

project (example)

add_executable(${PROJECT_NAME} main.cpp)

include_directories(${PROJECT_SOURCE_DIR}/)

target_link_libraries(${PROJECT_NAME} xlwgLib)
