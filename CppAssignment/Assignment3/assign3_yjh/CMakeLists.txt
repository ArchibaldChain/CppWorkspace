cmake_minimum_required(VERSION 3.15)
project(assign4)

set(CMAKE_CXX_STANDARD 11)

add_executable(assign4 main.cpp utf8.c )
add_executable(assign4_1 assign4_1.cpp utf8.c)
add_executable(codepoint using_utf8_to_codepoint.c utf8.c)
add_executable(assign4_2 assign4_2.cpp utf8.c)