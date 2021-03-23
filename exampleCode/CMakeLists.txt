cmake_minimum_required(VERSION 3.5)

project (xlwgLib)

add_executable(example main.cpp)

include_directories(../)

target_link_libraries(${PROJECT_NAME} ./xlwgLib)
