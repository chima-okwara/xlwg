cmake_minimum_required(VERSION 3.5)

project (3lwg)

add_executable(example main.cpp)

target_link_libraries(3lwg PUBLIC  xlwgLib)
