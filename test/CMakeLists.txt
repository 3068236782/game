cmake_minimum_required(VERSION 3.17)
project(test)

set(CMAKE_CXX_STANDARD 14)

link_libraries(libeasyx.a)

add_executable(test main.cpp)